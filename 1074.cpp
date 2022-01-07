# include <cstdio>
# include <iostream>
# include <algorithm>
using namespace std;
const int maxn = 10010;
struct node
{
 int data;
 int address;
 int next;
 int order;   
}nodeunion[maxn];
bool cmp(node a, node b){
    return a.order < b.order;
}

int main(){
int firstadd, n , k;
cin >>firstadd >> n >> k;
for (int i = 0; i < maxn; i++)
{
    nodeunion[i].order = maxn;
}
int p = firstadd; 
int count = 0;
while(nodeunion[p].address != -1){
    nodeunion[p].order = count;
    count++;
}
sort(nodeunion, nodeunion + k, cmp);

for (int i = 0; i < count / k; i++)
{
    for (int j = (i + 1) * k - 1; j > i * k; j--)
    {
       printf("%05d %d %05d", nodeunion[j].address, nodeunion[j].data, nodeunion[j - 1].address);
    }
    printf("%05d %d", nodeunion[i * k].address, nodeunion[i * k].data); //每分组最后一块
    if (i < count / k - 1)
    {
        printf("%05d\n", nodeunion[(i + 2) * k - 1].address);
    }
    else
    {
        if (count / k == 0)
        {
            printf("-1\n");
        }else
        {
            printf("%05d %d", nodeunion[(i + 1) * k].address, nodeunion[i].data);
            for (int i = count / k * k; i < count; i++)
            {
                printf("%05d %d", nodeunion[i].address,nodeunion[i].data);
                if (i < count - 1)
                {
                   printf("%05d", nodeunion[i + 1].address);
                }
                else
                {
                    printf("-1");
                }   
            }
        }   
    }       
}
    return 0;
}