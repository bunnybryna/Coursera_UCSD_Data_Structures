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
  points.push_back(segmentsPair[segmentsPair.size()-1].first);
  int compareStart = segmentsPair[segmentsPair.size()-1].first;
  for (int i=segmentsPair.size()-1;i>=0;i--)
  {
        if (compareStart>segmentsPair[i-1].second)
        {
            points.push_back(segmentsPair[i-1].first);
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
