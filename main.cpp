#include "cream.h"
#include "random69.h"

int main(int argc, char const *argv[])
{
    int N_mol = 400;
    int n_iterations = 10000;

    std::vector<Molecule> ini_mol; // vector que contiene las clases Molecule

    for (int ii = 0; ii < N_mol; ++ii){ 
        Molecule mol(pos_ini(10)); // Se crea una molecula con posición inicial
        ini_mol[ii] = mol; // Se agrega la molecula al vector
    }


    Cream cup(ini_mol);

    for (int ii = 0; ii < N_mol; ++ii){ 
        std::vector<int> pos_time = cup.molecules[ii].position;
        std::cout << pos_time[0] << pos_time[1] << std::endl;
    }

    return 0;
}
