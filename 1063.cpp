# include<cstdio>
# include<set>
using namespace std;
const int N = 52;//不能是50，否则N只能0-49会越界
set<int> st[N];


void compare(int a, int b){
    int samenum = 0, totlenum = st[b].size();
    for(set<int>::iterator it = st[a].begin(); it != st[a].end(); it++){
        if(st[b].find(*it) != st[b].end()) samenum++;
        else totlenum++;
    }
    printf("%.1f%\n", samenum * 100.0 / totlenum);

}
int main(){
    int n, k, v, m, x, y;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){ //i必须从1开始，下面的集合编号从1开始
        scanf("%d", &k);
        for(int j = 0; j < k; ++j){
            scanf("%d", &v);
            st[i].insert(v);
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &x, &y);
        compare(x, y);
    }


    return 0;
}