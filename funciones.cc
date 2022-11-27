#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <iterator>
#include "UsuarioRegistrado.h"

std::list<UsuarioRegistrado> registrados_list_;

void login()
{
    std::string usuarioaux;
    std::string passwordaux;
    std::cout << "Usuario: ";
    std::cin >> usuarioaux;
    std::cout << "\n";
    std::cout << "Contraseña: ";
    std::cin >> usuarioaux;
    int opusuario;

    for (auto i = registrados_list_.begin(); i != registrados_list_.end(); i++)
    {
        if (i->get_usuario() == usuarioaux)
        {
            if (i->get_password() == passwordaux)
            {
                switch (i->get_rol())
                {
                case RolType::Admin:
                    std::cout << "Es admin";
                    break;
                case RolType::Ccursos:
                    std::cout << "Es cursos";
                    break;
                case RolType::Crecursos:
                    std::cout << "Es recursos";
                    break;
                case RolType::Alumno:
                    std::cout << "Es alumno";
                    break;
                default:
                    std::cout << "Error de registro\n";
                    break;
                }
            }
            else
            {
                std::cout << "Acceso inválido, el usuario y la contraseña no coinciden.\n";
                login();
            }
        }
        else
        {
            do
            {
                std::cout << "El usuario no es correcto o este usuario aún no está registrado.\n";
                std::cout << "Elija entre las siguientes opciones:\n";
                std::cout << "\t1.Probar otra vez.\n";
                std::cout << "\t2.Registrarse.\n";
                std::cout << "\t3.Salir.\n";
                std::cout << "Opción: \n";
                std::cin >> opusuario;
                switch (opusuario)
                {
                case 1:
                    login();
                    break;
                case 2:
                    // registrarusu();
                case 3:
                    system(EXIT_SUCCESS);
                default:
                    std::cout << "Error, ha introducido una opción no válida.\n";
                    break;
                }
            } while (opusuario != 3);
        }
    }
}

void registrarusu()
{
    std::string nombreaux;
    std::string apellidosaux;
    std::string dniaux;
    std::string correoaux;
    std::string usuarioaux;
    std::string passwordaux;

    std::cout << "Para registrarse deberá introducir los siguientes datos:\n";
    std::cout << "Dni: ";
    std::cin >> dniaux;
    int option;
    for (auto i = registrados_list_.begin(); i != registrados_list_.end(); i++)
    {
        if (i->get_dni() == dniaux)
        {
            do
            {
                std::cout << "Ya hay una cuenta registrada con este dni.\n";
                std::cout << "Elija entre las siguientes opciones:\n";
                std::cout << "\t1.Probar otra vez.\n";
                std::cout << "\t2.Olvidé mi contraseña\n";
                std::cout << "\t3.Salir.\n";
                std::cout << "Opción: \n";
                std::cin >> option;
                switch (option)
                {
                case 1:
                    registrarusu();
                    break;
                case 2:
                    // olvidacontra();
                case 3:
                    system(EXIT_SUCCESS);
                }
            } while (option != 3);
        }
        else
        {
            UsuarioRegistrado nuevo;
            nuevo.set_dni(dniaux);
            std::cout << "Nombre: ";
            std::cin >> nombreaux;
            nuevo.set_nombre(nombreaux);
            std::cout << "Apellidos: ";
            std::cin >> apellidosaux;
            nuevo.set_apellidos(apellidosaux);
            std::cout << "Correo: ";
            std::cin >> correoaux;
            nuevo.set_correo(correoaux);
            std::cout << "Usuario: ";
            std::cin >> usuarioaux;
            nuevo.set_usuario(usuarioaux);
            std::cout << "Contraseña: ";
            std::cin >> passwordaux;
            nuevo.set_password(passwordaux);

            registrados_list_.push_back(nuevo);

        }
    }
}