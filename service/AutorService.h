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
};

#endif // AUTOR_SERVICE_H
