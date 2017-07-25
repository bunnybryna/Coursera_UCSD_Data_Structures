#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <utility>

using namespace std;


pair<long long, long long> minAndMax(int i, int j, const vector<vector<long long> > &m, const vector<vector<long long> > &M, const vector<char> &op);
long long eval(long long a, long long b, char op);
long long get_maximum_value(string exp);
long long min(long long a, long long b, long long c, long long d);
long long max(long long a, long long b, long long c, long long d);
void printTDVector(const vector<vector<long long> > &vec);

/*using std::vector;
using std::string;
using std::max;
using std::min;*/


int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}


pair<long long, long long> minAndMax(int i, int j, const vector<vector<long long> > &m, const vector<vector<long long> > &M, const vector<char> &op)
{
	long long a,b,c,d, minNow, maxNow;
	long long minF = numeric_limits<int>::max();
	long long maxF = numeric_limits<int>::min();
	for (int k=i;k<j;k++)
	{
		a = eval(M[i][k],M[k+1][j],op[k]);
		b = eval(M[i][k],m[k+1][j],op[k]);
		c = eval(m[i][k],M[k+1][j],op[k]);
		d = eval(m[i][k],m[k+1][j],op[k]);
		minNow = min(a,b,c,d);
		maxNow = max(a,b,c,d);
		if (minF > minNow)
			minF = minNow;
		if (maxF < maxNow)
			maxF = maxNow;
	}
	return make_pair(minF, maxF);

}

long long get_maximum_value(string exp) {
	vector<int> digits;
	vector<char> operations;
	string number;
	int i, j=0;
	int n = exp.length();
	for (i=0;i<n;i++)
	{
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*')
		{
			// str.substr(position,length)
			number = exp.substr(j,i-j);
			int value = atoi(number.c_str());
			digits.push_back(value);
			operations.push_back(exp[i]);
			j = i+1;

		}
		if (i== exp.length()-1)
		{
			{
                // when there is no operation
			    if (j==0)
                    number = exp;
                // when there is no operation left
                else
                    number = exp.substr(j,i);
			}
			int value = atoi(number.c_str());
			digits.push_back(value);
		}
	}
	/*cout << " Digits are " << endl;
	for (int i=0;i<digits.size();i++)
		cout << digits[i] << " ";
	cout << endl << " Operations are " << endl;*/
	if (operations.size() == 0)
		return digits[0];
	/*for (int i=0;i<digits.size();i++)
		cout << operations[i] << " ";*/
	int num = digits.size();
	vector< vector<long long> > m(num, vector<long long>(num));
    vector< vector<long long> > M(num, vector<long long>(num));
    //5-8+7*4-8+9
	for (int i=0;i<num;i++)
		for (int j=0;j<num;j++)
		{
			if (i==j)
            {
				m[i][j]=digits[i];
				M[i][j]=digits[i];
            }
		}
	/*cout << endl << "----------m---------" << endl;
	printTDVector(m);
	cout << endl << "----------M---------" << endl;
	printTDVector(M);*/
	pair<long long, long long> mmPair;
	for (int s=1;s<num;s++)
    {
		for (int i=0;i<num-s;i++)
		{
			int j= i+s;
			if (s==1)
			{
				m[i][j]=eval(digits[i],digits[j],operations[i]);
				M[i][j]=eval(digits[i],digits[j],operations[i]);
			}
			mmPair = minAndMax(i,j,m,M,operations);
			m[i][j]= mmPair.first;
			M[i][j]= mmPair.second;
		}
    }
	/*cout << endl << "----------m---------" << endl;
	printTDVector(m);
	cout << endl << "----------M---------" << endl;
	printTDVector(M);*/
    return M[0][num-1];
}


long long min(long long a, long long b, long long c, long long d)
{
	return min(min(a,b),min(c,d));
}

long long max(long long a, long long b, long long c, long long d)
{
	return max(max(a,b),max(c,d));
}

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

void printTDVector(const vector<vector<long long> > &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << "   ";
		}
		cout << endl;
	}
}
