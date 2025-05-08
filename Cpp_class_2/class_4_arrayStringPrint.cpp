#include <iostream>
int main(void){
    char name[100];
    char lang[200];

    std::cout<<"name : ";
    std::cin>>name;
    std::cout<<"like programming lang: ";
    std::cin>>lang;
    std::cout<<"name : "<<name<<".\n";
    std::cout<<"like lang: "<<lang<<".\n"<<std::endl;

    return 0;
}
