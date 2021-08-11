#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string addition (string a, string b);
string substraction (string a, string b);


string addition (string a, string b) {
  string result;

  int flag_a = 0, flag_b = 0;

  if (a[0] == '-') flag_a = 1;
  if (b[0] == '-') flag_b = 1;


  if (flag_a && !flag_b) return substraction(b, a.substr(1));
  if (!flag_a && flag_b) return substraction(a, b.substr(1));

  if (flag_a && flag_b) {
      a = a.substr(1);
      b = b.substr(1);
  }
  
  int len_a = a.length();
  int len_b = b.length();

  for (int i = 0; i < abs(len_a-len_b); i++) {
        if (len_a > len_b) b = '0' + b;
        else a = '0' + a;
  }


  int length = a.length();
  int carry = 0, sum = 0;

  for (int i = length-1; i >= 0; i--) {
      sum = carry + a[i]-'0' + b[i]-'0';
  
      if (sum >= 10) carry = 1, sum -= 10;
      else carry = 0;

      result =  char(sum + '0') + result;
  }

    if (carry > 0) result = char(carry +'0') + result;

    while (result.length() > 1 && result[0] == '0') {
        result = result.substr(1);
    }
  
  if (flag_a && flag_b) result = '-' + result;

  return result;
}

string substraction (string a, string b) {
    string result;

    int flag_a = 0, flag_b = 0;


  if (a[0] == '-') flag_a = 1;
  if (b[0] == '-') flag_b = 1;

  
  if (flag_a && !flag_b) return addition(a, '-' + b);
  if (!flag_a && flag_b) return addition(a, b.substr(1));

    if (flag_a && flag_b) {
      a = a.substr(1);
      b = b.substr(1);
  }


    int len_a = a.length();
    int len_b = b.length();

    for (int i = 0; i < abs(len_a-len_b); i++) {
        if (len_a > len_b) b = '0' + b;
            else a = '0' + a;
    }

    int k = 0, flag = 0;
    while (k != a.length()) {        
        if (a[k]-'0' < b[k]-'0') {
            swap(a, b);
            swap(len_a, len_b);
            flag = 1;
        }

        else if (a[k]-'0' > b[k]-'0') break;
        else k++;
    }


    int length = a.length();
    int borrow = 0, sub = 0;

    for (int i = length-1; i >= 0; i--) {
        sub = ((int)(a[i]-'0') - borrow) - (int)(b[i]-'0');
    
        if (sub < 0) borrow = 1, sub += 10;
        else borrow = 0;

        result = char(sub + '0') + result;

    }

    while (result.length() > 1 && result[0] == '0') {
        result = result.substr(1);
    }

    if (!(flag_a && flag_b) && (flag)) result =  "-" + result;
    if ((flag_a && flag_b) && !(flag)) result =  "-" + result;

    return result;
}

int modulo (string a, string b) {
    int remainder = 0;
  	int k = stoi(b);
    int length = a.length();

    for (int i = 0; i < length; i++) {
        remainder = (remainder * 10 + (a[i]-'0'))%k;
    }
  
  return remainder;
}

string power (string a, string b) {
    int n = stoi(a);
    int r = stoi(b);
    
    string result = to_string(pow(n, r));
    result = result.substr(0, result.find("."));
  
    return result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << addition(s1, s2) << endl;

    return 0;
}