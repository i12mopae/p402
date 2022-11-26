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

Options resolver_switch(std::string aux){
    if(aux=="Nombre"){
        return Nombre;
    }
    if(aux=="Descripcion"){
        return Descripcion;
    }
    if(aux=="Ponentes"){
        return Ponentes;
    }
    if(aux=="Duracion"){
        return Duracion;
    }
    if(aux=="Aforo"){
        return Aforo;
    }
    if(aux=="Plazas libres"){
        return Plazas_libres;
    }
}
void Curso::modifica_curso(std::string nombre){
    std::cout<<"Datos actuales del curso que desea modificar:\n";
        std::string campo;
    for(std::list<Curso>::iterator i=lista_curso_.begin(); i!=lista_curso_.end(); i++){
        if(i->get_nombre()==nombre){
            std::cout<<"Nombre: "<<nombre<<"\n";
            std::cout<<"Descripcion: "<<i->get_descripcion()<<"\n";
            std::cout<<"Ponentes: "<<i->get_ponentes()<<"\n";
            std::cout<<"Duracion: "<<i->get_duracion()<<"\n";
            std::cout<<"Aforo: "<<i->get_aforo()<<"\n";
            std::cout<<"Plazas libres: "<<i->get_plibre()<<"\n";
            std::cout<<"Introduzca  el campo que desea modificar\n";
                std::cin>>campo;
                std::string modificador;
                switch(resolver_switch(campo)){
                    case Nombre:
                    std::cout<<"Introduzca  el nuevo valor\n";
                    std::cin>>modificador;
                    set_nombre(modificador);
                    case Descripcion:
                    std::cout<<"Introduzca  el nuevo valor\n";
                    std::cin>>modificador;
                    set_nombre(modificador);
                    case Ponentes:
                    std::cout<<"Introduzca  el nuevo valor\n";
                    std::cin>>modificador;
                    set_nombre(modificador);
                    case Duracion:
                    std::cout<<"Introduzca  el nuevo valor\n";
                    std::cin>>modificador;
                    set_nombre(modificador);
                    case Aforo:
                    std::cout<<"Introduzca  el nuevo valor\n";
                    std::cin>>modificador;
                    set_nombre(modificador);
                    case Plazas_libres:
                    std::cout<<"Introduzca  el nuevo valor\n";
                    std::cin>>modificador;
                    set_nombre(modificador);
                };
        }
    }

    
}
void Curso::visualiza_cursos(){
    for(std::list<Curso>::iterator i=lista_curso_.begin(); i!=lista_curso_.end(); i++){
            std::cout<<"Nombre: "<<i->get_nombre()<<"\n";
    }
}