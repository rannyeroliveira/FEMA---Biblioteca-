//BIBLIOTECA.cpp

#include <iostream>
#include <string>
#include "service/AutorService.h"
#include "service/EditoraService.h"
#include "service/LivroService.h"
#include "service/EmprestimoService.h"

int main() {
    EmprestimoService emprestimoService;
    emprestimoService.emprestimo();
}
