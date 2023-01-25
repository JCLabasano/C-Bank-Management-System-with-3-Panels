
#include<fstream> /*This data type represents the file stream generally, 
					and has the capabilities of both ofstream and ifstream which means it can create files,
					write information to files, and read information from files.*/
#include<iomanip>  //helps us in manipulating the output of any C++ program
#include<cctype> //header file declares a set of functions to classify (and transform) individual characters
#include<cstdlib>//This header defines a collection of functions and macros to facilitate efficient, high-performing, standardized C++ code across teams and platforms.
#include<string> 
#include<time.h> //C Time Library. This header file contains definitions of functions to get and manipulate date and time information.
#include<conio.h>//The word conio. h stands for console input-output and in programming, console means output window which is the window where the result of the execution of our program is displayed
#include<iostream> /**/
using namespace std;

class Bank_management_system
{

private:

	char Fname[100], Add[100];
	char Acctype, gen;
	int amt, totalbill;
	long long Nnum, pin, CN;
	long long Accnum;

public:

	void Create_acc(); //function Get data from the user
	void Update_info();   //function Modify record of user
	void deposit_cash();  //function to deposite amount 
	void withdraw_am();// function to withdraw amount
	char conacctype();  //function to return acctype
	int Nidnum();   //function to return Natinal ID number
	void withdrawAmount(); //withdraw amount
	int Bill();        //function to return total cash
	void deposit(int);  //function to deposite amount 
	void deleted_acc(int);    //function delete record of user
	void Show_sp_rec() const; //show account information of specific account holder
	void display_all() const; //show all Bank account holder information
	int accnum() const;  //function to return account number
	int pinn() const;
  //class ends
};

void Bank_management_system::Create_acc()
{
	system("cls");
	srand(time(0));   /*gives the random function a new seed, a starting point(usually random
					  numbers are calculated by taking the previous number(or the seed) and then do many operations on that number to generate the next).
						*/
	cout << "\n\n";
	cout << "\t\t\t\t\t*****************************************" << endl;
	cout << "\t\t\t\t\t*                                       *" << endl;
	cout << "\t\t\t\t\t*             CREATE ACCOUNT            *" << endl;
	cout << "\t\t\t\t\t*                                       *" << endl;
	cout << "\t\t\t\t\t*****************************************" << endl;
	cout << "\n\n";
	cout << "\t\t\tEnter Your Full name: ";
	cin.ignore();                          //ignore or clear one line
	cin.getline(Fname, 30);                        // So you can use spaces when you input a string
	cout << "\n";
	cout << "\t\t\tEnter Your National ID Number: ";
	cin >> Nnum;
	cout << "\n";
	cout << "\t\t\tEnter Your Gender ( M - male / F - female ): ";
	cin >> gen;
	cout << "\n";
	cout << "\t\t\tEnter Your Address: ";
	cin.ignore();
	cin.getline(Add, 50);
	cout << "\n";
	cout << "\t\t\tEnter Your Contact Number: ";
	cin >> CN;
	cout << "\n";
	cout << "\t\t\tChoose Your Account Type Savings/Current (S / C): ";
	cin >> Acctype;
	Acctype = toupper(Acctype);  // convert letter to upper
	if (Acctype == 'S' || Acctype == 's') {          // condition if user input (S/C) it will display savings or current.
		cout << "\n";
		cout << "\t\t\tYOU CHOOSE SAVINGS!" << endl;
		cout << "\n";
		cout << "\t\t\tMinimum Balance (500): ";
		cin >> amt;
		do {                              //loops until the stated condition becomes false
			if (amt < 500) {
				cout << "\n";
				cout << "\t\t\tInvalid Amount!!" << endl;
				cout << "\n";
				cout << "\t\t\tEnter Amount Again: ";
				cin >> amt;
			}
		} while (amt < 500);
	}
	else {
		cout << "\n";
		cout << "\t\t\tYOU CHOOSE CURRENT!" << endl;
		cout << "\n";
		cout << "\t\t\tMinimum Balance (1000): ";
		cin >> amt;
		do {
			if (amt < 1000) {
				cout << "\n";
				cout << "\t\t\tInvalid Amount!!" << endl;
				cout << "\n";
				cout << "\t\t\tEnter Amount Again: ";
				cin >> amt;
			}

		} while (amt < 1000);
	}
	cout << "\n";
	cout << "\t\t\tEnter Your Pin Number: ";
	cin >> pin;
	Accnum = rand() % 1000; // generate random value ranges 1 - 1000
	cout << "\n";
	cout << "\t\t\tAccount Number: " << Accnum << endl;
	cout << "\n";
	cout << "\t\t\tSuccessfuly Created Account!" << endl;
	cout << "\n";
	cout << "\t\t\tPress Enter To Return In Main Menu.";
	cin.get();

}

