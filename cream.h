#pragma once
#include <vector>
#include <random>
#include <cmath>
#include <string>
#include <fstream>


class Molecule;
class Cream;

// Declaración de la clase Molecule
class Molecule {
    std::vector<int> position; //Vector que guarda la posición como (x,y)

public:
    void setPosition(std::vector<int> pos);
    void moveMolecule(int movement, int max);
    friend class Cream; //Se usa para que la clase Cream pueda acceder a los atributos de cualquier molécula.
};

// Declaración de la clase Cream
class Cream {
    int N_molecules;
    int seed;
    int N_iterations;
    int latticeSize;
    int maxLatticeSize;
    std::mt19937 gen;

public:

    Cream(int randomSeed, int nMol, int nIterations, int latticesize, int maxLatticesize); //Constructor clase Cream.

    void initializeMolecules(std::vector<Molecule> & molecules);

    void evolve(std::vector<Molecule> & molecules);

    std::vector<int> infoMoveMolecule(void);

    // void moveMolecule(Molecule & molecule);

    // int time_step = 0;

    // void total_positions();

    // // double entropy(nsample);
    // double size();


};
