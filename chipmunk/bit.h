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
		// Sum of frequencies up to idx
		int sum(int idx);
		// Assign a value at a certain index
		void assign(int idx, int val);
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
