#include <iostream>

#include "geom.h"
#include "algebra.h"
#include "bit.h"
#include "boxunion.h"

using namespace std;

void test_geom() {
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
	cout << endl;
}

void test_algebra() {
	cout << "Testing: algebra" << endl;
	cout << endl;
	cout << "isPrime(2) " << chipmunk::isPrime(2) << endl;
	cout << "isPrime(4) " << chipmunk::isPrime(4) << endl;
	cout << "isPrime(21) " << chipmunk::isPrime(21) << endl;
	cout << "isPrime(91) " << chipmunk::isPrime(91) << endl;
	cout << endl;
	cout << "Prime Sieve to 500" << endl;
	chipmunk::PrimeSieve ps(500);
    vector<int> primes = ps.getPrimes();
    for(int p : primes)
    	cout << p << " ";
	cout << endl;
	cout << "GCD(24, 42) = " << chipmunk::gcd(24, 42) << endl;
	cout << "LCM(15, 9) = " << chipmunk::lcm(15, 9) << endl;
	cout << endl;
	cout << "mod(25, 3) = " << chipmunk::mod(25, 3) << endl;
	cout << "LCM(-25, 3) = " << chipmunk::mod(-25, 3) << endl;
	cout << endl;
	cout << "10! = " << chipmunk::factorial(10) << endl;
	cout << "100!/96! = " << chipmunk::factorialDiv(100, 96) << endl;
	cout << "16C4 = " << chipmunk::nCr(16, 4) << endl;
	cout << "16P4 = " << chipmunk::nPr(16, 4) << endl;
	cout << endl;
}

void test_bit() {
	cout << "Testing: bit" << endl;
	cout << endl;

	cout << "Initializing RUPQ BIT" << endl;
	chipmunk::RUPQ_BIT b(5);

    cout << "update(1, 3, 100)" << endl;
	b.update(1, 3, 100);
	cout << "update(2, 4, 22)" << endl;
	b.update(2, 4, 2);

	for(int i = 1; i <= b.size(); i++) {
		cout << b.at(i) << " ";
	}
	cout << endl;
}

void test_boxunion() {
	cout << "Testing: boxunion" << endl;
	cout << endl;

	cout << "Using rectangles:" << endl;
	vector<chipmunk::Rectangle> rects;
	cout << "(0, 0) , (5, 5)" << endl;
	rects.push_back(make_pair(make_pair(0, 0), make_pair(5, 5)));
	cout << "(4, 4) , (6, 6)" << endl;
	rects.push_back(make_pair(make_pair(4, 4), make_pair(6, 6)));
	cout << "(5, 5) , (6, 7)" << endl;
	rects.push_back(make_pair(make_pair(5, 5), make_pair(6, 7)));

	cout << chipmunk::union_area(rects) << endl;
}

int main() {
	//test_geom();
	//test_algebra();
	//test_bit();
	test_boxunion();

	return 0;
}


