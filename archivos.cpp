#include "archivos.h"

void escribir_txt(string name,string data){
    /* k: objeto que pertenece a la clase fstream,
     * donde estan definidas todas las funciones,
     * que permite comunicarnos con los archivos de texto.
     * se crea o se abre el archivo ensayo en modo escritura (fstream::out)
     *  o de manera binaria (fstream::binary)
    */
    fstream k(name,fstream::out | fstream::binary);
    //k << data; // se escribe sobre archivo ensayo
    k.write(data.c_str(),data.length());
    k.close();//cerrar archivo
}

string lectura_txt(string name){
    long long int tam;
    string data;
    //abrir archivo en modo lectura o posicionar el cursos al final del archivo(ate)
    fstream k(name,fstream::in | fstream::ate| fstream::binary);
    tam=k.tellg();  // determina el tamaño de caracteres en el  archivo al colocar el cursor al final del texto
    k.seekg(0);    // defino el cursor al incio del texto
    if (k.is_open()){
        for(long long int i=0;i<tam;i++) data.push_back(k.get());// concateno caracter por caracter
    }
    else cout<<"El archivo no existe"<<endl;
    k.close();//cerrar archivo
    return data;
}

void escribir_txt2(char *name,char *data,unsigned long long int tam ){
    fstream k(name,fstream::out | fstream::binary);
    k.write(data,tam);
    k.close();//cerrar archivo
}

unsigned long long int tamano(char *name){
    unsigned long long int tam;
    fstream k(name,fstream::in | fstream::ate | fstream::binary);
    tam=k.tellg();
    k.close();
    return tam;
}

void leer_txt2(char *name, char *data){
    fstream k(name,fstream::in | fstream::binary);
    if(k.is_open()){
      for(long long int i=0;!k.eof();i++) data[i]=k.get();
    }
    else cout << "El archivo de texto no existe" << endl;
    k.close();
}










/*leer un archivo linea por linea
 * while(!k.eof()){
 *      getline(k,data2);   //lee una linea de texto (hasta que encuentra un salto de linea)
 *      data.append("\n\r"); //salto de linea con tabulación al principio
 *      data.append(data2); //concateno cada linea de texto leida
 * }
*/

/*Leer una archivo de texto con un ciclo while caracter por caracter
 *  while(!k.eof()){
 *          data.push_back(k.get());// concateno caracter por caracter
 *  }
*/

/*determinar el tamaño de un archivo de texto en modo lectura
 * fstream k("Ensayo.txt",fstream::in | fstream::ate);
 * cout<<k.tellg()<<endl;
 */
