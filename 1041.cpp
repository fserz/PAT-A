# include <cstdio>
int a[100001];
int Hashtable[10001] = {0};
int main(){
    int n;
    scanf("%d", &n);
    for (int  i = 0; i < n; i++){
        scanf("%d", &a[i]);
        Hashtable[a[i]]++;
    }
    for (int  i = 0; i < n; i++){
        if(Hashtable[a[i]] == 1){
        printf("%d", a[i]);
        return 0;
        }
    }
    printf("None\n");

    return 0;
}