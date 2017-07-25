#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> a);
bool compare(string a,string b);

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}

string largest_number(vector<string> a) {
  sort(a.begin(),a.end(),compare);
  /*for (int i=0;i<a.size();i++)
  {
      std::cout << "After sorted " << a[i] << std::endl;
  }*/
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

bool compare(string a,string b)
{
    if (a+b>b+a)
        return true;
    else
        return false;
}
