#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>
using namespace std;
class Medicine{
	private:
		int medicine_num;
		char title[20];
		char manufacturer[20];
		char expiry[20]; 
		double price;
		int stock;
		char disease[20];
		
	public:
	
		void addmed(Medicine arr[]);
		void M_display();
		void displayt(Medicine a[]);
		void M_update();
		void M_del();
		void salemed();
};
class Person{
	private:
		char id[20];
		char fname[20];
		char lname[20];
		char city[20];
		char datejoin[20]; 
		int salary;
		char pnum[20]; 
		
	public:
		
		void addperson(Person arr[]);
		void P_display();
		void displayf(Person a[]);
		void displayl(Person a[]);
		void personc(Person a[]);
		void P_update();
		void P_del();
		
};


void Medicine :: addmed (Medicine arr[]){
	
	fstream data;
	data.open("MedicalStoreMedicine.txt",ios::in|ios::out|ios::app);
	int i;
	cout<<"Please enter at which number you want to add medicine: ";
	cin>>i;
	cin.ignore();
	

	
	if (i == 1){
		data<<"Sr. Number\tTitle\t\tManufacturer\tExpiry\t\tPrice\t\tStock\t\tDisease\n";
	}
		
	if (i>=50){
		cout<<"Space full.";
	}
	
	if (i<50){
		
		arr[i-1].medicine_num = i;
		cout<<"Please enter information of medicine.";
		cout<<"\nEnter Title of Medicine: ";
		gets(arr[i-1].title);
		cout<<"Enter Manufacturer: ";
		gets(arr[i-1].manufacturer);
		cout<<"Enter Expiry Date: ";
		gets(arr[i-1].expiry);
		cout<<"Enter Price: ";
		cin>>arr[i-1].price;
		cin.ignore();
		cout<<"Enter Stock: ";
		cin>>arr[i-1].stock;
		cin.ignore();
		cout<<"Enter Diseases: ";
		gets(arr[i-1].disease);
	}
	data<<arr[i-1].medicine_num<<"\t\t"<<arr[i-1].title<<"\t\t"<<arr[i-1].manufacturer<<"\t\t"<<arr[i-1].expiry<<"\t\t"<<arr[i-1].price<<"\t\t"<<arr[i-1].stock<<"\t\t"<<arr[i-1].disease<<endl;
	data.close();	
}

void Person :: addperson (Person arr[]){
	
	fstream data;
	data.open("MedicalStorePerson.txt",ios::in|ios::out|ios::app);
	int i;
	cout<<"Please enter at which number you want to add Person: ";
	cin>>i;
	cin.ignore();
	

	
	if (i == 1){
		data<<"ID\tFirst Name\tLast Name\tCity\t\tJoining Date\tSalary\t\tPersonal Number\n";
	}
		
	if (i>=50){
		cout<<"Space full.";
	}
	
	if (i<50){
		
		cout<<"Please enter information of Person.\n";
		cout<<"Enter ID: ";
		gets(arr[i-1].id);
		cout<<"\nEnter First Name: ";
		gets(arr[i-1].fname);
		cout<<"Enter Last Name: ";
		gets(arr[i-1].lname);
		cout<<"Enter City: ";
		gets(arr[i-1].city);
		cout<<"Enter Date of joining: ";
		gets(arr[i-1].datejoin);
		cout<<"Enter salary: ";
		cin>>arr[i-1].salary;
		cin.ignore();
		cout<<"Enter Personal Number: ";
		gets(arr[i-1].pnum);
	}
	data<<arr[i-1].id<<"\t"<<arr[i-1].fname<<"\t\t"<<arr[i-1].lname<<"\t\t"<<arr[i-1].city<<"\t\t"<<arr[i-1].datejoin<<"\t\t"<<arr[i-1].salary<<"\t\t"<<arr[i-1].pnum<<endl;
	data.close();	
}

