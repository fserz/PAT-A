# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;
struct node{
    node *left, *right;
    int v, height;//v为权重，height为高度
}*root;
node *newNode(int v){//生成一个新结点
    node* Node = new node;
    Node->v = v;
    Node->height = 1;
    Node->left = Node->right = NULL;
    return Node;
}
int getHight(node *root){//获取当前节点高度
    if (root == NULL) return 0;//空结点
    return root->height;
}
void updateHeight(node *root){//更新高度为，左右子树高度最大值+１
    root->height = max(getHight(root->left), getHight(root->right)) + 1;
}
int getBalanceFactor(node *root){//获取平衡因子
    return getHight(root->left) - getHight(root->right);
}
void L(node *&root){//左旋
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp); 
    root = temp;
}
void R(node *&root){//右旋
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp); 
    root = temp;
}
void insert(node *&root, int v){
    if(root == NULL){
        root = newNode(v);
        return ;
    }
    if (root->v > v){//v比根节点小
        insert(root->left, v);//插入左子树
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->left) == 1)//LL型
                R(root);
            if (getBalanceFactor(root->left) == -1){//LR型
                L(root->left);
                R(root);
            }  
        }
}else{
    insert(root->right, v);
    updateHeight(root);
    if(getBalanceFactor(root) == -2){
            if (getBalanceFactor(root->right) == -1)//RR型
                L(root);
            if (getBalanceFactor(root->right) == 1){//RL型
                R(root->right);
                L(root);
            }
        }
    }
}
int main(){
    int n, val;
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; i++){
        cin >> val;
        insert(root, val);
    }
    cout << root->v;
    return 0;
}

// int main(){//直接输出中位数的话可以得到17分
//     int n, temp;
//     cin >> n;
//     vector<int> a;
//     for (int i = 0; i < n; i++){
//         cin >> temp;
//         a.push_back(temp);
//     }
//     sort(a.begin(), a.end());
//     cout << a[n/2];
//     return 0;
// }