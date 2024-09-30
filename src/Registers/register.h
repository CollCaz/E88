#include <bitset>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>

namespace E8088 {

typedef class Regisiter {
  int16_t X = 0;
  int8_t L = 0;
  int8_t H = 0;

public:
  Regisiter(int16_t i16) : X(i16){};
  int16_t get_X() { return this->X; }
  int8_t get_L() { return this->L; }
  int8_t get_H() { return this->H; }

  void set_X(int v) {
    this->X = v;
    this->update_LH();
  }

  void set_L(int v) {
    this->L = v;
    this->update_X();
  }

  void set_H(int v) {
    this->H = v;
    this->update_X();
  }

  void update_X() {
    this->X = 0x0000;
    this->X = ((int16_t)(this->H) << 8);
    this->X |= ((int16_t)(this->L)) & 0x00ff;
    this->update_LH();
  }

  void update_LH() {
    this->L = (this->X & 0x00ff);
    this->H = (this->X & 0xff00) >> 8;
  }

  void addx(int16_t v) {
    this->X += v;
    this->update_LH();
  }

  void addl(int8_t v) {
    this->L += v;
    this->update_X();
  }

  void addh(int8_t v) {
    this->H += v;
    this->update_X();
  }

  void pl() {
    if (this->L == 0) {
      printf("%02d", this->L);
    } else if (this->L > 0) {
      printf("%+04d", this->L);
    } else {
      printf("%04d", this->L);
    }
  }

  void ph() {
    if (this->H == 0) {
      printf("%03d", this->H);
    } else if (this->H > 0) {
      printf("%+04d", this->H);
    } else {
      printf("%04d", this->H);
    }
  }

  void px() { std::cout << std::bitset<12>(this->X); }

} Regisiter;

} // namespace E8088
