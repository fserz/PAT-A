# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int dp[10010], w[10010];
bool choice[10010][110];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    sort(w + 1, w + n +1, cmp);//硬币从大到小排序
    for (int i = 1; i <= n; i++){
        for(int j = m; j >= w[i]; j --){
            if (dp[j] <= dp[j - w[i]] + w[i]){
                choice[i][j] = true;
                dp[j] = dp[j - w[i]] + w[i];
            }
        }
    }
    if (dp[m] != m)
       cout << "No Solution";
    else{
        vector<int> arr;
        int v = m, index = n;
        while (v > 0){
            if(choice[index][v] == true){
                arr.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for (int i = 0; i < arr.size(); i++){
            if (i != 0) cout << " ";
            cout << arr[i];
        }
    }   
    return 0;
}