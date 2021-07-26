# include <cstdio>
# include <algorithm>
using namespace std;
const int maxn = 1000050;
const int cmax = 2000100;
int a[maxn], b[maxn], c[cmax];


int main(){
    int n, m;
    for (int  i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    int k = 0, l = 0, j = 0;
    while (k != n - 1 && m != l - 1)
    {
        if(a[k] < b[l]){
            c[j++] = a[k++]; 
        }
         else if(a[k] > b[l]){
            c[j++] = b[l++]; 
        }
        else{
            c[j++] = a[k++];
            j++;
        }
    }
    if (k = n - 1)
    {
        
    }
        if (l = n - 1)
    {
        
    }
    
    
    
    return 0;
}