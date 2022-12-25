#include <iostream>
#include<string>
#include<iomanip>
#include <conio.h>
#include <fstream>
using namespace std;

struct Cars
{
	string mark[10] = { "Hyundai  ----> cheap","Ford     ----> cheap","Suzuki   ----> cheap","Audi     ----> cheap","Tesla   ----> Expensive","Lexus    ----> Expensive","Mercedes ----> Expensive","Toyota    ----> Expensive","BMW       ----> Expensive" };

	string carpricetype[10] = { "cheap","cheap","cheap","cheap","Expensive","Expensive","Expensive","Expensive","Expensive" };

	string model[10] = { "BR-V","ECO-SPORT","SWIFT","A6-SERIES","MODEL-S","RX 400","BENZ-S","VIGO","X3-SERIES" };

	string color[10] = { "Red","black","yellow","Blue","Red","Brown","Silver","Black","grey" };

	string seats[10] = { "4 Seats","2 Seats","4 Seats","2 Seats","4 Seats","4 Seats","2 Seats","4 Seats","2 Seats" };

	string maxs_peed[10] = { "100 Km/h ","150 Km/h","150 Km/h","170 Km/h","130 Km/h","140 Km/h","130 Km/h","120 Km/h","150 Km/h" };

	int advanceamount[10] = { 150,200,250,300,350,400,450,500,520 };

	int prday_rent[10] = { 50,80,110,140,170,200,230,260,290 };



};


struct person
{
	string Name[10];
	string Natio_ID[10];
	int pay_acc[10], Rental_Amount[10], Rent_Days[10], totalfee[10];
};

//Declaring struct
Cars car;
person Detail;

//First output
void Manu()
{
	int num = 1;
	for (int i = 0; i < 9; ++i)
	{
		cout << "\t\t\t";
		cout << "Enter " << num << "\t- To Select  " << car.mark[i] << endl;
		num++;
	}
}

//Second output
void Details(int theChoice)
{
	system("CLS");
	cout << "\n\n\n\t\t\t-----------------------------\n";
	cout << "\t\t\tYou Have Selected - " << car.mark[theChoice - 1] << endl;
	cout << "\t\t\t-----------------------------\n\n\n";
	cout << "\t\t\tModel : " << car.model[theChoice - 1] << endl;
	cout << "\t\t\tColor : " << car.color[theChoice - 1] << endl;
	cout << "\t\t\tCar Seats : " << car.seats[theChoice - 1] << endl;
	cout << "\t\t\tMaximum Speed : " << car.maxs_peed[theChoice - 1] << endl;
	cout << "\t\t\tadvance amount : " << car.advanceamount[theChoice - 1] << "K" << endl;

}
//check lessee credit

void check(int j)

