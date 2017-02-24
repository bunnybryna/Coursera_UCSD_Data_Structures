#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments)
{
  vector<int> points;
  vector<std::pair <int, int> > segmentsPair;
  for (size_t i=0;i<segments.size();i++) {
    segmentsPair.push_back(std::make_pair(segments[i].start,segments[i].end));
  }
  sort(segmentsPair.begin(),segmentsPair.end());
  // first add the starting point of the last segment
  points.push_back(segmentsPair[segmentsPair.size()-1].first);
  int compareStart = segmentsPair[segmentsPair.size()-1].first;
  // note the pair is from small to large
  for (int i=segmentsPair.size()-1;i>=0;i--)
  {
        // compare each starting point to the ending point of the left segment
        // if ending point is left to the compareStart point
        // then add the starting point of the left segment to the Points vector
        // otherwise compareStart remains same and move to the next comparison
        if (compareStart>segmentsPair[i-1].second)
        {
            points.push_back(segmentsPair[i-1].first);
            //std::cout << " adding " << segmentsPair[i-1].first<< std::endl;
            // after add this point, move the compareStart to this point
            compareStart = segmentsPair[i-1].first;
        }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
