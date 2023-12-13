#include<iostream>
#include<string>
#include <vector>
#include <fstream>
#include <filesystem> // Use C++ 17
namespace fs = std::filesystem;
using namespace std;
//VARIABLES DITO
string discountChoice, titleCharacter;
int totpricerep;
//LOGIN VARIABLES
string loguser, logpass, logDecision, regiuser, regipass, filename, variFile, FULLname;

int choice = 0, catalogueChoice, booknum, decision;
int jsChoice, programmingChoice, programLanguageChoice, cppChoice, pythonChoice; //switch values for programming section
int mathChoice, algebraChoice, calculusChoice, statsChoice; //switch values for math section
int scienceChoice, chemistryChoice, biologyChoice, physicsChoice; //switch value for science section
bool redoing = true, catalogueRedo = true;
bool programmingRedo = true, programmingLNG = true, cppRedo = true, pythonRedo = true, jsRedo = true; //boolean values for programming section
bool mathRedo = true, algebraRedo = true, calculusRedo = true, statsRedo = true; //boolean values for math section
bool scienceRedo = true, chemistryRedo = true, biologyRedo = true, physicsRedo = true, cartRedo = true;//boolean values for science section
string restart;
//Book stuff
string Books[27] = { "Introduction to Computer Programming (C++ Edition)", "The C++ Programming Language", "Programming: Principles and Practice of C++",
"Fluent Python", "Python Crash Course, 3rd Edition", "Head First Python", "JavaScript: The Good Parts", "Head First JavaScript Programming: A brain-friendly Guide", "JavaScript: The Definitive Guide",
"Linear Algebra done right", "College Algebra", "Algebra: A Complete Introduction", "Calculus: An Intuitive and Physical Approach", "Calculus Made Easy", "Calculus: Early Transcendentals",
"Visual Display of Quantitative Information", "The  Elements of Statistical Learning", "An Introduction to Statistical Learning: With Applications in R", "Organic Chemistry as a Second Language",
"General Chemistry", "Nature’s Building Blocks", "Concepts of Biology", "On the Origin of Species", "The Selfish Gene", "Fundamentals of Physics I: Mechanics, Relativity, and Thermodynamics",
"Basic Physics: A Self-Teaching Guide", "" };
int Bookprices[] = { 3000,3500,3450,2500,2300,2000,3000,3000,2999,1500,1700,2000,3200,2500,3300,2500,3000,3200,1000,2300,3999,3000,2000,3050,2300,1000,1400 };
string x[100]; //Stored Books
string recochoice;
//ASHY VARIABLE
int i = 1, totprice;
int b1, b2, b3, MOP, amo, ansr, tru;
char egg;
bool transac = true, ans;

//LOGIN SYSTEM
//FILESAVING SYSTEM
int fileCounter = 1, f;
void loadFileCounter(); // void function prototype 
void saveFileCounter(); //Void function prototype 


void loadFileCounter()
{
    ifstream counterFile("counter.txt");
    if (counterFile.is_open()) {
        counterFile >> fileCounter;
        counterFile.close();
    }
}

