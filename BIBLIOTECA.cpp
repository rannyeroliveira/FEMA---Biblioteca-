//BIBLIOTECA.cpp

#include <iostream>
#include <string>
#include "service/AutorService.h"

int main() {
    AutorService service;

    char gab[1] = {'a'};

    Autor a = service.createAutor(1, gab);

    std::cout << "ID do autor: " << a.getId() << std::endl;
    std::cout << "Nome do autor: " << a.getNomeAutor() << std::endl;
}


int converteCharPraInt(char a)
{
    return a - 0;
}