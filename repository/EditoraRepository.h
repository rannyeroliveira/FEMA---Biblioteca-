#ifndef EDITORAREPOSITORY_H
#define EDITORAREPOSITORY_H

#include "../model/Editora.h"



class EditoraRepository
{
public:
    int static const TAMANHO = 100;

    int getTamanhoAtual()
    {
        return this->tamanhoTabelaEditorasAtual;
    }
    int getMaximoEditorasParaInserir()
    {
        return TAMANHO - getTamanhoAtual();
    }
    Editora* getAll()
    {
        return tabelaDeEditoras;
    }

    EditoraRepository() {populaVetor();}

    Editora getByID(int id)
    {
        int i = 0;
        int a = buscaBinaria(i, tamanhoTabelaEditorasAtual, tabelaDeEditoras, id);
        if(a >= 0)
        {
            return tabelaDeEditoras[a];
        }

        cout << "Editora não encontrada! Retornando editora vazia.";
        return Editora();
    }

    bool existsByID(int id)
    {
        int i = 0;
        int p = buscaBinaria(i, tamanhoTabelaEditorasAtual, tabelaDeEditoras, id);

        if(p >= 0)
        {
            return true;
        }

        return false;
    }

    void inserirEditoras(Editora tabelaNovasEditoras[], int tamanhoTabelaNovasEditoras)
    {                  // Tabela novas editoras = T

        int tamanhotabelaGeradaEditora = tamanhoTabelaNovasEditoras + tamanhoTabelaEditorasAtual;

        // A
        Editora tabelaGeradaEditoras[tamanhotabelaGeradaEditora];

        // s
        int contadorTabelaPrincipal = 0;

        // t
        int contadortabelaNovasEditoras = 0;

        // a
        int contadorTabelaGerada = 0;

        while(contadorTabelaPrincipal < getTamanhoAtual() && contadortabelaNovasEditoras < tamanhotabelaGeradaEditora){
            if(tabelaDeEditoras[contadorTabelaPrincipal].getId() < tabelaNovasEditoras[contadortabelaNovasEditoras].getId()){
                tabelaGeradaEditoras[contadorTabelaGerada] = tabelaDeEditoras[contadorTabelaPrincipal++];
            }else{
                tabelaGeradaEditoras[contadorTabelaGerada] = tabelaNovasEditoras[contadortabelaNovasEditoras++];
            }
            contadorTabelaGerada++;
        }

        while(contadorTabelaPrincipal < getTamanhoAtual()){
            tabelaGeradaEditoras[contadorTabelaGerada++] = tabelaDeEditoras[contadorTabelaPrincipal++];
        }

        while(contadortabelaNovasEditoras < tamanhoTabelaNovasEditoras){
            tabelaGeradaEditoras[contadorTabelaGerada++] = tabelaNovasEditoras[contadortabelaNovasEditoras++];
        }

        atualizaTabela(tabelaDeEditoras, tabelaGeradaEditoras, tamanhotabelaGeradaEditora);
    }

    void updateEditora(int id, char nomeEditora[], int idCidade)
    {
        int i = 0;

        int pos = buscaBinaria(i, tamanhoTabelaEditorasAtual, tabelaDeEditoras, id);

        if(pos < 0)
        {
            cout << "A Editora com id " << id << " não existe na base de dados!";
            return;
        }

        tabelaDeEditoras[pos] = Editora(id, nomeEditora, idCidade);
        cout << "Editora atualizado com sucesso!" << endl;
    }


    void deleteByID (int TabelaEditorasRemovidas[], int tamanhoTabelaEditorasRemovidas){

        // Clientes S = tabelaDeEditoras
        // T = IDs a remover
        // A = Tabela atualizada sem Editoras que foram deletadas

        // contA
        int tamanhoTabelaGeradaEditora = tamanhoTabelaEditorasAtual - tamanhoTabelaEditorasRemovidas;

        Editora tabelaGeradaEditora[tamanhoTabelaGeradaEditora];

        int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)

        for (;j < tamanhoTabelaEditorasRemovidas; i++){
            if (tabelaDeEditoras[i].getId() != TabelaEditorasRemovidas[j]){
                tabelaGeradaEditora[k].setId(tabelaDeEditoras[i].getId());
                tabelaGeradaEditora[k].setCodigoCidade(tabelaDeEditoras[i].getCodigoCidade());
                tabelaGeradaEditora[k].setNomeEdtr(tabelaDeEditoras[i].getNomeEdtr());
                k++;
            }
            else {
                j++;
            }
        }

        while (i < tamanhoTabelaEditorasAtual){
            tabelaGeradaEditora[k].setId(tabelaDeEditoras[i].getId());
            tabelaGeradaEditora[k].setCodigoCidade(tabelaDeEditoras[i].getCodigoCidade());
            tabelaGeradaEditora[k].setNomeEdtr(tabelaDeEditoras[i].getNomeEdtr());
            i++;
            k++;
        }

        tamanhoTabelaEditorasAtual = k;
    }




private:
    int pos;
    int tamanhoTabelaEditorasAtual = 10;
    Editora tabelaDeEditoras[TAMANHO];

    void atualizaTabela(Editora tabela1[], Editora tabela2[], int tam)
    {
        for (int i = 0; i < tam; ++i)
        {
            tabela1[i] = tabela2[i];
        }
    }

    int buscaBinaria(int i, int f, Editora a[], int idEditora)
    {
        int m;
        while (i <= f)
        {
            m = (i + f) / 2;
            if(a[m].getId() == idEditora)
            {
                return m;
            } else if(a[m].getId() < idEditora)
            {
                i = m + 1;
            } else f = m - 1;
        }

        return -1;
    }

    void populaVetor()
    {
        tabelaDeEditoras[0] = Editora(1, (char*) "Companhia das Letras", 101);
        tabelaDeEditoras[1] = Editora(2, (char*) "Editora Record", 102);
        tabelaDeEditoras[2] = Editora(3, (char*) "HarperCollins Brasil", 103);
        tabelaDeEditoras[3] = Editora(4, (char*) "Intrínseca", 104);
        tabelaDeEditoras[4] = Editora(5, (char*) "Editora Rocco", 105);
        tabelaDeEditoras[5] = Editora(6, (char*) "Objetiva", 106);
        tabelaDeEditoras[6] = Editora(7, (char*) "Saraiva", 107);
        tabelaDeEditoras[7] = Editora(8, (char*) "Globo Livros", 108);
        tabelaDeEditoras[8] = Editora(9, (char*) "Editora Abril", 109);
        tabelaDeEditoras[9] = Editora(10, (char*) "Editora Melhoramentos", 110);
    }
};



#endif //EDITORAREPOSITORY_H