void saveFileCounter()
{
    ofstream counterFile("counter.txt");
    if (counterFile.is_open()) {
        counterFile << fileCounter;
        counterFile.close();
    }
}
void OverwriteFiles(const std::string& targetUser, const std::string& targetPass) {
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::ifstream inFile(entry.path());
            if (inFile.is_open()) {
                std::string line;
                std::string storedUser, storedPass;

                while (getline(inFile, line)) {
                    // Extract stored username and password from the file
                    if (line.find("Username:") != std::string::npos) {
                        storedUser = line.substr(line.find(":") + 2); // Extract after the colon
                    }
                    else if (line.find("Password:") != std::string::npos) {
                        storedPass = line.substr(line.find(":") + 2);
                    }
                }

                // Compare with the target username and password
                if (storedUser == targetUser && storedPass == targetPass)
                {
                    system("CLS");
                    inFile.close();
                    // Overwrite the file with new information
                    inFile.close();
                    std::ofstream outFile(entry.path());
                    outFile << "Full name: " << FULLname << endl;
                    outFile << "Username: " << loguser << endl;
                    outFile << "Password: " << logpass << endl;
                    outFile << "Books Rented: \n";
                    outFile << "--------------------------------------------";
                    for (i = 1; i <= 27; i++)
                    {
                        if (x[i] == "")
                        {
                            break;
                        }
                        outFile << "\n" << i << ". " << x[i] << endl;
                    }
                    cout << "Account updated successfully!" << endl;
                    return; // Exit the function if login is successful
                }

                inFile.close();
            }
            else {
                std::cerr << "Error opening file: " << entry.path() << std::endl;
                return;
            }
        }
    }

    std::cout << "Invalid Username and Password" << std::endl;
    exit(1); // Exit program
}
void loadVariablesFromFile(const string& filename, string& FULLname, string& loguser, string& logpass, string x[], int& i)
{
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            if (line.find("Full name:") != string::npos) {
                FULLname = line.substr(line.find(":") + 2);
            }
            else if (line.find("Username:") != string::npos) {
                loguser = line.substr(line.find(":") + 2);
            }
            else if (line.find("Password:") != string::npos) {
                logpass = line.substr(line.find(":") + 2);
            }
            else if (line.find("Books Rented:") != string::npos) {
                for (i = 0; getline(inFile, line) && line != "--------------------------------------------"; ++i) {
                    x[i] = line;
                }
            }
        }
        inFile.close();
    }
    else {
        cerr << "Error opening file: " << filename << endl;
    }
}
//Read all Files
void readAllFiles(const std::string& targetUser, const std::string& targetPass) {
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::ifstream inFile(entry.path());
            if (inFile.is_open()) {
                std::string line;
                std::string storedUser, storedPass;

                while (getline(inFile, line)) {
                    // Extract stored username and password from the file
                    if (line.find("Username:") != std::string::npos) {
                        storedUser = line.substr(line.find(":") + 2); // Extract after the colon
                    }
                    else if (line.find("Password:") != std::string::npos) {
                        storedPass = line.substr(line.find(":") + 2);
                    }
                }

                // Compare with the target username and password
                if (storedUser == targetUser && storedPass == targetPass)
                {
                    system("CLS");
                    std::cout << "Login successful!" << std::endl;
                    cout << "Welcome back reader!" << endl;
                    loadVariablesFromFile(filename, FULLname, loguser, logpass, x, i);
                    cout << endl;
                    cout << endl;
                    inFile.close();
                    return; // Exit the function if login is successful
                }

                inFile.close();
            }
            else {
                std::cerr << "Error opening file: " << entry.path() << std::endl;
                return;
            }
        }
    }

    std::cout << "Invalid Username and Password" << std::endl;
    exit(1); // Exit program
}
//Storing books function 
string Bookstore(string& a, string& b) //function kasi nakakatamad
{
    a = b;
    return b;
}
int Price(int& a, int& b) //Function uli
{
    a = a + b;
    return b;
}
void cinfail(int a, bool b)
{
    if (cin.fail())
    {

        system("CLS");
        cin.ignore();
        cin.clear();
        return;
    }
}
void clear()
{
    for (int i = 1; i < 27; ++i)
    {
        cout << "\n" << x[i];
        if (x[i] == "") {
            break;
        }
        x[i] = "";
    }
}

void redo(string& a, bool& b) // Restart function
{
    bool valid = true;
    do {
        cout << "Invalid option, would you like to try again ? (y / n)\n";
        cin >> a;


        if (a == "y" || a == "Y") {
            b = true;
            valid = true;
        }
        else if (a == "n" || a == "N") {
            exit(1);
        }
        else if (a != "y" && a != "Y" && a != "n" && a != "N" || cin.fail())
        {
            cin.clear();
            cin.ignore();
            valid = false;

        }


    } while (!valid);
}
void  checkout(char a, bool& b) // Checkout function
{
    if (a == 'y' || a == 'Y') {
        b = false;
        exit(1);
    }
    else if (a == 'n' || a == 'N') {
        b = true;
    }

}

//Void Assign Price
void DeterminePrice(int& a, int b)
{
    a += b;
}

void goback(int& a, bool& b, int& c)
{
    system("CLS");
    cinfail(a, b);
    if (a == 4)
    {
        system("CLS");
        b = false;
        c = 4;
    }
    if (a == 5)
    {
        system("CLS");
        b = false;

    }

    if (a != 1 && a != 2 && a != 3 && a != 4 && a != 5)
    {
        system("CLS");

        redo(restart, b);
        system("CLS");

    }
}

//Moeka variable
int PLC;
int DiscountCode(int& priceold) {
    string dcode, repChoice;
    bool dcoderep = true;
    while (dcoderep) {
        cout << "Enter Discount Code: ";
        cin >> dcode;
        if (dcode == "TIPQC") {
            priceold = priceold * 0.9;
            cout << "Discount Applied, New price is Php " << priceold;
            dcoderep = false;
            return priceold;

        }
        else if (dcode == "CCS") {
            priceold = priceold - 250;
            cout << "Discount Applied, New price is Php " << priceold;
            dcoderep = false;
            return priceold;

        }
        else
            cout << "Would you like to try again? (y/n): ";
        cin >> repChoice;
        if (repChoice == "y" || repChoice == "Y") {
            dcoderep = true;
        }
        else {
            dcoderep = false;
            cout << "No Discount Applied";
        }
    }
    return priceold;
}

