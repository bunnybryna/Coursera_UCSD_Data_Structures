#include <cstdio>
#include <string>
#include <iostream>
#include <utility>
#include <vector>

using std::vector;


class Rope {
	/*std::string s;
public:
	Rope(const std::string &s) : s(s) {
	}

	void process( int i, int j, int k ) {
                // Replace this code with a faster implementation
                std::string t = s.substr(0, i) + s.substr(j + 1);
                s = t.substr(0, k) + s.substr(i, j - i + 1) + t.substr(k);
	}

	std::string result() {
		return s;
	}*/
	struct Vertex
	{
		char key;
		long long index;
		Vertex* left;
		Vertex* right;
		Vertex* parent;

		Vertex(char key, long long index, Vertex* left, Vertex* right, Vertex* parent)
		:key(key), index(index),left(left),right(right),parent(parent){}
	};
public:
	vector<char> s;
	vector<char> subs;

	Rope(const std::string &s)
	{
		for(int i=0;i<s.length();++i)
		{
			insert(s[i],i);
		}
	}

	void update(Vertex* v)
	{
	  if (v == NULL) return;

	  if (v->left != NULL)
		v->left->parent = v;

	  if (v->right != NULL)
		v->right->parent = v;
	}

    // rotate 2 notes: v and p
	void small_rotation(Vertex* v)
	{
	  Vertex* parent = v->parent;
	  if (parent == NULL)
	  {
		return;
	  }
	  Vertex* grandparent = v->parent->parent;
	  if (parent->left == v)
	  {
		Vertex* m = v->right;
		v->right = parent;
		parent->left = m;
	  }
	  else
	  {
		Vertex* m = v->left;
		v->left = parent;
		parent->right = m;
	  }
	  update(parent);
	  update(v);
	  v->parent = grandparent;
	  if (grandparent != NULL)
	  {
		if (grandparent->left == parent)
		{
		  grandparent->left = v;
		}
		else
		{
		  grandparent->right = v;
		}
	  }
	}

	// rotate 3 nodes: v, p, q(grandparent)
	void big_rotation(Vertex* v)
	{
	  if (v->parent->left == v && v->parent->parent->left == v->parent) {
		// Zig-zig
		small_rotation(v->parent);
		small_rotation(v);
	  } else if (v->parent->right == v && v->parent->parent->right == v->parent) {
		// Zig-zig
		small_rotation(v->parent);
		small_rotation(v);
	  } else {
		// Zig-zag
		small_rotation(v);
		small_rotation(v);
	  }
	}

	// Makes splay of the given vertex and makes
	// it the new root.
	void splay(Vertex*& root, Vertex* v)
	{
	  if (v == NULL) return;
	  while (v->parent != NULL)
	  {
		if (v->parent->parent == NULL)
		{
		  small_rotation(v);
		  break;
		}
		big_rotation(v);
	  }
	  root = v;
	//std::cout << "Splayed " << root->key << std::endl;
	}

	Vertex* find(Vertex*& root, long long index)
	{
	  Vertex* v = root;
	  Vertex* last = root;
	  Vertex* next = NULL;
	  while (v != NULL)
	  {
		if (v->index >= index && (next == NULL || v->index < next->index))
		{
		  next = v;
		}
		last = v;
		if (v->index == index)
		{
		  break;
		}
		if (v->index < index)
		{
		  v = v->right;
		} else
		{
		  v = v->left;
		}
	  }
	  splay(root, last);
	  return next;
	}

	void split(Vertex* root, long long index, Vertex*& left, Vertex*& right) {
	  right = find(root, index);
	  splay(root, right);
	  if (right == NULL)
	  {
		left = root;
		return;
	  }
	  // use the splayed tree's left as left
	  left = right->left;
	  right->left = NULL;
	  // splitting here
	  if (left != NULL) {
		left->parent = NULL;
	  }
	  update(left);
	  update(right);
	}

