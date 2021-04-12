/*
Date:		12/11/2019
File:		TelephoneDirectorySource.cpp
Descr:
Design and impelement a telephone directory system
add a telephone directory entry, search for an entry by name
reverse the number look up, delete an entry by phone number
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void nameLookup(struct TelephoneDirectory t1);			// function to look up names
// splash screen to start user input
void menu(struct TelephoneDirectory t1, struct TelephoneDirectory t2, struct TelephoneDirectory t3, struct TelephoneDirectory t4);				
void deleteEntry(struct TelephoneDirectory t3);			// deleting from the telephone directory
void reverseNumberLookup(struct TelephoneDirectory t2);	// searching the directory by the number
void addNumber(struct TelephoneDirectory t4);			// adding the number to the directory

struct TelephoneDirectory {
	string firstName;			// to hold first name data
	string lastName;			// to hold last name data
	string firstFile;			// searching file for first name
	string lastFile;			// searching file for last name
	string numberFile;			// searching file for number
	string telephoneNumber;		// to hold number data
	string userInput;			// variable to hold data input
	string deleteNum;			// variable to delete number
	string line;				// variable to find line number to delete the telephone number

};

int main()
{
	// variable declarations
	string fname;

	// prompt user for filename and read
	cout << "Please enter a Telephone Directory: ";
	getline(cin, fname);

	// declaring structures for each function
	struct TelephoneDirectory t1;		
	struct TelephoneDirectory t2;
	struct TelephoneDirectory t3;
	struct TelephoneDirectory t4;
	menu(t1, t2, t3, t4);		// call splash screen menu for user input
	return 0;	// close out 
	
}
void addNumber(struct TelephoneDirectory t4)		// function to add number to the telephone directory
{
	string userInput = " ";		// what the user inputs
	ofstream outFile;	//opening an output file
	
	outFile.open("TelephoneDirectory2.txt");
	cout << "Enter a number to the directory that you would like to add: ";
	cin >> t4.userInput;		// inputting information from the user
	outFile << t4.userInput << endl;	// adding information to output file

	cout << "The number: " << t4.userInput << " was added to the directory" << endl;	// letting the user know number was added
	outFile.close();	//closing an output file

}
void reverseNumberLookup(struct TelephoneDirectory t2)		// function to lookup a person by putting in their number
{

	char chr;
	ifstream infile;


	infile.open("TelephoneDirectory.txt"); //opening the file TelephoneDirectory.txt
	infile >> t2.firstFile >> t2.lastFile >> t2.numberFile;

	cout << "Telephone Number to look up: "; //prompt user for number to be deleted
	cin >> t2.numberFile;   //data is inputted

	if (t2.numberFile == t2.firstFile && t2.telephoneNumber == t2.numberFile)  //checking to see if the input matches
		cout << t2.firstName << " " << t2.lastName << " number is " << t2.numberFile << endl; //printing out the information

	cout << "That Telephone Number belongs to: " << t2.firstName << " " << t2.lastName << endl;	// printing out the name of who owns the number

}

void deleteEntry(struct TelephoneDirectory t3)		// function to delete a number from the telephone directory
{
	
	
	ifstream f;					// opening file
	f.open("TelephoneDirectory.txt");
	ofstream temp;				// output file to write too temporarly
	temp.open("temp.txt");		// open temp folder to delete
	
	cout << "what telephone number would you like to delete: ";		// prompt user to delete number
	cin >> t3.deleteNum;					// user input number to be deleted
	while (getline(f, t3.line))
	{
		if (t3.line != t3.deleteNum)
		{
			temp << t3.line << endl;
		}
	}
	temp.close();		// closing the file
	f.close();			// closing the file
	//remove("TelephoneDirectory.txt");
	//rename("temp.txt", "TelephoneDirectory.txt");
	cout << t3.deleteNum << " has been removed from the directory";		// display message that number has been deleted
}

void nameLookup(struct TelephoneDirectory t1)	// function to lookup number by inputting first and last name
{

	char chr;
	char cont = 'Y';
	ifstream inFile;


	inFile.open("TelephoneDirectory.txt"); //opening the file TelephoneDirectory.txt
	inFile >> t1.firstFile >> t1.lastFile >> t1.numberFile;
	
	cout << "Enter a First Name and a Last Name: "; //prompt user for first and last name input
	cin >> t1.firstName >> t1.lastName;   //data is inputted

	if(cont == 'Y')		// if user wants to continue 'Y'
	{
		if (t1.firstName == t1.firstFile && t1.lastName == t1.lastFile)  //checking to see if the input matches
			cout << t1.firstName << " " << t1.lastName << " number is " << t1.numberFile << endl; //printing out the information
	}
	if (!inFile)	// run a loop for failure
	{
		cout << "Sorry that is not in our database." << endl;   //error message if name isn't in system
	}
	cout << "Would you like to search for another name? Y or N" << endl;  //user is asked if they would like to continue
	cin >> cont;
	if (cont == 'N')
	{
		return;
	}
	inFile.close(); //close file
	cin >> chr;
}

void menu(struct TelephoneDirectory t1, struct TelephoneDirectory t2, struct TelephoneDirectory t3, struct TelephoneDirectory t4)		// function to display options for user
{
	int userChoice = 0;	// variable to hold user choice
	// splash screen display of options available
	cout << "1. Add a telephone directory entry" << endl;
	cout << "2. Search for an entry by name" << endl;
	cout << "3. Reverse number look up" << endl;
	cout << "4. Delete an entry by phone number" << endl;

	cout << "Enter your choice: "; // prompt user for input
	cin >> userChoice;				// inputting information
	if (userChoice == 1)			// looping user choice to bring them to function call
	{
		addNumber(t4);
	}
	else if 
	(userChoice == 2)
	{
		nameLookup(t1);
	}
	else if
	(userChoice == 3)
	{
		reverseNumberLookup(t2);
	}
	else if
	 (userChoice == 4)
	{
		deleteEntry(t3);
	}

}

/*
TEST OUTPUT OF ALL FUNCTIONS 

Please enter a Telephone Directory: "D:\TelephoneDirectory.txt"
1. Add a telephone directory entry
2. Search for an entry by name
3. Reverse number look up
4. Delete an entry by phone number
Enter your choice: 1
Enter a number to the directory that you would like to add: 123123
The number: 123123 was added to the directory





----------------------------------------------------------------------------------------------------------------------------------------------------


Please enter a Telephone Directory: "D:\TelephoneDirectory.txt"
1. Add a telephone directory entry
2. Search for an entry by name
3. Reverse number look up
4. Delete an entry by phone number
Enter your choice: 2
Enter a First Name and a Last Name: Marge Walder
Marge Walder number is 312-840-3405
Would you like to search for another name? Y or N
N




----------------------------------------------------------------------------------------------------------------------------------------------------


Please enter a Telephone Directory: "D:\TelephoneDirectory.txt"
1. Add a telephone directory entry
2. Search for an entry by name
3. Reverse number look up
4. Delete an entry by phone number
Enter your choice: 3
Telephone Number to look up: 312-445-9892
That Telephone Number belongs to:




----------------------------------------------------------------------------------------------------------------------------------------------------


Please enter a Telephone Directory: "D:\TelephoneDirectory.txt"
1. Add a telephone directory entry
2. Search for an entry by name
3. Reverse number look up
4. Delete an entry by phone number
Enter your choice: 4
what telephone number would you like to delete: 217-451-0184
217-451-0184 has been removed from the directory



*/
