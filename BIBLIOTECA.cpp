//BIBLIOTECA.cpp

#include <iostream>
#include <string>
#include "service/AutorService.h"
#include "service/EditoraService.h"
#include "service/LivroService.h"
#include "service/EmprestimoService.h"
#include "service/PessoaService.h"
#include "service/DevolucaoService.h"
#include "service/CidadeService.h"
#include "service/GeneroService.h"

void mostrarMenu() {
    cout << "\nMenu:\n";
    cout << "1 - Criar cidade\n";
    cout << "2 - Criar pessoa\n";
    cout << "3 - Criar editora\n";
    cout << "4 - Criar autor\n";
    cout << "5 - Criar genero\n";
    cout << "6 - Criar livro\n";
    cout << "7 - Realizar emprestimo\n";
    cout << "8 - Realizar devolucao\n";
    cout << "9 - Mostrar livros emprestados\n";
    cout << "10 - Mostrar emprestimos atrasados\n";
    cout << "0 - Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    AutorService autor;
    LivroService livro;
    EmprestimoService emprestimo;
    PessoaService pessoa;
    DevolucaoService devolucao;
    EditoraService editora;
    CidadeService cidade;
    GeneroService genero;

    int opcao;

    do {
        mostrarMenu();
        cin >> opcao;

        switch(opcao) {
            case 1:
                cidade.createCidade();
            break;
            case 2:
                pessoa.createPessoa();
            break;
            case 3:
                editora.createEditora();
            break;
            case 4:
                autor.createAutor();
            break;
            case 5:
                genero.createGenero();
            break;
            case 6:
                livro.createLivro();
            break;
            case 7:
                emprestimo.emprestimo();
            break;
            case 8:
                devolucao.devolucao();
            break;
            case 9:
                livro.livrosDisponiveis();
            break;
            case 10:
                emprestimo.emprestimoAtrasado();
            break;
            case 0:
                cout << "Saindo do programa...\n";
            break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
            break;
        }

    } while (opcao != 0);

    return 0;







}
