#include "curso.h"

Curso::Curso(std::string nombre,
        std::string descripcion,
        std::string ponentes,
        std::string duracion,
        int aforo,
        int plibre){
            nombre_=nombre;
            descripcion_=descripcion;
            ponentes_=ponentes;
            duracion_=duracion;
            aforo_=aforo;
            plibre_=plibre;
        }

void crearCurso(){
    std::ofstream fichero;
    fichero.open("cursos.txt", std::fstream::app);
    Curse aux;
    std::cin.ignore();//para descartar el primer caraacter del buffer que es un salto de linea
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
    std::string nombre;
    std::string auxline;
    int n;
    std::string modificador;
    std::cout<<"Introduzca el nombre del curso que desea modificar\n";
    getline(std::cin, nombre);
    std::ifstream fichero("cursos.txt");
    std::ofstream ficheronuevo("cursosnuevo.txt");
    Curse aux;
    while(getline(fichero,auxline)){
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
                }else{
                    ficheronuevo<<auxline<<"\n";
                } 
    }
    fichero.close();
    ficheronuevo.close();
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
        }
    } while (opcion != 5);
}
/*
void Curso::add_curso(Curso c){
    
    for(std::list<Curso>::iterator i=lista_curso_.begin(); i!=lista_curso_.end(); i++){
        if(i->get_nombre()==c.get_nombre()){
            std::cout<<"Ese curso ya está añadido a la lista\n";
            return;
        }
    }
    lista_curso_.push_back(c);
}
void Curso::imprime_curso(std::string nombre){
    for(std::list<Curso>::iterator i=lista_curso_.begin(); i!=lista_curso_.end(); i++){
        if(i->get_nombre()==nombre){
            std::cout<<"Nombre: "<<nombre<<"\n";
            std::cout<<"Descripcion: "<<i->get_descripcion()<<"\n";
            std::cout<<"Ponentes: "<<i->get_ponentes()<<"\n";
            std::cout<<"Duracion: "<<i->get_duracion()<<"\n";
            std::cout<<"Aforo: "<<i->get_aforo()<<"\n";
            std::cout<<"Plazas libres: "<<i->get_plibre()<<"\n";
        }
    }
}

void Curso::modifica_curso(std::string nombre){
    std::cout<<"Datos actuales del curso que desea modificar:\n";
        std::string campo;
    for(std::list<Curso>::iterator i=lista_curso_.begin(); i!=lista_curso_.end(); i++){
        if(i->get_nombre()==nombre){
            std::cout<<"1.Nombre: "<<nombre<<"\n";
            std::cout<<"2.Descripcion: "<<i->get_descripcion()<<"\n";
            std::cout<<"3.Ponentes: "<<i->get_ponentes()<<"\n";
            std::cout<<"4.Duracion: "<<i->get_duracion()<<"\n";
            std::cout<<"5.Aforo: "<<i->get_aforo()<<"\n";
            std::cout<<"6.Plazas libres: "<<i->get_plibre()<<"\n";
            std::cout<<"Introduzca  el número del campo que desea modificar\n";
            int campo;
            std::cin>>campo;
                
                std::string modificador;
                switch(campo){
                    case 1:
                    std::cout<<"Introduzca  el nuevo valor\n";
                    std::cin>>modificador;
                    set_nombre(modificador);
                    break;
                    case 2:
                    std::cout<<"Introduzca  el nuevo valor\n";
                    std::cin>>modificador;
                    set_nombre(modificador);
                    break;
                    case 3:
                    std::cout<<"Introduzca  el nuevo valor\n";
                    std::cin>>modificador;
                    set_nombre(modificador);
                    break;
                    case 4:
                    std::cout<<"Introduzca  el nuevo valor\n";
                    std::cin>>modificador;
                    set_nombre(modificador);
                    break;
                    case 5:
                    std::cout<<"Introduzca  el nuevo valor\n";
                    std::cin>>modificador;
                    set_nombre(modificador);
                    break;
                    case 6:
                    std::cout<<"Introduzca  el nuevo valor\n";
                    std::cin>>modificador;
                    set_nombre(modificador);
                    break;
                };
        }
    }
    std::cout<<"Cambio realizado con exito\n";
    
}
void Curso::visualiza_cursos(){
    for(std::list<Curso>::iterator i=lista_curso_.begin(); i!=lista_curso_.end(); i++){
            std::cout<<"Nombre: "<<i->get_nombre()<<"\n";
            std::cout<<"Descripcion: "<<i->get_descripcion()<<"\n";
            std::cout<<"Ponentes: "<<i->get_ponentes()<<"\n";
            std::cout<<"Duracion: "<<i->get_duracion()<<"\n";
            std::cout<<"Aforo: "<<i->get_aforo()<<"\n";
            std::cout<<"Plazas libres: "<<i->get_plibre()<<"\n";
    }
}
*/
