# include <iostream>
# include <vector>
using namespace std;
struct node{
    int data;
    node *left, *right;
};
void insert(node* &root, int data){//&为引用
    if (root == NULL){
        root =  new node;
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return;
        }
    if(root->data <= data) insert(root->right, data);
    else insert(root->left, data);
}
void preOrder(node *root, vector<int> &vi){//先序遍历结果存在vi
    if (root == NULL) return;
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}
void preOrderMirror(node *root, vector<int> &vi){
    if (root == NULL) return;
    vi.push_back(root->data);
    preOrderMirror(root->right, vi);
    preOrderMirror(root->left, vi);
}
void postOrder(node *root, vector<int> &vi){
    if (root == NULL) return;
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->data);
}
void postOrderMirror(node *root, vector<int> &vi){
    if (root == NULL) return;
    postOrderMirror(root->right, vi);
    postOrderMirror(root->left, vi);
    vi.push_back(root->data);
}
vector<int> origin, pre, preM, post, postM;
int main(){
    int n, data;
    node *root = NULL;//头结点
    cin >> n;
    for (int i = 0; i < n; i++){//建立二叉树
        cin >> data;
        origin.push_back(data);
        insert(root, data);//data插入二叉树
    }
    preOrder(root, pre);
    preOrderMirror(root, preM);
    postOrder(root, post);
    postOrderMirror(root, postM);
    if (origin == pre){
        cout << "YES" << endl;
        for (int i = 0; i < origin.size(); i++){
            cout << post[i];
            if (i < origin.size() - 1) cout << " ";
        }   
    }else if (origin == preM){
        cout << "YES" << endl;
        for (int i = 0; i < origin.size(); i++){
            cout << postM[i];
            if (i < origin.size() - 1) cout << " ";
        }   
    }else cout << "NO" << endl;
    return 0;
}