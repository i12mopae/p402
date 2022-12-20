#include "curso.h"
#include <string>
#include <iostream>
#include <ctype.h>
#include <time.h>
#include <unistd.h>


void clear_cin() {
    std::cin.clear();
    std::cin.ignore(80,'\n');
}

bool inscribirse(std::string dni, std::string nombre){
    int plibres;
    std::ifstream fichero;
    std::string auxline;
    bool encontrado=false;
    std::string nombref=nombre;
    nombref+=".txt";
    fichero.open(nombref.c_str(), std::ios::out);
    /*
    if(fichero.fail()){
        std::cout<<"no se ha podido abrir fichero  \n";
        return false;
        exit(1);
        
            }
            */
        
            
    while(getline(fichero, auxline)){
        if(auxline==dni){
            std::cout<<"Usted ya se encuentra matriculado en este curso\n";
            
            return false;
        }
        fflush(stdout);
    }
    fichero.close();
    fflush(stdout);
    Curse curso;
    std::ifstream fcursos;
    fcursos.open("cursos.txt", std::ios::in);
    std:: ofstream fnuevo;
    fnuevo.open("cursosnuevos.txt", std::fstream::app);
    while(getline(fcursos, auxline)&&encontrado==false){
        fflush(stdout);
        if(auxline==nombre){
            encontrado=true;
            curso.nombre=auxline;
            getline(fcursos, auxline);
            curso.descripcion=auxline;
            fflush(stdout);
            getline(fcursos, auxline);
            curso.ponentes=auxline;
            fflush(stdout);
            getline(fcursos, auxline);
            curso.duracion=auxline;
            fflush(stdout);
            getline(fcursos, auxline);
            curso.aforo=auxline;
            fflush(stdout);
            getline(fcursos, auxline);
            curso.plibre=auxline;
            fflush(stdout);
            plibres=stoi(auxline);
            if(plibres>0){
                std::cout<<"\n";
                std::cout<<"Usted se ha INSCRITO con éxito.\n";
                std::cout<<"\n";
                std::cout<<"En unos instantes recibira un correo con las pautas que tendra que realizar para pagarlo y estar matriculado\n";
                std::cout<<"\n";
            }
            else{
                std::cout<<"El aforo del curso esta completo, pero usted ha quedado inscrito en la lista de espera.\n";
                std::cout<<"Sera notificado por correo si finalmente puede inscribirse.\n";
            }
        }
            getline(fcursos, auxline);
            fflush(stdout);
            getline(fcursos, auxline);
            fflush(stdout);
            getline(fcursos, auxline);
            fflush(stdout);
            getline(fcursos, auxline);
            fflush(stdout);
            getline(fcursos, auxline);
            fflush(stdout);
    }
    fcursos.close();
    fcursos.open("cursos.txt", std::ios::in);
    while(getline(fcursos, auxline)){
        if(auxline==curso.nombre){
            fflush(stdout);
            getline(fcursos, auxline);
            fflush(stdout);
            getline(fcursos, auxline);
            fflush(stdout);
            getline(fcursos, auxline);
            fflush(stdout);
            getline(fcursos, auxline);
            fflush(stdout);
            getline(fcursos, auxline);
            fflush(stdout);
        }
        else{
            fnuevo<<auxline<<"\n";
            fflush(stdout);
            getline(fcursos, auxline);
            fnuevo<<auxline<<"\n";
            fflush(stdout);
            getline(fcursos, auxline);
            fnuevo<<auxline<<"\n";
            fflush(stdout);
            getline(fcursos, auxline);
            fnuevo<<auxline<<"\n";
            fflush(stdout);
            getline(fcursos, auxline);
            fnuevo<<auxline<<"\n";
            fflush(stdout);
            getline(fcursos, auxline);
            fnuevo<<auxline<<"\n";
            fflush(stdout);
        }
    }
    if(encontrado==false){
        std::cout<<"ERROR, el nombre de curso que busca no se encuentra en nuestro sistema.\n";
        remove((nombref).c_str());
        std::cout<<"Intentelo de nuevo teniendo cuidado con las mayusculas, minusculas y espacios entre caracteres.\n";
        return false;
    }
    fnuevo<<curso.nombre<<"\n";
    fnuevo<<curso.descripcion<<"\n";
    fnuevo<<curso.ponentes<<"\n";
    fnuevo<<curso.duracion<<"\n";
    fnuevo<<curso.aforo<<"\n";
    if(plibres!=0){
    plibres=plibres-1;
    }
    
    curso.plibre=std::to_string(plibres);
    fnuevo<<curso.plibre<<"\n";
    remove("cursos.txt");
    rename("cursosnuevos.txt", "cursos.txt");
    std::ofstream fich;
    fich.open(nombref.c_str(), std::fstream::app);
    fich<<dni<<"\n";
    fich.close();
    fnuevo.close();
    fcursos.close();
    return true;
}



