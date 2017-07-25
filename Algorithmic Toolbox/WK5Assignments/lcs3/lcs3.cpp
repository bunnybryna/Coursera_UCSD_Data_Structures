#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) ;
int max(int a,int b, int c);


int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}


int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  int l = a.size();
  int m = b.size();
  int n = c.size();
  int d1 = l+1;
  int d2 = m+1;
  int d3 = n+1;
  // vector<vector<vector<double>>> f(3, vector<vector<double>>(4, vector<double>(5)));
  vector<vector<vector<int> > > vec(d1, vector<vector<int> >(d2,vector<int>(d3)));
  for (int i=0;i<l+1;i++)
  {
	for (int j=0;j<m+1;j++)
    {
		for (int k=0;k<n+1;k++)
		{
			if (i==0 || j==0|| k==0 )
				vec[i][j][k]=0;
			else if (a[i-1] == b[j-1] && a[i-1] == c[k-1])
				vec[i][j][k] = 1+vec[i-1][j-1][k-1];
			//(a[i]!= b[j]||a[i]!=c[k]||b[j]!=c[k])
			else
				vec[i][j][k] = max(vec[i-1][j][k],vec[i][j-1][k],vec[i][j][k-1]);
		}
     }
  }
  return vec[l][m][n];
}

int max(int a,int b, int c)
{
	return max(max(a,b),c);
}
