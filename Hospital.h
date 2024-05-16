#ifndef Hospital_H
#define Hospital_H

#include <iostream>
#include <string>
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
    Hospital():name(""){};
    //Getters y Setters
    std::string get_name();
    Doctor get_d(int);
    Personal get_p(int);
    void set_name(std::string);
    void set_d(Doctor &);
    void set_p(Personal &);
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
#endif
