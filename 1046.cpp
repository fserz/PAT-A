# include <cstdio>
# include <algorithm>
using namespace std;

const int MAXN = 100010;
int A[MAXN], dis[MAXN];

int main(){
    int N, sum = 0;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &A[i]);//别忘了&
        sum += A[i];
        dis[i] = sum;
    }
    int M, right, left;
    scanf("%d", &M);
    for(int i = 1; i <= M; i++){
        scanf("%d%d", &left, &right);
        if(right < left) swap(left, right);
        int temp = dis[right - 1] - dis [left - 1];
        printf("%d\n", min(temp, sum - temp));
    }

    return 0;
}