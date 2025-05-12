//
// Created by Gabriel Isper on 12/05/25.
//

#ifndef GENERO_H
#define GENERO_H


#include <string>
using namespace std;

class Genero {
private:
    int idGenero;
    string descricao;

public:
    Genero(int id, const string& desc) {
        idGenero = id;
        descricao = desc;
    }

    int getIdGenero() const {
        return idGenero;
    }

    string getDescricao() const {
        return descricao;
    }

    void setIdGenero(int id) {
        idGenero = id;
    }

    void setDescricao(const string& desc) {
        descricao = desc;
    }
};



#endif //GENERO_H
