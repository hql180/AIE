#include <iostream>	
#include <random>
#include <iomanip>
#include <queue>

struct Tree
{
	struct Node
	{
		Node() : value(NULL), left(nullptr), right(nullptr) {}
		Node(int value) : value(value), left(nullptr), right(nullptr) {}
		~Node() 
		{
			if (left != nullptr)
			{
				delete left;
			}
			if (right != nullptr)
			{
				delete right;
			}
		}

		void print()
		{
			for (int i = 0; i < level; ++i) std::cout << ' ';
			std::cout << value << "\n";
			++level;
			if (left)
			{
				left->print();
				--level;
			}
			if (right)
			{
				right->print();
				--level;
			}			
		}

		int value;
		Node* left;
		Node* right;
		static int level;
	};

	Tree() : root(new Node) {}
	Tree(int value) : root(new Node(value)) {}
	~Tree() { delete root; }
	
	bool isEmpty()
	{
		if (root->value == NULL)
		{
			return true;
		}
	}

	Node* getNode(Node* current, int value)
	{
		if (current->value < value && current->right != nullptr)
		{
			return current->right;
		}
		else if (current->value > value && current->left != nullptr)
		{
			return current->left;
		}
		else
		{
			return current;
		}
	}

	void insert(int value)
	{
		if (root->value == NULL)
		{
			root->value = value;
		}

		Node* current = root;
		Node* next = getNode(current, value);
		while (current != next)
		{
			current = next;
			next = getNode(current, value);
		}

		Node* newNode = new Node(value);

		if (current->value < value)
		{
			current->right = newNode;
		}
		else if (current->value > value)
		{
			current->left = newNode;
		}
		else
		{
			delete newNode;
		}
	}

	bool find(int value)
	{
		Node* current = root;
		Node* next = getNode(current, value);
		if (current->value == value)
		{
			return true;
		}

		while (current != next)
		{
			current = next;
			next = getNode(current, value);
			if (current->value == value)
			{
				return true;
			}
		}
		return false;
	}

	void remove(int value)
	{
		if (find(value))
		{
			Node* current = root;
			Node* previous = current;
			Node* next = getNode(current, value);
			while (current != next)
			{
				previous = current;
				current = next;
				next = getNode(current, value);
			}
			if (current->left == nullptr && current->right == nullptr)
			{
				if (previous->value < value)
				{
					previous->right = nullptr;
				}
				else if (previous->value > value)
				{
					previous->left = nullptr;
				}
				delete current;
			}
			else if (current->right == nullptr)
			{
				if (previous->value < value)
				{
					previous->right = current->left;
				}
				else if (previous->value > value)
				{
					previous->left = current->left;
				}
				delete current;
			}
			else if (current->left == nullptr)
			{
				if (previous->value < value)
				{
					previous->right = current->right;
				}
				else if (previous->value > value)
				{
					previous->left = current->right;
				}
				delete current;
			}
			else
			{
				Node* tPrevious;
				Node* tCurrent = current->right;
				Node* tNext = tCurrent->left;
				while (tNext != nullptr)
				{
					tPrevious = tCurrent;
					tCurrent = tNext;
					tNext = tCurrent->left;
				}
				current->value = tCurrent->value;
				tPrevious->left = tCurrent->right;
				delete tCurrent;
			}
		}
	}

	void DFPreOrder()
	{
		Node* current = root;

		std::cout << current->value << ' ';

		DFPreOrder(current->left);
		DFPreOrder(current->right);

		std::cout << '\n';
	}

	void DFPreOrder(Node* current)
	{
		if (current != nullptr)
		{
			std::cout << current->value <<' ';

			DFPreOrder(current->left);
			DFPreOrder(current->right);
		}
	}

	void DFPostOrder()
	{
		Node* current = root;

		DFPostOrder(current->left);
		DFPostOrder(current->right);

		std::cout << current->value << '\n';
	}

	void DFPostOrder(Node* current)
	{
		if (current != nullptr)
		{
			DFPostOrder(current->left);
			DFPostOrder(current->right);

			std::cout << current->value << ' ';
		}
	}

	void DFInOrder()
	{
		Node* current = root;
		
		DFPreOrder(current->left);

		std::cout << current->value << ' ';

		DFPreOrder(current->right);

		std::cout << '\n';
	}

	void DFInOrder(Node* current)
	{
		if (current != nullptr)
		{
			DFPreOrder(current->left);

			std::cout << current->value << ' ';

			DFPreOrder(current->right);
		}
	}

	void breadFirst()
	{
		std::queue<Node*> tree;

		tree.push(root);
		
		while (!tree.empty())
		{
			std::cout << tree.front()->value << ' ';
			if (tree.front()->left != nullptr)
				tree.push(tree.front()->left);
			if (tree.front()->right != nullptr)
				tree.push(tree.front()->right);
			tree.pop();
		}
	}

	/*void print()
	{
		if (!root)
			return;
		root->print();
	}

	void print2(Node* p, int indent = 0)
	{
		if (p != NULL)
		{
			if (indent)
			{
				std::cout << std::setw(indent) << ' ';
			}
			std::cout << p->value << "\n";
			if (p->left) print2(p->left, indent + 4);
			if (p->right) print2(p->right, indent + 4);
			
			
		}
	}*/

	void postorder(Node* p, int indent = 0)
	{
		if (p != NULL) {
			if (p->right) {
				postorder(p->right, indent + 4);
			}
			if (indent) {
				std::cout << std::setw(indent) << ' ';
			}
			if (p->right) std::cout << " /\n" << std::setw(indent) << ' ';
			std::cout << p->value << "\n ";
			if (p->left) {
				std::cout << std::setw(indent) << ' ' << " \\\n";
				postorder(p->left, indent + 4);
			}
		}
	}

	Node* root;
	
};

int Tree::Node::level = 0;

int main()
{

	Tree test;

	
	test.insert(33);
	test.insert(92);
	test.insert(74);
	test.insert(28);
	test.insert(39);
	test.insert(67);
	test.insert(12);
	test.insert(5);
	test.insert(87);
	test.insert(96);
	test.insert(7);

		
	//test.postorder(test.root);
	
	test.DFPreOrder();
	test.DFPostOrder();
	test.DFInOrder();
	test.breadFirst();

	system("pause");
    return 0;
}

