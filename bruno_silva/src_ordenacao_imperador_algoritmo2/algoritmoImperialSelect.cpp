#include <iostream>
#include <stdlib.h>
#define Troca(A, B)    \
    {                  \
        Planeta c = A; \
        A = B;         \
        B = c;         \
    }
#include "headers/planeta.hpp"

using namespace TP;

void ordenarVetor(Planeta vetorPlanetas[], int quantidadePlanetas)
{
    int min = 0;
    for (int i = 0; i < quantidadePlanetas - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < quantidadePlanetas; j++)
        {

            if (vetorPlanetas[j].getDistanciaPlaneta() < vetorPlanetas[min].getDistanciaPlaneta())
            {
                min = j;
            }
            else
            {
                if (vetorPlanetas[j].getDistanciaPlaneta() == vetorPlanetas[min].getDistanciaPlaneta())
                {
                    if (vetorPlanetas[j].getPopulacaoPlaneta() > vetorPlanetas[min].getPopulacaoPlaneta())
                    {
                        min = j;
                    }
                }
            }
        }
        Troca(vetorPlanetas[i], vetorPlanetas[min]);
    }
}

void printarVetor(Planeta vetorPlanetas[], int quantidadePlanetas)
{

    for (int i = 0; i < quantidadePlanetas; i++)
    {

        std::cout << vetorPlanetas[i].getNomePlaneta() << " " << vetorPlanetas[i].getDistanciaPlaneta() << " " << vetorPlanetas[i].getPopulacaoPlaneta() << std::endl;
    }
}

int main()
{

    time_t start, end;

    time(&start);

    int quantidadePlanetas = 0;
    std::string nomePlaneta = "";
    int distanciaPlaneta = 0;
    int populacaoPlaneta = 0;

    std::cin >> quantidadePlanetas;

    Planeta *vetorPlanetas = new Planeta[quantidadePlanetas];

    Planeta planeta = Planeta();

    for (int i = 0; i < quantidadePlanetas; i++)
    {

        std::cin >> nomePlaneta;
        std::cin >> distanciaPlaneta;
        std::cin >> populacaoPlaneta;

        planeta.setNomePlaneta(nomePlaneta);
        planeta.setDistanciaPlaneta(distanciaPlaneta);
        planeta.setPopulacaoPlaneta(populacaoPlaneta);

        vetorPlanetas[i] = planeta;
    }

    ordenarVetor(vetorPlanetas, quantidadePlanetas);

    printarVetor(vetorPlanetas, quantidadePlanetas);

    time(&end);

    double time_taken = double(end - start);
    std::cout << "Time taken by program is : " << std::fixed
              << time_taken;
    std::cout << " sec " << std::endl;

    return 0;
}