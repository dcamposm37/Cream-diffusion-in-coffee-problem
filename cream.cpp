#include "cream.h"
#include "random69.h"


void Molecule::setPosition(std::vector<int> pos){
    position = pos;
}

void Molecule::moveMolecule(int movement, int maxLattice){
    /* La variable movement será un número de 0 a 3, se establece la convención de que los números pares corresponden a incrementeos y
       los números impares a decrementos. Además si el número es 0 ó 1, corresponde desplazamientos en x; si el número es 2 ó 3 corresponde
       a desplazaminetos en y.
       Se establecen condicionales de modo que cuando una molécula llegue al límite se congele en esa coordenada. */

    int max = maxLattice/2; //Si maxLattice no es divisible entre 2, se trunca.
    if((movement == 0) && (position[0] < max)) position[0] +=1;
    if((movement == 1) && (position[0] > -max)) position[0]-=1;
    if((movement == 2) && (position[1] < max)) position[1] +=1;
    if((movement == 3) && (position[1] > -max)) position[1] -=1;
}


Cream::Cream(int randomSeed, int nMol, int nIterations, int latticesize, int maxLatticesize, int gridbins){
    N_molecules = nMol;
    N_iterations = nIterations;
    latticeSize = latticesize;
    maxLatticeSize = maxLatticesize;
    gen = std::mt19937(randomSeed);
    gridBins = gridbins;
    grid.resize(gridbins*gridbins,0);

}

std::vector<int> Cream::getGrid(void){
    return grid;
}

void Cream::initializeMoleculesGrid(std::vector<Molecule> & molecules){
    int i;

    for(i=0;i<N_molecules;i++){
        std::vector<int> pos = pos_ini(latticeSize,gen); //Devuelve la posición inicial en formato {x,y}
        molecules[i].setPosition(pos);
        fillInitialGrid(pos);
    }

}

void Cream::fillInitialGrid(std::vector<int> pos){
        int Mx;
        int My;
        int ancho = maxLatticeSize/gridBins;
        int valDistance = maxLatticeSize/2;
        /* Se llena la grilla de la siguiente forma: Como sabemos el tamaño de la grilla (maxLatticeSize) y
           el número de cajas que tendrá por cada lado (gridBins), entonces el ancho de cada cuadrado será maxLatticeSize/gridBins.
           Ahora, si tomamos el extremo izquierdo, con maxLatticeSize=200 el extremo izquierdo sería la coordenada (-100,-100), como el lugar desde
           donde se empiezan a contar los bins (Que inician en 0) y la distancia, tenemos que se cumple que M veces el ancho será igual a la distancia de un valor "x"
           desde (-100,-100). Así, se cumplirá en x que: M*Ancho = x+100, donde la parte entera de M nos dirá a qué bin en el eje x pertenece el valor x. De la misma
           forma M*Ancho = y + 100 nos dirá a qué bin del eje y pertenece el valor y. Se implementa a continuación. Para una explicación gráfica, refiérase al informe.
        */
        Mx = (pos[0] + valDistance)/ancho; //Índice de la columna.
        My = (pos[1] + valDistance)/ancho; //Índice de la fila.

        grid[My*gridBins + Mx] += 1;
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

fout.open("datos1.txt");

for (int i=0;i<gridBins*gridBins;i++) {
fout<<i<<"\t"<<grid[i]<<"\n";
 }
 fout.close();

//Crear arreglo inicial como atributo.
//Paso por referencia en initialize (MoleculesGrid) y calculo dónde están las posiciones iniciales.
//Luego, en evolve calculo a dónde se movió la que se movió y actualizo.


    for (int t=0;t<N_iterations;t++) {
        std::vector<int> infoMove = infoMoveMolecule();
        int numberMolecule = infoMove[0];
        int movement = infoMove[1];
        molecules[numberMolecule].moveMolecule(movement,maxLatticeSize); //Se mueve la molécula.
    }



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
