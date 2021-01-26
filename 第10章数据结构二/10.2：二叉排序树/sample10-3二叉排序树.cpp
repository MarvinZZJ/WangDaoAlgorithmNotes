/*
例题10.3	二叉排序树（华中科技大学复试上机题	
http://t.cn/Ai9PAkkv
*/

#include <iostream>
#include <cstdio>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *lchild, *rchild;
    TreeNode(int d): data(d), lchild(nullptr), rchild(nullptr){}
};

void Insert(TreeNode* &root, int x, int father){
    if(root == nullptr){
        cout << father << endl;
        root = new TreeNode(x);
    }
    else if(root->data > x){
        Insert(root->lchild, x, root->data);
    }
    else{
        Insert(root->rchild, x, root->data);
    }
    return;
}

int main(){
    int n;
    while(cin >> n){
        TreeNode *root = nullptr;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            Insert(root, x, -1);
        }
    }
    return 0;
}
