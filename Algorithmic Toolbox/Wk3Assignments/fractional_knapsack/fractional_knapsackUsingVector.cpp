#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
// iomanip=>setf,algorithm=>sort

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  double weight = 0.0;
  vector<double> vPerUnit;
  for (int i=0;i<weights.size();i++)
  {
    // int/int=int,int/double = double
    vPerUnit.push_back(values[i]/((double)weights[i]));
  }
  /*
    vector<double>::iterator it;
    for(it=vPerUnit.begin();it!=vPerUnit.end();it++)
    {
        std::cout << *it << std::endl;
    }*/
  std::vector<double> sortVPU(vPerUnit);
  // reversed sort the vector
  sort(sortVPU.begin(),sortVPU.end(),std::greater<int>());
  for (int i=0;i<sortVPU.size();i++)
  {
      if (capacity == 0)
          return value;
      // to find the item number matching values[i] and weights[i]
      vector<double>::iterator it = std::find(vPerUnit.begin(),vPerUnit.end(),sortVPU[i]);
      if (it<vPerUnit.begin())
        std::cout<<"Wrong."<<std::endl;
      // need distance() to calculate the index
      int item = std::distance(vPerUnit.begin(),it) ;
      if (capacity >= weights[item])
      {
          weight = weight + weights[item];
          capacity = capacity - weights[item];
          value = value + values[item];
          std::cout << "capacity is "<< capacity << " weight is " << weight << " value is " << value<< std::endl;
      }
      else
      {
          weight = weight + capacity;
          value = value + vPerUnit[item] * capacity;
          capacity = 0;
          std::cout << "capacity is "<< capacity << " weight is " << weight << " value is " << value<< std::endl;
          return value;
      }
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

  std::cout.setf(std::ios::fixed);
  std::cout.setf(std::ios::showpoint);
  std::cout.precision(4);
  std::cout << optimal_value << std::endl;

  return 0;
}
