/*Student : Samantha Sands
* Class : CS210
* Date : 15 - 03 - 26
* Purpose : A program that displays both a 12 and 24 hour clock with the ability to add hour, minute, or second
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function for the clock borders
void clockBorder() {
	for (int i = 0; i < 16; ++i) { // For loop for side padding
		cout << " ";
	}
	for (int i = 0; i < 27; ++i) { // For loop that prints * border for 12 hour clock
		cout << "*";
	}
	for (int i = 0; i < 5; ++i) { // For loop that prints padding between clocks
		cout << " ";
	}
	for (int i = 0; i < 27; ++i) { // For loop that prints * border for 24 hour clock 
		cout << "*";
	}
	cout << endl;
}

void Clocks(int hours, int minutes, int seconds) { // Outputs both the 12 hour and 24 hour clock

	// Attributes used for 12 hour conversion
	int hourCon;        // Hour conversion
	int minCon;         // Minute conversion
	int secCon;         // Second conversion
	string amPm = "AM"; // AM or PM

	// Conversion for 24 hour clock to 12 hour clock 
	if (hours == 0) { // If 0 on 24 hour clock, reads as 12 on 12 hour clock
		hourCon = 12;
	}

	else if (hours == 12) { // If past hour 12, now Pm
		hourCon = hours;
		amPm = "PM";
	}

	else if (hours > 12) { // If great than 12 on 24 hour clock, subtract 12 to get Pm time
		hourCon = hours - 12;
		amPm = "PM";
	}

	else { // If Am hours are the same
		hourCon = hours;
	}

	// Clock Titles
	cout << "\t\t*\t" << "12 Hour Clock";
	cout << "\t  *";
	cout << "\t*" << "\t24 Hour Clock";
	cout << "\t  *" << endl;

	// Set up for the 12 hour clock
	cout << "\t\t* \t ";
	cout << setw(2) << setfill('0') << hourCon << ":";
	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds;
	cout << "" << amPm;
	cout << "\t  *";

	// Set up for the 24 hour clock
	cout << "\t*" << "\t  ";
	cout << setw(2) << setfill('0') << hours << ":";
	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds;
	cout << endl;
}

// Taking input for hour, minutes, and seconds
void initialTime(int& setHour, int& setMinute, int& setSecond) {
	string inputString; // Holds input
	string tempString; // User time input validation
	bool validTime = false; 
	int firstColon; // Finds the first colon
	int secondColon; // Finds the second colon

	while (!validTime) { // Tells the user what to do to get the clocks, and how to input the information
		cout << "Please input time as HH:MM:SS for 24 hour clock: ";
		getline(cin, inputString);

		firstColon = inputString.find(':');
		secondColon = inputString.find(':', firstColon + 1);

		try
		{
			setHour = stoi(inputString.substr(0, firstColon)); // takes in first section to colon and converts it
			setMinute = stoi(inputString.substr(firstColon + 1, secondColon)); // takes in second section after 1st colon and converts it
			setSecond = stoi(inputString.substr(secondColon + 1, inputString.size() - 1)); // takes in last section and converts it
		}

		catch (const std::exception&)
		{
		}

		if (inputString.size() != 8) {// Verifies character input is 8, which includes colons
			cout << "Invalid time" << endl;
			!validTime;
		}

		else if (setHour < 0 || setHour > 23) { // If hour less than 0 or greater than 23 prints 'invalid'
			cout << "Invalid time" << endl;
			!validTime;
		}

		else if (setMinute < 0 || setMinute > 59) { // If minute less than 0 or greater than 59 prints 'invalid'
			cout << "Invalid time" << endl;
			!validTime;
		}

		else if (setSecond < 0 || setSecond > 59) { // If second less than 0 or greater than 59 prints 'invalid'
			cout << "Invlaid time" << endl;
			!validTime;
		}

		else { // Valid input
			validTime = true;
		}
	}
}

void printMainMenu() { // The main menu options
	cout << endl;
	cout << "*********************************" << endl; //border for menu
	cout << "* 1 - Add One Hour\t\t*" << endl;
	cout << "* 2 - Add One Minute\t\t*" << endl;
	cout << "* 3 - Add One Second\t\t*" << endl;
	cout << "* 4 - Exit Program\t\t*" << endl; // Ends the program
	cout << "*********************************" << endl;
	cout << endl;
}

void processUserInput(int& userChoice, int& setHour, int& setMinute, int& setSecond) {
	cout << "Select option (1-4): "; // Asks user to pick a number

	if (!(cin >> userChoice)) {
		cin.clear();

		cin.ignore(numeric_limits < streamsize > ::max(), '\n'); // Input ignored if not a number
		userChoice = 0;
	}

	switch (userChoice) {
	case 1:
		cout << "1 Hour Added" << endl;
		if (setHour < 23) { // Adds an hour
			++setHour;
		}
		
		else {
			setHour = 00; // Resets the clock at 24
		}
		break;

	case 2:
		cout << "1 Minute Added" << endl;
		if (setMinute < 59) { // Adds a minute
			++setMinute;
		}
		else {
			setMinute = 00; // Resets the minutes after 59
		}
		break;

	case 3:
		cout << "1 Second Added" << endl;
		if (setSecond < 59) { // Adds a second
			++setSecond;
		}
		else {
			setSecond = 00; // Resets the seconds after 59
		}
		break;

	case 4:
		cout << "Thank you, Goodbye!" << endl; // Ends program
		break;

	default:
		cout << "Invalid choice.  Please choose again between 1 and 4." << endl; // Asks for a number corresponding to action
		cin.clear();
		break;
	}
}

int main() { // Sets the clock up for midnight
	int userChoice = 0;
	int setHour = 0;
	int setMinute = 0;
	int setSecond = 0;

	initialTime(setHour, setMinute, setSecond); // Asks for starting time

	while (userChoice != 4) {
		clockBorder();
		Clocks(setHour, setMinute, setSecond);
		clockBorder();
		printMainMenu(); // Prints the menu
		processUserInput(userChoice, setHour, setMinute, setSecond); // takes input for modifying the clock
	}
	return 0;
}

