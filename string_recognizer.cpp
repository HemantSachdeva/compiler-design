#include <iostream>
#include <string>
using namespace std;

bool isAcceptedByAStar(string input_str) {
  /*
   * This function checks if the string is acceptable by A*
   * The string is acceptable by A* iff it is null or a single terminal 'a'
   * that may or may not be followed by any number of terminal 'a'.
   */
  if (input_str.length() == 0) {
    return true;
  } else if (input_str.length() == 1) {
    return input_str[0] == 'a';
  } else {
    return input_str[0] == 'a' &&
           isAcceptedByAStar(input_str.substr(
               1)); // subtr is a substring left after the first character
  }
}

bool isAcceptedByBPlus(string input_str) {
  /*
   * This function checks if the string is acceptable by B+
   * The string is acceptable by B+ iff it contains at least one terminal 'b'
   * followed by any number of terminal 'b'.
   */
  if (input_str.length() == 0) {
    return false;
  } else if (input_str.length() == 1) {
    return input_str[0] == 'b';
  } else {
    return input_str[0] == 'b' &&
           isAcceptedByBPlus(input_str.substr(
               1)); // subtr is a substring left after the first character
  }
}

bool isAcceptedByAStarBPlus(string input_str) {
  /*
   * This function checks if the string is acceptable by A*B+
   * The string is acceptable by A*B+ iff it contains at least one terminal 'b'
   * and it can have any number of terminal 'a' before the first 'b'.
   */
  if (input_str.length() == 0) {
    return false;
  } else if (input_str.length() == 1) {
    return input_str[0] == 'b';
  } else if (input_str.length() == 2) {
    return (input_str[0] == 'a' && input_str[1] == 'b') ||
           (input_str[0] == 'b' && input_str[1] == 'b');
  } else if (input_str.length() >= 2) {
    int first_b_index = input_str.find('b');
    string str_with_first_b = input_str.substr(first_b_index);
    int is_a_before_b = input_str.find('a') < first_b_index;
    if (is_a_before_b) {
      string str_before_b = input_str.substr(0, first_b_index);
      return isAcceptedByAStar(str_before_b) &&
             isAcceptedByBPlus(str_with_first_b);
    } else {
      return isAcceptedByBPlus(str_with_first_b);
    }
  }
  return false;
}

bool isAcceptableByABB(string input_str) {
  /*
   * This function checks if the string is acceptable by ABB
   * The string is acceptable by ABB iff it contains exactly 'abb' terminal.
   */
  if (input_str.length() == 3) {
    return input_str[0] == 'a' && input_str[1] == 'b' && input_str[2] == 'b';
  } else {
    return false;
  }
}

int main() {
  string input_str;
  cout << "Enter a string: ";
  cin >> input_str;

  if (isAcceptedByAStar(input_str)) {
    cout << "The string is accepted by A*" << endl;
  } else if (isAcceptableByABB(input_str) &&
             isAcceptedByAStarBPlus(input_str)) {
    cout << "The string is accepted by ABB and A*B+" << endl;
  } else if (isAcceptableByABB(input_str)) {
    cout << "The string is accepted by ABB" << endl;
  } else if (isAcceptedByAStarBPlus(input_str)) {
    cout << "The string is accepted by A*B+" << endl;
  } else {
    cout << "The string is not accepted by any of the given expression." << endl;
  }
  return 0;
}
