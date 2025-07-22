//--------------------- File Information ---------------------
// File         : STLComplexDataTypes.cpp
// Author       : Rune Dirk Willen
// Date         : 22-07-2025
// Description  : Basic C++ program looking into nested STL
// 				  complex data types such as maps, sets, 
//				  vectors, stacks, queues, and deques.

// Include necessary headers and namespaces
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

// Define a class to hold month scores
class monthScores
{
private:
	// String to hold the name of the month
	string monthName;
	
	// Map to hold student names and their scores for the month
	map<string, vector<int> > scores;

public:
	// Default constructor initializes monthName to an empty string and scores to an empty map
	monthScores() : monthName(""), scores()
	{
	}
	
	// Parameterized constructor to initialize monthName and scores
	monthScores(string monthName, map<string, vector<int> > scores) : monthName(monthName), scores(scores)
	{
	}

	// Destructor for monthScores class
	~monthScores()
	{
		// Destructor can be used for cleanup if needed
	}

	// Getter methods to access private members
	string getMonthName() const
	{
		return monthName;
	}

	map<string, vector<int> > getScores() const
	{
		return scores;
	}
};


int main()
{
	// Set fixed-point notation and precision for output
	cout << fixed << setprecision(1); 
	
	// Create a deque to hold monthScores objects
	deque<monthScores> testScoreDeque; 

	// Create a map with a string key and a vector of integers as value
	map<string, vector<int> > januaryScores;

	januaryScores["Alice"] = { 85, 90, 78 };
	januaryScores["Bob"] = { 88, 92, 80 };
	januaryScores["Charlie"] = { 82, 85, 88 };

	monthScores january("January", januaryScores);

	map<string, vector<int> > februaryScores;
	februaryScores["Alice"] = { 90, 92, 85 };
	februaryScores["Bob"] = { 91, 89, 84 };
	februaryScores["Charlie"] = { 87, 90, 85 };

	monthScores february("February", februaryScores);

	// Add the maps to the deque
	testScoreDeque.push_back(january);
	testScoreDeque.push_back(february);

	int scoreTotal;

	while (!testScoreDeque.empty())
	{
		monthScores &currentMonth = testScoreDeque.front();

		string monthName = currentMonth.getMonthName();
		map<string, vector<int> > scores = currentMonth.getScores();

		cout << "Scores for " << monthName << endl;
		cout << "-----------------------------------" << endl;
		for (auto it = scores.begin(); it != scores.end(); it++)
		{
			scoreTotal = 0;
			string studentName = it->first;
			vector<int> studentScores = it->second;
			
			cout << studentName << "\t: " << flush;
			for (int i = 0; i < studentScores.size(); i++)
			{
				scoreTotal += studentScores[i];
				cout << studentScores[i] << " " << flush;
			}

			cout << " | Average: " << (double)scoreTotal / (double)studentScores.size() << endl;
		}

		testScoreDeque.pop_front();

		cout << endl;
		cout << "===================================" << endl;
	}

	return 0;
}