void Bank_management_system::Show_sp_rec()const//show one record
{
	system("cls");
	cout << "\n\n";
	cout << "\t\t\t\t********************************************************************" << endl;
	cout << "\t\t\t\t********************************************************************" << endl;
	cout << "\t\t\t\t*                 BANK HOLDER ACCOUNT INFORMATION                  *" << endl;
	cout << "\t\t\t\t********************************************************************" << endl;
	cout << "\t\t\t\t********************************************************************" << endl;
	cout << "\n";
	cout << "\t\t\t\tBank account holder name: " << Fname << endl;
	cout << "\n";
	cout << "\t\t\t\tNational ID number: " << Nnum << endl;
	cout << "\n";
	cout << "\t\t\t\tGender: " << gen << endl;
	cout << "\n";
	cout << "\t\t\t\tAdress: " << Add << endl;
	cout << "\n";
	cout << "\t\t\t\tContact number: " << CN << endl;
	cout << "\n";
	cout << "\t\t\t\tAccount type (S-savings / C-current): " << Acctype << endl;
	cout << "\n";
	cout << "\t\t\t\tBalance: " << amt << endl;
	cout << "\n";
	cout << "\t\t\t\tPin number: " << pin << endl;
	cout << "\n";
	cout << "\t\t\t\tAccount number:" << Accnum << endl;

	cin.get();
}

void Bank_management_system::Update_info() //update  information
{
	cout << "\n\n";
	cout << "\t\t\t*******************************************************************************************" << endl;
	cout << "\t\t\t*******************************************************************************************" << endl;
	cout << "\t\t\t*                           PREVIOUS INFORMATION OF BANK HOLDER                           *" << endl;
	cout << "\t\t\t*******************************************************************************************" << endl;
	cout << "\t\t\t*******************************************************************************************" << endl;
	cout << "\n";
	cout << "\t\t\tBank account holder name: " << Fname << endl;
	cout << "\n";
	cout << "\t\t\tNational ID number: " << Nnum << endl;
	cout << "\n";
	cout << "\t\t\tGender: " << gen << endl;
	cout << "\n";
	cout << "\t\t\tAdress: " << Add << endl;
	cout << "\n";
	cout << "\t\t\tContact number: " << CN << endl;
	cout << "\n";
	cout << "\t\t\tAccount type (S-savings / C-current): " << Acctype << endl;
	cout << "\n";
	cout << "\t\t\tBalance: " << amt << endl;
	cout << "\n";
	cout << "\t\t\tPin number: " << pin << endl;
	cout << "\n";
	cout << "\t\t\tAccount number:" << Accnum << endl;
	cin.get();
	cout << "\n\n\n";
	cout << "\t\t\tEnter your Full name: ";
	cin.ignore();
	cin.getline(Fname, 50);
	cout << "\t\t\tEnter your National ID number: ";
	cin >> Nnum;
	cout << "\t\t\tEnter your gender (M/F): ";
	cin >> gen;
	gen = toupper(gen);
	cout << "\t\t\tEnter your address: ";
	cin.ignore();
	cin.getline(Add, 50);
	cout << "\t\t\tEnter your contact number: ";
	cin >> CN;
	cout << "\t\t\tEnter your Account type: ";
	cin.ignore();
	cin >> Acctype;
	cout << "\t\t\tEnter your balance: ";
	cin >> amt;
	Acctype = toupper(Acctype);
	cout << "\t\t\tEnter your pin number: ";
	cin >> pin;
}

