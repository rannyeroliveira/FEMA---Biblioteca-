//
// Created by Gabriel Isper on 14/05/25.
//

#ifndef AUTORREPOSITORY_H
#define AUTORREPOSITORY_H

#include "../model/Autor.h"

class AutorRepository
{
public:
    int static const TAMANHO = 100;

    int getMaximoAutoresParaInserir()
    {
        return TAMANHO - getTamanhoAtual();
    }

    int getTamanhoAtual()
    {
        return this->tamanhoTabelaAutoresAtual;
    }

    Autor* getAll()
    {
        return tabelaDeAutores;
    }

    AutorRepository() {populaVetor();}

    Autor getByID(int id)
    {
        int i = 0;
        int a = buscaBinaria(i, tamanhoTabelaAutoresAtual, tabelaDeAutores, id);
        if(a >= 0)
        {
            return tabelaDeAutores[a];
        }

        cout << "Autor não encontrado! Retornando autor vazio.";
        return Autor();
    }

    bool existsByID(int id)
    {
        int i = 0;
        int p = buscaBinaria(i, tamanhoTabelaAutoresAtual, tabelaDeAutores, id);

        if(p >= 0)
        {
            return true;
        }

        return false;
    }

    void inserirAutores(Autor tabelaNovosAutores[], int tamanhoTabelaNovosAutores)
    {                  // Tabela novos autores = T

        int tamanhoTabelaGeradaAutores = tamanhoTabelaNovosAutores + tamanhoTabelaAutoresAtual;

        // A
        Autor tabelaGeradaAutores[tamanhoTabelaGeradaAutores];

        // s
        int contadorTabelaPrincipal = 0;

        // t
        int contadorTabelaNovosAutores = 0;

        // a
        int contadorTabelaGerada = 0;

        while(contadorTabelaPrincipal < getTamanhoAtual() && contadorTabelaNovosAutores < tamanhoTabelaGeradaAutores){
            if(tabelaDeAutores[contadorTabelaPrincipal].getId() < tabelaNovosAutores[contadorTabelaNovosAutores].getId()){
                tabelaGeradaAutores[contadorTabelaGerada] = tabelaDeAutores[contadorTabelaPrincipal++];
            }else{
                tabelaGeradaAutores[contadorTabelaGerada] = tabelaNovosAutores[contadorTabelaNovosAutores++];
            }
            contadorTabelaGerada++;
        }

        while(contadorTabelaPrincipal < getTamanhoAtual()){
            tabelaGeradaAutores[contadorTabelaGerada++] = tabelaDeAutores[contadorTabelaPrincipal++];
        }

        while(contadorTabelaNovosAutores < tamanhoTabelaNovosAutores){
            tabelaGeradaAutores[contadorTabelaGerada++] = tabelaNovosAutores[contadorTabelaNovosAutores++];
        }

        atualizaTabela(tabelaDeAutores, tabelaGeradaAutores, tamanhoTabelaGeradaAutores);
    }

    // Da pra trocar e fazer um array, tipo se ele mandar 10 autores a gente atualiza os 10
    // porém isso adiciona mais complexidade
    void updateAutor(char nomeAutor[], int id)
    {
        int i = 0;

        int pos = buscaBinaria(i, tamanhoTabelaAutoresAtual, tabelaDeAutores, id);

        if(pos < 0)
        {
            cout << "O Autor com id " << id << " não existe na base de dados!";
            return;
        }

        tabelaDeAutores[pos] = Autor(id, nomeAutor);
        cout << "Autor atualizado com sucesso!" << endl;
    }


    void deleteByID (int TabelaAutoresRemovidos[], int tamanhoTabelaAutoresRemovidos){

        // Clientes S = tabelaDeAutores
        // T = IDs a remover
        // A = Tabela atualizada sem Autores que foram deletados

        // contA
        int tamanhoTabelaGeradaAutores = tamanhoTabelaAutoresAtual - tamanhoTabelaAutoresRemovidos;

        Autor tabelaGeradaAutores[tamanhoTabelaGeradaAutores];

        int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)

        for (;j < tamanhoTabelaAutoresRemovidos; i++){
            if (tabelaDeAutores[i].getId() != TabelaAutoresRemovidos[j]){
                tabelaGeradaAutores[k].setId(tabelaDeAutores[i].getId());
                strcpy (tabelaGeradaAutores[k].getNomeAutor(),tabelaDeAutores[i].getNomeAutor());
                k++;
            }
            else {
                j++;
            }
        }
        while (i < tamanhoTabelaAutoresAtual){
            tabelaGeradaAutores[k].setId(tabelaDeAutores[i].getId());
            strcpy (tabelaGeradaAutores[k].getNomeAutor(),tabelaDeAutores[i].getNomeAutor());
            i++;
            k++;
        }

        tamanhoTabelaAutoresAtual = k;
    }




private:
    int pos;
    int tamanhoTabelaAutoresAtual = 10;
    Autor tabelaDeAutores[TAMANHO];

    void atualizaTabela(Autor tabela1[], Autor tabela2[], int tam)
    {
        for (int i = 0; i < tam; ++i)
        {
            tabela1[i] = tabela2[i];
        }
    }

    int buscaBinaria(int i, int f, Autor a[], int idCliente)
    {
        int m;
        while (i <= f)
        {
            m = (i + f) / 2;
            if(a[m].getId() == idCliente)
            {
                return m;
            } else if(a[m].getId() < idCliente)
            {
                i = m + 1;
            } else f = m - 1;
        }

        return -1;
    }

    void populaVetor()
    {
        tabelaDeAutores[0] = Autor(1, (char*) "Machado de Assis");
        tabelaDeAutores[1] = Autor(2, (char*) "Clarice Lispector");
        tabelaDeAutores[2] = Autor(3, (char*) "William Shakespeare");
        tabelaDeAutores[3] = Autor(4, (char*) "Jane Austen");
        tabelaDeAutores[4] = Autor(5, (char*) "George Orwell");
        tabelaDeAutores[5] = Autor(6, (char*) "Gabriel García Márquez");
        tabelaDeAutores[6] = Autor(7, (char*) "Franz Kafka");
        tabelaDeAutores[7] = Autor(8, (char*) "Virginia Woolf");
        tabelaDeAutores[8] = Autor(9, (char*) "Jorge Luis Borges");
        tabelaDeAutores[9] = Autor(10, (char*) "Leonardo Padura");
    }
};



#endif //AUTORREPOSITORY_H