//
// Created by Gabriel Isper on 14/05/25.
//

#ifndef AUTORREPOSITORY_H
#define AUTORREPOSITORY_H



class AutorRepository {
    Autor tabelaDeAutores[100];

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

public:

    AutorRepository() {populaVetor();}

    Autor getByID(int id)
    {
        return tabelaDeAutores[id];
    }
};



#endif //AUTORREPOSITORY_H