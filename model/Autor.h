//
// Created by Gabriel Isper on 12/05/25.
//

#ifndef AUTOR_H
#define AUTOR_H

#include<string>
using namespace std;


class Autor {

    int idAutor;
    string nomeAutor;

public:
    Autor(int id, string nomeAutor)
    {
        this->idAutor = id;
        this->nomeAutor = nomeAutor;
    }

    int getId();
    void setId(int id);

    string getNomeAutor();
    void setNomeAutor(string nomeAutor);

};


inline int Autor::getId()
{
    return this->idAutor;
}

inline void Autor::setId(int id)
{
    this->idAutor = id;
}

inline string Autor::getNomeAutor()
{
    return this->nomeAutor;
}

inline void Autor::setNomeAutor(string nomeAutor)
{
    this->nomeAutor = nomeAutor;
}


#endif //AUTOR_H
