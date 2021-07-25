# include <cstdio>
# include <cstring>
# include <algorithm>
# include <iostream>
using namespace std;
int minlen = 256, ans = 0;
char s[100][256];
int main(){
    
    int n;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++){
        cin >> s[i];
        int len = strlen(s[i]);
        if(len < minlen) minlen = len;
        reverse(s[i], s[i] + len);
    }
    for(int i = 0; i < minlen; i++){
        char c = s[0][i];
        bool same = true;
        for(int j = 1; j < n; j ++){
            if(c != s[j][i]){
                same = false;
                break;
            } 
        }
        if(same) ans++;
        else break;
    }
    if(ans) for(int i = ans - 1; i >= 0; i--){
        printf("%c", s[0][i]);
    }
    else printf("nai");
    return 0;
}