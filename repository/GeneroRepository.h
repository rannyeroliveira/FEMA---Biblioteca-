#ifndef GENEROREPOSITORY_H
#define GENEROREPOSITORY_H

#include "../model/Genero.h"
#include <iostream>

using namespace std;

class GeneroRepository {
public:
    static const int TAMANHO = 100;

    int getTamanhoAtual() {
        return tamanhoTabelaGenerosAtual;
    }

    Genero* getAll() {
        return tabelaDeGeneros;
    }

    GeneroRepository() {
        populaVetor();
    }

    Genero getByID(int id) {
        int i = 0;
        int pos = buscaBinaria(i, tamanhoTabelaGenerosAtual, tabelaDeGeneros, id);
        if (pos >= 0) {
            return tabelaDeGeneros[pos];
        }

        cout << "Gênero não encontrado! Retornando objeto vazio." << endl;
        return Genero();
    }

    bool existsByID(int id) {
        int i = 0;
        int pos = buscaBinaria(i, tamanhoTabelaGenerosAtual, tabelaDeGeneros, id);
        return (pos >= 0);
    }

    void inserirGeneros(Genero novosGeneros[], int tamanhoNovos) {
        int novoTamanhoTotal = tamanhoTabelaGenerosAtual + tamanhoNovos;
        Genero tabelaAtualizada[novoTamanhoTotal];

        int i = 0, j = 0, k = 0;

        while (i < tamanhoTabelaGenerosAtual && j < tamanhoNovos) {
            if (tabelaDeGeneros[i].getId() < novosGeneros[j].getId()) {
                tabelaAtualizada[k++] = tabelaDeGeneros[i++];
            } else {
                tabelaAtualizada[k++] = novosGeneros[j++];
            }
        }

        while (i < tamanhoTabelaGenerosAtual) {
            tabelaAtualizada[k++] = tabelaDeGeneros[i++];
        }

        while (j < tamanhoNovos) {
            tabelaAtualizada[k++] = novosGeneros[j++];
        }

        atualizaTabela(tabelaDeGeneros, tabelaAtualizada, novoTamanhoTotal);
        tamanhoTabelaGenerosAtual = novoTamanhoTotal;
    }

    void updateGenero(int id, char descricao[]) {
        int i = 0;
        int pos = buscaBinaria(i, tamanhoTabelaGenerosAtual, tabelaDeGeneros, id);

        if (pos < 0) {
            cout << "O gênero com id " << id << " não existe na base de dados!" << endl;
            return;
        }

        tabelaDeGeneros[pos] = Genero(id, descricao);
        cout << "Gênero atualizado com sucesso!" << endl;
    }

    void deleteByID(int idsParaRemover[], int tamanhoRemocoes) {
        int novoTamanho = tamanhoTabelaGenerosAtual - tamanhoRemocoes;
        Genero tabelaAtualizada[novoTamanho];

        int i = 0, j = 0, k = 0;

        for (; j < tamanhoRemocoes; i++) {
            if (tabelaDeGeneros[i].getId() != idsParaRemover[j]) {
                tabelaAtualizada[k++] = tabelaDeGeneros[i];
            } else {
                j++;
            }
        }

        while (i < tamanhoTabelaGenerosAtual) {
            tabelaAtualizada[k++] = tabelaDeGeneros[i++];
        }

        atualizaTabela(tabelaDeGeneros, tabelaAtualizada, k);
        tamanhoTabelaGenerosAtual = k;
    }

private:
    int tamanhoTabelaGenerosAtual = 10;
    Genero tabelaDeGeneros[TAMANHO];

    void atualizaTabela(Genero destino[], Genero origem[], int tam) {
        for (int i = 0; i < tam; ++i) {
            destino[i] = origem[i];
        }
    }

    int buscaBinaria(int i, int f, Genero a[], int idGenero) {
        int m;
        while (i <= f) {
            m = (i + f) / 2;
            if (a[m].getId() == idGenero) {
                return m;
            } else if (a[m].getId() < idGenero) {
                i = m + 1;
            } else {
                f = m - 1;
            }
        }
        return -1;
    }

    void populaVetor() {
        tabelaDeGeneros[0] = Genero(1, "Romance");
        tabelaDeGeneros[1] = Genero(2, "Ficção Científica");
        tabelaDeGeneros[2] = Genero(3, "Fantasia");
        tabelaDeGeneros[3] = Genero(4, "Terror");
        tabelaDeGeneros[4] = Genero(5, "Drama");
        tabelaDeGeneros[5] = Genero(6, "Aventura");
        tabelaDeGeneros[6] = Genero(7, "Comédia");
        tabelaDeGeneros[7] = Genero(8, "Suspense");
        tabelaDeGeneros[8] = Genero(9, "Biografia");
        tabelaDeGeneros[9] = Genero(10, "Histórico");
    }
};

#endif // GENEROREPOSITORY_H
