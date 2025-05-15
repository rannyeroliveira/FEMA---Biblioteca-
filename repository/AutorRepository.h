//
// Created by Gabriel Isper on 14/05/25.
//

#ifndef AUTORREPOSITORY_H
#define AUTORREPOSITORY_H



class AutorRepository {

public:
    int static const TAMANHO = 100;

    int getTamanhoAtual()
    {
        return this->tamanhoTabelaAutoresAtual;
    }

    AutorRepository() {populaVetor();}

    Autor getByID(int id)
    {
        return tabelaDeAutores[id];
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


//
//
// void insercao(Autor arquivo1[], Autor arquivo2[], int S, int T, int A, struct Autor arquivo3[])
// {
//     int a = 0;
//     int s = 0;
//     int t = 0;
//     while(s<S && t<T){
//         if(arquivo1[s].getId() < arquivo2[t].getId()){
//             arquivo3[a] = arquivo1[s];
//             s++;
//         }else{
//             arquivo3[a] = arquivo2[t];
//             t++;
//         }
//         a++;
//     }
//
//     while(s < S){
//         arquivo3[a++] = arquivo1[s++];
//     }
//
//     while(t < T){
//         arquivo3[a++] = arquivo2[t++];
//     }
// }

//
// void inclusao (Autor S[], int contS, Autor T[], int contT, Autor A[], int &contA)
// {
//     int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
//     for (;i < contS && j < contT;k++){
//         if (S[i].codigo < T[j].codigo){
//             A[k].codigo = S[i].codigo;
//             strcpy (A[k].nome,S[i].nome);
//             strcpy (A[k].endereco,S[i].endereco);
//             strcpy (A[k].cidade,S[i].cidade);
//             strcpy (A[k].uf,S[i].uf);
//             i++;
//         }
//         else {
//             A[k].codigo = T[j].codigo;
//             strcpy (A[k].nome,T[j].nome);
//             strcpy (A[k].endereco,T[j].endereco);
//             strcpy (A[k].cidade,T[j].cidade);
//             strcpy (A[k].uf,T[j].uf);
//             j++;
//         }
//     }
// }
//
// void mostrar (struct clientes A[], int contA){
//     cout << "\n\nLista dos Registros no Arquivo Atualizado" << endl;
//     for (int i = 0; i < contA; i++){
//         cout << "\nCodigo: " << A[i].codigo;
//         cout << "\tNome: " << A[i].nome;
//         cout << "\tEndereco: " << A[i].endereco;
//         cout << "\tCidade: " << A[i].cidade;
//         cout << "\tUF: " << A[i].uf;
//     }
// }



#endif //AUTORREPOSITORY_H