#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <alsa/asoundlib.h>

#define BITS                    2
#define FRAGMENT                8
#define DURATION                5.0
#define MODE                    1
#define FREQ                    44100
#define BUFSIZE                 (int)(BITS*FREQ*DURATION*MODE)

int setupDSP(snd_pcm_t *dev, int buf_size, int format, int sampleRate, int channels);

int main(int argc, char **argv)
{
        snd_pcm_t *playback_handle;
        double total = DURATION, t;
        int freq = 440;
        int i, frames, count = 1;
        char *snd_dev_out = "plughw:0,0";
        short buf[BUFSIZE];

        /* ALSA 오디오 디바이스 열기 */
        if(snd_pcm_open(&playback_handle, snd_dev_out, SND_PCM_STREAM_PLAYBACK, 0) < 0) {
                perror("Could not open output audio dev");
                return -1;
        }

        /* 오디오 디바이스 설정 */
        if(setupDSP(playback_handle, BUFSIZE, SND_PCM_FORMAT_S16_LE, FREQ, MODE) < 0) {
                perror("Could not set output audio device"); return -1;
        }

        /* 정현파 데이터 생성 */
        printf("Make Sine wave!!!\n");
        for(i = 0; i < BUFSIZE; i++) {
                t = (total / BUFSIZE) * i;
                buf[i] = SHRT_MAX * sin((int)(2.0 * M_PI * freq * t));
        }

        frames = BUFSIZE / (MODE * BITS);

        while(count--) {
                /* 오디오 출력을 위한 준비 */
                snd_pcm_prepare(playback_handle);

                /* 오디오 데이터를 디바이스로 출력(쓰기) */
                snd_pcm_writei(playback_handle, buf, frames);
        }

        /* 오디오 버퍼 버리기 */
        snd_pcm_drop(playback_handle);

        /* 오디오 디바이스 닫기 */
        snd_pcm_close(playback_handle);

        return 0;
}

int setupDSP(snd_pcm_t *dev, int buf_size, int format, int sampleRate, int channels)
{
        snd_pcm_hw_params_t* hw_params;
        snd_pcm_uframes_t frames;
        int fragments = FRAGMENT;
        int bits = (format == SND_PCM_FORMAT_S16_LE)?2:1;

        /* 오디오 디바이스의 매개변수 구조체를 위한 메모리 할당 */
        if(snd_pcm_hw_params_malloc(&hw_params) < 0) {
                perror("Could not allocate parameter");
                return -1;
        }

        /* 오디오 디바이스의 매개변수들을 초기화한다. */
        if(snd_pcm_hw_params_any(dev, hw_params) < 0) {
                perror("Could not initialize parameter");
                return -1;
        }

        /* 오디오 데이터의 접근(access) 타입(인터리브드, 논인터리브드)을 설정한다. */
        if(snd_pcm_hw_params_set_access(dev, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED) < 0){
                perror("Could not set access type");
                return -1;
        }

        /* 샘플의 포맷을 설정한다: 부호 있는 16비트 리틀 엔디안*/
        if(snd_pcm_hw_params_set_format(dev, hw_params, format) < 0) {
                perror("Could not set sample format");
                return -1;
        }

        /* 샘플링 레이트를 설정한다: 44.1KHz(CD 수준의 품질) */
        if(snd_pcm_hw_params_set_rate_near(dev, hw_params, &sampleRate, 0) < 0) {
                perror("Could not set sample rate");
                return -1;
        }

        /* 채널 설정: MONO(1) */
        if(snd_pcm_hw_params_set_channels(dev, hw_params, channels) < 0) {
                perror("Could not set channel count");
                return -1;
        }

        /* 프레임 주기 설정 */
        if(snd_pcm_hw_params_set_periods_near(dev, hw_params, &fragments, 0) < 0) {
                perror("Count not set fragments");
                return -1;
        }

        /* 버퍼의 크기 설정 */
        frames = (buf_size * fragments) / (channels * bits);
        if(snd_pcm_hw_params_set_buffer_size_near(dev, hw_params, &frames) < 0){
                perror("Count not set buffer_size");
                return -1;
        }

        buf_size = frames * channels * bits / fragments;

        /* 앞에서 설정한 오디오 디바이스의 매개변수를 ALSA 시스템에 적용 */
        if(snd_pcm_hw_params(dev, hw_params) < 0) {
                perror("Count not set HW params");
                return -1;
        }

        return 0;
}
