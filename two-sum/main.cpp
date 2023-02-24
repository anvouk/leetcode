#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (int complement = target - nums[i]; map.find(complement) != map.end()) {
                return { map[complement], i };
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

/* https://leetcode.com/problems/two-sum/ */
int main()
{
    Solution sol;
    vector<int> vecs { 1, 2, 3, 4, 5 };
    auto res = sol.twoSum(vecs, 7);
    for (const auto v : res) {
        cout << "res: " << v << '\n';
    }
    return 0;
}
