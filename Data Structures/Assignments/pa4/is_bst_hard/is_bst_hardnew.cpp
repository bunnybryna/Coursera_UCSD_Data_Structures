#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  long long key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long long key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool isBST(const vector<Node>& tree, int index, long long min, long long max)
{
	if (index == -1)
		return true;
	bool l = isBST(tree, tree[index].left, min, tree[index].key);
	bool r = isBST(tree, tree[index].right, tree[index].key, max);
	if (tree[index].key >= min && tree[index].key < max && l== true && r == true)
		return true;
	else:
		return false;

}

bool IsBinarySearchTree(const vector<Node>& tree) {
  long long infp = std::numeric_limits<long long>::max();
  long long infn =  std::numeric_limits<long long>::min();
  return isBST(tree, 0, infn, infp);
}



int main() {
  int nodes;
  cin >> nodes;
  if (nodes == 0)
	  cout << "CORRECT" << endl;
  else
  {
	  vector<Node> tree;
	  for (int i = 0; i < nodes; ++i)
      {
		long long key;
		int	left, right;
		cin >> key >> left >> right;
		tree.push_back(Node(key, left, right));
	  }
	  if (IsBinarySearchTree(tree)) {
		cout << "CORRECT" << endl;
	  } else {
		cout << "INCORRECT" << endl;
	  }
  }
  return 0;
}
