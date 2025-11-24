#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node (int data): data(data), left(nullptr), right(nullptr){}
};

int treeHeight(Node *root){
    if(root == nullptr) return -1;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return max(leftHeight, rightHeight) + 1;

}

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
            }else{
                current = current->left;
            }
            } else {
                if (current->right == nullptr){
                    current->right = new Node(data);
                    return;
                }else{
                current = current->right;
                }
        }
    }
}

int main(){
    vector<int> data = {5,3,8,2,4,7,9,1,6};
    Node *root = nullptr;
    for (auto v: data){
        cout << "Inserting " << v << "\n";
        BSTinsert(root, v);
        int depth = treeHeight(root);
        for (int i = 0; i <+depth; i++){
            printlevel(root,i);
            cout << endl;
        }
    int target = 1;
    Node *current = root; Node *parent = nullptr;
    while(current != nullptr && current ->data != target){
        if (target < current->data)
            current = current->left;
            else
            current = current->right;
    }
    cout << "Found target " << current->data << "Parent " << parent->data << endl;
    parent->left = nullptr;
    delete current;
    for (int i = 0; i <+depth; i++){
        printlevel(root,i);
        cout << endl;
        }
    }
}