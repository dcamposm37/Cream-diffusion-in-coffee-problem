#include "mol.h"


std::vector<std::vector<int>> POSS(int dim, int mol, std::vector<std::vector<int>> MOL){
    int dim2= dim/2;
    if(dim % 2 == 0){
        int N1=mol/20;
        int N2=mol/20;
        int N3=mol/20;
        int N4=mol/20;

        int k=N1+N2+N3+N4;
        if (mol*k<mol*mol){
            for(int uu=k; uu<mol;uu++){
                N1+=1;
                uu+=1;
                N4+=1;
            }
        }
        int N5=N1+N2;
        int N6=N5+N3;
        for(int ia=0; ia<N1; ia++){
            MOL[ia][0]=(dim2)-1;
            MOL[ia][1]=(dim2)-1;
        }
        for(int ai=N1; ai<N5; ai++){
            MOL[ai][0]=(dim2)-1;
            MOL[ai][1]=(dim2);
        }
        for(int ais=N5; ais<N6; ais++){
            MOL[ais][0]=(dim2);
            MOL[ais][1]=(dim2)-1;
        }
        for(int a=N6; a<mol; a++){
            MOL[a][0]=(dim2);
            MOL[a][1]=(dim2);
        }
        return MOL;
    }
    else{
         for(int ir=0; ir<mol; ir++){
             for(int jr=0; jr<2; jr++){
                 MOL[ir][jr]=(dim2)+0.5;
             }
         }
         return MOL;
    }
}

std::vector<std::vector<int>> MOVE(std::vector<int> Pr, std::vector<std::vector<int>> MOL, int dim){
    int M1=Pr[0];
    int M2=Pr[1];
    int P1=1, P2=-1;
    if(MOL[M2][0]==-10 || MOL[M2][1]==-10){
        return MOL;
    }
    else{
        if(M1==1){
            MOL[M2][0]+=P1;
            if(MOL[M2][0]>(dim-1)){
                MOL[M2][0]=dim-1;
            }
        }
        if(M1==2){
            MOL[M2][0]+=P2;
            if(MOL[M2][0]<0 ){
                MOL[M2][0]=0;
            }
        }
        if(M1==3){
            MOL[M2][1]+=P1;
            if(MOL[M2][1]>(dim-1)){
                MOL[M2][1]=dim-1;
            }
        }
        if(M1==4){
            MOL[M2][1]+=P2;
            if(MOL[M2][1]<0 ){
                MOL[M2][1]=0;
            }
        }
        MOL=HOLE(MOL,dim);
        return MOL;
    }
}

std::vector<std::vector<int>> HOLE(std::vector<std::vector<int>> MOL, int dim){
    int omega=MOL.size();
    if( dim% 2 ==0){
        int adl=dim/2;
        for(int ua=0; ua<omega; ua++){
            if(MOL[ua][0]==0){
                if(MOL[ua][1]==adl-5||MOL[ua][1]==adl-4||MOL[ua][1]==adl-3||MOL[ua][1]==adl-2||MOL[ua][1]==adl-1||MOL[ua][1]==adl||MOL[ua][1]==adl+1||MOL[ua][1]==adl+2||MOL[ua][1]==adl+3||MOL[ua][1]==adl+4){
                    MOL[ua][0]=-10;
                    MOL[ua][1]=-10;
                }
            }
        }
    }
    else{
        int ald=dim/2 +0.5;
        for(int kk=0; kk<omega; kk++){
            if(MOL[kk][0]==0){
                if(MOL[kk][1]==ald-5||MOL[kk][1]==ald-4||MOL[kk][1]==ald-3||MOL[kk][1]==ald-2||MOL[kk][1]==ald-1||MOL[kk][1]==ald||MOL[kk][1]==ald+1||MOL[kk][1]==ald+2||MOL[kk][1]==ald+3||MOL[kk][1]==ald+4){
                    MOL[kk][0]=-10;
                    MOL[kk][1]=-10;
                }
            }
        }
    }
    return MOL;
}

int SIZ(std::vector<std::vector<int>> MOL){
    int End=MOL.size();
    int Fin=0;
    for(int ll=0; ll<End; ll++){
            if(MOL[ll][0]==-10 || MOL[ll][1]==-10){
                Fin=1+Fin;
            }
            else{

            }
        }
    int U=End-Fin;
    return U;
}
