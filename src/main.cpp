#include "Registers/register.h"
#include <bitset>

using namespace std;

int main() {
  bitset<12> b;
  b.set(1);
  b.reset(1);
  size_t a = b[1];
  cout << a << endl;
  E8088::Regisiter r(0);
  r.set_X(0x802);
  r.ph();
  cout << " ";
  r.pl();
  cout << endl;
  r.px();
}
