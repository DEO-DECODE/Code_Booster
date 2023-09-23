string intToRoman(int num) {
        map<int, string> romanValue;
  romanValue[1] = "I";
  romanValue[4] = "IV";
  romanValue[5] = "V";
  romanValue[9] = "IX";
  romanValue[10] = "X";
  romanValue[40] = "XL";
  romanValue[50] = "L";
  romanValue[90] = "XC";
  romanValue[100] = "C";
  romanValue[400] = "CD";
  romanValue[500] = "D";
  romanValue[900] = "CM";
  romanValue[1000] = "M";
  auto itr = --romanValue.end();
  string ans = "";
  while (num > 0)
  {
    int quotiennt = num / (*itr).first;
    int rem = num % (*itr).first;
    if (quotiennt != 0)
    {
      for (int i = 0; i < quotiennt; ++i)
      {
        ans += (*itr).second;
      }
    }
    num = rem;
    itr--;
  }
  return ans;
    }
