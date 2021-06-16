# include <cstdio>
# include <algorithm>
using namespace std;
char S[3] = {'W', 'T', 'L'};

int main(){
    double ans = 1.0;
    double temp, a; //temp再此处不能赋值为0，要再下面每一行运行完赋值为0
    int idx;
    for(int i = 0; i < 3; i++){
        temp = 0.0;//每一行都要把temp重新还原成0再开始比较
    for(int j = 0; j < 3; j++){
    scanf("%lf", &a);
    if(a > temp){
        swap(a, temp);
        idx = j;
        }
    }
    ans *= temp;
    printf("%c ", S[idx]);
    }
    printf("%.2f\n", (ans * 0.65 - 1) * 2);
    return 0;
}
