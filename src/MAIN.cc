#include "curso.h"
#include <iostream>
#include <time.h>
#include <unistd.h>


int main(){
    int opcion;
    do
    {
        std::cout << "\n\t\tBienvenido al programa de cursos de extensión de la UCO.\t\t\n\n";
        std::cout << "MENU PRINCIPAL:\n";
        std::cout<<"\n";
        std::cout << "\t1. Login\n\n";
        std::cout << "\t2. Registrarse\n\n";
        std::cout << "\t3. Visualizar cursos\n\n";
        std::cout << "\t4. Inscribirse en un curso\n\n";
        std::cout << "\t5. Salir\n\n";
        std::cout << "Teclee el numero asociado a la opcion que desea llevar a cabo...";
        std::cin>>opcion;
       
        if (std::cin.fail()){ 
            clear_cin();
            std::cout<<"\n";
            std::cout<<"Error, debe introducir un numero. Intentelo de nuevo"<<"\n";
            sleep(1.5);
            system("clear");
            return main(); 
        }
        system("clear");

        std::string dni;
        std::string contrasena;

        switch (opcion)
        {
        case 1:
            std::cout<<"\n\t\tBienvenido\a a la sección de login al sistema\n\t\t"<<"\n";
            std::cout<<"Introduzca su dni\n";
            std::cin.ignore();
            getline(std::cin,dni);
            std::cout<<"Introduzca su contraseña\n";
            fflush(stdin);
            getline(std::cin,contrasena);
            loginUsuario(dni, contrasena);
            break;
        case 2:
            registrarUsuario();
            break;
        case 3:
            mostrarCursos();
            std::cout<<"\n";
            std::cout<<"------------------------------------------------------------------------------------------\n";
            std::cout<<"\n";
            std::cout<<"Seleccione una opción del menu"<<"\n";
            std::cout<<"\n";
            break;
        case 4:
            std::cout<<"Para inscribirse debera primero de haber hecho login en el sistema. Se le mostrará de nuevo el menú para acceder a una opción del sistema\n";
            sleep(4);
            system("clear");
            break;
        case 5:
            exit(EXIT_SUCCESS);
            break;
        default:
                std::cout << "La opcion ingresada no es válida,inténtelo de nuevo:\n";
                sleep(1);
                return main();
        };
    } while (opcion != 5);
}

