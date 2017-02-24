//LCM(a,b)*GCD(a,b)=a*b
#include <iostream>
// second algorithm for gcd
long long gcd(int a, int b){
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
        if (b==1)
            return 1;
        else
            return gcd(b,a);
    }
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b){
    if (a==1)
        return b;
    else if (b==1)
        return a;
    else if ((a==0)||(b==0))
        return 0;
    else
    {
        long long mul = (long long) a * b;
        long long gcdF = gcd(a,b);
        return (long long)(mul/gcdF);
    }
}
int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a,b) << std::endl;

  return 0;
}
