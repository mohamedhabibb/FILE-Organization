#include<iostream>
#include<fstream>
#include  <string.h>
#include  <string>
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
        cin.getline(Book.Author, 11);
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
            fil.getline(Book.Author, 11, '|');
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
            fil.getline(Book.Author, 11, '|');
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
            fil.getline(Book.Author, 11, '|');
            fil.getline(Book.size, 25, '|');
            fil.getline(Book.type, 14);
            if (strcmp(a, Book.name) == 0)
            {

                cout << " \n\tenter new value of record  \n ";
                cout << " \n name : ";
                cin.getline(Book.name, 30);
                cout << " \nAuthor : ";
                cin.getline(Book.Author, 11);
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
            temp.getline(Book.Author, 11, '|');
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
            fil.getline(Book.Author, 11, '|');
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
            temp.getline(Book.Author, 11, '|');
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
int main()
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


    return 0;

}
