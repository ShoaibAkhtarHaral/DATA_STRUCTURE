#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;
	Node(int val)
	{
		data = val;
		left = right = NULL;
	}
};

class BST
{
public:
	Node *root;
	BST()
	{
		root = NULL;
	}
	
	void insert(int val)
	{
		root = insert(root, val);
	}
	
	Node* insert(Node* node, int val) {
	        if (node == NULL) {
	            return new Node(val);
	        }
	
	        if (val < node->data) {
	            node->left = insert(node->left, val);
	        } else if (val > node->data) {
	            node->right = insert(node->right, val);
	        }
	
	        return node;
	    }
	
	void In_Order(Node* root)
	{
	        if (root == NULL) {
	            return;
	        }

	        In_Order(root->left);
	        cout << root->data << " ";
	        In_Order(root->right);
	}

	void search(int v)
	{
		bool ch = search(root, v);
		if(ch)
			cout<<"\nvalue found\n";
		else
			cout<<"\nvalue not found\n";
	}
	bool search(Node *n, int val)
	{
		if(n == nullptr)
			return false;
			
		if(n->data == val)
			return true;
			
		if(val < n->data)
			return search(n->left, val);
			
		if(val > n->data)
			return search(n->right, val);
			
		return false;
	}
	
	void min()
	{
		cout<<"The minimum value is: "<<min(root)<<endl;
	}
	
	int min(Node *n)
	{
	    if(n == NULL)
	    {
	        return -1
	    }
	    
	    Node* current = n;
	
	    while (current->left != NULL) 
	    {
	        current = current->left;
	    }
	    
	    return (current->data);
	}

	void max()
	{
		cout<<"The maximum value is: "<<max(root)<<endl;
	}
	
	int max(Node *n)
	{
		if(n == NULL)
		{
			return 0;
		}
		
		Node* current = n;
 
		while (current->right != NULL) 
		{
        		current = current->right;
    		}
    	
		return (current->data);
	}
	
	void size()
	{
		cout<<"Root Size is: " << size(root)<<endl;	
	}	
	
	int size(Node* n)
	{
	        if (n == NULL) {
	            return 0;
	        }
	        return(size(n->left) + 1 + size(n->right)); 
	}
	
	void findParent(Node* node, int val, int parent)
	{
	    if (node == NULL)
	        return;
	 
	    // If current node is the required node
	    if (node->data == val) {
	 
	        // Print its parent
	        cout << "Parent: " << parent <<endl;
	    }
	    else {
	 
	        // Recursive calls for the children
	        // of the current node
	        // Current node is now the new parent
	        findParent(node->left, val, node->data);
	        findParent(node->right, val, node->data);
	    }
	}
	
	int maxDepth(Node* n)  
	{  
	    if (n == NULL)  
	        return -1;  
	    else
	    {  
	        /* compute the depth of each subtree */
	        int lDepth = maxDepth(n->left);  
	        int rDepth = maxDepth(n->right);  
	      
	        /* use the larger one */
	        if (lDepth > rDepth)  
	            return(lDepth + 1);  
	        else return(rDepth + 1);  
	    }  
	}
	
	Node* Find(Node* root, int data) 
	{
		if(root == NULL) 
			return NULL;
			
		else if(root->data == data) 
			return root;
			
		else if(root->data < data) 
			return Find(root->right,data);
			
		else 
			return Find(root->left,data);
	}
	
	void successor(Node* root, int val)
	{
	    if (root == NULL)
	    {
	        return;
	    }
	
	    Node* targetNode = Find(root, val);
	
	    if (targetNode == NULL)
	    {
	        cout << "Node with value " << val << " not found in the tree." << endl;
	        return;
	    }
	
	    // If the target node has a right subtree, find the minimum value node in that subtree
	    if (targetNode->right != NULL)
	    {
	        Node* minNode = targetNode->right;
	        while (minNode->left != NULL)
	        {
	            minNode = minNode->left;
	        }
	        cout << "Successor: " << minNode->data << endl;
	    }
	    else
	    {
	        // Backtrack to find the successor
	        Node* successor = NULL;
	        Node* ancestor = root;
	
	        while (ancestor != targetNode)
	        {
	            if (targetNode->data < ancestor->data)
	            {
	                successor = ancestor; // This node could be a potential successor
	                ancestor = ancestor->left;
	            }
	            else
	            {
	                ancestor = ancestor->right;
	            }
	        }
	
	        if (successor != NULL)
	        {
	            cout << "Successor: " << successor->data << endl;
	        }
	        else
	        {
	            cout << "No successor found for the node with value " << val << endl;
	        }
	    }
	}
	
