#include "cream.h"
#include "random69.h"

int main(int argc, char const *argv[])
{
    int N_mol = 400;
    int n_iterations = 10000;

    std::vector<Molecule> ini_mol(N_mol, Molecule(pos_ini(10))); // vector que contiene las clases Molecule

    // for (int ii = 0; ii < N_mol; ++ii){ 
    //     std::cout << ini_mol[ii].position[0];
    //     // Molecule mol({0,0}); // Se crea una molecula con posición inicial aleatoria
    //     // ini_mol.push_back(Molecule(pos_ini(10))); // Se agrega la molecula al vector
    // }


    Cream cup(ini_mol);
    // std::cout << cup.molecules[2].position[0] << std::endl;

    // for (int ii = 0; ii < N_mol; ++ii){ 
    //     int pos_time = cup.molecules[ii].position[0];
    //     // std::cout << pos_time[0] << std::endl;
    // }

    // return 0;
}
