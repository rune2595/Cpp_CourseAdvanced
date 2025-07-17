//--------------------- File Information ---------------------
// File         : 2DVector.cpp
// Author       : Rune Dirk Willen
// Date         : 17-07-2025
// Description  : Basic C++ program looking into 2D vectors.

// Include necessary headers and namespaces
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	vector<vector<int>> table12(10, vector<int>(3, 0)); // Create a 12x3 vector initialized to 0



	// Fill the vector with values
	for (int row = 0; row < table12.size(); row++)
	{
		table12[row][0] = 12; // Set first column to 12
		table12[row][1] = row + 1;
		table12[row][2] = table12[row][0] * table12[row][1];

		for (int col = 0; col < table12[row].size(); col++)
		{
			cout << table12[row][col] << flush;

			if (col == 0)
			{
				cout << " * " << flush;
			}
			else if (col == 1)
			{
				cout << " = " << flush;
			}
		}

		cout << endl;
	}
	return 0;
}
