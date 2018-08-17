#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void LoadFile(string airport[], int delay[], int &dataCount)
{
	ifstream inFile("C:\\Users\\Ali\\Downloads\\Airline_Delays-2015-11-13\\AirlineDelays\\airline_delays.txt");
	
	// if the file is not good, let the user know
	if (!inFile.good())
	{
		cout << "Cannot find the file!" << endl;
	}
	else
	{
		while (!inFile.eof()){
			inFile >> airport[dataCount];
			inFile >> delay[dataCount];
			dataCount++;
		}
	}

	inFile.close();
}

void AvgDelay(string airport[], int delay[], int dataCount)
{
	cout << "For which airport? ";
	string airportCode;
	cin >> airportCode;

	double sum = 0;
	int count = 0;

	for (int i = 0; i < dataCount; i++)
	{
		// the airport must be same as the provided airport, or provided airport needs to be ALL
		if (airport[i] == airportCode || airportCode == "ALL")
		{
			sum += delay[i];
			count++;
		}
	}

	double avg = sum / count;
	cout << "Average Delay: " << avg << " minutes" << endl;
}

void MaxDelay(string airport[], int delay[], int dataCount)
{
	int maxDelayIndex = 0; // take the very first flight as max delay

	// then go through all flights starting from second one
	for (int i = 1; i < dataCount; i++)
	{
		// if I find a delay greater than or equal to the one I am holding
		if (delay[i] > delay[maxDelayIndex])
		{
			maxDelayIndex = i;
		}
	}
	cout << "Maximum Delay: " << delay[maxDelayIndex] / 60.0 << " hours" << endl;
	cout << "At Airport: " << airport[maxDelayIndex] << endl;
}

void FlightCount(string airport[], int delay[], int dataCount)
{
	cout << "For which airport? ";
	string airportCode;
	cin >> airportCode;

	cout << "Minimum Delay? ";
	int minDelay;
	cin >> minDelay;

	int count = 0;

	for (int i = 0; i < dataCount; i++)
	{
		// same as AvgDelay() function
		if (airport[i] == airportCode || airportCode == "ALL")
		{
			if (delay[i] >= minDelay){
				count++;
			}
		}
	}

	cout << "There are " << count << " flights that matched the criteria." << endl;
}

int main()
{
	// at most 1000 flights in the file
	string airport[1000];
	int delay[1000];
	int dataCount = 0;

	LoadFile(airport, delay, dataCount);

	while (true)
	{
		cout << endl;
		cout << "Airport Delay Report v1.0" << endl;
		cout << "=========================" << endl;
		cout << "1- Average Delay" << endl;
		cout << "2- Maximum Delay" << endl;
		cout << "3- Flight Count" << endl;
		cout << "0- Exit" << endl;
		cout << "What do you want to do? ";
		int choice;
		cin >> choice;

		if (choice == 1) 
		{
			AvgDelay(airport, delay, dataCount);
		}
		else if (choice == 2)
		{
			MaxDelay(airport, delay, dataCount);
		}
		else if (choice == 3)
		{
			FlightCount(airport, delay, dataCount);
		}
		else if (choice == 0)
		{
			break;
		}
	}

	system("PAUSE");
	return 0;
}