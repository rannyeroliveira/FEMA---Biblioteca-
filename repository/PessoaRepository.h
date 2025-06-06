#ifndef PESSOAREPOSITORY_H
#define PESSOAREPOSITORY_H

#include "../model/Pessoa.h"
#include <iostream>

using namespace std;

class PessoaRepository {
public:
    static const int TAMANHO = 100;

    int getMaximoPessoasParaInserir()
    {
        return TAMANHO - getTamanhoAtual();
    }

    int getTamanhoAtual() {
        return tamanhoTabelaPessoasAtual;
    }

    Pessoa* getAll() {
        return tabelaDePessoas;
    }

    PessoaRepository() {
        populaVetor();
    }

    Pessoa getByID(int id) {
        int i = 0;
        int pos = buscaBinaria(i, tamanhoTabelaPessoasAtual, tabelaDePessoas, id);
        if (pos >= 0) {
            return tabelaDePessoas[pos];
        }

        cout << "Pessoa não encontrada! Retornando pessoa vazia." << endl;
        return Pessoa();
    }

    bool existsByID(int id) {
        int i = 0;
        int pos = buscaBinaria(i, tamanhoTabelaPessoasAtual, tabelaDePessoas, id);
        return pos >= 0;
    }

    void ordenaIdParaInserir(Pessoa tabelaNovasPessoas[], int tamanhoTabelaNovasPessoas) {
        for (int i = 0; i < tamanhoTabelaNovasPessoas - 1; ++i) {
            for (int j = 0; j < tamanhoTabelaNovasPessoas - i - 1; ++j) {
                if (tabelaNovasPessoas[j].getId() > tabelaNovasPessoas[j + 1].getId()) {
                    Pessoa temp = tabelaNovasPessoas[j];
                    tabelaNovasPessoas[j] = tabelaNovasPessoas[j + 1];
                    tabelaNovasPessoas[j + 1] = temp;
                }
            }
        }
    }
    void inserirPessoas(Pessoa tabelaNovasPessoas[], int tamanhoTabelaNovasPessoas) {
        ordenaIdParaInserir(tabelaNovasPessoas, tamanhoTabelaNovasPessoas);
        int tamanhoTabelaGerada = tamanhoTabelaPessoasAtual + tamanhoTabelaNovasPessoas;
        Pessoa tabelaGerada[tamanhoTabelaGerada];

        int i = 0, j = 0, k = 0;

        while (i < tamanhoTabelaPessoasAtual && j < tamanhoTabelaNovasPessoas) {
            if (tabelaDePessoas[i].getId() < tabelaNovasPessoas[j].getId()) {
                tabelaGerada[k++] = tabelaDePessoas[i++];
            } else {
                tabelaGerada[k++] = tabelaNovasPessoas[j++];
            }
        }

        while (i < tamanhoTabelaPessoasAtual) {
            tabelaGerada[k++] = tabelaDePessoas[i++];
        }

        while (j < tamanhoTabelaNovasPessoas) {
            tabelaGerada[k++] = tabelaNovasPessoas[j++];
        }

        atualizaTabela(tabelaDePessoas, tabelaGerada, tamanhoTabelaGerada);
        tamanhoTabelaPessoasAtual = tamanhoTabelaGerada;
    }

    void updatePessoa(int id, char nome[], char cpfStr[], char endereco[], int codCidade) {
        int i = 0;
        int pos = buscaBinaria(i, tamanhoTabelaPessoasAtual, tabelaDePessoas, id);

        if (pos < 0) {
            cout << "A pessoa com id " << id << " não existe na base de dados!" << endl;
            return;
        }

        tabelaDePessoas[pos] = Pessoa(id, nome, cpfStr, endereco, codCidade);
        cout << "Pessoa atualizada com sucesso!" << endl;
    }

    void deleteByID(int tabelaPessoasRemovidas[], int tamanhoTabelaPessoasRemovidas) {
        int tamanhoTabelaGerada = tamanhoTabelaPessoasAtual - tamanhoTabelaPessoasRemovidas;
        Pessoa tabelaGerada[tamanhoTabelaGerada];

        int i = 0, j = 0, k = 0;

        for (; j < tamanhoTabelaPessoasRemovidas; i++) {
            if (tabelaDePessoas[i].getId() != tabelaPessoasRemovidas[j]) {
                tabelaGerada[k++] = tabelaDePessoas[i];
            } else {
                j++;
            }
        }

        while (i < tamanhoTabelaPessoasAtual) {
            tabelaGerada[k++] = tabelaDePessoas[i++];
        }

        atualizaTabela(tabelaDePessoas, tabelaGerada, k);
        tamanhoTabelaPessoasAtual = k;
    }

private:
    int tamanhoTabelaPessoasAtual = 10;
    Pessoa tabelaDePessoas[TAMANHO];

    void atualizaTabela(Pessoa tabela1[], Pessoa tabela2[], int tam) {
        for (int i = 0; i < tam; ++i) {
            tabela1[i] = tabela2[i];
        }
    }

    int buscaBinaria(int i, int f, Pessoa a[], int idPessoa) {
        int m;
        while (i <= f) {
            m = (i + f) / 2;
            if (a[m].getId() == idPessoa) {
                return m;
            } else if (a[m].getId() < idPessoa) {
                i = m + 1;
            } else {
                f = m - 1;
            }
        }
        return -1;
    }

    void populaVetor() {
        tabelaDePessoas[0] = Pessoa(1, (char*)"João",     (char*)"52998224725", "Rua A", 101);
        tabelaDePessoas[1] = Pessoa(2, (char*)"Maria",    (char*)"52998224725", "Rua B", 102);
        tabelaDePessoas[2] = Pessoa(3, (char*)"José",     (char*)"52998224725", "Rua C", 103);
        tabelaDePessoas[3] = Pessoa(4, (char*)"Ana",      (char*)"52998224725", "Rua D", 104);
        tabelaDePessoas[4] = Pessoa(5, (char*)"Carlos",   (char*)"52998224725", "Rua E", 105);
        tabelaDePessoas[5] = Pessoa(6, (char*)"Paula",    (char*)"52998224725", "Rua F", 106);
        tabelaDePessoas[6] = Pessoa(7, (char*)"Fernanda", (char*)"52998224725", "Rua G", 107);
        tabelaDePessoas[7] = Pessoa(8, (char*)"Lucas",    (char*)"52998224725", "Rua H", 108);
        tabelaDePessoas[8] = Pessoa(9, (char*)"Mateus",   (char*)"52998224725", "Rua I", 109);
        tabelaDePessoas[9] = Pessoa(10, (char*)"Julia",   (char*)"52998224725", "Rua J", 110);


}

};

#endif // PESSOAREPOSITORY_H
