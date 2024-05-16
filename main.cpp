#include <iostream>
#include <string>
#include "Hospital.h"
#include "Doctor.h"
void menu(){
    std::cout << "Treatment" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
}
int main(){
    int n=0;
    Personal Clark;
    Clark.set_name("Clark");
    Clark.set_age(43);
    Clark.set_hours(31);
    Clark.set_job(1);
    Doctor John;
    John.set_name("John");
    John.set_age(35);
    John.set_hours(56);
    John.set_specialty("General MD");
    std::cout << John.get_name() << " " << John.get_specialty() << std::endl;
    Patient Ana;
    Ana.set_name("Ana");
    Ana.set_age(26);
    Ana.set_status("Sick");
    John.set_patient(Ana);
    std::cout << "Patient " << John.get_patient(0).get_name() << " status: " << John.get_patient(0).get_status() << std::endl;
    menu();
    std::cin >> n;
    if(n==1){
        John.treatment(0);
        std::cout << "Patient " << John.get_patient(0).get_name() << " status: " << John.get_patient(0).get_status() << std::endl;
        std::cout << John.get_patient(0).get_name() << " Medical bill: " << John.get_patient(0).bill() << std::endl;
    }
    else{
        std::cout << "Patient " << John.get_patient(0).get_name() << " status: " << John.get_patient(0).get_status() << std::endl;
    }
    return 0;
}
