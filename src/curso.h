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
bool crearCurso();
void mostrarCursos();
void modificarCurso();
void modificadoCurso();
void llamaLogin();
void registrarUsuario();
void loginUsuario();
void menuUsuario(std::string dni);
void inscribirse(std::string dni);
#endif