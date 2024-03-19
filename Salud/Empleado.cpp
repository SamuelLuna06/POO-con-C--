#include <iostream>
#include "../Salud/Persona.cpp"

class Empleado: public Persona{

    private:

        int anoActual = 0;
        int anoNacimiento = 0;
        int valorHora = 0;
        int horasTrabajadas = 0;
        string cargo;
        string departamento;

    public:

    Empleado(){

    }

    void setValorHora(int valorHora){
        this -> valorHora = valorHora;
    }

    int getPeso(){
        return valorHora;
    } 

    void setHorasTrabajadas(int horasTrabajadas){
        this -> horasTrabajadas = horasTrabajadas;
    }

    int getHorasTrabajadas(){
        return horasTrabajadas;
    }

    void setCargo(string cargo){
        this -> cargo = cargo;
    }

    string getCargo(){
        return cargo;
    }

    void setDepartamento(string departamento){
        this -> departamento = departamento;
    }

    string getDepartamento(){
        return departamento;
    }

    void pedirDatos(){
        cout << "Ingresa el valor de tu hora:" << endl;
        cin >> this -> valorHora;
        cout << "Ingresa las horas trabajadas: " << endl;
        cin >> this -> horasTrabajadas;
        cout << "Ingresa tu cargo: " << endl;
        cin >> this -> cargo;
        cout << "Ingresa tu departamento: " << endl;
        cin >> this -> departamento;
        cout << "Ingresa tu año de nacimiento: " << endl;
        cin >> this -> anoNacimiento;
        cout << "Ingresa el año actual: " << endl;
        cin >> this -> anoActual;
    }

    void calcularHonorarios(){
        
        int honorarios = (valorHora * horasTrabajadas) - ((valorHora * horasTrabajadas) * 0.00966);

        cout << "Los honorarios del empleado son de $" << honorarios << endl;
    }

    int mayorEdad(){

        int edad = anoActual - anoNacimiento;

        return edad;
    }

};