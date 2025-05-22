//
// Created by Gabriel Isper on 19/05/25.
//

#ifndef EMPRESTIMOSERVICE_H
#define EMPRESTIMOSERVICE_H

#include "../repository/EmprestimoRepository.h"
#include "../repository/PessoaRepository.h"
#include "../model/Cidade.h"
#include "../repository/CidadeRepository.h"
#include "../repository/LivroRepository.h"
#include "../repository/EditoraRepository.h"
#include "../repository/AutorRepository.h"


class EmprestimoService {

    EmprestimoRepository emprestimoRepository;
    PessoaRepository pessoaRepository;
    CidadeRepository cidadeRepository;
    LivroRepository livroRepository;
    EditoraRepository editoraRepository;
    AutorRepository autorRepository;

    tm pegarDataAtual() {
        std::time_t agora = std::time(nullptr);
        return *std::localtime(&agora);
    }

    tm adicionarDias(int dias) {
        time_t agora = time(nullptr);
        tm data = *localtime(&agora);
        data.tm_mday += dias;
        mktime(&data);
        return data;
    }

public:

    void emprestimo()
    {
        int codigo_pessoa;
        int codigo_livro;
        tm data_emprestimo;
        tm data_prevista_devolucao;
        tm data_efetiva_devolucao;

        do
        {
            cout << "Digite o ID da pessoa que você deseja emprestar o livro: " << endl;
            cin >> codigo_pessoa;
            if(!pessoaRepository.existsByID(codigo_pessoa)) cout << "Pessoa não encontrada!" << endl;
        } while (!pessoaRepository.existsByID(codigo_pessoa));
        Pessoa p = pessoaRepository.getByID(codigo_pessoa);
        cout << "Nome da pessoa: " << p.getNomePessoa() << endl;

        Cidade c = cidadeRepository.getByID(p.getCodigoCidade());
        cout << "Nome da cidade da pessoa: " << c.getDescricao() << endl;

        do
        {
            cout << "\nDigite o ID do livro a ser emprestado: " << endl;
            cin >> codigo_livro;

            if(!livroRepository.existsByID(codigo_livro))
                cout << "Livro não encontrado!" << endl;
            else if(!livroRepository.isDisponivel(codigo_livro))
                cout << "Livro encontrado não está disponível! Digite outro livro.";

        } while (!livroRepository.existsByID(codigo_livro) || !livroRepository.isDisponivel(codigo_livro));

        Livro l = livroRepository.getByID(codigo_livro);
        cout << "Nome do livro: " << l.getNomeLivro() << endl;

        Editora e = editoraRepository.getByID(l.getCodigoEditora());
        cout << "Nome da Editora: " << e.getNomeEdtr() << endl;

        Autor a = autorRepository.getByID(l.getCodigoAutor());
        cout << "Nome do autor: " << a.getNomeAutor() << endl;

        data_emprestimo = pegarDataAtual();
        data_prevista_devolucao = adicionarDias(7);
        data_efetiva_devolucao = {};

        l.setDisponivel(false);
        livroRepository.updateLivro(l);

        Emprestimo emp = Emprestimo(codigo_pessoa, codigo_livro, data_emprestimo, data_prevista_devolucao, data_efetiva_devolucao);
        Emprestimo empArray[1] = {emp};
        empArray[0].setId(emprestimoRepository.getUltimoIdCadastrado() + 1);
        emprestimoRepository.inserirEmprestimos(empArray, 1);
        cout << "Emprestimo inserido com sucesso!" << endl;
    }
};



#endif //EMPRESTIMOSERVICE_H
