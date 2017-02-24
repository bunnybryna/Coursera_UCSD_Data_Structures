#include <iostream>

int get_change(int m) {
  int num10,num5,num1;
  while (m>0)
  {
      num10 = int(m/10);
      m = m-(10*num10);
      num5 = int(m/5);
      m = m-(5*num5);
      num1 = int(m/1);
      m = m-(num1);
  }
  return (num10 + num5 + num1);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
