#include <vector>

namespace chipmunk {
	// Class for Point Update and Range Query Binary Indexed Tree
	class PURQ_BIT {
	// Size of the tree
	int SIZE;
	// Tree values
	std::vector<int> tree;
	public:
		// Constructor for BIT
		PURQ_BIT(int N);
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

	// Class for Range Update and Point Query Binary Indexed Tree
	class RUPQ_BIT {
	// Size of the tree
	int SIZE;
	// Tree values
	std::vector<int> tree;
	public:
		// Constructor for BIT
		RUPQ_BIT(int N);
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
	};

	// Class for Range Update and Range Query Binary Indexed Tree
	class RURQ_BIT {
	// Size of the tree
	int SIZE;
	// Tree values
	std::vector<int> tree[2];
	public:
		// Constructor for BIT
		RURQ_BIT(int N);
		// Get the frequency at a certain index
		int size();
		// Sum of frequencies up to idx
		int sum(int idx);
		// Add a value at a certain index rnage
		void update(int idx1, int idx2, int val);
	private:
		// Point query of selected tree
		int internal_at(int treenum, int idx);
		// Point update of selected tree
		void internal_update(int treenum, int idx, int val);
	};

	// Generates a bitmask with a number's greatest bit
	int greatestBit(int num);
}
