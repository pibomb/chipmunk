#include "geom.h"

#include <cmath>
#include <utility>

double chipmunk::dist(std::pair<double, double> p1, std::pair<double, double> p2) {
    return std::sqrt(pow(p1.first-p2.first, 2) + std::pow(p1.second-p2.second, 2));
}

double chipmunk::dist(double x1, double y1, double x2, double y2) {
	return std::sqrt(pow(x1-x2, 2) + std::pow(y1-y2, 2));
}

double chipmunk::manhattan_dist(std::pair<double, double> p1, std::pair<double, double> p2) {
    return std::abs(p1.first - p2.first) + std::abs(p1.second - p2.second);
}

double chipmunk::manhattan_dist(double x1, double y1, double x2, double y2) {
	return std::abs(x1 - x2) + std::abs(y1 - y2);
}

double chipmunk::area(std::vector<std::pair<int, int> > points) {
    double area = 0;
    int size = points.size();
    for(int i = 0; i < size; i++)
    {
        area += cross(points[i], points[(i + 1) % size]);
    }
    area /= 2;
    return std::abs(area);
}

double chipmunk::perimeter(std::vector<std::pair<int, int> > points) {
    double perim = 0;
    int size = points.size();
    for(int i = 0; i < size; i++)
    {
        perim += dist(points[i], points[(i + 1) % size]);
    }

    return perim;
}
