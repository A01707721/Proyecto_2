#ifndef Hospital_H
#define Hospital_H

#include <iostream>
#include <string>
#include <sstream>
#include "Doctor.h"

//Clase Hospital
class Hospital{
    private:
    //Atributos
    std::string name;
    //Composición por parte de la clase Employee
    Employee * E[100];
    int num_e;
    //Agregación por part de la clase Patient
    Patient Pa[150];
    int num_p;
    public:
    //Constructor default
    Hospital():name(""),num_e(0),num_p(0){};
    //Constructor
    Hospital(std::string n):name(n),num_e(0),num_p(0){};
    //Getters y Setters
    std::string get_name();
    void set_name(std::string);
    void set_d(std::string,int,int);
    void set_d(std::string,int,int,std::string);
    void set_pe(std::string n,int a, int h, int j);
    Patient get_patient(int);
    void set_patient(Patient &);
    //Metodos
    void employees();
    void patients();
    void doctors();
    void others();
};
std::string Hospital::get_name(){
    return name;
}
void Hospital::set_name(std::string n){
    name=n;
}
void Hospital::set_d(std::string n,int a, int h){
    E[num_e]= new Doctor(n,a,h);
    num_e++;
}
void Hospital::set_d(std::string n,int a, int h,std::string s){
    E[num_e]= new Doctor(n,a,h,s);
    num_e++;
}
void Hospital::set_pe(std::string n,int a, int h, int j){
    E[num_e]= new Personal(n,a,h,j);
    num_e++;
}
Patient Hospital::get_patient(int n){
    return Pa[n];
}
void Hospital::set_patient(Patient &Pat){
    Pa[num_p]=Pat;
    num_p++;
}
void Hospital::employees(){
    std::cout << name << " " << "Employees:" << std::endl;
    for(int i=0;i<num_e;i++){
        std::cout << std::endl << i+1 << ".- " << E[i]->to_stream() << "payment: " << E[i]->pay() << std::endl;
    }
}
void Hospital::patients(){
    std::cout << name << " " << "Patients:" << std::endl;
    for(int i=0;i<num_p;i++){
        std::cout << std::endl << i+1 << ".- " << Pa[i].to_string() << std::endl;
    }
}
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
