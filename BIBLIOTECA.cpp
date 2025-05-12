//BIBLIOTECA.cpp

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include "model/Cidade.h";
#include "model/Livro.h";
#include "model/Editora.h";
#include "model/Autor.h";
#include "model/Genero.h";
#include "model/Emprestimo.h";
#include "model/Pessoa.h";

using namespace std;


struct Cidade{
    int idCidade;
    char descricao[70];
    char UF[30];
};

struct Pessoa{
    int idPessoa;
    char nomePessoas[50];
    char CPF[14];
    char endereco[100];
    int codigo_cidade;
};

struct Editora{
    int idEditora;
    char nomeEdtr[50];
    int codigo_cidade;
};

struct Autor{
    int idAutor;
    char nomeAutor[60];
};

struct Genero{
    int idGenero;
    char descricao[80];
};


struct Livro {
    int idLivro;
    char nomeLivro[50];
    int codigo_editora;
    int codigo_autor;
    int codigo_genero;
    bool disponivel;
};

//Empréstimos: codigo (PK), codigo_pessoa, codigo_livro, data_empréstimo, data_prevista_devolução, data_efetiva_devolução
struct Emprestimo{
    int idEmprestimo;
    int codigo_pessoa;
    int codigo_livro;
    char data_emprestimo[10];
    char data_prevista_devolucao[10];
    char data_efetiva_devolucao[10];
};


//1) Escreva funções específicas para a leitura dos dados das estruturas.

void lerCidades(struct Cidade cidade[]){
    for(int i=0; i<10; i++){
        cout<<"---------------------------------------Leitura de dados Cidade---------------------------------------"<<endl;
        cout<<"Digite o id da cidade"<<endl;
        cin>>cidade[i].idCidade;
        cin.ignore();
        cout<<"Digite a descricao da cidade"<<endl;
        gets(cidade[i].descricao);
        cout<<"Digite o UF da cidade"<<endl;
        cin >> cidade->UF;

    }
}

void lerPessoas(struct Pessoa pessoa[]){
    cout<<"---------------------------------------Leitura de dados PEssoa---------------------------------------"<<endl;
    cout<<"Digite o id da pessoa:"<<endl;
}


void popularDadosMock(
    Cidade cidades[], Pessoa pessoas[], Editora editoras[],
    Autor autores[], Genero generos[], Livro livros[],
    Emprestimo emprestimos[]
);

int main(){

    int const TAMANHO = 100;

    struct Cidade cidades[TAMANHO];
    struct Pessoa pessoas[TAMANHO];
    struct Editora editoras[TAMANHO];
    struct Autor autores[TAMANHO];
    struct Genero generos[TAMANHO];
    struct Livro livros[TAMANHO];
    struct Emprestimo emprestimos[TAMANHO];

    popularDadosMock(cidades, pessoas, editoras, autores, generos, livros, emprestimos);




}

int converteCharPraInt(char a)
{
    return a - 0;
}



