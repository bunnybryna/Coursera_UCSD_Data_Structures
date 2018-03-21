#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>

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


void in_orderRe(const vector<Node>& tree, int index, vector<int>& toprint)
{
	if (tree[index].left != -1)
	{
		in_orderRe(tree, tree[index].left, toprint);
	}
	toprint.push_back(tree[index].key);
	if (tree[index].right != -1)
	{
		in_orderRe(tree, tree[index].right, toprint);
	}
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  vector<int> inorder, unsorted;
  in_orderRe(tree, 0, inorder);
  //for (int i=0;i<tree.size();i++)
	  //cout << inorder[i] << endl;
  unsorted = inorder;
  std::sort (inorder.begin(), inorder.end());
  for (int i=0;i<tree.size();i++)
  {
	if (unsorted[i]!=inorder[i])
		return false;
  }
  return true;
}


int main() {
  int nodes;
  cin >> nodes;
  if (nodes == 0)
	  cout << "CORRECT" << endl;
  else
  { 
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
  }
  return 0;
}
