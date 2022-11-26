#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <iterator>
#include "UsuarioRegistrado.h"

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
        if(i->get_usuario()==usuarioaux){
            if(i->get_password()==passwordaux){        
            switch (i->get_rol())
            {
            case 0:
                std::cout<<"Es admin";
                break;
            case 1:
                std::cout<<"Es cursos";
                break;
            case 2:
                std::cout<<"Es recursos";
                break;
            case 3:
                std::cout<<"Es alumno";
                break;
            default:
                std::cout<<"Error de registro\n";
                break;
            }
            }
            else{std::cout<<"Acceso inválido, el usuario y la contraseña no coinciden.\n";
                login();}
        }
        else{
            do{
            std::cout<<"El usuario no es correcto o este usuario aún no está registrado.\n";
            std::cout<<"Elija entre las siguientes opciones:\n";
            std::cout<<"\t1.Probar otra vez.\n";
            std::cout<<"\t2.Registrarse.\n";
            std::cout<<"\t3.Salir.\n";
            std::cout<<"Opción: \n";
            std::cin>>opusuario;
            switch (opusuario)
            {
            case 1:
                login();
                break;
            case 2:
                // registrar();
            case 3:
                system(EXIT_SUCCESS);
            default:
                std::cout << "Error, ha introducido una opción no válida.\n";
                break;
            }
            }while(opusuario!=3);


        }
    }
}

#endif