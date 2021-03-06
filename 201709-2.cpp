/*************************************************************************
	> File Name: 201709-2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月04日 星期一 19时15分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000
int ans[MAX_N + 5] = {0};
int n, k, max_num = 0;
struct Data {
    int id;
    int s;
    int c;
    int e;
} data[MAX_N + 5];

int cmp(Data a, Data b) {
    return a.id < b.id;
}

void output() {
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return ;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> data[i].id >> data[i].s >> data[i].c;
        data[i].e = data[i].s + data[i].c;
        if (max_num < data[i].e) max_num = data[i].e;
    }
    sort(data + 1, data + k + 1, cmp);
    /*
    for (int i = 1; i <= k; i++) {
        cout << data[i].id << " " << data[i].s << " " << data[i].c << " " << data[i].e << endl;
    }
    */
    for (int i = 1; i <= n; i++) ans[i] = i;
    for (int i = 1; i <= max_num; i++) {
        for (int j = 1; j <= k; j++) {
            if (data[j].e == i) {
                for (int l = 1; l <= n; l++) {
                    if (ans[l]) continue;
                    ans[l] = data[j].id;
                    break;
                }
            }
        }
        for (int j = 1; j <= k; j++) {
            if (data[j].s == i) {
                for (int l = 1; l <= n; l++) {
                    if (data[j].id == ans[l]) {
                        ans[l] = 0;
                    }
                }
            }
        }
        /*
        cout << "time = " << i << ": ";
        output();*/
    }
    output();
    return 0;
}