// Função que preenche todos os dados com 5 registros cada
void popularDadosMock(
    Cidade cidades[], Pessoa pessoas[], Editora editoras[],
    Autor autores[], Genero generos[], Livro livros[],
    Emprestimo emprestimos[]
) {



    cidades[0].idCidade = 1;
    strcpy(cidades[0].descricao, "Sao Paulo");
    strcpy(cidades[0].UF, "SP");

    cidades[1].idCidade = 2;
    strcpy(cidades[1].descricao, "Rio de Janeiro");
    strcpy(cidades[1].UF, "RJ");

    cidades[2].idCidade = 3;
    strcpy(cidades[2].descricao, "Belo Horizonte");
    strcpy(cidades[2].UF, "MG");

    cidades[3].idCidade = 4;
    strcpy(cidades[3].descricao, "Curitiba");
    strcpy(cidades[3].UF, "PR");

    cidades[4].idCidade = 5;
    strcpy(cidades[4].descricao, "Salvador");
    strcpy(cidades[4].UF, "BA");


    pessoas[0].idPessoa = 1;
    strcpy(pessoas[0].nomePessoas, "Joao Silva");
    strcpy(pessoas[0].CPF, "123.456.789-00");
    strcpy(pessoas[0].endereco, "Rua das Flores, 123");
    pessoas[0].codigo_cidade = 1;

    pessoas[1].idPessoa = 2;
    strcpy(pessoas[1].nomePessoas, "Maria Oliveira");
    strcpy(pessoas[1].CPF, "234.567.890-11");
    strcpy(pessoas[1].endereco, "Av. Brasil, 456");
    pessoas[1].codigo_cidade = 2;

    pessoas[2].idPessoa = 3;
    strcpy(pessoas[2].nomePessoas, "Carlos Pereira");
    strcpy(pessoas[2].CPF, "345.678.901-22");
    strcpy(pessoas[2].endereco, "Rua Central, 789");
    pessoas[2].codigo_cidade = 3;

    pessoas[3].idPessoa = 4;
    strcpy(pessoas[3].nomePessoas, "Ana Costa");
    strcpy(pessoas[3].CPF, "456.789.012-33");
    strcpy(pessoas[3].endereco, "Rua das Acácias, 10");
    pessoas[3].codigo_cidade = 4;

    pessoas[4].idPessoa = 5;
    strcpy(pessoas[4].nomePessoas, "Lucas Mendes");
    strcpy(pessoas[4].CPF, "567.890.123-44");
    strcpy(pessoas[4].endereco, "Av. Independência, 999");
    pessoas[4].codigo_cidade = 5;


    editoras[0].idEditora = 1;
    strcpy(editoras[0].nomeEdtr, "Editora Globo");
    editoras[0].codigo_cidade = 1;

    editoras[1].idEditora = 2;
    strcpy(editoras[1].nomeEdtr, "Companhia das Letras");
    editoras[1].codigo_cidade = 2;

    editoras[2].idEditora = 3;
    strcpy(editoras[2].nomeEdtr, "Editora Abril");
    editoras[2].codigo_cidade = 3;

    editoras[3].idEditora = 4;
    strcpy(editoras[3].nomeEdtr, "Saraiva");
    editoras[3].codigo_cidade = 4;

    editoras[4].idEditora = 5;
    strcpy(editoras[4].nomeEdtr, "LeYa Brasil");
    editoras[4].codigo_cidade = 5;


    autores[0].idAutor = 1;
    strcpy(autores[0].nomeAutor, "Machado de Assis");

    autores[1].idAutor = 2;
    strcpy(autores[1].nomeAutor, "Clarice Lispector");

    autores[2].idAutor = 3;
    strcpy(autores[2].nomeAutor, "Carlos Drummond de Andrade");

    autores[3].idAutor = 4;
    strcpy(autores[3].nomeAutor, "Jorge Amado");

    autores[4].idAutor = 5;
    strcpy(autores[4].nomeAutor, "Cecilia Meireles");

    generos[0].idGenero = 1;
    strcpy(generos[0].descricao, "Romance");

    generos[1].idGenero = 2;
    strcpy(generos[1].descricao, "Ficcao Cientifica");

    generos[2].idGenero = 3;
    strcpy(generos[2].descricao, "Poesia");

    generos[3].idGenero = 4;
    strcpy(generos[3].descricao, "Biografia");

    generos[4].idGenero = 5;
    strcpy(generos[4].descricao, "Fantasia");



    livros[0].idLivro = 1;
    strcpy(livros[0].nomeLivro, "Dom Casmurro");
    livros[0].codigo_editora = 1;
    livros[0].codigo_autor = 1;
    livros[0].codigo_genero = 1;
    livros[0].disponivel = true;

    livros[1].idLivro = 2;
    strcpy(livros[1].nomeLivro, "A Hora da Estrela");
    livros[1].codigo_editora = 2;
    livros[1].codigo_autor = 2;
    livros[1].codigo_genero = 1;
    livros[1].disponivel = false;

    livros[2].idLivro = 3;
    strcpy(livros[2].nomeLivro, "Alguma Poesia");
    livros[2].codigo_editora = 3;
    livros[2].codigo_autor = 3;
    livros[2].codigo_genero = 3;
    livros[2].disponivel = true;

    livros[3].idLivro = 4;
    strcpy(livros[3].nomeLivro, "Capitaes da Areia");
    livros[3].codigo_editora = 4;
    livros[3].codigo_autor = 4;
    livros[3].codigo_genero = 1;
    livros[3].disponivel = true;

    livros[4].idLivro = 5;
    strcpy(livros[4].nomeLivro, "Ou Isto ou Aquilo");
    livros[4].codigo_editora = 5;
    livros[4].codigo_autor = 5;
    livros[4].codigo_genero = 3;
    livros[4].disponivel = false;



    emprestimos[0].idEmprestimo = 1;
    emprestimos[0].codigo_pessoa = 1;
    emprestimos[0].codigo_livro = 1;
    strcpy(emprestimos[0].data_emprestimo, "01/05/2025");
    strcpy(emprestimos[0].data_prevista_devolucao, "15/05/2025");
    strcpy(emprestimos[0].data_efetiva_devolucao, "14/05/2025");

    emprestimos[1].idEmprestimo = 2;
    emprestimos[1].codigo_pessoa = 2;
    emprestimos[1].codigo_livro = 2;
    strcpy(emprestimos[1].data_emprestimo, "03/05/2025");
    strcpy(emprestimos[1].data_prevista_devolucao, "17/05/2025");
    strcpy(emprestimos[1].data_efetiva_devolucao, "");

    emprestimos[2].idEmprestimo = 3;
    emprestimos[2].codigo_pessoa = 3;
    emprestimos[2].codigo_livro = 3;
    strcpy(emprestimos[2].data_emprestimo, "02/05/2025");
    strcpy(emprestimos[2].data_prevista_devolucao, "16/05/2025");
    strcpy(emprestimos[2].data_efetiva_devolucao, "16/05/2025");

    emprestimos[3].idEmprestimo = 4;
    emprestimos[3].codigo_pessoa = 4;
    emprestimos[3].codigo_livro = 4;
    strcpy(emprestimos[3].data_emprestimo, "05/05/2025");
    strcpy(emprestimos[3].data_prevista_devolucao, "19/05/2025");
    strcpy(emprestimos[3].data_efetiva_devolucao, "");

    emprestimos[4].idEmprestimo = 5;
    emprestimos[4].codigo_pessoa = 5;
    emprestimos[4].codigo_livro = 5;
    strcpy(emprestimos[4].data_emprestimo, "04/05/2025");
    strcpy(emprestimos[4].data_prevista_devolucao, "18/05/2025");
    strcpy(emprestimos[4].data_efetiva_devolucao, "17/05/2025");
}