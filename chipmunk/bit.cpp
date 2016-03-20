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

int chipmunk::BIT::find(int cumFre) {
	int bitMask = chipmunk::greatestBit(SIZE);
	int idx = 0; // this var is result of function

    while((bitMask != 0) && (idx < MaxVal)){ // nobody likes overflow :)
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

int chipmunk::findG(int cumFre){
    int bitMask = chipmunk::greatestBit(SIZE);
    int idx = 0;

    while ((bitMask != 0) && (idx < MaxVal)){
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

int chipmunk::greatestBit(int num) {
	if(!num)
		return 0;

	int ret = 1;

	while (num >>= 1)
		ret <<= 1;

	return ret;
}
