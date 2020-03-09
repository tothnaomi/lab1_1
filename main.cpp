/*
1.
a. Generieren Sie alle Primzahlen, die kleiner als eine natürliche Zahl n sind.
b. Gegeben sei ein Vektor von Zahlen, finden Sie die längste ansteigende
zusammenhängende Teilfolge.
*/


// a main-ben csak egy fuggvenyem kell legyen, a main -> ez az amit meg fog kapni a "rendelo", ez az interface. 
#include "pb1.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
using namespace std;



int main()
{
	//testing the "primzahl" function 
	assert(primzahl(4) == 0);
	assert(primzahl(5) == 1);
	assert(primzahl(1) == 0);
	assert(primzahl(9) == 0);
	assert(primzahl(19) == 1);
	assert(primzahl(-7) == 0);

	// a)
	int n;
	cout << "Gib ein Zahl:";
	cin >> n;
	for (int i = 2; i < n; i++)
	{
		if (primzahl(i) == 1) cout << i << ", ";
	}


	// b)
	vector<int> v { 2, 5, 7, 9, 2, 13, 15, 4, 1, 2, 3, 4, 5, 6, 7, 8 };
	cout << langste_ansteigende_teilfolge(v);
	assert(langste_ansteigende_teilfolge({ 2, 5, 7, 9, 2, 13, 15, 4, 1, 2, 3, 4, 5, 6, 7, 8 }) == 8);
	assert(langste_ansteigende_teilfolge({ 1, 0, -2, 7, 1 }) == 2);
	return 0;
}