#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n);
vector<int> optimal_sequenceDP(int n);
int find_smallest(int num1, int num2, int num3);

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequenceDP(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";}
  return 0;
}


vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}


vector<int>& optimal_sequenceDP(int n) {
  std::vector<int> sequence;
  sequence.push_back(n);
  if (n == 1)
  {
	reverse(sequence.begin(), sequence.end());
	return sequence;
  }
  if ((n % 3 == 0) && (n % 2 == 0))
  {
	int num1,num2,num3;
    cout << " %3 and %2" << endl;
    num1 = (optimal_sequenceDP(n/3)).size();
	num2 = (optimal_sequenceDP(n/2)).size();
	num3 = (optimal_sequenceDP(n-1)).size();
	if ((num1 <= num2) && (num1 <= num3))

		return optimal_sequenceDP(n/3);
	else if ((num2 <= num1) && (num2 <= num3))
		return optimal_sequenceDP(n/2);
	else
		return optimal_sequenceDP(n-1);
  }
  else if ((n % 3 != 0) &&(n % 2 == 0))
  {
	int num2, num3;
    cout << " %2 " << endl;
	num2 = (optimal_sequenceDP(n/2)).size();
	num3 = (optimal_sequenceDP(n-1)).size();
	if (num2<num3)
		return optimal_sequenceDP(n/2);
	else
		return optimal_sequenceDP(n-1);
  }
  else if ((n % 3 == 0) &&(n % 2 != 0))
  {
	int num1, num3;
    cout << " %3 " << endl;
	num1 = (optimal_sequenceDP(n/3)).size();
	num3 = (optimal_sequenceDP(n-1)).size();
	if (num1<num3)
		return optimal_sequenceDP(n/3);
	else
		return optimal_sequenceDP(n-1);
  }
  else
  {
    cout << " n-1 " << endl;
	return optimal_sequenceDP(n-1);
  }
  return sequence;
}

int find_smallest(int num1, int num2, int num3)
{
	if ((num1 <= num2) && (num1 <= num3))
		return num1;
	else if ((num2 <= num1) && (num2 <= num3))
		return num2;
	else
		return num3;
}
