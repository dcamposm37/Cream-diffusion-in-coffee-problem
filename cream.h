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
    std::vector<int> position;

public:
    void setPosition(std::vector<int> pos);
    friend class Cream; //Se usa para que la clase Cream pueda acceder a los atributos de cualquier molécula.
};

// Declaración de la clase Cream
class Cream {
    int N_molecules;
    int seed;
    int N_iterations;
    int latticeSize;
    std::mt19937 gen;

public:

    Cream(int nMol, int nIterations, int latticesize, std::mt19937 & genMt); //Constructor clase Cream.

    void initializeMolecules(std::vector<Molecule> &molecules, int initialLatticeSize);

    // void evolve(Molecule * moleculesVector);
    // void moveMolecule(Molecule & molecule);

    // int time_step = 0;

    // void total_positions();

    // // double entropy(nsample);
    // double size();


};
