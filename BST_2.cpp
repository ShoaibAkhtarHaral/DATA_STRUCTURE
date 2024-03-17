#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int p) {
        data = p;
        left = NULL;
        right = NULL;
    }
};

class BST {

public:
    Node* root;
    BST() {
        root = NULL;
    }

    bool isEmpty() {
        return root == NULL;
    }

    Node* getRoot() {
        return root;
    }

    void insert(int d) {
        root = insert(root, d);
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

    void search(int val) {
        bool check = searchBST(root, val);
        if (check) {
            cout << val << " found in the tree" << endl;
        } else {
            cout << val << " Not found in tree" << endl;
        }
    }

    bool searchBST(Node* node, int val) {
        if (node == NULL) {
            return false;
        }

        if (node->data == val) {
            return true;
        }

        if (val < node->data) {
            return searchBST(node->left, val);
        } else if (val > node->data) {
            return searchBST(node->right, val);
        }

        return false;
    }

    void Pre_Order(Node* root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << " ";
        Pre_Order(root->left);
        Pre_Order(root->right);
    }

    void In_Order(Node* root) {
        if (root == NULL) {
            return;
        }
        In_Order(root->left);
        cout << root->data << " ";
        In_Order(root->right);
    }

    void Post_Order(Node* root) {
        if (root == NULL) {
            return;
        }
        Post_Order(root->left);
        Post_Order(root->right);
        cout << root->data << " ";
    }

    void deleteNode(int num, Node*& temp)	//pass reference bcz we pass original root for delete node.
    {
	    if (temp == NULL) {
	        cout << "Not Found!" << endl;
	        return;
	    }
	    if (num < temp->data) deleteNode(num, temp->left);
	    else if (num > temp->data) deleteNode(num, temp->right);
	    else {
	        Node* temp2;
	        if (temp->right == NULL) {
	            temp2 = temp;
	            temp = temp->left;
	            delete temp2;
	        } else if (temp->left == NULL) {
	            temp2 = temp;
	            temp = temp->right;
	            delete temp2;
	        } else {
	            temp2 = temp->right;
	            while (temp2->left) temp2 = temp2->left;
	            temp2->left = temp->left;
	            temp2 = temp;
	            temp = temp->right;
	            delete temp2;
	        }
	    }
	}
};

int main() {
    BST root;

    if (root.isEmpty()) {
        cout << "Root is Empty" << endl;
    } else {
        cout << "Root is Not Empty" << endl;
    }

    while (true) {
        int choice;
        cout << "\n\n----------------------------------" << endl;
        cout << "1. Insert Value in TREE." << endl;
        cout << "2. Search by Value from TREE." << endl;
        cout << "3. Traverse the BST." << endl;
        cout << "4. Delete Value from TREE" << endl;
        cout << "5. EXIT" << endl;
        cout << "----------------------------------" << endl;

        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter the value which you want to INSERT in tree: ";
            cin >> val;
            root.insert(val);
        } else if (choice == 2) {
            int search;
            cout << "Enter the value which you want to SEARCH in tree: ";
            cin >> search;
            root.search(search);
        } else if (choice == 3) {
            int traverse;
            cout << "\nIn which Order you want to traverse the TREE" << endl;
            cout << "1. Pre-Order" << endl;
            cout << "2. In-Order" << endl;
            cout << "3. Post-Order" << endl;
            cin >> traverse;

            if (traverse == 1) {
                root.Pre_Order(root.getRoot());
            } else if (traverse == 2) {
                root.In_Order(root.getRoot());
            } else if (traverse == 3) {
                root.Post_Order(root.getRoot());
            } else {
                cout << "Invalid Input" << endl;
            }
        } else if (choice == 4) {
            int val;
            cout << "Enter Value to Delete :";
            cin >> val;
            root.deleteNode(val, root.root);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid Input" << endl;
        }
    }

    return 0;
}