int Bank_management_system::accnum() const
{
	return Accnum;
}
int Bank_management_system::pinn() const
{
	return pin;
}
char Bank_management_system::conacctype()
{
	return Acctype;
}

int Bank_management_system::Nidnum()
{
	return Nnum;
}
int Bank_management_system::Bill()
{
	return totalbill;
}




void writefile();
void showinfo(int);
void modify_acc(int);
void all_info();
void withraw_dep();
void transLogs();
void All_deleted_logs();

void AdminPanel()
{
	char ch;
	Bank_management_system a;
	int wnum;
	do
	{
		system("cls");
		cout << "\n\n";
		cout << "\t\t\t\t************************************************************" << endl;
		cout << "\t\t\t\t************************************************************" << endl;
		cout << "\t\t\t\t**                                                        **" << endl;
		cout << "\t\t\t\t**                       ADMIN PANEL                      **" << endl;
		cout << "\t\t\t\t**                                                        **" << endl;
		cout << "\t\t\t\t************************************************************" << endl;
		cout << "\t\t\t\t************************************************************" << endl;
		cout << "\n\n";
		cout << "\t\t\t\t\t\t1. Create Account: " << endl;
		cout << "\n";
		cout << "\t\t\t\t\t\t2. Delete Account: " << endl;
		cout << "\n";
		cout << "\t\t\t\t\t\t3. Search Account: " << endl;
		cout << "\n";
		cout << "\t\t\t\t\t\t4. Show List Of All Accounts: " << endl;
		cout << "\n";
		cout << "\t\t\t\t\t\t5. Edit Account Information: " << endl;
		cout << "\n";
		cout << "\t\t\t\t\t\t6. Show Logs Of Deleted Account: " << endl;
		cout << "\n";
		cout << "\t\t\t\t\t\t7. To Main Menu: " << endl;
		cout << "\n";
		cout << "\t\t\t\t\t\tSelect Transaction: ";
		cin >> ch;
		switch (ch)
		{
		case '1':
			writefile();
			break;
		case '2':
			a.deleted_acc(wnum);
			cin.get();
			break;
		case '3':
			system("cls");
			cout << "\n";
			cout << "\t\t\tEnter account number: ";
			cin >> wnum;
			showinfo(wnum);
			break;
		case '4':
			all_info();
			cin.get();
			break;
		case '5':
			modify_acc(wnum);
			cin.get();
			break;
		case '6':
			All_deleted_logs();
			break;
		case '7':
			system("cls");
			break;
		default:
			cout << "Invalid Input";
		}
		cin.get();
	} while (ch != '7');
}
void deposit()
{
	system("cls");
	Bank_management_system a;
	int wnum;
	int wnum1;
	cout << "\n\n";
	cout << "\t\t\tEnter your account number: ";
	cin >> wnum;
	cout << "\n\n";

	fstream FileIn;
	fstream usFile;

	usFile.open("file.txt", ios::app);
	if (usFile.is_open())
	{
		cout << "\n\n";
		usFile << "\t\t\tBank holder account number: " << wnum << endl;
		cout << "\n\n";
	}
	usFile.close();
	FileIn.open("out.txt", ios::binary | ios::out | ios::in);    /* makes sure the data is read or written without translating new line characters to
	and from \r\n on the fly. In other words, exactly what you give the stream is exactly what's written.
																	 ios out opens the file for writing.*/
	while (!FileIn.eof())
	{
		if (FileIn.read(reinterpret_cast<char*>(&a), sizeof(Bank_management_system)))
		{
			if (wnum == a.accnum())
			{
				cout << "\t\t\tEnter your pin number: ";
				cin >> wnum1;
				if (wnum1 == a.pinn()) {

					a.deposit_cash();

					int pos = -1 * static_cast<int>(sizeof(Bank_management_system));
					FileIn.seekp(pos, ios::cur);
					FileIn.write(reinterpret_cast<char*>(&a), sizeof(Bank_management_system));
					return;
				}
				else {
					cout << "\n\n";
					cout << "\t\t\tInvalid pin number!" << endl;
				}
			}
		}
	}
	if (wnum != a.accnum())
	{
		cout << "\n\n";
		cout << "\t\t\tInvalid account number";
		cout << "\n";
	}
	cout << "\t\t\tPress enter to return...";
	cin.get();
	FileIn.close();
}
void Bank_management_system::withdrawAmount()
{
	system("cls");
	int wnum;
	int wnum1;
	time_t ct = time(0);
	string ctimenow = ctime(&ct);
	Bank_management_system a;
	cout << "\n\n";
	cout << "\t\t\tBank holder account number: ";
	cin >> wnum;

	fstream FileIn;
	fstream usFile;
	usFile.open("file.txt", ios::app);
	if (usFile.is_open())
	{
		cout << "\n\n";
		usFile << "\t\t\tBank holder account number: " << wnum << endl;
	}
	usFile.close();
	FileIn.open("out.txt", ios::binary | ios::out | ios::in);
	while (!FileIn.eof())
	{
		if (FileIn.read(reinterpret_cast<char*>(&a), sizeof(Bank_management_system)))
		{
			if (wnum == a.accnum())
			{
				cout << "\t\t\tEnter your pin number: ";
				cin >> wnum1;
				if (wnum1 == a.pin)
				{
					a.withdraw_am();

					int pos = -1 * static_cast<int>(sizeof(Bank_management_system));
					FileIn.seekp(pos, ios::cur);
					FileIn.write(reinterpret_cast<char*>(&a), sizeof(Bank_management_system));
					return;
				}
				else
				{
					cout << "\n\n";
					cout << "\t\t\t Invalid pin number" << endl;
					cout << "\n\n";
				}

			}
		}

	}

	if (wnum != a.accnum())
	{
		cout << "\n\n";
		cout << "\t\t\tInvalid Account number" << endl;
		cout << "\n\n";
	}
	cout << "\n\n";
	cout << "\t\t\tpress enter to to return";
	cin.get();
	FileIn.close();
}

