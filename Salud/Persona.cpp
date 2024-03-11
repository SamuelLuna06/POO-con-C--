#include <iostream>

using namespace std;

class Persona{

    private:

        int peso;
        int edad;
        int numeroDocumento;
        float IMC;
        float estatura;
        string sexo;
        string nombre;
        string apellido;
        string tipoDocumento;

    public:

    Persona (){

    }

    void setPeso(int peso){
        this -> peso = peso;
    }

    int getPeso(){
        return peso;
    }

    void setEdad(int edad){
        this -> edad = edad;
    }

    int getEdad(){
        return edad;
    }

    void setNumeroDocumento(int numeroDocumento){
        this -> numeroDocumento = numeroDocumento;
    }

    int getNumeroDocumento(){
        return numeroDocumento;
    }

    void setIMC(float IMC){
        this -> IMC = IMC;
    }

    float getIMC(){
        return IMC;
    }

    void setEstatura(float estatura){
        this -> estatura = estatura;
    }

    float getEstatura(){
        return estatura;
    }

    void setSexo(string sexo){
        this -> sexo = sexo;
    }

    string getSexo(){
        return sexo;
    }

    void setNombre(string nombre){
        this -> nombre = nombre;
    }

    string getNombre(){
        return nombre;
    }

    void setApellido(string apellido){
        this -> apellido = apellido;
    }

    string getApellido(){
        return apellido;
    }

    void setTipoDocumento(string tipoDocumento){
        this -> tipoDocumento = tipoDocumento;
    }

    string getTipoDocumento(){
        return tipoDocumento;
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

    string calcularImc(){
        this -> IMC = this -> peso/(this -> estatura * this -> estatura);
        
        if(this -> IMC < 20){
            return "Peso bajo.";
        }else if(20 <= this -> IMC and this -> IMC <= 25){
            return "Peso ideal.";
        }else if(25 < this -> IMC){
            return "Sobrepeso.";
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