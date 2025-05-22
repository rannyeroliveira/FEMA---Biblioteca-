#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <cstring>
#include <ctime>

using namespace std;

class Emprestimo {
    int idEmprestimo;
    int codigo_pessoa;
    int codigo_livro;
    tm data_emprestimo;
    tm data_prevista_devolucao;
    tm data_efetiva_devolucao;

public:
    Emprestimo() {
        idEmprestimo = 0;
        codigo_pessoa = 0;
        codigo_livro = 0;
    }

    Emprestimo(int id_emprestimo, int codigo_pessoa, int codigo_livro, const tm& data_emprestimo,
        const tm& data_prevista_devolucao, const tm& data_efetiva_devolucao)
        : idEmprestimo(id_emprestimo),
          codigo_pessoa(codigo_pessoa),
          codigo_livro(codigo_livro),
          data_emprestimo(data_emprestimo),
          data_prevista_devolucao(data_prevista_devolucao),
          data_efetiva_devolucao(data_efetiva_devolucao)
    {
    }

    Emprestimo(int codigo_pessoa, int codigo_livro, const tm& data_emprestimo,
    const tm& data_prevista_devolucao, const tm& data_efetiva_devolucao)
    :codigo_pessoa(codigo_pessoa),
      codigo_livro(codigo_livro),
      data_emprestimo(data_emprestimo),
      data_prevista_devolucao(data_prevista_devolucao),
      data_efetiva_devolucao(data_efetiva_devolucao)
    {
    }

    int getId() const { return idEmprestimo; }
    void setId(int id){ idEmprestimo = id; }

    int getCodigoPessoa() const { return codigo_pessoa; }
    void setCodigoPessoa(int cod) { codigo_pessoa = cod; }

    int getCodigoLivro() const { return codigo_livro; }
    void setCodigoLivro(int cod) { codigo_livro = cod; }

    tm getDataEmprestimo() const {return data_emprestimo;}
    void setDataEmprestimo(tm data) {this->data_emprestimo = data;}

    tm getDataPrevista() const {return data_prevista_devolucao;}
    void setDataPrevista(tm data) {this->data_prevista_devolucao = data;}

    tm getDataEfetiva() const {return data_efetiva_devolucao;}
    void setDataEfetiva(tm data) {this->data_efetiva_devolucao = data;}
};

#endif // EMPRESTIMO_H
