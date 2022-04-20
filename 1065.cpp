# include <iostream>
using namespace std;
int i;
void comp(long a, long b, long c){
    long sum = a + b;  
    if (a > 0 && b > 0 && sum < 0)//正溢
        cout << "Case #" << i << ": true" << endl;
    else if(a < 0 && b < 0 && sum >= 0)//负溢为>=0，注意等号
        cout << "Case #" << i << ": false" << endl;
    else if(sum > c)
        cout << "Case #" << i << ": true" << endl;
    else
        cout << "Case #" << i << ": false" << endl;
}
int main(){
    int n;
    long long a, b, c;
    cin >> n;
    for (i = 1; i <= n; i++){
        scanf("%lld%lld%lld", &a, &b, &c);//此处数据有可能溢出，需用scanf
        comp(a, b ,c);
    }
return 0;
}