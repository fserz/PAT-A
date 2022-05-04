# include <iostream>
#include <algorithm>
# include <vector>
const int maxn = 110;
using namespace std;
int n, m, S; 
int path[maxn];//记录路径
struct node{
    int weight;
    vector<int> child;
}Node[maxn];
bool cmp(int a, int b){
    return Node[a].weight > Node[b].weight;
}
void DFS(int index, int numNode, int sum){//index为当前结点，numNode为当前路径结点总数,sum为权和
    if (sum > S) return;
    if (sum == S){
        if (Node[index].child.size() != 0) return;//不是叶结点直接退出
        for (int i = 0; i < numNode; i++){//到达叶子结点，输出存储的路径
            printf("%d", Node[path[i]].weight);
            if (i < numNode - 1) printf(" ");
            else printf("\n");
        }
        return;      
    }
    for (int i = 0; i < Node[index].child.size(); i++){//s < sum的情况，枚举所有结点
        int child = Node[index].child[i];//结点child的第i的子节点编号
        path[numNode] = child;//将结点child加入path末尾
        DFS(child, numNode + 1, sum + Node[child].weight);
    }
}
int main(){
    int id, k, child;
    cin >> n >> m >> S;
    for (int i = 0; i < n; i++){
        scanf("%d", &Node[i].weight);
        }
        for (int i = 0; i < m; i++){
            cin >> id >> k;
            for(int j = 0; j < k; j++){
            cin >> child;
            Node[id].child.push_back(child);//child是i的孩子
            }
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);//对孩子按权重从大到小排序
        }
    path[0] = 0;
    DFS(0, 1, Node[0].weight);
    return 0;
}