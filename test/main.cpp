#include <iostream>

#include "geom.h"

using namespace std;

int main() {
	cout << "Testing: geom" << endl;
	cout << endl;
	cout << "Dot Product" << endl;
	cout << "(5, 3) * (7, 3) = " << chipmunk::dot(make_pair(5, 3), make_pair(7, 3)) << endl;
	cout << "(5, 3) * (7, 3) = " << chipmunk::dot(5, 3, 7, 3) << endl;
	cout << endl;
	cout << "Cross Product" << endl;
	cout << "(5, 3) x (7, 3) = " << chipmunk::cross(make_pair(5, 3), make_pair(7, 3)) << endl;
	cout << "(5, 3) x (7, 3) = " << chipmunk::cross(5, 3, 7, 3) << endl;
	cout << endl;
	cout << "Distance" << endl;
	cout << "dist(3, 4) = " << chipmunk::dist(3, 4) << endl;
	cout << "dist((3, 4), (5, 2)) = " << chipmunk::dist(make_pair(3, 4), make_pair(5, 2)) << endl;
	cout << "dist(3, 4, 5, 2) = " << chipmunk::dist(3, 4, 5, 2) << endl;

	return 0;
}
