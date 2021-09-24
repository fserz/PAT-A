# include <cstdio>
# include <cstring>
# include <queue>
# include <algorithm>
using namespace std;

const int maxn = 50;
struct node
{
    int data;
    node* lchild;
    node* rchild;
};
int pre[maxn], in[maxn], post[maxn];
int n;

node* create(int postL, int postR, int inL, int inR)//中序和后序
{
    if (postL > postR)
    return NULL;
    node* root = new node;
    root->data = post[postR];
    int k;
    for (k = inL; k <= inR; k++){
        if (in[k] == post[postR])
        break;
        }
    int numleft = k - inL;
    root->lchild = create(postL, postL + numleft - 1, inL, inL + k - 1);//左子树
    root->rchild = create(postL + numleft , postR - 1, k + 1, inR);//右子树
    return root;     
}
int num = 0;
void layer(node* root){
    queue<node*>q;
    q.push(root);
    while (!q.empty())
    {
        node* now = q.front();
        q.pop();
        printf("%d", now->data);
        num++;
        if(num < n)
        printf(" ");
        if (now->lchild != NULL)  q.push(now->lchild);
        if (now->rchild != NULL)  q.push(now->rchild);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
    }
    node* root = create(0, n - 1, 0, n - 1);
    layer(root);
    return 0;
}
