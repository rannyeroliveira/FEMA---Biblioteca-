//
// Created by Gabriel Isper on 19/05/25.
//

#ifndef EMPRESTIMOREPOSITORY_H
#define EMPRESTIMOREPOSITORY_H

#include "../model/Emprestimo.h"


class EmprestimoRepository
{
public:
    int static const TAMANHO = 100;

    int getMaximoEmprestimosParaInserir()
    {
        return TAMANHO - getTamanhoAtual();
    }

    int getTamanhoAtual()
    {
        return this->tamanhoTabelaEmprestimosAtual;
    }

    Emprestimo* getAll()
    {
        return tabelaDeEmprestimos;
    }

    EmprestimoRepository() {populaVetor();}

    Emprestimo getByID(int id)
    {
        int i = 0;
        int a = buscaBinaria(i, tamanhoTabelaEmprestimosAtual, tabelaDeEmprestimos, id);
        if(a >= 0)
        {
            return tabelaDeEmprestimos[a];
        }

        cout << "Empréstimo não encontrado! Retornando empréstimo vazio.";
        return Emprestimo();
    }

    bool existsByID(int id)
    {
        int i = 0;
        int p = buscaBinaria(i, tamanhoTabelaEmprestimosAtual, tabelaDeEmprestimos, id);

        if(p >= 0)
        {
            return true;
        }

        return false;
    }

    void inserirEmprestimos(Emprestimo tabelaNovosEmprestimos[], int tamanhoTabelaNovosEmprestimos)
    {
        int tamanhoTabelaGeradaEmprestimos = tamanhoTabelaNovosEmprestimos + tamanhoTabelaEmprestimosAtual;

        Emprestimo tabelaGeradaEmprestimos[tamanhoTabelaGeradaEmprestimos];

        int contadorTabelaPrincipal = 0;
        int contadorTabelaNovosEmprestimos = 0;
        int contadorTabelaGerada = 0;

        while(contadorTabelaPrincipal < getTamanhoAtual() && contadorTabelaNovosEmprestimos < tamanhoTabelaGeradaEmprestimos){
            if(tabelaDeEmprestimos[contadorTabelaPrincipal].getId() < tabelaNovosEmprestimos[contadorTabelaNovosEmprestimos].getId()){
                tabelaGeradaEmprestimos[contadorTabelaGerada] = tabelaDeEmprestimos[contadorTabelaPrincipal++];
            }else{
                tabelaGeradaEmprestimos[contadorTabelaGerada] = tabelaNovosEmprestimos[contadorTabelaNovosEmprestimos++];
            }
            contadorTabelaGerada++;
        }

        while(contadorTabelaPrincipal < getTamanhoAtual()){
            tabelaGeradaEmprestimos[contadorTabelaGerada++] = tabelaDeEmprestimos[contadorTabelaPrincipal++];
        }

        while(contadorTabelaNovosEmprestimos < tamanhoTabelaNovosEmprestimos){
            tabelaGeradaEmprestimos[contadorTabelaGerada++] = tabelaNovosEmprestimos[contadorTabelaNovosEmprestimos++];
        }

        atualizaTabela(tabelaDeEmprestimos, tabelaGeradaEmprestimos, tamanhoTabelaGeradaEmprestimos);
    }

    void updateEmprestimo(int id, int codPessoa, int codLivro, const char dataEmp[], const char dataPrev[], const char dataEfetiva[])
    {
        int i = 0;

        int pos = buscaBinaria(i, tamanhoTabelaEmprestimosAtual, tabelaDeEmprestimos, id);

        if(pos < 0)
        {
            cout << "O Empréstimo com id " << id << " não existe na base de dados!";
            return;
        }

        tabelaDeEmprestimos[pos] = Emprestimo(id, codPessoa, codLivro, dataEmp, dataPrev, dataEfetiva);
        cout << "Empréstimo atualizado com sucesso!" << endl;
    }

