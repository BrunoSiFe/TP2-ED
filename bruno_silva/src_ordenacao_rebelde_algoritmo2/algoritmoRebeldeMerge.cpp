#include <iostream>
#include <stdlib.h>
#define Troca(A, B) {Planeta c = A; A = B; B = c; }
#include "headers/planeta.hpp"
using namespace TP;

void merge(int esquerda,int meio,int direita, Planeta vetorPlanetas[]){
    int quantidadeValoresEsquerda = meio-esquerda+1;
    int quantidadeValoresDireita = fim - meio;

    Planeta *vetorPlanetasEsquerda = new Planetas[quantidadeValoresEsquerda];
    Planeta *vetorPlanetasDireita = new Planetas[quantidadeValoresDireita];

    for(int i=0;i<quantidadeValoresEsquerda;i++){
        vetorPlanetasEsquerda[i]=vetorPlanetas[esquerda+i];
    }

    for(int j=0;j<quantidadeValoresDireita;j++){
        vetorPlanetasDireita[j]=vetorPlanetas[meio+1+j];
    }

    int indiceEsquerda = 0;
    int indiceDireita = 0;
    int indiceMerge = esquerda;

    while(indiceEsquerda < quantidadeValoresEsquerda && indiceDireita < quantidadeValoresDireita){
        if(vetorPlanetasEsquerda[indiceEsquerda].getDistanciaPlaneta() == vetorPlanetasDireita[indiceDireita].getDistanciaPlaneta()){
            if(vetorPlanetasEsquerda[indiceEsquerda].getPopulacaoPlaneta() > vetorPlanetasDireita[indiceDireita].getPopulacaoPlaneta()){
                vetorPlanetas[indiceMerge]=vetorPlanetasEsquerda[indiceEsquerda];
                indiceEsquerda++;
            }else{
                vetorPlanetas[indiceMerge]=vetorPlanetasDireita[indiceDireita];
                indiceDireita++;
            }
        }else{
            if(vetorPlanetasEsquerda[indiceEsquerda].getPopulacaoPlaneta() < vetorPlanetasDireita[indiceDireita].getPopulacaoPlaneta()){
                vetorPlanetas[indiceMerge]=vetorPlanetasEsquerda[indiceEsquerda];
                indiceEsquerda++;
            }else{
                vetorPlanetas[indiceMerge]=vetorPlanetasDireita[indiceDireita];
                indiceDireita++;
            }
        }
        indiceMerge++;
    }

    while(indiceEsquerda < quantidadeValoresEsquerda){
        vetorPlanetas[indiceMerge] = vetorPlanetasEsquerda[indiceEsquerda];
        indiceMerge++;
        indiceEsquerda++;
    }

    while(indiceDireita < quantidadeValoresDireita){
        vetorPlanetas[indiceMerge] = vetorPlanetasEsquerda[indiceDireita];
        indiceMerge++;
        indiceDireita++;
    }

}

void ordenarVetor(int esquerda, int direita,Planeta vetorPlanetas[]){
    int meio =0;
    if(esquerda<direita){
        meio=(esquerda+direita)/2;
        ordenarVetor(esquerda,meio,vetorPlanetas);
        ordenarVetor(meio+1,direita,vetorPlanetas);

        merge(esquerda,meio,direita,vetorPlanetas);
    }
    


}

void printarVetor(Planeta vetorPlanetas[],int quantidadePlanetas){
    
    for(int i =0;i<quantidadePlanetas;i++){

        std::cout << vetorPlanetas[i].getNomePlaneta() << " " << vetorPlanetas[i].getDistanciaPlaneta() <<" " << vetorPlanetas[i].getPopulacaoPlaneta() << std::endl;

    }
}

int main() {

    int quantidadePlanetas = 0;
    std::string nomePlaneta = "";
    int distanciaPlaneta = 0;
    int populacaoPlaneta = 0;
    
    std::cin >> quantidadePlanetas;
    
    Planeta *vetorPlanetas = new Planeta[quantidadePlanetas];

    Planeta planeta = Planeta();

    for(int i =0;i<quantidadePlanetas;i++){

        std::cin >> nomePlaneta;
        std::cin >> distanciaPlaneta;
        std::cin >> populacaoPlaneta;

        planeta.setNomePlaneta(nomePlaneta);
        planeta.setDistanciaPlaneta(distanciaPlaneta);
        planeta.setPopulacaoPlaneta(populacaoPlaneta);

        vetorPlanetas[i] = planeta;

    }

    ordenarVetor(0,quantidadePlanetas-1,vetorPlanetas);

    printarVetor(vetorPlanetas,quantidadePlanetas);

    return 0;
}