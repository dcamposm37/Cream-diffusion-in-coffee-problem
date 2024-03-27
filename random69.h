#pragma once
#include <random>
#include <iostream>

int random_step(std::mt19937 gen);

std::vector<int> pos_ini(int range, std::mt19937 & gen);
