#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

#define NULLNODE static_cast<Node*>(0)

struct Node
{
	int data;
	Node* right;
	Node* left;
};

class BinarySearchTree
{
	public:
	BinarySearchTree()
	{
		m_Root = NULLNODE;
	}
	~BinarySearchTree(){erase();}
	BinarySearchTree(const BinarySearchTree& other);
	BinarySearchTree& operator=(const BinarySearchTree& other);
	void print();
	void inorder();
	void preorder();
	void postorder();
	bool empty()
	{
		return m_Root == NULLNODE;
	}
	void insert(int data);
	int nodeCount()
	{
		return nodeCountHelper(m_Root);
	}
	int height()
	{
		return heightHelper(m_Root);
	}
	int heightQueue()
	{
		return heightQueueHelper(m_Root);
	}
	bool find(int lookingFor){return findHelper(m_Root, lookingFor);}
	void erase(){eraseHelper(m_Root);
	m_Root = NULLNODE;}
	protected:
	private:
		void insertHelper(Node* &n, int data);
		void printHelper(Node* n);
		int nodeCountHelper(Node* n);
		int heightHelper(Node* n);
		int heightQueueHelper(Node* nodePointer);
		bool findHelper(Node* n, int lookingFor);
		void preorderHelper(Node* n);
		void inorderHelper(Node* n);
		void postorderHelper(Node* n);
		Node* copyHelper(Node* n);
		void eraseHelper(Node* n);
		Node* m_Root;
};

int main()
{
	srand(time(0));
	BinarySearchTree intBST;
	for (int i=0;i<5;i++)
	{
		int x = rand()%100;
		std::cout << x << std::endl;
		intBST.insert(x);
		//intBST.insert(i);
	}
	intBST.print();
	cout << "Height is " << intBST.height() << endl;
	cout << "Height is " << intBST.heightQueue() << endl;

	return 0;
}


BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& other)
{
	if(this == &other) return *this;
		return *this;
	erase();
	m_Root = copyHelper(other.m_Root);
}

void BinarySearchTree::print()
{
	if(empty())
	{
		std::cout << "Empty Tree" << std::endl;
	}
	else
	{
		printHelper(m_Root);
	}

}

void BinarySearchTree::printHelper(Node* n)
{
	if (n== NULLNODE) return;
	printHelper(n->left);
	std::cout << n->data << " ";
	printHelper(n->right);
}

void BinarySearchTree::insert(int data)
{
	insertHelper(m_Root, data);
}
void BinarySearchTree::insertHelper(Node* &n, int data)
{
	if (n==NULLNODE)
	{
		n = new Node;
		n->data = data;
		n->left = NULLNODE;
		n->right = NULLNODE;
		return ;
	}
	if (data <n->data)
	{
		insertHelper(n->left, data);
	}
	else
	{
		insertHelper(n->right, data);
	}
}

bool BinarySearchTree::findHelper(Node* n, int lookingFor)
{
	if(!n)
		return 0;
	if (n->data < lookingFor)
		return findHelper(n->right, lookingFor);
	else if (lookingFor< n->data)
		return findHelper(n->left, lookingFor);
	else
		return 1;
}

int BinarySearchTree::nodeCountHelper(Node* n)
{
	if(!n) return 0;
	return nodeCountHelper(n->left)+nodeCountHelper(n->right) + 1;
}

int BinarySearchTree::heightHelper(Node* n)
{
	if (!n) return 0;
	int hleft = heightHelper(n->left);
	int hright = heightHelper(n->right);
	return (hleft>hright)?(hleft+1):(hright+1);
}

// iterative height count
int BinarySearchTree::heightQueueHelper(Node* nodePointer)
{
	if (nodePointer == NULLNODE)
		return 0;
	std::queue <Node*> q;
	// it can replaced by m_Root
	q.push(nodePointer);
	int height = 0;
	// double layer loop
	// outer loop is to count height
	while(1)
	{
		int countNode = q.size();
		if (countNode == 0)
			return height;
		height++;
		// inner loop is to count nodes
		// when this lever of nodes =>0
		// break out of the inner while loop
		// move to next level
		while(countNode >0)
		{
			// pop node from front
			Node* n = q.front();
			q.pop();
			// push its children to queue
			if (n->left != NULLNODE)
				q.push(n->left);
			if(n->right != NULLNODE)
				q.push(n->right);
			// since this node is done, so -1
			// move to next node(still within this while loop)
			countNode--;
		}
	}

}


void BinarySearchTree::inorder()
{
	if(empty())
	{
		std::cout << "Empty Tree"<<std::endl;
	}
	else
	{
		inorderHelper(m_Root);
	}
}

void BinarySearchTree::inorderHelper(Node* n)
{
	if(n==NULLNODE) return ;
	inorderHelper(n->left);
	std::cout << n->data << " ";
	inorderHelper(n->right);
}

void BinarySearchTree::preorder()
{
    if (empty())
    {
        std::cout << "Empty Tree" << std::endl;
    }
    else
    {
        preorderHelper(m_Root);
    }

}


void BinarySearchTree::preorderHelper(Node* n)
{
    if (n == NULLNODE) return;

    /// pre order traversal of the tree
    std::cout << n->data << " ";
    preorderHelper(n->left);
    preorderHelper(n->right);
}


void BinarySearchTree::postorder()
{
    if (empty())
    {
        std::cout << "Empty Tree" << std::endl;
    }
    else
    {
        postorderHelper(m_Root);
    }

}


void BinarySearchTree::postorderHelper(Node* n)
{
    if (n == NULLNODE) return;

    /// post order traversal of the tree
    postorderHelper(n->left);
    postorderHelper(n->right);
    std::cout << n->data << " ";
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other)
{
	m_Root = copyHelper(other.m_Root);
}

Node* BinarySearchTree::copyHelper(Node* oldNode)
{
	if(oldNode == NULLNODE) return NULLNODE;
	Node* newNode = new Node();
	newNode->data = oldNode->data;
	newNode->left = copyHelper(oldNode->left);
	newNode->right = copyHelper(oldNode->right);
	return newNode;
}


void BinarySearchTree::eraseHelper(Node* n)
{
	if(!n) return ;
	eraseHelper(n->left);
	eraseHelper(n->right);
	delete n;
	return ;
}
