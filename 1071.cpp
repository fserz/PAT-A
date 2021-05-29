# include<cstdio>
# include<iostream>
# include<string>
# include<map>
using namespace std;
bool check(char c){
    if(c >= '0' && c <= '9') return true;
    if(c >= 'a' && c <= 'z') return true;
    if(c >= 'A' && c <= 'Z') return true;
    return false;
}


int main(){
    map<string, int> count;//计数字符串出现次数
    string str;
    getline(cin, str);
    int i = 0;
    while(i < str.length()){
        string word;
        while(check (str[i]) == true && i < str.length()){
            if(str[i] >= 'A' && str[i]<= 'Z'){
            str[i] += 32; 
        }
        word += str[i];
        i++;
        }
    
    if(word != " "){
        if(count.find(word) == count.end()) count[word] = 1;
        else count[word]++;
        }
        while(check (str[i]) == false && i < str.length()){  //跳过非单词字符
            i++;
        }
    }
    string ans;
    int Max = 0;
    for(map<string, int>::iterator it = count.begin(); it != count.end(); it++){
        if(it ->second > Max){
            Max = it ->second;
            ans = it ->first;
        }
    }
    cout<< ans <<" "<<Max<<endl;
    return 0;
}