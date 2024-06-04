#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    void insert(int data) {
        root = insertNode(root, data);
    }

    Node* insertNode(Node* temp, int data) {
        if (temp == nullptr) {
            return new Node(data);
        }
        if (data < temp->data) {
            temp->left = insertNode(temp->left, data);
        } else if (data > temp->data) {
            temp->right = insertNode(temp->right, data);
        }
        return temp;
    }

    void printInOrder(Node* temp) {
        if (temp == nullptr) {
            return;
        }
        printInOrder(temp->left);
        cout << temp->data << " ";
        printInOrder(temp->right);
    }
    Node* createMirrorTree(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* mirrorRoot = new Node(root->data);
        mirrorRoot->left = createMirrorTree(root->right);
        mirrorRoot->right = createMirrorTree(root->left);

        return mirrorRoot;
    }
};


int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(8);
    bst.insert(2);
    bst.insert(4);

    cout << "Orignal Tree:" << endl;
    bst.printInOrder(bst.root);

    Node* mirrorTree = bst.createMirrorTree(bst.root);
    cout << "\n\nMirrored Tree:" << endl;
    bst.printInOrder (mirrorTree);

    return 0;
}
