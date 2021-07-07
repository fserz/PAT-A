# include <cstdio>
# include <map>
# include <iostream>
# include <cstring>
using namespace std;
map<int, string> mp;
int digit[10];
char s[110];
int main(){
string zero, one, two, three, four, five, six, seven, eight, nine;
mp[0] = zero;
mp[1] = one;
mp[2] = two;
mp[3] = three;
mp[4] = four;
mp[5] = five;
mp[6] = six;
mp[7] = seven;
mp[8] = eight;
mp[9] = nine;
cin >> s;
int len = strlen(s);
int sum = 0, numlen = 0;
map<int , string>::iterator it;
for(int i = 0; i < len; i++){
    sum += s[i] - '0';
}
if(sum == 0){
    cout << mp[0];
}
else{
    while (sum != 0){
        digit[numlen++] = sum % 10;
        sum /= 10; 
    }
for(int i = numlen - 1; i > 0; i--){
    cout << mp[i];
    if(i != 0) printf(" ");
}
}
  return 0;
  }
