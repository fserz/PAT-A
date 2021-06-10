# include <cstdio>
const int max = 1010;
double p[max] = {};

int main(){
int k, m, n, count = 0;
double a;
scanf("%d", &k);
for(int i = 0; i < k; i++){
    scanf("%d%lf", &n, &a);
    p[n] += a;
}
scanf("%d", &m);
for(int i = 0; i < m; i++){
    scanf("%d%lf", &n, &a);
    p[n] += a;
}
for(int i = 0; i < max; i++){
    if(p[i] != 0) count++;
}
printf("%d", count);
for(int i = max; i >= 0; i--){
    if(p[i] != 0){
        printf(" %d %.1f", i, p[i]);//%.1f浮点数保留1位小数
    }
} 
return 0;
}