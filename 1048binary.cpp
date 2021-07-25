# include<cstdio>
# include<algorithm>
using namespace std;
const int maxn = 100050;
int a[maxn];

int Binary(int left, int right, int key){
    int mid;
    while(left <= right){
        mid =(left + right) / 2;
        if(key == a[mid]) 
        return mid;
       else if(key < a[mid])
        right = mid - 1;
        else left = mid + 1;   
    }
     return -1;
}
int main(){
    int N , M, i;
    scanf("%d%d", &N, &M);
    for(i = 0; i < N; i++)
    {
       scanf("%d", &a[i]);
    }
    sort(a, a + N);

for (i = 0; i < N; i++)
{
    int pos = Binary(0, N - 1, M - a[i]);
    if (pos != -1 && i != pos){ //别忘了i != pos
        printf("%d %d", a[i], a[pos]);
        break;
    }
    
}
if(i == N)
printf("No Solution\n");
return 0;
}