#include <iostream>
#include <fstream>
#include <string>
#include<windows.h>
using namespace std;
// Function to add a new book to the library
void addBook() {
    string title, ISSN, publisher;
    float cost;
    ofstream libraryBooks("library_books.txt", ios::app);
    cout << "Enter book title: ";
    cin >> title;
    cout << "Enter ISSN: ";
    cin >> ISSN;
    cout << "Enter publisher: ";
    cin >> publisher;
    cout << "Enter cost: ";
    cin >> cost;
    libraryBooks << title << "," << ISSN << "," << publisher << "," << cost << endl;
    libraryBooks.close();
    cout << "Book added to the library successfully." << endl;
}
// Function to display the details of a book
void viewBook(string bookTitle) {
    string line;
    ifstream libraryBooks("library_books.txt");
    while (getline(libraryBooks, line)) {
        if (line.find(bookTitle) != string::npos) {
            cout << line << endl;
            libraryBooks.close();
            return;
        }
    }
    libraryBooks.close();
    cout << "Book not found in the library." << endl;
}
// Function to check if a student has a book issued
bool checkIssued(string studentName) {
    string line;
    ifstream issuedBooks("issued_books.txt");
    while (getline(issuedBooks, line)) {
        if (line.find(studentName) != string::npos) {
            issuedBooks.close();
            return true;
        }
    }
    issuedBooks.close();
    return false;
}
// Function to issue a book to a student and not issue the new book if the student have already issue a book
void issueBook(string studentName, string bookTitle) {
if(checkIssued(studentName)){
cout << "Student has a book issued. Returning previous book before issuing a new one." << endl;
return;
}
ofstream issuedBooks("issued_books.txt", ios::app);
issuedBooks << studentName << "," << bookTitle << endl;
issuedBooks.close();
cout << "Book issued to " << studentName << "." << endl;
}
	void display(int a){
		string all;
		ifstream readall("library_books.txt");
		cout<<endl;
		while(getline(readall,all)){
			cout<<endl<<all<<endl;
		}
		cout<<endl<<endl;
}
int main() {
	{ 
	  {	
  	cout<<"\n\t\t..........WELCOME TO THE LIBRARY..........";
  	cout<<"\n                ";}
  	for(int i=0;i<42;i++)
  	{
  		Sleep(15);
  		cout<<char(260);
	  }
}
int choice;
while (true) {
cout << "\n\n1. Add a new book" << endl;
cout << "2. View book details" << endl;
cout << "3. Issue a book" << endl;
 cout <<"4. All Books" << endl;
cout << "5. Exit" << endl;
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
addBook();
break;
case 2: {
string bookTitle;
cout << "Enter book title: ";
cin >> bookTitle;
viewBook(bookTitle);
break;
}
case 3: {
string studentName, bookTitle;
cout << "Enter student name: ";
cin >> studentName;
cout << "Enter book title: ";
cin >> bookTitle;
issueBook(studentName, bookTitle);
break;
}
case 4: {
		//display all books
	display(choice);
	break;}
case 5:
return 0;
default:
cout << "Invalid choice. Please enter a valid choice." << endl;
break;
}
}
return 0;
}
