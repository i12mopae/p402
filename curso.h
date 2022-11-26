#ifndef CURSO_H
#define CURSO_H

#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <iterator>

class Curso{
    private:
        std::string nombre_;
        std::string descripcion_;
        std::string ponentes_;
        std::string duracion_;
        int aforo_;
        int plibre_;//plazas libres
        std::list<Curso> lista_curso_;
    public:
    Curso(std::string nombre,
        std::string descripcion,
        std::string ponentes,
        std::string duracion,
        int aforo,
        int plibre);

    inline std::string get_nombre(){ return nombre_;}
    inline std::string get_descripcion(){ return descripcion_;}
    inline std::string get_ponentes(){ return ponentes_;}
    inline std::string get_duracion(){ return duracion_;}
    inline int get_aforo(){ return aforo_;}
    inline int get_plibre(){ return plibre_;}

    inline void set_nombre(std::string nombre) { nombre_ = nombre; }
    inline void set_descripcion(std::string descripcion) { descripcion_ = descripcion; }
    inline void set_ponentes(std::string ponentes) { ponentes_ = ponentes; }
    inline void set_duracion(std::string duracion) { duracion_ = duracion; }
    inline void set_aforo(int aforo) { aforo_ = aforo; }
    inline void set_plibre(int plibre) { plibre_ = plibre; }

    inline int get_size(){return lista_curso_.size();}
    
    void add_curso(Curso c);
    void imprime_curso(std::string nombre);
    void modifica_curso(std::string nombre);
    void visualiza_cursos();
};
#endif