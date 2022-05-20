# include <iostream>
# include <algorithm>
using namespace std;
const int maxn = 1010;
int father[maxn];//存放父节点
int course[maxn] = {0};//
int isRoot [maxn] = {0};//isRoot[x]记录以x号结点作为根节点的社交网络多少人
int findfather(int x){
    int a = x;//先将x存一下
    while (x != father[x])//寻找根节点
        x = father[x];
    while (a != father[a]){//压缩路径
        int z = a;//保存a
        a = father[a];//向上
        father[z] = x;
    }
    return x;
}
void Union(int a, int b){//合并
    int faA = findfather(a);
    int faB = findfather(b);
    if (faA != faB)
        father[faA] = faB;
}
void init(int n){//初始father[i]为i，且father[i]为false
    for(int i = 1; i <= n; i++)
        father[i] = i;
}
bool cmp(int a, int b){
    return a > b;
}
int main(){
    int n, k, h;
    cin >> n;
    init(n);//初始化别忘
    for (int i = 1; i <= n; i++){//编号从1开始
       scanf("%d:", &k);
        for (int j = 0; j < k; j++){
            cin >> h;//输入第i个人喜欢的活动
            if (course[h] == 0){//如果h第一次有人喜欢
                course[h] = i;//令i喜欢h
            }
            Union(i, findfather(course[h]));
        }
    }
    for (int i = 1; i <= n; i++){
        isRoot[findfather(i)]++;//i的根节点人数+1
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (isRoot[i] != 0){//统计isRoot[i]不为0的,即集合个数
            ans++;
        }
    }
    cout << ans << endl;
    sort(isRoot + 1, isRoot + n + 1, cmp);
    for (int i = 1; i <= ans; i++){
        cout << isRoot[i];
        if (i != ans) cout << " ";
    }
    return 0;
}
