# include <cstdio>
# include <map>
using namespace std;

int  main(){
    int  M, N, col;
    scanf("%d%d", &M, &N);
    map<int, int> count;
    for(int i = 0; i < N; i++){
        for(int i = 0; i < M; i++){
            scanf("%d", &col);
            if(count.find(col) != count.end())
            count[col]++;
            else
                count[col] = 1;
           
        }
    }
    int k, Max = 0;
    for(map<int, int>::iterator it = count.begin(); it != count.end(); it++){
        if(it ->second > Max)
        Max = it ->second;
        k = it ->first;
    }
    printf("%d\n", k);
    return 0;

}