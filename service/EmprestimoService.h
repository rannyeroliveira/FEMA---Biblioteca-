//
// Created by Gabriel Isper on 19/05/25.
//

#ifndef EMPRESTIMOSERVICE_H
#define EMPRESTIMOSERVICE_H

#include "../repository/EmprestimoRepository.h"
#include "../repository/PessoaRepository.h"


class EmprestimoService {

    EmprestimoRepository emprestimoRepository;

public:

    void emprestimo()
    {

        int idEmprestimo;
        int codigo_pessoa;
        int codigo_livro;
        char data_emprestimo[11];
        char data_prevista_devolucao[11];
        char data_efetiva_devolucao[11];

        cout << "Digite o ID da pessoa que você deseja emprestar o livro: " << endl;

    }

};



#endif //EMPRESTIMOSERVICE_H
