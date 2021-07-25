# include<cstdio>
# include<algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn];

void twopointers(int n, int m){//n为个数， m为和
    int k = 0, l = n - 1;//two pointers
    for(int i = 0 ;i < n && k < l; i++){    
        if (a[k] + a[l] == m){
        
        break;
        }
        else if(a[k] + a[l] > m){
            l--;
        }
        else{
            k++;
        }   
    }
    if(k < l)
    printf("%d %d", a[k], a[l]);
    else{
        printf("No Solution\n");
    }
}

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + N);
    twopointers(N , M);



    return 0;
}