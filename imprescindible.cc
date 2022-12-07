#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Curso
{
private:
    string codigocurso_;
    std::string nombre_;
    std::string descripcion_;
    std::string ponentes_;
    std::string duracion_;
    string aforo_;
    string plibre_; // plazas libres

public:
    void menuCursos();
    void crearCurso();
    // void borrarCurso();
    // void modificarCurso();
    // void mostrarCurso();
};

void pausa();
void error();

void Curso::menuCursos()
{
    int opcion;
    do
    {
        std::cout << "\n\t\tBienvenido al programa de cursos de extensión de la UCO.\t\t\n\n";
        std::cout << "Menú:\n";
        std::cout << "\t1. Crear curso\n\n";
        std::cout << "\t2. Borrar curso\n\n";
        std::cout << "\t3. Ver cursos\n\n";
        std::cout << "\t4. Modificar curso\n\n";
        std::cout << "\t5. Salir\n\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        system("clear");

        switch (opcion)
        {
        case 1:
            crearCurso();
            break;
        case 2:
            // borrarCurso();
            break;
        case 3:
            // mostrarCurso();
            break;
        case 4:
            // modificarCurso();
        case 5:
            system(EXIT_SUCCESS);
            break;
        default:
            std::cout << "Error, ha introducido una opción no válida.\n";
            break;
        }
    } while (opcion != 5);
}

void pausa()
{
    cout << "Presiona Enter para continuar...";
    getch();
    system("clear");
}

int main()
{
    Curso inicio;
    inicio.menuCursos();
    return 0;
}

void error()
{
    cout << "No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout << "la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout << "clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}

void Curso::crearCurso()
{
    string auxcod;
    cout << "\n\tCrear curso\n";
    fflush(stdin);
    cout << "Introduzca el codigo del curso: ";
    getline(cin, auxcod);
    ifstream lectura;
    lectura.open("cursos.txt", ios::in);
    if (lectura.fail())
    {
        cout << "No se pudo abrir el archivo txt\n";
        exit(1);
    }

    while (!lectura.eof())
    {
        getline(lectura, codigocurso_);
        getline(lectura, descripcion_);
        getline(lectura, ponentes_);
        getline(lectura, duracion_);
        getline(lectura, aforo_);
        getline(lectura, plibre_);

        if (codigocurso_ == auxcod)
        {
            cout << "El codigo introducido ya pertenece a un curso existente.\n";
        }
        else
        {
            ofstream escritura;
            escritura.open("cursos.txt", ios::app);
            if (escritura.fail())
            {
                cout << "No se pudo abrir el archivo txt\n";
                exit(1);
            }

            
                codigocurso_=auxcod;
                cout<<"Codigo: "<<codigocurso_;
                cout<<"\n";
                fflush(stdin);
                cout<<"Nombre: ";
                getline(cin, nombre_);
                cout<<"\n";
                fflush(stdin);
                cout<<"Descripcion: ";
                getline(cin, descripcion_);
                cout<<"\n";
                fflush(stdin);
                cout<<"Ponentes: ";
                getline(cin, ponentes_);
                cout<<"\n";
                fflush(stdin);
                cout<<"Duración: ";
                getline(cin, duracion_);
                cout<<"\n";
                fflush(stdin);
                cout<<"Aforo: ";
                getline(cin, aforo_);
                cout<<"\n";
                fflush(stdin);
                cout<<"Plazas libres: ";
                getline(cin, plibre_);
                
                escritura <<"\nCodigo: "<< codigocurso_ << "\n"
                        << "\nNombre: "<<nombre_ << "\n"
                        << "\nDescripcion: "<<descripcion_ << "\n"
                        << "\nPonentes: "<<ponentes_ << "\n"
                        << "\nDuracion: "<<duracion_ << "\n"
                        << "\nAforo: "<<aforo_ << "\n\n";

            
        }
    }
}

// void Curso::borrarCurso()
// {
//     ifstream lectura;
//     ofstream auxiliar;
//     bool encontrado = false;
//     string auxCodigo;
//     char respuesta[5];
//     lectura.open("cursos.txt", ios::in);
//     auxiliar.open("auxiliar.txt", ios::out);
//     cout << "\t\t\t\t***Borrar curso***\t\t\t\t\n\n";
//     if (lectura.is_open() && auxiliar.is_open())
//     {
//         fflush(stdin);
//         cout << "Ingresa el codigo del curso que quieres borrar: ";
//         getline(cin, auxCodigo);
//         getline(lectura, codigocurso_);
//         while (!lectura.eof())
//         {
//             getline(lectura, nombre_);
//             getline(lectura, descripcion_);
//             getline(lectura, ponentes_);
//             getline(lectura, duracion_);
//             getline(lectura, aforo_);
//             getline(lectura, plibre_);

//             if (auxCodigo == codigocurso_)
//             {
//                 encontrado = true;
//                 cout << "\n\nRegistro Encontrado\n\n";
//                 cout << "C\242digo: " << codigocurso_ << endl;
//                 cout << "Nombre: " << nombre_ << endl;
//                 cout << "Descripción: " << descripcion_ << endl;
//                 cout << "Ponentes: " << ponentes_ << endl;
//                 cout << "Duración: " << duracion_ << endl;
//                 cout << "Aforo: " << aforo_ << endl;

//                 cout << "\n\n";
//                 cout << "Realmente deseas dar de baja a: " << nombre_ << " (s/n)?: ";
//                 cin.getline(respuesta, 5);
//                 if (strcmp(respuesta, "s") == 0 || strcmp(respuesta, "S") == 0 ||
//                     strcmp(respuesta, "s") == 0 || strcmp(respuesta, "SI") == 0 ||
//                     strcmp(respuesta, "S") == 0 || strcmp(respuesta, "si") == 0)
//                 {
//                     cout << "\n\nEl cliente se ha dado de baja correctamente\n\n";
//                 }

//                 else
//                 {

//                     cout << "\n\nCliente conservado\n\n";
//                     auxiliar << codigocurso_ << "\n"
//                              << nombre_ << "\n"
//                              << descripcion_ << "\n"
//                              << ponentes_
//                              << "\n"
//                              << duracion_ << "\n"
//                              << aforo_ << "\n";
//                 }
//             }
//             else
//             {
//                 auxiliar << codigocurso_ << "\n"
//                          << nombre_ << "\n"
//                          << descripcion_ << "\n"
//                          << ponentes_
//                          << "\n"
//                          << duracion_ << "\n"
//                          << aforo_ << "\n";
//             }
//             getline(lectura, codigocurso_);
//         }
//         if (encontrado == false)
//         {
//             cout << "\n\nNo se encontr\242 el c\242digo: " << auxCodigo << "\n\n";
//         }
//     }
//     else
//     {
//         error();
//     }
//     lectura.close();
//     auxiliar.close();
//     remove("clientes.txt");
//     rename("auxiliar.txt", "clientes.txt");
//     pausa();
// }