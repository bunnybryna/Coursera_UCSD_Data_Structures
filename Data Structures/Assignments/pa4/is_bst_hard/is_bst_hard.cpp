// didn't pass the grader for some reason

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
	//cout << "key: " << tree[index].key << " left: " << tree[index].left << " right: " << tree[index].right << endl;
	//cout << "index: " << index<< " min: " << min << " max: " << max << endl;
    // note here key<= min || key>max is wrong
	if (tree[index].key < min || tree[index].key >= max)
		return false;
	else
	{
		if (tree[index].left == -1 && tree[index].right == -1 )
			return true;
		else if (tree[index].right == -1)
		{
			//cout << "come to left " << endl;
			return isBST(tree, tree[index].left, min, tree[index].key);
		}
		else if (tree[index].left == -1)
		{
			//cout << "come to right " << endl;
			return isBST(tree, tree[index].right, tree[index].key, max);
		}
		else
		{
		    //cout << "come to else " << endl;
			return isBST(tree, tree[index].left, min, tree[index].key) && isBST(tree, tree[index].right, tree[index].key, max);
		}

	}
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  long long inf = std::numeric_limits<long long>::max();
  return isBST(tree, 0, -1, inf);
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
