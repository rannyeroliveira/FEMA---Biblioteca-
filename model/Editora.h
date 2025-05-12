//
// Created by Gabriel Isper on 12/05/25.
//

#ifndef EDITORA_H
#define EDITORA_H



#include <string>
using namespace std;

class Editora {

    int idEditora;
    string nomeEdtr;
    int codigo_cidade;

public:

    Editora(int id, const string& nome, int codCidade) {
        idEditora = id;
        nomeEdtr = nome;
        codigo_cidade = codCidade;
    }


    int getIdEditora() const {
        return idEditora;
    }

    string getNomeEdtr() const {
        return nomeEdtr;
    }

    int getCodigoCidade() const {
        return codigo_cidade;
    }


    void setIdEditora(int id) {
        idEditora = id;
    }

    void setNomeEdtr(const string& nome) {
        nomeEdtr = nome;
    }

    void setCodigoCidade(int codCidade) {
        codigo_cidade = codCidade;
    }
};




#endif //EDITORA_H
