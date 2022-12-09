#include "curso.h"
int main(){
    
    int opcion;
    do
    {
        std::cout << "\n\t\tBienvenido al programa de cursos de extensión de la UCO.\t\t\n\n";
        std::cout << "MENU PRINCIPAL:\n";
        std::cout << "\t1. Login\n\n";
        std::cout << "\t2. Registrarse\n\n";
        std::cout << "\t3. Visualizar cursos\n\n";
        std::cout << "\t4. Inscribirse\n\n";
        std::cout << "\t5. Salir\n\n";
        std::cout << "Teclee el numero asociado a la opcion que desea llevar a cabo...";
        std::cin >> opcion;

        system("clear");

        switch (opcion)
        {
        case 1:
            llamaLogin();
            break;
        case 2:
            registrarUsuario();
            break;
        case 3:
            mostrarCursos();
            break;
        case 4:
            std::cout<<"Para inscribirse debera primero de haber hecho login en el sistema\n";
        case 5:
            system(EXIT_SUCCESS);
            break;
        default:
            std::cout << "Error, ha introducido una opción no válida.\n";
            break;
        };
    } while (opcion != 5);
}

