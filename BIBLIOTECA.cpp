//BIBLIOTECA.cpp

#include <iostream>
#include <string>
#include "service/AutorService.h"


int main() {
    AutorService service;

    // service.getAllAutores();

    service.getByID(1);
}


int converteCharPraInt(char a)
{
    return a - 0;
}