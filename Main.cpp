#include <iostream>
#include "Nequi/Nequi.cpp"
#include "Daviplata/Daviplata.cpp"

using namespace std;

int main(){

    Nequi nequi1;

    if(nequi1.iniciarSesion() == true){

        int opcion = 0;

        while(opcion != 8){

            cout << "1. Recargar saldo.\n2. Colchon.\n3. Meta.\n4. Bolsillos.\n5. Sacar plata.\n6. Movimientos.\n7. Consultar saldo.\n8. Salir." << endl;
            cin >> opcion;

            switch(opcion){
                case 1:
                    nequi1.recargarPlata();
                    break;
                case 2:
                    nequi1.colchon();
                    break;
                case 3:
                    nequi1.meta();
                    break;
                case 4:
                    nequi1.bolsillos();
                    break;
                case 5:
                    nequi1.sacarPlata();
                    break;
                case 6:
                    nequi1.movimientos();
                    break;
                case 7: 
                    nequi1.consultarSaldo();
                    break;
                case 8:
                    cout << "Gracias por usar Nequi." << endl;
                    break;
                default:
                    cout << "Opcion no valida." << endl;
                    break;
            }
        }
    }else{
        cout << "No se ha podido iniciar sesion." << endl;
    }

    return 0;
}