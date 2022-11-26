#ifndef USUARIOREGISTRADO_H
#define USUARIOREGISTRADO_H

#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <iterator>



enum class RolType{Admin, Ccursos, Crecursos, Alumno};
class UsuarioRegistrado
{
private:
    std::string nombre_, apellidos_, dni_, correo_, usuario_, password_;
    RolType rol_;

public:
    UsuarioRegistrado(std::string nombre="empty",
                      std::string apellidos="empty",
                      std::string dni="empty",
                      std::string correo="empty",
                      std::string usuario="empty",
                      std::string password="empty",
                      RolType rol=RolType::Alumno);
    // gets
    inline std::string get_nombre() { return nombre_; }
    inline std::string get_apellidos() { return apellidos_; }
    inline std::string get_dni() { return dni_; }
    inline std::string get_correo() { return nombre_; }
    inline std::string get_usuario() { return usuario_; }
    inline std::string get_password() { return password_; }
    inline RolType get_rol() const {return rol_;}

    // setters
    inline void set_nombre(std::string nombre) { nombre_ = nombre; }
    inline void set_apellidos(std::string apellidos) { apellidos_ = apellidos; }
    inline void set_dni(std::string dni) { dni_ = dni; }
    inline void set_correo(std::string correo) { correo_ = correo; }
    inline void set_usuario(std::string usuario) { usuario_ = usuario; }
    inline void set_password(std::string password) { password_ = password; }
    inline void set_rol(RolType rol){rol_=rol;}

};


#endif