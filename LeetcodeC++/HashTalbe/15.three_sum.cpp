#include <iostream>
#include <vector>
#include <unordered_set>
#include <ctime>
#include <algorithm>
using namespace std;

class Solution {
public:
    //a + b + c = 0
    //确定a , b ，找c
    //返回三元组，不可重复

    //排序+hash的方式，首先排序，固定a并去重，然后遍历后面的元素，元素没有匹配则加入set，匹配后则从set中去除。
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() <= 2) return vector<vector<int>>();  //如果为空，返回空
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());   //排序
        // for(int i : nums) cout << i << " "; //输出验证是否有序
        // cout << endl;

        for (int i = 0; i < nums.size() - 1; i++) {
            //找a ，一定为负数或，如果为0，则b，c都为0
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue; //对a去重
            unordered_set<int> uset;
            for(int j = i+1; j < nums.size(); j++) {
                //找b
                if (j > i+2 && nums[j] == nums[j-1] && nums[j-1] == nums[j-2]) continue;  //对b去重
                //同时要连续判断三个的原因是，如果是-2 1 1 0这种，判断第一个b后，加入set，
                //判断第二个的时候要将第一个加入的元素可能满足条件，因此只有连续三个一一致的时候才忽略。
                int c = -(nums[i] + nums[j]);
                if (uset.find(c) != uset.end()) {  //如果找到了
                    vector<int> tmp{nums[i], nums[j], c};
                    sort(tmp.begin(), tmp.end());
                    ret.push_back(tmp);
                    uset.erase(c);   //c去重
                } else {
                    uset.insert(nums[j]);
                }
            }
        }
        return ret;
    }
    //方法二：排序加双指针
    //a + b + c = 0;

    vector<vector<int>> threeSum2(vector<int>& nums) {
        if(nums.size() < 3) return vector<vector<int>>();  //返回空
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());   //排序

        for (int i = 0; i < nums.size()-2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue; //去重a
            int a = -nums[i];  //b+c的和
            int l = i+1, r = nums.size()-1;
            while( l < r) {
                if (l > i+1 && nums[l] == nums[l-1]) {   //去重b,在b取第二个值的时候
                    l++;
                    continue;
                }
                if (nums[l] + nums[r] == a) {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    l++;
                } else if (nums[l] + nums[r] < a) {
                    l++;
                } else {
                    r--;
                }
            }

        }
        return ret;
    }
};
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) {
                return result;
            }
            // 错误去重方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // 正确去重方法
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }

        }
        return result;
    }
};

int main () {
    srand(time(0));
    vector<int> nums;
    int n = 15;
    for (int i = 0; i < n; i++) {
        nums.push_back(rand()%10-5);
    }
    cout << "nums: ";
    for (int i : nums) {
        cout << i << " " ;
    }
    cout << endl;
    Solution s;
    vector<vector<int>> res = s.threeSum(nums);
    cout << "threeSum 1 : " << endl;
    for(auto &i : res) {
        for(auto &j : i) {
            cout << j << " " ;
        }
        cout << endl;
    }
    res = s.threeSum2(nums);
    cout << "********************" << endl;
    cout << "threeSum 2 : " << endl;
    for(auto &i : res) {
        for(auto &j : i) {
            cout << j << " " ;
        }
        cout << endl;
    }
    cout << endl;
    system("pause");
    return 0;
}