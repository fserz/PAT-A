# include <iostream>
# include <cmath>
# include <cctype>
# include <algorithm>
using namespace std;
long long convert(string n, long long radix){//给定一个数值和进制，将其转换成十进制
    long long sum = 0;
    int index = 0, temp = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++){
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}
long long find_radix(string n, long long num){//找到令两个数相等的进制数，查找过程使用二分法，如出现负数则出现了溢出。
    char it = *max_element(n.begin(), n.end());
    long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
    long long high = max(num, low);
    while(low <= high){
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if(t < 0 || t > num) high = mid - 1;
        else if(t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}
int main(){
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix)); 
    if (result_radix != -1){
        printf("%lld", result_radix);
    }else{
        printf("Impossible");
    }
    return 0;
}