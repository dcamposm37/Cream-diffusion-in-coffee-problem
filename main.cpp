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
inputFile.open("input.txt", std::ios::in); //Abre el archivo en modo lectura.

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






    int N_mol = input[0]; //Number of molecules (400)
    int n_iterations = input[1]; //Niterations (20)
    int latticesize = input[2]; //latticesize (10)
    int seed = input[3]; //randomgeneratorsedd (0)
    int initialLatticeSize = 20;

//    std::mt19937 gen(seed); //Se inicializa el generador con la semilla dada.
    std::vector<Molecule> molecules(N_mol);

    Cream cup(seed,N_mol,n_iterations,latticesize);



    cup.initializeMolecules(molecules, initialLatticeSize);



    // for (int ii = 0; ii < N_mol; ++ii){ 
    //     std::cout << ini_mol[ii].position[0] << std::endl;
    //     // Molecule mol({0,0}); // Se crea una molecula con posición inicial aleatoria
    //     // ini_mol.push_back(Molecule(pos_ini(10))); // Se agrega la molecula al vector
    // }




}
