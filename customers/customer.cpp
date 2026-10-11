#include<iostream>
#include<fstream>
#include  <string.h>
#include  <string>
using namespace std;
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
    return 0;

}
