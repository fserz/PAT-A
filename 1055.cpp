# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
const int maxn = 100010;

int age[maxn] = {0};
srtuct person{
    int age, worths;
    char name[10];
} ps[maxn], valid[maxn];

bool(person a, person b){
    if(a.worths != b.worths) return a.worths > b.worths;
     else if(a.age !=  b.age) return a.age > b.age;

}

int main(){
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i = 0; i < n; i++){
        scanf("%s%d%d", &ps[i].name, &ps[i].age, &ps[i].worths);
    }
    sort(ps, ps + n, cmp);
    int vaildNum = 0;
    for(int i = 0; i < n; i++){
        if(age[ps[i].age] < 100)
    }



    return 0;
    }