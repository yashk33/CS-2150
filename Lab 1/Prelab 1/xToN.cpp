#include <iostream>
using namespace std;

int xton(int x, int n){
  if(n == 0)
    return 1;
  return x * xton(x, n-1);
}

int main() {
  int x, n, val;
  cin >> x;
  cin >> n;
  val = xton(x, n);
  cout << val << endl;
  return 0;
}
