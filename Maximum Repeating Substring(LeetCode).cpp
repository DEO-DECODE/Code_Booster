class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string temp = "";
  int k = 0, ans = 0;
  while (temp.size() <= sequence.size())
  {
    k++;
    temp += word;
    if (sequence.find(temp) < sequence.size())
    {
      ans = max(ans, k);
    }
    else{
      break;
    }
  }
  return ans;
    }
};
