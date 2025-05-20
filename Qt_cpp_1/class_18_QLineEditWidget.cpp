/* 문자열 입력 위젯 : QLineEdit, QTextEdit, QComboBox 위젯으로 나뉨
 * QLineEdit : 한 줄로된 문자열을 입력받을 때 사용
 * echoMode
 *  - Normal(default) : 그대로 출력
 *  - NoEcho : 입력 문자열을 화면에 표시 안함
 *  - Password : * 기호로 바꿔서 출력
 *
 */
#include <QApplication>
#include <QLineEdit>

#include <QCompleter>

int main(int argc, char* argv[]){
    QApplication a(argc,argv);

    /*
    QLineEdit* lineEdit = new QLineEdit();
    // echomode 설정(password)
    //lineEdit -> setEchoMode(QLineEdit::Password);
    lineEdit->setInputMask("000");
    lineEdit->setPlaceholderText("input the number");
    //lineEdit->show();
    */

    // QCompleter 클래스 : 자동 완성을 위한 목록을 제공
    QLineEdit* lineEdit = new QLineEdit();
    QStringList CompletionList;
    CompletionList << "Bryan" << "Bart" << "Kelvin" << "Beth" << "Brad" << "Kelly";
    QCompleter* stringCompleter = new QCompleter(CompletionList, lineEdit);
    stringCompleter->setCaseSensitivity(Qt::CaseInsensitive); //
    lineEdit->setCompleter(stringCompleter);
    lineEdit->show();

    return a.exec();
}
