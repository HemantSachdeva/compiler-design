#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

/* Function to check if a string contains single line comment */
bool isSingleLineComment(string input_str) {
  if (input_str[0] == '/' && input_str[1] == '/') {
    return true;
  }
  return false;
}

/* Function to check if a string contains multi line comment */
bool isMultiLineComment(string input_str) {
  if (input_str[0] == '/' && input_str[1] == '*' &&
      input_str[input_str.length() - 1] == '*' &&
      input_str[input_str.length() - 2] == '/') {
    return true;
  }
  return false;
}

int main() {
  string input_str;
  cout << "Enter a string: ";
  cin >> input_str;
  for (int i = 0; i < input_str.length(); i++) {
    cout << input_str[i];
  }

  if (isSingleLineComment(input_str)) {
    cout << "The string is a single line comment." << endl;
  } else if (isMultiLineComment(input_str)) {
    cout << "The string is a multi line comment." << endl;
  } else {
    cout << "The string is not a comment." << endl;
  }
  return 0;
}