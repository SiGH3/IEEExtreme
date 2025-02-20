#include <iostream>
#include <map>
#include<cmath>

using namespace std;
#define ll long long int

int main() {
    int t; cin >> t; // ��ȡ��������������
    while (t--) {
        ll n; cin >> n; // ��ȡ����ĳ���
        map<ll, ll> mp; // ����һ��ӳ�䣬���������е�Ԫ�أ�ֵ�Ǹ�Ԫ�س��ֵĴ���
        for (int i = 0; i < n; ++i) {
            ll x; cin >> x; // ��ȡ�����е�һ��Ԫ��
            mp[x]++; // ����ӳ���и�Ԫ�صļ���
        }

        ll mod1 = mp.begin()->first, total = 0; // ��ʼ��mod1Ϊӳ���еĵ�һ������totalΪ�ܺ�
        bool flag = false;

        // ����ӳ�䣬�ҵ���һ��ģ��Ϊ1��Ԫ��
        for (auto [num, occ] : mp) {
            if (occ % num == 1) mod1 = num;
        }
        mp[mod1]--; // ����mod1�ļ���
        for (auto [num, occ] : mp) {
            // �������һ��Ԫ�أ���������ܱ�����������������flagΪtrue
            if (num != mod1 && occ % num != 0) flag = true;
        }

        // �����ܺ�
        for (auto [num, occ] : mp) {
            total += ((ll)ceil((double)occ / num)) * num;
        }

        // ����flag��ֵ�����ܺ�
        if (!flag) {
            ++total;
            if (mod1 == 1) ++total;
        }
        cout << total << endl;
        // ����ܺ�
    }

    return 0;
}
