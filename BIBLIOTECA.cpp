//BIBLIOTECA.cpp

#include <iostream>
#include <string>
#include "service/AutorService.h"
#include "service/EditoraService.h"
#include "service/LivroService.h"
#include "service/EmprestimoService.h"


#include <ctime>
#include <thread>   // std::this_thread::sleep_for
#include <chrono>   // std::chrono::seconds

int main() {
    while (true) {
        std::time_t agora = std::time(nullptr);
        std::tm* tempo = std::localtime(&agora);

        std::cout << "\rHora: "
                  << tempo->tm_hour << ":"
                  << tempo->tm_min << ":"
                  << tempo->tm_sec << std::flush;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
