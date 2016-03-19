#include <vector>

#include "bit.h"

chipmunk::BIT::BIT(int N) {
	SIZE = N;
	tree = std::vector<int>(N);
}

int chipmunk::BIT::at(int idx) {
	int sum = tree[idx];
	if(idx > 0) {
		int z = idx - (idx & -idx);
		idx--;
		while(idx != z) {
			sum -= tree[idx];
			idx -= (idx & -idx);
		}
	}
	return sum;
}

int chipmunk::BIT::sum(int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void chipmunk::BIT::assign(int idx, int val) {
	while(idx <= MaxVal) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

void chipmunk::BIT::scale(int c) {
	for(int i = 1; i < SIZE; i++)
		tree[i] = tree[i] / c;
}
