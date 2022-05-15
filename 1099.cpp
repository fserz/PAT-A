# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;
const int maxn = 110;
int n, in[maxn], num = 0;
struct node{
    int data;
    int lchild, rchild;
}Node[maxn];
//将给定的结点从大到小排列，即得二叉树中序序列，按中序序列填入二叉树，就可以形成BST
void inorder(int root){
    if(root == -1) return;
    inorder(Node[root].lchild);
    Node[root].data = in[num++];//输入序列中的整数
    inorder(Node[root].rchild);
}
void BFS(int root){
    queue<int> q;
    q.push(root);
    num = 0;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        printf("%d", Node[now].data);
        num++;
        if(num < n) printf(" ");
        if (Node[now].lchild != -1) q.push(Node[now].lchild);
        if(Node[now].rchild != -1) q.push(Node[now].rchild);
    }
}
int main(){
    int  left, right;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &left, &right);
       Node[i].lchild = left; 
       Node[i].rchild = right;
        }
    for (int i = 0; i < n; i++)
        cin >> in[i];
    sort(in, in + n);//从小到大，中序序列
    inorder(0);//0为根结点进行中序
    BFS(0);//输出层序
    return 0;
}