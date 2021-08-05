# include <cstdio>
# include <cmath>
# include <algorithm>
using namespace std;
const int maxn = 100050;



struct node
{
    int address, key, next;
    bool flag;
}Node[maxn];

bool cmp(node a, node b){
    if(a.flag == false || b.flag == false)
    return a.flag > b.flag;
    else return a.key < b.key;
}

int main(){
    for (int i = 0; i < maxn; i++)
    {
        Node[i].flag = false;
    }
    
    int N, begin, address;
    scanf("%d%d", &N, &begin);
    for (int i = 0; i < N; i++){
        scanf("%d", &address);
        scanf("%d%d", &Node[address].key, &Node[address].next);
        Node[address].address = address;
    }
    int count = 0, p = begin;
    while (p != -1)
    {
        Node[p].flag = true;
        count++;
        p = Node[p].next;
        }
    if (count == 0){
         printf("0 -1\n");
         }
         else{
             sort(Node, Node + maxn, cmp);
             printf("%d %05d\n", count, Node[0].address);//%05d 别写错了
             }
    for (int i = 0; i < count; i++)
    {
        if (i != count - 1)
        {
            printf("%05d %d %05d\n", Node[i].address, Node[i].key, Node[i + 1].address);//此时要输出Node[i + 1].address，不能next已经不是初试的顺序
        }else
        {
            printf("%05d %d -1\n", Node[i].address, Node[i].key);
        }
        
    }

        return 0;
}