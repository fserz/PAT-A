# include <cstdio>
# include <cmath>
# include <algorithm>
using namespace std;

struct student{
    int id;
    int grade[4];
}stu[2050];

char course[4] = {'A', 'C', 'M', 'E'};
int Rank[10000000][4] = {0};
int now;

bool cmp(student a, student b){
    return a.grade[now] > b.grade[now];
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3;
    }
    for(now = 0; now < 4; now++){
        sort(stu, stu + 4, cmp);
        Rank[stu[0].id][now] = 1;
        for (int  i = 1; i < n; i++){
            if(stu[i].grade[now] == stu[i - 1].grade[now])
            Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];
            else{
                Rank[stu[i].id][now] = i + 1; 
            }
        }   
    }
    int quiry;
    for(int i = 0; i < m; i++){
        scanf("%d", &quiry);
        if(Rank[quiry][0] == 0)
        printf("N/A");
        else{
            int k = 0;
            for(int j = 0; j < 4; k++){
                if(Rank[quiry][j] < Rank[quiry][k])
                k = j;
            }
            printf("%d %c\n", Rank[quiry][k], course[k]);
        }
        
    }
    return 0;
}