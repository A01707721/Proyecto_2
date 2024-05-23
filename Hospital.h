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
    //Agregacion por parte de la clase Doctor y Personal
    Doctor D[50];
    Personal Pe[50];
    int num_d;
    int num_p;
    public:
    //Constructor default
    Hospital():name(""),num_d(0),num_p(0){};
    //Constructor
    Hospital(std::string n):name(n),num_d(0),num_p(0){};
    //Getters y Setters
    std::string get_name();
    Doctor get_d(int);
    Personal get_p(int);
    void set_name(std::string);
    void set_d(Doctor &);
    void set_p(Personal &);
    void employed_Doctors();
    void employed_Personal();
};
std::string Hospital::get_name(){
    return name;
}
Doctor Hospital::get_d(int nd){
    return D[nd];
}
Personal Hospital::get_p(int np){
    return Pe[np];
}
void Hospital::set_d(Doctor &Do){
    D[num_d]=Do;
    num_d++;
}
void Hospital::set_p(Personal &Per){
    Pe[num_p]=Per;
    num_p++;
}
void Hospital::employed_Doctors(){
    std::cout << name << " " << "Doctors:" << std::endl;
    for(int i=0;i<num_d;i++){
        std::cout << i << ".- " << D[i].to_stream() << "payment: " << D[i].pay() << std::endl;
    }
}
void Hospital::employed_Personal(){
    std::cout << name << " " << "Personal:" << std::endl;
    for(int i=0; i<num_p;i++)
        std::cout << i << ".- " << Pe[i].to_stream() << std::endl;
    
}
#endif

