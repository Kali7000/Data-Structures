#include <bits/stdc++.h>

using namespace std;

// struct to define node
struct Node {
    vector<int> nodes;        // store keys
    vector<Node*> pNodes;     // store pointers to child nodes
    Node() {}

    int getSize() { // size getter
        return nodes.size();
    }


    // add data to node, return true if full
    bool addNum(int N) {
        nodes.push_back(N);
        if (getSize() >= 5) {
            return true;
        }
        return false;
    }

    // Split the node if the node if full, use the addNum funtion to see if it's full or not
    int split(Node*& newRightNode) {
        newRightNode = new Node();

        //if full move last 2 elements to the new node
        newRightNode->nodes.push_back(nodes[3]);
        newRightNode->nodes.push_back(nodes[4]);

        // then remove those last 2 elements from the current node
        nodes.pop_back();
        nodes.pop_back();

        int temp = nodes[2]; //save and remove the middle element
        nodes.pop_back();

        return temp; // add the middle element to parent node
    }
};


//Adding a new element to the tree
void insert(Node*& root, int key) {
    if (root->addNum(key)) { // if node is full- split
        Node* newRightNode;
        int middle = root->split(newRightNode);

        Node* newRoot = new Node();
        newRoot->nodes.push_back(middle);
        newRoot->pNodes.push_back(root);
        newRoot->pNodes.push_back(newRightNode);

        root = newRoot; // save new root
    }
}

// recursive search funtion, and save the traversed tree in result
void searchRange(Node* node, int N, int lowerBound, int upperBound, vector<int>& result) {
    if (!node) return; //check the validity
    //check current node
    for (int key : node->nodes) {
        if (key >= lowerBound && key <= upperBound) {
            result.push_back(key);
        }
    }
    //loop through child nodes
    for (Node* child : node->pNodes) {
        searchRange(child, N, lowerBound, upperBound, result);
    }
}

//print funtion
void printBTree(Node* node) {
    if (!node) return;
    // Traverse through child nodes
    for (size_t i = 0; i < node->nodes.size(); ++i) {
        // Print the child node recursively
        if (i < node->pNodes.size()) {
            printBTree(node->pNodes[i]);
        }
        // Print the result
        cout << node->nodes[i] << " ";
    }
}




int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    set<int> uniqueIntegers;
    Node* root = new Node();

    // saving only unique random numbers using set
    srand(time(0));
    while (uniqueIntegers.size() < N) {
        int num = rand() % (3 * N + 1);
        uniqueIntegers.insert(num);
    }

    //convert set to vector
    vector<int> randomIntegers(uniqueIntegers.begin(), uniqueIntegers.end());

    // Insert the random nums in the B-tree one by one
    for (int i = 0; i < N; ++i) {
        insert(root, randomIntegers[i]);
    }

    // Search for keys in the given range
    vector<int> result;
    searchRange(root, N, N, 2 * N, result);

    cout<<"The B-Tree: "<<endl;
    printBTree(root);


    //print the keys in the given range
    cout << endl<<endl;
    cout << endl<<"Keys in the range (" << N << ", " << 2 * N << "): ";
    for (int key : result) {
        cout << key << " ";
    }
    cout << endl;

    return 0;
}