void Bank_management_system::withdraw_am() //Withdraw cash calculates balance and amount to be withdrawn
{
	time_t ct = time(0);
	string ctimenow = ctime(&ct); //generates current time
	fstream usFile;
	int totalbill;
	cout << "\n\n";
	cout << "\t\t\tEnter Desired amount: ";
	cin >> totalbill;
	if (amt < totalbill)
	{
		cout << "\n";
		cout << "\t\t\tInsufficient Balance" << endl;
		cout << "\n";
		cout << "\t\t\tpress enter to return" << endl;
		cin.get();
	}
	else
	{
		amt -= totalbill;
		cout << "\n\n";
		cout << "\t\t\tWithdraw Successfull!" << endl;
		cout << "\n\n";
		cout << "\t\t\tTotal Balance: " << amt << endl;
		cout << "\n\n";
		cout << "press enter to return" << endl;
		cin.get();
	}
	usFile.open("file.txt", ios::app); //for transaction logs
	if (usFile.is_open())
	{ 

		usFile << "\t\t\tWithdraw Amount: " << totalbill << " -------------------- " << ctimenow << endl;

	}
	usFile.close();

}

void Bank_management_system::display_all() const

/*DISPLAY ALL ACCOUNTS CREATED BY USER*/
{
	cout << "\n\n";
	cout << " " << Fname << setw(19) << Nnum << setw(19) << gen << setw(14) << "   " << Add << setw(26) << CN << setw(15) << Acctype << setw(16) << amt << setw(14) << pin << setw(13) << Accnum << setw(10) << endl;
}