void Medicine :: M_update (){
	
	fstream data, temp;
	data.open("MedicalStoreMedicine.txt", ios::in|ios::out|ios::app);
	temp.open("Temp.txt", ios::in|ios::out|ios::app);
	if (!data){
		cout<<"File not found\n";
	}
	if(!temp){
		cout<<"Temporary file not found.";
	}
	temp<<"Sr. Number\tTitle\t\tManufacturer\tExpiry\t\tPrice\t\tStock\t\tDisease\n";
	
	char title1[20], manu[20];
	cout<<"Enter name of medicine to be updated. ";
	cin.ignore();
	gets(title1);
	cout<<"Enter name of manufacturer. ";
	gets(manu);
	
	char title[20], manufacturer[20], expiry[20], disease[20];
	int medicine_num, price, stock;
	

	data.seekg(60,ios::beg);
	while (data>>medicine_num>>title>>manufacturer>>expiry>>price>>stock>>disease){
		if (strcmp(title,title1)==0 && strcmp(manufacturer, manu)==0){
			cout<<"Please enter information of medicine.";
			cout<<"\nEnter Title of Medicine: ";
			gets(title);
			cout<<"Enter Manufacturer: ";
			gets(manufacturer);
			cout<<"Enter Expiry Date: ";
			gets(expiry);
			cout<<"Enter Price: ";
			cin>>price;
			cin.ignore();
			cout<<"Enter Stock: ";
			cin>>stock;
			cin.ignore();
			cout<<"Enter Diseases: ";
			gets(disease);
			temp<<medicine_num<<"\t\t"<<title<<"\t\t"<<manufacturer<<"\t\t"<<expiry<<"\t\t"<<price<<"\t\t"<<stock<<"\t\t"<<disease<<endl;
		}
		else {
			temp<<medicine_num<<"\t\t"<<title<<"\t\t"<<manufacturer<<"\t\t"<<expiry<<"\t\t"<<price<<"\t\t"<<stock<<"\t\t"<<disease<<endl;
		}
	}
	temp.close();
	data.close();
	remove("MedicalStoreMedicine.txt");
	rename("Temp.txt", "MedicalStoreMedicine.txt");

}

void Person :: P_update (){
	
	fstream data, temp;
	data.open("MedicalStorePerson.txt", ios::in|ios::out|ios::app);
	temp.open("Temp.txt", ios::in|ios::out|ios::app);
	if (!data){
		cout<<"File not found\n";
	}
	if(!temp){
		cout<<"Temporary file not found.";
	}
	temp<<"ID\tFirst Name\tLast Name\tCity\t\tJoining Date\tSalary\t\tPersonal Number\n";
	
	char firstn[20], lastn[20];
	cout<<"Enter first name of the person to be updated.";
	cin.ignore();
	gets(firstn);
	cout<<"Enter last name of the person to be updated.";
	gets(lastn);
	
	char id[20], fname[20], lname[20], city[20], datejoin [20], pnum [20], sal[20];
	int salary;
	

	data.seekg(66,ios::beg);
	while (data>>id>>fname>>lname>>city>>datejoin>>salary>>pnum){
		if (strcmp(fname,firstn)==0 && strcmp(lname, lastn)==0){
			cout<<"Enter ID: ";
			gets(id);
			cout<<"\nEnter First Name: ";
			gets(fname);
			cout<<"Enter Last Name: ";
			gets(lname);
			cout<<"Enter City: ";
			gets(city);
			cout<<"Enter Date of joining: ";
			gets(datejoin);
			cout<<"Enter salary: ";
			cin>>salary;
			cin.ignore();
			cout<<"Enter Personal Number: ";
			gets(pnum);
			temp<<id<<"\t"<<fname<<"\t\t"<<lname<<"\t\t"<<city<<"\t\t"<<datejoin<<"\t\t"<<salary<<"\t\t"<<pnum<<endl;
		}
		else {
			temp<<id<<"\t"<<fname<<"\t\t"<<lname<<"\t\t"<<city<<"\t\t"<<datejoin<<"\t\t"<<salary<<"\t\t"<<pnum<<endl;
		}
	}
	temp.close();
	data.close();
	remove("MedicalStorePerson.txt");
	rename("Temp.txt", "MedicalStorePerson.txt");

}

////////////////////////////Ayesha///////////////////////////////
/////////////////////////////////////////////////////////////////

