# include <iostream>
# include <algorithm>
using namespace std;
int v[1010][1010];
bool visit[1000];
int n;//dfs要用n设成全局变量
void dfs(int node){
    visit[node] = true;
    for (int i = 1; i <= n; i++){//城市编号从1开始
     if (visit[i] == false && v[node][i] == 1)//对未访问的结点进行遍历
        dfs(i);
    }  
}
int main(){
    int  m, k, a, b;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        v[a][b] = v[b][a] = 1;
    }
    for (int i = 0; i < k; i++){
        fill(visit, visit + 1000, false);
        cin >> a;
        int cnt = 0;
        visit[a] = true;
        for (int j = 1; j <= n; j++){//城市从1开始编号
        if (visit[j] == false){
            dfs(j);
            cnt++;
            }
        }
        cout << cnt - 1 << endl;
        //cnt为连通分量数，连接n个连通分量需要n-1条边
    }
    return 0;
}