#include "cream.h"
#include "random69.h"

Molecule::Molecule(std::vector<int> pos) : position(pos) {} //

Cream::Cream(std::vector<Molecule> mol) {}

void Cream::evolve()
{
    int step = random_step();

    for (int ii = 0; ii < molecules.size(); ++ii) {
        molecules[ii].position[0] += step;
        molecules[ii].position[1] += step;

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
        double r = 0;
        int N = molecules.size();
        for (int ii = 0; ii < N; ++ii) {
            r += std::pow(molecules[ii].position[0], 2) + std::pow(molecules[ii].position[1], 2);
        }
        return std::sqrt(r / N);
}

// double Cream::entropy() {
//    delta = 200/nsample;
// }