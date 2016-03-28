#include <cassert>
#include <cmath>
#include <vector>

#include "algebra.h"

bool chipmunk::isPrime(int n) {
	if(n <= 1)
		return false;
	if(n == 2)
		return true;
	if(n % 2 == 0) // Added so loop checks odd numbers
		return false;

	int m = (int)sqrt(n); // Check to the square root

	for(int i = 3; i <= m; i+=2) {
		if(n % i == 0)
			return false;
	}

	return true;
}

chipmunk::PrimeSieve::PrimeSieve(int N) {
	prime = new bool[N+1];
	prime[0] = prime[1] = false;
	for(int i = 2; i < N+1; i++)
		prime[i] = true;
	int m = (int)sqrt(N);

	for(int p = 2; p <= m; p++) {
		if(prime[p]) {
			// Set all multiples as not prime
			for(int c = p*p; c <= N; c+=p)
				prime[c] = false;
		}
	}

	SIZE = N;
}

bool chipmunk::PrimeSieve::isPrime(int x) {
	return prime[x];
}

std::vector<int> chipmunk::PrimeSieve::getPrimes() {
	std::vector<int> v;
	for(int i = 0; i <= SIZE; i++)
		if(prime[i])
			v.push_back(i);

	return v;
}

// Using Euclid's algorithm for GCD
int chipmunk::gcd(int a, int b) {
	assert(!(a == 0 && b == 0));

	if(b == 0)
		return a;
	return gcd(b, a%b);
}

// Uses GCD function
int chipmunk::lcm(int a, int b) {
	return b*a/gcd(a, b);
}

int chipmunk::mod(int a, int b) {
	return (a < 0) ? (b+(a%b)) : (a%b);
}

unsigned long long chipmunk::factorial(int n) {
	return factorialDiv(n, 0);
}

unsigned long long chipmunk::factorialDiv(int n, int d) {
	unsigned long long ans = 1;
	for(int i = n; i > d; i--)
		ans *= i;
	return ans;
}

unsigned long long chipmunk::nCr(int n, int r) {
	return nPr(n, r) / factorial(r);
}

unsigned long long chipmunk::nPr(int n, int r) {
	return factorialDiv(n, n-r);
}
