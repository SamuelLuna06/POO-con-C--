#include <iostream>
#include <list>

using namespace std;

class Nequi{

    private:

    int saldo = 0;
    int opcion = 0;
    string usuario = "3114413251";
    string contrasena = "1234";

    public:

    Nequi(){

    }

    bool iniciarSesion(){

        int intentos = 3;
        bool incioSesion = false;
        string usuarioConfirmacion;
        string contrasenaConfirmacion;

        while (intentos > 0 and incioSesion == false){
            cout << "Ingrese su numero de usuario: " << endl;
            cin >> usuarioConfirmacion;
            cout << "Ingrese su contrasena: " << endl;
            cin >> contrasenaConfirmacion;

            if(usuarioConfirmacion == usuario and contrasenaConfirmacion == contrasena){
                cout << "Has iniciado sesion con exito!!" << endl;
                incioSesion = true;
            }else{
                intentos--;
                cout << "Upps!! Parece que tus datos de acceso no son correctos. Te quedan " << intentos << " intentos para inciar sesion." << endl;
            }
        }

        return incioSesion;
    }

    void recargarPlata(){

        int recarga = 0;

        cout << "Opciones para recargar:\n1. Plata al toque. Desde tu cuenta Bancolombia.\n2. Con efectivo. En corresponsales.\n3. Desde otro banco. Usa PSE.\n4. Codigo de regalo. Escribelo para reclamarlo.\n5. Volver a inicio." << endl;
        cin >> opcion;
        
        if(opcion == 1){

            float numeroCuenta;
            float cedula;

            cout << "Recarga con plata al toque." << endl;
            cout << "Ingrese el numero de cuenta Bancolombia: " << endl;
            cin >> numeroCuenta;
            cout << "Ingrese su numero de cedula: " << endl;
            cin >> cedula;
            cout << "Ingrese el valor a recargar: " << endl;
            cin >> recarga;

            if(recarga < 500){
                cout << "Upps!! No puedes recargar un valor menor a $500." << endl;
            }else{
                saldo += recarga;
                cout << "Recargaste $" << recarga << " a tu cuenta " << usuario << " desde la cuenta Bancolombia " << numeroCuenta << ". Y tu nuevo saldo es de $" << saldo << endl;
            }
        }else if(opcion == 2){
            cout << "Recarga con efectivo." << endl;
            cout << "Ingrese el valor a recargar: " << endl;
            cin >> recarga;

            if(recarga < 500){
                cout << "Upps!! No puedes recargar un valor menor a $500." << endl;
            }else{
                saldo += recarga;
                cout << "Recargaste $" << recarga << " a tu cuenta " << usuario << ". Y tu nuevo saldo es de $" << saldo << endl;
            }
        }else if(opcion == 3){
            
            int opcionBanco;
            string Bancos[6] = {"1. Bancolombia.", "2. Daviplata.", "3. Banco de Bogota.", "4. Banco de Occidente.", "5. Banco de Caja Social.", "6. Banco Popular."};

            cout << "Recarga desde otro banco." << endl;
            
            for(int i = 0; i < 6; i++){
                cout << Bancos[i] << endl;
            }
            cin >> opcionBanco;

            opcionBanco -= 1;

            cout << "Ingrese el valor a recargar: " << endl;
            cin >> recarga;

            if(recarga < 500){
                cout << "Upps!! No puedes recargar un valor menor a $500." << endl;
            }else{
                saldo += recarga;
                cout << "Recargaste $" << recarga << " a tu cuenta " << usuario << " desde el banco " << Bancos[opcionBanco] << ". Y tu nuevo saldo es de $" << saldo << endl;
            }
        }else if(opcion == 4){

            string codigoRegalo;

            cout << "Codigo de regalo." << endl;
            cout << "Ingrese el codigo de regalo: " << endl;
            cin >> codigoRegalo;
            cout << "Ingrese el valor a recargar: " << endl;
            cin >> recarga;
            if(recarga < 500){
                cout << "Upps!! No puedes recargar un valor menor a $500." << endl;
            }else{
                saldo += recarga;
                cout << "Recargaste $" << recarga << " a tu cuenta " << usuario << " usando el codigo de regalo " << codigoRegalo << ". Y tu nuevo saldo es de $" << saldo << endl;
            }
        }else if(opcion == 5){
            cout << "Volviendo al menu principal." << endl;
        }else{
            cout << "Opcion no valida." << endl;
        }
    }

    void colchon(){

        int ingresoColchon = 0;
        int saldoColchon = 0;

        cout << "Ingresa la cantidad de plata que vas a ingresar al colchon: " << endl;
        cin >> ingresoColchon;
        
        if(saldo < ingresoColchon){
            cout << "Upps!! No puedes ingresar un valor mayor al que tienes en tu cuenta." << endl;
        }else{
            saldoColchon = ingresoColchon;
            saldo -= saldoColchon;
            cout << "Ingresaste $" << saldoColchon << " a tu colchon. Tu nuevo saldo es de $" << saldo << endl;
        }
    }

    void meta(){
        cout << "Sirve." << endl;
    }

    void bolsillos(){
        cout << "Sirve." << endl;
    }

    void sacarPlata(){
        cout << "Sirve." << endl;
    }

    void movimientos(){
        cout << "Sirve." << endl;
    }

    void consultarSaldo(){

        cout << "Tu saldo en disponible es de $" << saldo << endl;
    }

};