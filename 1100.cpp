# include <cstdio>
# include <map>
# include <string>
# include <iostream>
using namespace std;

string unitDight[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", 
"jul", "aug", "sep", "oct", "nov", "dec"};
string tenDight[13] = {"treat", "tam", "hel", "maa", "huh", "tou",
 "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
 string numToStr[170];
 map<string, int> strToNum;

 void init(){
     for(int i = 0; i < 13; i++){
         numToStr[i] = unitDight[i];
         strToNum[unitDight[i]] = i;
         numToStr[i * 13] = tenDight[i];
         strToNum[tenDight[i]] = i * 13;
     }
     for(int i = 1; i < 13; i++){
         for(int j = 1; j < 13; j++){
             string str = tenDight[i] + " " + unitDight[j];
             numToStr[i * 13 + j] = str;
         }
     }
 }

int main(){
    int N;
    cin >> N;
    while(N--){
        string str;
        getline(cin, str);
        if(str[0] >= '0' && str[0] <= '9'){
            int num = 0;
            for(int i = 0; i < str.length(); i++){
            num = num * 10 + (str[i] - '0');
            }
        cout << numToStr[num] << endl;
        }
        else{
            cout << strToNum[str] << endl;
        }
        return 0;        
    }

}

