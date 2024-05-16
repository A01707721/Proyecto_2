#ifndef Doctor_H
#define Doctor_H

#include <iostream>
#include <string>
#include "Hospital.h"

//Clase padre
class Employee{
    private:
    //Atributos
    std::string name;
    int age;
    int hours;
    public:
    //Constructor Default
    Employee():name(""),age(0){};
    //Getteres y Setters
    std::string get_name();
    int get_age();
    int get_hours();
    void set_name(std::string);
    void set_age(int);
    void set_hours(int);
    void work(int);
};
std::string Employee::get_name(){
    return name;
}
int Employee::get_age(){
    return age;
}
int Employee::get_hours(){
    return hours;
}
void Employee::set_name(std::string n){
    name=n;
}
void Employee::set_age(int a){
    age=a;
}
void Employee::set_hours(int h){
    hours=h;
}
void Employee::work(int w){
    hours=hours+w;
}

//Clase Paciente
class Patient{
    //Atributos
    private:
    std::string name;
    int age;
    std::string status;
    public:
    //Constructor Default
    Patient():name(""),age(0),status(""){};
    //Getters y Setters
    std::string get_name();
    int get_age();
    std::string get_status();
    void set_name(std::string);
    void set_age(int);
    void set_status(std::string);
    void die();
    float bill();
};
std::string Patient::get_name(){
    return name;
}
int Patient::get_age(){
    return age;
}
std::string Patient::get_status(){
    return status;
}
void Patient::set_name(std::string n){
    name=n;
}
void Patient::set_age(int a){
    age=a;
}
void Patient::set_status(std::string s){
    status=s;
}
void Patient::die(){
    status="Dead";
}
float Patient::bill(){
    float total=500;
    return total;
}

//Clase hijo de Employee
class Doctor: public Employee{
    //Atributos
    private:
    std::string specialty;
    //Agregacion por parte de la clase Patient
    Patient P[3];
    int num_patient;
    public:
    //Constructor Default
    Doctor():Employee(),specialty(""),num_patient(0){};
    //Getters y Setters
    std::string get_specialty();
    Patient get_patient(int);
    void set_specialty(std::string);
    void set_patient(Patient &);
    void treatment(int);
};
std::string Doctor::get_specialty(){
    return specialty;
}
Patient Doctor::get_patient(int num){
    return P[num];
}
void Doctor::set_specialty(std::string s){
    specialty=s;
}
void Doctor::set_patient(Patient &Pa){
    P[num_patient]=Pa;
    num_patient++;
}
void Doctor::treatment(int num){
    P[num].set_status("Medical Discharge");
}

//Clase hijo de Employee
class Personal: public Employee{
    //Atributos
    private:
    int job;
    public:
    //Constructor default
    Personal():Employee(),job(0){};
    //Getters y Setters
    int get_job();
    void set_job(int);
};
int Personal::get_job(){
    return job;
}
void Personal::set_job(int j){
    job=j;
}


#endif
