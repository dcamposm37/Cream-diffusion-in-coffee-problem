#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "random69.h"
#include "cream.h"



TEST_CASE("Functionalty of pos_ini", "[pos_ini]") {

std::mt19937 gen(0); //Se crea un generador aleatorio con semilla en 0.
std::mt19937 gene(0); //Se crea un segundo generador aleatorio con semilla en 0, que se usará para comparar.
int lattice = 20;
int range = lattice/2;
std::uniform_int_distribution<> distrib(-range,range);
std::vector<int> values = pos_ini(lattice, gen);
REQUIRE(values[0] == distrib(gene));
REQUIRE(values[1] == distrib(gene));

}
