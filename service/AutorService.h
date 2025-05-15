#ifndef AUTOR_SERVICE_H
#define AUTOR_SERVICE_H

#include "../model/Autor.h"
#include "../repository/AutorRepository.h"


class AutorService {

    AutorRepository autorRepository;

public:
    AutorService() {}

    Autor createAutor(int id, char nomeAutor[]) {
        return Autor(id, nomeAutor);
    }

    Autor getByID(int id)
    {
        return autorRepository.getByID(id);
    }

    void createAutor()
    {

        int totalAutoresInserir;

        cout << "Digite quantos autores você deseja cadastrar: ";
        cin >> totalAutoresInserir;

        int maximoAutoresParaInserir = autorRepository.TAMANHO - autorRepository.getTamanhoAtual();

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



    void leitura (Autor cli[], int &contador){
        int i = 0;
        for (int saida = 1; i < 20 && saida != 0; i++){
            int id;
            // char nome[100];

            cout << "\n\nCodigo do Cliente " << (i+1) << ": ";
            cin >> id;

            cli[i].setId(id);


            if (cli[i].getId() > 0){
                cout << "Nome: ";
                cin >> cli[i].getNomeAutor();
            }
            else saida = 0;
        }
        contador = i-1;
    }
};

#endif // AUTOR_SERVICE_H
