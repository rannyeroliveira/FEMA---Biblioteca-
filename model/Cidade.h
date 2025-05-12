//
// Created by Gabriel Isper on 12/05/25.
//

#ifndef CIDADE_H
#define CIDADE_H


#include <string>
using namespace std;

class Cidade {

    int idCidade;
    string descricao;
    string UF;

public:

    Cidade(int id, const string& desc, const string& uf) {
        idCidade = id;
        descricao = desc;
        UF = uf;
    }


    int getIdCidade() const {
        return idCidade;
    }

    string getDescricao() const {
        return descricao;
    }

    string getUF() const {
        return UF;
    }


    void setIdCidade(int id) {
        idCidade = id;
    }

    void setDescricao(const string& desc) {
        descricao = desc;
    }

    void setUF(const string& uf) {
        UF = uf;
    }
};


#endif //CIDADE_H
