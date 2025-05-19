#ifndef GENERO_H
#define GENERO_H

#include <cstring>

using namespace std;

class Genero {
    int idGenero;
    char descricao[100];

public:
    Genero() {
        idGenero = 0;
        strcpy(this->descricao, "");
    }

    Genero(int id, const char descricao[]) {
        this->idGenero = id;
        strcpy(this->descricao, descricao);
    }

    int getId() const { return idGenero; }
    void setId(int id) { idGenero = id; }

    const char* getDescricao() { return descricao; }
    void setDescricao(const char desc[]) { strcpy(descricao, desc); }
};

#endif // GENERO_H