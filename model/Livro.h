//
// Created by Gabriel Isper on 12/05/25.
//

#ifndef LIVRO_H
#define LIVRO_H


#include <string>
using namespace std;

class Livro {
private:
    int idLivro;
    string nomeLivro;
    int codigo_editora;
    int codigo_autor;
    int codigo_genero;
    bool disponivel;

public:
    Livro(int id, const string& nome, int codEditora, int codAutor, int codGenero, bool disp) {
        idLivro = id;
        nomeLivro = nome;
        codigo_editora = codEditora;
        codigo_autor = codAutor;
        codigo_genero = codGenero;
        disponivel = disp;
    }

    int getIdLivro() const {
        return idLivro;
    }

    string getNomeLivro() const {
        return nomeLivro;
    }

    int getCodigoEditora() const {
        return codigo_editora;
    }

    int getCodigoAutor() const {
        return codigo_autor;
    }

    int getCodigoGenero() const {
        return codigo_genero;
    }

    bool isDisponivel() const {
        return disponivel;
    }

    void setIdLivro(int id) {
        idLivro = id;
    }

    void setNomeLivro(const string& nome) {
        nomeLivro = nome;
    }

    void setCodigoEditora(int codEditora) {
        codigo_editora = codEditora;
    }

    void setCodigoAutor(int codAutor) {
        codigo_autor = codAutor;
    }

    void setCodigoGenero(int codGenero) {
        codigo_genero = codGenero;
    }

    void setDisponivel(bool disp) {
        disponivel = disp;
    }
};



#endif //LIVRO_H
