#include <iostream> // Required for input/output operations like std::cout

// Using the standard namespace to avoid prefixing std:: before standard library elements
using namespace std;

// --- Node Class Definition ---
// Represents a single node in the Binary Search Tree.
// Each node holds an integer data value and pointers to its left and right children.
class Node
{
public:
    int data;    // The data value stored in the node
    Node *left;  // Pointer to the left child node
    Node *right; // Pointer to the right child node

    // Constructor for the Node class
    // Initializes a new node with the given data and sets child pointers to nullptr.
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// --- BinarySearchTree Class Definition ---
// Implements a Binary Search Tree data structure.
// Provides methods for inserting, searching, displaying (in-order traversal),
// and removing nodes from the tree.
class BinarySearchTree
{
private:
    Node *root; // Pointer to the root node of the tree

    // Helper function for recursive insertion.
    // Inserts a new node into the subtree rooted at 'root'.
    Node *insertHelper(Node *root, Node *node)
    {
        int data = node->data;

        if (root == nullptr)
        {
            root = node;
            return root;
        }
        else if (data < root->data)
        {
            root->left = insertHelper(root->left, node);
        }
        else
        {
            root->right = insertHelper(root->right, node);
        }
        return root;
    }

    // Helper function for recursive in-order display (traversal).
    // Prints the data of nodes in ascending order.
    void displayHelper(Node *root)
    {
        if (root != nullptr)
        {
            displayHelper(root->left);
            cout << root->data << endl; // Changed std::cout to cout, std::endl to endl
            displayHelper(root->right);
        }
    }

    // Helper function for recursive search.
    // Searches for a data value within the subtree rooted at 'root'.
    bool searchHelper(Node *root, int data)
    {
        if (root == nullptr)
        {
            return false;
        }
        else if (root->data == data)
        {
            return true;
        }
        else if (root->data > data)
        {
            return searchHelper(root->left, data);
        }
        else
        {
            return searchHelper(root->right, data);
        }
    }

    // Helper function for recursive removal.
    // Removes a node with the specified data from the subtree rooted at 'root'.
    Node *removeHelper(Node *root, int data)
    {
        if (root == nullptr)
        {
            return root;
        }
        else if (data < root->data)
        {
            root->left = removeHelper(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = removeHelper(root->right, data);
        }
        else
        { // Node found
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root; // Free memory
                root = nullptr;
            }
            else if (root->right != nullptr)
            { // Find a successor to replace this node
                root->data = successor(root);
                root->right = removeHelper(root->right, root->data);
            }
            else
            { // Find a predecessor to replace this node
                root->data = predecessor(root);
                root->left = removeHelper(root->left, root->data);
            }
        }
        return root;
    }

    // Finds the least value below the right child of this root node (successor).
    int successor(Node *root)
    {
        root = root->right;
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root->data;
    }

    // Finds the greatest value below the left child of this root node (predecessor).
    int predecessor(Node *root)
    {
        root = root->left;
        while (root->right != nullptr)
        {
            root = root->right;
        }
        return root->data;
    }

public:
    // Constructor for the BinarySearchTree class.
    // Initializes an empty tree by setting the root to nullptr.
    BinarySearchTree()
    {
        root = nullptr;
    }

    // Inserts a new node into the tree.
    void insert(Node *node)
    {
        root = insertHelper(root, node);
    }

    // Displays the elements of the tree in-order (sorted order).
    void display()
    {
        displayHelper(root);
    }

    // Searches for a specific data value in the tree.
    // Returns true if the data is found, false otherwise.
    bool search(int data)
    {
        return searchHelper(root, data);
    }

    // Removes a node with the specified data from the tree.
    void remove(int data)
    {
        if (search(data))
        {
            root = removeHelper(root, data);
        }
        else
        {
            cout << data << " could not be found" << endl; // Changed std::cout to cout, std::endl to endl
        }
    }

    // Destructor to free memory when the tree is destroyed
    ~BinarySearchTree()
    {
        // Implement a post-order traversal to delete nodes
        // This is a simple example; for large trees, iterative deletion is better
        deleteTree(root);
    }

private:
    void deleteTree(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
};

// --- Main Function Structure ---
// The entry point of the program.
// Demonstrates the usage of the BinarySearchTree class.
int main()
{
    // Binary Search Tree = A tree data structure, where each node is greater than its left child,
    //                      but less than its right.

    // Benefit: easy to locate a node when they are in this order
    // Time complexity: best case O(log n), worst case O(n)
    // Space complexity: O(n)

    BinarySearchTree tree;

    tree.insert(new Node(5));
    tree.insert(new Node(1));
    tree.insert(new Node(9));
    tree.insert(new Node(2));
    tree.insert(new Node(7));
    tree.insert(new Node(3));
    tree.insert(new Node(6));
    tree.insert(new Node(4));
    tree.insert(new Node(8));

    cout << "Displaying tree (in-order traversal):" << endl; // Changed std::cout to cout, std::endl to endl
    tree.display();
    cout << "------------------------------------" << endl; // Changed std::cout to cout, std::endl to endl

    cout << "Searching for 7: " << (tree.search(7) ? "Found" : "Not Found") << endl;   // Changed std::cout to cout, std::endl to endl
    cout << "Searching for 10: " << (tree.search(10) ? "Found" : "Not Found") << endl; // Changed std::cout to cout, std::endl to endl
    cout << "------------------------------------" << endl;                            // Changed std::cout to cout, std::endl to endl

    cout << "Removing 5 (root node):" << endl; // Changed std::cout to cout, std::endl to endl
    tree.remove(5);
    cout << "Displaying tree after removing 5:" << endl; // Changed std::cout to cout, std::endl to endl
    tree.display();
    cout << "------------------------------------" << endl; // Changed std::cout to cout, std::endl to endl

    cout << "Removing 1 (leaf node):" << endl; // Changed std::cout to cout, std::endl to endl
    tree.remove(1);
    cout << "Displaying tree after removing 1:" << endl; // Changed std::cout to cout, std::endl to endl
    tree.display();
    cout << "------------------------------------" << endl; // Changed std::cout to cout, std::endl to endl

    cout << "Removing 9 (node with one child):" << endl; // Changed std::cout to cout, std::endl to endl
    tree.remove(9);
    cout << "Displaying tree after removing 9:" << endl; // Changed std::cout to cout, std::endl to endl
    tree.display();
    cout << "------------------------------------" << endl; // Changed std::cout to cout, std::endl to endl

    cout << "Attempting to remove 100 (not found):" << endl; // Changed std::cout to cout, std::endl to endl
    tree.remove(100);
    cout << "------------------------------------" << endl; // Changed std::cout to cout, std::endl to endl

    return 0;
}
