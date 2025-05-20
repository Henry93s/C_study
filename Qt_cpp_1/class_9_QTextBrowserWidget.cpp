#include <QApplication>
#include <QTextBrowser>
#include <QUrl>
/*
 * QTextBrowser : QTextEdit 클래스를 상속받음
 * 문서를 구성할 때 기본적으로 사용하는 하이퍼텍스트를 표시할 때 사용
 */
int main(int argc, char* argv[]){
    QApplication a(argc, argv);

    QTextBrowser* tb = new QTextBrowser();
    tb->setSource(QUrl("index.html")); // project browser 경로에 해당 파일이 있어야 함
    tb->show();

    return a.exec();
}
