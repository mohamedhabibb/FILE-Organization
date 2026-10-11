#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
using namespace std;
class Book_sections
{
private:
    char name[30];
    char Author[14];
    char size[25];
    char type[11];

public:
    void add_Book()
    {
        Book_sections Book;
        fstream fil;
        fil.open("Book.txt", ios::app);
        cin.ignore();
        cout << " \n name : ";
        cin.getline(Book.name, 30);
        cout << " \n Author : ";
        cin.getline(Book.Author, 14);
        cout << " \n size : ";
        cin.getline(Book.size, 25);
        cout << " \n type : ";
        cin.getline(Book.type, 14);

        fil << Book.name << '|' << Book.Author << '|' << Book.size << '|' << Book.type << '\n';
        cout << "done !";
        fil.close();
    }
    void search_Book()
    {
        Book_sections Book;
        fstream fil;
        fil.open("Book.txt", ios::in);

        char a[11];
        cout << " \n enter the name of Book to search about it : ";
        cin.ignore();
        cin.getline(a, 11);
        int x = 0;
        cout << " \n\t name \t Author \t size \t type \n";
        while (!fil.eof())
        {
            fil.getline(Book.name, 30, '|');
            fil.getline(Book.Author, 14, '|');
            fil.getline(Book.size, 25, '|');
            fil.getline(Book.type, 14);

            if (strcmp(Book.name, a) == 0)
            {
                cout << "\n \t " << Book.name << "\t" << Book.Author << "\t" << Book.size << "\t" << Book.type << "\t" << "\t" << endl;
                x = 1;
                break;
            }

        }
        if (x == 0)
        {
            cout << " \n not found !!!!\n";
        }
        fil.close();
    }
    void display_all()
    {
        Book_sections Book;
        fstream fil;
        fil.open("Book.txt", ios::in);

        cout << " \n\t name \t Author \t size \t type \n";
        while (!fil.eof())
        {
            fil.getline(Book.name, 30, '|');
            fil.getline(Book.Author, 14, '|');
            fil.getline(Book.size, 25, '|');
            fil.getline(Book.type, 14);

            cout << "\n \t " << Book.name << "\t" << Book.Author << "\t" << Book.size << "\t" << Book.type << "\t" << "\t" << endl;

        }
    }
    void update_Book()
    {
        fstream fil;
        fstream temp;
        Book_sections Book;
        fil.open("Book.txt", ios::in);
        temp.open("temp.txt", ios::out);
        char a[30];
        cin.ignore();
        cout << " \n\t enter the name of book to update record : ";
        cin.getline(a, 25);
        while (!fil.eof())
        {
            fil.getline(Book.name, 30, '|');
            fil.getline(Book.Author, 14, '|');
            fil.getline(Book.size, 25, '|');
            fil.getline(Book.type, 14);
            if (strcmp(a, Book.name) == 0)
            {

                cout << " \n\tenter new value of record  \n ";
                cout << " \n name : ";
                cin.getline(Book.name, 30);
                cout << " \nAuthor : ";
                cin.getline(Book.Author, 14);
                cout << " \n size : ";
                cin.getline(Book.size, 11);
                cout << " \n type : ";
                cin.getline(Book.type, 14);


                temp << Book.name << '|' << Book.Author << '|' << Book.size << '|' << Book.type << '\n';

            }
            else
            {

                temp << Book.name << '|' << Book.Author << '|' << Book.size << '|' << Book.type << '\n';

            }


        }
        temp.close();
        fil.close();

        fil.open("Book.txt", ios::out);
        temp.open("temp.txt", ios::in);
        while (!temp.eof())
        {
            temp.getline(Book.name, 30, '|');
            temp.getline(Book.Author, 14, '|');
            temp.getline(Book.size, 25, '|');
            temp.getline(Book.type, 14);
            fil << Book.name << '|' << Book.Author << '|' << Book.size << '|' << Book.type << '\n';

        }
        temp.close();
        fil.close();
        remove("temp.txt");
        cout << "\n done !!! \n";
    }
    void delete_Book()
    {

        fstream fil;
        fstream temp;
        Book_sections Book;
        fil.open("Book.txt", ios::in);
        temp.open("temp.txt", ios::out);
        char a[25];
        cin.ignore();
        cout << " \n\t enter the name of Book to delete record : ";
        cin.getline(a, 25);
        while (!fil.eof())
        {
            fil.getline(Book.name, 30, '|');
            fil.getline(Book.Author, 14, '|');
            fil.getline(Book.size, 25, '|');
            fil.getline(Book.type, 14);

            if (strcmp(Book.name, a) == 0)
            {
                continue;
            }
            else
            {

                temp << Book.name << '|' << Book.Author << '|' << Book.size << '|' << Book.type << '\n';

            }


        }
        temp.close();
        fil.close();
        fil.open("Book.txt", ios::out);
        temp.open("temp.txt", ios::in);
        while (!temp.eof())
        {
            temp.getline(Book.name, 30, '|');
            temp.getline(Book.Author, 14, '|');
            temp.getline(Book.size, 25, '|');
            temp.getline(Book.type, 14);

            fil << Book.name << '|' << Book.Author << '|' << Book.size << '|' << Book.type << '\n';

        }
        temp.close();
        fil.close();
        remove("temp.txt");
        cout << "\n done !!! \n";
    }


};


