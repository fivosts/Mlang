#ifndef UTIL_H
#define UTIL_H

bool isDigit(char&& c)
{
	return (c <= (char)('9') 
			&& c >= (char)('0'));
}

bool isLetter(char&& c)
{
	return ((c >= (char)'A' 
			&& c <= (char)'Z')
			|| 
			(c >= (char)'a' 
			&& c <= (char)'z'));
}

#endif
