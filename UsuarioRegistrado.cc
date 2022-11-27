#include "UsuarioRegistrado.h"
#include <string>

UsuarioRegistrado::UsuarioRegistrado(std::string nombre, std::string apellidos, 
std::string dni, std::string correo, std::string usuario, std::string password, RolType rol){
    nombre_ = nombre;
    apellidos_ = apellidos;
    dni_ = dni;
    correo_ = correo;
    usuario_ = usuario;
    password_ = password;
    rol_=rol;
    }

