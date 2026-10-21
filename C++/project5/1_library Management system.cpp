
#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 10;

// Abstract Base Class
class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d)
    {
        title = t;
        author = a;
        dueDate = d;
    }

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    string getDueDate() const
    {
        return dueDate;
    }

    void setTitle(string t)
    {
        title = t;
    }

    void setAuthor(string a)
    {
        author = a;
    }

    void setDueDate(string d)
    {
        dueDate = d;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    virtual ~LibraryItem()
    {
    }
};

// Derived Class: Book
class Book : public LibraryItem
{
private:
    string ISBN;

public:
    Book(string t, string a, string d, string i)
        : LibraryItem(t, a, d)
    {
        ISBN = i;
    }

    void checkOut()
    {
        cout << "Book checked out successfully!" << endl;
    }

    void returnItem()
    {
        cout << "Book returned successfully!" << endl;
    }

    void displayDetails() const
    {
        cout << "Type: Book" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "ISBN: " << ISBN << endl;
    }
};

// Derived Class: DVD
class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, string d, int du)
        : LibraryItem(t, a, d)
    {
        duration = du;
    }

    void checkOut()
    {
        cout << "DVD checked out successfully!" << endl;
    }

    void returnItem()
    {
        cout << "DVD returned successfully!" << endl;
    }

    void displayDetails() const
    {
        cout << "Type: DVD" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Duration: " << duration << " minutes" << endl;
    }
};

// Main Function
int main()
{
    LibraryItem* libraryItems[MAX_ITEMS] = {NULL};

    int count = 0;
    int choice, itemNo, duration;
    string title, author, date, isbn, searchTitle;
    bool found;

    do
    {
        cout << "\n===== Library Management System =====" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Add DVD" << endl;
        cout << "3. Display All Items" << endl;
        cout << "4. Search Item" << endl;
        cout << "5. Check Out Item" << endl;
        cout << "6. Return Item" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.fail())
        {
            cout << "Invalid input!" << endl;
            break;
        }

        cin.ignore(1000, '\n');

        if (choice == 1 || choice == 2)
        {
            if (count >= MAX_ITEMS)
            {
                cout << "Library is full!" << endl;
                continue;
            }

            cout << "Enter title: ";
            getline(cin, title);

            cout << "Enter author: ";
            getline(cin, author);

            cout << "Enter due date: ";
            getline(cin, date);

            if (title.empty() || author.empty() || date.empty())
            {
                cout << "Fields cannot be empty!" << endl;
                continue;
            }

            if (choice == 1)
            {
                cout << "Enter 13-digit ISBN: ";
                getline(cin, isbn);

                if (isbn.length() != 13)
                {
                    cout << "ISBN must be 13 digits!" << endl;
                    continue;
                }

                found = true;

                for (int i = 0; i < 13; i++)
                {
                    if (isbn[i] < '0' || isbn[i] > '9')
                    {
                        found = false;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Invalid ISBN!" << endl;
                    continue;
                }

                libraryItems[count] =
                    new Book(title, author, date, isbn);
            }
            else
            {
                cout << "Enter DVD duration: ";
                cin >> duration;

                if (cin.fail())
                {
                    cout << "Invalid duration input!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                if (duration <= 0)
                {
                    cout << "Duration must be positive!" << endl;
                    continue;
                }

                cin.ignore(1000, '\n');

                libraryItems[count] =
                    new DVD(title, author, date, duration);
            }

            count++;

            cout << "Item added successfully!" << endl;
        }
        else if (choice == 3)
        {
            if (count == 0)
            {
                cout << "No items available!" << endl;
            }

            for (int i = 0; i < count; i++)
            {
                cout << "\nItem Number: " << i + 1 << endl;
                libraryItems[i]->displayDetails();
            }
        }
        else if (choice == 4)
        {
            cout << "Enter title to search: ";
            getline(cin, searchTitle);

            found = false;

            for (int i = 0; i < count; i++)
            {
                if (libraryItems[i]->getTitle() == searchTitle)
                {
                    libraryItems[i]->displayDetails();
                    found = true;
                }
            }

            if (!found)
            {
                cout << "Item not found!" << endl;
            }
        }
        else if (choice == 5 || choice == 6)
        {
            if (count == 0)
            {
                cout << "No items available!" << endl;
                continue;
            }

            cout << "Enter item number (1-" << count << "): ";
            cin >> itemNo;

            if (cin.fail())
            {
                cout << "Invalid item number!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (itemNo < 1 || itemNo > count)
            {
                cout << "Invalid item number!" << endl;
                continue;
            }

            if (choice == 5)
            {
                libraryItems[itemNo - 1]->checkOut();
            }
            else
            {
                libraryItems[itemNo - 1]->returnItem();
            }
        }
        else if (choice == 7)
        {
            cout << "Thank you for using LMS!" << endl;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    // Free allocated memory
    for (int i = 0; i < count; i++)
    {
        delete libraryItems[i];
    }

    return 0;
}

