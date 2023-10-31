class Solution {
public:
    vector<vector<int>> generate(int numRows) {
          vector<vector<int>> ans;
  ans.push_back({1});
  if (numRows == 1)
  {
    return ans;
  }
  ans.push_back({1, 1});
  if (numRows == 2)
  {
    return ans;
  }
  for (int ind = 3; ind <= numRows; ++ind)
  {
    int x = 0, y = 1;
    vector<int> temp;
    temp.push_back(1);
    for (int cnt = 1; cnt <= ind - 2; ++cnt)
    {
      temp.push_back(ans[ind - 2][x] + ans[ind - 2][y]);
      x++, y++;
    }
    temp.push_back(1);
    ans.push_back(temp);
  }
  return ans;
    }
};
