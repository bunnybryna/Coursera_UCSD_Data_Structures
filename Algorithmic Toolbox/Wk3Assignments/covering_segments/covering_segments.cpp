#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_points(vector<pair <int, int> > segments)
{
  vector<int> points;
  // first add the starting point of the last segment
  points.push_back(segments[segments.size()-1].first);
  int compareStart = segments[segments.size()-1].first;
  // note the pair is from small to large
  for (int i=segments.size()-1;i>=0;i--)
  {
        // compare each starting point to the ending point of the left segment
        // if ending point is left to the compareStart point
        // then add the starting point of the left segment to the Points vector
        // otherwise compareStart remains same and move to the next comparison
        if (compareStart>segments[i-1].second)
        {
            points.push_back(segments[i-1].first);
            //std::cout << " adding " << segments[i-1].first<< std::endl;
            // after add this point, move the compareStart to this point
            compareStart = segments[i-1].first;
        }
  }
  return points;
}

vector <pair <int, int> > segments;

int main() {
  int n, start, end;
  std::cin >> n;
  for (int i=0;i<n;i++) {
    std::cin >> start >> end;
    segments.push_back(make_pair(start,end));
  }
  sort(segments.begin(),segments.end());
  /*for (int i=0;i<n;i++)
  {
      std::cout << segments[i].first << " and " << segments[i].second << std::endl;
  }*/
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