void recommendation(int a, string b, string c, string d)
{

    system("CLS");

    do {
        cout << "\nDo you want to check out other books based on your selected book? (Yes/No)" << endl;
        cin >> recochoice;
        // process user choice
        if (recochoice == "yes" || recochoice == "Yes")
        {
            do {
                cout << "\nHere are your book recommendations:" << endl;
                if (a == 1)
                {
                    cout << "- " << c << endl; cout << "- " << d;
                }
                else if (a == 2)
                {
                    cout << "- " << b << endl; cout << "- " << d;
                }
                else
                {
                    cout << "- " << b << endl; cout << "- " << c;
                }
                cout << "\n\nComing to our shelves soon!! \n “C++ Concurrency in Action”";
                cout << "\n\nThank you for using our recommendation service.\n";
            } while (recochoice != "yes" && recochoice != "Yes");
        }
        else if (recochoice == "no" || recochoice == "No")
        {
            cout << "\nThank you for considering our offer!" << endl;
        }

        else {
            cout << "\nPlease enter 'Yes' or 'No' only." << endl << endl;
        }
    } while (recochoice != "yes" && recochoice != "Yes" && recochoice != "No" && recochoice != "no");
    //end of recommendation service
}



class Book {
public:
    string title;
    bool isBorrowed;
    bool isSelected;

    // Constructor to initialize the book with a title

    Book(const std::string& title) : title(title), isSelected(false), isBorrowed(false) {}

    const string& getTitle() const {
        return title;
    }

    bool getIsSelected() const {
        return isSelected;
    }

    void setIsSelected(bool selected) {
        isSelected = selected;
    }
};

class Library {
private:
    std::vector<Book> books;
    vector<Book>bookselected;

public:
    // Function to add a book to the library
    void addBookSelect(string& title)
    {
        bookselected.emplace_back(title);
    }
    void addBook(const std::string& title) {
        books.emplace_back(title);
    }
    // Function to borrow a book
    void borrowBook(const string& title) {
        for (Book& book : books) {
            if (book.title == title && book.isBorrowed == false) {
                book.isBorrowed = true;

                return;
            }
        }std::cout << "\nYou have successfully borrowed our book! Please treat with outmost care. :)\n\n";


    }


    // Function to return a book
    void returnBook(const std::string& title)
    {

        for (Book& book : books)
        {
            if (book.title == title && !book.isBorrowed)
            {
                book.isBorrowed = false;

                return;
            }
        } system("CLS");
        std::cout << "You have successfully returned: " << title << "\n";


    }


    //LIBRARY CONTENTS
    void displayLibrary() const {
        system("CLS");
        if (books.empty()) {
            std::cout << "The library is empty.\n";
        }
        else {
            std::cout << "Library Contents:\n";
            for (size_t i = 0; i < books.size(); ++i) {
                const Book& book = books[i];
                std::cout << i + 1 << ". Title: " << book.title << endl;

            }
            std::cout << "\n";
        }
        system("pause");
    }

    //SELECT BOOKS

    void selectBook(const string& title, bool selected)
    {
        for (Book& book : books) {
            if (book.getTitle() == title) {
                book.setIsSelected(selected);
                return;
            }
        }
    }

};



void listBooks()
{
    const int minTitleLength = 70;
    for (int i = 1; i <= 27; i++) //Loop Arrays
    {
        if (x[i] == "") //Stops if there is no listed books anymore
        {
            break;
        }

        titleCharacter = x[i]; //Transfer Variable
        int titleLength = titleCharacter.length();
        if (titleLength < minTitleLength) //Adds White space
        {
            for (int j = 0; j < minTitleLength - titleLength; j++)
            {
                titleCharacter += " ";
            }
        }

        cout << i << ". " << titleCharacter << "\t" << "P" << Bookprices[i] << endl;
    }
}

void CartSystem()
{

    if (x[1] == "")
    {
        choice = 4;
        system("CLS"); // Clear
        cout << "No books added yet!" << endl;
        redo(restart, redoing);


    }
    else if (x[1] != "")
    {
        system("CLS"); //Clear Screen
        cout << "Viewing Shopping Cart...\n";
        cout << "-----------------------------------------------------------------------------------------" << endl;
        cout << "Books selected:" << endl;
        listBooks();
        cout << "-----------------------------------------------------------------------------------------" << endl;
    }
}


//Start of Program

