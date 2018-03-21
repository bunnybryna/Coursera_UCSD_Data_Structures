#include <bits/stdc++.h>

// Splay tree implementation

// Vertex of a splay tree

using namespace std;

struct Vertex
{
    // Sum of all the keys in the subtree - remember to update
    // it after each operation that changes the tree.
    int key;
    long long sum;
    Vertex* left;
    Vertex* right;
    Vertex* parent;

    Vertex(int key, long long sum, Vertex* left, Vertex* right, Vertex* parent)
    : key(key), sum(sum), left(left), right(right), parent(parent) {}

};

void update( Vertex *v ){
    if ( v == NULL )
        return;
    v->sum = v->key + ( v->left != NULL ? v->left->sum : 0ll ) +( v->right != NULL ? v->right->sum : 0ll );
    if ( v->left != NULL ){
        v->left->parent = v;
    }
    if ( v->right != NULL ){
        v->right->parent = v;
    }
}

void small_rotation( Vertex *v ){
    Vertex *parent = v->parent;
    if ( parent == NULL ){
        return;
    }
    Vertex *grandparent = v->parent->parent;
    if ( parent->left == v ){
        Vertex *m = v->right;
        v->right = parent;
        parent->left = m;
    }
    else

    {
        Vertex *m = v->left;
        v->left = parent;
        parent->right = m;
    }

    update( parent );
    update( v );
    v->parent = grandparent;
    if ( grandparent != NULL ){
        if ( grandparent->left == parent ){
            grandparent->left = v;
        }

        else{
        grandparent->right = v;
        }
    }
}

void big_rotation( Vertex *v ){
    if ( v->parent->left == v && v->parent->parent->left == v->parent )
    {
        // Zig-zig
        small_rotation( v->parent );
        small_rotation( v );
    }
    else if ( v->parent->right == v && v->parent->parent->right == v->parent )
    {
        // Zig-zig
        small_rotation( v->parent );
        small_rotation( v );
    }
    else
    {
        // Zig-zag
        small_rotation( v );
        small_rotation( v );
    }
}

// Makes splay of the given vertex and makes
// it the new root.
void splay( Vertex *&root, Vertex *v )
{
    if ( v == NULL )
        return;
    while ( v->parent != NULL )
    {
        if ( v->parent->parent == NULL )
        {
        small_rotation( v );
        break;
        }

    big_rotation( v );
    }

    root = v;

}


// Searches for the given key in the tree with the given root
// and calls splay for the deepest visited node after that.
// If found, returns a pointer to the node with the given key.
// Otherwise, returns a pointer to the node with the smallest
// bigger key (next value in the order).
// If the key is bigger than all keys in the tree,
// returns NULL.


Vertex* find( Vertex*& root, int key ){
  Vertex *v = root;
  Vertex *last = root;
  Vertex *next = NULL;
  while ( v != NULL ){
    if ( v->key >= key && ( next == NULL || v->key < next->key ) ){
      next = v;
    }

    last = v;
    if ( v->key == key ){
      break;
    }
    if ( v->key < key ){
      v = v->right;
    }
    else{
      v = v->left;
    }
  }

  splay(root, last);
  return next;
}

void split( Vertex *root, int key, Vertex *&left, Vertex *&right ){
  right = find( root, key );
  splay( root, right );
  if ( right == NULL ){
    left = root;
    return;
  }
  left = right->left;
  right->left = NULL;
  if ( left != NULL ){
    left->parent = NULL;
  }
  update(left);
  update(right);
}

Vertex* merge(Vertex* left, Vertex* right) {
  if (left == NULL) return right;
  if (right == NULL) return left;
  Vertex* min_right = right;
  while (min_right->left != NULL) {
    min_right = min_right->left;
  }
  splay(right, min_right);
  right->left = left;
  update(right);
  return right;
}


// Code that uses splay tree to solve the problem
Vertex* root = NULL;

void insert(int x) {
  Vertex* left = NULL;
  Vertex* right = NULL;
  Vertex* new_vertex = NULL;
  split(root, x, left, right);
  if (right == NULL || right->key != x) {
    new_vertex = new Vertex(x, x, NULL, NULL, NULL);
  }
  root = merge(merge(left, new_vertex), right);
}

void erase(int x)
{
    // Implement erase yourself
    Vertex* v=find(root,x);
    splay(root,v);

    if (v==nullptr || v->key!=x)
        return;

    if (v&& v->key==x)
    {
        root=merge(root->left,root->right);
        if (root)
            root->parent = nullptr;
    }
}


bool find( int x )
{
    // Implement find yourself
    Vertex* v=find(root,x);
    splay(root,v);

    if (v==nullptr || v->key!=x)
        return false;

    if (v->key==x)
        return true;

    return false;

}


long long sum( int from, int to )
{
    Vertex *left = NULL;
    Vertex *middle = NULL;
    Vertex *right = NULL;
    split( root, from, left, middle );
    split( middle, to + 1, middle, right );
    long long ans = 0;
    // Complete the implementation of sum
    update(left);
    update(right);
    update(middle);
    if (middle !=nullptr)
        ans=middle->sum;

    root=merge(merge(left,middle),right);
        return ans;
}

const int MODULO = 1000000001;

struct Operation
{
    char ch;
    int x;
    int l;
    int r;

};

int main()
{
    stringstream ss;

    int n;
    cin >>n;

    vector<Operation> ops;

    for (int i=0 ;i<n; ++i)
        {
        Operation op;
        char ch;
        cin >>ch;
        switch (ch)
        {
        case 's':
            {
            int l,r;
            cin >>l;
            cin >>r;
            op={ch,-1,l,r};
            }
            break;

      case '+':
            {
            int x;
            cin >>x;
            op={ch,x,-1,-1};
            }
            break;

      case '-':
            {
            int x;
            cin>>x;
            op={ch,x,-1,-1};
            }
            break;

      case '?':
            {
            int x;
            cin>>x;
            op={ch,x,-1,-1};
            }
            break;

      default: break;
    }

    ops.push_back(op);
}

    int lastSumResult=0;
    for (int i=0 ;i<n; ++i)
    {
        auto op=ops[i];
        switch (op.ch)
        {
        case '+':
        {
        insert((op.x+lastSumResult)%MODULO);
        }
        break;

    case '-':
        {
        erase((op.x+lastSumResult)%MODULO);
        }
        break;

    case '?':
        {
        if (find((op.x+lastSumResult)%MODULO))
            ss<<"Found"<<endl;
        else
            ss<<"Not found"<<endl;
        }
        break;

    case 's':
        {
        long long res=sum((op.l+lastSumResult)%MODULO,(op.r+lastSumResult)%MODULO);
        ss <<res<<endl;

        lastSumResult=int(res%MODULO);
        }

    }
  }

    cout <<ss.str();

    return 0;
}
