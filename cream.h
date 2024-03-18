#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <cmath>

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

    int time_step;

    void evolve();

    // double entropy(nsample);

    double size();

    Cream(std::vector<Molecule> mol);
};