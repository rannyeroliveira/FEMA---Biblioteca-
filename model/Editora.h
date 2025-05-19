#ifndef EDITORA_H
#define EDITORA_H

#include <cstring>

using namespace std;

class Editora {
    int idEditora;
    char nomeEdtr[100];
    int codigo_cidade;

public:
    Editora() {
        idEditora = 0;
        strcpy(this->nomeEdtr, "");
        codigo_cidade = 0;
    }

    Editora(const int id, const char nomeEdtr[], const int codigoCidade) {
        this->idEditora = id;
        strcpy(this->nomeEdtr, nomeEdtr);
        this->codigo_cidade = codigoCidade;
    }

    int getId() const {
        return this->idEditora;
    }

    void setId(const int id) {
        this->idEditora = id;
    }

    const char* getNomeEdtr() {
        return this->nomeEdtr;
    }

    void setNomeEdtr(const char nomeEdtr[]) {
        strcpy(this->nomeEdtr, nomeEdtr);
    }

    int getCodigoCidade() const {
        return this->codigo_cidade;
    }

    void setCodigoCidade(const int codigoCidade) {
        this->codigo_cidade = codigoCidade;
    }

};

#endif // EDITORA_H