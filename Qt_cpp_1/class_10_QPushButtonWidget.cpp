/* QPushButton : 가장 기본적인 입력 위젯으로 푸시 버튼 형태로 GUI 프로그램에서 사용자와의 인터페이스를 제공하는 기본 위젯
 * - 명령 버튼(command button) 이라고도 함
 */

#include <QApplication>
#include <QPushButton>

int main(int argc,char* argv[]){
    QApplication a(argc, argv);

    QPushButton* pushButton = new QPushButton("Push&QAbstractButton", 0 );
    pushButton->setCheckable(true);
    // 첫 클릭 시 toggle 로 false, 두 번째 클릭 시 toggle 인데 false 이므로 a.quit() 실행됨
    QObject::connect(pushButton, &QPushButton::toggled,
                     [&](bool flag){qDebug() << "toggled"; if(!flag) a.quit();});
    pushButton->show();

    return a.exec();
}
