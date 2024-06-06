/* 
* Proyecto Hospital
* Adrian Marquez Nunez
* A01707721
* 5/6/2024
*/

//Bibliotecas
#include <iostream>
#include <string>
//Para implementar objetos tipo Employyee, Doctor, Patient y Personal
#include "Doctor.h"
//Para implementar objetos tipo Hospital
#include "Hospital.h"

//Menu inicial
void menu_0(){  
    std::cout << std::endl;  
    std::cout << "Hospital" << std::endl;
    std::cout << "1. Employees" << std::endl;
    std::cout << "2. Doctors" << std::endl;
    std::cout << "3. Personal" << std::endl;
    std::cout << "4. Patients" << std::endl;
    std::cout << "5. Add employee" << std::endl;
    std::cout << "6. Exit" << std::endl;
}

//Menu 1 en caso de que se selccione la opcion 6 del menu inicial
void menu_1(){
    std::cout << "Add employee" << std::endl;
    std::cout << "1. Add Doctor" << std::endl;
    std::cout << "2. Add Personal" << std::endl;
}

/*Este proyecto simula un hopsital que cuenta con un maximo de 100 empleados y 50 pacientes
* y que cuenta con funciones para ver los datos de estos mismos o bien agregar mas empleados
*/
int main(){
    //Variables bool para que se siga proyectando el menu
    bool cond=true;
    //Variable int para elegir que accion del menu realizar
    int n_0=0, n_1=1;
    std::string n="",s="";
    int a=0,h=0,j=0;
    //Creacion del objeto tipo Hospital
    Hospital Sunny("Sunny Hospital"); 
    //Composicion de 3 objetos tipo Personel dentro del objeto Hospital
    Sunny.set_pe("Clark",43,31,1);
    Sunny.set_pe("Michael",56,27,2);
    Sunny.set_pe("Jeniffer",28,45,3);
    //Composicion de tres objetos tipo Doctor dentro del objeto Hospital
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
    //Ciclo while para mostrar el menu inicial hasta que se eliga la opcion 6.Exit
    while(cond==true){
        //Impresion menu inicial
        menu_0();
        //Seleccionar opcion
        std::cout << "Select: " << std::endl;
        std::cin >> n_0;
        //Condicional si se elige la opcion 1. Employees
        if(n_0==1){
            //Imprime datos de todos los objetos tipo Employee 
            Sunny.employees();
        }
        //Condicional si se elige la opcion 2. Doctors
        if(n_0==2){
            //Imprime unicamente datos de los objetos tipo Doctor
            Sunny.doctors();
        }
        //Condicional si se elige la opcion 3. Personal
        if(n_0==3){
            //Imprime unicamente datos de los objetos tipo Personal 
            Sunny.others();
        }
        //Condicional si se elige la opcion 4. Patients
        if(n_0==4){
            //Imprime datos de los objetos tipo Patient 
            Sunny.patients();
        }
        //Condicional si se elige la opcion 5. Add employee
        if(n_0==5){
            //Impresion menu 1
            menu_1();
            //Seleccionar opcion
            std::cout << "Select: " << std::endl;
            std::cin >> n_1;
            //Condicional si se elige la sub-opcion 1. Add Doctor
            if(n_1==1){
                std::cout << "Add Doctor" << std::endl;
                //Ingresa el nombre
                std::cout << "Name: ";
                std::cin >> n;
                //Ingresa la edad
                std::cout << "Age: ";
                std::cin >> a;
                //Ingresa la especialidad, en caso de que no se ingresa NONE y se crea como General MD
                std::cout << "Specialty (if none type NONE): ";
                std::cin >> s;
                //Composicion de doctor con constructor simple en caso de que no haya especialidad
                if(s=="NONE"){
                    Sunny.set_d(n,a,0);
                }
                //Composicion de doctor con constructor con sobrecarga en caso de que haya especialidad
                else{
                    Sunny.set_d(n,a,0,s);
                }
            }
            //Condicional si se elige la sub-opcion 2. Add Personal
            if(n_1==2){
                std::cout << "Add Personal" << std::endl;
                //Ingresa el nombre
                std::cout << "Name: ";
                std::cin >> n;
                //Ingresa la edad
                std::cout << "Age: ";
                std::cin >> a;
                //Ingresa el tipo de trabajo 1 para conserje, 2 para administrativo, 3 para enfermero
                std::cout << "Type of job (1 for Janitor, 2 for Managemnet, 3 for Nurse): ";
                std::cin >> j;
                //Composicion de Personal con constructor simple
                Sunny.set_pe(n,a,0,j);
            }

        }
        //Condicional si se elige la opcion 6. Exit
        if(n_0==6){
            //Rompe el ciclo while y acaba el programa
            cond=false;
        }
    }
    return 0;
}
