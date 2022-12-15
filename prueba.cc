#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
int main(){
    std::fstream fichero;
    std::string nombre;
    std::cout<<"Introduzca el nombre del curso al que desea inscribirse\n";
    std::cout<<"(Si no quedan plazas disponibles usted quedara inscrito a la lista de espera)\n";
    std::cin.ignore();
    getline(std::cin, nombre);
    std::string nombref=nombre;
    nombref+=".txt";
    fichero.open(nombref.c_str(), std::ios::out);
    if(fichero.fail()){
        std::cout<<"no se ha podido abrir fichero  \n";
        exit(1);
            }
            return 0;
}