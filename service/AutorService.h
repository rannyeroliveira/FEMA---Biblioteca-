#ifndef AUTOR_SERVICE_H
#define AUTOR_SERVICE_H

#include "../model/Autor.h"
#include "../repository/AutorRepository.h"

class AutorService
{
    AutorRepository autorRepository;

    void imprimirAutores(Autor autores[], int t)
    {
        for (int i = 0; i < t; ++i)
        {
            cout << "ID: " << autores[i].getId() << endl;
            cout << "Nome: " << autores[i].getNomeAutor() << endl;
            cout << endl;
        }
    }

    void imprimirAutor(int id)
    {
        Autor a = autorRepository.getByID(id);
        if(a.getNomeAutor() != "")
        {
            cout << a.getNomeAutor();
            return;
        }
    }

    bool isIdRepetido(Autor* autors, int id, int cont)
    {
        int i = 0;

        do
        {
            if(autors[i].getId() == id) {
                return true;
            }

            i++;
        } while (i < cont);

        return false;
    }

public:
    AutorService() {}

    Autor createAutor(int id, char nomeAutor[]) {
        return Autor(id, nomeAutor);
    }

    void createAutor()
    {

        int totalAutoresInserir;

        cout << "Digite quantos autores você deseja cadastrar: ";
        cin >> totalAutoresInserir;

        if(totalAutoresInserir > autorRepository.getMaximoAutoresParaInserir())
        {
            while (totalAutoresInserir > autorRepository.getMaximoAutoresParaInserir())
            {
                cout << "Tamanho máximo de memória do banco excedido! \nDigite outra quantidade: ";
                cin >> totalAutoresInserir;
            }
        }

        Autor tabelaNovosAutores[totalAutoresInserir];
        int contAutoresInseridos = 0;

        for (int i = 0; i < totalAutoresInserir; ++i)
        {
            int id;
            char nome[100];

            cout << "Digite o ID: " << endl;
            cin >> id;

            while (autorRepository.existsByID(id) || isIdRepetido(tabelaNovosAutores, id, contAutoresInseridos))
            {
                cout << "ID " << id << " já utilizado. Digite um novo id: ";
                cin >> id;
            }

            cout << "Digite o nome: " << endl;
            cin.ignore();
            gets(nome);

            tabelaNovosAutores[i].setId(id);
            tabelaNovosAutores[i].setNomeAutor(nome);
            contAutoresInseridos++;
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

#endif // AUTOR_SERVICE_H
