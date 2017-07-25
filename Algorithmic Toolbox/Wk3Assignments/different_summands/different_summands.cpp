#include <iostream>
#include <vector>

using std::vector;


vector<int> optimal_summands(int n) ;
vector<int> summandsFunction(int k,int l,vector<int> &sumVec);

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}

vector<int> optimal_summands(int n) {
  vector<int> summands;
  summands = summandsFunction(n,1,summands);
  return summands;
}

vector<int> summandsFunction(int k,int l,vector<int> &sumVec)
{
    if (k<= 2*l)
    {
        sumVec.push_back(k);
        return sumVec;
    }
    else
    {
        sumVec.push_back(l);
        return summandsFunction(k-l,l+1,sumVec);
    }
}
