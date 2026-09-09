// Write a program that outputs an acceptance letter for Makerere University. It should prompt a user to enter their first name, last name, study program, academic year.
// The program should have autodates

// Example:

// Date: 27th August 2026

// To: John Okello,

// Dear John,

// CONGRATULATIONS! I am pleased to inform you that the Makerere University 
// Admissions Board has approved your application for admission to the 
// 2027/2028 academic year.

// You have been offered a place for the following course:
// PROGRAM: Bachelor of Science in Computer and Communication Engineering

// As a student of Makerere University, you will be part of a historic 
// institution dedicated to academic excellence and innovation. Please ensure 
// that you report to the Academic Registrar's office with your original 
// academic documents for verification during the orientation week.

// We look forward to welcoming you to the Makerere University.

// Yours sincerely,


// John Doe
// Registra
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
    string firstName, lastName, course, academicYear;

    // Get details from user
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cin.ignore(); // Clear newline buffer
    
    cout << "Enter the Course Applied : ";
    getline(cin, course);
    cout << "Enter Academic Year : ";
    getline(cin, academicYear);

    // Get current date automatically
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    // Formatting variables for day, month, year
    int day = ltm->tm_mday;
    int month = 1 + ltm->tm_mon;
    int year = 1900 + ltm->tm_year;

    // Print out the official letter

    cout << "                MAKERERE UNIVERSITY                   \n";
    cout << "         Office of the Academic Registrar             \n";
    cout << "         P.O. Box 7062, Kampala, Uganda               \n";
    cout << "Date: " << day << "/" << month << "/" << year << "\n\n";
    
    cout << "To: " << firstName << " " << lastName << ",\n\n";
    
    cout << "Dear " << firstName << ",\n\n";
    cout << "CONGRATULATIONS! I am pleased to inform you that you \n"
         << "have been offered admission to Makerere University for the \n"
         << "academic year " << academicYear << ".\n\n";
         
    cout << "You have been admitted to the following programme:\n"
         << ">> " << course << " <<\n\n";
         
    cout << "Please note that registration will begin prior to the \n"
         << "commencement of the semester. Bring your original academic \n"
         << "documents for verification.\n\n";
         
    cout << "We wish you success in your academic journey.\n\n";
    cout << "Yours Sincerely,\n\n";
    cout << "Academic Registrar\n";
    
    return 0;
