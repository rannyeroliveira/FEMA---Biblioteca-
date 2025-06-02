#ifndef PESSOA_SERVICE_H
#define PESSOA_SERVICE_H

#include "../model/Pessoa.h"
#include "../repository/PessoaRepository.h"
#include "../model/CPF.h"
#include "../repository/CidadeRepository.h"

#include <clocale>

class PessoaService {

    PessoaRepository pessoaRepository;
    CidadeRepository cidadeRepository;

    void imprimirPessoas(Pessoa pessoas[], int t) {
        for (int i = 0; i < t; ++i) {
            cout << "ID: " << pessoas[i].getId() << endl;
            cout << "Nome: " << pessoas[i].getNomePessoa() << endl;
            cout << "CPF: " << pessoas[i].getCpf() << endl;
            cout << "Endereço: " << pessoas[i].getEndereco() << endl;
            cout << "Código da Cidade: " << pessoas[i].getCodigoCidade() << endl;
            cout << endl;
        }
    }

    void imprimirPessoa(int id) {
        Pessoa p = pessoaRepository.getByID(id);
        if (p.getNomePessoa()[0] != '\0') {
            cout << "ID: " << p.getId() << endl;
            cout << "Nome: " << p.getNomePessoa() << endl;
            cout << "CPF: " << p.getCpf() << endl;
            cout << "Endereço: " << p.getEndereco() << endl;
            cout << "Código da Cidade: " << p.getCodigoCidade() << endl;
            cout << endl;
        }
    }

    bool isIdRepetido(Pessoa* pessoa, int id, int cont)
    {

        int i = 0;

        do
        {
            if(pessoa[i].getId() == id) {
                return true;
            }

            i++;
        } while (i < cont);

        return false;
    }

public:
    PessoaService() {}

    Pessoa createPessoa(int id, char nome[], char cpf[], char endereco[], int codCidade) {
        return Pessoa(id, nome, cpf, endereco, codCidade);
    }

    void createPessoa() {
        setlocale(LC_ALL, "pt_BR.UTF-8");
        int totalPessoasInserir;

        cout << "Digite quantas pessoas deseja cadastrar: ";
        cin >> totalPessoasInserir;

        if (totalPessoasInserir > pessoaRepository.getMaximoPessoasParaInserir()) {
            while (totalPessoasInserir > pessoaRepository.getMaximoPessoasParaInserir()) {
                cout << "Tamanho máximo de memória do banco excedido! \nDigite outra quantidade: ";
                cin >> totalPessoasInserir;
            }
        }

        Pessoa tabelaNovasPessoas[totalPessoasInserir];
        int contPessoasInseridas = 0;

        for (int i = 0; i < totalPessoasInserir; ++i) {
            int id, codCidade;
            char nome[100];
            char cpf[20];
            char endereco[100];

            cout << "Digite o ID: ";
            cin >> id;

            if (pessoaRepository.existsByID(id) || isIdRepetido(tabelaNovasPessoas, id, contPessoasInseridas)) {
                do {
                    cout << "ID " << id << " já utilizado. Digite um novo id: ";
                    cin >> id;
                } while (pessoaRepository.existsByID(id));
            }


            cout << "Digite o nome: ";
            cin.ignore();
            gets(nome);

            cout << "Digite o CPF: ";
            cin >> cpf;
            while (!CPF().validaCPF(cpf)) {
                cout << "CPF INVALIDO. DIGITE NOVAMENTE: ";
                cin >> cpf;
            }

            cout << "Digite o endereco:";
            cin.ignore();
            gets(endereco);


            bool cidadeValida = false;

            do {
                cout << "Digite o codigo da cidade: ";
                cin >> codCidade;

                if (cidadeRepository.existsByID(codCidade)) {
                    Cidade cidadeSelecionada = cidadeRepository.getByID(codCidade);
                    cout << "Cidade encontrada: " << cidadeSelecionada.getDescricao()
                         << " - " << cidadeSelecionada.getUF() << endl;

                    char confirma;
                    cout << "Confirma essa cidade? (S/N): ";
                    cin >> confirma;

                    if (confirma == 'S' || confirma == 's') {
                        cidadeValida = true;
                    }
                } else {
                    cout << "Código de cidade inválido! Tente novamente." << endl;
                }
            } while (!cidadeValida);



            tabelaNovasPessoas[i] = Pessoa(id, nome, cpf, endereco, codCidade);
        }

        pessoaRepository.inserirPessoas(tabelaNovasPessoas, totalPessoasInserir);
    }

    void deletePessoasByID(int TabelaPessoasRemovidas[], int tamanhoTabelaPessoasRemovidas) {
        pessoaRepository.deleteByID(TabelaPessoasRemovidas, tamanhoTabelaPessoasRemovidas);
    }

    void getByID(int id) {
        Pessoa p = pessoaRepository.getByID(id);
        Pessoa v[] = { p };
        imprimirPessoas(v, 1);
    }

    Pessoa* getAllPessoas() {
        Pessoa* pessoas = pessoaRepository.getAll();
        imprimirPessoas(pessoas, pessoaRepository.getTamanhoAtual());
        return pessoas;
    }
};

#endif // PESSOA_SERVICE_H