void Medicine::displayt(Medicine a[])
{
	fstream c("MedicalStoreMedicine.txt",ios::in);
	if(!c)
	{
		cout<<"File cannot open";
	}
	
	char b[20];
	cout<<"Enter the title of medicine you want to search: ";
	cin>>b;
	
	cout<<"Medicine#\tTitle\tManufacturer\tDate of Expiry\tPrice\tStock\tDiseases"<<endl;
	
	while(c>>medicine_num>>title>>manufacturer>>expiry>>price>>stock>>disease)
	{
		if(strcmp(b,title)==0)
		{
			cout<<medicine_num<<"\t"<<title<<"\t"<<manufacturer<<"\t"<<expiry<<"\t"<<price<<"\t"<<stock<<"\t"<<disease<<endl;
		}
	}
}
void Person::displayf(Person a[])
{
	fstream d("MedicalStorePerson.txt",ios::in);
	if(!d)
	{
		cout<<"File cannot open";
	}
	
	char c[20];
	cout<<"Enter the first name of the person you want to search"<<endl;
	cin>>c;
	
	cout<<"ID\tFirst Name\tLast Name\tCity\tDate of Joining\tSalary\tPh. No"<<endl;
	while(d>>fname>>lname>>city>>datejoin>>salary>>pnum)
	{
		if(strcmp(c,fname)==0)
		{
			cout<<id<<"\t"<<fname<<"\t"<<lname<<"\t"<<city<<"\t"<<datejoin<<"\t"<<salary<<"\t"<<pnum<<endl;
		}
	}
}
void Person::displayl(Person a[])
{
	fstream d("MedicalStorePerson.txt",ios::in);
	if(!d)
	{
		cout<<"File cannot open";
	}
	
	char c[20];
	cout<<"Enter the last name of the person you want to search"<<endl;
	cin>>c;
	
	cout<<"ID\tFirst Name\tLast Name\tCity\tDate of Joining\tSalary\tPh. No"<<endl;
	while(d>>fname>>lname>>city>>datejoin>>salary>>pnum)
	{
		if(strcmp(c,lname)==0)
		{
			cout<<id<<"\t"<<fname<<"\t"<<lname<<"\t"<<city<<"\t"<<datejoin<<"\t"<<salary<<"\t"<<pnum<<endl;
		}
	}	
}
void Person::personc(Person a[])
{
	fstream d("MedicalStorePerson.txt",ios::in);
	if(!d)
	{
		cout<<"File cannot open";
	}
	
	char c[20];
	cout<<"Enter the city of the person you want to search"<<endl;
	cin>>c;
	
	cout<<"ID\tFirst Name\tLast Name\tCity\tDate of Joining\tSalary\tPh. No"<<endl;
	while(d>>fname>>lname>>city>>datejoin>>salary>>pnum)
	{
		if(strcmp(c,city)==0)
		{
			cout<<id<<"\t"<<fname<<"\t"<<lname<<"\t"<<city<<"\t"<<datejoin<<"\t"<<salary<<"\t"<<pnum<<endl;
		}
	}		
}



void Medicine::M_display()
{
	fstream a("MedicalStoreMedicine.txt",ios::in);
	if(!a)
	{	
		cout<<"File cannot open";
	}
	
	cout<<"Medicine#\tTitle\tManufacturer\tDate of Expiry\tPrice\tStock\tDiseases"<<endl;
	while(a>>medicine_num>>title>>manufacturer>>expiry>>price>>stock>>disease)
		cout<<medicine_num<<"\t"<<title<<"\t"<<manufacturer<<"\t"<<expiry<<"\t"<<price<<"\t"<<stock<<"\t"<<disease<<endl;
}
void Person::P_display()
{
	fstream b("MedicalStorePerson.txt",ios::in);
	
	if(!b)
	{
		cout<<"File cannot open";
	}
	
	cout<<"ID\tFirst Name\tLast Name\tCity\tDate of Joining\tSalary\tPh. No"<<endl;
	while(b>>id>>fname>>lname>>city>>datejoin>>salary>>pnum)
		cout<<id<<"\t"<<fname<<"\t"<<lname<<"\t"<<city<<"\t"<<datejoin<<"\t"<<salary<<"\t"<<pnum<<endl;
}



void Medicine :: M_del (){
	fstream data, temp;
	data.open("MedicalStoreMedicine.txt", ios::in|ios::out|ios::app);
	temp.open("Temp.txt", ios::in|ios::out|ios::app);
	if (!data){
		cout<<"File not found\n";
	}
	if(!temp){
		cout<<"Temporary file not found.";
	}
	temp<<"Sr. Number\tTitle\t\tManufacturer\tExpiry\t\tPrice\t\tStock\t\tDisease\n";
	
	char title1[20], manu[20];
	cout<<"Enter name of medicine to be deleted. ";
	cin.ignore();
	gets(title1);
	cout<<"Enter name of manufacturer. ";
	gets(manu);
	
	char title[20], manufacturer[20], expiry[20], disease[20];
	int medicine_num, price, stock;
	

	data.seekg(60,ios::beg);
	while (data>>medicine_num>>title>>manufacturer>>expiry>>price>>stock>>disease){
		if (strcmp(title,title1)==0 && strcmp(manufacturer, manu)==0){
			continue;
		}
		else {
			temp<<medicine_num<<"\t\t"<<title<<"\t\t"<<manufacturer<<"\t\t"<<expiry<<"\t\t"<<price<<"\t\t"<<stock<<"\t\t"<<disease<<endl;
		}
	}
	temp.close();
	data.close();
	remove("MedicalStoreMedicine.txt");
	rename("Temp.txt", "MedicalStoreMedicine.txt");

}

