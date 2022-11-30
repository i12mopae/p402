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
/*
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
*/
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