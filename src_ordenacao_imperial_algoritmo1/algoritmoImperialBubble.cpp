#include <iostream>
#include <cstdlib>
#include <string>
#define Troca(A, B) {Planeta c = A; A = B; B = c; }
#include "headers/planeta.hpp"

using namespace TP;

void ordenarVetor(Planeta vetorPlanetas[],int quantidadePlanetas){
    for(int i=0;i<quantidadePlanetas-1;i++){
        for(int j=quantidadePlanetas-1;j>i;j--){

            if(vetorPlanetas[j-1].getDistanciaPlaneta() > vetorPlanetas[j].getDistanciaPlaneta()){
                Troca(vetorPlanetas[j-1],vetorPlanetas[j]);

            }else if(vetorPlanetas[j-1].getDistanciaPlaneta() == vetorPlanetas[j].getDistanciaPlaneta()){
                if(vetorPlanetas[j-1].getPopulacaoPlaneta() > vetorPlanetas[j].getPopulacaoPlaneta()){
                    Troca(vetorPlanetas[j-1],vetorPlanetas[j]);
                }
            }

        }
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
    
    Planeta vetorPlanetas[quantidadePlanetas];

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

    ordenarVetor(vetorPlanetas,quantidadePlanetas);

    printarVetor(vetorPlanetas,quantidadePlanetas);

    return 0;
}