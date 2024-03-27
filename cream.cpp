#include "cream.h"
#include "random69.h"

void Molecule::setPosition(std::vector<int> pos){
    position = pos;
}


Cream::Cream(int randomSeed,int nMol, int nIterations, int latticesize){
    N_molecules = nMol;
    N_iterations = nIterations;
    latticeSize = latticesize;
    std::mt19937 gene(randomSeed);
    gen = gene;

}

void Cream::initializeMolecules(std::vector<Molecule> & molecules, int initialLatticeSize){
    int i;
    for(i=0;i<N_molecules;i++){
    std::vector<int> pos = pos_ini(initialLatticeSize,gen);
    molecules[i].setPosition(pos);
    }


}


// void Cream::evolve(Molecule * moleculesVector);
// {
//     int step = random_step();

//     for (int ii = 0; ii < N_molecules; ++ii) {
//         molecules[ii].position[0] += step;
//         molecules[ii].position[1] += step;

//         // Pared superior y derecha
//         if (molecules[ii].position[0] > 100)
//             molecules[ii].position[0] = 100;

//         if (molecules[ii].position[1] > 100)
//             molecules[ii].position[1] = 100;

//         // Pared inferior e izquierda
//         if (molecules[ii].position[0] < -100)
//             molecules[ii].position[0] = -100;

//         if (molecules[ii].position[1] < -100)
//             molecules[ii].position[1] = -100;

//         time_step++;
//     }
// }

// // Función que calcula el tamaño promedio según la definición del libro
// double Cream::size() {
//         double r = 0;
//         for (int ii = 0; ii < N_molecules; ++ii) {
//             r += std::pow(molecules[ii].position[0], 2) + std::pow(molecules[ii].position[1], 2);
//         }
//         return std::sqrt(r / N_molecules);
// }

// // Función que retorna las posiciones de todas las moleculas
// void Cream::total_positions(){
//     std::string dataName = "position" + std::to_string(time_step) + ".txt";
//     std::ofstream fout;
//     fout.open(dataName);

//     for (int ii = 0; ii < N_molecules; ++ii){
//     std::vector<int> pos_time = molecules[ii].position;
//     fout<<pos_time[0] << "\t" << pos_time[1]<<std::endl;
//     }

//     fout.close();
// }




// double Cream::entropy() {
//    delta = 200/nsample;
// }

///////////// PRUEBAS ///////////////////
// int main(int argc, char const *argv[])
// {
//     Molecule mol(pos_ini(10));

//     std::cout << mol.position[0] << mol.position[1] << std::endl;

//     return 0;
// }
