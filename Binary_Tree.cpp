#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }

    void deleteTree(Node *leaf)
    {
        if (leaf != NULL)
        {
            deleteTree(leaf->left);
            deleteTree(leaf->right);
            delete leaf;
        }
    }

    Node *parent(Node *curr, Node *p, Node *par)
    {
        if (curr == NULL)
        {
            return NULL;
        }
        else if (curr == p)
        {
            return par;
        }
        else
        {
            Node *t = parent(curr->left, p, curr);
            if (t != NULL)
            {
                return t;
            }
            else
            {
                t = parent(curr->right, p, curr);
                if (t != NULL)
                {
                    return t;
                }
            }
        }
        return NULL;
    }

    int maxDepth(Node *n)
    {
        if (n == NULL)
        {
            return -1;
        }
        else
        {
            int leftDepth = maxDepth(n->left);
            int rightDepth = maxDepth(n->right);
            if (leftDepth > rightDepth)
            {
                return (leftDepth + 1);
            }
            else
            {
                return (rightDepth + 1);
            }
        }
    }

    Node *sibling(Node *root, Node *curr)
    {
        // find its parent
        Node *par = parent(root, curr, root);
        if (par->left == curr)
        {
            return par->right;
        }
        else
        {
            return par->left;
        }
    }

    void preOrder(Node *n)
    {
        if (n == NULL)
            return;
        cout << n->val << "\t";
        preOrder(n->left);
        preOrder(n->right);
    }
    void inOrder(Node *n)
    {
        if (n == NULL)
            return;
        inOrder(n->left);
        cout << n->val << "\t";
        inOrder(n->right);
    }

    void postOrder(Node *n)
    {
        if (n == NULL)
            return;
        postOrder(n->left);
        postOrder(n->right);
        cout << n->val << "\t";
    }
};

int main()
{
    Tree t;
    t.root = new Node(10);
    t.root->left = new Node(9);
    t.root->right = new Node(8);
    t.root->left->left = new Node(1);
    t.root->left->right = new Node(6);

    Node *n = t.root->left->right;
    Node *par = t.parent(t.root, n, t.root);
    if (par == NULL)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Parent of: " << n->val << " is: " << par->val << endl;
    }

    Node *sib = t.sibling(t.root, n);
    if (sib == NULL)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Sibling of: " << n->val << " is: " << sib->val << endl;
    }

    int depth = t.maxDepth(t.root);
    cout << "Depth of root is: " << depth << endl;

    cout << "\nPreorder traversal: " << endl;
    t.preOrder(t.root);

    cout << "\nInorder traversal: " << endl;
    t.inOrder(t.root);

    cout << "\nPostorder traversal: " << endl;
    t.postOrder(t.root);
}