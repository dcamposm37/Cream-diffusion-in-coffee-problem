#include "cream.h"


Molecule::Molecule(std::vector<int> pos) : position(pos) {} //

void Cream::evolve() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-1, 1);

    for (int ii = 0; ii < molecules.size(); ++ii) {
        molecules[ii].position[0] += dis(gen);
        molecules[ii].position[1] += dis(gen);

        // Pared superior y derecha
        if (molecules[ii].position[0] > 100)
            molecules[ii].position[0] = 100;

        if (molecules[ii].position[1] > 100)
            molecules[ii].position[1] = 100;

        // Pared inferior e izquierda
        if (molecules[ii].position[0] < -100)
            molecules[ii].position[0] = -100;

        if (molecules[ii].position[1] < -100)
            molecules[ii].position[1] = -100;

        time_step++;
    }
} 

double Cream::size() {
        double s = 0;
        int N = molecules.size();
        for (int ii = 0; ii < N; ++ii) {
            s += std::pow(molecules[ii].position[0], 2) + std::pow(molecules[ii].position[1], 2);
        }
        return std::sqrt(s / N);
}

// double Cream::entropy() {
//    delta = 200/nsample;
// }