    void deleteByID (int TabelaEmprestimosRemovidos[], int tamanhoTabelaEmprestimosRemovidos){

        int tamanhoTabelaGeradaEmprestimos = tamanhoTabelaEmprestimosAtual - tamanhoTabelaEmprestimosRemovidos;

        Emprestimo tabelaGeradaEmprestimos[tamanhoTabelaGeradaEmprestimos];

        int i = 0, j = 0, k = 0;

        for (;j < tamanhoTabelaEmprestimosRemovidos; i++){
            if (tabelaDeEmprestimos[i].getId() != TabelaEmprestimosRemovidos[j]){
                tabelaGeradaEmprestimos[k].setId(tabelaDeEmprestimos[i].getId());
                tabelaGeradaEmprestimos[k].setCodigoPessoa(tabelaDeEmprestimos[i].getCodigoPessoa());
                tabelaGeradaEmprestimos[k].setCodigoLivro(tabelaDeEmprestimos[i].getCodigoLivro());
                tabelaGeradaEmprestimos[k].setDataEmprestimo(tabelaDeEmprestimos[i].getDataEmprestimo());
                tabelaGeradaEmprestimos[k].setDataPrevistaDevolucao(tabelaDeEmprestimos[i].getDataPrevistaDevolucao());
                tabelaGeradaEmprestimos[k].setDataEfetivaDevolucao(tabelaDeEmprestimos[i].getDataEfetivaDevolucao());
                k++;
            }
            else {
                j++;
            }
        }
        while (i < tamanhoTabelaEmprestimosAtual){
            tabelaGeradaEmprestimos[k].setId(tabelaDeEmprestimos[i].getId());
            tabelaGeradaEmprestimos[k].setCodigoPessoa(tabelaDeEmprestimos[i].getCodigoPessoa());
            tabelaGeradaEmprestimos[k].setCodigoLivro(tabelaDeEmprestimos[i].getCodigoLivro());
            tabelaGeradaEmprestimos[k].setDataEmprestimo(tabelaDeEmprestimos[i].getDataEmprestimo());
            tabelaGeradaEmprestimos[k].setDataPrevistaDevolucao(tabelaDeEmprestimos[i].getDataPrevistaDevolucao());
            tabelaGeradaEmprestimos[k].setDataEfetivaDevolucao(tabelaDeEmprestimos[i].getDataEfetivaDevolucao());
            i++;
            k++;
        }

        tamanhoTabelaEmprestimosAtual = k;
    }

private:
    int pos;
    int tamanhoTabelaEmprestimosAtual = 10;
    Emprestimo tabelaDeEmprestimos[TAMANHO];

    void atualizaTabela(Emprestimo tabela1[], Emprestimo tabela2[], int tam)
    {
        for (int i = 0; i < tam; ++i)
        {
            tabela1[i] = tabela2[i];
        }
    }

    int buscaBinaria(int i, int f, Emprestimo a[], int idEmprestimo)
    {
        int m;
        while (i <= f)
        {
            m = (i + f) / 2;
            if(a[m].getId() == idEmprestimo)
            {
                return m;
            } else if(a[m].getId() < idEmprestimo)
            {
                i = m + 1;
            } else f = m - 1;
        }

        return -1;
    }

    void populaVetor()
    {
        tabelaDeEmprestimos[0] = Emprestimo(1, 1001, 2001, "01/01/2025", "15/01/2025", "");
        tabelaDeEmprestimos[1] = Emprestimo(2, 1002, 2002, "02/01/2025", "16/01/2025", "");
        tabelaDeEmprestimos[2] = Emprestimo(3, 1003, 2003, "03/01/2025", "17/01/2025", "");
        tabelaDeEmprestimos[3] = Emprestimo(4, 1004, 2004, "04/01/2025", "18/01/2025", "");
        tabelaDeEmprestimos[4] = Emprestimo(5, 1005, 2005, "05/01/2025", "19/01/2025", "");
        tabelaDeEmprestimos[5] = Emprestimo(6, 1006, 2006, "06/01/2025", "20/01/2025", "");
        tabelaDeEmprestimos[6] = Emprestimo(7, 1007, 2007, "07/01/2025", "21/01/2025", "");
        tabelaDeEmprestimos[7] = Emprestimo(8, 1008, 2008, "08/01/2025", "22/01/2025", "");
        tabelaDeEmprestimos[8] = Emprestimo(9, 1009, 2009, "09/01/2025", "23/01/2025", "");
        tabelaDeEmprestimos[9] = Emprestimo(10, 1010, 2010, "10/01/2025", "24/01/2025", "");
    }
};

#endif // EMPRESTIMOREPOSITORY_H
