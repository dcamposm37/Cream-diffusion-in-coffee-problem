#include "random69.h"


// Genera un vector de 2 entradas entre -range y range para las posiciones iniciales de las moleculas
std::vector<int> pos_ini(int range, std::mt19937 &gen) {
    // Generador de números aleatorios

    std::uniform_int_distribution<> distrib(-range, range);
    
    // Generar dos enteros aleatorios
    int random1 = distrib(gen);
    int random2 = distrib(gen);

    // Crear y retornar el vector con los dos enteros aleatorios
    return {random1, random2};
}

// int main() {
//     std::vector<int> ini_mol = pos_ini(10);
//     std::cout << random_step() << std::endl; // Imprime primera función
//     std::cout << ini_mol[0] << std::endl; // Imprime segunda función
    
//     return 0;
// }
