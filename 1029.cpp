# include <cstdio>
# include <algorithm>
using namespace std;
const int maxn = 1000050;
int a[maxn], b[maxn];
int n, m;

int main(){
    scanf("%d", &n);
    for (int  i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

int k = (n + m - 1) / 2, count = 0, i = 0, j = 0;
while (count < k)
{
    if (a[i] < b[j])  i++;
    else j++;
   count++;
}
if (a[i] < b[j]){
     printf("%d", a[i]);
}
else{
    printf("%d", b[j]);
}

return 0;
}
