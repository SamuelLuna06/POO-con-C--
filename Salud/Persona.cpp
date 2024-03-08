#include <iostream>

using namespace std;

class Persona{

    private:

        int peso;
        int edad;
        int numeroDocumento;
        float IMC;
        double estatura;
        string sexo;
        string nombre;
        string apellido;
        string tipoDocumento;

    public:

    Persona (){

    }
    
    void pedirDatos(){
        cout << "Ingresa tu tipo de documento:" << endl;
        cin >> this -> tipoDocumento;
        cout << "Ingresa tu numero de documento: " << endl;
        cin >> this -> numeroDocumento;
        cout << "Ingresa tu nombre: " << endl;
        cin >> this -> nombre;
        cout << "Ingresa tu apellido: " << endl;
        cin >> this -> apellido;
        cout << "Ingresa tu peso en kilogramos: " << endl;
        cin >> this -> peso;
        cout << "Ingresa tu estatura en metros: " << endl;
        cin >> this -> estatura;
        cout << "Ingresa tu edad: " << endl;
        cin >> this -> edad;
        cout << "Ingresa tu sexo: " << endl;
        cin >> this -> sexo;
    }

    void mostrarDatos(){
        cout << "Los datos del usuario son los siguientes: " << endl;
        cout << "Tipo de documento: " << this -> tipoDocumento << endl;
        cout << "Numero de documento: " << this -> numeroDocumento << endl;
        cout << "Nombre: " << this -> nombre << endl;
        cout << "Apellido: " << this -> apellido << endl;
        cout << "Peso: " << this -> peso << endl;
        cout << "Estatura: " << this -> estatura << endl;
        cout << "Edad: " << this -> edad << endl;
        cout << "Sexo: " << this -> sexo << endl;
    }

    void calcularImc(){
        this -> IMC = this -> peso/(this -> estatura * this -> estatura);
        
        if(this -> IMC < 20){
            cout << "Su peso esta por debajo de lo ideal." << endl;
        }else if(20 <= this -> IMC and this -> IMC <= 25){
            cout << "Su peso esta dentro de lo ideal." << endl;
        }else if(25 < this -> IMC){
            cout << "Su peso esta por encima de lo ideal." << endl;
        }
    }

    void mayorEdad(){
        if(this -> edad < 18){
            cout << "El usuario es menor de edad." << endl;
        }else{
            cout << "El usuario es mayor de edad." << endl;
        }
    }
};