void menuUsuario(std::string dni){
    int opcion;
    do
    {
        std::cout << "\t\tBienvenido al menú de usuario:\n";
        std::cout<<"\n";
        std::cout << "\t1. Visualizar cursos\n\n";
        std::cout << "\t2. Inscribirse a un curso\n\n";
        std::cout << "\t3. Mostrar datos del administrador y coordinador de los cursos\n\n";
        std::cout << "\t4. Consultar los cursos en los que estoy matriculado\a\n\n";
        std::cout << "\t5. Retroceder al menú principal\n\n";
        std::cout << "Teclee el numero asociado a la opcion que desea llevar a cabo...";
        std::cin >> opcion;
        if (std::cin.fail()){ 
            clear_cin();
            std::cout<<"\n";
            std::cout<<"Error, debe introducir un numero. Intentelo de nuevo"<<"\n";
            sleep(1.5);
            system("clear");
            menuUsuario(dni); 
        }
        Curse curso;
        std::string nombre;

        system("clear");

        switch (opcion)
        {
        case 1:
            mostrarCursos();
            std::cout<<"\n";
            std::cout<<"\n";
            std::cout<<"------------------------------------------------------------------------------------------\n";
            std::cout<<"\n";
            std::cout<<"Seleccione una opción del menu"<<"\n";
            std::cout<<"\n";
            break;
        case 2:
        mostrarCursos();
        std::cout<<"Introduzca el nombre del curso al que desea inscribirse\n";
        std::cout<<"(Si no quedan plazas disponibles usted quedara inscrito a la lista de espera)\n";
        std::cin.ignore();
        getline(std::cin,nombre);
        while(isNumber(nombre)){
        std::cout<<"\n";
        std::cout<<"Error, usted ha introducido un numero. Introduzca el nombre del curso en el que desee inscribirse"<<"\n";
        getline(std::cin,nombre);
        std::cout<<"\n";
        }
        inscribirse(dni, nombre);
        std::cout<<"\n";
        std::cout<<"\n";
        std::cout<<"------------------------------------------------------------------------------------------\n";
        std::cout<<"\n";
        std::cout<<"Seleccione una opción del menu"<<"\n";
        std::cout<<"\n";
        break;
        case 3:
            std::cout<<"A continuación, se facilitan los datos del administrador y del coordinador de los cursos, por si necesita ponerse en contacto con los mismos"<<"\n";
            std::cout<<"\n";
            std::cout<<"Nombre completo del administrador: Manuel Ramírez Osuna"<<"\n";
            std::cout<<"Correo electrónico: manuelramirez@gmail.com"<<"\n";
            std::cout<<"\n";
            std::cout<<"Nombre completo del coordinador de los cursos: Antonio López Vera"<<"\n";
            std::cout<<"Correo electrónico: antoniolove@gmail.com"<<"\n";
            std::cout<<"\n";
            std::cout<<"\n";
            std::cout<<"------------------------------------------------------------------------------------------\n";
            std::cout<<"\n";
            std::cout<<"Seleccione una opción del menu"<<"\n";
            std::cout<<"\n";
            break;
        case 4:
            cursosAlumno(dni);
            std::cout<<"\n";
            std::cout<<"\n";
            std::cout<<"------------------------------------------------------------------------------------------\n";
            std::cout<<"\n";
            std::cout<<"Seleccione una opción del menu"<<"\n";
            std::cout<<"\n";
            break;
        case 5:
            system(EXIT_SUCCESS);
            break;
        default:
           if(opcion<0 || opcion>5){
                std::cout << "La opción ingresada no es válida, inténtelo de nuevo\n";
                std::cout<<"\n";
                menuUsuario(dni);
            }
        };
    } while (opcion != 5);
}

size_t lengthOfString(const char *s){
    size_t size = 0;
    while (*s){
        size += 1;
        s +=1;
    }
    return size;
}

bool isNumber(const std::string& str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}