void Bank_management_system::deposit_cash() //deposit
{
	time_t ct = time(0);
	string ctimenow = ctime(&ct);
	int totalbill;
	fstream usFile;
	cout << "\n";
	cout << "\t\t\tEnter the amount to deposit : ";
	cin >> totalbill;
	amt += totalbill;
	cout << "\n\n";
	cout << "\t\t\tTotal Balance: " << amt << endl;
	cout << "\n\n" << endl;
	cout << "\t\t\tpress enter to return" << endl;
	cin.get();

	usFile.open("file.txt", ios::app); //for transaction logs
	if (usFile.is_open())
	{
		cout << "\n\n";
		usFile << "\t\t\tDeposit Amount: " << totalbill << " -------------------- " << ctimenow << endl; //display deposit amount in total and current time
		usFile << "\n";

	}
	usFile.close();

}


void writefile() //Function to write in file
{
	Bank_management_system a;
	ofstream FileIn;
	FileIn.open("out.txt", ios::binary | ios::app);
	a.Create_acc();
	FileIn.write(reinterpret_cast<char*>(&a), sizeof(Bank_management_system));
	FileIn.close();
}


void showinfo(int wnum)  //function to read specific record from file
{
	Bank_management_system a;
	bool var = false;
	ifstream Filein1;
	Filein1.open("out.txt", ios::binary);
	if (!Filein1)
	{
		cout << "\n\n";
		cout << "\t\t\tAccount not found!" << endl;
		return;
	}
	while (Filein1.read(reinterpret_cast<char*>(&a), sizeof(Bank_management_system)))
	{
		if (a.accnum() == wnum)
		{
			a.Show_sp_rec();
			var = true;
		}
	}
	Filein1.close();
	if (var == false)
		cout << "\t\t\tAccount number does not exist";
	
		cout << "\n\n";
	    cout << "\n";
	    cout << "\t\t\tPress enter to return";
}


void Bank_management_system::deleted_acc(int wnum)  // Remove account of bank holder 
{
	Bank_management_system a;
	ofstream File_op1;
	ifstream File_op;
	ofstream Unique;
	long long var1;
	File_op.open("out.txt", ios::binary);
	File_op1.open("doc.txt", ios::binary);

	system("cls");
	cout << "\n\n";
	cout << "\t\t\tEnter your Account number: ";
	cin >> var1;

	while (!File_op.eof())
	{
		if (File_op.read(reinterpret_cast<char*>(&a), sizeof(Bank_management_system)))
		{
			if (var1 != a.Accnum)
			{
				File_op1.write(reinterpret_cast<char*>(&a), sizeof(Bank_management_system));
			}
			else
			{
				Unique.open("remove.dat", ios::app);
				if (Unique.is_open())
				{
					Unique << "*\n";
					Unique << "*\t\t\t\tFull name : " << a.Fname << endl;
					Unique << "*\t\t\t\tNational ID number: " << a.Nnum << endl;
					Unique << "*\t\t\t\tGender: " << a.gen << endl;
					Unique << "*\t\t\t\tAddress: " << a.Add << endl;
					Unique << "*\t\t\t\tContact Number: " << a.CN << endl;
					Unique << "*\t\t\t\tAccount type: " << a.Acctype << endl;
					Unique << "*\t\t\t\tBalance: " << a.amt << endl;
					Unique << "*\t\t\t\tPin: " << a.pin << endl;
					Unique << "*\t\t\t\tAccount number:" << a.Accnum << endl;
					Unique << "*\n";

					Unique << "*************************************************************************************************************************" << endl;

				}
				cout << "\n\n";
				cout << "\t\t\tDeleted account Successfully!" << endl;
			}
		}
	}
	if (var1 != a.Accnum)
	{
		cout << "\n\n";
		cout << "\t\t\tAccount not found";
	}
	File_op.close();
	File_op1.close();
	Unique.close();
	remove("out.txt");
	rename("doc.txt", "out.txt"); return;
}

