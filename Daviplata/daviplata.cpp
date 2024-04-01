#include <iostream>
#include <list>
#include <stdlib.h> 
#include <time.h> 

using namespace std;

class Daviplata{

    private:

    int saldo = 0;
    int opcion = 0;
    int saldoBolsillo = 0;
    bool bolsilloCreado = false;
    string nombreBolsillo;
    string usuario = "3114413251";
    string contrasena = "1234";
    list <string> movimientosNombre;
    list <int> movimientosPlata;


    public:

    Daviplata(){}

    int getSaldo(){
        return saldo;
    }
    
    int getSaldoBolsillo(){
        return saldoBolsillo;
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
                movimientosPlata.push_back(recarga);
                movimientosNombre.push_back("Recarga desde cuenta Bancolombia.");
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
                movimientosPlata.push_back(recarga);
                movimientosNombre.push_back("Recarga con efectivo.");
                cout << "Recargaste $" << recarga << " a tu cuenta " << usuario << ". Y tu nuevo saldo es de $" << saldo << endl;
            }
        }else if(opcion == 3){
            
            int opcionBanco;
            string Bancos[6] = {"1. Bancolombia.", "2. Banco de Bogota.", "3. Banco de Occidente.", "4. Banco de Caja Social.", "5. Banco Popular."};

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
                movimientosPlata.push_back(recarga);
                movimientosNombre.push_back("Recarga desde otro banco.");
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
                movimientosPlata.push_back(recarga);
                movimientosNombre.push_back("Recarga con codigo de regalo.");
                cout << "Recargaste $" << recarga << " a tu cuenta " << usuario << " usando el codigo de regalo " << codigoRegalo << ". Y tu nuevo saldo es de $" << saldo << endl;
            }
        }else if(opcion == 5){
            cout << "Volviendo al menu principal." << endl;
        }else{
            cout << "Opcion no valida." << endl;
        }
    }

    void bolsillos(){

        int ingresoBolsillo = 0;

        if (bolsilloCreado == true){
            cout << "No puedes crear mas bolsillos." << endl; 
        }else{

            cout << "Ingresa el nombre del bolsillo: " << endl;
            cin >> nombreBolsillo;
            cout << "Deseas ingresar dinero al bolsillo " << nombreBolsillo << "?\n1. Si.\n2. No." << endl;
            cin >> opcion;

            if(opcion == 1){
                cout << "Ingresa la cantidad de dinero que quieres anadir al bolsillo: " << endl;
                cin >> ingresoBolsillo;
                if(saldo < ingresoBolsillo){
                    cout << "Upps!! No puedes ingresar un valor mayor al saldo de tu cuenta." << endl;
                }else{
                    saldoBolsillo = ingresoBolsillo;
                    saldo -= saldoBolsillo;
                    bolsilloCreado = true;
                    movimientosPlata.push_back(ingresoBolsillo);
                    movimientosNombre.push_back("Transaccion al bolsillo.");
                    cout << "Ingresaste $" << saldoBolsillo << " a tu bolsillo " << nombreBolsillo << ". Y tu nuevo saldo es de $" << saldo << endl;
                }
            }else if(opcion == 2){
                bolsilloCreado = true;
                cout << "Se creo con exito tu bolsillo " << nombreBolsillo << endl;
            }else{
                cout << "Opcion no valida." << endl;
            } 
        }
    }

    void sacarPlata(){
        
        int eleccionSaldo = 0;
        int valorRetirar = 0;
        int confirmacionCodigo = 0;
        int codigoCajero = 100000+rand()%999999;

        cout << "Opciones para sacar:\n1. Cajero. Desde un cajero Bancolombia.\n2. Punto fisico. En corresponsales y puntos nequi." << endl;
        cin >> opcion;

        if(opcion == 1){

            cout << "Escoge de donde saldra el dinero:\n1. Disponible.\n2. "<< nombreBolsillo << endl;
            cin >> opcion;
                
            cout << "Tu codigo para retirar desde un cajero es: " << codigoCajero << endl;

            cout << "Ingresa el codigo para retirar: " << endl;
            cin >> confirmacionCodigo;

            if(opcion == 1){
                eleccionSaldo = saldo;
            }else if(opcion == 2){
                eleccionSaldo = saldoBolsillo;    
            }

            if(confirmacionCodigo != codigoCajero){
                cout << "Upps!! Codigo incorrecto." << endl;
            }else{
                cout << "Ingresa el valor a retirar: " << endl;
                cin >> valorRetirar;

                if(valorRetirar > eleccionSaldo){
                    cout << "Upps!! No tienes suficiente saldo." << endl;
                }else{
                    if(opcion == 1){
                        saldo -= valorRetirar;
                        movimientosPlata.push_back(valorRetirar);
                        movimientosNombre.push_back("Retiro desde cajero.");
                        cout << "Retiraste $" << valorRetirar << " de tu cuenta " << usuario << " desde un cajero. Y tu nuevo saldo es de $" << saldo << endl;
                    }else if(opcion == 2){
                        saldoBolsillo -= valorRetirar;
                        movimientosPlata.push_back(valorRetirar);
                        movimientosNombre.push_back("Retiro desde cajero.");
                        cout << "Retiraste $" << valorRetirar << " de tu cuenta " << usuario << " desde un cajero. Y tu nuevo saldo en el bolsillo es de $" << saldoBolsillo << endl;
                    }else{
                        cout << "Upps!! Opcion no valida." << endl;
                    }
                }    
            }

        }else if(opcion == 2){
            cout << "Escoge de donde saldra el dinero:\n1. Disponible.\n2. "<< nombreBolsillo << endl;
            cin >> opcion;
                
            cout << "Tu codigo para retirar desde un cajero es: " << codigoCajero << endl;

            cout << "Ingresa el codigo para retirar: " << endl;
            cin >> confirmacionCodigo;

            if(opcion == 1){
                eleccionSaldo = saldo;
            }else if(opcion == 2){
                eleccionSaldo = saldoBolsillo;    
            }

            if(confirmacionCodigo != codigoCajero){
                cout << "Upps!! Codigo incorrecto." << endl;
            }else{
                cout << "Ingresa el valor a retirar: " << endl;
                cin >> valorRetirar;

                if(valorRetirar > eleccionSaldo){
                    cout << "Upps!! No tienes suficiente saldo." << endl;
                }else{
                    if(opcion == 1){
                        saldo -= valorRetirar;
                        movimientosPlata.push_back(valorRetirar);
                        movimientosNombre.push_back("Retiro desde cajero.");
                        cout << "Retiraste $" << valorRetirar << " de tu cuenta " << usuario << " desde un cajero. Y tu nuevo saldo es de $" << saldo << endl;
                    }else if(opcion == 2){
                        saldoBolsillo -= valorRetirar;
                        movimientosPlata.push_back(valorRetirar);
                        movimientosNombre.push_back("Retiro desde cajero.");
                        cout << "Retiraste $" << valorRetirar << " de tu cuenta " << usuario << " desde un cajero. Y tu nuevo saldo en el bolsillo es de $" << saldoBolsillo << endl;
                    }else{
                        cout << "Upps!! Opcion no valida." << endl;
                    }
                }    
            }
        }else{
            cout << "Upps!! Opcion no valida." << endl;
        }
    }

    void pagos(){

        cout << "Elige el convenio que deseas usar.\n1. Netflix.\n2. Github.\n3. OpenAI." << endl;
        cin >> opcion;

        if(opcion == 1){
            cout << "Selecciona tu plan:\n1. Premiun 4k+HDR $38.900.\n2. Estandar 1080p $26.900.\n3. Basico $16.900." << endl;
            cin >> opcion;
            if(opcion == 1 and saldo >= 38900){
                movimientosPlata.push_back(38900);
                movimientosNombre.push_back("Compra de plan premiun 4k+HDR en netflix.");
                cout << "Has adquirido el plan Premiun 4k+HDR exitosamente." << endl;
            }else if(opcion == 2 and saldo >= 26900){
                movimientosPlata.push_back(26900);
                movimientosNombre.push_back("Compra de plan Estandar 1080p en netflix.");
                cout << "Has adquirido el plan Estandar 1080p exitosamente." << endl;
            }else if(opcion == 3 and saldo >= 16900){
                movimientosPlata.push_back(16900);
                movimientosNombre.push_back("Compra de plan Basico en netflix.");
                cout << "Has adquirido el plan Básico exitosamente." << endl;
            }else{
                cout << "Upps!! Ha ocurrido un error en la compra del plan." << endl;
            }
        }else if(opcion == 2){
            cout << "Selecciona tu plan:\n1. Equipo. Colaboracion avanzada para individuos y organizaciones $14.170.\n2. Empresa. Seguridad, cumplimiento e implementacion flexible $74.328." << endl;
            cin >> opcion;
            if(opcion == 1 and saldo >= 14170){
                movimientosPlata.push_back(14170);
                movimientosNombre.push_back("Compra de plan Equipo en GitHub.");
                cout << "Has adquirido el plan Equipo exitosamente." << endl;
            }else if(opcion == 2 and saldo >= 74328){
                movimientosPlata.push_back(14170);
                movimientosNombre.push_back("Compra de plan Empresa en Github.");
                cout << "Has adquirido el plan Empresa exitosamente." << endl;
            }else{
                cout << "Upps!! Ha ocurrido un error en la compra del plan." << endl;
            }
        }else if(opcion == 3){
            cout << "Deseas suscribirte a OpenAi? La suscripcion se autorenovara por $81.000/mes hasta que la canceles.\n1. Si.\n2. No." << endl;
            cin >> opcion;
            if(opcion == 1 and saldo >= 81000){
                movimientosPlata.push_back(81000);
                movimientosNombre.push_back("Compra de plan premiun en OpenAI.");
                cout << "Te has suscrito exitosamente." << endl;
            }else if(opcion == 2){
                cout << "No se ha realizado la suscripcion." << endl;
            }else{
                cout << "Opcion no valida." << endl;
            }
        }else{
            cout << "Opcion no valida." << endl;
        }   
    }    

    void movimientos(){
        for(const auto & Tipo: movimientosNombre){
            cout << Tipo << " " ;
        }
        cout << endl;

        for(const auto & Tipo: movimientosPlata){
            cout << Tipo << " " ;
        }
        cout << endl;
    }

    void consultarSaldo(){
        cout << "Tu saldo en disponible es de $" << saldo << endl;
    }

};