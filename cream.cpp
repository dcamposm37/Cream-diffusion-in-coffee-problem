#include "cream.h"
#include "random69.h"


void Molecule::setPosition(std::vector<int> pos){
    position = pos;
}

void Molecule::moveMolecule(int movement, int maxLattice, int containerHoleSize, int &numberHoleMolecules){

    /*Se cuentan las moléculas que se salen por un hueco de tamaño "containerHolseSize" ubicado en la pared derecha.
      Si una molécula sale por el hueco, cambia su atributo "counted" a true, por lo que no volverá a ser contada. Lo anterior para
      resolver el punto 1, 3 y 4 con un solo código. */

    int containerHoleSizeD2= containerHoleSize/2;
    int x = position[0];
    int y = position[1];
    int max = maxLattice/2; //Si maxLattice no es divisible entre 2, se trunca.

    if((counted==false) && (movement == 0) && (x==max) && (y<containerHoleSizeD2) && (y>-containerHoleSizeD2)){
        counted=true;
        numberHoleMolecules+=1;
    }

    /* La variable movement será un número de 0 a 3, se establece la convención de que los números pares corresponden a incrementeos y
       los números impares a decrementos. Además si el número es 0 ó 1, corresponde desplazamientos en x; si el número es 2 ó 3 corresponde
       a desplazaminetos en y.
       Se establecen condicionales de modo que cuando una molécula llegue al límite no pueda salir, pero sí entrar de nuevo. Se considera que es
       lo que sucedería físicamente dado el problema. */

    if((movement == 0) && (x < max)) position[0] +=1;
    if((movement == 1) && (x > -max)) position[0]-=1;
    if((movement == 2) && (y < max)) position[1] +=1;
    if((movement == 3) && (y > -max)) position[1] -=1;
}


Cream::Cream(int randomSeed, int nMol, int nIterations, int latticesize, int maxLatticesize, int gridbins){
    N_molecules = nMol;
    N_iterations = nIterations;
    latticeSize = latticesize;
    maxLatticeSize = maxLatticesize;
    gen = std::mt19937(randomSeed);
    gridBins = gridbins;
    grid.resize(gridbins*gridbins,0);
    containerHoleSize = (maxLatticeSize*10)/50; //Se calcula el tamaño del hueco tomando en cuenta la relación dada en el pdf.
    N_moleculesD = static_cast<double>(N_molecules);
}

std::vector<int> Cream::getGrid(void){
    return grid;
}
void Cream::setSize(double sizeSet) {size=sizeSet;}
void Cream::setEntropy(double entropySet) {entropy=entropySet;}

double Cream::getSize(void) {return size;}
double Cream::getEntropy(void) {return entropy;}


void Cream::initializeMoleculesGrid(std::vector<Molecule> & molecules){
    int i;
    double N_moleculesD = static_cast<double>(N_molecules);
    for(i=0;i<N_molecules;i++){
        std::vector<int> pos = pos_ini(latticeSize,gen); //Devuelve la posición inicial en formato {x,y}
        molecules[i].setPosition(pos);
        size += std::pow(pos[0], 2) + std::pow(pos[1], 2);
        fillInitialGrid(pos); //Se llena la grilla inicial
    }

    entropyInitial(); //Inicializa entropía.
    size = size/N_moleculesD; //Inicializa size.
}

void Cream::fillInitialGrid(std::vector<int> pos){
    double Mx;
    double My;
    double ancho = maxLatticeSize/gridBins;
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

    int MxI = static_cast<int>(Mx);
    int MyI = static_cast<int>(My);

    grid[MyI*gridBins + MxI] += 1;
}



std::vector<int> Cream::infoMoveMolecule(void){

    std::uniform_int_distribution<> distribMolecule(0,N_molecules-1); //Genera una distribución uniforme que devolverá el índice de la molecula a modificar.
    std::uniform_int_distribution<> distribMove(0, 3); //Genera una distribución uniforme entre 0 y 3 que indica qué movimiento tendrá la molécula.
    std::vector<int> randomInfo = {distribMolecule(gen), distribMove(gen)};
    return randomInfo; // Devuelve ambos valores aleatorios.
}

