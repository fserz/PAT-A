# include<cstdio>
# include<vector>
# include<cstring>
# include <algorithm>
using namespace std;
const int N = 40020;
const int m = 26 * 26 * 26 * 10 +1;
vector<int> selectcoursse[m];

int getid(char name[]){
    int id;
    for(int i = 0; i < 3; i++){
     id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}


int main(){
    char name[5];
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; ++i){
        int course , x;
        scanf("%d%d", &course, &x);
        for(int i = 0; i < x; ++i){
            scanf("%s", name);
            int id = getid(name);
            selectcoursse[id].push_back(course);
        }
    }
    for(int i = 0; i < n; ++i){
        scanf("%s", name);
        int id = getid(name);
        sort(selectcoursse[id].begin(), selectcoursse[id].end());
        printf("%s %d", name, selectcoursse[id].size());
        for(int i = 0; i < selectcoursse[id].size(); ++i){
            printf(" %d", selectcoursse[id][i]);
        }
        printf("\n");
    } 
return 0;

}