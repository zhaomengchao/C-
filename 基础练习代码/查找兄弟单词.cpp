//≤È’“–÷µ‹µ•¥ 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_brother(string lhs, string rhs)
{
  if (lhs.size() != rhs.size())
  {
    return false;
  }
  if (lhs == rhs)
  {
    return false;
  }
  sort(lhs.begin(), lhs.end());
  sort(rhs.begin(), rhs.end());
  return (lhs == rhs);
}
int main()
{
  int num;
  while (cin >> num)
  {
    string str;
    vector<string> str_vec;
    while (num-- > 0)
    {
      cin >> str;
      str_vec.push_back(str);
    }
    string str_find;
    int idx = 0;
    cin >> str_find >> idx;
   
    int counts = 0;
    string str_found;
    sort(str_vec.begin(), str_vec.end());
    for (vector<string>::const_iterator cit = str_vec.begin(); cit != str_vec.end(); ++cit)
    {
      if (check_brother(str_find, *cit))
      {
        ++counts;
        if (counts == idx)
        {
          str_found = *cit;
        }
        //find_vec.push_back(*cit);
      }
    }
    cout << counts << "\n";
    if (counts >= idx)
    {
      cout << str_found << '\n';
    }
  }
  return 0;
}