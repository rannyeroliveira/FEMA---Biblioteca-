//BIBLIOTECA.cpp

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>

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


struct Livro{
    int idLivro;
    char nomeLivro[50];
    int codigo_editora;
    int codigo_autor;
    int codigo_genero;
    bool disponivel;
};

//Empréstimos: codigo (PK), codigo_pessoa, codigo_livro, data_empréstimo, data_prevista_devolução, data_efetiva_devolução
struct Emprestimos{
    int idEmprestimo;
    int codigo_pessoa;
    int codigo_livro;
    char data_emprestimo[10];
    char data_prevista_devolucao[10];
    char data_efetiva_devolucao[10];
};

//1) Escreva funções específicas para a leitura dos dados das estruturas.

void lerCidades(struct Cidades cidade[]){
    for(int i=0; i<10; i++){
        cout<<"---------------------------------------Leitura de dados Cidade---------------------------------------"<<endl;
        cout<<"Digite o id da cidade"<<endl;
        cin>>cidade[i].idCidade;
        cin.ignore();
        cout<<"Digite a descricao da cidade"<<endl;
        gets(cidade[i].descricao);
        cout<<"Digite o UF da cidade"<<endl;
        gets(cidade[i].UF);

    }
}

void lerPessoas(struct Pessoas pessoa[]){
    cout<<"---------------------------------------Leitura de dados PEssoa---------------------------------------"<<endl;
    cout<<"Digite o id da pessoa:"<<endl;
    cin>>
}

int main(){
    
    struct Cidade cidades[100];
    struct Pessoa pessoas[];
    struct Editora editoras[];
    struct Autor autores[];
    struct Genero generos[];
    struct Livro livros[];
    lerCidades(cidade);
}




