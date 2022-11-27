#include <iostream>
#include <string.h>
#include "funciones.h"
#include "UsuarioRegistrado.h"
int main()
{
    int opcion;
    do
    {
        std::cout << "\n\t\tBienvenido al programa de cursos de extensión de la UCO.\t\t\n\n";
        std::cout << "Menú:\n";
        std::cout << "\t1. Iniciar sesión\n\n";
        std::cout << "\t2. Registrarse\n\n";
        std::cout << "\t3. Ver cursos\n\n";
        std::cout << "\t4. Salir\n\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        system("clear");

        switch (opcion)
        {
        case 1:
            login();
            break;
        case 2:
            registrar();
            break;
        case 3:
            // ConsultaCurso();
            break;
        case 4:
            system(EXIT_SUCCESS);
            break;
        default:
            std::cout << "Error, ha introducido una opción no válida.\n";
            break;
        }
    }while(opcion!=4);
}