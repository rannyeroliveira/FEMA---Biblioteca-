class CPF {
private:
    char cpf[12];

public:
    CPF() {
        strcpy(cpf, "");
    }

    CPF( char* cpf2) {
        setCPF(cpf2);
    }

    void setCPF( char cpfStr[]) {
        if (!validaCPF(cpfStr)) {
            std::cout<<"CPF invalido";
        }else {
            strncpy(this->cpf, cpfStr,11);
            std::cout<<"CPF valido";
        }

    }

    const char* getCPF() const {
        return cpf;
    }

    bool validaCPF(char cpfStr[]) const {
        char cpfT[12];
        strcpy(cpfT, cpfStr);
        int tamanhoCPF = strlen(cpfT);
        if (tamanhoCPF != 11) {
            return false;
        }

        for (int i = 0; i < 11; ++i) {
            if (cpfT[i] < '0' || cpfT[i] > '9') return false;
        }

        bool todosIguais = true;
        for (int i = 1; i < 11; ++i) {
            if (cpfT[i] != cpfT[0]) {
                todosIguais = false;
                break;
            }
        }
        if (todosIguais) return false;

        int soma = 0;
        for (int i = 0; i < 9; ++i) {
            soma += (cpfT[i] - '0') * (10 - i);
        }
        int resto = (soma * 10) % 11;
        if (resto == 10) resto = 0;
        if (resto != (cpfT[9] - '0')) return false;

        soma = 0;
        for (int i = 0; i < 10; ++i) {
            soma += (cpfT[i] - '0') * (11 - i);
        }
        resto = (soma * 10) % 11;
        if (resto == 10) resto = 0;
        if (resto != (cpfT[10] - '0')) return false;

        return true;
    }
    
};