class Employee
{
private:
    char name[30];
    char mail[14];
    char age[25];
    char phone[11];
    char address[30];
    char job[30];
public:
    void add_employee()
    {


        Employee person;
        fstream fil;
        fil.open("management.txt", ios::app);
        cin.ignore();
        cout << " \n name : ";
        cin.getline(person.name, 30);
        cout << " \n phone : ";
        cin.getline(person.phone, 11);
        cout << " \n age : ";
        cin.getline(person.age, 25);
        cout << " \n mail : ";
        cin.getline(person.mail, 14);
        cout << " \n addres : ";
        cin.getline(person.address, 30);
        cout << " \n job: ";
        cin.getline(person.job, 30);
        fil << person.name << '|' << person.phone << '|' << person.age << '|' << person.mail << '|' << person.address << '|' << person.job << '\n';
        cout << "done !";
        fil.close();
    }
    void search_employee()
    {
        Employee person;
        fstream fil;
        fil.open("management.txt", ios::in );

        char a[11];
        cout << " \n enter the phone to search about it : ";
        cin.ignore();
        cin.getline(a, 11);
        int x = 0;
         cout << " \n\t name \t phone \t age \t mail \t address \t job\n";
        while (!fil.eof())
        {
            fil.getline(person.name, 30, '|');
            fil.getline(person.phone, 11, '|');
            fil.getline(person.age, 25, '|');
            fil.getline(person.mail, 14, '|');
            fil.getline(person.address, 30, '|');
            fil.getline(person.job, 25);
            if (strcmp(person.phone, a) == 0)
            {
                cout << "\n \t " << person.name << "\t" << person.phone << "\t" << person.age<<"\t" << person.mail << "\t" << person.address <<"\t"<< person.job << "\t" << "\t" << endl;
                x = 1;
                break;
            }

        }
        if (x == 0)
        {
            cout << " \n not found !!!!\n";
        }
        fil.close();
    }
    void display_all()
    {
        Employee person;
        fstream fil;
        fil.open("management.txt", ios::in);

        cout << " \n\t name \t phone \t age \t mail \t address \t job\n";
        while (!fil.eof())
        {
            fil.getline(person.name, 30, '|');
            fil.getline(person.phone, 11, '|');
            fil.getline(person.age, 25, '|');
            fil.getline(person.mail, 14, '|');
            fil.getline(person.address, 30, '|');
            fil.getline(person.job, 25);
            cout << "\n \t " << person.name << "\t" << person.phone << "\t" << person.age<< "\t"<< person.mail << "\t" << person.address<< "\t" << person.job << "\t" << "\t" << endl;

        }
    }
    void update_employee()
    {
        fstream fil;
        fstream temp;
        Employee person;
        fil.open("management.txt", ios::in);
        temp.open("temp.txt", ios::out);
        char a[25];
        cin.ignore();
        cout << " \n\t enter the phone number to update record : ";
        cin.getline(a, 25);
        while (!fil.eof())
        {
            fil.getline(person.name, 30, '|');
            fil.getline(person.phone, 11, '|');
            fil.getline(person.age, 25, '|');
            fil.getline(person.mail, 14, '|');
            fil.getline(person.address, 30, '|');
            fil.getline(person.job, 25);
            if (strcmp(a, person.phone) == 0)
            {

                cout << " \n\tenter new value of record  \n ";
                cout << " \n name : ";
                cin.getline(person.name, 30);
                cout << " \n phone : ";
                cin.getline(person.phone, 11);
                cout << " \n age : ";
                cin.getline(person.age, 25);
                cout << " \n mail : ";
                cin.getline(person.mail, 14);
                cout << " \n addres : ";
                cin.getline(person.address, 30);
                cout << " \n job: ";
                cin.getline(person.job, 30);


                temp << person.name << '|' << person.phone << '|' << person.age << '|' << person.mail << '|' << person.address << '|' << person.job << '\n';

            }
            else
            {

                temp << person.name << '|' << person.phone << '|' << person.age << '|' << person.mail << '|' << person.address << '|' << person.job << '\n';

            }


        }
        temp.close();
        fil.close();

        fil.open("management.txt", ios::out);
        temp.open("temp.txt", ios::in);
        while (!temp.eof())
        {
            temp.getline(person.name, 30, '|');
            temp.getline(person.phone, 11, '|');
            temp.getline(person.age, 25, '|');
            temp.getline(person.mail, 14, '|');
            temp.getline(person.address, 30, '|');
            temp.getline(person.job, 25);
            fil << person.name << '|' << person.phone << '|' << person.age << '|' << person.mail << '|' << person.address << '|' << person.job << '\n';

        }
        temp.close();
        fil.close();
        remove("temp.txt");
        cout << "\n done !!! \n";
    }
    void delete_employee()
    {

        fstream fil;
        fstream temp;
        Employee person;
        fil.open("management.txt", ios::in);
        temp.open("temp.txt", ios::out);
        char a[25];
        cin.ignore();
        cout << " \n\t enter the phone number to delete record : ";
        cin.getline(a, 25);
        while (!fil.eof())
        {
            fil.getline(person.name, 30, '|');
            fil.getline(person.phone, 11, '|');
            fil.getline(person.age, 25, '|');
            fil.getline(person.mail, 14, '|');
            fil.getline(person.address, 30, '|');
            fil.getline(person.job, 25);
            if (strcmp(person.phone, a) == 0)
            {
                continue;
            }
            else
            {

                temp << person.name << '|' << person.phone << '|' << person.age << '|' << person.mail << '|' << person.address << '|' << person.job << '\n';

            }


        }
        temp.close();
        fil.close();

        fil.open("management.txt", ios::out);
        temp.open("temp.txt", ios::in);
        while (!temp.eof())
        {
            temp.getline(person.name, 30, '|');
            temp.getline(person.phone, 11, '|');
            temp.getline(person.age, 25, '|');
            temp.getline(person.mail, 14, '|');
            temp.getline(person.address, 30, '|');
            temp.getline(person.job, 25);
            fil << person.name << '|' << person.phone << '|' << person.age << '|' << person.mail << '|' << person.address << '|' << person.job << '\n';

        }
        temp.close();
        fil.close();
        remove("temp.txt");
        cout << "\n done !!! \n";
    }


};




