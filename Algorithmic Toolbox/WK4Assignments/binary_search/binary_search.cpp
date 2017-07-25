#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x);
int searchResult(const vector<int> &a, int x, int low, int high);
int linear_search(const vector<int> &a, int x);

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  /*for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << linear_search(a, b[i]) << ' ';
  }*/
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size()-1;

  return searchResult(a,x,left,right);

}

int searchResult(const vector<int> &a, int x, int low, int high)
{
    //std::cout << "x is " << x << " low is " << low << " high is " << high << std::endl;
    if (low > high)
    {
        return -1;
    }
    else if (low == high)
    {
        if (a[low] == x)
            return low;
        else
            return -1;
    }
    else
    {
        int mid = low + int((high-low)/2);
        //std::cout << " mid is " << mid << "\n";
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] > x)
        {
            return searchResult(a,x,low,mid-1);
        }
        else
        {
            return searchResult(a,x,mid+1,high);
        }
    }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}
