# include <iostream>
# include <algorithm>
using namespace std;
const int N = 110;
int n;//元素个数,n要定义成全局变量
int orign[N], temp[N], changed[N];
bool issame(int A[], int B[]){
    for(int i = 1; i <= n; i++){
        if (A[i] != B[i])   return false;
    }
    return true;
}
void showArray(int A[]){
    for (int  i = 1; i <= n; i++){
        cout << A[i];
        if (i != n) cout << " ";
    }
}
bool insertSort(){
    bool flag = false;
    for(int j = 2; j <= n; j++){//数组下标从1开始存数
        if (j != 2 && issame(temp, changed))    flag = true;//如果flag为true说明已经到达目标数组
        sort(temp, temp + j + 1);//再一次插入排序,用sort代替
        if (flag == true)   return true;
    }
    return false;
}
void downAdjust(int low, int high){
    int i = low, j = i * 2;//i为欲调整节点，j为其孩子
    while (j <= high){
        if (j + 1 <= high && temp[j + 1] > temp[j]){//右孩子存在且大于左孩子值
            j++;//存储右节点
        }
        if (temp[j] > temp[i]){//如果孩子结点大于父节点
            swap(temp[j], temp[i]);
            i = j;//i为j，j仍为孩子进入下一层
            j = 2 * i;
        }else   break;//调整完毕
    }
}
void heapsort(){
    bool flag = false;
    for (int i = n / 2; i >= 1; i--)   downAdjust(i , n);//建堆
    for (int i = n; i > 1; i--){
        if (i != n && issame(temp, changed))    flag = true;//不是初始序列且匹配相等
        swap(temp[i], temp[1]);//调整堆顶
        downAdjust(1, i - 1);
        if (flag == true){
        showArray(temp);
        return;
        }
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &orign[i]);
        temp[i] = orign[i];
        }
    for (int i = 1; i <= n; i++){    
        scanf("%d", &changed[i]);
        }
    if (insertSort()){
        cout << "Insertion Sort" << endl;
        showArray(temp);
    }else{
        cout << "Heap Sort" <<endl;
        for (int i = 1; i <= n; i++){
            temp[i] = orign[i];
        }
        heapsort();
    }
    return 0;
}