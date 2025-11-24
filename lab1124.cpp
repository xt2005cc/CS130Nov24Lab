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

void BSTinsert(Node *root, int data){
    Node *current = root;
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
        cout << "Inserting" << v << "\n";
        BSTinsert(root, v);
    }
    cout << endl;
    printlevel(root,0); cout << endl;
    printlevel(root,1); cout << endl;
    printlevel(root,2); cout << endl;
    printlevel(root,3); cout << endl;




}