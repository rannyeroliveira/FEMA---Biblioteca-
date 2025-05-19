#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <cstring>

using namespace std;

class Emprestimo {
    int idEmprestimo;
    int codigo_pessoa;
    int codigo_livro;
    char data_emprestimo[11];
    char data_prevista_devolucao[11];
    char data_efetiva_devolucao[11];

public:
    Emprestimo() {
        idEmprestimo = 0;
        codigo_pessoa = 0;
        codigo_livro = 0;
        strcpy(this->data_emprestimo, "");
        strcpy(this->data_prevista_devolucao, "");
        strcpy(this->data_efetiva_devolucao, "");
    }

    Emprestimo(int id, int codPessoa, int codLivro, const char dataEmp[], const char dataPrev[], const char dataEfetiva[]) {
        this->idEmprestimo = id;
        this->codigo_pessoa = codPessoa;
        this->codigo_livro = codLivro;
        strcpy(this->data_emprestimo, dataEmp);
        strcpy(this->data_prevista_devolucao, dataPrev);
        strcpy(this->data_efetiva_devolucao, dataEfetiva);
    }

    int getId() const { return idEmprestimo; }
    void setId(int id) { idEmprestimo = id; }

    int getCodigoPessoa() const { return codigo_pessoa; }
    void setCodigoPessoa(int cod) { codigo_pessoa = cod; }

    int getCodigoLivro() const { return codigo_livro; }
    void setCodigoLivro(int cod) { codigo_livro = cod; }

    const char* getDataEmprestimo() { return data_emprestimo; }
    void setDataEmprestimo(const char data[]) { strcpy(data_emprestimo, data); }

    const char* getDataPrevistaDevolucao() { return data_prevista_devolucao; }
    void setDataPrevistaDevolucao(const char data[]) { strcpy(data_prevista_devolucao, data); }

    const char* getDataEfetivaDevolucao() { return data_efetiva_devolucao; }
    void setDataEfetivaDevolucao(const char data[]) { strcpy(data_efetiva_devolucao, data); }
};

#endif // EMPRESTIMO_H
