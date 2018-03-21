#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree) {
  for (int i=0;i<tree.size();i++)
  {
	//cout << "i:" << i << " key:" << tree[i].key << " left:" << tree[i].left << " right:" << tree[i].right << endl;
	if (tree[i].left!= -1)
	{
		int left;
		left = tree[tree[i].left].key;
		if (tree[i].key < left)
			return false;
	}
	if  (tree[i].right!= -1)
	{
		int right;
		right = tree[tree[i].right].key;
		if (tree[i].key > right)
			return false;
	}
  }
  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
