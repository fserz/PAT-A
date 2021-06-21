# include <cstdio>

struct studentIofo{
    char name[30];
    char gender;
    char id[12];
    int grade;
}M, F, person;
int main(){
    int n;
    scanf("%d", &n);
    M.grade = 101;
    F.grade = -1;
    for(int i = 0; i < n; i++){
        scanf("%s %c %s %d", person.name, &person.gender, person.id, &person.grade); 
        //上一行的%s %c %s %d之间必须带空格,只有两个数字%d%d和%d %d才都可以 
        if(person.gender == 'M' && M.grade > person.grade) M = person;
        else if(person.gender == 'F' && F.grade < person.grade) F = person;
        }
        if(F.grade == -1) printf("Absent\n");
        else printf("%s %s\n", F.name, F.id);
        if(M.grade == 101) printf("Absent\n");
        else printf("%s %s\n", M.name, M.id);
        if (F.grade == -1 || M.grade == 101) printf("NA\n");
        else printf("%d", F.grade - M.grade);
    return 0;
}