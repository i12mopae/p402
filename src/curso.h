#ifndef CURSO_H
#define CURSO_H

#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct Curse{
        std::string nombre;
        std::string descripcion;
        std::string ponentes;
        std::string duracion;
        std::string aforo;
        std::string plibre;
};
struct Persona{
        std::string dni;
        std::string contrasena;
        std::string nombre;
        std::string apellidos;
        std::string correo;
};
void menuCursos();
void crearCurso();
void mostrarCursos();
void modificarCurso();
void modificadoCurso(std::string nombre);
void registrarUsuario();
bool loginUsuario(std::string dni, std::string contrasena);
void menuUsuario(std::string dni);
void inscribirse(std::string dni);
size_t lengthOfString(const char *s);
bool isNumber(const std::string& str);
void clear_cin();
#endif






