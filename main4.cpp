#include "mol.h"
#include "mol.cpp"

int main(int argc, char *argv[]) {
    //std::ifstream myfile ("imput.txt");
    //std::string line;
    //myfile.is_open();
    //std::vector<int> dat(4);
    //getline(myfile,line);
    int dim=50;
    int mol=50;
    int SEED=0;
    int niter=300000;
    std::vector<std::vector<int>> Molecules(mol,std::vector<int> (2));
    Molecules=POSS(dim,mol,Molecules);

    for(int ju=0; ju<niter;ju++){
        Molecules=MOVE(step(SEED,mol),Molecules, dim);
        std::cout<<ju<<"\t"<<SIZ(Molecules)<<'\n';
    }
    return EXIT_SUCCESS;
}
