#ifndef GENERO_SERVICE_H
#define GENERO_SERVICE_H

#include "../model/Genero.h"
#include "../repository/GeneroRepository.h"
#include <iostream>

using namespace std;

class GeneroService {
    GeneroRepository generoRepository;

    void imprimirGeneros(Genero generos[], int t) {
        for (int i = 0; i < t; ++i) {
            cout << "ID: " << generos[i].getId() << endl;
            cout << "Descrição: " << generos[i].getDescricao() << endl;
            cout << endl;
        }
    }

    void imprimirGenero(int id) {
        Genero g = generoRepository.getByID(id);
        if (strcmp(g.getDescricao(), "") != 0) {
            cout << "ID: " << g.getId() << endl;
            cout << "Descrição: " << g.getDescricao() << endl;
        }
    }

    bool isIdRepetido(Genero* genero, int id, int cont)
    {

        int i = 0;

        do
        {
            if(genero[i].getId() == id) {
                return true;
            }

            i++;
        } while (i < cont);

        return false;
    }

public:
    GeneroService() {}

    Genero createGenero(int id, const char descricao[]) {
        return Genero(id, descricao);
    }

    void createGenero() {
        int totalGenerosInserir;

        cout << "Digite quantos gêneros deseja cadastrar: ";
        cin >> totalGenerosInserir;

        if (totalGenerosInserir > generoRepository.getMaximoGenerosParaInserir()) {
            while (totalGenerosInserir > generoRepository.getMaximoGenerosParaInserir()) {
                cout << "Tamanho máximo de memória do banco excedido! \nDigite outra quantidade: ";
                cin >> totalGenerosInserir;
            }
        }

        Genero tabelaNovosGeneros[totalGenerosInserir];
        int contGenerosInseridos = 0;

        for (int i = 0; i < totalGenerosInserir; ++i) {
            int id;
            char descricao[100];

            cout << "Digite o ID: ";
            cin >> id;

            while (generoRepository.existsByID(id) || isIdRepetido(tabelaNovosGeneros, id, contGenerosInseridos)) {
                cout << "ID " << id << " já utilizado. Digite um novo ID: ";
                cin >> id;
            }

            cout << "Digite a descrição do gênero: ";
            cin.ignore();
            gets(descricao);

            tabelaNovosGeneros[i].setId(id);
            tabelaNovosGeneros[i].setDescricao(descricao);
        }

        generoRepository.inserirGeneros(tabelaNovosGeneros, totalGenerosInserir);
    }

    void deleteGenerosByID(int tabelaGenerosRemovidos[], int tamanhoTabela) {
        generoRepository.deleteByID(tabelaGenerosRemovidos, tamanhoTabela);
    }

    void getByID(int id) {
        Genero g = generoRepository.getByID(id);
        Genero v[] = { g };
        imprimirGeneros(v, 1);
    }

    Genero* getAllGeneros() {
        imprimirGeneros(generoRepository.getAll(), generoRepository.getTamanhoAtual());
    }
};

#endif // GENERO_SERVICE_H
