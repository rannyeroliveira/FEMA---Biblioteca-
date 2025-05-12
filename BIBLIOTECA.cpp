//BIBLIOTECA.cpp

#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

struct Cidades{
    int idCidade;
    char descricao[70];
    char UF[30];
};

struct Pessoas{
    int idPessoa;
    char nomePessoas[50];
    char CPF[14];
    char endereco[100];
    int codigo_cidade;
};

struct Editoras{
    int idEditora;
    char nomeEdtr[50];
    int codigo_cidade;
};

struct Autores{
    int idAutor;
    char nomeAutor[60];
};

struct Generos{
    int idGenero;
    char descricao[80];
};


struct Livros{
    int idLivro;
    char nomeLivro[50];
    int codigo_editora;
    int codigo_autor;
    int codigo_genero;
    bool disponivel;
};

//Empr�stimos: codigo (PK), codigo_pessoa, codigo_livro, data_empr�stimo, data_prevista_devolu��o, data_efetiva_devolu��o
struct Emprestimos{
    int idEmprestimo;
    int codigo_pessoa;
    int codigo_livro;
    char data_emprestimo[10];
    char data_prevista_devolucao[10];
    char data_efetiva_devolucao[10];
};

//1) Escreva fun��es espec�ficas para a leitura dos dados das estruturas.

void lerCidades(struct Cidades cidade[]){
    for(int i=0; i<10; i++){
        cout<<"---------------------------------------Insercao de dados Cidade---------------------------------------"<<endl;
        cout<<"Digite o id da cidade"<<endl;
        cin>>cidade[i].idCidade;
        cin.ignore();
        cout<<"Digite a descricao da cidade"<<endl;
        gets(cidade[i].descricao);
        cout<<"Digite o UF da cidade"<<endl;
        gets(cidade[i].UF);

    }
}

/*
struct Pessoas{
    int idPessoa;
    char nomePessoas[50];
    char CPF[14];
    char endereco[100];
    int codigo_cidade;
};
*/
int main(){
    struct Cidades cidade[100];
}




