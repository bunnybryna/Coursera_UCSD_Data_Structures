#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b){
    if (a>=b)
    {
        // base case
        if (b == 0)
            return a;
        // recursive step
        else
        {
            int c = a%b;
            return gcd_fast(c, b);
        }
    }
    else
        return gcd_fast(b, a);

}
int gcd(int a, int b){
    if (a == b)
    {
        return a;
    }
    else if(a>b)
    {
        a = a-b;
        if (a==1)
            return 1;
        else
            return gcd(a,b);
    }
    else
    {
        b = b-a;
        return gcd(b,a);
    }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  // for big numbers, gcd is better
  std::cout << gcd(a, b) << std::endl;
  //std::cout << gcd_fast(a,b) << std:: endl;
  return 0;
}