void Cream::evolve(std::vector<Molecule> & molecules)
{
    std::ofstream fout;
    std::ofstream fout_size;
    std::ofstream fout_moleculesTime;



    std::string entropyFileName  = "EntropyVsTime" + std::to_string(maxLatticeSize) + "x" + std::to_string(maxLatticeSize) + ".txt";
    fout.open(entropyFileName);
    fout_size.open("SizeVsTime.txt");
    fout_moleculesTime.open("moleculesVsTime.txt");
    int numberOfMoleculesLeftBefore = N_molecules - numberHoleMolecules; //Variables adicionales para mandar al archivo el número de moléculas solo cuando cambie.
    int numberOfMoleculesLeftAfter = N_molecules - numberHoleMolecules + 1 ;

    for (int t=0;t<N_iterations;t++) {

        if(true){
        // if(t%1000==0){ //Se limita la cantidad de datos que tiene cada archivo para facilitar su graficación.
            fout <<t<<"\t"<<entropy<<"\n";
            fout_size << t << "\t" <<size<< "\n";
        }

        if(numberOfMoleculesLeftBefore != numberOfMoleculesLeftAfter) fout_moleculesTime<<t<<"\t"<<numberOfMoleculesLeftBefore<<"\n";
        numberOfMoleculesLeftBefore = N_molecules - numberHoleMolecules;
        std::vector<int> infoMove = infoMoveMolecule();
        int numberMolecule = infoMove[0];
        int movement = infoMove[1];
        updateGrid(molecules[numberMolecule], movement); //Se gestiona cómo se actualiza la grilla y así mismo cálculos de entropía y size.
        numberOfMoleculesLeftAfter = N_molecules - numberHoleMolecules;

    }

    fout.close();
    fout_size.close();
    fout_moleculesTime.close();

    //Mostrar el arreglo final de partículas:
    // fout.open("datos0.txt");

    // for (int i=0;i<N_molecules;i++) {
    //     fout<<molecules[i].position[0]<<"\t"<<molecules[i].position[1]<<"\n";
    // }
    // fout.close();

}

void Cream::entropyInitial(void){
    double S=0;
    for(int i=0;i<gridBins*gridBins;i++) {
        double probabilityi = grid[i]/N_moleculesD;
        if(probabilityi < 0.001){
            continue;
        }
        S+= std::log(probabilityi)*probabilityi;
    }
    entropy = -S;
}