bool loginUsuario(std::string dni, std::string contrasena){
    bool encontrado=false;
    std::string respuesta;
    std::fstream fichero;
    fichero.open("usuariosRegistrados.txt", std::ios::in);
    if(fichero.fail())
    {
        std::cout<<"error abrir archivo"<<"\n";
    }
    std::string auxline;
    while(lengthOfString(dni.c_str())!=9){
        fichero.close();
        std::cout<<"Error, el DNI introducido no es válido. Inténtelo de nuevo"<<"\n";
        return false;
        std::cout<<"Introduzca su dni\n";
        getline(std::cin,dni);
    }
    while(isNumber(dni)){
        fichero.close();
        std::cout<<"Error, el DNI introducido no es válido. Inténtelo de nuevo"<<"\n";
        return false;
        std::cout<<"Introduzca su dni\n";
        getline(std::cin,dni);
    }
    std::cout<<"\n";
    while(getline(fichero,auxline)&&encontrado==false){
        fflush(stdout);
        if(auxline==dni){
            getline(fichero,auxline);
            fflush(stdout);
            if(auxline==contrasena){
                encontrado=true;
                std::cout<<"\n";
                std::cout<<"A continuación se le mostrará su menu correspondiente"<<"\n";
                sleep(1);
                system("clear");
                //comprobar en que fichero esta y enseñar menu correspondiente
                
                if(dni=="12345678C" && contrasena=="coordinadorcurso"){
                    fichero.close();
                    menuCursos();//menu para coordinador de cursos
                    return true;
                }
                else{
                    fichero.close();
                    menuUsuario(dni);
                    return true;
                }
            }
            else{
                std::cout<<"La contraseña introducida no es correcta. Repita la operación o seleccione la opción que desee realizar"<<"\n";
                sleep(2);
                system("clear");
                return false;
            } 
        }
                getline(fichero,auxline);
                fflush(stdout);
                getline(fichero,auxline);
                fflush(stdout);
                getline(fichero,auxline);
                fflush(stdout);
                getline(fichero,auxline);
                fflush(stdout);
        //std::cin.ignore();
    }
    if(encontrado==false){
        std::cout<<"\n";
        std::cout<<"Usuario no encontrado, usted necesita estar previamente registrado en el sistema"<<"\n";
        //return false;
        /*std::cout<<"\n";
        std::cout<<"¿Desea acceder a esa sección? Introduzca 'Si' en caso afirmativo o 'No' si desea retroceder al menu principal"<<"\n";
        std::cin>>respuesta;
        while(isNumber(respuesta)){
            std::cout<<"\n";
            std::cout<<"Error, debe introducir 'Si' o 'No'. Inténtelo de nuevo"<<"\n";
            getline(std::cin,respuesta);
            std::cin.ignore();
            std::cout<<"\n";
        }
        if(respuesta=="Si"){
            std::cout<<"\n";
            std::cout<<"A continuación, se le mostrará el formulario de registro del sistema"<<"\n";
            sleep(2);
            system("clear");
            registrarUsuario();
        }else if(respuesta=="No"){
            sleep(1);
            system("clear");
            return false;
        }*/
        //sleep(1);
        //system("clear");
        //fichero.close();
    }
    fichero.close();
    return false;
    
}

bool registrarUsuario(Persona aux){
    std::fstream fichero;
    std::string auxline;
    fichero.open("usuariosRegistrados.txt");
    
    
    //creo que se puede quitar
    /*
    while(lengthOfString(aux.dni.c_str())!=9){
        fichero.close();
        std::cout<<"Error, el DNI introducido no es válido. Inténtelo de nuevo siguiendo el formato propio del DNI."<<"\n";
        return false;
    }
    */
    while(isNumber(aux.dni)){
        std::cout<<"Error, el DNI introducido no es válido. Inténtelo de nuevo"<<"\n";
        return false;
    }
    while(getline(fichero, auxline)){
        if(auxline==aux.dni){
            std::cout<<"Ya existe un usuario con ese DNI.\n El DNI es un documento identificativo unico por lo que debe contactar con el administrador si cree que se trata de un error\n";
            std::cout<<"\n";
            sleep(4);
            std::cout<<"Se le mostrará de nuevo el menú principal para que pueda seleccionar una opción"<<"\n";
            sleep(2);
            system("clear");
            return false;
        }
    }
    fichero.close();
    fichero.open("usuariosRegistrados.txt", std::fstream::app);
    
    
    while(isNumber(aux.nombre)){
        std::cout<<"Error, el nombre introducido no es válido. Inténtelo de nuevo"<<"\n";
        return false;
    }
    
    
    
    while(isNumber(aux.apellidos)){
        std::cout<<"Error, los apellidos introducidos no son válidos. Inténtelo de nuevo"<<"\n";
        return false;
    }
    fichero<<aux.dni<<"\n";
    fichero<<aux.contrasena<<"\n";
    fichero<<aux.nombre<<"\n";
    fichero<<aux.apellidos<<"\n";
    fichero<<aux.correo<<"\n";
    fichero.close();
    std::cout<<"\n";
    std::cout<<"Usted se ha registrado con exito"<<"\n";
    std::cout<<"\n";
    std::cout<<"\n";
    std::cout<<"------------------------------------------------------------------------------------------\n";
    std::cout<<"\n";
    std::cout<<"Seleccione una opción del menu"<<"\n";
    std::cout<<"\n";
    return true;
    //std::cout<<"Su usuario es "<<aux.nombre<<"@uco.es y su contraseña "<<aux.nombre<<aux.dni<<"\n";
    /*std::ofstream fich;
    fich.open("login.txt", std::fstream::app);
    fich<<aux.nombre<<"@uco.es"<<"\n";
    fich<<aux.nombre<<aux.dni<<"\n";
    fich.close();*/
}


