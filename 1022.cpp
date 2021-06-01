# include<cstdio>
# include<iostream>
# include<string>
# include<map>
# include<set>
using namespace std;
map<string, set<int>> mpID, mpTit, mpAut,  mpKey, mpPub, mpYea; 

void find(map<string, set<int>>& mp, string& str){ //string和map的参数传递较慢，如果作为函数参数及要加上引用。必须引用否则最后一组数据会超时
    if(mp.find(str) == mp.end()) printf("Not Found\n");
    else{
        for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++){
            printf("%07d\n", *it); //不能%7d，否则后两组不对，%07d， 不足7位时前方补0
        }
    }
}

int main(){
    int N, id, M, type;
    char c;
    string title, author, key, pub, year;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &id);
        getchar();
        getline(cin, title);
        mpTit[title].insert(id);
        getline(cin, author);
        mpAut[author].insert(id);
        while(cin >> key){
            mpKey[key].insert(id);
            c = getchar();
            if(c == '\n') break;
        }
        getline(cin, pub);
        mpPub[pub].insert(id);
        getline(cin, year);
        mpYea[year].insert(id);
    }

    string temp;
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d: ", &type);
        getline(cin, temp);
        cout << type << ": " << temp << endl;
        if(type == 1) find(mpTit, temp);
        if(type == 2) find(mpAut, temp);
        if(type == 3) find(mpKey, temp);
        if(type == 4) find(mpPub, temp);
        if(type == 5) find(mpYea, temp);
    }

    return 0 ;

}