#include "geom.h"

#include <cmath>
#include <utility>

double chipmunk::dist(std::pair<double, double> p1, std::pair<double, double> p2) {
    return sqrt(pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2));
}

double chipmunk::dist(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}
