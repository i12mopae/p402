#include "curso.h"
int main(){
    //Prueba en el supuesto de que en el menu del coord de recursos elija gestionar cursos y dentro de este elija añadir curso
    Curso c; 
    std::string aux;
    int auxi;
    std::cout<<"Introduzca el nombre\n";
    std::cin>>aux;
    c.set_nombre(aux);
    std::cout<<"Introduzca descripcion\n";
    std::cin>>aux;
    c.set_descripcion(aux);
    std::cout<<"Introduzca ponentes\n";
    std::cin>>aux;
    c.set_ponentes(aux);
    std::cout<<"Introduzca duracion\n";
    std::cin>>aux;
    c.set_duracion(aux);
    std::cout<<"Introduzca numero de aforo\n";
    std::cin>>auxi;
    c.set_aforo(auxi);
    std::cout<<"Introduzca el numero de plazas disponibles\n";
    std::cin>>auxi;
    c.set_plibre(auxi);
    c.add_curso(c);
    c.visualiza_cursos();
    //para el boton de modificar
    std::cout<<"Introduzca el nombre del curso que desea modificar\n";
    std::cin>>aux;
    c.modifica_curso(aux);
    return 0;
} 