#include "boxunion.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <unordered_map>

// Stuct for a line events for line sweep
struct line {
	int x, y1, y2, dir;
	line(int a, int b, int c, int d) : x(a), y1(b), y2(c), dir(d) {}
};

// Compare function for line
bool line_cmp(const line &a, const line &b) {
	return a.x < b.x;
}

long long chipmunk::union_area(std::vector<chipmunk::Rectangle> rects) {
	long long ans = 0;

	std::set<int> y; // Set for important y values
	std::vector<line> lines; // Vector of line events
	std::unordered_map<int, int> yindex; // Map gets index of y from y value

	for(int i = 0; i < rects.size(); i++) {
		int x1 = rects[i].first.first;
		int y1 = rects[i].first.second;
		int x2 = rects[i].first.first;
		int y2 = rects[i].first.second;

		y.insert(y1);
		y.insert(y2);
		lines.push_back(line(x1, std::min(y1, y2), std::max(y1, y2), 1));
		lines.push_back(line(x1, std::min(y1, y2), std::max(y1, y2), -1));
	}

	// Sort the vertical line segments
	sort(lines.begin(), lines.end(), line_cmp);

	// Maps values of y to their indices
	for(int i = 0; i < y.size(); i++) {
		std::set<int>::iterator iter = y.begin();
		std::advance(iter, i);
		int yval = *iter;
		yindex[yval] = i;
	}

	// The sweeping line
	int yaxis[y.size()-1];
	memset(yaxis, 0, y.size()-1);

	// TODO

	return ans;
}
