#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
// iomanip=>setf,algorithm=>sort

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  double weight = 0.0;
  vector<double> vPerUnit;
  for (int i=0;i<weights.size();i++)
  {
    // int/int=int,int/double = double
    double valuesPU = values[i]/((double)weights[i]);
    vPerUnit.push_back(valuesPU);
  }
  std::map<int,double> itemValue;
  for (int i=0;i<weights.size();i++)
  {
      itemValue[i]=values[i]/((double)weights[i]);
  }
  /*for (std::map<int,double>::iterator it=itemValue.begin();it!=itemValue.end();it++)
  {
      std::cout << it->first << " =>" <<it->second<<std::endl;
  }*/
  // reversed sort the vector
  sort(vPerUnit.begin(),vPerUnit.end(),std::greater<int>());
  for (int i=0;i<vPerUnit.size();i++)
  {
      if (capacity == 0)
          return value;
      // to find the item number matching values[i] and weights[i]
      int item=0;
      for (int j=0;j<itemValue.size();j++)
      {
          if (itemValue[j]== vPerUnit[i])
          {
            item = j;
            break;
          }
      }
      if (capacity >= weights[item])
      {
          weight = weight + weights[item];
          capacity = capacity - weights[item];
          value = value + values[item];
          itemValue.erase(item);
            /*for (std::map<int,double>::iterator it=itemValue.begin();it!=itemValue.end();it++)
              {
                  std::cout << it->first << " =>" <<it->second<<std::endl;
              }*/
          //std::cout << "capacity is "<< capacity << " weight is " << weight << " value is " << value<< std::endl;
      }
      else
      {
          weight = weight + capacity;
          value = value + vPerUnit[item] * capacity;
          capacity = 0;
          //std::cout << "capacity is "<< capacity << " weight is " << weight << " value is " << value<< std::endl;
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
