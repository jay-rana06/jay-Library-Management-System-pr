#include <iostream>
// #include <string>

using namespace std;

class LibraryItem
{
    private:
        string title;
        string author;
        string dueDate;
        int quantity;

    public:
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

        void setquantity(int q) 
        { 
            quantity = q; 
        }

        string getTitle() 
        { 
            return title; 
        }

        string getAuthor() 
        { 
            return author; 
        }

        string getDueDate() 
        { 
            return dueDate; 
        }

        int getquantity() 
        { 
            return quantity; 
        }

        virtual void checkOut() = 0;
        virtual void returnItem() = 0;
        virtual void displayDetails() = 0;

        virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
    public: 
        void checkOut() 
        { 
            cout << "Book checked out."<<endl; 
        }

        void returnItem() 
        { 
            cout << "Book returned."<<endl; 
        }

        void displayDetails()
        {
            cout << "Item Type: Book";
            cout << "Title: " << getTitle() << ""<<endl;
            cout << "Author: " << getAuthor() << ""<<endl;
            cout << "Due Date: " << getDueDate() << ""<<endl;
            cout << "Quantity: " << getquantity() << ""<<endl;
        }
};

class DVD : public LibraryItem
{
    public:
        void checkOut() { cout << "DVD checked out."<<endl; }
        void returnItem() { cout << "DVD returned."<<endl; }

        void displayDetails()
        {
            cout << "Item Type: DVD";
            cout << "Title: " << getTitle() << "<<endl";
            cout << "Author: " << getAuthor() << ""<<endl;
            cout << "Due Date: " << getDueDate() << ""<<endl;
            cout << "Quantity: " << getquantity() << ""<<endl;
        }
};

class Magazine : public LibraryItem
{
    public:
        void checkOut() 
        { 
            cout << "Magazine checked out."<<endl; 
        }

        void returnItem() 
        { 
            cout << "Magazine returned."<<endl; 
        }

        void displayDetails()
        {
            cout << "Item Type: Magazine";
            cout << "Title: " << getTitle() << ""<<endl;
            cout << "Author: " << getAuthor() << ""<<endl;
            cout << "Due Date: " << getDueDate() << ""<<endl;
            cout << "Quantity: " << getquantity() << ""<<endl;
        }
};

int main()
{
    const int MAX_ITEMS = 10;
    LibraryItem* items[MAX_ITEMS];
    int count = 0;

    int choice;

    do
    {
        cout << "--- Library Menu ---"<<endl;
        cout << "1. Add Book"<<endl;
        cout << "2. Add DVD"<<endl;
        cout << "3. Add Magazine"<<endl;
        cout << "4. Display Items"<<endl;
        cout << "5. Check Out Item"<<endl;
        cout << "6. Return Item"<<endl;
        cout << "7. Exit"<<endl;

        cout << "Enter choice: "<<endl;
        cin >> choice;
        cin.ignore();

        if (choice == 1 || choice == 2 || choice == 3)
        {
            if (count >= MAX_ITEMS)
            {
                cout << "Library full!"<<endl;
                continue;
            }

            string t, a, d;
            int q;

            cout << "Enter Title: ";
            getline(cin, t);

            cout << "Enter Author: ";
            getline(cin, a);

            cout << "Enter Due Date: ";
            cin >> d;

            cout << "Enter Quantity: ";
            cin >> q;

            if (q <= 0)
            {
                cout << "Quantity must be positive!"<<endl;
                continue;
            }

            if (choice == 1)
                items[count] = new Book();
            else if (choice == 2)
                items[count] = new DVD();
            else
                items[count] = new Magazine();

            items[count]->setTitle(t);
            items[count]->setAuthor(a);
            items[count]->setDueDate(d);
            items[count]->setquantity(q);

            count++;
            cout << "Item added successfully!"<<endl;
        }

        else if (choice == 4)
        {
            if (count == 0)
                cout << "No items available."<<endl;
            else
            {
                for (int i = 0; i < count; i++)
                {
                    cout << "-----------------"<<endl;
                    items[i]->displayDetails();
                }
            }
        }

        else if (choice == 5)
        {
            int idx;
            cout << "Enter item number to check out (0-" << count - 1 << "): ";
            cin >> idx;

            if (idx < 0 || idx >= count)
                cout << "Invalid index!"<<endl;
            else
                items[idx]->checkOut();
        }

        else if (choice == 6)
        {
            int idx;
            cout << "Enter item number to return (0-" << count - 1 << "): ";
            cin >> idx;

            if (idx < 0 || idx >= count)
                cout << "Invalid index!"<<endl;
            else
                items[idx]->returnItem();
        }

        else if (choice != 7)
        {
            cout << "Invalid choice!"<<endl;
        }

    } while (choice != 7);

    for (int i = 0; i < count; i++)
        delete items[i];

    cout << "Exiting..."<<endl;
    return 0;
}