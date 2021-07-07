# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

const int maxn = 60;

struct student{
    char name[12];
    char id[12];
    int grade;
};
student stu[maxn];
bool cmp(student a, student b){
    return a.grade > b.grade;
}

int main(){
    int n, left ,right;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
    }
    scanf("%d%d", &left, &right);
sort(stu, stu + n, cmp);
bool flag = false;
for(int i = 0; i < n; i++){
    if(stu[i].grade >= left && stu[i].grade <= right){
        printf("%s %s\n", stu[i].name, stu[i].id);
        flag = true; //存在区间内的分数
        }
} 
if(flag == false){ //不存在区间内的分数
    printf("NONE");
}
    return 0;
}