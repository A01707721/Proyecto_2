#include <iostream>
#include <string>
#include "Doctor.h"
#include "Hospital.h"
//Menu inicial
void menu_0(){  
    std::cout << std::endl;  
    std::cout << "Hospital" << std::endl;
    std::cout << "1. Doctors" << std::endl;
    std::cout << "2. Personal" << std::endl;
    std::cout << "3. Patients" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

//main
int main(){
    //Variables para navegar los menus
    bool cond=true;
    int n=0;
    int n_0=0;
    int n_1=0;
    //Creacion del objeto tipo Hospital
    Hospital Sunny("Sunny Hospital"); 
    //Creacion del objeto tipo Personel
    Personal Clark_Pe;
    Clark_Pe.set_name("Clark");
    Clark_Pe.set_age(43);
    Clark_Pe.set_hours(31);
    Clark_Pe.set_job(1);
    //Creacion de dos objetos tipo Patient
    Doctor John_Dr("John",35,56);
    Doctor Angela_Dr("Angela", 43, 48,"Cardiologist");
    //Creacion de tres objetos tipo Patient
    Patient Ana_Pa("Ana",24);
    Patient Greg_Pa("Greg",65,"Medical Discharge");
    Patient Mark_Pa("Mark",36,"ICU");
    //Agregacion de objetos tipo Patient a objetos tipo Doctor
    John_Dr.set_patient(Ana_Pa);
    John_Dr.set_patient(Greg_Pa);
    Angela_Dr.set_patient(Mark_Pa);
    //Agregacion de objetos tipo Doctor y Personel a objeto tipo Hospital
    Sunny.set_p(Clark_Pe);
    Sunny.set_d(John_Dr);
    Sunny.set_d(Angela_Dr);
    //Ciclo while para mostrar el menu inicial
    while(cond==true){
        menu_0();
        std::cout << "Select: " << std::endl;
        std::cin >> n_0;
        if(n_0==1){
            //Imprime datos de los objetos tipo Doctor 
            Sunny.employed_Doctors();
        }
        if(n_0==2){
            //Imprime datos de los objetos tipo Personel
            Sunny.employed_Personal();
        }
        if(n_0==3){
            Sunny.employed_Doctors();
            std::cout << "Select the number of the doctor to see their patients: ";
            std::cin >> n_1;
            //Imprime datos de los objetos tipo Patient 
            Sunny.get_d(n_1).patients();
        }
        if(n_0==4){
            //Rompe el ciclo while
            cond=false;
        }
    }
    
    return 0;
}
