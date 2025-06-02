#ifndef CIDADE_SERVICE_H
#define CIDADE_SERVICE_H

#include "../model/Cidade.h"
#include "../repository/CidadeRepository.h"
#include <iostream>

using namespace std;

class CidadeService {
    CidadeRepository cidadeRepository;

    void imprimirCidades(Cidade cidades[], int t) {
        for (int i = 0; i < t; ++i) {
            cout << "ID: " << cidades[i].getId() << endl;
            cout << "Descrição: " << cidades[i].getDescricao() << endl;
            cout << "UF: " << cidades[i].getUF() << endl;
            cout << endl;
        }
    }

    void imprimirCidade(int id) {
        Cidade c = cidadeRepository.getByID(id);
        if (strcmp(c.getDescricao(), "") != 0) {
            cout << "ID: " << c.getId() << endl;
            cout << "Descrição: " << c.getDescricao() << endl;
            cout << "UF: " << c.getUF() << endl;
        }
    }

    bool isIdRepetido(Cidade* cidades, int id, int cont)
    {

        int i = 0;

        do
        {
            if(cidades[i].getId() == id) {
                return true;
            }

            i++;
        } while (i < cont);

        return false;
    }

public:
    CidadeService() {}

    Cidade createCidade(int id, const char descricao[], const char uf[]) {
        return Cidade(id, descricao, uf);
    }

    void createCidade() {
        int totalCidadesInserir;

        cout << "Digite quantas cidades você deseja cadastrar: ";
        cin >> totalCidadesInserir;

        if (totalCidadesInserir > cidadeRepository.getMaximoCidadesParaInserir()) {
            while (totalCidadesInserir > cidadeRepository.getMaximoCidadesParaInserir()) {
                cout << "Tamanho máximo de memória do banco excedido! \nDigite outra quantidade: ";
                cin >> totalCidadesInserir;
            }
        }

        Cidade tabelaNovasCidades[totalCidadesInserir];
        int contCidadesInseridas = 0;

        for (int i = 0; i < totalCidadesInserir; ++i) {
            int id;
            char descricao[100];
            char uf[3]; // +1 para o caractere nulo

            cout << "Digite o ID: ";
            cin >> id;

            while (cidadeRepository.existsByID(id) || isIdRepetido(tabelaNovasCidades, id, contCidadesInseridas)) {
                cout << "ID " << id << " já utilizado. Digite um novo ID: " << endl;
                cin >> id;
            }

            cout << "Digite a descrição da cidade: ";
            cin.ignore();
            gets(descricao);

            cout << "Digite a UF (2 letras): ";
            cin.getline(uf, 3);

            tabelaNovasCidades[i].setId(id);
            tabelaNovasCidades[i].setDescricao(descricao);
            tabelaNovasCidades[i].setUF(uf);
        }

        cidadeRepository.inserirCidades(tabelaNovasCidades, totalCidadesInserir);
    }

    void deleteCidadesByID(int tabelaCidadesRemovidas[], int tamanhoTabela) {
        cidadeRepository.deleteByID(tabelaCidadesRemovidas, tamanhoTabela);
    }

    void getByID(int id) {
        Cidade c = cidadeRepository.getByID(id);
        Cidade v[] = { c };
        imprimirCidades(v, 1);
    }

    Cidade* getAllCidades() {
        imprimirCidades(cidadeRepository.getAll(), cidadeRepository.getTamanhoAtual());
    }
};

#endif // CIDADE_SERVICE_H