void Cream::updateGrid(Molecule &mol,int movement){


    std::vector<int> pos = mol.position; //Se guarda la posición.
    bool xLimit = false;
    bool yLimit = false;
    int x = pos[0];
    int y = pos[1];

    double Mx;
    double My;

    int limit = maxLatticeSize/2;
    double ancho = static_cast<double>(maxLatticeSize)/gridBins;
    int valDistance = maxLatticeSize/2;


    if((x != limit) && (y != limit)){//Si x e y no son el límite, podemos operar sin problema Mx e My.
        Mx = (pos[0] + valDistance)/ancho; //Índice de la columna.
        My = (pos[1] + valDistance)/ancho; //Índice de la fila.
    }
    else{ //Uno de los dos es límite. Se manejan por aparte porque hay problemas al calcular Mx e My, pues en el límite toman el valor de un elemento del arreglo que no existe, puesto que los invervalos en la grilla son cerrados a izquierda y abiertos a derecha.

        if(x==limit) {
            Mx = gridBins-1;
            xLimit = true;
        }

        if(y==limit) {
            My = gridBins-1;
            yLimit = true;}

        if(xLimit == true && yLimit == false){
            My = (pos[1] + valDistance)/ancho; //Índice de la fila.
        }
        else if (xLimit == false && yLimit == true) {
            Mx = (pos[0] + valDistance)/ancho; //Índice de la columna.
        }
    }

    int MxI_B = static_cast<int>(Mx); //Se guarda el valor de MxI "Before"
    int MyI_B = static_cast<int>(My); //Se guardan el valor de MyI "Before"

    mol.moveMolecule(movement,maxLatticeSize,containerHoleSize,numberHoleMolecules); //Se mueve la molécula.

    pos = mol.position;
    xLimit = false;
    yLimit = false;
    int x_B = x; //Se guardan los valores de las posiciones "Before" para el cálculo de Size.
    int y_B = y;
    x = pos[0];
    y = pos[1];

    //Se vuelve a evaluar si los nuevos valores tienen o no problemas por ser límite.
    if((x != limit) && (y != limit)){
        Mx = (pos[0] + valDistance)/ancho; //Índice de la columna.
        My = (pos[1] + valDistance)/ancho; //Índice de la fila.
    }
    else{ //Uno de los dos es límite.

        if(x==limit) {
            Mx = gridBins-1;
            xLimit = true;
        }

        if(y==limit) {
            My = gridBins-1;
            yLimit = true;}

        if(xLimit == true && yLimit == false){
            My = (pos[1] + valDistance)/ancho; //Índice de la fila.
        }
        else if (xLimit == false && yLimit == true) {
            Mx = (pos[0] + valDistance)/ancho; //Índice de la columna.
        }
    }

    int MxI_A = static_cast<int>(Mx); //Se guarda MxI "After"
    int MyI_A = static_cast<int>(My); //Se guarda MyI "After"

    /*
      Si cambió alguno de los dos componentes del índice, entonces se debe recalcular la entropía,
      en caso contrario permanecerá igual, pues la molécula no habrá cambiado de celda.
    */
    if((MxI_A != MxI_B) || (MyI_A != MyI_B)){

        int index_B = MyI_B*gridBins + MxI_B;
        int index_A = MyI_A*gridBins + MxI_A;


        double probability_B = grid[index_B]/N_moleculesD;
        double probability_A = grid[index_A]/N_moleculesD;

        if(probability_B > 0.001){
            double S_B = std::log(probability_B)*probability_B;

            entropy += S_B; //Se le resta el valor S_B a la entropía (S_B < 0), pues hubo movimiento.

        }
        if(probability_A > 0.001){
            double S_A = std::log(probability_A)*probability_A;
            entropy += S_A; //Se le resta el valor S_A a la entropía (S_A < 0), pues hubo movimiento.
        }


        grid[index_B] -= 1;
        grid[index_A] += 1;
        //Se actualiza la grilla y las probabilidades que ahora hay que sumar.
        probability_B = grid[index_B]/N_moleculesD;
        probability_A = grid[index_A]/N_moleculesD;

        if(probability_B > 0.001){
            double S_B = std::log(probability_B)*probability_B;

            entropy -= S_B; //Se le suma el valor S_B a la entropía (S_B < 0), pues hubo movimiento.

        }
        if(probability_A > 0.001){
            double S_A = std::log(probability_A)*probability_A;
            entropy -= S_A; //Se le suma el valor S_B a la entropía (S_B < 0), pues hubo movimiento.
        }
    }


    size += -(std::pow(x_B, 2) + std::pow(y_B, 2))/N_moleculesD; //Se le quita el valor que tenía la molécula que se movió
    size += +(std::pow(x, 2) + std::pow(y, 2))/N_moleculesD; //Se agrega el valor de la molécula con sus nuevos valores de posición.

}



void Cream::evolve2(std::vector<Molecule> & molecules) //Funcionamiento análogo a evolve1 pero no se abren archivos para escribir size ni número de moléculas.
{

    //Imprime iniciales.
    std::ofstream fout;

    std::string entropyFileName  = "EntropyVsTime" + std::to_string(maxLatticeSize) + "x" + std::to_string(maxLatticeSize) + ".txt";
    fout.open(entropyFileName);

    for (int t=0;t<N_iterations;t++) {
        // if(true){
        if(t%1000==0){
            fout <<t<<"\t"<<entropy<<"\n";
        }
        std::vector<int> infoMove = infoMoveMolecule();
        int numberMolecule = infoMove[0];
        int movement = infoMove[1];
        updateGrid(molecules[numberMolecule], movement);

    }

    fout.close();

    // //Mostrar el arreglo final de partículas:
    //                                 fout.open("datos0.txt");

    //                                 for (int i=0;i<N_molecules;i++) {
    //                                     fout<<molecules[i].position[0]<<"\t"<<molecules[i].position[1]<<"\n";
    //                                 }
    //                                 fout.close();

}























