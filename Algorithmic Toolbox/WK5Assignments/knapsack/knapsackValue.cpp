#include <iostream>
#include <vector>

using namespace std;


int optimal_weight(int W, const vector<int> &w, const vector<int> &v) {
	int n=w.size();
	int itemValue[n+1][W+1];
	for (int i=0;i<n+1;i++)
	{
		for (int j=0;j<W+1;j++)
		{
			itemValue[i][j]=0;
			cout << itemValue[i][j] << " ";
		}
		cout << endl;
	}
	int val;
	for (int i=1;i<=n;i++)
	{
		for (int weight=1;weight<=W;weight++)
        {
			itemValue[i][weight]= itemValue[i-1][weight];
			if (w[i-1] <= weight)
			{
				val = itemValue[i-1][weight-w[i-1]]+v[i-1];
				cout << "val is now " << val << endl;
				if (val > itemValue[i][weight])
					itemValue[i][weight]=val;
			}
        }
	}

	/*for i from 1 to n:
		for w from 1 to W:
			value(w, i ) ← value(w, i − 1)
			if wi ≤ w:
				val ← Knapsack(w − wi ) + vi
				if val > value(w):
					value(w) ← val
	insert value(w) into hash table with key w
	return value(W,n)*/
	for (int i=0;i<n+1;i++)
	{
		for (int j=0;j<W+1;j++)
		{
			cout << itemValue[i][j] << " ";
		}
		cout << endl;
	}
	return itemValue[n][W];
}

int main() {
  /*int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }*/
  vector<int> w;
  w.push_back(6);
  w.push_back(3);
  w.push_back(4);
  w.push_back(2);
  vector<int> v;
  v.push_back(30);
  v.push_back(14);
  v.push_back(16);
  v.push_back(9);
  int W = 10;
  for (int i=0;i<w.size();i++)
  {
	  cout << w[i] << " " << v[i] << endl;
  }
  std::cout << optimal_weight(W, w, v) << '\n';
}
