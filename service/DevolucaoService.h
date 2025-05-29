//
// Created by ranny on 28/05/2025.
//

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
    void devolucao() {
        Pessoa pessoa;
        Livro livro;
        Editora editora;
        Autor autor;
        Emprestimo emprestimo;
        tm data_atual;
        tm data_emprestimo;
        int codEmpDevolucao;

        cout<<"Digite o codigo do emprestimo: ";
        cin>>codEmpDevolucao;

        if (!emprestimorepository.existsByID(codEmpDevolucao))
            //se não encontrar
        {
            do
            {
                cout << "ID " << codEmpDevolucao << " inexistente. Digite um novo id: ";
                cin >> codEmpDevolucao;
            }
            while (!emprestimorepository.existsByID(codEmpDevolucao));
        }
        int confirmacao =0;
        pessoa = pessoarepository.getByID(codEmpDevolucao);
        livro = livrorepository.getByID(codEmpDevolucao);
        editora = editorarepository.getByID(codEmpDevolucao);
        autor = autorepository.getByID(codEmpDevolucao);
        emprestimo = emprestimorepository.getByID(codEmpDevolucao);
        data_atual = pegarDataAtual();
        data_emprestimo = emprestimo.getDataEmprestimo();

        cout<<"Nome pessoa:"<< pessoa.getNomePessoa()<<endl;
        cout<<"Nome do livro:"<< livro.getNomeLivro()<<endl;
        cout<<"Nome autor:"<< autor.getNomeAutor()<<endl;
        cout<<"Data emprestimo:"<<data_emprestimo<<endl;
        cout<<"Data Efetiva devolução:"<< data_atual<<endl;
    }
};
#endif //DEVOLUCAOSERVICE_H