# include <cstdio>

bool judge(int z[], int num){
    for(int i = 0; i <= num / 2; i++){ // i <= num / 2 等于号别忘了
        if(z[i] != z[num - i])
        return false;
    }
    return true;
}
int main(){
    int n, b, num = 0, z[100];
    scanf("%d%d", &n, &b);
    while(n != 0){
        z[num++] = n % b;
        n /= b;
    }
    bool flag = judge(z, num - 1);//num - 1 个不为零的数
    if(flag == true) printf("Yes\n");
    else printf("No\n");
    for(int i = num - 1; i >= 0; i--){
        printf("%d", z[i]);
        if(i != 0) printf(" ");
    }
    return 0;
}