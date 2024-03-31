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
    bool counted=false;
public:
    void setPosition(std::vector<int> pos);
    void moveMolecule(int movement, int maxLattice, int containerHoleSize,int &numberHoleMolecules);

    friend class Cream; //Se usa para que la clase Cream pueda acceder a los atributos de cualquier molécula.
};

// Declaración de la clase Cream
class Cream {
    int N_molecules;
    int seed;
    int N_iterations;
    int latticeSize;
    int maxLatticeSize;
    int gridBins;
    std::mt19937 gen;
    std::vector<int> grid;
    int containerHoleSize;
    int numberHoleMolecules=0;
    double entropy=0;
    double size=0;
    double N_moleculesD;

public:

    Cream(int randomSeed, int nMol, int nIterations, int latticesize, int maxLatticesize, int gridbins); //Constructor clase Cream.

    std::vector<int> getGrid(void);

    void initializeMoleculesGrid(std::vector<Molecule> & molecules);

    void fillInitialGrid(std::vector<int> pos);
    void evolve(std::vector<Molecule> & molecules);
    void evolve2(std::vector<Molecule> & molecules);
    std::vector<int> infoMoveMolecule(void);

    void entropyPerTimeStep(void);
    void updateGrid(Molecule &mol,int flag);





};
