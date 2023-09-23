class Solution {
public:
    int romanToInt(string s) {
        vector<pair<string, int>> vec;
  vec.push_back({"I", 1});
  vec.push_back({"IV", 4});
  vec.push_back({"V", 5});
  vec.push_back({"IX", 9});
  vec.push_back({"X", 10});
  vec.push_back({"XL", 40});
  vec.push_back({"L", 50});
  vec.push_back({"XC", 90});
  vec.push_back({"C", 100});
  vec.push_back({"CD", 400});
  vec.push_back({"D", 500});
  vec.push_back({"CM", 900});
  vec.push_back({"M", 1000});
  string temp = s;
  int ans = 0;
  while (temp.size() > 0)
  {
    for (int i = vec.size() - 1; i >= 0; --i)
    {
      string str = vec[i].first;
      if (temp.find(str) == 0)
      {
        ans += vec[i].second;
        temp = temp.substr(str.size());
        break;
      }
    }
  }
  return ans;
    }
};
