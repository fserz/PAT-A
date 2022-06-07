# include <iostream>
# include <map>
# include <string>
using namespace std;
const int maxn = 2022;
const int INF = 100000;
map <int, string> intToString;
map <string, int> stringToInt;
map <string, int> Gang;
int G[maxn][maxn] = {0}, weight[maxn] = {0};//邻接矩阵G和点权weight
int n, k, numperson = 0;
bool vis[maxn] = {false};
void DFS(int nowVist, int& head, int& numMember, int& totalvalue){//访问单个连通块
    numMember++;
    vis[nowVist] = true;
    if (weight[nowVist] > weight[head])  head = nowVist;
    for (int i = 0; i < numperson; i++){
        totalvalue += G[nowVist][i];//增加边权
        G[nowVist][i] =  G[i][nowVist] = 0;//删除这条边
        if (vis[i] == false)   DFS(i, head, numMember, totalvalue);
    }
}
void DFSTraverse(){
    for (int i = 0; i < numperson; i++){
        if(vis[i] == false){
            int head = i, numMember = 0, totalvalue = 0;
            DFS(i, head, numMember, totalvalue);
            if (numMember > 2 && totalvalue > k) Gang[intToString[head]] = numMember;
        }
    }
}
int change(string str){//发张照姓名对应的编号
    if(stringToInt.find(str) != stringToInt.end()){//str已经出现过了
        return stringToInt[str];
    }else{
        stringToInt[str] = numperson;//str的编号为numperson
        intToString[numperson] = str;//numperson对应str
        return numperson++;//总人数++
    }
}
int main(){
    int w;
    string str1, str2;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;//点权+w
        weight[id2] += w;
        G[id1][id2] += w;//边权+w
        G[id2][id1] += w;
    }
    DFSTraverse();
    cout << Gang.size() << endl;
    for (auto it = Gang.begin(); it != Gang.end(); it++){
        cout << it->first << " " << it->second << endl; 
    }
    return 0;
}