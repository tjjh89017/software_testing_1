#include "main.hpp"

#define SWAP(t, x, y) do { \
	t = x; \
	x = y; \
	y = t; \
} while(0)

int triangle_type(int a, int b, int c) {

	// check invaild
	if(1 > a || a > 200)
		return INVAILD;
	if(1 > b || b > 200)
		return INVAILD;
	if(1 > c || c > 200)
		return INVAILD;

	// sort it, a <= b <= c
	int t;
	if(a > b)
		SWAP(t, a, b);
	if(b > c)
		SWAP(t, b, c);
	if(a > b)
		SWAP(t, a, b);

	// NOT_TRIANGLE
	if(c >= a + b)
		return NOT_TRIANGLE;

	// EQUILATERAL
	if(a == b && b == c)
		return EQUILATERAL;
	// ISOSCELES
	if(a == b || b == c)
		return ISOSCELES;

	return TRIANGLE;
}
