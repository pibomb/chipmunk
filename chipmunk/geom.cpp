#include "geom.h"

#include <cmath>
#include <utility>

double chipmunk::dist(std::pair<double, double> p1, std::pair<double, double> p2) {
    return sqrt(pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2));
}

double chipmunk::dist(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
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

bool chipmunk::in_poly(std::vector<std::pair<double, double> > points, std::pair<double, double> test){
    bool c = 0;
    for(int i = 0, j = points.size()-1; i < points.size(); j = i++)
    {
        if( ((points[i].second > test.second) != (points[j].second > test.second)) &&
            (test.first < (points[j].first-points[i].first) * (test.second-points[i].second) / (points[j].second-points[i].second) + points[i].first) )
        {
            c = !c;
        }
    }
    return c;
}

bool chipmunk::in_poly(std::vector<double> vertx, std::vector<double> verty, double pointx, double pointy){
    bool c = 0;
    for(int i = 0, j = vertx.size()-1; i < vertx.size(); j = i++)
    {
        if( ((verty[i] > pointy) != (verty[j] > pointy)) &&
            (pointx < (vertx[j]-vertx[i]) * (pointy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) )
        {
            c = !c;
        }
    }
    return c;
}
