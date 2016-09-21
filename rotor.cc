#include "rotor.hh"

//Rotor
unsigned int Rotor::toInt(const unsigned char inChar)const
{
	int num;//convert char to int
	num = inChar - firstChar;
	return num;			
}
unsigned char Rotor::toChar(const unsigned int intInt)const
{
	char tochar;// convert int to char
	tochar = intInt + firstChar;
	return tochar;

}
	
Rotor::Rotor(const unsigned char firstChar, const unsigned char lastChar, const char *mapping)
	: Permutation(lastChar -firstChar + 1), firstChar(firstChar), lastChar(lastChar)
{
	//int size1 = lastChar - firstChar + 1;//the size
	int i;//for loop
	//set the table
	for ( i = 0; i < size ; i++)
	{
//		set(i,toInt(*(mapping+i)));
		set(i,toInt(mapping[i]));
	}
									
}
void Rotor::setPosition(const unsigned char position1)//'C' 
{
//	cout << "setPosition:size is " << size << "Position is " << position1 << endl;
	if (toInt(position1) > size-1 )  // '1'
	{
		throw out_of_range("setPosition:out_of_range");
	}
	else
	{	
		position = toInt(position1);//toInt('C')->2
	}
}	
unsigned char Rotor::getPosition()const
{
	return toChar(position);
}
void Rotor::rotate()
{
	position = (position+1+size)%size;
}
unsigned char Rotor::forward(const unsigned char inChar)
{
	int pos1,temp;
	temp = position + toInt(inChar);//'B' -> 1
//	cout << "forward::temp=" << temp << " "<<position << "+" << " " << toInt(inChar) << endl;
	// temp  : 2+1=3(D)
	pos1 = Permutation::forward(temp);//position : 3(D) ---> 7(H)  
//	cout << "pos1:: " << pos1 << endl;
//	cout << "toChar:: " << toChar(pos1 - position);
	return toChar((pos1+size-position)%size);// 7-2=5;toChar(5)->F could be negative!!!
			
}
//reverse rotor
unsigned char Rotor::reverse(unsigned char inChar)
{
	int pos2,temp;
	temp = position + toInt(inChar);
	pos2 = Permutation::reverse(position);
	return toChar((pos2+size-position)%size);
}
