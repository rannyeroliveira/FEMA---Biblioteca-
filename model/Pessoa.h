#ifndef PESSOA_H
#define PESSOA_H

#include <cstring>
#include "CPF.h"

class Pessoa {
private:
    int idPessoa;
    char nomePessoa[100];
    CPF cpf;
    char endereco[100];
    int codigo_cidade;

public:
    Pessoa() : idPessoa(0), codigo_cidade(0), cpf() {
        strcpy(nomePessoa, "");
        strcpy(endereco, "");
    }

    Pessoa(int id,char nome[], char cpfStr[], const char endereco[], int codCidade){
        this->idPessoa = id;
        strcpy(this->nomePessoa, nome);
        this->cpf= CPF(cpfStr);
        strcpy(this->endereco, endereco);
        this->codigo_cidade = codCidade;
    }

    int getId() const { return idPessoa; }
    void setId(int id) { idPessoa = id; }

    const char* getNomePessoa() const { return nomePessoa; }
    void setNomePessoa(const char nome[]) {
        strncpy(nomePessoa, nome, sizeof(nomePessoa) - 1);
        nomePessoa[sizeof(nomePessoa) - 1] = '\0';
    }

    const char* getEndereco() const { return endereco; }
    void setEndereco(const char e[]) {
        strncpy(endereco, e, sizeof(endereco) - 1);
        endereco[sizeof(endereco) - 1] = '\0';
    }

    int getCodigoCidade() const { return codigo_cidade; }
    void setCodigoCidade(int cod) { codigo_cidade = cod; }

    void setCpf( char* cpfStr) { cpf.setCPF(cpfStr); }
    const char* getCpf() const { return cpf.getCPF(); }


};

#endif // PESSOA_H
