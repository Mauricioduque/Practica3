#ifndef CODIFICACION_H
#define CODIFICACION_H
#include "archivos.h"


void codificacion(string name, int n);
void decodificacion(string name, int n);
string text2bin(string texto);
string metodo1(string binario, int n,bool control);
int contar(string partido);
string swap(string,int);
string bin2text (string cod);
string reglas (string partido,int n);
void text2bin2(char *texto2, char *binario2, unsigned long long int tam);
char metodo2cod(char *binario2, unsigned long long int tam, int n,char *cod2,bool control2);
void metodo2dec(char *cod2,int n, unsigned long long int tam,char *decod2);
void bin2text2(char *decod2, unsigned long long tam, char *final2);
void codificacion2(char *name2, int n);
void decodificacion2(char *name3, int n);

#endif // CODIFICACION_H
