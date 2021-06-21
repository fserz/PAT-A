# include <cstdio>
# include <iostream>
using namespace std;

struct pNode{
    char id[18];
    int hh ,mm , ss;
}temp, ans1, ans2; //ans1签到，ans1签离
bool great(pNode node1, pNode node2){
    if(node1.hh != node2.hh) return node1.hh > node2.hh;
    if(node1.mm != node2.mm) return node1.mm > node2.mm;
    else{
        return node1.ss > node2.ss;
    }
    
}

int main(){
    int M;
    ans1.hh = 24, ans1.mm = 60, ans1.ss = 60;
    ans2.hh = 0, ans2.mm = 0, ans2.ss = 0;
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%s%d:%d:%d", temp.id, &temp.hh, &temp.mm, &temp.ss);
        if(great(ans1, temp)) ans1 = temp;
        scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);//第二次只读入时间
        if(great(temp, ans2)) ans2 = temp;
    }


    printf("%s %s", ans1.id, ans2.id);
    return 0;
}