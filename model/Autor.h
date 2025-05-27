#ifndef AUTOR_H
#define AUTOR_H

#include <cstring>
#include<stdio.h>

using namespace std;

class Autor {
    int idAutor;
    char nomeAutor[100];

public:
    Autor()
    {
        idAutor = 0;
        nomeAutor[0] = '0';
    }

    Autor(int id, char nomeAutor[]) {
        this->idAutor = id;
        strcpy(this->nomeAutor, nomeAutor);
    }

    int getId() const {
        return this->idAutor;
    }

    void setId(int id) {
        this->idAutor = id;
    }

    char* getNomeAutor() {
        return this->nomeAutor;
    }

    void setNomeAutor(char nomeAutor[]) {
        strcpy(this->nomeAutor, nomeAutor);
    }
};

#endif // AUTOR_H