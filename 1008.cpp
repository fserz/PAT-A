# include <iostream>
int main(){
    int N, now = 0, to, total = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &to);
        if (to > now)
        {
            total += (to - now) * 6 + 5;
            now = to;
        }
        else {
            total += (now - to) * 4 + 5;
            now = to;
        }
    }
    printf("%d\n", total);
    return 0;
}