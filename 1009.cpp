# include <cstdio>
struct poly{
    int exp;//指数
    double cof;//系数
}poly[1010];

double ans[2010];
int main(){
    int k, n, number = 0;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d %lf", &poly[i].exp, &poly[i].cof);
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int exp;
        double cof;
        scanf("%d %lf", &exp, &cof);
        for(int j = 0; j < n; j++){
              ans[exp + poly[j].exp] += (cof * poly[j].cof);
          }
    }
    for(int i = 0; i <= 2000; i++){
        if (ans[i] != 0)
        number++;
    }
    printf("%d", number);
    for(int i = 2000; i >= 0; i--){
        if(ans[i] != 0.0){
        printf(" %d %.1f", i, ans[i]);
        }
    }
    return 0;
}