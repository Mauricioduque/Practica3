#ifndef APLICACION_H
#define APLICACION_H
#include "archivos.h"

string cod_app(string name);
string deco_app(string name);
bool administrador(string clave);
string registro(string registro);
string checkUsuario(string cedula,string clave,string datos);
string find_saldo(string datos, string buscar,std::size_t found);
#endif // APLICACION_H
