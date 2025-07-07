#include <cmath>
#include "calcDistance.h"
using namespace std;

double haversine(double lat1, double lon1, double lat2, double lon2){
    auto deg2rad = [](double d) { return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = pow(sin(dlat / 2), 2) +
               cos(deg2rad(lat1)) * cos(deg2rad(lat2)) *
               pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_R * c;
}
