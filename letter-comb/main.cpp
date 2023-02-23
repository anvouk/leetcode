#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

static const unordered_map<char, string> numletts {
    { '2', "abc" },
    { '3', "def" },
    { '4', "ghi" },
    { '5', "jkl" },
    { '6', "mno" },
    { '7', "pqrs" },
    { '8', "tuv" },
    { '9', "wxyz" },
};

static void calc(const string &digits, size_t digits_i, vector<string> &res, string &str)
{
    if (digits_i >= digits.size()) {
        res.emplace_back(str);
        return;
    }

    const auto &letters = numletts.at(digits[digits_i]);
    for (size_t i = 0; i < letters.size(); i++) {
        str += letters[i];
        calc(digits, digits_i + 1, res, str);
        str.pop_back();
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        string str;
        calc(digits, 0, res, str);
        return res;
    }
};

/* https://leetcode.com/problems/letter-combinations-of-a-phone-number/ */
int main()
{
    Solution sol;
    vector<string> res = sol.letterCombinations("7");
    printf("sz: %ld\n", res.size());
    for (size_t i = 0; i < res.size(); ++i) {
        printf("[%ld]: %s\n", i, res[i].data());
    }
    return 0;
}
