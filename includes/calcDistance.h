#ifndef OBTEMDISTANCIA_H
#define OBTEMDISTANCIA_H

constexpr double EARTH_R = 6371.0;

double haversine(double lat1, double lon1, double lat2, double lon2);

#endif