class customer
{
private:
    char name[30];
    char mail[14];
    char age[25];
    char phone[11];
    char address[30];
    char job[30];
public:
    void addcustomer()
    {


        customer person;
        fstream fil;
        fil.open("customer.txt", ios::app);
        cin.ignore();
        cout << " \n name : ";
        cin.getline(person.name, 30);
        cout << " \n phone : ";
        cin.getline(person.phone, 11);
        cout << " \n age : ";
        cin.getline(person.age, 25);
        cout << " \n mail : ";
        cin.getline(person.mail, 14);
        cout << " \n addres : ";
        cin.getline(person.address, 30);
        cout << " \n job: ";
        cin.getline(person.job, 30);
        fil << person.name << '|' << person.phone << '|' << person.age << '|' << person.mail << '|' << person.address << '|' << person.job << '\n';
        cout << "done !";
        fil.close();
    }
    void search_customer()
    {
        customer person;
        fstream fil;
        fil.open("customer.txt", ios::in );

        char a[11];
        cout << " \n enter the phone to search about it : ";
        cin.ignore();
        cin.getline(a, 11);
        int x = 0;
         cout << " \n\t name \t phone \t age \t mail \t address \t job\n";
        while (!fil.eof())
        {
            fil.getline(person.name, 30, '|');
            fil.getline(person.phone, 11, '|');
            fil.getline(person.age, 25, '|');
            fil.getline(person.mail, 14, '|');
            fil.getline(person.address, 30, '|');
            fil.getline(person.job, 25);
            if (strcmp(person.phone, a) == 0)
            {
                cout << "\n \t " << person.name << "\t" << person.phone << "\t" << person.age<<"\t" << person.mail << "\t" << person.address <<"\t"<< person.job << "\t" << "\t" << endl;
                x = 1;
                break;
            }

        }
        if (x == 0)
        {
            cout << " \n not found !!!!\n";
        }
        fil.close();
    }
    void display_all()
    {
        customer person;
        fstream fil;
        fil.open("customer.txt", ios::in);

        cout << " \n\t name \t phone \t age \t mail \t address \t job\n";
        while (!fil.eof())
        {
            fil.getline(person.name, 30, '|');
            fil.getline(person.phone, 11, '|');
            fil.getline(person.age, 25, '|');
            fil.getline(person.mail, 14, '|');
            fil.getline(person.address, 30, '|');
            fil.getline(person.job, 25);
            cout << "\n \t " << person.name << "\t" << person.phone << "\t" << person.age<< "\t"<< person.mail << "\t" << person.address<< "\t" << person.job << "\t" << "\t" << endl;

        }
    }
    void update_customer()
    {
        fstream fil;
        fstream temp;
        customer person;
        fil.open("customer.txt", ios::in);
        temp.open("temp.txt", ios::out);
        char a[25];
        cin.ignore();
        cout << " \n\t enter the phone number to update record : ";
        cin.getline(a, 25);
        while (!fil.eof())
        {
            fil.getline(person.name, 30, '|');
            fil.getline(person.phone, 11, '|');
            fil.getline(person.age, 25, '|');
            fil.getline(person.mail, 14, '|');
            fil.getline(person.address, 30, '|');
            fil.getline(person.job, 25);
            if (strcmp(a, person.phone) == 0)
            {

                cout << " \n\tenter new value of record  \n ";
                cout << " \n name : ";
                cin.getline(person.name, 30);
                cout << " \n phone : ";
                cin.getline(person.phone, 11);
                cout << " \n age : ";
                 cin.getline(person.age, 25);
                cout << " \n mail : ";
                cin.getline(person.mail, 14);
                cout << " \n addres : ";
                cin.getline(person.address, 30);
                cout << " \n job: ";
                cin.getline(person.job, 30);


                temp << person.name << '|' << person.phone << '|' << person.age << '|' << person.mail << '|' << person.address << '|' << person.job << '\n';

            }
            else
            {

                temp << person.name << '|' << person.phone << '|' << person.age << '|' << person.mail << '|' << person.address << '|' << person.job << '\n';

            }


        }
        temp.close();
        fil.close();

        fil.open("customer.txt", ios::out);
        temp.open("temp.txt", ios::in);
        while (!temp.eof())
        {
            temp.getline(person.name, 30, '|');
            temp.getline(person.phone, 11, '|');
            temp.getline(person.age, 25, '|');
            temp.getline(person.mail, 14, '|');
            temp.getline(person.address, 30, '|');
            temp.getline(person.job, 25);
            fil << person.name << '|' << person.phone << '|' << person.age << '|' << person.mail << '|' << person.address << '|' << person.job << '\n';

        }
        temp.close();
        fil.close();
        remove("temp.txt");
        cout << "\n done !!! \n";
    }
    void delete_customer()
    {

        fstream fil;
        fstream temp;
        customer person;
        fil.open("customer.txt", ios::in);
        temp.open("temp.txt", ios::out);
        char a[25];
        cin.ignore();
        cout << " \n\t enter the phone number to delete record : ";
        cin.getline(a, 25);
        while (!fil.eof())
        {
            fil.getline(person.name, 30, '|');
            fil.getline(person.phone, 11, '|');
            fil.getline(person.age, 25, '|');
            fil.getline(person.mail, 14, '|');
            fil.getline(person.address, 30, '|');
            fil.getline(person.job, 25);
            if (strcmp(person.phone, a) == 0)
            {
                continue;
            }
            else
            {

                temp << person.name << '|' << person.phone << '|' << person.age << '|' << person.mail << '|' << person.address << '|' << person.job << '\n';

            }


        }
        temp.close();
        fil.close();

        fil.open("customer.txt", ios::out);
        temp.open("temp.txt", ios::in);
        while (!temp.eof())
        {
            temp.getline(person.name, 30, '|');
            temp.getline(person.phone, 11, '|');
            temp.getline(person.age, 25, '|');
            temp.getline(person.mail, 14, '|');
            temp.getline(person.address, 30, '|');
            temp.getline(person.job, 25);
            fil << person.name << '|' << person.phone << '|' << person.age << '|' << person.mail << '|' << person.address << '|' << person.job << '\n';

        }
        temp.close();
        fil.close();
        remove("temp.txt");
        cout << "\n done !!! \n";
    }

};



