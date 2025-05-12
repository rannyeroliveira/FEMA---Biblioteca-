//
// Created by Gabriel Isper on 12/05/25.
//

#ifndef PESSOA_H
#define PESSOA_H


#include <string>
using namespace std;

class Pessoa {

    int idPessoa;
    string nomePessoas;
    string cpf;
    string endereco;
    int codigo_cidade;

public:
    Pessoa(int id, const string& nome, const string& documento, const string& end, int codCidade) {
        idPessoa = id;
        nomePessoas = nome;
        cpf = documento;
        endereco = end;
        codigo_cidade = codCidade;
    }

    int getIdPessoa() const {
        return idPessoa;
    }

    string getNomePessoas() const {
        return nomePessoas;
    }

    string getCpf() const {
        return cpf;
    }

    string getEndereco() const {
        return endereco;
    }

    int getCodigoCidade() const {
        return codigo_cidade;
    }

    void setIdPessoa(int id) {
        idPessoa = id;
    }

    void setNomePessoas(const string& nome) {
        nomePessoas = nome;
    }

    void setCpf(const string& documento) {
        cpf = documento;
    }

    void setEndereco(const string& end) {
        endereco = end;
    }

    void setCodigoCidade(int codCidade) {
        codigo_cidade = codCidade;
    }
};



#endif //PESSOA_H
