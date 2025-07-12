#include <cmath>
#include "calcDistance.h"

// Implementação da haversine usada para capturar a posição dos corretores/avaliadores
 double haversine(double lat1, double lon1, double lat2, double lon2){
    
    // Função lambda para converter graus em radianos
    auto deg2rad = [](double d) { return d * M_PI / 180.0; };

    // Diferença das latitudes e longitudes em radianos
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    
    // Cálculo da fórmula de Haversine
    double a = pow(sin(dlat / 2), 2) +
               cos(deg2rad(lat1)) * 
               cos(deg2rad(lat2)) *
               pow(sin(dlon / 2), 2);

    // Cálculo do ângulo central entre os dois pontos
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    // Retorna a distância em quilômetros multiplicado pelo raio da Terra
    return EARTH_R * c; 
}