bool crearCurso(Curse aux){
    std::fstream fichero;
    std::string auxline;
    fichero.open("cursos.txt");
    
    
    while(isNumber(aux.nombre)){
        std::cout<<"\n";
        std::cout<<"Error, el nombre introducido no es válido. Inténtelo de nuevo"<<"\n";
        return false;
    }
    
    while(getline(fichero, auxline)){
        if(auxline==aux.nombre){
            std::cout<<"ERROR. No pueden existir dos cursos con el mismo nombre. Seleccione de nuevo una opción del menú\n";
            return false;
        }
        
    }
    fichero.close();
    fichero.open("cursos.txt", std::fstream::app);
    
    
    while(isNumber(aux.descripcion)){
        std::cout<<"\n";
        std::cout<<"Error, la descripción introducida no es válida. Inténtelo de nuevo"<<"\n";
        return false;
    }
    
    
    while(!isNumber(aux.ponentes)){
        std::cout<<"\n";
        std::cout<<"Error, el número de ponentes introducido no es válido. Debe introducir un numero. Inténtelo de nuevo"<<"\n";
        return false;
    }
    
    
    while(!isNumber(aux.duracion)){
        std::cout<<"\n";
        std::cout<<"Error, la duración del curso introducida no es válida. Debe introducir un numero. Inténtelo de nuevo"<<"\n";
        return false;
    }
    
    
    while(!isNumber(aux.aforo)){
        std::cout<<"\n";
        std::cout<<"Error, el aforo del curso introducido no es válido. Debe introducir un numero. Inténtelo de nuevo"<<"\n";
        return false;
    }
    
    
    while(!isNumber(aux.plibre)){
        std::cout<<"\n";
        std::cout<<"Error, las plazas libres introducidas no son válidas. Debe introducir un numero. Inténtelo de nuevo"<<"\n";
        return false;
    }
    fichero<<aux.nombre<<"\n";
    fichero<<aux.descripcion<<"\n";
    fichero<<aux.ponentes<<"\n";
    fichero<<aux.duracion<<"\n";
    fichero<<aux.aforo<<"\n";
    fichero<<aux.plibre<<"\n";
    std::cout<<"\n";
    std::cout<<"El curso ha sido creado con éxito. Podrá visualizarlo con el resto de cursos que había en el sistema"<<"\n";
    fichero.close();
    return true;
}



