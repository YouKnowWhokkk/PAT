#include<iostream>
#include<map>
using namespace std;

int main() {
    map<int, double, greater<int>> mp;
    int n;
    int num;
    double flo;     //我之前这里出错了是因为把flo设成了int，如果调试时发现一个数字巨大或者巨小，很有可能就是这种情况
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %lf", &num, &flo);    //&lf用来记录double
        mp[num] = flo;                  //map可以这样赋值
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %lf", &num, &flo);
        if (mp.find(num) == mp.end()) {     //找不到时,mp.find(key)会返回mp.end()
            mp[num] = flo;
        }
        else {
            mp[num] += flo;
        }
    }

    //删除map中的东西时，要这样删，因为删去的时候，这个指针已经变了，而mp.erase(it)的返回值是it被删之前的下一个指针
    for (map<int, double>::iterator it = mp.begin(); it != mp.end();) {
        if (it->second == 0) {
            it = mp.erase(it);
        }
        else {
            it++;
        }
    }

    printf("%d", mp.size());

    for (map<int, double>::iterator it = mp.begin(); it != mp.end(); it++) {
        printf(" %d %.1f", it->first, it->second);
    }
    printf("\n");
    return 0;
}