int main()
{
cout<<"\t\t\t\t\t The library Management system"<<endl;
cout<<"\t\t\t\t\t -----------------------------"<<endl;
int x;
cout<<"Enter  1 to go to Books"<<endl;
cout<<"Enter  2 to go to Management"<<endl;
cout<<"Enter  3 to go to Customers"<<endl;
cin>>x;
if(x==1)
{
     bool flag = true;
     while (flag)
     {
        Book_sections Book;
        cout << "add_Book: 1 \n search_Book : 2 \n display all : 3 \n update_Book : 4 \n delete_Book :  5 \n write your choose : ";
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
            Book.add_Book();
            break;
        case 2:
            Book.search_Book();
            break;
        case 3:
            Book.display_all();
            break;
        case 4:
            Book.update_Book();

            break;
        case 5:
            Book.delete_Book();
            break;
        default:
            cout << " \n choose right number \n";
        }

        cout << " if you continue to use program press ' yes ' \n ";
        string f;
        cin >> f;
        if (f != "yes")
        {
            flag = false;
            cout << "finished..!!!!\n";
        }
    }

}
else if(x==2)
{

    bool flag = true;
    while (flag)
    {
        Employee person;
        cout << " add_employee: 1 \n search_employee : 2 \n display all : 3 \n update : 4 \n delete :  5 \n write your choose : ";
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
            person.add_employee();
            break;
        case 2:
            person.search_employee();
            break;
        case 3:
            person.display_all();
            break;
        case 4:
            person.update_employee();

            break;
        case 5:
            person.delete_employee();
            break;
        default:
            cout << " \n choose right number \n";
        }
        cout << " if you continue to use program press ' yes ' \n ";
        string f;
        cin >> f;
        if (f != "yes")
        {
            flag = false;
            cout<<"finished..!!!!\n";
        }
    }


}
else if(x==3)
{

  bool flag = true;
    while (flag)
    {
        customer person;
        cout << " addCustomer: 1 \n search_customer : 2 \n display all : 3 \n update : 4 \n delete :  5 \n write your choose : ";
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
            person.addcustomer();
            break;
        case 2:
            person.search_customer();
            break;
        case 3:
            person.display_all();
            break;
        case 4:
            person.update_customer();

            break;
        case 5:
            person.delete_customer();
            break;
        default:
            cout << " \n choose right number \n";
        }
        cout << " if you continue to use program press ' yes ' \n ";
        string f;
        cin >> f;
        if (f != "yes")
        {
            flag = false;
            cout<<"finished..!!!!\n";
        }
    }


}
else
    cout<<"your choose  not found"<<endl;

   return 0;


}
