/**
 * @file 1064.cpp
 * @author fserz
 * @brief 
 * @version 0.1
 * @date 2022-05-13
 * @copyright Copyright (c) 2022
 */
# include <iostream>
# include <algorithm>
using namespace std;
const int maxn = 1010;
int n, CBT[maxn], number[maxn], index = 0;//number保存结点权值
void inorder(int root){
    if(root > n) return;
    inorder(root * 2);//左子树
    CBT[root] = number[index++];//number[index]赋值给根节点
    inorder(root * 2 + 1);//右子树
}
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> number[i];
    }
    sort(number, number + n);
    inorder(1);
    for (int i = 1; i <= n; i++){//下标从1开始
        cout << CBT[i];
        if (i < n) cout << " "; 
}
    return 0;
}