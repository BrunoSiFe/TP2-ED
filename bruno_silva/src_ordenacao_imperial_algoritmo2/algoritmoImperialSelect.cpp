#include <iostream>
#include <cstdlib.h>
#define Troca(A, B) {Planeta c = A; A = B; B = c; }
#include "headers/planeta.hpp"

using namespace TP;

void ordenarVetor(Planeta vetorPlanetas[],int quantidadePlanetas){
    int min =0;
    for(int i=0;i<quantidadePlanetas-1;i++){
        min = i;
        for(int j=i-1;j<quantidadePlanetas;j++){

            if(vetorPlanetas[j].getDistanciaPlaneta() > vetorPlanetas[min].getDistanciaPlaneta()){
                Troca(vetorPlanetas[j],vetorPlanetas[min]);

            }else if(vetorPlanetas[j].getDistanciaPlaneta() == vetorPlanetas[min].getDistanciaPlaneta()){
                if(vetorPlanetas[j].getPopulacaoPlaneta() > vetorPlanetas[min].getPopulacaoPlaneta()){
                    Troca(vetorPlanetas[j],vetorPlanetas[min]);
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