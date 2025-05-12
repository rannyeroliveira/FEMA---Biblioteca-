//
// Created by Gabriel Isper on 12/05/25.
//

#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H


#include <string>
using namespace std;

class Emprestimo {

    int idEmprestimo;
    int codigo_pessoa;
    int codigo_livro;
    string data_emprestimo;
    string data_prevista_devolucao;
    string data_efetiva_devolucao;

public:

    Emprestimo::Emprestimo(int id, int codPessoa, int codLivro, const string& dataEmp, const string& dataPrev, const string& dataEfetiva) {
        idEmprestimo = id;
        codigo_pessoa = codPessoa;
        codigo_livro = codLivro;
        data_emprestimo = dataEmp;
        data_prevista_devolucao = dataPrev;
        data_efetiva_devolucao = dataEfetiva;
    }


    int getIdEmprestimo() const {
        return idEmprestimo;
    }

    int getCodigoPessoa() const {
        return codigo_pessoa;
    }

    int getCodigoLivro() const {
        return codigo_livro;
    }

    string getDataEmprestimo() const {
        return data_emprestimo;
    }

    string getDataPrevistaDevolucao() const {
        return data_prevista_devolucao;
    }

    string getDataEfetivaDevolucao() const {
        return data_efetiva_devolucao;
    }

    void setIdEmprestimo(int id) {
        idEmprestimo = id;
    }

    void setCodigoPessoa(int codPessoa) {
        codigo_pessoa = codPessoa;
    }

    void setCodigoLivro(int codLivro) {
        codigo_livro = codLivro;
    }

    void setDataEmprestimo(const string& dataEmp) {
        data_emprestimo = dataEmp;
    }

    void setDataPrevistaDevolucao(const string& dataPrev) {
        data_prevista_devolucao = dataPrev;
    }

    void setDataEfetivaDevolucao(const string& dataEfetiva) {
        data_efetiva_devolucao = dataEfetiva;
    }
};



#endif //EMPRESTIMO_H