void mostrarCursos(){
    std::cout<<"Usted se encuentra en la sección de cursos del sistema"<<"\n";
    std::cout<<"A continuación, podrá visualizar una breve descripción sobre aquellos cursos que se encuentran actualmente en vigor"<<"\n";
    std::ifstream fichero("cursos.txt", std::ifstream::in);
    std::string auxline;
    while(getline(fichero,auxline)){
            std::cout<<"\n";
            std::cout<<"Nombre:"<<auxline<<"\n";
            fflush(stdout);
        getline(fichero, auxline);
            std::cout<<"Descripcion:"<<auxline<<"\n";
            fflush(stdout);
        getline(fichero, auxline);
            std::cout<<"Ponentes:"<<auxline<<"\n";
            fflush(stdout);
        getline(fichero, auxline);
            std::cout<<"Duracion:"<<auxline<<"\n";
            fflush(stdout);
        getline(fichero, auxline);
            std::cout<<"Aforo:"<<auxline<<"\n";
            fflush(stdout);
        getline(fichero, auxline);
            std::cout<<"Plazas disponibles:"<<auxline<<"\n";
            fflush(stdout);
        std::cout<<"\n";
        }
    fichero.close();
}
/*
void modificadoCurso(std::string nombre){
    std::ofstream fichero;
    fichero.open("cursosnuevo.txt", std::fstream::app);
    Curse aux;
    fichero<<nombre<<"\n";
    std::cout<<"\n";
    std::cout<<"Introduzca una breve descripcion del curso\n";
    getline(std::cin, aux.descripcion);
    while(isNumber(aux.descripcion)){
        std::cout<<"Error, la descripción introducida no es válida. Inténtelo de nuevo"<<"\n";
        std::cout<<"\n";
        std::cout<<"Introduzca una breve descripción del curso\n";
        getline(std::cin,aux.descripcion);
    }
    fflush(stdout);
    fichero<<aux.descripcion<<"\n";
    std::cout<<"\n";
    std::cout<<"Introduzca el número de ponentes que impartirán el curso\n";
    getline(std::cin, aux.ponentes);
    while(!isNumber(aux.ponentes)){
        std::cout<<"Error, el número de ponentes introducido no es válido. Debe introducir un numero. Inténtelo de nuevo"<<"\n";
        std::cout<<"\n";
        std::cout<<"Introduzca el numero de ponentes que impartirán el curso\n";
        getline(std::cin,aux.ponentes);
    }
    fflush(stdout);
    fichero<<aux.ponentes<<"\n";
    std::cout<<"\n";
    std::cout<<"Introduzca la duración del curso\n";
    getline(std::cin, aux.duracion);
    while(!isNumber(aux.duracion)){
        std::cout<<"Error, la duración del curso introducida no es válida. Debe introducir un numero. Inténtelo de nuevo"<<"\n";
        std::cout<<"\n";
        std::cout<<"Introduzca la duracion del curso\n";
        getline(std::cin,aux.duracion);
    }
    fflush(stdout);
    fichero<<aux.duracion<<"\n";
    std::cout<<"\n";
    std::cout<<"Introduzca el aforo del mismo\n";
    getline(std::cin, aux.aforo);
    while(!isNumber(aux.aforo)){
        std::cout<<"Error, el aforo del curso introducido no es válido. Debe introducir un numero. Inténtelo de nuevo"<<"\n";
        std::cout<<"\n";
        std::cout<<"Introduzca el aforo del mismo\n";
        getline(std::cin,aux.aforo);
    }
    fflush(stdout);
    fichero<<aux.aforo<<"\n";
    std::cout<<"\n";
    std::cout<<"Introduzca el numero de plazas disponibles\n";
    getline(std::cin, aux.plibre);
    while(!isNumber(aux.plibre)){
        std::cout<<"Error, las plazas libres introducidas no son válidas. Debe introducir un numero. Inténtelo de nuevo"<<"\n";
        std::cout<<"\n";
        std::cout<<"Introduzca el numero de plazas disponibles\n";
        getline(std::cin,aux.plibre);
    }
    fflush(stdout);
    fichero<<aux.plibre<<"\n";
    fichero.close();
}



void modificarCurso(){
    std::string nombre="";
    std::string auxline;
    int n;
    std::ifstream fichero;
    fichero.open("cursos.txt", std::ios::in);
    if(fichero.fail()){
        std::cout<<"no se pudo abrir el fichero\n";
        exit(1);
    }
    std::ofstream ficheronuevo;
    ficheronuevo.open("cursosnuevo.txt", std::fstream::app);
    std::cin.ignore();
    std::cout<<"Introduzca el nombre del curso que desea modificar\n";
    getline(std::cin, nombre);
    fflush(stdout);
    Curse aux;
    //std::cin.ignore();
    
    while(getline(fichero,auxline)){
         //std::cout<<"Los valores actuales de los parametros del curso seleccionado se muestran a continuacion:\n";
                if(auxline==nombre){
                            std::cout<<"Los valores actuales de los parametros del curso seleccionado se muestran a continuacion:\n";
                            std::cout<<"1.Nombre:"<<auxline<<"\n";
                            fflush(stdout);
                            aux.nombre=auxline;
                    getline(fichero, auxline);
                        std::cout<<"2.Descripcion:"<<auxline<<"\n";
                        aux.descripcion=auxline;
                        fflush(stdout);
                    getline(fichero, auxline);
                        std::cout<<"3.Ponentes:"<<auxline<<"\n";
                        aux.ponentes=auxline;
                        fflush(stdout);
                    getline(fichero, auxline);
                        std::cout<<"4.Duracion:"<<auxline<<"\n";
                        aux.duracion=auxline;
                        fflush(stdout);
                    getline(fichero, auxline);
                        std::cout<<"5.Aforo:"<<auxline<<"\n";
                        aux.aforo=auxline;
                        fflush(stdout);
                    getline(fichero, auxline);
                        std::cout<<"6.Plazas disponibles:"<<auxline<<"\n";
                        aux.plibre=auxline;
                        fflush(stdout);
                        
                }
                else{
                    ficheronuevo<<auxline<<"\n";
                } 
    }
    fichero.close();
    ficheronuevo.close();
    //std::cin.ignore();
    std::cout<<"\n";
    std::cout<<"Introduzca los nuevos datos del curso\n";
    std::cout<<"\n";
    
    modificadoCurso(aux.nombre);
    remove("cursos.txt");
    rename("cursosnuevo.txt", "cursos.txt");         
}
           */         
