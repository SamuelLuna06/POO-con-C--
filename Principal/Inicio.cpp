#include <iostream>
#include "../Salud/Persona.cpp"

using namespace std;

class Inicio{
  
};

int main(){

    Persona usuario1;

    usuario1.pedirDatos();
    usuario1.mostrarDatos();
    usuario1.calcularImc();
    usuario1.mayorEdad();

    return 0;
}