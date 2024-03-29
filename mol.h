#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <fstream>

std::vector<std::vector<int>> POSS(int dim, int mol, std::vector<std::vector<int>> MOL);
std::vector<int> step(int SEED,int mol);
std::vector<std::vector<int>> MOVE(std::vector<int> Pr, std::vector<std::vector<int>> MOL, int dim);
std::vector<std::vector<int>> HOLE(std::vector<std::vector<int>> MOL, int dim);
int SIZ(std::vector<std::vector<int>> MOL);
