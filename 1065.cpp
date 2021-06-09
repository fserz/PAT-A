# include <cstdio>

int main(){
    int T, tcase = 1;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        bool flag;
        long long sum = a + b;
        if(a > 0 && b > 0 && sum < 0) flag = true;
        else if(a < 0 && b < 0 && sum > 0) flag = false;
        else if(sum > c) flag = true;
        else flag = false;
        if(flag == true){
        printf("Case #%d: true\n", tcase);
        }else{
           printf("Case #%d: false\n", tcase);
        }
        ++tcase;
    }
    return 0;
}