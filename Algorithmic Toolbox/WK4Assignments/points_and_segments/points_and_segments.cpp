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
  // points is not sorted {-100,100,0}, need to built a bridge between points and cnt
  std::map<int, int> cntMap;
  vector<pair <int, char> >sortEverything;
  for (size_t i = 0; i< starts.size();i++)
  {
      sortEverything.push_back(make_pair(starts[i],'l'));
      sortEverything.push_back(make_pair(ends[i],'r'));
  }
  for (size_t i = 0; i< points.size();i++)
  {
      sortEverything.push_back(make_pair(points[i],'p'));
  }
  sort(sortEverything.begin(),sortEverything.end());
  //printPair(sortEverything);
 /* for example: sortEverything = {(2,l),(3,p),(4,l),(5,l),(5,p),(6,r),(7,r),(8,p),(10,r)}
  * just like counting open brackets, whenever encounters a 'l', count+1
  * encounters a 'r', count-1,
  * and encounters a 'p', push count to the cnt vector
  * cnt = {1,3,1} this way, only scan one time of the vector, log(n)
  */
  int count = 0;
  for (size_t i = 0;i<sortEverything.size();i++)
  {
      if (sortEverything[i].second == 'l')
      {
         count ++;
      }
      else if(sortEverything[i].second == 'r')
      {
          count --;
      }
      else
      {
          cntMap[sortEverything[i].first]=count;
      }
  }
  for (size_t i=0;i<points.size();i++)
  {
      cnt[i]=cntMap[points[i]];
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
