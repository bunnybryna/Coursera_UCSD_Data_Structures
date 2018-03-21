#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll maxn = 1e15;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool isValid(const vector<Node> &tree, int n, ll min, ll max){
    if(n == -1) return true;

    bool l = isValid(tree, tree[n].left, min, tree[n].key);
    bool r = isValid(tree, tree[n].right, tree[n].key, max);

    if(tree[n].key >= min && tree[n].key < max && l == true && r == true){
        return true;
    } else{
        return false;
    }
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  if(tree.size() == 0) return true;
  bool ok = isValid(tree, 0, -maxn, maxn);
  return ok;
}

int main() {
  // freopen("in", "r", stdin);
  // freopen("out", "w", stdout);

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