bool muestraCurso(std::string nombre){
    std::ifstream fichero;
    fichero.open("cursos.txt", std::ios::in);
    std::string auxline;
    bool encontrado=false;
    while(getline(fichero, auxline)){
        
        if(auxline==nombre){
            encontrado=true;
            std::cout<<"Nombre: "<<auxline<<"\n";
            fflush(stdout);
            getline(fichero, auxline);
            std::cout<<"Descripcion: "<<auxline<<"\n";
            fflush(stdout);
            getline(fichero, auxline);
            std::cout<<"Numero de Ponentes: "<<auxline<<"\n";
            fflush(stdout);
            getline(fichero, auxline);
            std::cout<<"Duracion: "<<auxline<<"\n";
            fflush(stdout);
            getline(fichero, auxline);
            std::cout<<"Aforo: "<<auxline<<"\n";
            fflush(stdout);
            getline(fichero, auxline);
            std::cout<<"Numero de plazas libres: "<<auxline<<"\n";
            fflush(stdout);
        }
        fflush(stdout);
    }
    if(encontrado==false){
        std::cout<<"Ese curso aun no existe en nuestro sistema\n";
        return false;
    }
    fichero.close();
    return true;
}

bool modificarCurso(Curse aux){
    // std::string nombre="";
    std::string auxline;
    int n;
    std::ifstream fichero;
    fichero.open("cursos.txt", std::ios::in);
    if(fichero.fail()){
        std::cout<<"no se pudo abrir el fichero\n";
        return false;
        exit(1);
    }
    
    
    while(isNumber(aux.descripcion)){
        std::cout<<"\n";
        std::cout<<"Error, la descripción introducida no es válida. Inténtelo de nuevo"<<"\n";
        return false;
    }
    
    
    
    while(!isNumber(aux.ponentes)){
        std::cout<<"\n";
        std::cout<<"Error, el número de ponentes introducido no es válido. Debe introducir un numero. Inténtelo de nuevo"<<"\n";
        return false;
    }
    
    while(!isNumber(aux.duracion)){
        std::cout<<"Error, la duración del curso introducida no es válida. Debe introducir un numero. Inténtelo de nuevo"<<"\n";
        return false;
    }
    
    
    while(!isNumber(aux.aforo)){
        std::cout<<"\n";
        std::cout<<"Error, el aforo del curso introducido no es válido. Debe introducir un numero. Inténtelo de nuevo"<<"\n";
        return false;
    }
    
    
    while(!isNumber(aux.plibre)){
        std::cout<<"\n";
        std::cout<<"Error, las plazas libres introducidas no son válidas. Debe introducir un numero. Inténtelo de nuevo"<<"\n";
        return false;
    }
    std::ofstream ficheronuevo;
    ficheronuevo.open("cursosnuevo.txt", std::fstream::app);
    // std::cin.ignore();
    // std::cout<<"Introduzca el nombre del curso que desea modificar\n";
    // getline(std::cin, nombre);
    // fflush(stdout);
    //std::cin.ignore();
    Curse curso;
    while(getline(fichero,auxline)){
         //std::cout<<"Los valores actuales de los parametros del curso seleccionado se muestran a continuacion:\n";
                if(auxline==aux.nombre){
                            //std::cout<<"Los valores anteriores de los parametros del curso seleccionado se muestran a continuacion:\n";
                            //std::cout<<"1.Nombre:"<<auxline<<"\n";
                            fflush(stdout);
                    getline(fichero, auxline);
                        //std::cout<<"2.Descripcion:"<<auxline<<"\n";
                        
                        fflush(stdout);
                    getline(fichero, auxline);
                        //std::cout<<"3.Ponentes:"<<auxline<<"\n";
                        
                        fflush(stdout);
                    getline(fichero, auxline);
                        //std::cout<<"4.Duracion:"<<auxline<<"\n";

                        fflush(stdout);
                    getline(fichero, auxline);
                        //std::cout<<"5.Aforo:"<<auxline<<"\n";
                        
                        fflush(stdout);
                    getline(fichero, auxline);
                        //std::cout<<"6.Plazas disponibles:"<<auxline<<"\n";
                        
                        fflush(stdout);
                        
                }
                else{
                    ficheronuevo<<auxline<<"\n";
                } 
    }
    fichero.close();
    ficheronuevo<<aux.nombre<<"\n";
    ficheronuevo<<aux.descripcion<<"\n";
    ficheronuevo<<aux.ponentes<<"\n";
    ficheronuevo<<aux.duracion<<"\n";
    ficheronuevo<<aux.aforo<<"\n";
    ficheronuevo<<aux.plibre<<"\n";
    ficheronuevo.close();
    //std::cin.ignore();
    std::cout<<"Curso modificado con éxito\n";
    remove("cursos.txt");
    rename("cursosnuevo.txt", "cursos.txt");    
    return true;     
}

