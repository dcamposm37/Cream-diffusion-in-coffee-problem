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
    void moveMolecule(int movement, int maxLattice, int containerHoleSize,int &numberHoleMolecules); //Maneja el movimiento de la molécula.

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
    std::mt19937 gen; //Generador de números aleatorios.
    std::vector<int> grid;
    int containerHoleSize;
    int numberHoleMolecules=0;
    double entropy=0;
    double size=0; //Tamaño del grupo de moléculas.
    double N_moleculesD; //N_molecules pero tipo double para evitar división entera no requerida.

public:

    Cream(int randomSeed, int nMol, int nIterations, int latticesize, int maxLatticesize, int gridbins); //Constructor clase Cream.

    std::vector<int> getGrid(void);
    void setSize(double sizeSet);
    void setEntropy(double entropySet);
    double getSize(void);
    double getEntropy(void);
    void initializeMoleculesGrid(std::vector<Molecule> & molecules);
    void fillInitialGrid(std::vector<int> pos); //Llena la grilla con las posiciones iniciales de las moléculas.
    void evolve(std::vector<Molecule> & molecules); //Evoluciona el sistema
    void evolve2(std::vector<Molecule> & molecules); //Evoluciona el sistema sin imprimir size ni moléculas por paso de tiempo. (Punto 2)
    std::vector<int> infoMoveMolecule(void); //Información para mover las moléculas.
    void entropyInitial(void); //Calcula la entropía inicial.
    void updateGrid(Molecule &mol,int flag);




};
