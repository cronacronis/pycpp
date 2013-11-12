#include <iostream>
#include <cmath>
using namespace std;

class Calc {

private:
  double x;
  double average(double,double);
  bool is_good_enough(double);
  double improve(double);
  double sqrt_iter(double);
public:
  Calc();
  void setX(double);
  double getX();
  double sqrt(double);
};

Calc::Calc()
  : x(0){
    cout << "Constructor" << endl;
}

void Calc::setX(double a){x = a;}

double Calc::getX(){ return x;}

double Calc::average(double a, double b){
  return (a + b) / 2.0;
}

bool Calc::is_good_enough(double guess){
  return (abs((guess * guess) -x) < 0.001);
}

double Calc::improve(double guess){
  return average(guess, x / guess);
}

double Calc::sqrt_iter(double guess){
  if(is_good_enough(guess))
    return guess;
  else
    return sqrt_iter(improve(guess));
}

double Calc::sqrt(double a){
  return sqrt_iter(1.0);
}

int main(){
  Calc c = Calc();
  c.setX(2.0);
  cout << c.sqrt(2) << endl;
  return 0;
}
