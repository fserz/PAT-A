# include <iostream>
# include <algorithm>
# include <string>
const int maxn = 100010;
using namespace std;
int c;//c使用全局变量，再cmp中可直接分情况讨论
struct node{
    string name;
    int id, grade;  
}records[maxn];
bool cmp(node a, node b){
    if (c == 1)
        return a.id < b.id;//从小到大
    else if(c == 2)
        return a.name <= b.name;//不降
    else if(c == 3)
        return a.grade <= b.grade;//不降
}
int main(){
    int n;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> records[i].id >> records[i].name >> records[i].grade;
    sort(records, records + n, cmp);
    for (int i = 0; i < n; i++){
        printf("%06d ", records[i].id); 
        cout << records[i].name << " " << records[i].grade << endl;
    }
    return 0;
}