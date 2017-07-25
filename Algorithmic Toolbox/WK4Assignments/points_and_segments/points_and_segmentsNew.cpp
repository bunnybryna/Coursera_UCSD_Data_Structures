// this one exceeds the time limitation
// because the while + for loop
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void print(vector<int> v);
void printPair(vector<pair <int, char> > pchar);
vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points);
vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points);

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);

  for (size_t i = 0; i < starts.size(); i++)
    {
    std::cin >> starts[i] >> ends[i];
    }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  /*vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }*/
  vector<int> cntfast = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cntfast.size(); i++) {
    std::cout << cntfast[i] << ' ';
  }
}

void print(vector<int> v)
{
  for(size_t i = 0; i < v.size(); i++) std::cout << v[i] << " ";
  std::cout << std::endl;
}

void printPair(vector<pair <int, char> > pchar)
{
  for(size_t i = 0; i < pchar.size(); i++)
  {
     std::cout << "first is " << pchar[i].first << " second is " << pchar[i].second << std::endl;
  }
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  std::map<int,int> segments;
  for (size_t i = 0; i < starts.size(); i++)
  {
    segments[starts[i]] = ends[i];
  }
/*  for (std::map<int,int>::iterator it=segments.begin();it!=segments.end();it++)
  {
      std::cout << it->first << " =>" <<it->second<<std::endl;
  }*/
  vector<pair <int, char> >sortEverything;
  for (size_t i = 0; i< starts.size();i++)
  {
      sortEverything.push_back(make_pair(starts[i],'l'));
  }
  for (size_t i = 0; i< points.size();i++)
  {
      sortEverything.push_back(make_pair(points[i],'p'));
  }
  sort(sortEverything.begin(),sortEverything.end());
  //printPair(sortEverything);
  for (size_t i = 0;i<points.size();i++)
  {
      size_t j=0;
      int count = 0;
      int pointValue = points[i];
      while (j<sortEverything.size())
      {
          if ((sortEverything[j].first<=pointValue) &&
             (sortEverything[j].second== 'l')&&
             (segments[sortEverything[j].first]>=pointValue))
             count ++;
             //std::cout << "\ncount is now " << count;
          if (sortEverything[j].first>pointValue)
              break;
          j++;
      }
      //std::cout << "\ncount is now " << count;
      cnt[i]=count;
  }
  //print(cnt);
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}
