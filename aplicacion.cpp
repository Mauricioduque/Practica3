#include "aplicacion.h"
#include "codificacion.h"
#include <math.h>
#include <sstream>

//Codificar los datos para llevarlos al archivo Datos.dat
string cod_app(string name){
    string texto,binario,codificado;
    bool bandera=true;
    binario=text2bin(name);
    codificado=metodo1(binario,4,bandera);
    return codificado;
}

//decodificar os datos para trabajar con ellos
string deco_app(string name){
    bool bandera=false;
    string texto,binario,decodificado,final;
    texto=lectura_txt(name);
    decodificado=metodo1(texto,4,bandera);
    final=bin2text(decodificado);
    return final;
}

//Verifica si la clave del adminsitrador es correcta
bool administrador(string clave){
    bool efect=false;
    string texto,binario,codificado,final,sudo;
    texto="sudo.dat";
    final=deco_app(texto);
    for(unsigned int i=0;i<final.length();i++){
        if(clave[i]==final[i]) efect=true;
        else efect=false;
    }
    return efect;
}

//Registro de datos hechos por el administrador y organizacion de la estructura de datos (cedula,clave,saldo)
string registro(string registro){
    short opc=0;
    string clave,cedula,saldo;
    string texto,binario,codificado,final;
    while(opc!=2){
        cout<<"Presione 1 si desea registrar un usuario o 2 para salir: ";
        cin>>opc;
        if(opc==1){
            cout<<"Ingrese los datos del usuario "<<endl;
            cout<<"Ingrese cedula: ";
            cin>>cedula;
            registro.append(cedula);
            registro.push_back(',');
            cout<<"Ingrese clave: ";
            cin>>clave;
            registro.append(clave);
            registro.push_back(',');
            cout<<"Ingrese saldo: ";
            cin>>saldo;
            registro.append(saldo);
            registro.push_back('\n');
        }
    }
    return registro;
}

// Busca el usuario en la base de datos y realiza las operacion de consultar saldo y retirar
string checkUsuario(string cedula,string clave, string datos){
    string buscar,saldostring,datoscod,saldo,opc;
    int costo=0;
    unsigned long long int saldoentero=0,saldoactual=0,saldoretirar;
    buscar.append(cedula);
    buscar.push_back(',');
    buscar.append(clave);
    std::size_t found = datos.find(buscar);
    if (found!=std::string::npos) {
        cout<<"Oprima 1 si quiere consultar saldo o 2 si desea retirar dinero:";
        cin>>opc;
        if(opc=="1"){
            saldo=find_saldo(datos,buscar,found);
            datos.erase(found+buscar.length()+1,saldo.length()); //borra saldo que en la base de datos
            stringstream ss;  //conversion de string a entero
              ss << saldo;
              ss >> saldoentero;
            if(saldoentero!=0){
                cout<<"Su saldo es: "<<saldoentero<<endl;
                saldoactual=saldoentero-1000;
                saldostring=to_string(saldoactual);
                cout<<"Costo de la transaccion 1000"<<endl;
                cout<<"Su saldo actual es: "<<saldostring<<endl;
            }
            else {
                saldoactual=saldoentero;
                saldostring=to_string(saldoactual);
                cout<<"Costo de la transaccion 1000"<<endl;
                cout<<"Saldo insuficiente: "<<saldostring<<endl;
            }
            datos.insert(found+buscar.length()+1,saldostring); //Inserta el saldo actual despues de la operacion
        }
        else if (opc=="2"){
            cout<<"Ingrese el monto a retirar:";
            cin>>saldoretirar;
            saldo=find_saldo(datos,buscar,found);
            datos.erase(found+buscar.length()+1,saldo.length());
            stringstream ss;  //conversion de string a entero
              ss << saldo;
              ss >> saldoentero;
           if(saldoentero>=saldoretirar+1000){
                saldoactual=saldoentero-saldoretirar-1000;
                saldostring=to_string(saldoactual);
                cout<<"Costo de la transaccion 1000"<<endl;
                cout<<"El saldo actual de su cuenta es: "<<saldoactual<<endl;
           }
           else {
               if(saldoentero>=1000) costo=1000;
               else costo=0;
               saldoactual=saldoentero-costo;
               saldostring=to_string(saldoactual);
               cout<<"Costo de la transaccion 1000 "<<endl;
               cout<<"Saldo insuficiente: "<<saldoactual<<endl;
           }
           datos.insert(found+buscar.length()+1,saldostring);
        }
        else cout<<"Operacion invalida"<<endl;
    }
    else cout<<"Datos incorrectos"<<endl;
    return datos;
}

//recorre la porcion de datos de la cedula y la clave respectiva para saber el saldo correspondiente
string find_saldo(string datos, string buscar,std::size_t found){
    string saldo,digito="0";
    for(unsigned long long int i=found+buscar.length()+1;digito!="\n";i++){
           digito=datos[i];
           saldo.append(digito);
    }
    saldo.pop_back();
    return saldo;
}
