#ifndef Doctor_H
#define Doctor_H

#include <iostream>
#include <string>
#include <sstream>

//Clase padre
class Employee{
    private:
    //Atributos
    std::string name;
    int age;
    public:
    int hours;
    //Constructor Default
    Employee():name(""),age(0),hours(0){};
    //Constructor
    Employee(std::string n, int a, int h);
    //Getteres y Setters
    std::string get_name();
    int get_age();
    int get_hours();
    void set_name(std::string);
    void set_age(int);
    void set_hours(int);
    //Metodo
    void work(int);
    //Metodos abstractos seran sobreescritos 
    float pay();
    std::string to_stream();
};
Employee::Employee(std::string n, int a, int h){
    name=n;
    age=a;
    hours=h;
}
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
    public:
    std::string status;
    //Constructor Default
    Patient():name(""),age(0),status(""){};
    //Constructor con sobrecarga
    Patient(std::string n, int a, std::string s);
    //Constructor 
    Patient(std::string n, int a);
    //Getters y Setters
    std::string get_name();
    int get_age();
    std::string get_status();
    void set_name(std::string);
    void set_age(int);
    void set_status(std::string);
    //Metodos
    void die();
    float bill();
    std::string to_string();
};
Patient::Patient(std::string n,int a, std::string s){
    name=n;
    age=a;
    status=s;
}
Patient::Patient(std::string n, int a){
    name=n;
    age=a;
    status="Sick";
}
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
    set_status("Dead");
}
float Patient::bill(){
    float total=500;
    return total;
}
std::string Patient::to_string(){
    std::stringstream aux;
    aux << "Patient: " << get_name() << std::endl << "status: " << status << std::endl;
    return aux.str();
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
    //Constructor con sobrecarga
    Doctor(std::string n, int a, int h, std::string s):Employee(n,a,h){
        specialty=s;
        num_patient=0;
    }
    //Constructor
    Doctor(std::string n, int a, int h):Employee(n,a,h){
        specialty="General Md";
        num_patient=0;
    }
    //Getters y Setters
    std::string get_specialty();
    Patient get_patient(int);
    void set_specialty(std::string);
    void set_patient(Patient &);
    //Metodos
    void treatment(int);
    void patients();
    //Metodos sobreescritos de la clase padre
    float pay();
    std::string to_stream();
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
void Doctor::patients(){
    for(int i=0;i<num_patient;i++){
        std::cout << i << ".- " << P[i].to_string() << std::endl;
    }
}
float Doctor::pay(){
    float payment=0;
    if(specialty=="General Md"){
        payment=(hours*250);
    }
    else{
       payment=(hours*500); 
    }
    return payment;
}
std::string Doctor::to_stream(){
    std::stringstream aux;
    aux << "Doctor " << get_name() << " " << specialty << std::endl;
    return aux.str();
}

//Clase hijo de Employee
class Personal: public Employee{
    //Atributos
    private:
    int job;
    public:
    //Constructor default
    Personal():Employee(),job(1){};
    //Constructor con sobrecarga
    Personal(std::string n, int a, int h, int j):Employee(n,a,h){
        job=j;
    }
    //Constructor
    Personal(std::string n, int a, int h):Employee(n,a,h){
        job=1;
    }
    //Getters y Setters
    int get_job();
    void set_job(int);
    //Metodos sobreescritos de la clase padre
    float pay();
    std::string to_stream();
};
int Personal::get_job(){
    return job;
}
void Personal::set_job(int j){
    job=j;
}
float Personal::pay(){
    float payment=0;
    payment=hours*50*job;
    return payment;
}
std::string Personal::to_stream(){
    std::stringstream aux;
    aux << "Personal " << get_name() << " payment: " << pay() << std::endl;
    return aux.str();
}


#endif
