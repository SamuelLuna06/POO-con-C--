#include <iostream>
#include "../Salud/Persona.cpp"

using namespace std;

class Inicio{
  
};

int main(){

    Persona usuario;

    usuario.pedirDatos();
    usuario.calcularImc();

    return 0;
}