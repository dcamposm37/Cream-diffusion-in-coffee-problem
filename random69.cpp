#include "random69.h"

// Utiliza un generador de números aleatorios para generar un índice aleatorio dentro del rango válido para el 
//   arreglo proporcionado y devuelve el elemento correspondiente a ese índice. 
int random_step(std::vector<int>& vec) {
    // Generador de números aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, vec.size() - 1);

    int randomIndex = distrib(gen); // Generar un índice aleatorio
    return vec[randomIndex]; // Devolver el elemento correspondiente al índice aleatorio
}

// Genera un vector de 2 entradas entre -range y range para las posiciones iniciales de las moleculas
std::vector<int> pos_ini(int range) {
    // Generador de números aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(-range, range);
    
    // Generar dos enteros aleatorios
    int random1 = distrib(gen);
    int random2 = distrib(gen);
    
    // Crear y retornar el vector con los dos enteros aleatorios
    return {random1, random2};
}

int main() {
    std::vector<int> step = {-1,1};
    
    // Ejemplo de uso
    std::cout << "Elemento aleatorio seleccionado: " << random_step(step) << std::endl;
    std::cout << "Elemento aleatorio seleccionado: " << random_step(step) << std::endl;
    
    return 0;
}