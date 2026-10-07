#include <iostream>

int main()
{
    int god{}, brojac{0};
    std::string ime{};
    std::cout<<"Upisi godinu rodenja: ";
    std::cin>> god;
    std::cout<<2026-god<<"\n";
    std::cout<<"Upisi ime i prezime: ";
    std::cin.ignore();
    std::getline(std::cin, ime);
    int razmak = ime.find(' ');
    std::cout<<ime[0]<<" "<<ime[razmak+1]<<"\n";
    
    for(char znak : ime){
        if(znak != ' '){
            brojac++;
        }
    }
    std::cout<<"Broj slova: " << brojac;
    return 0;
}