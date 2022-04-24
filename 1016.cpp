# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
# include <map>
using namespace std;
struct node{
    int month, day, hour, minute, status, time;
    string name;
};
bool cmp(node a, node b){
    return a.name != b.name ? a.name < b.name : a.time < b.time;
}
double cost(node call , int *rate){
    double total = rate[call.hour] * call.minute + rate[24] * 60 * call.day;
    for (int i = 0; i < call.hour; i++)
        total += rate[i] * 60;
    return total / 100.0;
}
int main(){
    int rate[25] = {0}, n;
    for (int i = 0; i < 24; i++){
        cin >> rate[i];
        rate[24] += rate[i];
    }
    cin >> n;
    vector<node> data(n);//n个vector
    for (int i = 0; i < n; i++){
        cin >> data[i].name ;
        scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);//scanf别忘&
        string temp;
        cin >> temp;
       data[i].status = (temp == "on-line") ? 1 : 0;//在线时状态为1，离线为0
       data[i].time = data[i].minute + data[i].hour * 60 + data[i].day * 24 * 60;
    }
    sort(data.begin(), data.end(), cmp);
    map<string, vector<node>>custom;
    for (int i = 1; i < n; i++){
        if (data[i].name == data[i - 1].name && data[i].status == 0 && data[i - 1].status == 1){
            custom[data[i - 1].name].push_back(data[i - 1]);
            custom[data[i].name].push_back(data[i]);
        }
    }
     for (auto it : custom){//for each
         vector<node> temp = it.second;
         cout << it.first;
         printf(" %02d\n", temp[0].month);
         double total = 0.0;
         for (int i = 1; i < temp.size(); i += 2){//i每次+2
             double t = cost(temp[i], rate) - cost(temp[i - 1], rate);
             printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute,
             temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
             total += t;
         }
         printf("Total amount: $%.2f\n", total);
     }
    return 0;
}