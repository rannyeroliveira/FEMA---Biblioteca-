#ifndef LIVRO_H
#define LIVRO_H

#include <cstring>

using namespace std;

class Livro {
    int idLivro;
    char nomeLivro[100];
    int codigo_editora;
    int codigo_autor;
    int codigo_genero;
    bool disponivel;

public:
    Livro() {
        idLivro = 0;
        strcpy(this->nomeLivro, "");
        codigo_editora = 0;
        codigo_autor = 0;
        codigo_genero = 0;
        disponivel = true;
    }

    Livro(int id, const char nome[], int codEditora, int codAutor, int codGenero, bool disp) {
        this->idLivro = id;
        strcpy(this->nomeLivro, nome);
        this->codigo_editora = codEditora;
        this->codigo_autor = codAutor;
        this->codigo_genero = codGenero;
        this->disponivel = disp;
    }

    int getId() const { return idLivro; }
    void setId(int id) { idLivro = id; }

    const char* getNomeLivro() { return nomeLivro; }
    void setNomeLivro(const char nome[]) { strcpy(nomeLivro, nome); }

    int getCodigoEditora() const { return codigo_editora; }
    void setCodigoEditora(int cod) { codigo_editora = cod; }

    int getCodigoAutor() const { return codigo_autor; }
    void setCodigoAutor(int cod) { codigo_autor = cod; }

    int getCodigoGenero() const { return codigo_genero; }
    void setCodigoGenero(int cod) { codigo_genero = cod; }

    bool isDisponivel() const { return disponivel; }
    void setDisponivel(bool disp) { disponivel = disp; }
};

#endif // LIVRO_H