void All_deleted_logs()
{
	/*DELETED ACCOUNTS LOGS OF ALL BANK ACCOUNT HOLDER*/
	system("cls");
	fstream usFile;
	cout << "\n\n";
	cout << "\t\t\t*********************************************************************" << endl;
	cout << "\t\t\t*********************************************************************" << endl;
	cout << "\t\t\t*                ALL BANK HOLDER'S DELETED ACCOUNTS                 *" << endl;
	cout << "\t\t\t*********************************************************************" << endl;
	cout << "\t\t\t*********************************************************************" << endl;
	cout << "\n\n";
	usFile.open("remove.dat", ios::in);
	if (usFile.is_open())
	{
		string var3;
		while (getline(usFile, var3))
		{
			cout << var3 << endl;
		}
	}usFile.close();
	cout << "\n\n";
	cout << "\t\t\tPress Enter to return";
	cin.get();
}
void Ch2StaffPanel()
{
	Bank_management_system a;
	int ch;
	int wnum;
	do
	{
		system("cls");
		cout << "\n\n";
		cout << "\t\t\t\t*******************************" << endl;
		cout << "\t\t\t\t*******************************" << endl;
		cout << "\t\t\t\t**                           **" << endl;
		cout << "\t\t\t\t**         STAFF PANEL       **" << endl;
		cout << "\t\t\t\t**                           **" << endl;
		cout << "\t\t\t\t*******************************" << endl;
		cout << "\t\t\t\t*******************************" << endl;
		cout << "\n\n";
		cout << "\t\t\t\t1. Check Account Info" << endl;
		cout << "\n";
		cout << "\t\t\t\t2. Deposit Cash" << endl;
		cout << "\n";
		cout << "\t\t\t\t3. Widthraw Cash" << endl;
		cout << "\n";
		cout << "\t\t\t\t4. Check Logs Of User Account Transactions" << endl;
		cout << "\n";
		cout << "\t\t\t\t5. To Main Menu" << endl;
		cout << "\n";
		cout << "\t\t\t\tSelect Transaction: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			system("cls");
			cout << "\t\t\t\tEnter account number: ";
			cin >> wnum;
			showinfo(wnum);
			cin.get();
			break;
		case 2:
			deposit();
			cin.get();
			break;
		case 3:
			a.withdrawAmount();
			cin.get();
			break;
		case 4:
			transLogs();
			cin.get();
			break;
		case 5:
			cout << " ";
			break;
		default:
			cout << "\t\t\tInvalid Input" << endl;
		}

	} while (ch != 5);


}
void all_info()
{
	system("cls");
	Bank_management_system a;
	ifstream Filein1;
	Filein1.open("out.txt", ios::binary);
	if (!Filein1)
	{

		cout << "\t\t\tAccount not found" << endl;
		return;
	}
	cout << "\t\t\t\t\t\t*************************************************" << endl;
	cout << "\t\t\t\t\t\t*                                               *" << endl;
	cout << "\t\t\t\t\t\t*               LIST OF ALL ACCOUNTS            *" << endl;
	cout << "\t\t\t\t\t\t*                                               *" << endl;
	cout << "\t\t\t\t\t\t*************************************************" << endl;
	cout << "\n\n";
	cout << "****************************************************************************************************************************************************************************" << endl;
	cout << "|                   *                          *             *                                        *                 *             *           *         *              *" << endl;
	cout << "   FULL NAME" << "        *     " << "NATIONAL ID NUMBER" << "   *   " << "GENDER" << "    *                  " << "ADDRESS" << "               *  " << "CONTACT NUMBER" << " * " << "ACCOUNT TYPE" << "*  " << "BALANCE" << "  * " << "PIN NUM" << " *  " << "ACCOUNT NUM" << " *" << endl;
	cout << "|                   *                          *             *                                        *                 *             *           *         *              *" << endl;
	cout << "****************************************************************************************************************************************************************************" << endl;
	while (Filein1.read(reinterpret_cast<char*>(&a), sizeof(Bank_management_system)))
	{
		a.display_all();
	}
	Filein1.close();
	cout << "\n\n\n";
	cout << "\t\t\tpress enter to return";
}


