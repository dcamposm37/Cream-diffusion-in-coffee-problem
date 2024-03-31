#include "random69.h"


// Genera un vector de 2 entradas entre -range y range para las posiciones iniciales de las moleculas
std::vector<int> pos_ini(int latticesize, std::mt19937 &gen) {
    // Generador de números aleatorios
    int range = latticesize/2; //Si el número no es divisible entre 2, se trunca como entero.
    std::uniform_int_distribution<> distrib(-range, range);
    
    // Generar dos enteros aleatorios
    int random1 = distrib(gen);
    int random2 = distrib(gen);

    // Crear y retornar el vector con los dos enteros aleatorios
    return {random1, random2};
}

