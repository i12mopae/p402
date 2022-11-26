#include "curso.h"

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
    std::string campo;
    std::cout<<"Introduzca  el campo que desea modificar\n";
    std::cin>>campo;
    switch(campo){
        case "Nombre":
        case "Nombre":
    };
}
void Curso::visualiza_cursos(){
    for(std::list<Curso>::iterator i=lista_curso_.begin(); i!=lista_curso_.end(); i++){
            std::cout<<"Nombre: "<<i->get_nombre()<<"\n";
    }
}