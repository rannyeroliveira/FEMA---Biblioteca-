//
// Created by Gabriel Isper on 19/05/25.
//

#ifndef LIVROSERVICE_H
#define LIVROSERVICE_H

#include "../repository/LivroRepository.h"
#include "../repository/EditoraRepository.h"
#include "../repository/AutorRepository.h"
#include "../repository/GeneroRepository.h"

class LivroService {
    LivroRepository livroRepository;
    EditoraRepository editoraRepository;
    AutorRepository autorRepository;
    GeneroRepository generoRepository;

public:
    void createAutor()
    {

        int totalLivrosInserir;

        cout << "Digite quantos livros você deseja cadastrar: ";
        cin >> totalLivrosInserir;

        if(totalLivrosInserir > livroRepository.getMaximoLivrosParaInserir())
        {
            do {
                cout << "Tamanho máximo de memória do banco excedido! \nDigite outra quantidade: ";
                cin >> totalLivrosInserir;
            } while (totalLivrosInserir > livroRepository.getMaximoLivrosParaInserir());
        }

        Livro tabelaNovosLivros[totalLivrosInserir];

        for (int i = 0; i < totalLivrosInserir; ++i)
        {
            int id;
            char nome[100];
            int codigo_editora;
            int codigo_autor;
            int codigo_genero;
            bool disponivel;

            cout << "Digite o ID: " << endl;
            cin >> id;


            // Validar tambem se ele repetiu algum ID
            if (livroRepository.existsByID(id))
            {
                do
                {
                    cout << "ID " << id << " já utilizado. Digite um novo id: ";
                    cin >> id;
                }
                while (livroRepository.existsByID(id));
            }

            cout << "Digite o nome: " << endl;
            cin.ignore();
            gets(nome);

            do
            {
                cout << "Digite o ID da editora: " << endl;
                cin >> codigo_editora;
            } while (!editoraRepository.existsByID(codigo_editora));
            cout << editoraRepository.getByID(codigo_editora).getNomeEdtr() << endl;

            do
            {
                cout << "Digite o ID do Autor: " << endl;
                cin >> codigo_autor;
            } while (!autorRepository.existsByID(codigo_autor));
            cout << autorRepository.getByID(codigo_autor).getNomeAutor() << endl;

            do
            {
                cout << "Digite o ID do Genero: " << endl;
                cin >> codigo_genero;
            } while (!generoRepository.existsByID(codigo_genero));
            cout << generoRepository.getByID(codigo_genero).getDescricao() << endl;

            cout << "Digite se o livro esta disponível: S/N" << endl;
            cin.ignore();
            char decision;
            cin >> decision;
            if(decision == 'S' || decision == 's')
            {
                disponivel = true;
            } else disponivel = false;

            tabelaNovosLivros[i] = Livro(id, nome, codigo_editora, codigo_autor, codigo_genero, disponivel);
        }

        livroRepository.inserirLivros(tabelaNovosLivros, totalLivrosInserir);
    }


};



#endif //LIVROSERVICE_H
