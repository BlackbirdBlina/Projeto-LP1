#ifndef OBTEMDISTANCIA_H
#define OBTEMDISTANCIA_H

// Raio da terra em Km
constexpr double EARTH_R = 6371.0;

// Fórmula para calcular a distância entre dois pontos na superfície da Terra
double haversine(double lat1, double lon1, double lat2, double lon2);
// lat1 = Latitude do primeiro ponto
// lon1 = Longitude do primeiro ponto
// lat2 = Latitude do segundo ponto
// lon2 = Longitude do segundo ponto

#endif
