#include "cream.h"
#include "random69.h"


void Molecule::setPosition(std::vector<int> pos){
    position = pos;
}

void Molecule::moveMolecule(int movement, int max){
    /* La variable movement será un número de 0 a 3, se establece la convención de que los números pares corresponden a incrementeos y
       los números impares a decrementos. Además si el número es 0 ó 1, corresponde desplazamientos en x; si el número es 2 ó 3 corresponde
       a desplazaminetos en y.
       Se establecen condicionales de modo que cuando una molécula llegue al límite se congele en esa coordenada. */
    if((movement == 0) && (position[0] < max)) position[0] +=1;
    if((movement == 1) && (position[0] > -max)) position[0]-=1;
    if((movement == 2) && (position[1] < max)) position[1] +=1;
    if((movement == 3) && (position[1] > -max)) position[1] -=1;
}


Cream::Cream(int randomSeed,int nMol, int nIterations, int latticesize, int maxLatticesize){
    N_molecules = nMol;
    N_iterations = nIterations;
    latticeSize = latticesize;
    maxLatticeSize = maxLatticesize;
    std::mt19937 gene(randomSeed);
    gen = gene;

}

void Cream::initializeMolecules(std::vector<Molecule> & molecules){
    int i;
    for(i=0;i<N_molecules;i++){
        std::vector<int> pos = pos_ini(latticeSize,gen);
        molecules[i].setPosition(pos);
    }

}

    std::vector<int> Cream::infoMoveMolecule(void){

        std::uniform_int_distribution<> distribMolecule(0,N_molecules-1); //Genera una distribución uniforme que devolverá el índice de la molecula a modificar.
        std::uniform_int_distribution<> distribMove(0, 3); //Genera una distribución uniforme entre 0 y 3 que indica qué movimiento tendrá la molécula.
        std::vector<int> randomInfo = {distribMolecule(gen), distribMove(gen)};
        return randomInfo; // Devuelve ambos valores aleatorios.
    }

void Cream::evolve(std::vector<Molecule> & molecules)
{

//Imprime iniciales.
std::ofstream fout;
fout.open("datos0.txt");

for (int i=0;i<N_molecules;i++) {
fout<<i<<"\t"<<molecules[i].position[0]<<"\t"<<molecules[i].position[1]<<"\n";
 }
 fout.close();


    for (int t=0;t<N_iterations;t++) {
        std::vector<int> infoMove = infoMoveMolecule();
        int numberMolecule = infoMove[0];
        int movement = infoMove[1];
        molecules[numberMolecule].moveMolecule(movement,maxLatticeSize); //Se mueve la molécula.
    }
fout.open("datos1.txt");
 for (int i=0;i<N_molecules;i++) {
     fout<<i<<"\t"<<molecules[i].position[0]<<"\t"<<molecules[i].position[1]<<"\n";
 }
 fout.close();

}

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
