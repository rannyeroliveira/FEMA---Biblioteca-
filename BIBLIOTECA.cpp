//BIBLIOTECA.cpp

#include <iostream>
#include <string>
#include "service/AutorService.h"
#include "service/EditoraService.h"
#include "service/LivroService.h"
#include "service/EmprestimoService.h"
#include "service/PessoaService.h"

int main() {
    PessoaService pessoaService;
    pessoaService.createPessoa();
}