void menuCursos()
{
    std::cout<<"\n";
    int opcion;
    std::string respuesta;
    do
    {
        std::cout << "\n\t\tBienvenido al programa de cursos de extensión de la UCO.\t\t\n\n";
        std::cout << "Menú del coordinador de cursos:\n";
        std::cout<<"\n";
        std::cout << "\t1. Crear curso\n\n";
        std::cout << "\t2. Visualizar cursos\n\n";
        std::cout << "\t3. Modificar curso\n\n";
        std::cout << "\t4. Visualizar los registrados en el sistema\n\n";
        std::cout << "\t5. Retroceder al menu principal\n\n";
        std::cout << "Opción: ";
        std::cin >> opcion;
        if (std::cin.fail()){ 
            clear_cin();
            std::cout<<"\n";
            std::cout<<"Error, debe introducir un numero. Intentelo de nuevo"<<"\n";
            menuCursos(); 
        }
        Curse aux;
        std::string num_ponentes;
        std::string auxline;
        bool encontrado;
        system("clear");

        switch (opcion)
        {
        case 1:
            std::cout<<"\n\n\t\tComplete la siguiente información para la creación del curso\n\n\t\t"<<"\n";
            std::cin.ignore();//para descartar el primer caraacter del buffer que es un salto de linea
            std::cout<<"Introduzca el nombre del nuevo curso\n";
            getline(std::cin, aux.nombre);
            fflush(stdout);
            std::cout<<"\n";
            std::cout<<"Introduzca una breve descripcion del curso\n";
            getline(std::cin, aux.descripcion);
            fflush(stdout);
            std::cout<<"\n";
            std::cout<<"Introduzca el número ponentes que impartirán el curso\n";
            getline(std::cin, num_ponentes);
            fflush(stdout);
            /////////////////////////////////////////////////////////////////////////
            while(stoi(num_ponentes)>5){
                std::cout<<"Error, debe haber como mínimo un ponente en el curso y como máximo 5. Repita la operación\n"<<"\n";
                std::cout<<"\n";
                std::cout<<"Introduzca el número ponentes que impartirán el curso\n";
                getline(std::cin,num_ponentes);
            }
            //////////////////////////////////////////////////////////////////////////
            std::cout<<"\n";
            std::cout<<"Introduzca, separados por dos espacios, el nombre de los ponentes que impartirán el curso\n";
            getline(std::cin, num_ponentes);
            std::cout<<"\n";
            std::cout<<"Introduzca la duración del curso\n";
            getline(std::cin, aux.duracion);
            std::cout<<"\n";
            std::cout<<"Introduzca el aforo del mismo\n";
            getline(std::cin, aux.aforo);
            fflush(stdout);
            std::cout<<"\n";
            std::cout<<"Introduzca el numero de plazas disponibles\n";
            getline(std::cin, aux.plibre);
            fflush(stdout);
            crearCurso(aux);
            std::cout<<"\n";
            std::cout<<"\n";
            std::cout<<"------------------------------------------------------------------------------------------\n";
            std::cout<<"\n";
            std::cout<<"Seleccione una opción del menu"<<"\n";
            std::cout<<"\n";
            break;
        case 2:
            mostrarCursos();
            std::cout<<"\n";
            std::cout<<"------------------------------------------------------------------------------------------\n";
            std::cout<<"\n";
            std::cout<<"Seleccione una opción del menu"<<"\n";
            std::cout<<"\n";
            break;
        case 3:
            std::cin.ignore();
            std::cout<<"Introduzca el nombre del curso que desea modificar\n";
            getline(std::cin, aux.nombre);
            fflush(stdout);
            std::cout<<"Estos son los parametros actuales de dicho curso...\n";
            encontrado=muestraCurso(aux.nombre);
            if(encontrado==false){
                break;
            }
            std::cout<<"\n";
            std::cout<<"Introduzca los nuevos datos del curso...\n";
            std::cout<<"\n";
            std::cout<<"\tIntroduzca una breve descripcion del curso\n";
            getline(std::cin, aux.descripcion);
            std::cout<<"\n";
            fflush(stdout);
            std::cout<<"\n";
            std::cout<<"\tIntroduzca el número de ponentes que impartirán el curso\n";
            getline(std::cin, aux.ponentes);
            fflush(stdout);
            while(stoi(aux.ponentes)>5){
                std::cout<<"Error, debe haber como mínimo un ponente en el curso y como máximo 5. Repita la operación\n"<<"\n";
                std::cout<<"\n";
                std::cout<<"Introduzca el número ponentes que impartirán el curso\n";
                getline(std::cin,aux.ponentes);
            }
            std::cout<<"\n";
            std::cout<<"\tIntroduzca la duración del curso\n";
            getline(std::cin, aux.duracion);
            fflush(stdout);
            std::cout<<"\n";
            std::cout<<"\tIntroduzca el aforo del mismo\n";
            getline(std::cin, aux.aforo);
            fflush(stdout);
            std::cout<<"\n";
            std::cout<<"\tIntroduzca el numero de plazas disponibles\n";
            getline(std::cin, aux.plibre);
            fflush(stdout);
            modificarCurso(aux);
            std::cout<<"\n";
            std::cout<<"------------------------------------------------------------------------------------------\n";
            std::cout<<"\n";
            std::cout<<"Seleccione una opción del menu"<<"\n";
            std::cout<<"\n";
            
            break;
        case 4:
            visualizar_registrados();
            std::cout<<"\n";
            std::cout<<"------------------------------------------------------------------------------------------\n";
            std::cout<<"\n";
            std::cout<<"Seleccione una opción del menu"<<"\n";
            std::cout<<"\n";
            break;
        case 5:
            system(EXIT_SUCCESS);
            break;
        default:
            std::cout << "Error, ha introducido una opción no válida. Se le mostrará de nuevo el menú a continuación:\n";
            sleep(1);
        };
    } while (opcion != 5);
}


