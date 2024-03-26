#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <string>
#include <fstream>

// Declaración de la clase Molecule
class Molecule {
public:
    std::vector<int> position;

    Molecule(std::vector<int> pos);
};

// Declaración de la clase Cream
class Cream {
public:
    std::vector<Molecule> molecules;

    int N_molecules;

    int time_step = 0;

    void evolve();

    void total_positions();

    // double entropy(nsample);

    double size();

    Cream(std::vector<Molecule> mol, int N_molecules);
};