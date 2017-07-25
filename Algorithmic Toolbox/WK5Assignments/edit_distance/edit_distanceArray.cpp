#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int edit_distance(const string &str1, const string &str2);
int edit_distance2(const string &str1, const string &str2);
int editDist(string str1, string str2, int m, int n);
int min(int x, int y, int z);

int main() {
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << editDist(str1, str2, str1.size(), str2.size())<<endl;
  cout << edit_distance2(str1, str2) << endl;
  cout << edit_distance(str1, str2) << endl;

  return 0;
}

int editDist(string str1, string str2, int m, int n)
{
	if (m == 0)
		return n;
	if (n == 0)
		return m;
	if (str1[m-1] == str2[n-1])
		return editDist(str1, str2, m-1, n-1);
	return 1 + min (editDist(str1, str2, m, n-1),
					editDist(str1, str2, m-1, n),
					editDist(str1, str2, m-1,n-1));
}

int edit_distance2(const string &str1, const string &str2)
{
	int m = str1.size();
	int n = str2.size();
	if (m == 0)
		return n;
	if (n == 0)
		return m;
	string newstr1 = str1.substr(0,m-1);
	string newstr2 = str2.substr(0,n-1);
	if (str1[m-1] == str2[n-1])
		return edit_distance2(newstr1, newstr2);
	return 1+ min(edit_distance2(str1, newstr2),
					  edit_distance2(newstr1, str2),
					  edit_distance2(newstr1, newstr2));
}

int edit_distance(const string &str1, const string &str2)
{
	int m = str1.size();
	int n = str2.size();
	int distance[m+1][n+1];
	for (int i=0;i<m+1;i++)
	{
		for (int j=0;j<n+1;j++)
		{
			if (i==0)
				distance[i][j] = j;
			else if (j==0)
				distance[i][j] = i;
			else if (str1[i-1] == str2[j-1])
				distance[i][j]= distance[i-1][j-1];
			else
				distance[i][j] = 1+ min(distance[i-1][j], distance[i][j-1], distance[i-1][j-1]);

		}
	}
	return distance[m][n];
}


int min(int x, int y, int z)
{
	return min(min(x,y),z);
}
