#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// 获取输入数字
int get_number() {
    int num;
    cin >> num;
    return num;
}

int main()
{
    // 读取N值
    int N = get_number();

    // 读取数字列表
    vector<int> nums(N);
    for (int i = 0; i < N; i++) 
    {
        nums[i] = get_number();
    }

    // 使用双端队列进行处理
    deque<int> q;
    q.push_back(nums[0]);

    for (int i = 1; i < N; i++) 
    {
        int num = nums[i];
        if (q.back() <= num) 
        {
            q.push_back(num);  // 如果当前数字比队列的最后一个大或相等，直接加入队列
        }
        else 
        {
            int m = q.back();  // 保存队列最后一个元素
            q.pop_back();  // 弹出队列最后一个元素
            // 弹出所有大于当前数字的元素
            while (!q.empty() && q.back() > num) 
            {
                q.pop_back();
            }
            q.push_back(m);  // 加回原来的元素
        }
    }

    // 输出有效的子数组数量
    cout << q.size() << endl;

    return 0;
}
