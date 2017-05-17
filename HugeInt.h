#ifndef HUGEINT_H
#define HUGEINT_H
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class HugeInt{
friend ostream& operator << (ostream&,const HugeInt &);
friend istream& operator >> (istream&,HugeInt &);
public:
HugeInt(int = 0);
HugeInt(string);
 HugeInt operator+ (HugeInt &);
HugeInt operator- (HugeInt &);
const HugeInt& operator= (const HugeInt &);
vector<int> value;
private:


};






#endif
