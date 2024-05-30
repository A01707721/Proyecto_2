#ifndef Doctor_H
#define Doctor_H

#include <iostream>
#include <string>
#include <sstream>

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


//Clase padre
class Employee{
    private:
    //Atributos
    std::string name;
    int age;
    public:
    int hours;
    std::string type;
    //Constructor Default
    Employee():name(""),age(0),hours(0),type(""){};
    //Constructor
    Employee(std::string n, int a, int h, std::string t);
    //Getteres y Setters
    std::string get_name();
    int get_age();
    int get_hours();
    std::string get_type();
    void set_name(std::string);
    void set_age(int);
    void set_hours(int);
    //Metodo
    void work(int);
    //Metodos abstractos seran sobreescritos 
    virtual float pay()=0;
    virtual std::string to_stream()=0;
};
Employee::Employee(std::string n, int a, int h, std::string t){
    name=n;
    age=a;
    hours=h;
    type=t;
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
std::string Employee::get_type(){
    return type;
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


//Clase hijo de Employee
class Doctor: public Employee{
    //Atributos
    private:
    std::string specialty;
    public:
    //Constructor Default
    Doctor():Employee("",0,0,"Doctor"),specialty(""){};
    //Constructor con sobrecarga
    Doctor(std::string n, int a, int h, std::string s):Employee(n,a,h,"Doctor"){
        specialty=s;
    }
    //Constructor
    Doctor(std::string n, int a, int h):Employee(n,a,h,"Doctor"){
        specialty="General Md";
    }
    //Getters y Setters
    std::string get_specialty();
    std::string get_type();
    void set_specialty(std::string);
    //Metodos sobreescritos de la clase padre
    float pay();
    std::string to_stream();
};
std::string Doctor::get_specialty(){
    return specialty;
}
void Doctor::set_specialty(std::string s){
    specialty=s;
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
    Personal():Employee("",0,0,"Personal"),job(1){};
    //Constructor con sobrecarga
    Personal(std::string n, int a, int h, int j):Employee(n,a,h,"Personal"){
        job=j;
    }
    //Constructor
    Personal(std::string n, int a, int h):Employee(n,a,h,"Personal"){
        job=1;
    }
    //Getters y Setters
    int get_job();
    std::string get_type();
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
    if(job==1){
        aux << "Janitor " << get_name() << " payment: " << pay() << std::endl;
    }
    if(job==2){
        aux << "Management " << get_name() << " payment: " << pay() << std::endl;
    }
    if(job==3){
        aux << "Nurse " << get_name() << " payment: " << pay() << std::endl;
    }
    
    return aux.str();
}


#endif
