# include <cstdio>
# include <iostream>
# include <cstring>
using namespace std;

char str1[10010];
char str2[10010];
int main(){
cin.getline(str1, 10010);//得到一行字符
cin.getline(str2, 10010);
int len1 = strlen(str1);
int len2 = strlen(str2);
bool flag[128] = {false};
for(int i = 0; i < len2; i++)
flag[str2[i]] = true;
for (int  i = 0; i < len1; i++){
    if(!flag[str1[i]])
    printf("%c", str1[i]);
}

return 0;

}