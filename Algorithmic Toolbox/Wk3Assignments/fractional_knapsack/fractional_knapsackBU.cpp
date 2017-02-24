#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  double weight = 0.0;
  vector<int> vPerUnit;
  for (int i=0;i<weights.size();i++)
  {
    vPerUnit[i]=values[i]/weights[i];
  }
  //printVector(vPerUnit);
  std::vector<int> sortVPU(vPerUnit);
  sort(sortVPU.begin(),sortVPU.end());
  //printVector(sortVPU);
  for (int i=0;i<sortVPU.size();i++)
  {
      if (capacity == 0)
          return value;
      // to find the item number match values[i] and weights[i]
      vector<int>::iterator it = std::find(vPerUnit.begin(),vPerUnit.end(),sortVPU[i]);
      if (it<vPerUnit.begin())
        std::cout<<"Wrong."<<std::endl;
      int item = std::distance(vPerUnit.begin(),it) ;
      std::cout << item<< std::endl;
      /*
      if (capacity >= weights[item])
      {
          weight = weight + weights[item];
          capacity = capacity - weights[item];
          value = value + values[item];
      }
      else
      {
          weight = weight + capacity;
          capacity = 0;
          value = value + vPerUnit[item] * capacity;
      }*/
  }

  return value;
}

void printVector(vector<int> l)
{
    vector<int>::iterator it;
    for(it=l.begin();it!=l.end();it++)
    {
        std::cout << *it << std::endl;
    }
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
