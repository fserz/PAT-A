# include <iostream>
# include <string>
# include <cctype>
using namespace std;
int main(){
    string a, b, c ,d;
    cin >> a >> b >> c >> d;
    char t[3];//保存星期,小时,分钟
    int i = 0, j = 0;
    while (i < a.length() && i < b.length()){
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')){
            t[0] = a[i];
            break;
        }
        i++;
    }
    i++;//从下一个字符继续匹配
    while (i < a.length() && i < b.length()){
        if ((a[i] == b[i]) && ((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i]))){//此处英文字母只会取A到N
            t[1] = a[i];
            break;
        }
        i++;
    }
    while (j < c.length() && j <d.length()){
        if ((c[j] == d[j]) && islower(c[j])){
            t[2] = j;
        }
        j++;
    }
    string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    cout << week[t[0] - 'A'] << " ";
    int m = isdigit(t[1]) ?  t[1] - '0':  t[1] - 'A' + 10;
    printf("%02d:%02d", m, t[2]);
return 0;
}