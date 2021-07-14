# include <cstdio>
const int N = 1010;
int Hashtable[N];
 int main(){
     int n, m, a;
     scanf("%d%d", &n, &m);
     for(int i = 0; i < n; i++){
         scanf("%d", &a);
         ++Hashtable[a];
     }
     for(int i = 1; i <= m; i++){ //i从1开始，因为值从1开始
         if(Hashtable[i] && Hashtable[m - i]){
             if(i == m - i && Hashtable[i] <= 1){
             continue;
         }
         printf("%d %d\n", i, m - i);
         return 0;
     }
     }
printf("No solution\n");
return 0;
 }