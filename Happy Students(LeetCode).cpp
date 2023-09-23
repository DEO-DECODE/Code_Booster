int countWays(vector<int>& nums) {
        int ways = 0;
  int selected = 0, n = nums.size();
  nums.push_back(1e9);
  sort(nums.begin(), nums.end());
  if (nums[0] != 0)
  {
    ways++;
  }
  for (int i = 0; i < n; ++i)
  {
    selected++;
    if (nums[i] < selected && selected< nums[i+1])
    {
      // cout << i << " " << endl;
      ways++;
    }
  }
  return ways;
    }
