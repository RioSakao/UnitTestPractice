#include "Password.h"
#include <string>
#include <cassert>

using std::string;

/*
  The function receives a string counts how many times the same character
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase)
{
  int repetition = 1;
  int index = 0;

  while (index < phrase.length() - 1 && phrase[index] == phrase[index + 1])
  {
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string pass)
{
  bool lower = false;
  bool upper = false;
  for (int i = 0; i < pass.size(); i++)
  {
    if (pass[i] >= 'A' && pass[i] <= 'Z')
    {
      upper = true;
    }
    else if (pass[i] < 'z')
    {
      lower = true;
    }
  }
  return upper && lower;
}

/*
constructor sets the default password to "ChicoCA-95929"
*/
Password::Password()
{
  pass_history.push_back("ChicoCA-95929");
}

/*
receives a password and sets the latest in pass_history to it if and only
if it meets all criteria:
  1. The password is at least 8 letters long
  2. It has no more than 3 of the same leading characters
  3. It has mixed case (at least one upper case and at least one lower case)
  4. It was not a previous password in the history
*/
void Password::set(string s)
{
  int upper = 0, lower = 0, leading;
  bool flag = true;
  // 1
  if (s.length() < 8)
    flag = false;

  // 2
  if (s[0] == s[1] == s[2])
    flag == false;

  // 3
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] >= 'A' && s[i] <= 'Z')
    {
      upper++;
    }
    else if (s[i] < 'z')
    {
      lower++;
    }
  }
  if (upper < 1 || lower < 1)
    flag = false;

  // 4
  for (int i = 0; i < pass_history.size(); i++)
  {
    if (pass_history[i] == s)
    {
      flag = false;
      break;
    }
  }
  if (flag == false)
    assert("Invalid password");
  else
    pass_history.push_back(s);
}

/*
receives a string and authenticates it against the latest password in the
pass_history, returning true for an exact match or false when it does not match
or if a password has not been set.
*/
bool Password::authenticate(string s)
{
  if (pass_history.back() == s)
    return true;

  return false;
}