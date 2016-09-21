#include <stdexcept>
#include "permutation.hh"

Permutation::Permutation(unsigned int const size) 
	: size(size), forwardMap(new unsigned int [size]), reverseMap(new unsigned int[size])// pass the parameter size to the protected variable size
	{
		if (size == 0)
			throw out_of_range("0 size permutation");
		for (unsigned int i = 0; i < size; i++)
		{
			forwardMap[i] = size;
			reverseMap[i] = size;
		}	
	}	
Permutation::~Permutation()
	{
		delete [] forwardMap;// delete the array
		//cout << "delete the forwardMap" << endl;
		delete [] reverseMap;
		//cout << "delete the reverseMap" << endl;
	}	
void Permutation::set(unsigned int const index, unsigned int const permute)
	{
		// check the out_of_range
		if (index > size-1 || permute > size-1)
		{
			throw out_of_range("index and/or permute too large");
		}
		if (forwardMap[index] != size || reverseMap[permute] != size)//check the index or petmute has already used 
		{
			throw invalid_argument("forward and/or reverse map already set");
		}
		
		forwardMap[index] = permute;// set the forwardMap    0--->1
		reverseMap[permute] = index;// set the reverseMap    1--->0
	}
	// return the size 
unsigned int Permutation::getSize() const
	{
		return size;
	}
unsigned int Permutation::forward(unsigned int index) const
	{
		//chenck the range
		if (index > size-1)
		{
			throw out_of_range("index >= size");			
		}
		if (forwardMap[index] == size)//If the table entry has not been set (ie its value is still the value of 'size' set when the instance was constructed) you need to throw a logic_error exception.
		{
			throw logic_error("permutation map entry not set");
		}
		//cout << "forwardMap[" << index << "]" << forwardMap[index] << endl;
		return forwardMap[index];	
	}
unsigned int Permutation::reverse(unsigned int permute) const
	{	
		//check the range
		if (permute > size-1)
		{
			throw out_of_range("permute >= size");			
		}
		if (reverseMap[permute] == size)
		{
			throw logic_error("permutation map entry not set");
		}
		//cout << " reverseMap[" << permute << "]" << reverseMap[permute] << endl;
		return reverseMap[permute];	
	}

//test
// 1. code coverage 2. Breadth of value:  Permutation p(1) 3. edge causes Permutation p(3) set(0,2) set(1,1) set(2,0) 
//Permutation p(0) 
