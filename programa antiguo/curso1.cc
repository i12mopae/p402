#include "curso1.h"
//ARREGLAR, NO ME CAMBIA EL NOMBRE
void inscribirse(std::string dni){
    int plibres;
    //mostrarCursos();
    std::fstream fichero;
    std::string auxline;
    bool encontrado=false;
    Curse curso;
    std::cout<<"Introduzca el nombre del curso al que desea inscribirse\n";
    std::cout<<"(Si no quedan plazas disponibles usted quedara inscrito a la lista de espera)\n";
    std::cin.ignore();
    getline(std::cin, curso.nombre);
    std::string nombref=curso.nombre;
    nombref+=".txt";
    fichero.open(nombref.c_str(), std::ios::out);
    if(fichero.fail()){
        std::cout<<"no se ha podido abrir fichero  \n";
        exit(1);
            }
    while(getline(fichero, auxline)){
        if(auxline==dni){
            std::cout<<"Usted ya se encuentra matriculado en este curso\n";
            return;
        }
        fflush(stdout);
    }
    fichero.close();
    fflush(stdout);
    std::ifstream fcursos;
    fcursos.open("cursos.txt", std::ios::in);
    std:: ofstream fnuevo;
    fnuevo.open("cursosnuevos.txt", std::fstream::app);
    while(getline(fcursos, auxline)&&encontrado==false){
        fflush(stdout);
        if(auxline==curso.nombre){
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
                    std::cout<<"Usted se ha INSCRITO con éxito.\n";
                    std::cout<<"En breves instantes recibira un correo con las pautas que tendra que realizar para pagarlo y estar matriculado\n";
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
    fnuevo<<curso.nombre<<"\n";
    fnuevo<<curso.descripcion<<"\n";
    fnuevo<<curso.ponentes<<"\n";
    fnuevo<<curso.duracion<<"\n";
    fnuevo<<curso.aforo<<"\n";
    plibres=plibres-1;
    curso.plibre=std::to_string(plibres);
    fnuevo<<curso.plibre<<"\n";
    remove("cursos.txt");
    rename("cursosnuevos.txt", "cursos.txt");
    if(encontrado==false){
        std::cout<<"ERROR, el nombre de curso que busca no se encuentra en nuestro sistema.\n";
        std::cout<<"Intentelo de nuevo teniendo cuidado con las mayusculas, minusculas y espacios.\n";
        return;
    }
    fichero.open(nombref.c_str(), std::fstream::app);
    fichero<<dni<<"\n";
    fichero.close();
    fnuevo.close();
    fcursos.close();
}

void menuUsuario(std::string dni){
    int opcion;
    do
    {
        std::cout << "Menú de usuario:\n";
        std::cout << "\t1. Visualizar cursos\n\n";
        std::cout << "\t2. Inscribirse a curso\n";
        std::cout << "\t3. Salir\n\n";
        std::cout << "Teclee el numero asociado a la opcion que desea llevar a cabo...";
        std::cin >> opcion;

        system("clear");

        switch (opcion)
        {
        case 1:
            mostrarCursos();
            break;
        case 2:
            mostrarCursos();
            inscribirse(dni);
            break;
        case 3:
            system(EXIT_SUCCESS);
            break;
        default:
            std::cout << "Error, ha introducido una opción no válida.\n";
            break;
        };
    } while (opcion != 3);
}

bool loginUsuario(std::string dni, std::string contrasena){
    std::cout<<"Bienvenido/a a la sección de registro del sistema"<<"\n";
    //std::cout<<"LA CONTRASEÑA ES:"<<contrasena<<"\n";
    bool encontrado=false;
    std::fstream fichero;
    fichero.open("usuariosRegistrados.txt");
    std::string auxline;
    while(getline(fichero,auxline)&&encontrado==false){
        fflush(stdout);
        if(auxline==dni){
            getline(fichero,auxline);
            fflush(stdout);
            if(auxline==contrasena){
                encontrado=true;
                std::cout<<"A continuacion se le mostrará su menu correspondiente"<<"\n";
                //comprobar en que fichero esta y enseñar menu correspondiente
                if(dni=="1234"){
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
                std::cout<<"La contraseña introducida no es correcta. Repita la operacion"<<"\n";
                std::cout<<"\n";
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
    fichero.close();
    if(encontrado==false){
        std::cout<<"Usuario no encontrado, usted necesita estar previamente registrado en el sistema"<<"\n";
        registrarUsuario();
        return false;
    }
    return false;
}

void registrarUsuario(){
    std::fstream fichero;
    std::string auxline;
    fichero.open("usuariosRegistrados.txt");
    Persona aux;
    std::cin.ignore();
    std::cout<<"Introduzca su dni\n";
    getline(std::cin, aux.dni);
    while(getline(fichero, auxline)){
        if(auxline==aux.dni){
            std::cout<<"Ya existe un usuario con ese DNI.\n El DNI es un documento identificativo unico por lo que debe contactar con el administrador si cree que se trata de un error\n";
            return;
        }
    }
    fichero.close();
    fichero.open("usuariosRegistrados.txt", std::fstream::app);
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


void crearCurso(){
    std::fstream fichero;
    fichero.open("cursos.txt");
    Curse aux;
    std::string auxline;
    std::cin.ignore();//para descartar el primer caraacter del buffer que es un salto de linea
    std::cout<<"Introduzca el nombre\n";
    getline(std::cin, aux.nombre);
    fflush(stdout);
    while(getline(fichero, auxline)){
        if(auxline==aux.nombre){
            std::cout<<"ERROR. No pueden existir dos cursos con el mismo nombre.\n";
            return;
        }
        fflush(stdout);
    }
    fichero.close();
    fichero.open("cursos.txt", std::fstream::app);
    fflush(stdout);
    fichero<<aux.nombre<<"\n";
    std::cout<<"Introduzca descripcion\n";
    getline(std::cin, aux.descripcion);
    fflush(stdout);
    fichero<<aux.descripcion<<"\n";
    std::cout<<"Introduzca ponentes\n";
    getline(std::cin, aux.ponentes);
    fflush(stdout);
    fichero<<aux.ponentes<<"\n";
    std::cout<<"Introduzca duracion\n";
    getline(std::cin, aux.duracion);
    fflush(stdout);
    fichero<<aux.duracion<<"\n";
    std::cout<<"Introduzca numero de aforo\n";
    getline(std::cin, aux.aforo);
    fflush(stdout);
    fichero<<aux.aforo<<"\n";
    std::cout<<"Introduzca el numero de plazas disponibles\n";
    getline(std::cin, aux.plibre);
    fflush(stdout);
    fichero<<aux.plibre<<"\n";
    fichero.close();
}

void mostrarCursos(){
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
        std::cout<<"------------------------------------------------------------------------------------";
        }
    fichero.close();
    std::cout<<"\n";
}

void modificadoCurso(){
    std::ofstream fichero;
    fichero.open("cursosnuevo.txt", std::fstream::app);
    Curse aux;
   // std::cin.ignore();
    std::cout<<"Introduzca el nombre\n";
    getline(std::cin, aux.nombre);
    fflush(stdout);
    fichero<<aux.nombre<<"\n";
    std::cout<<"Introduzca descripcion\n";
    getline(std::cin, aux.descripcion);
    fflush(stdout);
    fichero<<aux.descripcion<<"\n";
    std::cout<<"Introduzca ponentes\n";
    getline(std::cin, aux.ponentes);
    fflush(stdout);
    fichero<<aux.ponentes<<"\n";
    std::cout<<"Introduzca duracion\n";
    getline(std::cin, aux.duracion);
    fflush(stdout);
    fichero<<aux.duracion<<"\n";
    std::cout<<"Introduzca numero de aforo\n";
    getline(std::cin, aux.aforo);
    fflush(stdout);
    fichero<<aux.aforo<<"\n";
    std::cout<<"Introduzca el numero de plazas disponibles\n";
    getline(std::cin, aux.plibre);
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
    std::cout<<"Introduzca los nuevos datos del curso\n";
    
    modificadoCurso();
    remove("cursos.txt");
    rename("cursosnuevo.txt", "cursos.txt");         
}
                    
        

void menuCursos()
{
    int opcion;
    do
    {
        std::cout << "\n\t\tBienvenido al programa de cursos de extensión de la UCO.\t\t\n\n";
        std::cout << "Menú del coordinador de cursos:\n";
        std::cout << "\t1. Crear curso\n\n";
        std::cout << "\t2. Borrar curso\n\n";
        std::cout << "\t3. Visualizar cursos\n\n";
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
            mostrarCursos();
            break;
        case 4:
            modificarCurso();
        case 5:
            system(EXIT_SUCCESS);
            break;
        default:
            std::cout << "Error, ha introducido una opción no válida.\n";
            break;
        };
    } while (opcion != 5);
}