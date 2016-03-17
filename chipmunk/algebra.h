#include <vector>

namespace chipmunk {
	// Checks if a number is prime
	bool isPrime(int n);

	// Class for prime number sieve
	class PrimeSieve {
	int SIZE;
	bool* prime;
	public:
		// Generates a sieve with specified size
		PrimeSieve(int N);
		// Check if number is prime
		bool isPrime(int x);
		// Returns a list of prime numbers from sieve
		std::vector<int> getPrimes();
		// Getter for SIZE
		int getSize();
	};

	// Greatest Common Divisor
	int gcd(int a, int b);
	// Least Common Multiple
	int lcm(int a, int b);

	// Mod operator including negative values
	int mod(int a, int b);
}
