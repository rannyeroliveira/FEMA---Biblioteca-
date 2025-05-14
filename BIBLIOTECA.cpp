//BIBLIOTECA.cpp

#include<iostream>
#include "model/Cidade.h";
#include "model/Livro.h";
#include "model/Editora.h";
#include "model/Autor.h";
#include "model/Genero.h";
#include "model/Emprestimo.h";
#include "model/Pessoa.h";

using namespace std;


int main(){

    int const TAMANHO = 100;

    Cidade cidades[TAMANHO];
    Pessoa pessoas[TAMANHO];
    Editora editoras[TAMANHO];
    Autor autores[TAMANHO];
    Genero generos[TAMANHO];
    Livro livros[TAMANHO];
    Emprestimo emprestimos[TAMANHO];


}

int converteCharPraInt(char a)
{
    return a - 0;
}