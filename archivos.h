#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void escribir_txt(string name,string data);
string lectura_txt(string name);
void escribir_txt2(char *name,char *data,unsigned long long int tam );
unsigned long long int tamano(char *name);
void leer_txt2(char *name, char *data);

#endif // ARCHIVOS_H
