#ifndef CIDADEREPOSITORY_H
#define CIDADEREPOSITORY_H

#include "../model/Cidade.h"


class CidadeRepository
{
public:
    int static const TAMANHO = 100;

    int getTamanhoAtual()
    {
        return this->tamanhoTabelaCidadesAtual;
    }
    int getMaximoCidadesParaInserir()
    {
        return TAMANHO - getTamanhoAtual();
    }
    Cidade* getAll()
    {
        return tabelaDeCidades;
    }

    CidadeRepository() {populaVetor();}

    Cidade getByID(int id)
    {
        int i = 0;
        int a = buscaBinaria(i, tamanhoTabelaCidadesAtual, tabelaDeCidades, id);
        if(a >= 0)
        {
            return tabelaDeCidades[a];
        }

        cout << "Cidade não encontrada! Retornando cidade vazia.";
        return Cidade();
    }

    bool existsByID(int id)
    {
        int i = 0;
        int p = buscaBinaria(i, tamanhoTabelaCidadesAtual, tabelaDeCidades, id);

        if(p >= 0)
        {
            return true;
        }

        return false;
    }
    void ordenaIdCidadeParaInserir(Cidade tabelaNovasCidades[], int tamanhoTabelaNovasCidades) {
        for (int i = 0; i < tamanhoTabelaNovasCidades - 1; ++i) {
            for (int j = 0; j < tamanhoTabelaNovasCidades - i - 1; ++j) {
                if (tabelaNovasCidades[j].getId() > tabelaNovasCidades[j + 1].getId()) {
                    Cidade temp = tabelaNovasCidades[j];
                    tabelaNovasCidades[j] = tabelaNovasCidades[j + 1];
                    tabelaNovasCidades[j + 1] = temp;
                }
            }
        }
    }

    void inserirCidades(Cidade tabelaNovasCidades[], int tamanhoTabelaNovasCidades)
    {                  
        ordenaIdCidadeParaInserir(tabelaNovasCidades, tamanhoTabelaNovasCidades);
        int tamanhoTabelaGeradaCidades = tamanhoTabelaNovasCidades + tamanhoTabelaCidadesAtual;
        
        Cidade tabelaGeradaCidades[tamanhoTabelaGeradaCidades];
        
        int contadorTabelaPrincipal = 0;
        
        int contadorTabelaNovasCidades = 0;
        
        int contadorTabelaGerada = 0;

        while(contadorTabelaPrincipal < getTamanhoAtual() && contadorTabelaNovasCidades < tamanhoTabelaGeradaCidades){
            if(tabelaDeCidades[contadorTabelaPrincipal].getId() < tabelaNovasCidades[contadorTabelaNovasCidades].getId()){
                tabelaGeradaCidades[contadorTabelaGerada] = tabelaDeCidades[contadorTabelaPrincipal++];
            }else{
                tabelaGeradaCidades[contadorTabelaGerada] = tabelaNovasCidades[contadorTabelaNovasCidades++];
            }
            contadorTabelaGerada++;
        }

        while(contadorTabelaPrincipal < getTamanhoAtual()){
            tabelaGeradaCidades[contadorTabelaGerada++] = tabelaDeCidades[contadorTabelaPrincipal++];
        }

        while(contadorTabelaNovasCidades < tamanhoTabelaNovasCidades){
            tabelaGeradaCidades[contadorTabelaGerada++] = tabelaNovasCidades[contadorTabelaNovasCidades++];
        }

        atualizaTabela(tabelaDeCidades, tabelaGeradaCidades, tamanhoTabelaGeradaCidades);
    }
    
    void updateCidade(int id, char nomeCidade[], char UF[])
    {
        int i = 0;

        int pos = buscaBinaria(i, tamanhoTabelaCidadesAtual, tabelaDeCidades, id);

        if(pos < 0)
        {
            cout << "A cidade com id " << id << " não existe na base de dados!";
            return;
        }

        tabelaDeCidades[pos] = Cidade(id, nomeCidade, UF);
        cout << "Cidade atualizada com sucesso!" << endl;
    }
    
    void deleteByID (int tabelaCidadesRemovidas[], int tamanhoTabelaCidadesRemovidas){
        int tamanhoTabelaGeradaCidades = tamanhoTabelaCidadesAtual - tamanhoTabelaCidadesRemovidas;

        Cidade tabelaGeradaCidades[tamanhoTabelaGeradaCidades];

        int i = 0, j = 0, k = 0;

        for (;j < tamanhoTabelaCidadesRemovidas; i++){
            if (tabelaDeCidades[i].getId() != tabelaCidadesRemovidas[j]){
                tabelaGeradaCidades[k].setId(tabelaDeCidades[i].getId());
                tabelaGeradaCidades[k].setDescricao(tabelaDeCidades[i].getDescricao());
                tabelaGeradaCidades[k].setUF(tabelaDeCidades[i].getUF());
                k++;
            }
            else {
                j++;
            }
        }
        while (i < tamanhoTabelaCidadesAtual){
            tabelaGeradaCidades[k].setId(tabelaDeCidades[i].getId());
            tabelaGeradaCidades[k].setDescricao(tabelaDeCidades[i].getDescricao());
            tabelaGeradaCidades[k].setUF(tabelaDeCidades[i].getUF());
            i++;
            k++;
        }

        tamanhoTabelaCidadesAtual = k;
    }


private:
    int pos;
    int tamanhoTabelaCidadesAtual = 10;
    Cidade tabelaDeCidades[TAMANHO];

    void atualizaTabela(Cidade tabela1[], Cidade tabela2[], int tam)
    {
        for (int i = 0; i < tam; ++i)
        {
            tabela1[i] = tabela2[i];
        }
    }

    int buscaBinaria(int i, int f, Cidade a[], int idCidade)
    {
        int m;
        while (i <= f)
        {
            m = (i + f) / 2;
            if(a[m].getId() == idCidade)
            {
                return m;
            } else if(a[m].getId() < idCidade)
            {
                i = m + 1;
            } else f = m - 1;
        }

        return -1;
    }

    void populaVetor()
    {
        tabelaDeCidades[0] = Cidade(101, (char*) "São Paulo", "SP");
        tabelaDeCidades[1] = Cidade(102, (char*) "Rio de Janeiro", "RJ");
        tabelaDeCidades[2] = Cidade(103, (char*) "Belo Horizonte", "MG");
        tabelaDeCidades[3] = Cidade(104, (char*) "Curitiba", "PR");
        tabelaDeCidades[4] = Cidade(105, (char*) "Porto Alegre", "RS");
        tabelaDeCidades[5] = Cidade(106, (char*) "Salvador", "BA");
        tabelaDeCidades[6] = Cidade(107, (char*) "Recife", "PE");
        tabelaDeCidades[7] = Cidade(108, (char*) "Florianópolis", "SC");
        tabelaDeCidades[8] = Cidade(109, (char*) "Brasília", "DF");
        tabelaDeCidades[9] = Cidade(110, (char*) "Fortaleza", "CE");
    }
};



#endif //CIDADEREPOSITORY_H
