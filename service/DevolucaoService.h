#ifndef DEVOLUCAOSERVICE_H
#define DEVOLUCAOSERVICE_H

#include"../repository/PessoaRepository.h"
#include"../repository/EditoraRepository.h"
#include"../repository/LivroRepository.h"
#include"../repository/AutorRepository.h"
#include "../repository/EmprestimoRepository.h"

#include <iostream>

class DevolucaoService {
private:
    EmprestimoRepository emprestimorepository;
    PessoaRepository pessoarepository;
    LivroRepository livrorepository;
    EditoraRepository editorarepository;
    AutorRepository autorepository;


public:
    tm pegarDataAtual(){
        std::time_t agora = std::time(nullptr);
        return *std::localtime(&agora);
    }
    bool verificarNullTime(const tm& data) {
        return data.tm_sec   == 0 &&
               data.tm_min   == 0 &&
               data.tm_hour  == 0 &&
               data.tm_mday  == 0 &&
               data.tm_mon   == 0 &&
               data.tm_year  == 0 &&
               data.tm_wday  == 0 &&
               data.tm_yday  == 0 &&
               data.tm_isdst == 0;
    }
    void devolucao() {
    int codEmpDevolucao;
    cout << "Digite o codigo do emprestimo: ";
    cin >> codEmpDevolucao;

    if (!emprestimorepository.existsByID(codEmpDevolucao)) {
        do {
            cout << "ID " << codEmpDevolucao << " inexistente. Digite um novo id: ";
            cin >> codEmpDevolucao;
        } while (!emprestimorepository.existsByID(codEmpDevolucao));
    }

    Emprestimo emprestimo = emprestimorepository.getByID(codEmpDevolucao);


    if (verificarNullTime(emprestimo.getDataEfetiva())) {
        Livro livro = livrorepository.getByID(emprestimo.getCodigoLivro());
        Pessoa pessoa = pessoarepository.getByID(emprestimo.getCodigoPessoa());


        Autor autor = autorepository.getByID(livro.getCodigoAutor());
        Editora editora = editorarepository.getByID(livro.getCodigoEditora());

        tm data_atual = pegarDataAtual();

        cout << "Nome pessoa: " << pessoa.getNomePessoa() << endl;
        cout << "Nome do livro: " << livro.getNomeLivro() << endl;
        cout << "Nome da editora: " << editora.getNomeEdtr() << endl;
        cout << "Nome do autor: " << autor.getNomeAutor() << endl;
        cout << "Data do empréstimo: " << emprestimo.getDataEmprestimo().tm_mday << "/" << emprestimo.getDataEmprestimo().tm_mon + 1 << "/" << emprestimo.getDataEmprestimo().tm_year + 1900 << endl;
        cout << "Data da devolução: " << data_atual.tm_mday << "/" << data_atual.tm_mon + 1 << "/" << data_atual.tm_year + 1900 << endl;

        char confirmacao;
        cout << "Confirma devolução? [S/N]: ";
        cin >> confirmacao;

        if (confirmacao == 's' || confirmacao == 'S') {
            livrorepository.updateLivro(livro);
            emprestimorepository.atualizaDataEfetivaParaAtual(emprestimo.getId(), data_atual);
            cout << "Livro devolvido com sucesso!" << endl;
        }
    } else {
        cout << "Esse livro ja foi devolvido." << endl;
    }
}
};
#endif //DEVOLUCAOSERVICE_H