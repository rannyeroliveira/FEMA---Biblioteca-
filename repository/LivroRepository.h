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

    Livro* getAllExistente()
    {
        Livro tabelaLivros[getTamanhoAtual()];
        for (int i = 0; i < getTamanhoAtual(); ++i)
        {
            tabelaLivros[i] = tabelaDeLivros[i];
        }

        return tabelaLivros;
    }

    Livro* getAllExistente(Livro l[])
    {
        for (int i = 0; i < getTamanhoAtual(); ++i)
        {
            l[i] = tabelaDeLivros[i];
        }
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

    bool isDisponivel(int id)
    {
        return this->getByID(id).isDisponivel();
    }
    void ordenaIdLivroParaInserir(Livro tabelaNovosLivros[], int tamanhoTabelaNovosLivros) {
        for (int i = 0; i < tamanhoTabelaNovosLivros - 1; ++i) {
            for (int j = 0; j < tamanhoTabelaNovosLivros - i - 1; ++j) {
                if (tabelaNovosLivros[j].getId() > tabelaNovosLivros[j + 1].getId()) {
                    Livro temp = tabelaNovosLivros[j];
                    tabelaNovosLivros[j] = tabelaNovosLivros[j + 1];
                    tabelaNovosLivros[j + 1] = temp;
                }
            }
        }
    }
    void inserirLivros(Livro tabelaNovosLivros[], int tamanhoTabelaNovosLivros)
    {                  
        ordenaIdLivroParaInserir(tabelaNovosLivros, tamanhoTabelaNovosLivros);
        int tamanhoTabelaGeradaLivros = tamanhoTabelaNovosLivros + tamanhoTabelaLivrosAtual;
        
        Livro tabelaGeradaLivros[tamanhoTabelaGeradaLivros];
        
        int contadorTabelaPrincipal = 0;
        
        int contadortabelaNovosLivros = 0;
        
        int contadorTabelaGerada = 0;

        while(contadorTabelaPrincipal < getTamanhoAtual() && contadortabelaNovosLivros < tamanhoTabelaGeradaLivros){
            if(tabelaDeLivros[contadorTabelaPrincipal].getId() < tabelaNovosLivros[contadortabelaNovosLivros].getId()){
                tabelaGeradaLivros[contadorTabelaGerada] = tabelaDeLivros[contadorTabelaPrincipal++];
            }else{
                tabelaGeradaLivros[contadorTabelaGerada] = tabelaNovosLivros[contadortabelaNovosLivros++];
            }
            contadorTabelaGerada++;
        }

        while(contadorTabelaPrincipal < getTamanhoAtual()){
            tabelaGeradaLivros[contadorTabelaGerada++] = tabelaDeLivros[contadorTabelaPrincipal++];
        }

        while(contadortabelaNovosLivros < tamanhoTabelaNovosLivros){
            tabelaGeradaLivros[contadorTabelaGerada++] = tabelaNovosLivros[contadortabelaNovosLivros++];
        }

        atualizaTabela(tabelaDeLivros, tabelaGeradaLivros, tamanhoTabelaGeradaLivros);
    }

    void updateLivro(Livro livro)
    {
        int i = 0;

        int pos = buscaBinaria(i, tamanhoTabelaLivrosAtual, tabelaDeLivros, livro.getId());

        if(pos < 0)
        {
            cout << "O Livro com id " << livro.getId() << " não existe na base de dados!";
            return;
        }

        tabelaDeLivros[pos] = livro;
        cout << "Livro atualizado com sucesso!" << endl;
    }
    
    void deleteByID (int tabelaLivrosRemovidos[], int tamanhoTabelaLivrosRemovidos){

        int tamanhoTabelaGeradaLivros = tamanhoTabelaLivrosAtual - tamanhoTabelaLivrosRemovidos;

        Livro tabelaGeradaLivros[tamanhoTabelaGeradaLivros];

        int i = 0, j = 0, k = 0;

        for (;j < tamanhoTabelaLivrosRemovidos; i++){
            if (tabelaDeLivros[i].getId() != tabelaLivrosRemovidos[j]){
                tabelaGeradaLivros[k].setId(tabelaDeLivros[i].getId());
                tabelaGeradaLivros[k].setNomeLivro(tabelaDeLivros[i].getNomeLivro());
                tabelaGeradaLivros[k].setCodigoAutor(tabelaDeLivros[i].getCodigoAutor());
                tabelaGeradaLivros[k].setCodigoEditora(tabelaDeLivros[i].getCodigoEditora());
                tabelaGeradaLivros[k].setCodigoGenero(tabelaDeLivros[i].getCodigoGenero());
                tabelaGeradaLivros[k].setDisponivel(tabelaDeLivros[i].isDisponivel());
                k++;
            }
            else {
                j++;
            }
        }
        while (i < tamanhoTabelaLivrosAtual){
            tabelaGeradaLivros[k].setId(tabelaDeLivros[i].getId());
            tabelaGeradaLivros[k].setId(tabelaDeLivros[i].getId());
            tabelaGeradaLivros[k].setNomeLivro(tabelaDeLivros[i].getNomeLivro());
            tabelaGeradaLivros[k].setCodigoAutor(tabelaDeLivros[i].getCodigoAutor());
            tabelaGeradaLivros[k].setCodigoEditora(tabelaDeLivros[i].getCodigoEditora());
            tabelaGeradaLivros[k].setCodigoGenero(tabelaDeLivros[i].getCodigoGenero());
            tabelaGeradaLivros[k].setDisponivel(tabelaDeLivros[i].isDisponivel());
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