{
	if (Detail.pay_acc[j] >= car.advanceamount[j])
	{
		system("CLS");
		cout << "\n\n\n\t\t\tProcess has been done successfully!! " << endl;
		cout << "\n\t\t                       Car Rental - Customer Invoice                  " << endl;
		cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
		cout << "\t\t	| Invoice No. :" << "------------------|" << setw(15) << "#Cnb81353" << "  |" << endl;
		cout << "\t\t	| Car Model:" << "---------------------|" << setw(15) << Detail.Name[j] << "  |" << endl;
		cout << "\t\t	| Customer Name:" << "-----------------|" << setw(15) << Detail.Name[j] << "  |" << endl;
		cout << "\t\t	| Customer National ID : " << "--------|" << setw(15) << Detail.Natio_ID[j] << "  |" << endl;
		cout << "\t\t	| Advance Amount    :" << "------------|" << setw(15) << Detail.pay_acc[j] << "  | " << endl;
		cout << "\t\t	| Rental Amount :" << "----------------|" << setw(15) << Detail.Rent_Days[j] << "  |" << endl;
		cout << "\t\t	| miscellaneous charges :" << "--------|" << setw(15) << "0" << "  |" << endl;
		cout << "\t\t	 ________________________________________________________" << endl;
		cout << "\n";
		cout << "\t\t	| Total Rental Amount is :" << "-------|" << setw(15) << Detail.totalfee[j] << "  |" << endl;
		cout << "\t\t	 ________________________________________________________" << endl;
		cout << "\t\t	 # This is a computer generated invoice and it does not" << endl;
		cout << "\t\t	 require an authorised signture #" << endl;
		cout << " " << endl;
		cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
		cout << "\t\t	You are advised to pay up the amount before due date." << endl;
		cout << "\t\t	Otherwise penelty fee will be applied" << endl;
		cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
		fstream new_file;
		new_file.open("Details.txt", ios::out);
		if (!new_file)
		{
			cout << "File creation failed";
		}
		else
		{
			cout << "New file created";
			new_file << "Name : " << Detail.Name[j] << endl << "CNIC : " << Detail.Natio_ID[j] << endl << "Advance Amout : " << Detail.pay_acc[j] << endl << "Rent : " << Detail.Rent_Days[j] << endl << "Total Fee : " << Detail.totalfee[j] << endl;  //Writing to file
			new_file.close();
		}
	}

	else
		cout << "\n\n\n\t\t\tNot Available " << endl;

}
//User Inputcpo
void user_input(int theChoice)
{
	system("CLS");
	int j = theChoice - 1;
	cout << "\t\t\t----------------------------------------\n";
	cout << "\t\t\tPlease Provide Your Personal Details  : \n";
	cout << "\t\t\t----------------------------------------\n\n";
	cout << "\n\tNOTE: PROVIDE FIRST NAME ONLY, DONOT ENTER SPACE WHILE PROVIDING NAME,\n\tPAYMENT WON'T PROCEED IF THE GIVEN AMOUNT IS LESS THEN THE ADVANCE OF CAR\n\n\n\n";
	cout << "\t\t\tEnter Your Name : ";
	cin >> Detail.Name[j];
	cout << "\t\t\tEnter Your National ID : ";
	cin >> Detail.Natio_ID[j];
	cout << "\t\t\tAdvance Amount: ";
	cin >> Detail.pay_acc[j];  //this will be advance 
	cout << "\t\t\tHow many days you want to rent this car: ";
	cin >> Detail.Rent_Days[j];
	Detail.Rent_Days[j] = Detail.Rent_Days[j] * car.prday_rent[theChoice - 1];

	Detail.totalfee[j] = Detail.Rent_Days[j] + Detail.pay_acc[j];

	check(j);
}

//cpo
int login()
{
	string pass = "";
	char ch;
	cout << "\n\n\n\n\n\n\n\t\t\t\t\t  Simple Car Rental System Login";
	cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
	ch = _getch();
	while (ch != 13)
	{//character 13 is enter
		pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	if (pass == "pass")
	{
		cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
		system("PAUSE");
		system("CLS");

	}
	else
	{
		cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
		system("PAUSE");
		system("CLS");
		return login();
	}
}

int main()
{
	int login();
	login();

	string decide = "yes";
	cout << "\t\t\t----------------------------------------------\n";
	cout << "\t\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
	cout << "\t\t\tWelcome to Our Company ,Choose from the menu : " << endl;
	cout << "\t\t\t----------------------------------------------\n";
	while (decide != "exit")
	{
		Manu();
		cout << "\n\n\n\t\t\tYour Choice: ";
		int theChoice;
		cin >> theChoice;
		Details(theChoice);
		cout << "\n\n\n\t\t\tAre You Sure, you want to rent this Car? (yes /no /exit ) : ";
		cin >> decide;
		if (decide == "yes")
		{
			user_input(theChoice);
			cout << "\n\n\t\t\tDo you want to continue ?(yes/no) ";
			cin >> decide;
			if (decide == "no")
				break;
			system("CLS");
		}

		else
		{
			if (decide == "no")
			{
				system("CLS");
				continue;
			}
			else if (decide == "exit")
			{
				system("CLS");
				cout << "\n\n\n\t\t\t";
				break;
			}

		}
	}

	return 0;
}