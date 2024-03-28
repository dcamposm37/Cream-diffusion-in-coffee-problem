#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "random69.h"
#include "cream.h"



TEST_CASE("Functionality of pos_ini", "[pos_ini]") {

std::mt19937 gen(0); //Se crea un generador aleatorio con semilla en 0.
std::mt19937 gene(0); //Se crea un segundo generador aleatorio con semilla en 0, que se usará para comparar.
int lattice = 20;
int range = lattice/2;
std::uniform_int_distribution<> distrib(-range,range);
std::vector<int> values = pos_ini(lattice, gen);
REQUIRE(values[0] == distrib(gene));
REQUIRE(values[1] == distrib(gene));

}

TEST_CASE("Functionality of initial grid", "[fillInitialGrid]"){
    const int N_mol = 10;
    const int latticesize = 20;
    const int n_iterations = 10;
    const int seed = 0;

    const int maxLatticesize = 200; //Preferibles números divisibles entre 2.
    const int gridbins = 8; //Cantidad de cajas que tendrá por lado. La grilla será cuadrada.

    Cream cup(seed,N_mol,n_iterations,latticesize, maxLatticesize, gridbins);

    std::vector<int> pos1 = {1,2};
    std::vector<int> pos2 = {5,7};
    std::vector<int> pos3 = {2,8};
    std::vector<int> pos4 = {1,7};
    std::vector<int> pos5 = {-2,3};
    std::vector<int> pos6 = {3,-2};
    std::vector<int> pos7 = {-1,-4};
    std::vector<int> pos8 = {8,-9};
    std::vector<int> pos9 = {10,-5};
    std::vector<int> pos10 = {-2,0};

    cup.fillInitialGrid(pos1);
    cup.fillInitialGrid(pos2);
    cup.fillInitialGrid(pos3);
    cup.fillInitialGrid(pos4);
    cup.fillInitialGrid(pos5);
    cup.fillInitialGrid(pos6);
    cup.fillInitialGrid(pos7);
    cup.fillInitialGrid(pos8);
    cup.fillInitialGrid(pos9);
    cup.fillInitialGrid(pos10);
    std::vector<int> grid = cup.getGrid();
    REQUIRE(grid[27]==1);
    REQUIRE(grid[28]==3);
    REQUIRE(grid[35]==2);
    REQUIRE(grid[36]==4);


}