void Person :: P_del (){
	fstream data, temp;
	data.open("MedicalStorePerson.txt", ios::in|ios::out|ios::app);
	temp.open("Temp.txt", ios::in|ios::out|ios::app);
	if (!data){
		cout<<"File not found\n";
	}
	if(!temp){
		cout<<"Temporary file not found.";
	}
	temp<<"ID\tFirst Name\tLast Name\tCity\t\tJoining Date\tSalary\t\tPersonal Number\n";
	
	char firstn[20], lastn[20];
	cout<<"Enter first name of the person to be deleted.";
	cin.ignore();
	gets(firstn);
	cout<<"Enter last name of the person to be deleted.";
	gets(lastn);
	
	char id[20], fname[20], lname[20], city[20], datejoin [20], pnum [20];
	int salary;

	data.seekg(66,ios::beg);
	while (data>>id>>fname>>lname>>city>>datejoin>>salary>>pnum){
		if (strcmp(fname,firstn)==0 && strcmp(lname, lastn)==0){
			continue;
		}
		else {
			temp<<id<<"\t"<<fname<<"\t\t"<<lname<<"\t\t"<<city<<"\t\t"<<datejoin<<"\t\t"<<salary<<"\t\t"<<pnum<<endl;
		}
	}
	temp.close();
	data.close();
	remove("MedicalStorePerson.txt");
	rename("Temp.txt", "MedicalStorePerson.txt");

}


int main(){
	
	Medicine *m, marr[50];
	Person *p, parr[50];
	
	int i, j;
	while (i != 6){
		system("cls");
		cout<<"*******\nMENU\n*********\n\n\n1.Add Record\n2.Display All\n3.Display with Options\n4.Update\n5.Delete Record\n6.Exit\n";
		cin>>i;
		if (i == 1){
			system("cls");
			cout<<"*****\nAdd Record.\n*****\n1.Medicine\n2.Person\n";
			while (j!=1 || j!=2){
				cin>>j;
				if (j == 1){
					m->addmed(marr);
					getch();
					break;
				}
				else if (j == 2) {
					p->addperson(parr);
					getch();
					break;
				}
				else {
					cout<<"INVALID, Try Again\n*****\nAdd Record.\n*****\n1.Medicine\n2.Person\n";
				}
			}
		}
		else if (i == 2){
			system("cls");
			cout<<"*****\nDisplay All.\n*****\n1.Medicine\n2.Person\n";
			while (j!=1 || j!=2){
				cin>>j;
				if (j == 1){
					m->M_display();
					getch();
					break;
				}
				else if (j == 2) {
					p->P_display();
					getch();
					break;
				}
				else {
					cout<<"INVALID, Try Again\n*****\nDisplay All.\n*****\n1.Medicine\n2.Person\n";
				}
			}
		}
		else if (i==3){
			system("cls");
			cout<<"*****\nDisplay with Options.\n*****\n1.Medicine\n2.Person\n";
			cin>>j;
			while (j!=1 || j!=2){
				if (j == 1){
					cout<<"Display with Title\n";
					m->displayt(marr);
					getch();
					break;
				}
				else {
					cout<<"\n1.Display with first name\nDisplay with last name\nDisplay with city\n";
					int k;
					
					while (k!=1 || k!=2 || k!=3){
						cin>>k;
						if (k == 1){
							p->displayf(parr);
							getch();
							break;
						}
						else if (k == 2){
							p->displayl(parr);
							getch();
							break;
						}
						else if (k == 3){
							p->personc(parr);
							getch();
							break;
						}
						else {
							cout<<"INVALID Choice, Enter Again\n\n1.Display with first name\nDisplay with last name\nDisplay with city\n";
						}
					}
				}
			}
		}
		else if (i == 4){
			system("cls");
			cout<<"*****\nUpdate.\n*****\n1.Medicine\n2.Person\n";
			while (j!=1 || j!=2){
				cin>>j;
				if (j == 1){
					m->M_update();
					getch();
					break;
				}
				else if (j == 2) {
					p->P_update();
					getch();
					break;
				}
				else {
					cout<<"INVALID, Try Again\n*****\nUpdate.\n*****\n1.Medicine\n2.Person\n";
				}
			}
		}
		else if (i == 5){
			system("cls");
			cout<<"*****\nDelete.\n*****\n1.Medicine\n2.Person\n";
			while (j!=1 || j!=2){
				cin>>j;
				if (j == 1){
					m->M_del();
					getch();
					break;
				}
				else if (j == 2) {
					p->P_del();
					getch();
					break;
				}
				else {
					cout<<"INVALID, Try Again\n*****\nDelete.\n*****\n1.Medicine\n2.Person\n";
				}
			}
		}
		else {
			cout<<"Invalid, Try Again********\nMENU\n********\n\n\n1.Add Record\n2.Display All\n3.Display with Options\n4.Update\n5.Delete Record\n6.Exit";
		}
	}
}
