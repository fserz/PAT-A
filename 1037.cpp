# include <cstdio>
# include <algorithm>
using namespace std;
const int maxn = 100050;
int prdoduct[maxn], coupon[maxn];

int main(){
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &prdoduct[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &coupon[i]);
    }
    sort(prdoduct, prdoduct + n);
    sort(coupon, coupon + m);
    int i = 0, j = 0, ans = 0;
    while(i < n && j <m && prdoduct[i] < 0 && coupon[j] < 0){
        ans += prdoduct[i] * coupon[j];
        i++;
        j++;
    }
    i = n - 1;
    j = m - 1;
    while (i >= 0 && j >= 0 && prdoduct[i] > 0 && coupon[j] > 0)
    {
              ans += prdoduct[i] * coupon[j];
        i--;
        j--;
    }
    printf("%d", ans);
    return 0;
}