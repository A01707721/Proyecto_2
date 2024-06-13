# Proyecto-A01707721-TC1030
Este proyecto es para la clase de Programación Orientada a Objetos.
## Hospital Contexto
Este proyecto simula un hospital con una nómina máxima de 100 empleados, además de tener capacidad para 150 pacientes, permite ver el estatus de los empleados, también el de los pacientes ingresados,
finalmente da la opción de agregar nuevos empleados al sistema.
## Funcionalidad
El código imprime el siguiente menú en primera estancia:
1. Employees
2. Doctors
3. Personal
4. Patients
5. Add employee
6. Exit
A partir de este menú el usuario puede consultar datos de los diferentes objetos,
además de crear más empleados.
## Consideraciones
Programa hecho en C++ standard, con una interfaz del usuario en el idioma español
- Compilar en terminal con g++ main.cpp Doctor.h Hospital.h
- Windows a.exe
- Linux ./a.out
## Casos de error
- El ingresar números que no estén incluidos en los diferentes menús, causa un error.
- Modificación del nombre de los archivos .h causa errores de compilación
- Al crear un nuevo empleado Personal utilizar un número fuera del rango establecido
- Al crear un nuevo empleado Doctor no usar la palabra NONE para especificar la ausencia de especialidad.
- Ingresar datos del tipo incorrecto, (Ingresar un número cuando se pide caracteres, o viceversa).
## Correcciones
Versión Github 1.0: Se creo el repositorio en Github con los archivos main.cpp, Hospital.h, Doctor.h, el UML de clases y el Readme.
**SICT0301A Evalúa los componentes que integran una problemática y SICT0303A Implementa acciones científicas:** Se crearon las diferentes clases con sus respectivos métodos y atributos,
las clases seguían la relación ya establecida en el UML. **(Doctor.h Patient líneas 18-144, Doctor.h Employee hereda a Doctor y Personal líneas 151-413)**

Versión Github 2.0: **SICT0303A Implementa acciones científicas:** Se aseguro que todas las clases tuvieran sus getters y setters.
**(Doctor.h Patient líneas 35-42, Doctor.h Employee líneas 167-175, Hospital.h Hospotal líneas 43-51)**
También se creó sobrecarga de operadores con los constructores y se rescribieron métodos de la clase padre Employee.
**(Doctor.h Doctor líneas 265-283, Doctor.h líneas 310-333, Doctor.h Personal líneas 386-413)**

Versión Github 3.0:**SICT0303A Implementa acciones científicas:** Para polimorfismo, se agregó un arreglo de apuntadores a objetos tipo Employee en la clase Hospital,
se declararon métodos sobrescritos de Employee como virtual para que se realizaran en el heap, los objetos Doctor y Personal son creados también en el heap.
**(Hospital.h Hospital líneas 24-25, Doctor.h Employee líneas 178-180, Hospital.h Hospital líneas 75-100)**

Versión Github 4.0: **SICT0303A Implementa acciones científicas:** Se modificaron métodos para hacer a la clase padre Employee una clase abstracta.
**(Doctor.h Employee líneas 178-180)**
**SEG0702A Tecnologías y Herramientas:** Se sobrescribió el código sobre los archivos ya existentes en el github, además de agregar documentación de versiones y datos en el Github.
**SICT0301A Evalúa los componentes que integran una problemática:** Se añadió en el Readme una sección que documenta los casos de error previstos en el código.

Versión Github 5.0: **SICT0301A Evalúa los componentes que integran una problemática:** Se modificó la versión final del diagrama de clases, se añadió información adicional de casos de error.
Finalmente se mejoró la interfaz del usuario permitiendo agregar espacios en el nombre de los empleados a crear.

