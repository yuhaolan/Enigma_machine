#ifndef _PERMUTATION_HH_
#define _PERMUTATION_HH_
#include <iostream>
#include <stdexcept>
using namespace std;

class Permutation
{
	protected:
		unsigned int const size;
	private:
		unsigned int  *forwardMap;
		unsigned int  *reverseMap;
	public:
		Permutation(unsigned int const size);// pass the parameter size to the protected variable size
 	
		~Permutation();
	
		void set(unsigned int const index, unsigned int const permute);
// return the size 
		unsigned int getSize() const;
//return forward array
		unsigned int forward(unsigned int index) const;
//return reverse array
		unsigned int reverse(unsigned int permute) const;

	
};
#endif
