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

    void createAutor()
    {
        int id;
        char nome[100];

        cout << "Digite o ID: " << endl;
        cin >> id;

        cout << "Digite o nome: " << endl;
        cin.ignore();
        gets(nome);

        if(autorRepository.existsByID(id))
        {
            cout << "Usuario ja existente no banco!!";
        } else autorRepository.save(Autor(id, nome));
    }
};

#endif // AUTOR_SERVICE_H
