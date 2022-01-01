# include<cstdio>
# include<cstring>
# include<algorithm>
# include<iostream>
# include<stack>

using namespace std;
const int maxn = 60;
int pre[maxn], in[maxn];
int num = 0;
int N;

struct node
{
    int data;
    node *lchild;
    node *rchild;
};

node* creat(int preL, int preR, int inL, int inR){   //构建二叉树
if(preL > preR)
return NULL;
 node* root = new node;
 root->data = pre[preL];
 int k;
 for ( k = inL; k <= inR; k++)
 {
     if (root->data == in[k])
     {
        break;
     }
 }
 int numleft = k - inL;
 root->lchild = creat(preL + 1, preL + numleft, inL, k - 1);
 root->rchild = creat(preL + numleft + 1, preR, k + 1, inR);
 return root;    
}
void postorder(node *root){
    if (root == NULL)
    {
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d", root->data);
    num++;
    if (num < N)
    {
        cout <<" ";
    }
    
}


int main(){
    int x, preindex = 0, inIndex =0;
    char str[6];
    scanf("%d", &N);
    stack<int>st;
    for (int i = 0; i < 2*N; i++)
    {
       scanf("%s", str);
       if(strcmp(str, "Push") == 0)// 入栈
       {
        scanf("%d", &x);
        pre[preindex] = x;
        preindex++;
        st.push(x);
       }
       else
       {
           in[inIndex] = st.top();
           st.pop();
           inIndex++;
       }
       
    }
    node *root =creat(0, N - 1, 0, N - 1);
    postorder(root);
    return 0;

}