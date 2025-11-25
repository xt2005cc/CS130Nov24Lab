#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node (int data): data(data), left(nullptr), right(nullptr){}
};

void printlevel(Node *root, int level){
    if(root==nullptr) return;
    if(level == 0) cout << root->data << " ";
    else if (level > 0){
        printlevel(root->left, level-1);
        printlevel(root->right, level-1);

    }
}

void BSTinsert(Node *&root, int data){
    Node *current = root;
    if (root == nullptr){
        root = new Node(data);
        return;
    }
    while(current != nullptr){
        if (data < current->data){
            if (current->left == nullptr){
                current->left = new Node(data);
                return;
            }else
                current = current->left;
            }
             else {
                if (current->right == nullptr){
                    current->right = new Node(data);
                    return;
                }else
                current = current->right;
        }
    }
}

Node *BSTdelete(Node *root, int data){
    Node *current = root; Node *parent = nullptr;
    if(root == nullptr) return root;
    while(current != nullptr && current->data != data){
        parent = current;
        if (data<current->data)
        current = current->left;
        else
        current = current->right;
    }
    if(current == nullptr) return root;
    
    if (current->left == nullptr && current->right == nullptr){
        if(parent == nullptr){
            delete current;
            return nullptr;
        }
        if (parent->left ==current)
            parent->left = nullptr;
            else
            parent->right = nullptr;
            delete current;
            return root;
    }
    if (current->left == nullptr || current->right == nullptr){
        Node *child = (current->left != nullptr)? current->left :current->right;
        if(parent == nullptr){
            delete current;
            return child;
        }
        if (parent->left == current)
        parent->left = child;
        else
        parent->right = child;
        delete current;
        return root;
    }

    Node *successor = current->right;
    Node *successorParent = current;
    while(successor->left != nullptr){
        successorParent = successor;
        successor = successor->left;
    }
    current->data = successor->data;
    if(successorParent->left == successor)
        successorParent->left = nullptr;
        else
        successorParent->right = nullptr;
        delete successor;
        return root;
}
int treeHeight(Node *root){
    if(root == nullptr) return -1;
    if (root->left == nullptr && root->right == nullptr) return 0;
    return 1+ max(treeHeight(root->left), treeHeight(root->right));
}

int main(){
    vector<int> data = {5,3,8,2,4,7,9,1,6};
    Node *root = nullptr;
    for (auto v: data)
        BSTinsert(root, v);
        int depth = treeHeight(root);
        for (int i = 0; i <= depth; i++){
            printlevel(root,i);
            cout << endl;
        }
    int target = 1;
    BSTdelete(root, target);
    for (int i = 0; i <=depth; i++){
        printlevel(root,i);
        cout << endl;
        }
    }