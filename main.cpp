#include "cream.h"
#include "random69.h"
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>

int main(int argc, char const *argv[])
{

    std::vector<int> input(4); //Vector que guarda los parámetros de entrada.

    std::fstream inputFile;
    inputFile.open("input.txt", std::fstream::in); //Abre el archivo en modo lectura.

    if (inputFile.is_open()){  //Se verifica que esté abierto.
        std::string line;
        int inputContador = 0;
        while(getline(inputFile, line)){  //Se lee cada línea del archivo.
            int pos = line.find(' '); // Busca el primer espacio en la línea
            std::string numberLine = line.substr(0, pos); // Extrae la parte de la cadena antes del espacio

            int val=std::stoi(numberLine); //Se convierten valores numéricos a enteros.
            input[inputContador] = val;
            inputContador++;
        }
        inputFile.close();   //close the file object.
    }


    const int N_mol = input[0]; //Number of molecules (400)
    const int latticesize = input[1]; //latticesize (20) Preferibles números divisibles entre 2.
    const int n_iterations = input[2]; //Niterations (10)
    const int seed = input[3]; //randomgeneratorsedd (0)

    const int maxLatticesize = 200; //Preferibles números divisibles entre 2.
    const int gridbins = 8; //Cantidad de cajas que tendrá por lado. La grilla será cuadrada.

    const std::vector<int> maxLatticeSizes {50,100,150,250,300,350}; //Punto 2


    std::vector<Molecule> molecules(N_mol);

    Cream cup(seed,N_mol,n_iterations,latticesize, maxLatticesize, gridbins); //Punto 1 y 3
    cup.initializeMoleculesGrid(molecules);
    cup.evolve(molecules);


     for (int size : maxLatticeSizes) {

             std::vector<Molecule> molecules2(N_mol);

             Cream cup2(seed,N_mol,n_iterations,latticesize, size, gridbins);
             cup2.initializeMoleculesGrid(molecules2);
             cup2.evolve2(molecules2);
    }



}
