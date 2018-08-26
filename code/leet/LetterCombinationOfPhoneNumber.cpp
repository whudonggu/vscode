#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res；
        unordered_map<int, string> value = map_list_of(2, "abc")(3, "def")(4, "ghi")(5, "jkl")(6, "mno")(7, "pqrs")(8, "tuv")(9, "wxyz");
        if(digits.empty())
            return -1;
        while(digits!='\0')
        {
            
        }
    }
};