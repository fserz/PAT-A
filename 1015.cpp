# include <cstdio>
# include <cmath>

bool isprime(int n){
    if(n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++){
        if (n%i == 0)  return false;
        }
    return true;
    }
int a[100];
int main(){
    int n, radix;
    int len = 0; 
    while (scanf("%d", &n) != EOF)
    {
        if (n < 0) break;
        scanf("%d", &radix);
        if (isprime(n) == false)
        printf("No\n");
        else
        {
            do
            {
                a[len++] = n % radix;
                n /= radix;
            } while (n != 0);
            for(int i = 0; i < len; i++){
                n = a[i] + n * radix;
            }
            if (isprime(n))  printf("Yes\n");
            else printf("No\n");

        }
       
    }
return 0;
}