#include <iostream>
#include <map>
#include<cmath>

using namespace std;
#define ll long long int

int main() {
    int t; cin >> t; // 读取测试用例的数量
    while (t--) {
        ll n; cin >> n; // 读取数组的长度
        map<ll, ll> mp; // 定义一个映射，键是数组中的元素，值是该元素出现的次数
        for (int i = 0; i < n; ++i) {
            ll x; cin >> x; // 读取数组中的一个元素
            mp[x]++; // 更新映射中该元素的计数
        }

        ll mod1 = mp.begin()->first, total = 0; // 初始化mod1为映射中的第一个键，total为总和
        bool flag = false;

        // 遍历映射，找到第一个模数为1的元素
        for (auto [num, occ] : mp) {
            if (occ % num == 1) mod1 = num;
        }
        mp[mod1]--; // 减少mod1的计数
        for (auto [num, occ] : mp) {
            // 如果存在一个元素，其计数不能被自身整除，则设置flag为true
            if (num != mod1 && occ % num != 0) flag = true;
        }

        // 计算总和
        for (auto [num, occ] : mp) {
            total += ((ll)ceil((double)occ / num)) * num;
        }

        // 根据flag的值调整总和
        if (!flag) {
            ++total;
            if (mod1 == 1) ++total;
        }
        cout << total << endl;
        // 输出总和
    }

    return 0;
}
