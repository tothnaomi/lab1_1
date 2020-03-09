#include "pb1.h"
// itt csisnalom meg az implementare reszet azoknak a fuggvenyeknek,  amik deklaralva vannak a pb.h-ban

bool primzahl(int n)
{
	//diese Funktion uberpruft ob ein Zahl Prim ist oder nicht.
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	else
	{
		for (int i = 3; i <= sqrt(n); i++)
		{
			if (n % i == 0) return false;
		}
	}
	return true;
}

int langste_ansteigende_teilfolge(vector<int> v)
{
	int size = v.size();
	int max = 1;
	int max2 = 1;
	for (int i = 0; i < (size - 1); i++)
	{
		if (v[i] < v[i + 1]) {
			max2++;
			//I have printed this on the monitor to verify if the program runs correctly
			//cout << "max2 = " << max2<<endl;
		}
		else
		{
			if (max2 > max) max = max2;
			max2 = 1;
			//I have printed this on the monitor to verify if the program runs correctly
			//cout << "max = " << max << endl;
		}
	}
	if (max < max2) max = max2;
	return max;
}