#include <vector>

namespace chipmunk {
	// Class for Binary Indexed Tree
	class BIT {
	// Size of the tree
	int SIZE;
	// Tree values
	std::vector<int> tree;
	public:
		// Constructor for BIT
		BIT(int N);
		// Get the frequency at a certain index
		int at(int idx);
		// Set the size of the tree
		int size();
		// Sum of frequencies up to idx
		int sum(int idx);
		// Add a value at a certain index
		void update(int idx, int val);
		// Add a value at a certain index rnage
		void update(int idx1, int idx2, int val);
		// Scale the tree by a factor
		void scale(int c);
		// Find index of a certain cumulative frequency
		int find(int cumFre);
		// Find greatest index with a certain cumulative frequency
		int findG(int cumFre);
	};

	// Generates a bitmask with a number's greatest bit
	int greatestBit(int num);
}