void visualizar_registrados(){
    std::cout<<"A continuación, podrá visualizar las personas registradas en el sistema"<<"\n";
    std::ifstream fichero("usuariosRegistrados.txt", std::ifstream::in);
    std::string auxline;
    if(fichero.fail()){
        std::cout<<"no se pudo abrir el fichero\n";
        exit(1);
    }
    while(getline(fichero,auxline)){
        //para que no se vean los datos del coordinador
        //getline(fichero,auxline);
        //getline(fichero,auxline);
        //getline(fichero,auxline);
        //getline(fichero,auxline);
        //getline(fichero,auxline);
            std::cout<<"\n";
            std::cout<<"Dni:"<<auxline<<"\n";
            fflush(stdout);
        getline(fichero, auxline);
            fflush(stdout);
        getline(fichero, auxline);
            std::cout<<"Nombre:"<<auxline<<"\n";
            fflush(stdout);
        getline(fichero, auxline);
            std::cout<<"Apellidos:"<<auxline<<"\n";
            fflush(stdout);
        getline(fichero, auxline);
            std::cout<<"Correo electrónico:"<<auxline<<"\n";
            fflush(stdout);
        std::cout<<"\n";
        }
    fichero.close();
}


void cursosAlumno(std::string dni){
    std::cout<<"Usted se encuentra matriculado en los siguientes cursos:\n";
    std::cout<<"\n";
    std::string cursos_alumno=dni;
    cursos_alumno+=".txt";
    std::ifstream fich(cursos_alumno.c_str(),std::ifstream::in);
    if(fich.fail()){
        std::cout<<"No se ha podido abrir fichero\n";
        exit(1);
    }
    std::string auxline;
    while(getline(fich,auxline)){
        std::cout<<auxline<<"\n";
        fflush(stdout);
        }
        fich.close();
        }