	Vertex* merge(Vertex* left, Vertex* right)
	{
	  if (left == NULL) return right;
	  if (right == NULL) return left;
	  Vertex* min_right = right;
	  // find the min of the right tree, when there is no left
	  while (min_right->left != NULL)
	  {
		min_right = min_right->left;
	  }
	  // move it to the top and use as the root of merged tree
	  splay(right, min_right);
	  right->left = left;
	  update(right);
	  return right;
	}


	Vertex* root = NULL;

	void insert(char c, long long index)
	{
	  Vertex* left = NULL;
	  Vertex* right = NULL;
	  Vertex* new_vertex = NULL;
	  // split at c, if c doesn't exist, returns its left and right pointer
	  split(root, index, left, right);
	  // if right != NULL && right->key == c, means right is c
	  // then new_vertex is still NULL, no need to insert
	  if (right == NULL || right->key != c)
		new_vertex = new Vertex(c, index, NULL, NULL, NULL);
	  // merge root, left and right all three
	  if (root != NULL)
		  root = merge(root, merge(merge(left, new_vertex),right));
	  else
		  root = merge(merge(left, new_vertex), right);
	}

	Vertex* erase(int index)
	{
	  Vertex* v = find(root,index);
	  splay(root,v);
	  if (v == NULL || v->index != index)
		  return NULL;
	  if(v != NULL && v->index == index)
	  {
		  root = merge(root->left, root->right);
		  if(root)
			  root->parent = NULL;
	  }
	  return v;
	}

	void rec_in_order(Vertex* root)
	{
		if(root == NULL)
			return;
		if(root->left != NULL)
		{
			rec_in_order(root->left);
		}
		// update indeces
		root->index = s.size()!=NULL ? s.size() : 0;
		if(root->right != NULL)
		{
			rec_in_order(root->right);
		}
	}

	void in_order()
	{
		s.clear();
		rec_in_order(root);
	}

	void rec_right_index(Vertex* v)
	{
		if (v == NULL) return;
		if (v->left != NULL)
			rec_in_order(v->left);
		v->index = v->index + subs.size();
		if (v->right != NULL)
			rec_in_order(v->right);
	}

	void result()
	{
		for(int i=0;i<s.size();++i)
			std::cout << s[i];
		std::cout << std::endl;
	}
void process( int i, int j, int k ) {
		Vertex* er = NULL;
		Vertex* left = NULL;
		Vertex* right = NULL;
		Vertex* new_vertex = NULL;
		
		subs.clear();
		
				for(int in=i; in<=j; ++in){
			// k +j ??? for one loop instead of 2
			er = erase(in);
			subs.push_back(er->key); // we have indices starting from k+1 now
		}
		
		//s.clear();
		in_order(); // resets all the indices to the right ones
		//result();
		// we are going to split at every single point in question and merge accordingly
		for(int it=0; it<subs.size(); ++it){
			
			// debug properly???
			if(s.size() > k){
				split(root,k+it,left,right); // check how split works exactly
				//if(right == NULL && left == NULL) rec_right_index(root);
				rec_right_index(right);
				
				//result(); // ????
				
				new_vertex = new Vertex(subs[it],k+it,NULL,NULL,NULL);
				
				if(right == NULL && left == NULL) {
					// the case where the split was smooth
					root = merge(root,merge(merge(left,new_vertex),right));
				}
				
				else
					root = merge(merge(left,new_vertex),right);
			}
			
			else{
				new_vertex = new Vertex(subs[it],k+it,NULL,NULL,NULL);
				root = merge(root,new_vertex);
			}
			
			in_order();
		}
	}
};

int main() {

	std::ios_base::sync_with_stdio(0);
	std::string s;
	std::cin >> s;
	Rope rope(s);
	int actions;
	std::cin >> actions;
        for (int action_index = 0; action_index < actions; ++action_index) {
                int i, j, k;
		std::cin >> i >> j >> k;
		rope.process(i, j, k);
	}
	rope.result();
}
