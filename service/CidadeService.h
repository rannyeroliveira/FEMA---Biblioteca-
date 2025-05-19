//
// Created by Gabriel Isper on 19/05/25.
//

#ifndef CIDADESERVICE_H
#define CIDADESERVICE_H

#include "../repository/CidadeRepository.h"


class CidadeService {
    CidadeRepository cidadeRepository;

    void imprimirCidades(Cidade cidades[], int t)
    {
        for (int i = 0; i < t; ++i)
        {
            cout << "ID: " << cidades[i].getId() << endl;
            cout << "Nome: " << cidades[i].getDescricao() << endl;
            cout << "UF: " << cidades[i].getUF() << endl;
            cout << endl;
        }
    }

    void imprimirCidade(int id)
    {
        Cidade c = cidadeRepository.getByID(id);
        if(c.getDescricao() != "")
        {
            cout << c.getDescricao() << endl;
            return;
        }
    }

public:
    CidadeService() {}

    void createCidade()
    {

        int totalCidadesInserir;

        cout << "Digite quantos autores você deseja cadastrar: ";
        cin >> totalCidadesInserir;

        int maximoAutoresParaInserir = cidadeRepository.TAMANHO - cidadeRepository.getTamanhoAtual();

        if(totalAutoresInserir > maximoAutoresParaInserir)
        {
            while (totalAutoresInserir > maximoAutoresParaInserir)
            {
                cout << "Tamanho máximo de memória do banco excedido! \nDigite outra quantidade: ";
                cin >> totalAutoresInserir;
            }
        }

        Autor tabelaNovosAutores[totalAutoresInserir];

        for (int i = 0; i < totalAutoresInserir; ++i)
        {
            int id;
            char nome[100];

            cout << "Digite o ID: " << endl;
            cin >> id;


            // Validar tambem se ele repetiu algum ID
            if (autorRepository.existsByID(id))
            {
                do
                {
                    cout << "ID " << id << " já utilizado. Digite um novo id: ";
                    cin >> id;
                }
                while (autorRepository.existsByID(id));
            }

            cout << "Digite o nome: " << endl;
            cin.ignore();
            gets(nome);

            tabelaNovosAutores[i].setId(id);
            tabelaNovosAutores[i].setNomeAutor(nome);
        }

        autorRepository.inserirAutores(tabelaNovosAutores, totalAutoresInserir);
    }

    void deleteAutoresByID(int TabelaAutoresRemovidos[], int tamanhoTabelaAutoresRemovidos){
        {
            autorRepository.deleteByID(TabelaAutoresRemovidos, tamanhoTabelaAutoresRemovidos);
        }


    }

    void getByID(int id)
    {
        Autor a = autorRepository.getByID(id);

        Autor v[] = {a};

        imprimirAutores(v, 1);
    }

    Autor* getAllAutores()
    {
        imprimirAutores(autorRepository.getAll(), autorRepository.getTamanhoAtual());
    }
};



#endif //CIDADESERVICE_H