void modify_acc(int)    //Update information of bank accpunt holder
{
	system("cls");
	Bank_management_system a;
	int wnum;
	fstream FileIn;
	cout << "\n\n";
	cout << "\t\t\tEnter your account number: ";
	cin >> wnum;

	FileIn.open("out.txt", ios::binary | ios::out | ios::in);
	while (!FileIn.eof())
	{
		if (FileIn.read(reinterpret_cast<char*>(&a), sizeof(Bank_management_system)))
		{
			if (wnum == a.accnum())
			{
				a.Update_info();

				int bin = -1 * static_cast<int>(sizeof(Bank_management_system));
				FileIn.seekp(bin, ios::cur);
				FileIn.write(reinterpret_cast<char*>(&a), sizeof(Bank_management_system));
				cout << "\t\t\tSuccessfully updated information";
				return;
			}
		}

	}

	cout << "\n\n";
	cout << "\t\t\tAccount holder not found!" << endl;
	FileIn.close();
}

void AtmPanel()
{
	Bank_management_system a;
	int ch;
	do
	{
		system("cls");
		cout << "\n\n";
		cout << "\t\t\t\t************************" << endl;
		cout << "\t\t\t\t************************" << endl;
		cout << "\t\t\t\t\tATM SERVICE" << endl;
		cout << "\t\t\t\t************************" << endl;
		cout << "\t\t\t\t************************" << endl;
		cout << "\t\t\t\t1. Withdraw Cash" << endl;
		cout << "\n";
		cout << "\t\t\t\t2. Back To Main Menu" << endl;
		cout << "\n";
		cout << "\t\t\t\tSelect transaction: ";
		cin >> ch;
		switch (ch) {

		case 1:
			a.withdrawAmount();
			cin.get();
			break;

		default:
			cout << "\t\t\tInvalid Input!" << endl;

		}
	} while (ch != 2);
}

void transLogs()   //Funtion of transaction logs
{
	system("cls");
	fstream usFile;
	usFile.open("file.txt", ios::in);
	if (usFile.is_open())
	{
		cout << "\t\t\t\t\t*****************************" << endl;
		cout << "\t\t\t\t\t*                           *" << endl;
		cout << "\t\t\t\t\t*      transaction logs     *" << endl;
		cout << "\t\t\t\t\t*                           *" << endl;
		cout << "\t\t\t\t\t*****************************" << endl;
		string var3;
		while (getline(usFile, var3))
		{
			cout << "\n\n";
			cout << var3 << endl;
		}
	}
	else {
		cout << "\n\n";
		cout << "\t\t\tNo transaction records" << endl;
	}
		usFile.close();
	cout << "\n\n";
	cout << "\t\t\tPress Enter to return";
	cin.get();
}

int main()
{
	char ch;

	do
	{
		system("cls");
		system("color 30"); //change color of background to aqua
		cout << "\n";
		cout << "\t\t\t\t=================================================" << endl;
		cout << "\t\t\t\t\t|******BANK MANAGEMENT SYSTEM********|" << endl;
		cout << "\t\t\t\t=================================================" << endl;
		cout << "\t\t\t\t\tInformation Communication Technology" << endl;
		cout << "\t\t\t\t\tInstructor: Roselle Faye Haban" << endl;
		cout << "\n";
		cout << "\t\t\t\t\t      \3 \3 \3 \3 GROUP 4 \3 \3 \3 \3" << endl;
		cout << "\n\n";
		cout << "\t\t\t\t\t\t******************" << endl;
		cout << "\t\t\t\t\t\t*                *" << endl;
		cout << "\t\t\t\t\t\t*----MAIN MENU---*" << endl;
		cout << "\t\t\t\t\t\t*                *" << endl;
		cout << "\t\t\t\t\t\t******************" << endl;
		cout << "\n";
		cout << "\t\t\t\t\t\t  1.ADMIN PANEL" << endl;
		cout << "\n";
		cout << "\t\t\t\t\t\t  2.STAFF PANEL" << endl;
		cout << "\n";
		cout << "\t\t\t\t\t\t  3.ATM SERVICE" << endl;
		cout << "\n\n";
		cout << "\t\t\t\t\tSelect transaction: ";
		cin >> ch;
		switch (ch)
		{
		case '1':
			AdminPanel();
			break;
		case '2':
			Ch2StaffPanel();
			break;
		case '3':
			AtmPanel();
			break;
		default:
			cout << "\t\t\tInvalid Input!" << endl;
		}

	} while (ch != '4');
	return 0;


}

