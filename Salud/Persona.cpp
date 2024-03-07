#include <iostream>

using namespace std;

class Persona{

    public:
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
        cin >> tipoDocumento;
        cout << "Ingresa tu numero de documento: " << endl;
        cin >> numeroDocumento;
        cout << "Ingresa tu nombre: " << endl;
        cin >> nombre;
        cout << "Ingresa tu apellido: " << endl;
        cin >> apellido;
        cout << "Ingresa tu peso en kilogramos: " << endl;
        cin >> peso;
        cout << "Ingresa tu estatura en metros: " << endl;
        cin >> estatura;
        cout << "Ingresa tu edad: " << endl;
        cin >> edad;
        cout << "Ingresa tu sexo: " << endl;
        cin >> sexo;
    }

    void mostrarDatos(){
        cout << "Los datos del usuario son los siguientes: " << endl;
        cout << "Tipo de documento: " << tipoDocumento << endl;
        cout << "Numero de documento: " << numeroDocumento << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Peso: " << peso << endl;
        cout << "Estatura: " << estatura << endl;
        cout << "Edad: " << edad << endl;
        cout << "Sexo: " << sexo << endl;
    }

    void calcularImc(){
        IMC = peso/(estatura*estatura);
        
        if(IMC < 20){
            cout << "Su peso esta por debajo de lo ideal." << endl;
        }else if(20 <= IMC and IMC <= 25){
            cout << "Su peso esta dentro de lo ideal." << endl;
        }else if(25 < IMC){
            cout << "Su peso esta por encima de lo ideal." << endl;
        }
    }

    void mayorEdad(){
        if(edad < 18){
            cout << "El usuario es menor de edad." << endl;
        }else{
            cout << "El usuario es mayor de edad." << endl;
        }
    }
};

int main(){

    Persona usuario1;

    usuario1.pedirDatos();
    usuario1.mostrarDatos();
    usuario1.calcularImc();
    usuario1.mayorEdad();

    return 0;
}