# include <cstdio>

int main(){
    int a[3], b[3], c;
    scanf("%d.%d.%d", &a[0], &a[1], &a[2]);
    scanf("%d.%d.%d", &b[0], &b[1], &b[2]);
    a[2] += b[2];
    c = a[2] /29;
    a[2] = a[2] % 29;

    a[1] = a[1] + b[1] + c;
    c = a[1] / 17;
    a[1] = a[1] % 17;

    a[0] = a[0] + b[0] + c;

    printf("%d.%d.%d", a[0], a[1], a[2]);
    return 0;
}