#include <iostream>
#include <vector>
using namespace std;
#define COUNT 10

// Definition of a Node using struct
struct Node {
    int num;
    Node* left;          // Pointer to left child
    Node* right;         // Pointer to right child

    // Constructor
    Node(int data) {
        num = data;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a new value in BST
Node* insert(Node* node, int data) {
    // If the current node is NULL, create and return thea new node
    if (node == NULL) {
        return new Node(data);
    }
    // If the data already exists in the tree, print the message
    else if ((*node).num == data) {
        cout << "Data already in the tree!!";
        return node;
    }
    // If the new data is greater, insert it in the right subtree
    else if ((*node).num < data) {
        (*node).right = insert((*node).right, data);
    }
    // If the new data is less, insert it in the left subtree
    else {
        (*node).left = insert((*node).left, data);
    }
    return node;
}

// Function for in-order traversal
void inorder(Node* root, vector<int>& inordered) {
    if (root != NULL) {
        inorder(root->left, inordered);

        // add the current node in the vector
        inordered.push_back(root->num);

        inorder(root->right, inordered);
    }
}


//this code is taken from geeksforgeeks to visulize the tree, url- https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void print2DUtil(Node* root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->num << "\n";

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(Node* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}



int main() {
    int k;
    //GIVEN LIST
    vector<int> nums = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
    Node* root = new Node(65);  // Create the root node
    nums.erase(nums.begin() + 7);  // Remove the 8th element (index 7) from the vector



    // insert the remaining numbers into the BST
    //this loop inserts the elements from middle out to make the tree balanced as possible////////////////////////////////////////
    // this is my attempt to make the tree as balanced as possible without using AVL

    while (nums.size() > 0) {
        root = insert(root, nums[nums.size() / 4]);
        nums.erase(nums.begin() + nums.size() / 4);
        if(nums.empty()){
                break;
        }
        root = insert(root, nums[(3*nums.size()) / 4]);
        nums.erase(nums.begin() + (3*nums.size()) / 4);
        if(nums.empty()){
                break;
        }

        root = insert(root, nums[nums.size() / 6]);
        nums.erase(nums.begin() + nums.size() / 6);
        if(nums.empty()){
                break;
        }
        root = insert(root, nums[(5*nums.size()) / 6]);
        nums.erase(nums.begin() + (5*nums.size()) / 6);
        if(nums.empty()){
                break;
        }

        root = insert(root, nums[nums.size() / 8]);
        nums.erase(nums.begin() + nums.size() / 8);
        if(nums.empty()){
                break;
        }

        root = insert(root, nums[(7*nums.size()) / 8]);
        nums.erase(nums.begin() + (7*nums.size()) / 8);
    }

    vector<int> inordered;  // vector to store elements in sorted order
    inorder(root, inordered);  // performing in-order traversal to fill the vector

    print2D(root); //visulize the tree
    // Output the k-th smallest element
    cout <<endl <<"Enter K: ";
    cin >> k;
    cout << k << "th smallest element is " << inordered[k - 1] << endl;


    return 0;
}
