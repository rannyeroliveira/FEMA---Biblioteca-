
#ifndef CIDADE_H
#define CIDADE_H

#include <cstring>

using namespace std;

class Cidade {
    int idCidade;
    char descricao[100];
    char UF[2];

public:
    Cidade() {
        idCidade = 0;
        strcpy(this->descricao, "");
        strcpy(this->UF, "");
    }

    Cidade(const int id, const char descricao[], const char UF[]) {
        this->idCidade = id;
        strcpy(this->descricao, descricao);
        strcpy(this->UF, UF);
    }

    int getId() const {
        return this->idCidade;
    }

    void setId(const int id) {
        this->idCidade = id;
    }

    const char* getDescricao() {
        return this->descricao;
    }

    void setDescricao(const char descricao[]) {
        strcpy(this->descricao, descricao);
    }

    const char* getUF() {
        return this->UF;
    }

    void setUF(const char UF[]) {
        strcpy(this->UF, UF);
    }
};

#endif // CIDADE_H