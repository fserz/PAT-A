# include <iostream>
# include <string>
# include <map>
using namespace std;
map<char, int> mp1, mp2;
string doublestr(string str){
    string s;
    int t = 0;//进位
    for (int i = str.length() - 1; i >= 0; i--){
        int k = str[i] - '0';
        k = 2 * k + t;
        int a = k % 10;
        s = to_string(a) + s;//取余后添加到字符串前面
        t = k / 10;
        if (i == 0 && t != 0)//最前面有进位
          s = to_string(t) + s;
    }
    return s;
}
int main(){
    string str1;
    cin >> str1;
    string str2 = doublestr(str1);
    for (int i = 0; i < str1.length(); i++){
        mp1[str1[i]]++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        mp2[str2[i]]++;
    }
    if (mp1 == mp2 && str1.length() == str2.length())
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    cout << str2 << endl;
    return 0;
}