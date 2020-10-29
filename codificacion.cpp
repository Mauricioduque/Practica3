#include "codificacion.h"
#include <math.h>

void codificacion(string name, int n){
    string texto,binario,codificado,final;
    bool bandera=true;
    texto=lectura_txt(name);
    binario=text2bin(texto);
    codificado=metodo1(binario,n,bandera);
    final=bin2text(codificado);
    escribir_txt("Cod_metodo1.dat",final);
}

void decodificacion(string name, int n){
    bool bandera=false;
    string texto,binario,decodificado,final;
    texto=lectura_txt(name);
    binario=text2bin(texto);
    decodificado=metodo1(binario,n,bandera);
    final=bin2text(decodificado);
    escribir_txt("Dec_metodo1.txt",final);
}


string text2bin(string texto){
    string binario;
    for(unsigned long long int i=0;i<texto.length();i++){ // recorre cada uno de los caracteres del texto
        for(int j=0;j<8;j++) binario.push_back(char((((texto[i]<<j)&(0x80))/128)+48));
    }
    return binario;
}

string metodo1(string binario, int n, bool bandera){
    short caso=1,unos;
    string partido,codificado,codificado2,control;
    for(unsigned long long int i=0,k=0;i<binario.length();i++){
        partido.push_back(binario[i]);
        if((k+1)*n-1==i || i==binario.length()-1){ //condicion matematica que se cumple cuando se tiene partido en la semilla
            codificado=reglas(partido,caso);
            codificado2.append(codificado);
            // se define si es codificacion o decodificacion
            if(bandera==true) control=partido;
            else control=codificado;

            unos=contar(control);
            if(unos==(int(control.length())-unos)) caso=1;
            else if (unos<(int(control.length())-unos)) caso=2;
            else caso=3;
            partido.clear();
            k++;
        }
    }
    return codificado2;
}

int contar(string partido){
    int cont=0;
    for(unsigned long long int i=0;i<partido.length();i++){
        if(partido[i]=='1') cont++;
    }
    return cont;
}

string bin2text (string cod){
    string final;
    int aux=0;
    int k=7;
    for (unsigned long long int i=0;i<cod.length();i++,k--){
        aux=aux+int(cod[i]-48)*pow(2,k);
        if (k==0){
            final.push_back(aux);
            aux=0;
            k=8;
        }
    }
    return final;
}

string reglas (string partido,int caso){ //funcion que applica las reglas de codificacion metodo1
    string codificado;
    for(unsigned long long int j=0;j<partido.length();j++){
        switch (caso) {
            case 1:
                if (partido[j]=='1') codificado.push_back('0');
                else codificado.push_back('1');

            break;
            case 2:
                if(j%2!=0){
                    if (partido[j]=='1') codificado.push_back('0');
                    else codificado.push_back('1');
                }
                else codificado.push_back(partido[j]);
            break;
            default:
                if((j+1)%3==0){
                    if (partido[j]=='1') codificado.push_back('0');
                    else codificado.push_back('1');
                }
                else codificado.push_back(partido[j]);
            break;
        }
    }
    return codificado;
}


void text2bin2(char *texto2, char *binario2, unsigned long long int tam)
{
    for(unsigned long long int i=0; i<tam; i++){
        for(int j=0;j<8;j++) binario2[8*i+j]=(char((((texto2[i]<<j)&(0x80))/128)+48));
    }
}

void metodo2(char *binario2,int n, unsigned long long int tam, char *cod2,bool control2){
    char *partido;
    unsigned long long pos=0;
    int a=0;
    partido= new char [n+1];
    bool menor=false;
    for(unsigned long long int i=0, k=0; i<8*tam;i++){
        partido[a]=binario2[i];
        a++;
        if((k+1)*n-1==i || i==(8*tam-1)){
            if(a<n) menor=true;
            for(int j=0,aux=a;j<n && aux>0; j++,aux--){
               if (menor ==true) {
                   cod2[pos]=partido[aux-1];
               }
               //Reglas del metodo 2 si es para codificacion o decodifcacion
               else if(aux==n && control2==true) cod2[pos]= partido[n-1];
               else if(control2==true) cod2[pos]=partido[j-1];
               else if(aux==n && control2==false) cod2[(k+1)*n-1]= partido[j];
               else cod2[pos-1]=partido[j];

               pos++;
            }
            k++;
            delete [] partido;
            partido= new char [n+1];
            partido[n]='\0';
            a=0;
            menor=false;
      }
  }
}


void bin2text2(char *decod2, unsigned long long tam, char *final2){
    int aux=0;
    int k=7;
    unsigned long long int j=0;
    for (unsigned long long int i=0; i<8*tam;i++,k--){
            aux=aux+int(decod2[i]-48)*pow(2,k);
            if(k==0){
                final2[j]=aux;
                j++;
                k=8,aux=0;
            }
    }
}

void codificacion2(char *name2, int n){
    unsigned long long int tam;
    bool control2=true;
    char *texto2,*binario2,*cod2;
    tam=tamano(name2);
    texto2=new char[tam+1];
    texto2[tam]='\0';
    binario2=new char[8*tam+1];
    binario2[8*tam]='\0';
    cod2=new char[8*tam+1];
    cod2[8*tam]='\0';
    leer_txt2(name2,texto2);
    text2bin2(texto2,binario2,tam);
    metodo2(binario2,n,tam,cod2,control2);
    bin2text2(cod2,tam,texto2);
    escribir_txt2("Cod_metodo2.dat",texto2,tam);
    delete [] texto2;
    delete [] binario2;
    delete [] cod2;
}

void decodificacion2(char *name3, int n){
    unsigned long long int tam;
    bool control2=false;
    char *texto2,*binario2,*decod2;
    tam=tamano(name3);
    texto2=new char[tam+1];
    texto2[tam]='\0';
    binario2=new char[8*tam+1];
    binario2[8*tam]='\0';
    decod2=new char[8*tam+1];
    decod2[8*tam]='\0';
    leer_txt2(name3,texto2);
    text2bin2(texto2,binario2,tam);
    metodo2(binario2,n,tam,decod2,control2);
    bin2text2(decod2,tam,texto2);
    escribir_txt2("Dec_metodo2.txt",texto2,tam);
    delete [] texto2;
    delete [] binario2;
    delete [] decod2;
}

