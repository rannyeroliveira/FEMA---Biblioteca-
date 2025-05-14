#ifndef AUTOR_SERVICE_H
#define AUTOR_SERVICE_H

#include "../model/Autor.h"


class AutorService {
    Autor tabelaDeAutores[100];

public:
    AutorService() {}

    Autor createAutor(int id, char nomeAutor[]) {
        return Autor(id, nomeAutor);
    }
};

#endif // AUTOR_SERVICE_H
