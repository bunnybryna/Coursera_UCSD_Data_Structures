#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

void randomized_quick_sort(vector<int> &a, int l, int r);
int partition2(vector<int> &a, int l, int r);
int partition3(vector<int> &a, int l, int r);

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void partition3(vector<int> &a, int l, int r, int &m1, int &m2){
  int x = a[l];
  int j = l;
  int k = l;
  int n = l;
  for (int i = l + 1; i <= r; i++) {
    std::cout << "x is " << x << std::endl;
    std::cout << "a[i] is " << a[i] << std::endl;
    if (a[i] < x)
    {
      if (j!= k)
      {
          j++;
          swap(a[i], a[j]);

          k++;
          swap(a[i],a[k]);
      }
      else
      {
          j++;
          swap(a[i],a[j]);
          k = j;
      }
      for (int n=l;n<=r;n++)
      {
          std::cout << "after swap [i] and [j] & [i] and [k] " << a[n]<< "\n" ;
      }
    }
    else if(a[i] == x)
    {
      k++;
      swap(a[i],a[k]);
      for (int n=l;n<=r;n++)
      {
          std::cout << "after swap [i] and [k] " << a[n]<< "\n" ;
      }
    }
  }
  swap(a[l], a[j]);
  m1 = j;
  m2 = k;
  std::cout << "m1 and m2 " << m1 << m2 << std::endl;
  //return j;
      for (int n=l;n<=r;n++)
      {
          std::cout << a[n]<<std::endl;
      }
}


void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  int k = l + rand() % (r - l + 1);
  std::cout << " k is " << k << std::endl;
  swap(a[l], a[k]);
  int m1=0,m2=0;
  partition3(a, l, r, m1, m2);
  std::cout << " m1 is " << m1 << " m2 is " << m2 << std::endl;
  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
}
