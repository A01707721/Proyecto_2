/* 
* Proyecto Hospital
* Adrian Marquez Nunez
* A01707721
* 4/06/2024
*/
#ifndef Doctor_H
#define Doctor_H
//Bibliotecas
#include <iostream>
#include <string>
#include <sstream>

/**Clase Patient que maneja datos de los pacientes con su nombre, edad, y estatus medico 
*y da la capacidad de que el paciente muera y calcula la cuenta
*/ 

//Declaracion clase Patient
class Patient{
    //atributos de la clase: nombre del paciente (name), edad (age), estatus medico (status)
    private:
    std::string name;
    int age;
    public:
    std::string status;
    /**Constructor default 
    *@param
    *@return objeto Patient
    */
    Patient():name(""),age(0),status(""){};
    //Constructor con sobrecarga donde se reciben las variables para los diferentes atributos incluyendo estatus
    Patient(std::string n, int a, std::string s);
    //Constructor donde se reciben las variables para los diferentes atributos
    Patient(std::string n, int a);
    //Getters
    std::string get_name();
    int get_age();
    std::string get_status();
    //Setters
    void set_name(std::string);
    void set_age(int);
    void set_status(std::string);
    //Metodo para cambiar el estatus del paciente a Dead
    void die();
    //Metodo para calcular la cuenta del paciente
    float bill();
    //Metodo para convertir los datos del objeto en una cadena de texto
    std::string to_string();
};

/**Constructor con sobrecarga 
*@param string n: el nombre del paciente, int a: edad, string s: estatus del paciente
*@return objeto Patient
*/ 
Patient::Patient(std::string n,int a, std::string s){
    name=n;
    age=a;
    status=s;
}

/**Constructor donde se reciben las variables para los diferentes atributos
*@param string n: el nombre del paciente, int a: edad
*@return objeto Patient
*/
Patient::Patient(std::string n, int a){
    name=n;
    age=a;
    status="Sick";
}

/**Getter nombre del paciente
*@param 
*@return string:nombre
*/
std::string Patient::get_name(){
    return name;
}

/**Getter edad
*@param 
*@return int:edad
*/
int Patient::get_age(){
    return age;
}

/**Getter estatus del paciente
*@param 
*@return string:estatus medico
*/
std::string Patient::get_status(){
    return status;
}

/**Setter nombre del paciente
*@param string:nombre
*@return
*/
void Patient::set_name(std::string n){
    name=n;
}

/**Setter edad
*@param 
*@return int:edad
*/
void Patient::set_age(int a){
    age=a;
}

/**Setter estatus del paciente
*@param string:esatus medico
*@return
*/
void Patient::set_status(std::string s){
    status=s;
}

/**Metodo para modificar el estatus del paciente a Dead
*@param
*@return 
*/
void Patient::die(){
    set_status("Dead");
}

/**Metodo pay calcula la cuenta del paciente
*@param
*@return float: cuenta del paciente
*/
float Patient::bill(){
    float total=500;
    return total;
}

/**Almacena los datos del objeto Patient en una cadena de texto
*@param 
*@return string:datos del paciente
*/
std::string Patient::to_string(){
    std::stringstream aux;
    aux << "Patient: " << get_name() << std::endl << "status: " << status << std::endl;
    return aux.str();
}


/**Clase abtracta Employee que contiene los metodos y atributos basicos sobre los empleados y hereda a 2 clases:
*Doctor y Personal que forman la nomina del hotel
*/

//Declaracion clase abstracta Employee
class Employee{
    private:
    //atributos de la clase: nombre del paciente (name), edad (age), horas trabajo (hours), tipo de empleado (type)
    std::string name;
    int age;
    public:
    int hours;
    std::string type;
    /**Constructor default 
    *@param
    *@return objeto Employee
    */
    Employee():name(""),age(0),hours(0),type(""){};
    //Constructor donde se reciben las variables para los diferentes atributos
    Employee(std::string n, int a, int h, std::string t);
    //Getteres
    std::string get_name();
    int get_age();
    int get_hours();
    std::string get_type();
    //Setters
    void set_name(std::string);
    void set_age(int);
    void set_hours(int);
    //Metodo para agregar horas de trabajo
    void work(int);
    //Metodos que hacen a la clase abstracta, seran sobreescritos 
    virtual float pay()=0;
    virtual std::string to_stream()=0;
};

/**Constructor donde se reciben las variables para los diferentes atributos
*@param string n: el nombre del empleado, int a: edad, int h: horas de trabajo, string t: tipo de empleado
*@return objeto Employee
*/
Employee::Employee(std::string n, int a, int h, std::string t){
    name=n;
    age=a;
    hours=h;
    type=t;
}

/**Getter nombre del empleado
*@param 
*@return string:nombre 
*/
std::string Employee::get_name(){
    return name;
}

/**Getter edad
*@param 
*@return int:edad
*/
int Employee::get_age(){
    return age;
}

