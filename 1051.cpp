# include<cstdio>
# include<iostream>
# include<algorithm>
# include<stack>
using namespace std;
const int maxn = 10010;
int array[maxn];

int main(){
    stack<int>st;
    int M, N, K;
    scanf("%d%d%d", &M, &N, &K);

    for (int i = 0; i < K; i++)//运行k次
    {
        bool flag = true;
        int currunt = 1;
    for (int i = 1; i <= N; i++)//读入数据
        scanf("%d", &array[i]);
    for (int j = 1; j <= N; j++)
    {
        st.push(j);
        if (st.size() > M)
        {
            flag = false;
            break;
        }
        else
        {
            if (!st.empty() && st.top() == array[currunt]) //top取栈顶
            {
                st.pop();
                currunt++;
            }
        } 
    }
    if (flag == true && st.empty())
        printf("YES\n");
    else
        printf("NO\n");
   }
   return 0; 
}