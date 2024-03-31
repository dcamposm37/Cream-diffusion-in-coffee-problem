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
            input[inputContador] = val; //Se guardan los valores en el arreglo construido para ello.
            inputContador++;
        }
        inputFile.close();   //close the file object.
    }


    const int N_mol = input[0]; //Number of molecules
    const int latticesize = input[1]; //latticesize: Tamaño del arreglo inicial de moléculas. Será de tamaño latticesizeXlatticesize
    const int n_iterations = input[2]; //Niterations
    const int seed = input[3]; //randomgeneratorsedd

    const int maxLatticesize = 200; //Tamaño del lado del cuadrado que contiene todas las moléculas. Será de 200x200
    const int gridbins = 8; //Cantidad de cajas que tendrá por lado. La grilla será cuadrada.

    const std::vector<int> maxLatticeSizes {50,100,150,250,300,350}; //Arreglo para estudiar los tamaños que pide el punto 2.


    std::vector<Molecule> molecules(N_mol); //Vector que almacena todas las moléculas. Clase Molecule.

    Cream cup(seed,N_mol,n_iterations,latticesize, maxLatticesize, gridbins); //Objeto cup de la clase Cream.
    cup.initializeMoleculesGrid(molecules); //Se inicializan las moléculas, grilla, entropía y size.
    cup.evolve(molecules); //Evoluciona el sistema.

     for (int size : maxLatticeSizes) { //Se recorren los distintos tamaños.

             std::vector<Molecule> molecules2(N_mol);
             Cream cup2(seed,N_mol,n_iterations,latticesize, size, gridbins);
             cup2.initializeMoleculesGrid(molecules2);
             cup2.evolve2(molecules2);
    }



}
