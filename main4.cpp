#include "mol.h"
#include "mol.cpp"

int main(int argc, char *argv[]) {

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


    const int N_mol = input[0]; //Number of molecules
    const int latticesize = input[1]; //latticesize
    const int niter = input[2]; //Niterations
    const int SEED= input[3]; //randomgeneratorsedd

    std::vector<std::vector<int>> Molecules(N_mol,std::vector<int> (2));
    Molecules=POSS(latticesize,N_mol,Molecules);
    std::mt19937 gen(SEED);
    std::vector<int> Prob (2);
    std::uniform_int_distribution<> distrib(1,4);
    std::uniform_int_distribution<> dis(0,N_mol-1);


    for(int ju=0; ju<niter;ju++){
        Prob[0]=distrib(gen);
        Prob[1]=dis(gen);
        Molecules=MOVE(Prob,Molecules, latticesize);
        std::cout<<ju<<"\t"<<SIZ(Molecules)<<'\n';
    }
    return EXIT_SUCCESS;
}
