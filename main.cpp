#include "codificacion.h"

#include "aplicacion.h"
#include <math.h>

int main()
{
    short caso=0;
    while(true){
    cout<<"Ingrese 1 para ejercicios o 2 para Aplicacion de cajero: ";
    cin>>caso;
    switch (caso) {
        case 1:
            {int metodo=0,semilla;
                while(metodo!=3){
                    cout<<"Ingrese la semilla:";
                    cin>>semilla;
                    cout<<"Ingrese el metodo de codificacion (1, 2 o 3 para salir):";
                    cin>>metodo;
                    if (metodo==1){
                        string archivo_natural="Ensayo.txt";
                        codificacion(archivo_natural,semilla);
                        decodificacion("Cod_metodo1.dat", semilla);
                    }
                    else if(metodo==2){
                        char archivo[]="Ensayo.txt";
                        char archivo2[]="Cod_metodo2.dat";
                        codificacion2(archivo,semilla);
                        decodificacion2(archivo2,semilla);
                    }
                    else if (metodo==3) break;
                    else cout<<"Operacion invalida"<<endl;
                }
           }
        break;
        case 2:
            {string clave,final,datoscod,datosdeco,cedula;
            string datos=deco_app("Datos.dat");
            string casoapli="0";

            while (casoapli<"4"){
                cout<<"Bienvenido al cajero"<<endl;
                cout<<"Marque 1  si desea ingresar como administrador, 2 como  usuario o 3 para salir : ";
                cin>>casoapli;
                if (casoapli=="1"){
                    cout<<"Ingrese la clave de administrador:";
                    cin>>clave;
                    bool efect;
                    efect=administrador(clave);
                    if (efect==true) {
                        final=registro(datos);
                        datos.append(final);
                        datoscod=cod_app(datos);
                        escribir_txt("Datos.dat",datoscod);
                    }
                    else cout<< "Clave incorrecta"<<endl;
                }
                else if(casoapli=="2"){
                    cout<<"Ingrese la cedula:";
                    cin>>cedula;
                    cout<<"Ingrese la clave :";
                    cin>>clave;
                    datos=checkUsuario(cedula,clave,datos);
                    datoscod=cod_app(datos);
                    escribir_txt("Datos.dat",datoscod);
                }
                else if (casoapli=="3") break;
                else cout<<"Operacion invalida"<<endl;
            }

        }
        break;

        default:
            cout<<"Operacion invalida"<<endl;
        break;

    }




//AdMiNiStRaDoR123.
    }
  return 0;

}

