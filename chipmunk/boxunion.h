#include <vector>

namespace chipmunk {
	// Rectangle as defined by the starting and ending coordinates
	typedef std::pair<std::pair<int, int>, std::pair<int, int> > Rectangle;

	// Finds total area covered by a list of rectangles
	long long union_area(std::vector<Rectangle> rects);
}
