#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>

enum class RolType
{
    Admin,
    Ccursos,
    Crecursos,
    Alumno
};
class UsuarioRegistrado
{
private:
    std::string nombre_, apellidos_, dni_, correo_, usuario_, password_;
    RolType rol_;

public:
    void menuPrincipal();
    void login();
    void menuCursos();
    void registrar();
};

void error();
void pausa();

void UsuarioRegistrado::menuPrincipal()
{
    int opcion;
    do
    {
        std::cout << "\n\t\tBienvenido al programa de cursos de extensión de la UCO.\t\t\n\n";
        std::cout << "Menú:\n";
        std::cout << "\t1. Iniciar sesión\n\n";
        std::cout << "\t2. Registrarse\n\n";
        std::cout << "\t3. Ver cursos\n\n";
        std::cout << "\t4. Ver registrados\n\n";
        std::cout << "\t5. Salir\n\n";
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
            // mostrar_registrados();
        case 5:
            system(EXIT_SUCCESS);
            break;
        default:
            std::cout << "Error, ha introducido una opción no válida.\n";
            break;
        }
    } while (opcion != 5);
}

void UsuarioRegistrado::login()
{

    std::ifstream lectura;
    lectura.open("usuarios.txt", std::ios::in);
    if (lectura.is_open())
    {
        std::string usuarioaux;
        std::string passwordaux;
        std::cout << "Usuario: ";
        fflush(stdin);
        getline(std::cin, usuarioaux);
        std::cout << "\n";
        std::cout << "Contraseña: ";
        fflush(stdin);
        getline(std::cin, passwordaux);
        bool coincidencia = false;
        
        do
        {
            lectura.seekg(0);
            getline(lectura, nombre_);
            while (!lectura.eof())
            {
                getline(lectura, apellidos_);
                getline(lectura, dni_);
                getline(lectura, correo_);
                getline(lectura, usuario_);
                getline(lectura, password_);


                if (usuario_ == usuarioaux)
                {
                    if (password_ == passwordaux)
                    {
                        coincidencia = true;
                        menuCursos();
                    }

                break;
                }

            }
        }while (coincidencia==false);
    }
    else{
        error();
    }

    lectura.close();
    pausa();
}


void UsuarioRegistrado::menuCursos(){
    switch (rol_)
    {
    case RolType::Alumno:
        std::cout<<"Eres alumno.\n";
        break;
    case RolType::Admin:
        std::cout<<"Eres admin.\n";
        break;
    case RolType::Ccursos:
        std::cout<<"Eres coordinador de cursos.\n";
        break;
    case RolType::Crecursos:
        std::cout<<"Eres Coordinador de recursos.\n";
        break;
    default:
        break;
    }

}

void UsuarioRegistrado::registrar(){
    
    std::ofstream escritura;
    std::ifstream verificador;
    std::string correoaux;
    bool coincidencia=false;
    verificador.open("clientes.txt",std::ios::in);
    escritura.open("clientes.txt",std::ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        std::cout<<"\t\t\t\t***Registrar usuario***\t\t\t\t\n\n";
        fflush(stdin);
        std::cout<<"Ingresa el correo electrónico: ";
        getline(std::cin, correoaux);
        if(correoaux=="")
        //QUITARIA EL DO WHILE
            do
            {
                std::cout<<"Correo no v\240lido!, intentalo nuevamente: ";
                getline(std::cin,correoaux);
            }
            while(correoaux=="");
        do
        {
            verificador.seekg(0);
            getline(verificador,correo_);
            while(!verificador.eof())
            {
                getline(verificador,nombre_);
                getline(verificador,apellidos_);
                getline(verificador, dni_);
                getline(verificador, usuario_);
                getline(verificador, password_);


                if(correo_==correoaux)
                {
                    coincidencia=true;
                    std::cout<<"\n\nYa existe un cliente con ese código!\n\n";
                    std::cout<<"Ingresa un código válido!: ";
                    getline(std::cin,correoaux);
                    if(correoaux=="")
                        do
                        {
                            std::cout<<"\nCorreo no válido!, intentalo nuevamente: ";
                            getline(std::cin,correoaux);
                        }
                        while(correoaux=="");

                    break;
                }

                getline(verificador,correo_);
            }

            if(verificador.eof()&&correoaux!=correo_)
                coincidencia=false;

        }
        while(coincidencia==true);
        system("clear");
        correo_=correoaux;
        std::cout<<"\t\t\t\t***Registrar a un usuario***\t\t\t\t\n\n";
        std::cout<<"Nombre: ";
        getline(std::cin,nombre_);
        std::cout<<"\n\n";
        fflush(stdin);
        std::cout<<"Apellidos: ";
        getline(std::cin,apellidos_);
        std::cout<<"\n\n";
        fflush(stdin);
        std::cout<<"Dni: ";
        getline(std::cin,dni_);
        std::cout<<"\n\n";
        std::cout<<"Correo: "<<correo_;
        std::cout<<"\n\n";
        fflush(stdin);
        std::cout<<"Usuario: ";
        getline(std::cin, usuario_);
        std::cout<<"\n\n";
        fflush(stdin);
        std::cout<<"Contraseña: ";
        getline(std::cin,password_);
        std::cout<<"\n\n";

        escritura<<nombre_<<"\n"<<apellidos_<<"\n"<<dni_<<"\n"<<correo_
                <<"\n"<<usuario_<<"\n"<<password_<<"\n";

    std:: cout<<"El registro se ha completado correctamente.\n\n";
    }

    else
    {
        error();
    }

    escritura.close();
    verificador.close();
    pausa();
}












void pausa()
{
    std::cout<<"Presiona Enter para continuar...";
    getch();
    system("clear");
}

int main()
{
    system ("color f0");
    UsuarioRegistrado inicio;
    inicio.menuPrincipal();
    return 0;
}

void error()
{
    std::cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    std::cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    std::cout<<"registrados.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado.\n\n";
}