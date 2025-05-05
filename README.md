# FEMA---Biblioteca-
Implementação em C++ que simularão arquivos sequenciais para uma aplicação de Biblioteca.
Escreva um programa para criar as seguintes estruturas que simularão arquivos sequenciais para uma aplicação de Biblioteca:

Cidades: código (PK), descrição, UF

Pessoas: codigo (PK), nome, CPF, endereço, codigo_cidade

Editoras: codigo (PK), nome, codigo_cidade

Autores: codigo (PK), nome

Gêneros: codigo (PK), descrição

Livros: codigo (PK), nome, codigo_editora, codigo_autor, codigo_genero, disponível_s_n

Empréstimos: codigo (PK), codigo_pessoa, codigo_livro, data_empréstimo, data_prevista_devolução, data_efetiva_devolução

1) Escreva funções específicas para a leitura dos dados das estruturas.

2) Escreva uma função para permitir a inclusão de novos registros na tabela de pessoas. 
2.1) Quando o usuário digitar o CPF, o programa deverá realizar a validação do CPF.
2.2) Quando o usuário digitar o código da cidade, o programa deverá buscar este código na tabela de cidades e exibir a descrição e UF da cidade.

3) Escreva uma função para permitir a inclusão de novos registros na tabela de livros.
3.1) Quando o usuário digitar o código da editora, o programa deverá buscar este código na tabela de editoras e exibir o nome da editora.
3.2) Quando o usuário digitar o código do autor, o programa deverá buscar este código na tabela de autores e exibir o nome do autor.
3.3) Quando o usuário digitar o código do gênero, o programa deverá buscar este código na tabela de gêneros e exibir a descrição.

4) Escreva uma função para permitir que uma pessoa realize o empréstimo de um livro, cujas informações serão gravadas na tabela Empréstimos.
4.1) O código do empréstimo (PK) deverá ser gerado automaticamente e sequencialmente a partir do último registro cadastrado.
4.2) O usuário deverá informar o código da pessoa que está emprestando o livro e o programa deverá buscar este código na tabela de pessoas e exibir o nome da pessoa e o nome da sua cidade.
4.3) O usuário deverá informar o código do livro a ser emprestado e o programa deverá buscar este código na tabela de livros e exibir o nome do livro.
4.4) O programa deverá exibir o nome da editora e o nome do autor do livro.
4.5) O programa deverá verificar na tabela de livros se o livro está disponível para empréstimo (disponivel_s_n = "S"). 
4.5.1) SE o livro estiver disponível para empréstimo, o programa deverá: 
4.5.1.1) Gravar a data_empréstimo como a data do dia atual.
4.5.1.2) Gravar a data_prevista_devolução como sendo a data atual mais sete dias.
4.5.1.3) Gravar a informação da tabela de Livros disponivel_s_n = "N"

4.6) Se o livro não estiver disponível para empréstimo, então uma mensagem deverá ser mostrado ao usuário e o empréstimo não será realizado.

5) Escreva uma função para permitir que uma pessoa realize a devolução de um livro.
5.1) O usuário deverá informar o código do empréstimo do livro a ser devolvido e o programa deverá buscar este código na tabela de Empréstimos e exibir:
5.1.1) O nome da pessoa e o nome do livro.
5.1.2) O nome da editora e o nome do autor do livro.
5.1.3) A data do empréstimo e a data da efetiva devolução (que deverá ser a data do dia atual).
5.2) Se a data da efetiva devolução estiver em branco, então o livro ainda não foi devolvido e poderá ser devolvido neste momento.
5.2.1) Para confirmar a devolução, o programa deverá atualizar a data da efetiva devolução com a data atual e atualizar o atributo da tabela de Livros disponivel_s_n = "S".

6) Escreva uma função para mostrar todos os livros que estejam emprestados, verificando a tabela de Livros: disponível_s_n = "N". 
6.1) O programa deverá exibir: código do livro, nome do livro.
6.2) Ao final dessa função, mostrar a quantidade de livros emprestados e a quantidade de livros disponíveis para empréstimo.

7) Escreva uma função para mostrar os dados dos livros e das pessoas que estejam com a devolução em atraso (data_prevista_devolução < data atual).
7.1) O programa deverá exibir: código do livro, nome do livro, nome da editora, nome do autor, data prevista da devolução, quantidade de dias em atraso.


Todas as funções descritas acima deverão ser chamadas através de um menu de opções que será chamado a partir da função main().

Obs: não utilizar variáveis globais.
