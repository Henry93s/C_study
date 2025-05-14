#include "time.h" // 클래스와 #include, 네임스페이스 사용 선언은 헤더파일에서 진행

class Time {
private:
	unsigned int hour;
	unsigned int min;
	unsigned int sec;
	unsigned int t_sec;
public:
	Time() : hour(0), min(0), sec(0), t_sec(0) {} // 이니셜라이저(초기화 리스트) 사용
	Time(int hour, int min, int sec) {
		this->hour = hour;
		this->min = min;
		this->sec = sec;
		this->t_sec = (HOUR_SEC * this->hour) + (MIN_SEC * this->min) + this->sec;
	}
	int CalSecond() {
		this->t_sec = (HOUR_SEC * hour) + (MIN_SEC * min) + sec;
		return this->t_sec;
	}

	void setTime(int hour, int min, int sec) {
		this->hour = hour;
		this->min = min;
		this->sec = sec;
	}
	int getTimeHour() const { // const : 변경이 발생하지 않는 메소드
		return this->hour;
	}
	int getTimeMin() const {
		return this->min;
	}
	int getTimeSecond() const {
		return this->sec;
	}
	string getTimeStr() { // std::to_string(int) : integer -> string
		string str = "";
		str.append(to_string(hour) + "시 ");
		str.append(to_string(min) + "분 ");
		str.append(to_string(sec) + "초");
		return str;
	}


	bool operator<=(Time timeObj) {
		this->CalSecond();
		timeObj.CalSecond();
		if(this->t_sec <= timeObj.t_sec) {
			return true;
		}
		else {
			return false;
		}
	}


	bool operator>=(Time timeObj) {
		this->CalSecond();
		timeObj.CalSecond();
		if (this->t_sec >= timeObj.t_sec) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Time time;
	time.setTime(14, 30, 6);
	cout << time.CalSecond() << "초" << endl;
	cout << time.getTimeHour() << "시" << time.getTimeMin() << "분" << time.getTimeSecond() << "초" << endl;
	cout << time.getTimeStr() << endl;

	Time time2;
	time2.setTime(18, 0, 32);
	if (time >= time2) { // time2.operator>=(time) 과 같다. (연산자 오버로딩 함수)
		cout << time.getTimeStr() << "이 " << time2.getTimeStr() << "보다 크거나 같다." << endl;
	} else {
		cout << time2.getTimeStr() << "이 " << time.getTimeStr() << "보다 크거나 같다." << endl;
	}

	if (time <= time2) { // time.operator<=(time2) 와 같다. (연산자 오버로딩 함수)
		cout << time2.getTimeStr() << "이 " << time.getTimeStr() << "보다 크거나 같다." << endl;
	}
	else {
		cout << time.getTimeStr() << "이 " << time2.getTimeStr() << "보다 크거나 같다." << endl;
	}

	return 0;
}