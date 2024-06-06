/* 
* Proyecto Hospital
* Adrian Marquez Nunez
* A01707721
* 5/06/2024
*/
#ifndef Hospital_H
#define Hospital_H
//Bibliotecas
#include <iostream>
#include <string>
#include <sstream>
#include "Doctor.h"

/**Clase Hospital que maneja datos del hospital sus empleados y pacientes
*y da la capacidad de ver la info de los mismos
*/ 

//Declaracion de la clase Hospital
class Hospital{
    private:
    //atributos de la clase: nombre del hospital (name), lista de empleados (E), lista de pacientes (Pa)
    std::string name;
    //Composición por parte de la clase Employee (polimorfismo de Doctor y Personal)
    Employee * E[100];
    //Numero para crear empleados
    int num_e;
    //Agregación por parte de la clase Patient
    Patient Pa[150];
    //Numero para agregar pacientes
    int num_p;
    public:
    /**Constructor default 
    *@param
    *@return objeto Hospital
    */
    Hospital():name(""),num_e(0),num_p(0){};
    /**Constructor donde se reciben las variables para los diferentes atributos
    *@param string n: el nombre del hospital
    *@return objeto Hospital
    */
    Hospital(std::string n):name(n),num_e(0),num_p(0){};
    //Getters 
    std::string get_name();
    Patient get_patient(int);
    void set_name(std::string);
    //Setters
    void set_d(std::string,int,int);
    void set_d(std::string,int,int,std::string);
    void set_pe(std::string n,int a, int h, int j);
    void set_patient(Patient &);
    //Metodos para imprimir datos
    void employees();
    void patients();
    void doctors();
    void others();
};

/**Getter nombre del hospital
*@param 
*@return string:nombre 
*/
std::string Hospital::get_name(){
    return name;
}

/**Setter nombre del hospital
*@param string:nombre 
*@return 
*/
void Hospital::set_name(std::string n){
    name=n;
}

/**Setter doctor
*@param string:nombre, int:edad, int:horas trabajadas
*@return 
*/
void Hospital::set_d(std::string n,int a, int h){
    E[num_e]= new Doctor(n,a,h);
    num_e++;
}

/**Setter doctor con sobrecarga
*@param string:nombre, int:edad, int:horas trabajadas, string:especialidad medica
*@return 
*/
void Hospital::set_d(std::string n,int a, int h,std::string s){
    E[num_e]= new Doctor(n,a,h,s);
    num_e++;
}

/**Setter personal
*@param string:nombre, int:edad, int:horas trabajadas, int:tipo de trabajo
*@return 
*/
void Hospital::set_pe(std::string n,int a, int h, int j){
    E[num_e]= new Personal(n,a,h,j);
    num_e++;
}

/**Getter doctor
*@param int:numero de paciente
*@return Patient:paciente
*/
Patient Hospital::get_patient(int n){
    return Pa[n];
}

/**Setter paaciente
*@param Patient:paciente
*@return 
*/
void Hospital::set_patient(Patient &Pat){
    Pa[num_p]=Pat;
    num_p++;
}

/**Imprime datos de los empleados
*@param
*@return 
*/
void Hospital::employees(){
    std::cout << name << " " << "Employees:" << std::endl;
    for(int i=0;i<num_e;i++){
        std::cout << std::endl << i+1 << ".- " << E[i]->to_stream() << "payment: " << E[i]->pay() << std::endl;
    }
}

/**Imprime datos de los pacientes
*@param
*@return 
*/
void Hospital::patients(){
    std::cout << name << " " << "Patients:" << std::endl;
    for(int i=0;i<num_p;i++){
        std::cout << std::endl << i+1 << ".- " << Pa[i].to_string() << std::endl;
    }
}

/**Imprime datos de los empleados tipo doctor
*@param
*@return 
*/
void Hospital::doctors(){
    int cont=1;
    std::cout << name << " " << "Doctors:" << std::endl;
    for(int i=0;i<num_e;i++){
        if(E[i]->get_type()=="Doctor"){
            std::cout << std::endl << cont << ".- " << E[i]->to_stream() << "payment: " << E[i]->pay() << std::endl;
            cont++;
        }   
    }
}

/**Imprime datos de los empleados tipo personal
*@param
*@return 
*/
void Hospital::others(){
    int cont=1;
    std::cout << name << " " << "Personal:" << std::endl;
    for(int i=0;i<num_e;i++){
        if(E[i]->get_type()=="Personal"){
            std::cout << std::endl << cont << ".- " << E[i]->to_stream() << "payment: " << E[i]->pay() << std::endl;
            cont++;
        }   
    }
}

#endif
