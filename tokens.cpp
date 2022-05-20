#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Function to identify if the input is a keyword in CPP  */
bool isKeyword(string input_str) {

  vector<string> keywords = {
      "auto",     "break",  "case",    "char",   "const",    "continue",
      "default",  "do",     "double",  "else",   "enum",     "extern",
      "float",    "for",    "goto",    "if",     "int",      "long",
      "register", "return", "short",   "signed", "sizeof",   "static",
      "struct",   "switch", "typedef", "union",  "unsigned", "void",
      "volatile", "while"};
  for (int i = 0; i < keywords.size(); i++) {
    if (input_str == keywords[i]) {
      return true;
    }
  }
  return false;
}

/* Function to identify if the input is a operator in CPP  */
bool isOperator(string input_str) {
  vector<string> operators = {
      "=",   "==",  "!=",     ">=",    "<=",      ">",   "<",   "+",  "-",
      "*",   "/",   "%",      "++",    "--",      "&&",  "||",  "!",  "&",
      "|",   "^",   "~",      "<<",    ">>",      "<<=", ">>=", "->", "[]",
      ".",   "->*", "()",     "{}",    ",",       ";",   ":",   "?",  "::",
      "...", "new", "delete", "new[]", "delete[]"};

  for (int i = 0; i < operators.size(); i++) {
    if (input_str == operators[i]) {
      return true;
    }
  }
  return false;
}

/* Function to identify if the input is a identifier in CPP  */
bool isIdentifier(string input_str) {
  if (input_str[0] == '_' || (input_str[0] >= 'a' && input_str[0] <= 'z') ||
      (input_str[0] >= 'A' && input_str[0] <= 'Z')) {
    for (int i = 1; i < input_str.length(); i++) {
      if ((input_str[i] >= 'a' && input_str[i] <= 'z') ||
          (input_str[i] >= 'A' && input_str[i] <= 'Z') ||
          (input_str[i] >= '0' && input_str[i] <= '9') || input_str[i] == '_') {
        continue;
      } else {
        return false;
      }
    }
    return true;
  }
  return false;
}

int main() {

  string input_str;
  cout << "Enter a string: ";
  cin >> input_str;

  if (isKeyword(input_str)) {
    cout << "The string is a keyword." << endl;
  } else if (isOperator(input_str)) {
    cout << "The string is an operator." << endl;
  } else if (isIdentifier(input_str)) {
    cout << "The string is an identifier." << endl;
  } else {
    cout << "The string is not a keyword, operator or identifier." << endl;
  }

  return 0;
}