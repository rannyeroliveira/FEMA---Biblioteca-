#ifndef EDITORA_SERVICE_H
#define EDITORA_SERVICE_H

#include "../model/Editora.h"
#include "../repository/EditoraRepository.h"
#include <iostream>

using namespace std;

class EditoraService
{
    EditoraRepository editoraRepository;





public:
    EditoraService() {}

    Editora createEditora(int id, char nome[], int codigoCidade)
    {
        return Editora(id, nome, codigoCidade);
    }

    void createEditora()
    {
        int totalEditorasInserir;

        cout << "Digite quantas editoras você deseja cadastrar: ";
        cin >> totalEditorasInserir;

        if (totalEditorasInserir > editoraRepository.getMaximoEditorasParaInserir())
        {
            while (totalEditorasInserir > editoraRepository.getMaximoEditorasParaInserir())
            {
                cout << "Tamanho máximo de memória do banco excedido! \nDigite outra quantidade: ";
                cin >> totalEditorasInserir;
            }
        }

        Editora tabelaNovasEditoras[totalEditorasInserir];

        for (int i = 0; i < totalEditorasInserir; ++i)
        {
            int id;
            char nome[100];
            int codigoCidade;

            cout << "Digite o ID: ";
            cin >> id;

            while (editoraRepository.existsByID(id))
            {
                cout << "ID " << id << " já utilizado. Digite um novo ID: ";
                cin >> id;
            }

            cout << "Digite o nome da editora: ";
            cin.ignore();
            gets(nome);

            cout << "Digite o código da cidade: ";
            cin >> codigoCidade;

            tabelaNovasEditoras[i].setId(id);
            tabelaNovasEditoras[i].setNomeEdtr(nome);
            tabelaNovasEditoras[i].setCodigoCidade(codigoCidade);
        }

        editoraRepository.inserirEditoras(tabelaNovasEditoras, totalEditorasInserir);
    }

    void deleteEditorasByID(int tabelaEditorasRemovidas[], int tamanhoTabela)
    {
        editoraRepository.deleteByID(tabelaEditorasRemovidas, tamanhoTabela);
    }

    void getByID(int id)
    {
        Editora e = editoraRepository.getByID(id);
        Editora v[] = {e};

    }

};

#endif // EDITORA_SERVICE_H
