# include<cstdio>
# include<algorithm>
# include<vector>
# include<cstring>
using namespace std; 
const int maxn = 40020;
const int maxc = 2520;

char name[maxn][6];//至少是5，字符数组长度一定要比实际存储长度大1
vector<int> course[maxc];
bool cmp(int a, int b){
    return strcmp(name[a], name[b]) < 0;
}

int main(){
    int n, k, c, courseID;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i){
        scanf("%s%d", name[i], &c);
        for(int j = 0; j < c; ++j){
            scanf("%d", &courseID);
            course[courseID].push_back(i);
        }
    }
    for(int i = 1; i <= k; i++){
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        for(int j = 0; j < course[i].size(); j++){
            printf("%s\n", name[course[i][j]]);
        }
    }
    return 0;
}