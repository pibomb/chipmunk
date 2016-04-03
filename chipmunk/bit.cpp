#include <vector>

#include "bit.h"

chipmunk::PURQ_BIT::PURQ_BIT(int N) {
	SIZE = N;
	tree = std::vector<int>(N+1);
}

int chipmunk::PURQ_BIT::at(int idx) {
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

int chipmunk::PURQ_BIT::size() {
	return SIZE;
}

int chipmunk::PURQ_BIT::sum(int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void chipmunk::PURQ_BIT::update(int idx, int val) {
	while(idx <= SIZE) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

void chipmunk::PURQ_BIT::update(int idx1, int idx2, int val) {
	while(idx1 <= idx2) {
		update(idx1, val);
		idx1++;
	}
}

void chipmunk::PURQ_BIT::scale(int c) {
	for(int i = 1; i < SIZE; i++)
		tree[i] = tree[i] / c;
}

int chipmunk::PURQ_BIT::find(int cumFre) {
	int bitMask = chipmunk::greatestBit(SIZE);
	int idx = 0; // this var is result of function

    while((bitMask != 0) && (idx < SIZE)){ // nobody likes overflow :)
        int tIdx = idx + bitMask; // we make midpoint of interval
        if (cumFre == tree[tIdx]) // if it is equal, we just return idx
            return tIdx;
        else if (cumFre > tree[tIdx]){
                // if tree frequency "can fit" into cumFre,
                // then include it
            idx = tIdx; // update index
            cumFre -= tree[tIdx]; // set frequency for next loop
        }
        bitMask >>= 1; // half current interval
    }
    if (cumFre != 0) // maybe given cumulative frequency doesn't exist
        return -1;
    else
        return idx;
}

int chipmunk::PURQ_BIT::findG(int cumFre){
    int bitMask = chipmunk::greatestBit(SIZE);
    int idx = 0;

    while ((bitMask != 0) && (idx < SIZE)){
        int tIdx = idx + bitMask;
        if (cumFre >= tree[tIdx]){
                // if current cumulative frequency is equal to cumFre,
                // we are still looking for higher index (if exists)
            idx = tIdx;
            cumFre -= tree[tIdx];
        }
        bitMask >>= 1;
    }
    if (cumFre != 0)
        return -1;
    else
        return idx;
}

chipmunk::RUPQ_BIT::RUPQ_BIT(int N) {
	SIZE = N;
	tree = std::vector<int>(N+1);
}

int chipmunk::RUPQ_BIT::at(int idx) {
	int sum = 0;

	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & - idx);
	}

	return sum;
}

int chipmunk::RUPQ_BIT::size() {
	return SIZE;
}

int chipmunk::RUPQ_BIT::sum(int idx) {
	int sum = 0;

	while(idx > 0) {
		sum += at(idx);
		idx--;
	}

	return sum;
}

void chipmunk::RUPQ_BIT::update(int idx, int val) {
	while(idx <= SIZE) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

void chipmunk::RUPQ_BIT::update(int idx1, int idx2, int val) {
	update(idx1, val);
	update(idx2 + 1, -val);
}

chipmunk::RURQ_BIT::RURQ_BIT(int N) {
	SIZE = N;
	tree[0] = std::vector<int>(N+1);
	tree[1] = std::vector<int>(N+1);
}

int chipmunk::RURQ_BIT::size() {
	return SIZE;
}

int chipmunk::RURQ_BIT::sum(int idx) {
	return internal_at(0, idx) * idx - internal_at(1, idx);
}

void chipmunk::RURQ_BIT::update(int idx1, int idx2, int val) {
	internal_update(0, idx1, val);
	internal_update(0, idx2 + 1, -val);
	internal_update(1, idx1, val * (idx1 - 1));
	internal_update(1, idx2 + 1, -val * idx2);
}

int chipmunk::RURQ_BIT::internal_at(int treenum, int idx) {
	int sum = 0;

	while(idx) {
		sum += tree[treenum][idx];
		idx -= (idx & - idx);
	}

	return sum;
}

void chipmunk::RURQ_BIT::internal_update(int treenum, int idx, int val) {
	while(idx <= SIZE) {
		tree[treenum][idx] += val;
		idx += (idx & - idx);
	}
}

int chipmunk::greatestBit(int num) {
	if(!num)
		return 0;

	int ret = 1;

	while (num >>= 1)
		ret <<= 1;

	return ret;
}
