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

int partition3(vector<int> &a, int l, int r){
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
    

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  int k = l + rand() % (r - l + 1);
  std::cout << " k is " << k << std::endl;
  swap(a[l], a[k]);
  int m = partition2(a, l, r);
  std::cout << " m is " << m << std::endl;
  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}
