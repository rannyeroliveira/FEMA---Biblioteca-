//
// Created by Gabriel Isper on 19/05/25.
//

#ifndef LIVROREPOSITORY_H
#define LIVROREPOSITORY_H

#include "../model/Livro.h"


class LivroRepository
{
public:
    int static const TAMANHO = 100;

    int getMaximoLivrosParaInserir()
    {
        return TAMANHO - getTamanhoAtual();
    }

    int getTamanhoAtual()
    {
        return this->tamanhoTabelaLivrosAtual;
    }

    Livro* getAll()
    {
        return tabelaDeLivros;
    }

    LivroRepository() {populaVetor();}

    Livro getByID(int id)
    {
        int i = 0;
        int a = buscaBinaria(i, tamanhoTabelaLivrosAtual, tabelaDeLivros, id);
        if(a >= 0)
        {
            return tabelaDeLivros[a];
        }

        cout << "Livro não encontrado! Retornando livro vazio.";
        return Livro();
    }

    bool existsByID(int id)
    {
        int i = 0;
        int p = buscaBinaria(i, tamanhoTabelaLivrosAtual, tabelaDeLivros, id);

        if(p >= 0)
        {
            return true;
        }

        return false;
    }

    void inserirLivros(Livro tabelaNovosLivros[], int tamanhoTabelaNovosLivros)
    {                  // Tabela novos livros = T

        int tamanhoTabelaGeradaAutores = tamanhoTabelaNovosLivros + tamanhoTabelaLivrosAtual;

        // A
        Livro tabelaGeradaAutores[tamanhoTabelaGeradaAutores];

        // s
        int contadorTabelaPrincipal = 0;

        // t
        int contadortabelaNovosLivros = 0;

        // a
        int contadorTabelaGerada = 0;

        while(contadorTabelaPrincipal < getTamanhoAtual() && contadortabelaNovosLivros < tamanhoTabelaGeradaAutores){
            if(tabelaDeLivros[contadorTabelaPrincipal].getId() < tabelaNovosLivros[contadortabelaNovosLivros].getId()){
                tabelaGeradaAutores[contadorTabelaGerada] = tabelaDeLivros[contadorTabelaPrincipal++];
            }else{
                tabelaGeradaAutores[contadorTabelaGerada] = tabelaNovosLivros[contadortabelaNovosLivros++];
            }
            contadorTabelaGerada++;
        }

        while(contadorTabelaPrincipal < getTamanhoAtual()){
            tabelaGeradaAutores[contadorTabelaGerada++] = tabelaDeLivros[contadorTabelaPrincipal++];
        }

        while(contadortabelaNovosLivros < tamanhoTabelaNovosLivros){
            tabelaGeradaAutores[contadorTabelaGerada++] = tabelaNovosLivros[contadortabelaNovosLivros++];
        }

        atualizaTabela(tabelaDeLivros, tabelaGeradaAutores, tamanhoTabelaGeradaAutores);
    }

    void updateLivro(int id, char nomeLivro[], int codigoEditora, int codigoAutor, int codigoGenero, bool disponivel)
    {
        int i = 0;

        int pos = buscaBinaria(i, tamanhoTabelaLivrosAtual, tabelaDeLivros, id);

        if(pos < 0)
        {
            cout << "O Livro com id " << id << " não existe na base de dados!";
            return;
        }

        tabelaDeLivros[pos] = Livro(id, nomeLivro, codigoEditora, codigoAutor, codigoGenero, disponivel);
        cout << "Livro atualizado com sucesso!" << endl;
    }
    
    void deleteByID (int tabelaLivrosRemovidos[], int tamanhoTabelaLivrosRemovidos){

        // Clientes S = tabelaDeLivros
        // T = IDs a remover
        // A = Tabela atualizada sem Autores que foram deletados

        // contA
        int tamanhoTabelaGeradaAutores = tamanhoTabelaLivrosAtual - tamanhoTabelaLivrosRemovidos;

        Livro tabelaGeradaAutores[tamanhoTabelaGeradaAutores];

        int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)

