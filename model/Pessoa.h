#ifndef PESSOA_H
#define PESSOA_H

#include <cstring>

using namespace std;

class Pessoa {
    int idPessoa;
    char nomePessoas[100];
    char cpf[15];
    char endereco[100];
    int codigo_cidade;

public:
    Pessoa() {
        idPessoa = 0;
        strcpy(this->nomePessoas, "");
        strcpy(this->cpf, "");
        strcpy(this->endereco, "");
        codigo_cidade = 0;
    }

    Pessoa(int id, const char nome[], const char cpf[], const char endereco[], int codCidade) {
        this->idPessoa = id;
        strcpy(this->nomePessoas, nome);
        strcpy(this->cpf, cpf);
        strcpy(this->endereco, endereco);
        this->codigo_cidade = codCidade;
    }

    int getId() const { return idPessoa; }
    void setId(int id) { idPessoa = id; }

    const char* getNomePessoas() { return nomePessoas; }
    void setNomePessoas(const char nome[]) { strcpy(nomePessoas, nome); }

    const char* getCpf() { return cpf; }
    void setCpf(const char c[]) { strcpy(cpf, c); }

    const char* getEndereco() { return endereco; }
    void setEndereco(const char e[]) { strcpy(endereco, e); }

    int getCodigoCidade() const { return codigo_cidade; }
    void setCodigoCidade(int cod) { codigo_cidade = cod; }
};

#endif // PESSOA_H