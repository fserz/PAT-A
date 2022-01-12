# include <iostream>
using namespace std;
const int maxn = 10010;

int main(){
    int a[maxn], dp[maxn], s[maxn] = {0};//s[i]存储从那个元素开始
    int k;
    bool flag = false;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        if (a[i] >= 0)
        flag = true;
    }
    if (flag == false){
    cout << "0 " << a[0] << " " << a[k - 1];
    return 0;
    }    
    dp[0] = a[0];
    for (int i = 1; i < k; i++)
    {
        if (dp[i - 1] + a[i] > a[i])
        {
            dp[i] = dp[i - 1] + a[i];
            s[i] = s[i - 1];    
        }else{
            dp[i] = a[i];
            s[i] = i;
        }        
    }
    int j = 0;
    for (int i = 1; i < k; i++)//寻找最大的dp[i] 下标i
    {
        if(dp[i] > dp[j])
        j = i;
    }
    cout << dp[j] << " " << a[s[j]] << " " << a[j] << endl;
    return 0;
}