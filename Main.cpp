#include <iostream>
#include "Nequi/Nequi.cpp"
#include "Daviplata/Daviplata.cpp"

using namespace std;

int main(){

    Daviplata daviplata1;
    Nequi nequi1;

    int opcion = 0;
    int opcionApp = 0;

    cout << "Elija la aplicacion que desea usar:\n1. Nequi.\n2. Daviplata." << endl;
    cin >> opcionApp;

    if(opcionApp == 1){
        if(nequi1.iniciarSesion() == true){
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
    }else if(opcionApp == 2){
        if(daviplata1.iniciarSesion() == true){
            while(opcion != 7){
                cout << "1. Recargar saldo.\n2. Bolsillos.\n3. Sacar plata.\n4. Movimientos.\n5. Pagos.\n6. Consultar saldo.\n7. Salir." << endl;
                cin >> opcion;
                switch(opcion){
                    case 1:
                        daviplata1.recargarPlata();
                        break;
                    case 2:
                        daviplata1.bolsillos();
                        break;
                    case 3:
                        daviplata1.sacarPlata();
                        break;
                    case 4:
                        daviplata1.movimientos();
                        break;
                    case 5: 
                        daviplata1.pagos();
                        break;
                    case 6: 
                        daviplata1.consultarSaldo();
                        break;
                    case 7:
                        cout << "Gracias por usar Daviplata." << endl;
                        break;
                    default:
                        cout << "Opcion no valida." << endl;
                        break;
                }
            }
        }else{
            cout << "No se ha podido iniciar sesion." << endl;
        }
    }else{
        cout << "Opcion no valida." << endl;
    }

    return 0;
}