/**Getter horas de trabajo
*@param 
*@return int:horas
*/
int Employee::get_hours(){
    return hours;
}

/**Getter tipo de empleado
*@param 
*@return string:tipo de empleado
*/
std::string Employee::get_type(){
    return type;
}

/**Setter nombre del empleado
*@param string:nombre
*@return
*/
void Employee::set_name(std::string n){
    name=n;
}

/**Setter edad
*@param int:edad
*@return
*/
void Employee::set_age(int a){
    age=a;
}

/**Setter horas de trabajo
*@param int:horas
*@return
*/
void Employee::set_hours(int h){
    hours=h;
}

/**Metodo que suma horas a las horas de trabajo
*@param int:horas extras
*@return
*/
void Employee::work(int w){
    hours=hours+w;
}


//Declaracion de la clase Doctor que hereda de la clase abstracta Employee
class Doctor: public Employee{
    //atributos de la clase: especialidad medica (specialty)
    private:
    std::string specialty;
    public:
    /**Constructor default
    *@param 
    *@return objeto Doctor
    */
    Doctor():Employee("",0,0,"Doctor"),specialty(""){};
    /**Constructor con sobrecarga 
    *@param string n: el nombre del empleado, int a: edad, int h: horas trabajadas, string t: tipo de empleado, s: especialidad medica
    *@return objeto Doctor
    */ 
    Doctor(std::string n, int a, int h, std::string s):Employee(n,a,h,"Doctor"){
        specialty=s;
    }
    /**Constructor donde se reciben las variables para los diferentes atributos
    *@param string n: el nombre del empleado, int a: edad, int h: horas de trabajo, string t: tipo de empleado
    *@return objeto Doctor
    */
    Doctor(std::string n, int a, int h):Employee(n,a,h,"Doctor"){
        specialty="General Md";
    }
    //Getters
    std::string get_specialty();
    std::string get_type();
    //Setters
    void set_specialty(std::string);
    //Metodos sobreescritos de la clase abstracta
    float pay();
    std::string to_stream();
};

/**Getter especialidad medica
*@param 
*@return string:especialidad
*/
std::string Doctor::get_specialty(){
    return specialty;
}

/**Setter especialidad medica
*@param string:especialidad
*@return 
*/
void Doctor::set_specialty(std::string s){
    specialty=s;
}

/**Metodo que calcula la paga en base a las horas trabajadas y si se tiene especialidad
*@param 
*@return float:paga del doctor
*/
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

/**Almacena los datos del objeto Doctor en una cadena de texto
*@param 
*@return string:datos del doctor
*/
std::string Doctor::to_stream(){
    std::stringstream aux;
    aux << "Doctor " << get_name() << " " << specialty << std::endl;
    return aux.str();
}

//Declaracion de la clase Personal que hereda de la clase abstracta Employee
class Personal: public Employee{
    //atributos de la clase: tipo de trabajo (job)
    private:
    int job;
    public:
    /**Constructor default
    *@param 
    *@return objeto Personal
    */
    Personal():Employee("",0,0,"Personal"),job(1){};
    /**Constructor con sobrecarga 
    *@param string n: el nombre del empleado, int a: edad, int h: horas trabajadas, string t: tipo de empleado, int j: tipo de trabajo
    *@return objeto Personal
    */ 
    Personal(std::string n, int a, int h, int j):Employee(n,a,h,"Personal"){
        job=j;
    }
    /**Constructor donde se reciben las variables para los diferentes atributos
    *@param string n: el nombre del empleado, int a: edad, int h: horas de trabajo, string t: tipo de empleado
    *@return objeto Doctor
    */
    Personal(std::string n, int a, int h):Employee(n,a,h,"Personal"){
        job=1;
    }
    //Getters 
    int get_job();
    std::string get_type();
    //Setters
    void set_job(int);
    //Metodos sobreescritos de la clase abstracta
    float pay();
    std::string to_stream();
};

/**Getter tipo de trabajo (1=Conserje, 2=Administrativo, 3=Enfermera)
*@param 
*@return int:trabajo 
*/
int Personal::get_job(){
    return job;
}

/**Setter especialidad medica
*@param int:trabajo
*@return 
*/
void Personal::set_job(int j){
    job=j;
}

/**Metodo que calcula la paga en base a las horas trabajadas y el tipo de trabajo
*@param 
*@return float:paga del personal
*/
float Personal::pay(){
    float payment=0;
    payment=hours*50*job;
    return payment;
}

/**Almacena los datos del objeto Doctor en una cadena de texto
*@param 
*@return string:datos del doctor
*/
std::string Personal::to_stream(){
    std::stringstream aux;
    if(job==1){
        aux << "Janitor " << get_name() <<  std::endl;
    }
    if(job==2){
        aux << "Management " << get_name() << std::endl;
    }
    if(job==3){
        aux << "Nurse " << get_name() << std::endl;
    }
    
    return aux.str();
}


#endif
