#include "cream.h"
#include "random69.h"
#include <iostream>


int main(int argc, char const *argv[])
{
    int N_mol = 400; //Number of molecules
    int n_iterations = 10; //Niterations
    int latticesize = 100; //latticesize
    int seed = 0; //randomgeneratorsedd


    std::vector<Molecule> molecules(N_mol);

    Cream cup(seed, N_mol);
    cup.initializeMolecules(molecules);



    // for (int ii = 0; ii < N_mol; ++ii){ 
    //     std::cout << ini_mol[ii].position[0] << std::endl;
    //     // Molecule mol({0,0}); // Se crea una molecula con posición inicial aleatoria
    //     // ini_mol.push_back(Molecule(pos_ini(10))); // Se agrega la molecula al vector
    // }




}
