# include <iostream>
# include <algorithm>
# include <cmath>
using namespace std;
long long gcd(long long a, long long b){//最大公约数
    return !b ? a : gcd(b, a % b);
}
void func(long long m, long long n){
    if (m * n == 0){
        printf("%s", n == 0 ? "Inf" : "0");
        return;//n=0直接返回
    }
    bool flag = ((m < 0 && n > 0) || (m > 0 && n < 0)); //不能通过m*n<0来判断，这样可能会溢出
    m = abs(m);
    n = abs(n);
    long long x = m / n;
    printf("%s", flag ? "(-" : "");
    if(x != 0) printf("%lld", x);
    if (m % n == 0){//判定整数
        if(flag) printf(")");
        return;//整数输出括号后直接返回
    }
    m = m - x * n;
    if(x != 0) printf(" ");
    long long t = gcd(m, n);
    m = m / t; n = n / t;
    printf("%lld/%lld%s", m, n, flag ? ")" : "");     
}
int main(){
    long long a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    func(a, b); printf(" + "); func(c, d); printf(" = "); func(a * d + b * c, b * d);printf("\n");
    func(a, b); printf(" - "); func(c, d); printf(" = "); func(a * d - b * c, b * d);printf("\n");
    func(a, b); printf(" * "); func(c, d); printf(" = "); func(a * c, b * d); printf("\n");
    func(a, b); printf(" / "); func(c, d); printf(" = "); func(a * d, b * c);
    return 0;
}