	void printLeafNodes(Node *root) 
	{ 
	    if (!root) 
	        return; 
	      
	    // if node is leaf node, print its data     
	    if (!root->left && !root->right) 
	    {
	        cout << root->data << " ";  
	        return; 
	    } 
	  
	    // if left child exists, check for leaf  
	    // recursively 
	    if (root->left) 
	       printLeafNodes(root->left); 
	          
	    // if right child exists, check for leaf  
	    // recursively 
	    if (root->right) 
	       printLeafNodes(root->right); 
	}
	
	void printNonLeafNodes(Node* root) 
	{ 
	    if (!root || (!root->left && !root->right)) 
	        return; 
	    
	    // if node is non-leaf node, print its data     
	    cout << root->data << " ";  
	    
	    // recursively check for non-leaf nodes in left and right subtrees
	    if (root->left) 
	       printNonLeafNodes(root->left); 
	      
	    if (root->right) 
	       printNonLeafNodes(root->right); 
	}
	
	int getLeafCount(Node* node) 
	{ 
	    if(node == NULL)     
	        return 0;
			 
	    if(node->left == NULL && node->right == NULL) 
	        return 1; 
			        
	    else
	        return getLeafCount(node->left)+ getLeafCount(node->right); 
	} 
	
	
	void isAVLTree()
    {
        if(isAVLTree(root))
		{
			cout<<"Tree is AVL\n";	
		}
		else
			cout<<"Tree is NOT AVL\n";	
    }

    bool isAVLTree(Node* node)
    {
        if (node == NULL)
            return true;

        int balance = getBalance(node);
        if (balance > 1 || balance < -1)
            return false;

        return isAVLTree(node->left) && isAVLTree(node->right);
    }


	int max(int a, int b)
	{
		if(a > b)
			return a;
		else
			return b;
	}
	
    int getBalance(Node* node)
	{
	    if (node == NULL)
	        return 0;
	
	    return max(maxDepth(node->left), maxDepth(node->right));
	}
	
	
	void deleteNode(int val)
	{
    	deleteNode(val, root);
	}

	void deleteNode(int val, Node*& temp)
	{
	    if (temp == nullptr)
	    {
	        cout << "\nThe value " << val << " not found in TREE.\n";
	        return;
	    }
	
	    if (val < temp->data)
	    {
	        deleteNode(val, temp->left);
	    }
	    else if (val > temp->data)
	    {
	        deleteNode(val, temp->right);
	    }
	    else
	    {
	        Node* temp2;
	        if (temp->right == nullptr)
	        {
	            temp2 = temp;
	            temp = temp->left;
	            delete temp2;
	        }
	        else if (temp->left == nullptr)
	        {
	            temp2 = temp;
	            temp = temp->right;
	            delete temp2;
	        }
	        else
	        {
	            temp2 = temp->right;
	            while (temp2->left)
	            {
	                temp2 = temp2->left;
	            }
	            temp2->left = temp->left;
	            temp2 = temp;
	            temp = temp->right;
	            delete temp2;
	        }
	    }
	}



    
};

int main()
{
	BST tree;
//	14, 15, 4, 9, 7, 18, 3, 5, 16, 20, 17
	tree.insert(14);
	tree.insert(15);
    tree.insert(4);
    tree.insert(9);
    tree.insert(7);
    tree.insert(18);
    tree.insert(3);
    tree.insert(5);
    tree.insert(16);
    tree.insert(20);
    tree.insert(17);
    tree.In_Order(tree.root);
    tree.search(16);
    tree.min();
    tree.max();
    tree.size();
    tree.findParent(tree.root, 16, -1);
    cout<<"Depth is: "<<tree.maxDepth(tree.root)<<endl;
    tree.successor(tree.root, 16);
    cout<<"Leaf Nodes: ";
	tree.printLeafNodes(tree.root);
	cout << endl;
    cout<<"Non Leaf Nodes: ";
	tree.printNonLeafNodes(tree.root);
	cout << endl;
    cout<<"\nLeaf count is: "<<tree.getLeafCount(tree.root)<<endl;
    tree.isAVLTree();
    cout<<"The value of root before deletion: "<<tree.root->data<<endl;
    tree.deleteNode(14);
    tree.In_Order(tree.root);
    cout<<"\nThe value of root after deletion: "<<tree.root->data<<endl;
    
return 0;
}