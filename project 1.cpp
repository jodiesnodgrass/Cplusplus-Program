// Jodie Snodgrass
// 1/23/25
// project 1

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void clockBorder() {
	for (int i = 0; i < 16; ++i) {
		cout << " ";
	}
	for (int i = 0; i < 27; ++i) {
		cout << "*";
	}
	for (int i = 0; i < 5; ++i) {
		cout << " ";
	}
	for (int i = 0; i < 27; ++i) {
		cout << "*";
	}
	cout << endl;
}

void Clocks(int hours, int minutes, int seconds) { //outputs both 24 and 12 clocks
	int hoursCon; // changed hours
	int minutesCon; // changed minutes
	int secondsCon; // changed seconds
	string amPm = " AM"; // AM or PM

	if (hours == 0) { // verifing if 0 24 hour clock then it is 12 AM 12 hour clock
		hoursCon = 12;
	}
	else if (hours == 12) { // if past hour 12 changes to PM
		hoursCon = hours;
		amPm = " PM";
	}
	else if (hours > 12) { // if hours greater than 12 subtract 12 to get PM time
		hoursCon = hours - 12;
		amPm = " PM";
	}
	else { // if AM hours they stay the same as 24 hour clock no change needed
		hoursCon = hours;
	}
	// clock titles 
	cout << "\t\t*\t" << "12 Hour Clock";
	cout << "\t *";
	cout << "\t*" << "\t24 Hour Clock";
	cout << "\t *" << endl;


	// set up for 12 hour clock 
	cout << "\t\t* \t ";
	cout << setw(2) << setfill('0') << hoursCon << ":";
	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds;
	cout << " " << amPm;
	cout << "\t *";

	//set up for 24 hour clock
	cout << "\t*" << "\t ";
	cout << setw(2) << setfill('0') << hours << ":";
	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds;
	cout << endl;
}
// takes input hour, minutes and seconds
void initialTime(int& setHour, int& setMinute, int& setSecond) {
	string inputString; //holds input values
	string tempString; //for user time input validation
	bool validTime = false; //valid time toggle for while statement 
	int firstColon; // used to find first colon
	int secondColon; // finds second colon

	while (!validTime) { //informs user how to input time for 24 hour clock
		cout << "Input time as HH:MM:SS for 24 hour clock: ";
		getline(cin, inputString);

		firstColon = inputString.find(':');
		secondColon = inputString.find(':', firstColon + 1);

		try
		{ //assign and change if needed if integers and ignore if not integer
			setHour = stoi(inputString.substr(0, firstColon)); //takes input as integer 
			setMinute = stoi(inputString.substr(firstColon + 1, secondColon)); //takes input as integer
			setSecond = stoi(inputString.substr(secondColon + 1, inputString.size() - 1)); //takes inptu as integer
		}
		catch (const std::exception&) //not planning to do something with the exception
		{

		}
		if (inputString.size() != 8) { // verfying character input should be 8 incluing colons
			cout << "Invalid time" << endl;
			!validTime;
		}
		else if (setHour < 0 || setHour > 23) { // if input is less than 0 or greater than 23 prints "Invalid time"
			cout << "Invalid time" << endl;
			!validTime;
		}
		else if (setMinute < 0 || setMinute > 59) { //if input less than 0 or more than 59 prints "Invalid time"
			cout << "Invalid time" << endl;
			!validTime;
		}
		else if (setSecond < 0 || setSecond > 59) { //same as minutes input
			cout << "Invalid time" << endl;
			!validTime;
		}
		else {
			validTime = true; //valid input
		}
	}
}
void printMainMenu() { // main nenu options
	cout << endl;
	cout << "******************************" << endl; //border for menu
	cout << "* 1-add one hour\t\t*" << endl;
	cout << "* 2-add one minute\t\t*" << endl;
	cout << "* 3-add one second\t\t*" << endl;
	cout << "* 4-exit\t\t\t*" << endl; //end program
	cout << "******************************" << endl;
	cout << endl;
}
//validates input
void processUserInput(int& userChoice, int& setHour, int& setMinute, int& setSecond) {
	cout << "Select option (1-4): "; //asks to pick a number 1-4

	if (!(cin >> userChoice)) { //verifies only numbers
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //if not integer input is ignored
		userChoice = 0;
	}

	switch (userChoice) {
	case 1:
		cout << "1 hour added" << endl;
		if (setHour < 23) { //adds 1 hour
			++setHour;
		}
		else {
			setHour = 00; //resets to 00 once 24 is reached
		}
		break;
	case 2:
		cout << "1 minute added" << endl;
		if (setMinute < 59) { //adds 1 minute
			++setMinute;
		}
		else {
			setMinute = 00; //resets to 00 once 59 is reached
		}
		break;
	case 3:
		cout << "1 second added" << endl;
		if (setSecond < 59) { //adds 1 second
			++setSecond;
		}
		else {
			setSecond = 00; //resets to 00 once 59 is reached
		}
		break;
	case 4:
		cout << "Thank you. Goodbye!" << endl; //ends program
		break;
	default:
		cout << "Invalid choice. Please pick again between 1 and 4" << endl; //reminds the user to pick a number between 1-4
		cin.clear();
		break;
	}
}

int main() { //uses the clock to midnight
	int userChoice = 0;
	int setHour = 0;
	int setMinute = 0;
	int setSecond = 0;

	initialTime(setHour, setMinute, setSecond); //asks for initial time

	while (userChoice != 4) {
		clockBorder();
		Clocks(setHour, setMinute, setSecond);
		clockBorder();
		printMainMenu(); //prints menu for user to pick
		processUserInput(userChoice, setHour, setMinute, setSecond); //takes input modifies to clock

	}
	return 0;
}
