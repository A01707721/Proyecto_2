#include <iostream>
#include <string>
#include "Doctor.h"
#include "Hospital.h"
//Menu inicial
void menu_0(){  
    std::cout << std::endl;  
    std::cout << "Hospital" << std::endl;
    std::cout << "1. Employees" << std::endl;
    std::cout << "2. Doctors" << std::endl;
    std::cout << "3. Personal" << std::endl;
    std::cout << "4. Patients" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

//main
int main(){
    //Variables para navegar los menus
    bool cond=true;
    int n_0=0;
    //Creacion del objeto tipo Hospital
    Hospital Sunny("Sunny Hospital"); 
    //Creacion de 3 objetos tipo Personel
    Sunny.set_pe("Clark",43,31,1);
    Sunny.set_pe("Michael",56,27,2);
    Sunny.set_pe("Jeniffer",28,45,3);
    //Creacion de tres objetos tipo Doctor
    Sunny.set_d("John",35,56);
    Sunny.set_d("Angela", 43, 48,"Cardiologist");
    Sunny.set_d("William", 29, 37,"Inmunologist");
    //Creacion de tres objetos tipo Patient
    Patient Ana_Pa("Ana",24);
    Patient Greg_Pa("Greg",65,"Medical Discharge");
    Patient Mark_Pa("Mark",36,"ICU");
    //Agregacion de objetos tipo Patient a objeto tipo Hospital
    Sunny.set_patient(Ana_Pa);
    Sunny.set_patient(Greg_Pa);
    Sunny.set_patient(Mark_Pa);
    //Ciclo while para mostrar el menu inicial
    while(cond==true){
        menu_0();
        std::cout << "Select: " << std::endl;
        std::cin >> n_0;
        if(n_0==1){
            //Imprime datos de todos los objetos tipo Employee 
            Sunny.employees();
        }
        if(n_0==2){
            //Imprime datos de los objetos tipo Doctor
            Sunny.doctors();
        }
        if(n_0==3){
            //Imprime datos de los objetos tipo Personal 
            Sunny.others();
        }
        if(n_0==4){
            //Imprime datos de los objetos tipo Patient 
            Sunny.patients();
        }
        if(n_0==5){
            //Rompe el ciclo while
            cond=false;
        }
    }
    return 0;
}
