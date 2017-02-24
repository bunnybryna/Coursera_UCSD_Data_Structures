#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product_naive(vector<int> a, vector<int> b) {
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

long long max_dot_product(vector<int> a, vector<int> b) {
  long long result = 0;
  sort(a.begin(),a.end(),std::greater<int>());
  /*for(std::vector<int>::iterator it=a.begin();it!=a.end();it++)
    {
        std::cout << *it << std::endl;
    }*/
  sort(b.begin(),b.end(),std::greater<int>());
  for (int i=0;i<a.size();i++)
  {
    result = result + (long long)((long long)a[i]*(long long)b[i]);
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  //std::cout << max_dot_product_naive(a, b) << std::endl;
  std::cout << max_dot_product(a, b) << std::endl;
}
