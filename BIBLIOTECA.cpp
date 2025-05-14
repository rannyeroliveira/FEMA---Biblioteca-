//BIBLIOTECA.cpp

#include <iostream>
#include <string>
#include "service/AutorService.h"



int main() {
    AutorService service;



    Autor a = service.getByID(2);

    std::cout << "ID do autor: " << a.getId() << std::endl;
    std::cout << "Nome do autor: " << a.getNomeAutor() << std::endl;
}


int converteCharPraInt(char a)
{
    return a - 0;
}