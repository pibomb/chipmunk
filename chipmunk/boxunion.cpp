#include "boxunion.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <unordered_map>

#include "bit.h"

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
		lines.push_back(line(x2, std::min(y1, y2), std::max(y1, y2), -1));
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
	chipmunk::RUPQ_BIT yaxis(y.size()-1);
	yaxis.update(yindex[lines[0].y1]+1, yindex[lines[0].y2]+1, lines[0].dir);

	for(int i = 1; i < lines.size(); i++) {
		for(int j = 1; j <= yaxis.size(); j++) {
			if(yaxis.at(j) > 0) {
				std::set<int>::iterator iter1 = y.begin();
				std::set<int>::iterator iter2 = y.begin();
				std::advance(iter1, j-1);
				std::advance(iter2, j);
				ans += (lines[i].x - lines[i-1].x) * (*iter2 - *iter1);
			}
		}

		yaxis.update(yindex[lines[i].y1]+1, yindex[lines[i].y2]+1, lines[i].dir);
	}

	return ans;
}