        for (;j < tamanhoTabelaLivrosRemovidos; i++){
            if (tabelaDeLivros[i].getId() != tabelaLivrosRemovidos[j]){
                tabelaGeradaAutores[k].setId(tabelaDeLivros[i].getId());
                tabelaGeradaAutores[k].setNomeLivro(tabelaDeLivros[i].getNomeLivro());
                tabelaGeradaAutores[k].setCodigoAutor(tabelaDeLivros[i].getCodigoAutor());
                tabelaGeradaAutores[k].setCodigoEditora(tabelaDeLivros[i].getCodigoEditora());
                tabelaGeradaAutores[k].setCodigoGenero(tabelaDeLivros[i].getCodigoGenero());
                tabelaGeradaAutores[k].setDisponivel(tabelaDeLivros[i].isDisponivel());
                k++;
            }
            else {
                j++;
            }
        }
        while (i < tamanhoTabelaLivrosAtual){
            tabelaGeradaAutores[k].setId(tabelaDeLivros[i].getId());
            tabelaGeradaAutores[k].setId(tabelaDeLivros[i].getId());
            tabelaGeradaAutores[k].setNomeLivro(tabelaDeLivros[i].getNomeLivro());
            tabelaGeradaAutores[k].setCodigoAutor(tabelaDeLivros[i].getCodigoAutor());
            tabelaGeradaAutores[k].setCodigoEditora(tabelaDeLivros[i].getCodigoEditora());
            tabelaGeradaAutores[k].setCodigoGenero(tabelaDeLivros[i].getCodigoGenero());
            tabelaGeradaAutores[k].setDisponivel(tabelaDeLivros[i].isDisponivel());
            i++;
            k++;
        }

        tamanhoTabelaLivrosAtual = k;
    }


private:
    int pos;
    int tamanhoTabelaLivrosAtual = 10;
    Livro tabelaDeLivros[TAMANHO];

    void atualizaTabela(Livro tabela1[], Livro tabela2[], int tam)
    {
        for (int i = 0; i < tam; ++i)
        {
            tabela1[i] = tabela2[i];
        }
    }

    int buscaBinaria(int i, int f, Livro a[], int idLivro)
    {
        int m;
        while (i <= f)
        {
            m = (i + f) / 2;
            if(a[m].getId() == idLivro)
            {
                return m;
            } else if(a[m].getId() < idLivro)
            {
                i = m + 1;
            } else f = m - 1;
        }

        return -1;
    }

    void populaVetor()
    {
        tabelaDeLivros[0] = Livro(1, (char*) "Dom Casmurro", 1, 1, 1, true);
        tabelaDeLivros[1] = Livro(2, (char*) "A Hora da Estrela", 2, 2, 2, false);
        tabelaDeLivros[2] = Livro(3, (char*) "Hamlet", 3, 3, 2, true);
        tabelaDeLivros[3] = Livro(4, (char*) "Orgulho e Preconceito", 4, 4, 1, true);
        tabelaDeLivros[4] = Livro(5, (char*) "1984", 5, 5, 3, false);
        tabelaDeLivros[5] = Livro(6, (char*) "Cem Anos de Solidão", 6, 6, 1, true);
        tabelaDeLivros[6] = Livro(7, (char*) "A Metamorfose", 7, 7, 4, true);
        tabelaDeLivros[7] = Livro(8, (char*) "Mrs. Dalloway", 8, 8, 2, false);
        tabelaDeLivros[8] = Livro(9, (char*) "Ficções", 9, 9, 5, true);
        tabelaDeLivros[9] = Livro(10, (char*) "O Homem que Amava os Cachorros", 10, 10, 5, true);

    }
};


#endif //LIVROREPOSITORY_H
