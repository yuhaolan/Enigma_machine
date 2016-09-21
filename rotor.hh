#include <iostream>
#include <stdexcept>
#include "permutation.hh"
using namespace std;

class Rotor : private Permutation
{
	private:
		unsigned int position;
		const unsigned char firstChar;
		const unsigned char lastChar;

		unsigned int toInt(const unsigned char inChar)const;
		unsigned char toChar(const unsigned int intInt)const;
	public:
		Rotor(const unsigned char firstChar, const unsigned char lastChar, const char *mapping);
		void setPosition(const unsigned char position1);
		unsigned char getPosition()const;
		void rotate();
		unsigned char forward(const unsigned char inChar);
		unsigned char reverse(unsigned char inChar);
};
