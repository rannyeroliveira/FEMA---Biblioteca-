//BIBLIOTECA.cpp

#include <iostream>
#include <string>
#include "service/AutorService.h"
#include "service/EditoraService.h"
#include "service/CidadeService.h"
#include "service/LivroService.h"
#include "service/EmprestimoService.h"


int main() {
    AutorService autorService;
    EditoraService editoraService;
    LivroService livroService;

    // service.getAllAutores();

    autorService.getByID(1);
}


int converteCharPraInt(char a)
{
    return a - 0;
}