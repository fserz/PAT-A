# include <cstdio>
# include <queue>
using namespace std;
const int maxn = 10010;
struct rat
{
    int weight;
    int r; //排名
};
rat mouse[maxn];
int main(){
    queue<int>q;
    int ng, np, order;
    scanf("%d%d", &np, &ng);
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &mouse[i].weight);
    }
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &order);
        q.push(order);
    }
    int temp = np, group;
    while (q.size() != 1)
    {
        if (temp % ng == 0)
        group = np / ng;
        else
        group =np / ng + 1;  
        for (int i = 0; i < group; i++)
        {
            int k = q.front();
            for (int j = 0; j < ng; j++)
            { 
                if (i * ng + j >= temp)
                break;
                int front = q.front();
                if (mouse[front].weight > mouse[k].weight)
                     k = front;
                    mouse[front].r = group + 1;
                    q.pop();
            }
                q.push(k);
        } 
            temp = group;
    }
        mouse[q.front()].r = 1;
        for (int i = 0; i < np; i++)
        {
            printf("%d", mouse[i].r);
            if (i < np - 1)
            {
                printf(" ");
            }
        }   
        
        return 0;
}