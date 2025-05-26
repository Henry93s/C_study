#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_videoWidget = new QVideoWidget(this);
    m_videoWidget->resize(QSize(820,500)); // 비디오 위젯 사이즈 정의
    // setAspectRatioMode : 창 크기 조정에 대한 가로 세로 비율 수정 모드를 설정
    //  Qt::IgnoreAspectRatio : 비디오의 비율을 무시하고, 위젯의 크기에 맞춰서 그림의 형태가 변함.
    m_videoWidget->setAspectRatioMode(Qt::IgnoreAspectRatio);

    m_audioOutput = new QAudioOutput(this);
    m_audioOutput->setVolume(100);

    m_player = new QMediaPlayer(this);
    m_player->setPlaybackRate(1); // 재생 속도 설정
    m_player->setVideoOutput(m_videoWidget); // 비디오 Output 위젯 설정
    m_player->setAudioOutput(m_audioOutput); // 오디오 output 설정
    // setSource : QUrl("video url") 설정
    m_player->setSource(QUrl("https://commondatastorage.googleapis.com/gtv-videos-bucket/sample/BigBuckBunny.mp4"));
    // 객체 생성 시 바로 재생
    m_player->play();


}

Widget::~Widget() {}
