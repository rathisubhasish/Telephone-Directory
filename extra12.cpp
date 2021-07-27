#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <windows.h>
using namespace std;

struct contac
{
	int mob;
	char name[25];
	char name1[25];
};

int main()
{
loop:
	string nam;
	contac s;
	char ans;
	char ch;
	system("color 80");
	cout << "\n"
			 << endl;
	cout << "\n"
			 << endl;
	cout << "\n"
			 << endl;
	cout << "\t\t\t\t===============================================\n";
	cout << "\t\t\t\t\\ |   |@@    RATHI CONTACTOPEDIA  @@|	     ||\n";
	cout << "\t\t\t\t \\|  |@@                           @@|	     //\n";
	cout << "\t\t\t\t     |@@                           @@|	    //\n";
	cout << "\t\t\t\t    |@@  ** How Can I Help You : ** @@|   \n";
	cout << "\t\t\t\t  |@@                                 @@|\n";
	cout << "\t\t\t\t |@@                                   @@|" << endl;
	cout << "\t\t\t\t|*| 	1) NEW CONTACT			|*|\n";
	cout << "\t\t\t\t|*| 	2) SHOW RECENT DIRECTORY	|*|\n";
	cout << "\t\t\t\t|*| 	3) UPDATE EXISTING CONTACT	|*|\n";
	cout << "\t\t\t\t|*| 	4) DELETE EXISTING CONTACT	|*|\n";
	cout << "\t\t\t\t|*| 	5) EXPLORE ANY CONTACT		|*|\n";
	cout << "\t\t\t\t|*| 	6) EXIT				|*|\n";
	cout << "\t\t\t\t|*| 	 				|*|\n";
	cout << "\t\t\t\t===========================================\n";
	cout << endl;
	cout << endl;
	cout << "\t\t\t\tWHAT DO YOU WANT TO DO : " << endl;
	ch = getch();

	switch (ch)
	{
	case '1':
	{
		system("cls");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		ofstream sdata;
		sdata.open("contact.txt", ios::app);
		do
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "\t\t\t\t***********************************" << endl;
			cout << "\t\t\t\tMAY I HAVE YOUR NAME PLEASE:" << endl;
			cout << "\t\t\t\t";
			cin >> s.name;
			cout << "\t\t\t\tGIVE ME YOUR CONTACT NO.:" << endl;
			cout << "\t\t\t\t";
			cin >> s.mob;
			sdata << endl;
			sdata << s.name;
			sdata << endl;
			sdata << s.mob;
			sdata << endl;
			sdata << endl;
			cout << "\n\t\t\t\tWANT TO --- \n\t\t\t\t1)ADD MORE\n\t\t\t\t2)DONE\n"
					 << endl;
			ans = getch();
		} while (ans == '1' || ans == '1');
		sdata.close();
		system("cls");
		goto loop;
		break;
	}

	case '2':
	{
		system("cls");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		ifstream tdata;
		tdata.open("contact.txt");

		tdata >> s.name;
		tdata >> s.mob;

		while (!tdata.eof())
		{
			cout << "\t\t\t\tNAME:\n"
					 << "\t\t\t\t" << s.name << endl;
			cout << "\t\t\t\tCONTACT NO:\n"
					 << "\t\t\t\t" << s.mob << endl;
			cout << endl;
			tdata >> s.name;
			tdata >> s.mob;
		}
		tdata.close();
		cout << "\t\t\t\t";
		system("pause");
		system("cls");
		goto loop;
		break;
	}

	case '3':
	{
		system("cls");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		int m1;
		string n1;
		cout << "\t\t\t\t====================\n";
		cout << "\t\t\t\tNAME :" << endl;
		cout << "\t\t\t\t";
		cin >> nam;

		ifstream inn;
		inn.open("contact.txt");
		ofstream oww;
		oww.open("record.txt");

		inn >> s.name;
		inn >> s.mob;

		while (!inn.eof())
		{
			if (s.name != nam)
			{
				oww << endl;
				oww << s.name;
				oww << endl;
				oww << s.mob;
				oww << endl;
			}
			else
			{
				cout << "\t\t\t\tENTER NEW NAME :" << endl;
				;
				cout << "\t\t\t\t";
				cin >> n1;
				cout << "\t\t\t\tENTER NEW CONTACT NO :" << endl;
				cout << "\t\t\t\t";
				cin >> m1;

				oww << endl;
				oww << n1;
				oww << endl;
				oww << m1;
				oww << endl;
			}
			inn >> s.name;
			inn >> s.mob;
		}
		oww.close();
		inn.close();

		if (remove("contact.txt") != 0)
		{
			cout << "\t\t\t\tFILE DOES NOT REMOVE";
		}

		if (rename("record.txt", "contact.txt") != 0)
		{
			cout << "\t\t\t\tFILE DOES NOT RENAME";
		}
		else
		{
			cout << "\t\t\t\tUPDATED!!\n";
		}
		cout << "\t\t\t\t";
		system("pause");
		system("cls");
		goto loop;
		break;
	}

	case '4':
	{
		system("cls");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "\t\t\t\tENTER THE NAME TO DELETE :" << endl;
		cout << "\t\t\t\t";
		cin >> nam;

		ifstream inn;
		inn.open("contact.txt");
		ofstream oww;
		oww.open("record.txt");

		inn >> s.name;
		inn >> s.mob;

		while (!inn.eof())
		{
			if (s.name != nam)
			{
				oww << endl;
				oww << s.name;
				oww << endl;
				oww << s.mob;
				oww << endl;
			}
			else
			{
				cout << "\t\t\t\tRECORD DELETED" << endl;
			}
			inn >> s.name;
			inn >> s.mob;
		}
		oww.close();
		inn.close();

		if (remove("contact.txt") != 0)
		{
			cout << "\t\t\t\tFILE DOES NOT REMOVE" << endl;
		}

		if (rename("record.txt", "contact.txt") != 0)
		{
			cout << "\t\t\t\tFILE DOES NOT RENAME" << endl;
		}
		cout << "\t\t\t\t";
		system("pause");
		system("cls");
		goto loop;
		break;
	}

	case '5':
	{
		system("cls");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		char find_name[20];
		cout << "\t\t\t\t=========================" << endl;
		cout << "\t\t\t\tENTER THE NAME YOU WANT TO CONTACT :" << endl;
		cout << "\t\t\t\t";
		cin >> find_name;
		if (strcmp(find_name, s.name) == 0)
		{
			cout << "\t\t\t\tNAME :" << s.name << endl;
			cout << "\t\t\t\tMOBILE NO:" << s.mob << endl;
		}

		cout << "\t\t\t\t";
		system("pause");
		system("cls");
		goto loop;
		break;
	}

	case '6':
		system("cls");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "\t\t\t\t=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n";
		cout << "\t\t\t\t    Thankyou For Using  Rathi Contactopedia  \n";
		cout << "\t\t\t\t=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n";
		exit(0);
		break;

	default:
		cout << endl;
		cout << "\t\t\t\tOOps YOU GOT IT WRONG!!!\n";
		cout << "\t\t\t\tTRY AGAIN LATER";
		exit(0);
		break;
	}
	getch();
}
