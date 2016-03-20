#include <utility>
#include <vector>

namespace chipmunk {
	// Computes the dot product of two 2D vectors
	template<typename T> inline T const& dot(std::pair<T, T> const& p1, std::pair<T, T> const& p2) {
		return p1.first * p2.first + p1.second * p2.second;
	}

	template<typename T> inline T const& dot(T const& x1, T const& y1, T const& x2, T const& y2) {
		return x1 * x2 + y1 * y2;
	}

	// Computes the cross product of two 2D vectors
	template<typename T> inline T const& cross(std::pair<T, T> const& p1, std::pair<T, T> const& p2) {
		return p1.first * p2.second - p1.second * p2.first;
	}

	template<typename T> inline T const& cross(T const& x1, T const& y1, T const& x2, T const& y2) {
		return x1 * y2 - y1 * x2;
	}

	// Distance between two points
	double dist(std::pair<double, double> p1, std::pair<double, double> p2 = std::make_pair(0, 0));
	double dist(double x1, double y1, double x2 = 0, double y2 = 0);

	// Area of a polygon
	double area(std::vector<std::pair<int, int> > points);
}
