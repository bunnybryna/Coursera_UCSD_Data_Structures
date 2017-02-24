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
  // create two vectors, one to sort, the other stays same to find matching index for segments
  vector<int> startPoints, startPointsSort;
  for (size_t i=0;i<segments.size();i++)
  {
        startPoints.push_back(segments[i].start);
  }
  /*for (std::vector<int>::iterator it=startPoints.begin();it!=startPoints.end();it++)
  {
      std::cout <<"Start Points are " <<*it << std::endl;
  }*/
  // sort startPointsSort to find the biggest starting point
  for (size_t i=0;i<segments.size();i++)
  {
        startPointsSort.push_back(segments[i].start);
  }
  sort(startPointsSort.begin(),startPointsSort.end(),std::greater<int>());
  /*for (std::vector<int>::iterator it=startPointsSort.begin();it!=startPointsSort.end();it++)
  {
      std::cout <<"After sorted " <<*it << std::endl;
  }*/
  points.push_back(startPointsSort[0]);
  int compareStart = startPointsSort[0];
  for (size_t i=0;i<startPointsSort.size()-1;i++)
  {
        std::cout << "start point is " << startPointsSort[i];
        std::cout << "compareStart is " << compareStart << " i is " << i;
        // compareStart=startPointSort[0]=5,startPointSort[i+1]=4=>matching ending point=7
        vector<int>:: iterator it=std::find(startPoints.begin(),startPoints.end(),startPointsSort[i+1]);
        int index = std::distance(startPoints.begin(),it);
        // segments[index].end=7
        std::cout <<"compare " << compareStart << " to the ending point " << segments[index].end << std::endl;
        // if ending point is left to the compareStart point, then add the starting point matched the ending point to the Points vector
        // otherwise compareStart remains same
        if (compareStart>segments[index].end)
        {
            points.push_back(startPointsSort[i+1]);
            std::cout << " adding " << startPointsSort[i+1]<< std::endl;
            // after add this point, move the compareStart to this point
            compareStart = startPointsSort[i+1];
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
  //std::cout << " are the optimal points." << std::endl;
}