int main()
{
    Library library;
    library.addBook("Introduction to Computer Programming(C++ Edition)");
    library.addBook("The C++ Programming Language");
    library.addBook("Programming: Principles and Practice of C++");
    library.addBook("Fluent Python");
    library.addBook("Python Crash Course, 3rd Edition");
    library.addBook("Head First Python");
    library.addBook("JavaScript: The Good Parts");
    library.addBook("Head First JavaScript Programming: A brain-friendly Guide");
    library.addBook("JavaScript: The Definitive Guide");
    library.addBook("Linear Algebra done right");
    library.addBook("College Algebra");
    library.addBook("Algebra: A Complete Introduction");
    library.addBook("Calculus: An Intuitive and Physical Approach");
    library.addBook("Calculus Made Easy");
    library.addBook("Calculus: Early Transcendentals");
    library.addBook("Visual Display of Quantitative Information");
    library.addBook("The  Elements of Statistical Learning");
    library.addBook("An Introduction to Statistical Learning: With Applications in R");
    library.addBook("Organic Chemistry as a Second Language");
    library.addBook("General Chemistry");
    library.addBook("Nature’s Building Blocks");
    library.addBook("Concepts of Biology");
    library.addBook("On the Origin of Species");
    library.addBook("The Selfish Gene");
    library.addBook("Fundamentals of Physics I: Mechanics, Relativity, and Thermodynamics");
    library.addBook("Basic Physics: A Self-Teaching Guide");
    library.addBook("College Physics 2e");
 
    loadFileCounter(); // load function


    cout << "+----------------------------+" << "\n|Welcome to the Login Page ! |" << "\n|       LOGIN||SIGNUP        |" << "\n+----------------------------+" << endl; //Front 
    getline(cin, logDecision);
    if (logDecision == "Login" || logDecision == "login" || logDecision == "LOGIN")
    {

        cout << "Enter your username: ";
        getline(cin, loguser);

        cout << "Enter your password: ";
        getline(cin, logpass);
        readAllFiles(loguser, logpass);
    }


    if (logDecision == "Signup" || logDecision == "signup" || logDecision == "SIGNUP")
    {
        fileCounter++;
        filename = "Account_" + to_string(fileCounter) + ".txt";
        cout << "Enter your full name (LAST NAME, First name, M.I.): ";
        getline(cin, FULLname);
        cout << "Enter your username: ";
        getline(cin, regiuser);

        cout << "Enter your password: ";
        getline(cin, regipass);

        std::ofstream outfile(filename);
        if (outfile.is_open()) {
            outfile << "Full name: " << FULLname << endl;
            outfile << "Username: " << regiuser << endl;
            outfile << "Password: " << regipass << endl;
            outfile << "Due when: " << endl;
        }
        else {
            cout << "Error opening file" << endl;
            return 1;
        }
        system("CLS"); //Clear screen
        cout << "+----------------------------+" << "\n|Welcome to the Login Page ! |" << "\n|       LOGIN||SIGNUP        |" << "\n+----------------------------+" << endl; //Front 
        cout << "Enter your username: ";
        getline(cin, loguser);
        cout << "Enter your password: ";
        getline(cin, logpass);
        if (loguser != regiuser && logpass != regipass)
        {
            cout << "Invalid Username and Password";
            return 0;
        }
        else;
    }
    if (logDecision != "Signup" && logDecision != "signup" && logDecision != "SIGNUP" && logDecision != "Login" && logDecision != "login" && logDecision != "LOGIN")
    {
        cout << "Invalid!";
        return 0;
    }



    while (redoing)
    {
        do
        {
            system("CLS");
            cout << "What would you like to do?\n";
            cout << "1. View catalogue\n";
            cout << "2. View shopping cart\n";
            cout << "3. Return a book\n";
            cout << "4. See the latest books available\n";
            cout << "5. Exit\n\n";
            cout << "Choice: ";
            cin >> choice;
            cinfail(choice, redoing);
            switch (choice)
            {
            case 1:
                catalogueRedo = true;

                while (catalogueRedo)
                {
                    do
                    {
                        system("CLS");
                        cout << "\nOpening catalogue...\n";
                        cout << "1. Programming\n";
                        cout << "2. Mathematics\n";
                        cout << "3. Science\n";
                        cout << "4. Return to catalogue\n";
                        cout << "5. Go back\n";

                        cout << "Choice: ";
                        cin >> programmingChoice;
                        switch (programmingChoice)
                        {

                        case 1:
                            programmingLNG = true;
                            while (programmingLNG)
                            {
                                do
                                {
                                    system("CLS");
                                    cout << "\nEntering Programming Collection.\n";
                                    cout << "Which Programming Language would you like to read about?\n";
                                    cout << "1. C++\n";
                                    cout << "2. Python\n";
                                    cout << "3. JavaScript\n";
                                    cout << "4. Return to catalogue\n";
                                    cout << "5. Go back\n";
                                    cout << "Choice: ";
                                    cin >> programLanguageChoice;
                                    switch (programLanguageChoice)
                                    {
                                    case 1:
                                        cppRedo = true;
                                        while (cppRedo)
                                        {
                                            do {
                                                system("CLS");
                                                cout << "\nPlease choose among the following C++ books available!\n";
                                                cout << "1. Introduction to Computer Programming (C++ Edition)\n";
                                                cout << "2. The C++ Programming Language\n";
                                                cout << "3. Programming: Principles and Practice of C++\n";
                                                cout << "4. Return to catalogue\n";
                                                cout << "5. Go back\n";
                                                cout << "\nChoice: ";
                                                cin >> cppChoice;
                                                switch (cppChoice)
                                                {
                                                case 1:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[0]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[1]);
                                                    recommendation(cppChoice, Books[0], Books[1], Books[2]);
                                                    break;
                                                case 2:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[1]);
                                                    DeterminePrice(totprice, Bookprices[2]);
                                                    recommendation(cppChoice, Books[0], Books[1], Books[2]);
                                                    i++;

                                                    break;
                                                case 3:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[2]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[3]);
                                                    recommendation(cppChoice, Books[0], Books[1], Books[2]);

                                                    break;
                                                } // end of switch cpp

                                            } while (cppChoice >= 1 && cppChoice <= 3); //end of do while cpp
                                            goback(cppChoice, cppRedo, programLanguageChoice);
                                        } //end of while cpp

                                        break; //Case 1 Break

                                    case 2:
                                        pythonRedo = true;
                                        while (pythonRedo)
                                        {
                                            do
                                            {
                                                system("CLS");
                                                cout << "Please choose among the following Python books available!\n";
                                                cout << "1. Fluent Python\n";
                                                cout << "2. Python Crash Course, 3rd Edition\n";
                                                cout << "3. Head First Python\n";
                                                cout << "4. Return to catalogue\n";
                                                cout << "5. Go back\n";
                                                cout << "Choice: ";
                                                cin >> pythonChoice;
                                                switch (pythonChoice)
                                                {
                                                case 1:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[3]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[4]);
                                                    recommendation(pythonChoice, Books[3], Books[4], Books[5]);

                                                    break;

                                                case 2:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[4]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[5]);
                                                    recommendation(pythonChoice, Books[3], Books[4], Books[5]);
                                                    break;

                                                case 3:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[5]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[6]);
                                                    recommendation(pythonChoice, Books[3], Books[4], Books[5]);
                                                    break;
                                                } //end of switch python


                                            } while (pythonChoice <= 3); //end of do while python
                                            goback(pythonChoice, pythonRedo, programLanguageChoice);

                                        } //end of while python
                                        break; //Case 2 Break

                                    case 3:
                                        jsRedo = true;
                                        while (jsRedo)
                                        {
                                            do
                                            {
                                                system("CLS");
                                                cout << "Please choose among the following JavaScript books available!\n";
                                                cout << "1. JavaScript: The Good Parts\n";
                                                cout << "2. Head First JavaScript Programming: A brain-friendly Guide\n";
                                                cout << "3. JavaScript: The Definitive Guide\n";
                                                cout << "4. Return to catalogue\n";
                                                cout << "5. Go back\n";
                                                cout << "Choice: ";
                                                cin >> jsChoice;
                                                switch (jsChoice)
                                                {
                                                case 1:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[6]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[7]);
                                                    recommendation(jsChoice, Books[6], Books[7], Books[8]);
                                                    break;

                                                case 2:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[7]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[8]);
                                                    recommendation(jsChoice, Books[6], Books[7], Books[8]);
                                                    break;

                                                case 3:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[8]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[9]);
                                                    recommendation(jsChoice, Books[6], Books[7], Books[8]);
                                                    break;
                                                } //end of switch JavaScript

                                            } while (jsChoice <= 3); //end of do while JavaScript
                                            goback(jsChoice, jsRedo, programLanguageChoice);
                                        } //end of while JavaSCipt
                                        break; // Case 3 Break
                                    } //end of switch language choice                                                           
                                } while (programLanguageChoice <= 3); //end of do while language choice
                                goback(programLanguageChoice, programmingLNG, programmingChoice);
                            } //end of while language choice
                            break;
                        case 2:
                            while (mathRedo)
                            {
                                do {
                                    system("CLS");
                                    cout << "\nEntering Mathematics Collection.\n";
                                    cout << "Which book in mathematics would you like to read about?\n";
                                    cout << "1. Algebra\n";
                                    cout << "2. Calculus\n";
                                    cout << "3. Statistics\n";
                                    cout << "4. Return to catalogue\n";
                                    cout << "5. Go back\n";
                                    cout << "Choice: ";
                                    cin >> mathChoice;
                                    switch (mathChoice)
                                    {
                                    case 1:
                                        while (algebraRedo)
                                        {
                                            do
                                            {
                                                system("CLS");

                                                cout << "\nPlease choose among the Algebra books available\n";
                                                cout << "1. Linear Algebra done right\n";
                                                cout << "2. College Algebra\n";
                                                cout << "3. Algebra: A Complete Introduction\n";
                                                cout << "4. Return to catalogue\n";
                                                cout << "5. Go back\n";
                                                cout << "Choice: ";
                                                cin >> algebraChoice;
                                                switch (algebraChoice)
                                                {
                                                case 1:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[9]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[10]);
                                                    recommendation(algebraChoice, Books[9], Books[10], Books[11]);
                                                    break;
                                                case 2:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[10]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[11]);
                                                    recommendation(algebraChoice, Books[9], Books[10], Books[11]);
                                                    break;
                                                case 3:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[11]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[12]);
                                                    recommendation(algebraChoice, Books[9], Books[10], Books[11]);
                                                    break;
                                                } //end of switch


                                                 //case 2 Math Break

                                            } while (algebraChoice <= 3); //end of do while math catalogue
                                            goback(algebraChoice, algebraRedo, mathChoice);
                                        } //end of while math catalogue
                                        break;

                                    case 2:
                                        calculusRedo = true;
                                        while (calculusRedo)
                                        {
                                            do
                                            {
                                                system("CLS");
                                                cout << "\nPlease choose among the Calculus books available!\n";
                                                cout << "1. Calculus: An Intuitive and Physical Approach\n";
                                                cout << "2. Calculus Made Easy\n";
                                                cout << "3. Calculus: Early Trancendetals\n";
                                                cout << "4. Return to catalogue\n";
                                                cout << "5. Go back\n";
                                                cout << "Choose: ";
                                                cin >> calculusChoice;
                                                switch (calculusChoice) {
                                                case 1:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[12]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[13]);
                                                    recommendation(calculusChoice, Books[12], Books[13], Books[14]);
                                                    break;
                                                case 2:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[13]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[14]);
                                                    recommendation(calculusChoice, Books[12], Books[13], Books[14]);
                                                    break;
                                                case 3:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[14]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[15]);
                                                    recommendation(calculusChoice, Books[12], Books[13], Books[14]);
                                                    break;
                                                } //end of switch calculus catalogue
                                            } while (calculusChoice <= 3); //end of do while calculus catalogue
                                            break;
                                        } //end of while calculus catalogue
                                        goback(calculusChoice, calculusRedo, mathChoice);
                                        break;

                                    case 3:
                                        statsRedo = true;
                                        while (statsRedo)
                                        {
                                            do {
                                                system("CLS");
                                                cout << "\nPlease choose among the Statistics books available!\n";
                                                cout << "1. Visual Display of Quantitative Information\n";
                                                cout << "2. The Elements of Statistical Learning\n";
                                                cout << "3. An Introduction to Statistical Learning: With Applications in R\n";
                                                cout << "4. Return to catalogue\n";
                                                cout << "5. Go back\n";
                                                cout << "Choose: ";
                                                cin >> statsChoice;
                                                switch (statsChoice)
                                                {
                                                case 1:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[15]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[16]);
                                                    recommendation(statsChoice, Books[15], Books[16], Books[17]);
                                                    break;
                                                case 2:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[16]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[17]);
                                                    recommendation(statsChoice, Books[15], Books[16], Books[17]);
                                                    break;
                                                case 3:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[17]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[18]);
                                                    recommendation(statsChoice, Books[15], Books[16], Books[17]);
                                                    break;
                                                } //end of switch statistics
                                            } while (statsChoice <= 3); //end of do while statistics
                                            break;

                                        } //end of while statistics
                                        goback(statsChoice, statsRedo, mathChoice);



                                    } //end of switch math catalogue



                                } while (mathChoice <= 3); //end of do while math catalogue
                                break;
                            } //end of while math catalogue
                            goback(mathChoice, mathRedo, programmingChoice);

                            break;

                        case 3:
                            scienceRedo = true;
                            while (scienceRedo)
                            {
                                do
                                {
                                    system("CLS");
                                    cout << "\nEntering the Science Collecion.\n";
                                    cout << "Which book in Science would you like to read about?\n";
                                    cout << "1. Chemistry\n";
                                    cout << "2. Biology\n";
                                    cout << "3. Physics\n";
                                    cout << "4. Return to catalogue\n";
                                    cout << "5. Go back\n";
                                    cout << "Choice: ";
                                    cin >> scienceChoice;
                                    switch (scienceChoice)
                                    {
                                    case 1:
                                        chemistryRedo = true;
                                        while (chemistryRedo)
                                        {
                                            do
                                            {
                                                system("CLS");
                                                cout << "\n\nThe following are the Chemistry books available!\n";
                                                cout << "1. Organic Chemistry as the Second Language.\n";
                                                cout << "2. General Chemistry\n";
                                                cout << "3. Nature's Building Blocks.\n";
                                                cout << "4. Return to catalogue\n";
                                                cout << "5. Go back\n";
                                                cout << "Choice: ";
                                                cin >> chemistryChoice;
                                                switch (chemistryChoice)
                                                {
                                                case 1:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[18]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[19]);
                                                    recommendation(chemistryChoice, Books[18], Books[19], Books[20]);
                                                    break;
                                                case 2:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[19]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[20]);
                                                    recommendation(chemistryChoice, Books[18], Books[19], Books[20]);
                                                    break;
                                                case 3:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[20]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[21]);
                                                    recommendation(chemistryChoice, Books[18], Books[19], Books[20]);
                                                    break;
                                                } //end of switch chemistry
                                            } while (chemistryChoice <= 3); //end of do while chemistry
                                            break;
                                        }
                                        goback(chemistryChoice, chemistryRedo, scienceChoice);

                                        break;

                                    case 2:
                                        biologyRedo = true;
                                        while (biologyRedo) {
                                            do {
                                                system("CLS");
                                                cout << "\n\nThe following are the Biology books avaiable!\n";
                                                cout << "1. Concepts of Biology\n";
                                                cout << "2. On the Origins of Species\n";
                                                cout << "3. The Selfish Gene.\n";
                                                cout << "4. Return to catalogue\n";
                                                cout << "5. Go back\n";
                                                cout << "Choose: ";
                                                cin >> biologyChoice;
                                                switch (biologyChoice) {
                                                case 1:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[21]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[22]);
                                                    recommendation(biologyChoice, Books[21], Books[22], Books[23]);
                                                    break;
                                                case 2:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[22]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[23]);
                                                    recommendation(biologyChoice, Books[21], Books[22], Books[23]);
                                                    break;
                                                case 3:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[23]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[24]);
                                                    recommendation(biologyChoice, Books[21], Books[22], Books[23]);
                                                    break;
                                                } //end of switch biology                                         
                                            } while (biologyChoice <= 3); //end of do while biology
                                            goback(biologyChoice, biologyRedo, scienceChoice);
                                        }

                                        break;

                                    case 3:
                                        physicsRedo = true;
                                        while (physicsRedo) {
                                            do {
                                                system("CLS");
                                                cout << "\n\n The following are the Physics books available!\n";
                                                cout << "1. Fundementals of Physica I: Mechanics, Relativity, and Thermodynamics.\n";
                                                cout << "2. Basics Physics: A Slef-Teaching Guide.\n";
                                                cout << "3. College Physics 2e.\n";
                                                cout << "4. Return to catalogue\n";
                                                cout << "5. Go back\n";
                                                cout << "Choose: ";
                                                cin >> physicsChoice;
                                                switch (physicsChoice) {
                                                case 1:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[24]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[25]);
                                                    recommendation(physicsChoice, Books[24], Books[25], Books[26]);
                                                    break;
                                                case 2:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[25]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[26]);
                                                    recommendation(physicsChoice, Books[24], Books[25], Books[26]);
                                                    break;
                                                case 3:
                                                    cout << "\n\nSuccessfully added to cart!\n\n";
                                                    Bookstore(x[i], Books[26]);
                                                    i++;
                                                    DeterminePrice(totprice, Bookprices[27]);
                                                    recommendation(physicsChoice, Books[24], Books[25], Books[26]);
                                                    break;
                                                } //end of switch physics

                                            } while (physicsChoice <= 3); //end of do while physics
                                            break;
                                            goback(physicsChoice, physicsRedo, scienceChoice);
                                        }//end of while physics 

                                        break;
                                    }
                                    break;
                                } while (scienceChoice <= 3); //end of do while science catalogue
                                break;

                            } //end of while science catalogue
                            goback(scienceChoice, scienceRedo, programmingChoice);
                        } //end of switch catalogue


                    } while (programmingChoice >= 1 && programmingChoice <= 3); //end of do while


                    goback(programmingChoice, catalogueRedo, choice);


                }while (choice <= 3)

                    break;




                break; //break of opening catalogue option

            case 2:

                CartSystem();

                if (x[1] != "")
                {
                    cout << "Total Price: " << "P" << totprice << endl;
                    totpricerep = totprice;
                    cout << "Do you want a discount? (yes/no): ";// Ask if the user wants a discount
                    cin >> discountChoice;
                    if (discountChoice == "yes" || discountChoice == "Yes") { // Check if the user wants a discount
                        DiscountCode(totprice);
                    }
                    else if (discountChoice == "no" || discountChoice == "No") {
                        cout << "No Discount Applied";
                    }
                    cout << "\n\nProceed transaction?\n";
                    cout << "\n\n1. Yes || 2. No\n";
                    cin >> b1;
                    if (b1 == 1)
                    {
                        cout << "Do you want to purchase or borrow the book?\n1 = Purchase | 2 = Borrow | 3 = Exit\n";
                        cin >> b3;
                        switch (b3)
                        {
                        case 1: (b3 == 1);
                            cout << "Confirm Purchase" << "\n";
                            cout << "1 = Yes | 2 = No\n";
                            cin >> b2;
                            if (b2 == 1)
                            {
                                cout << "Choose mode of Payment: \n1.Gcash\n2.Credit Card\n";
                                cin >> MOP;
                                switch (MOP)
                                {
                                case 1:
                                    cout << "Your total amount is: \n";
                                    cout << "Enter the exact amount\n\n ";
                                    cin >> amo;
                                    system("CLS");

                                    if (amo >= totprice)
                                    {
                                        amo = amo - totprice;
                                        if (amo != 0)
                                        {
                                            cout << "Total change of: P" << amo << endl;
                                        }
                                        cout << "Success! Proceed to Counter to claim book.\n";
                                        return 0;
                                    }
                                    else
                                    {
                                        cout << "Not enough balance\n\n" << endl;
                                        totprice = totpricerep;
                                    }

                                    break;
                                case 2:
                                    cout << "Your total amount is:  \n";
                                    cout << "Enter the exact amount\n\n ";
                                    cin >> amo;
                                    system("CLS");

                                    if (amo >= totprice)
                                    {
                                        amo = amo - totprice;
                                        if (amo != 0)
                                        {
                                            cout << "Total change of: P" << amo;
                                        }
                                        cout << "Success! Proceed to Counter to claim book.\n";
                                        clear();
                                        return 0;
                                    }
                                    else
                                    {
                                        cout << "Not enough balance\n\n" << endl;
                                        totprice = totpricerep;
                                    }

                                }
                            }
                            else
                            {
                                cout << "\n\n1. Return to Main menu\n";
                                cout << "\n2. Exit \n";
                                cin >> ans;
                                if (ans == 1) {
                                    checkout(ans, redoing);
                                }
                                else {
                                    return 0;
                                }
                            }
                            break;

                        case 2:
                            if (b3 == 2) {
                                cout << "Confirm Borrowed" << "\n";
                                cout << "1 = Yes | 2 = No\n";
                                cin >> ansr;

                                if (ansr == 1) {
                                    string borrowTitle;
                                    for (int i = 1; i < 27; ++i) {
                                        cout << "\n" << x[i];
                                        if (x[i] == "") {
                                            break;
                                        }
                                        borrowTitle = x[i];
                                    }
                                    library.borrowBook(borrowTitle);
                                    system("pause");
                                    clear();
                                }
                                totprice = totpricerep;
                            }
                            else

                            {
                                cout << "\n\n1. Return to Main menu\n";
                                cout << "\n2. Exit \n";
                                cin >> ans;
                                if (ans == 1) {
                                    checkout(ans, redoing);
                                }
                                else {
                                    return 0;
                                }
                                break;
                            }
                            break;
                        } //end of swith
                        break;
                    }
                    else if (b1 == 2) {
                        cout << "\n\nWould you like to go back?\n 1. Yes || 2. No\n";
                        cin >> tru;
                        if (tru == 1)
                        {
                            redoing = true;
                        }
                        else
                        {
                            cout << "Cancelling transaction";
                            return 0;
                        }
                    }
                }
                break;
            case 3:
            {
                string borrowTitle;
                for (int i = 1; i < 27; ++i)
                {
                    cout << "\n" << x[i];
                    if (x[i] == "") {
                        break;
                    }
                    borrowTitle = x[i];
                }
                library.returnBook(x[i]);
             
                clear();

                system("pause");
            }
            break;


            case 4:

                library.displayLibrary();

                break;


            case 5:
                return 0;
                break;

            default:

                redo(restart, redoing);

                break;

                //end of switch

            }

        } while (choice <= 5); //end of do while
    } //end of while 
    return 0;
}


