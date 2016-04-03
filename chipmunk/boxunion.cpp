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

	std::set<int> y_set; // Set for important y values
	std::vector<int> y;
	std::vector<line> lines; // Vector of line events
	std::unordered_map<int, int> yindex; // Map gets index of y from y value

	for(int i = 0; i < rects.size(); i++) {
		int x1 = rects[i].first.first;
		int y1 = rects[i].first.second;
		int x2 = rects[i].second.first;
		int y2 = rects[i].second.second;

		y_set.insert(y1);
		y_set.insert(y2);
		lines.push_back(line(std::min(x1, x2), std::min(y1, y2), std::max(y1, y2), 1));
		lines.push_back(line(std::max(x1, x2), std::min(y1, y2), std::max(y1, y2), -1));
	}

	// Sort the vertical line segments
	std::sort(lines.begin(), lines.end(), line_cmp);
	std::copy(y_set.begin(), y_set.end(), std::back_inserter(y));

	// Maps values of y to their indices
	for(int i = 0; i < y.size(); i++) {
		yindex[y[i]] = i;
	}

	// The sweeping line
	chipmunk::RUPQ_BIT yaxis(y.size()-1);
	yaxis.update(yindex[lines[0].y1]+1, yindex[lines[0].y2], lines[0].dir);

	for(int i = 1; i < lines.size(); i++) {

		for(int j = 1; j <= yaxis.size(); j++) {
			if(yaxis.at(j) > 0) {
				ans += (lines[i].x - lines[i-1].x) * (y[j] - y[j-1]);
			}
		}

		yaxis.update(yindex[lines[i].y1]+1, yindex[lines[i].y2], lines[i].dir);
	}

	return ans;
}
