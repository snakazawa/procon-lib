#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

namespace convert{
	template<typename T>
	T fromString(const string s) {
		istringstream ist(s);
		T res;
		ist >> res;
		return res;
	}
	
	template<typename T>
	string toString(const T d, int precision = -1) {
		ostringstream ost;
	
		if (precision < 0) {
			ost << fixed << setprecision(precision);
		}
		ost << d;
	
		return ost.str();
	}
}

// *** example ***
//int main(void) {
//	string str("0.1513254");
//	cout << str << endl;
//
//	double d = convert::fromString<double>(str);
//	cout << d << endl;
//
//	d += 1;
//	
//	cout << convert::toString<double>(d) << endl;
//	cout << convert::toString<double>(d, 2) << endl;
//	cout << "kore" << endl;
//	cout << convert::toString<double>(d, -10) << endl;
//
//	cout << convert::fromString<double>("ewr0.5w") << endl;
//}

