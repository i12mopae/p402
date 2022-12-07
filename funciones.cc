#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <conio.h>
#include "UsuarioRegistrado.h"
#include "funciones.h"

std::list<UsuarioRegistrado> registrados_list_;

void login()
{
    std::ifstream lectura;
    lectura.open("usuarios.txt", std::ios::in);
    if (lectura.is_open())
    {
        fflush(stdin);
        std::string usuarioaux;
        std::string passwordaux;
        std::cout << "Usuario: ";
        getline(std::cin, usuarioaux);
        std::cout << "\n";
        std::cout << "Contraseña: ";
        getline(std::cin, passwordaux);
        bool coincidencia = false;
        int opusuario;

//         do{
//             lectura.seekg(0);
           
//         }
//     }
//     else
//     {
//         std::cout << "Acceso inválido, el usuario y la contraseña no coinciden.\n";
//         exit(EXIT_FAILURE);
    }
}

//             else
//             {
//                 do
//                 {
//                     std::cout << "El usuario no es correcto o este usuario aún no está registrado.\n";
//                     std::cout << "Elija entre las siguientes opciones:\n";
//                     std::cout << "\t1.Probar otra vez.\n";
//                     std::cout << "\t2.Registrarse.\n";
//                     std::cout << "\t3.Salir.\n";
//                     std::cout << "Opción: ";
//                     std::cin >> opusuario;
//                     switch (opusuario)
//                     {
//                     case 1:
//                         login();
//                         break;
//                     case 2:
//                         registrar();
//                     case 3:
//                         system(EXIT_SUCCESS);
//                     default:
//                         std::cout << "\nError, ha introducido una opción no válida.\n";
//                         break;
//                     }
//                 } while (opusuario != 3);
//             }
//         }
//     }
// }

void registrar()
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

    for (std::list<UsuarioRegistrado>::iterator i = registrados_list_.begin(); i != registrados_list_.end(); i++)
    {
        if (i->get_dni() == dniaux)
        {

            std::cout << "\nYa hay una cuenta registrada con este dni.\n";
            system(EXIT_SUCCESS);
        }
    }
    UsuarioRegistrado nuevo;
    std::cout << "\nNombre: ";
    std::cin >> nombreaux;
    nuevo.set_nombre(nombreaux);
    std::cout << "\nApellidos: ";
    std::cin >> apellidosaux;
    nuevo.set_apellidos(apellidosaux);
    nuevo.set_dni(dniaux);
    std::cout << "\nCorreo: ";
    std::cin >> correoaux;
    nuevo.set_correo(correoaux);
    std::cout << "\nUsuario: ";
    std::cin >> usuarioaux;
    nuevo.set_usuario(usuarioaux);
    std::cout << "\nContraseña: ";
    std::cin >> passwordaux;
    nuevo.set_password(passwordaux);

    registrados_list_.push_back(nuevo);
    std::cout << "\nUsuario registrado correctamente.\n";
}

void mostrar_registrados()
{
    // std::ofstream fich("registrados.txt");
    // if (!fich)
    // {
    //     std::cout << "Error al abrir registrados.txt\n";
    //     exit(EXIT_FAILURE);
    // }
    for (std::list<UsuarioRegistrado>::iterator i = registrados_list_.begin(); i != registrados_list_.end(); i++)
    {
        std::cout << "\nNombre: " << i->get_nombre();
        std::cout << "\tApellidos: " << i->get_apellidos();
        std::cout << "\tDni: " << i->get_dni();
        std::cout << "\tCorreo: " << i->get_correo();
        std::cout << "\tUsuario: " << i->get_usuario() << "\n";
    }
}