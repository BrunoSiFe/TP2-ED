#include <iostream>
#include <stdlib.h>
#define Troca(A, B) {Planeta c = A; A = B; B = c; }
#include "headers/planeta.hpp"
using namespace TP;

void partirVetor(int esquerda, int direita,
    int *i, int *j, Planeta vetorPlanetas[]){

    Planeta planetaAuxiliar1, planetaAuxiliar2;
    *i = esquerda; 
    *j = direita;
    planetaAuxiliar1 = vetorPlanetas[(*i + *j)/2];
    do{

        while ((planetaAuxiliar1.getDistanciaPlaneta() > vetorPlanetas[*i].getDistanciaPlaneta()) || (planetaAuxiliar1.getDistanciaPlaneta() == vetorPlanetas[*i].getDistanciaPlaneta() && planetaAuxiliar1.getPopulacaoPlaneta() > vetorPlanetas[*i].getPopulacaoPlaneta())) (*i)++;
        while ((planetaAuxiliar1.getDistanciaPlaneta() < vetorPlanetas[*j].getDistanciaPlaneta()) || (planetaAuxiliar1.getDistanciaPlaneta() == vetorPlanetas[*j].getDistanciaPlaneta() && planetaAuxiliar1.getDistanciaPlaneta() < vetorPlanetas[*j].getPopulacaoPlaneta())) (*j)--;
        
        if (*i <= *j){
            planetaAuxiliar2 = vetorPlanetas[*i];
            vetorPlanetas[*i] = vetorPlanetas[*j]; 
            vetorPlanetas[*j] = planetaAuxiliar2;
        (*i)++; 
        (*j)--;
        }

    } while (*i <= *j);
}

void ordenarVetor(int esquerda, int direita,Planeta vetorPlanetas[]){
    int i,j;
    partirVetor(esquerda, direita, &i, &j, vetorPlanetas);
    if (esquerda < j) ordenarVetor(esquerda, j, vetorPlanetas);
    if (i < direita) ordenarVetor(i, direita, vetorPlanetas);


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

    for(int i=0;i<quantidadePlanetas;i++){

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