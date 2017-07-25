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
  int m = a.size();
  int n = b.size();
  int o = c.size();
    int L[m+1][n+1][o+1];

    /* Following steps build L[m+1][n+1][o+1] in
       bottom up fashion. Note that L[i][j][k]
       contains length of LCS of X[0..i-1] and
       Y[0..j-1]  and Z[0.....k-1]*/
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            for (int k=0; k<=o; k++)
            {
                if (i == 0 || j == 0||k==0)
                    L[i][j][k] = 0;

                else if (a[i-1] == b[j-1] && a[i-1]==c[k-1])
                    L[i][j][k] = L[i-1][j-1][k-1] + 1;

                else
                    L[i][j][k] = max(max(L[i-1][j][k],
                                         L[i][j-1][k]),
                                     L[i][j][k-1]);
            }
        }
    }
  return L[m][n][o];
}

int max(int a,int b, int c)
{
	return max(max(a,b),c);
}
