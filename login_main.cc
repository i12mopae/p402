#include <iostream>
#include <fstream>

struct Persona{
        std::string dni;
        std::string contrasena;
        std::string nombre;
        std::string apellidos;
        std::string correo;
        std::string rol;
};

void registrarUsuario(){
    std::ofstream fichero;
    fichero.open("usuariosRegistrados.txt", std::fstream::app);
    Persona aux;
    std::cout<<"Introduzca su dni\n";
    getline(std::cin, aux.dni);
    fflush(stdout);
    fichero<<aux.dni<<"\n";
    std::cout<<"Introduzca la contraseña que desea tener para hacer login en el sistema\n";
    getline(std::cin, aux.contrasena);
    fflush(stdout);
    fichero<<aux.contrasena<<"\n";
    std::cout<<"Introduzca su nombre\n";
    getline(std::cin, aux.nombre);
    fflush(stdout);
    fichero<<aux.nombre<<"\n";
    std::cout<<"Introduzca sus apellidos\n";
    getline(std::cin, aux.apellidos);
    fflush(stdout);
    fichero<<aux.apellidos<<"\n";
    std::cout<<"Introduzca su correo electronico\n";
    getline(std::cin, aux.correo);
    fflush(stdout);
    fichero<<aux.correo<<"\n";
    std::cout<<"Introduzca su rol\n";
    getline(std::cin, aux.rol);
    fflush(stdout);
    fichero<<aux.rol<<"\n";
    fichero.close();
    std::cout<<"\n";
    std::cout<<"Usted se ha registrado con exito"<<"\n";
    //std::cout<<"Su usuario es "<<aux.nombre<<"@uco.es y su contraseña "<<aux.nombre<<aux.dni<<"\n";
    /*std::ofstream fich;
    fich.open("login.txt", std::fstream::app);
    fich<<aux.nombre<<"@uco.es"<<"\n";
    fich<<aux.nombre<<aux.dni<<"\n";
    fich.close();*/
}


void loginUsuario(){
    bool encontrado=false;
    std::string dni;
    std::string contrasena;
    std::fstream fichero;
    fichero.open("usuariosRegistrados.txt");
    std::string auxline;
    std::cout<<"Introduzca su nombre de usuario\n";
    getline(std::cin,dni);
    fflush(stdout);
    std::cout<<"Introduzca su contraseña\n";
    getline(std::cin,contrasena);
    fflush(stdout);
    while(getline(fichero,auxline)){
        if(auxline==dni){
            getline(fichero,auxline);
            if(auxline==contrasena){
                encontrado=true;
                std::cout<<"A continuacion se le mostrará su menu correspondiente"<<"\n";
                //comprobar en que fichero esta y enseñar menu correspondiente
                getline(fichero,auxline);
                fflush(stdout);
                getline(fichero,auxline);
                fflush(stdout);
                getline(fichero,auxline);
                fflush(stdout);
                getline(fichero,auxline);
                fflush(stdout);
            }else{
                std::cout<<"La contraseña introducida no es correcta. Repita la operacion"<<"\n";
                std::cout<<"\n";
                loginUsuario();
            } 
        }
    }
    if(encontrado==false){
        std::cout<<"Usuario no encontrado, usted necesita estar previamente registrado en el sistema"<<"\n";
        registrarUsuario();
    }
    fichero.close();
}

int main(){
    std::cout<<"Bienvenido/a a la sección de registro del sistema"<<"\n";
    loginUsuario();
    
    return 0;
} 

