#include <iostream>
#include <conio.h>
#include <cstdio>
#include<cstdlib>
#include<fstream>
#include<iomanip>
using namespace std;

class student{
   int id;
   char name[60];
   char batch[15],semester[15],dept[15],fac[15];
public:
    void input();
    void show();
    int rollNO();

};

int student::rollNO()
{
    return id;
}

/*Create a Student List */
void student::input()  //Member function of Class
{

cout<<"\nEnter The ID Number of Student: ";
cin>>id;
cout<<"Enter The Name of Student: ";
cin.ignore();
cin.getline(name,60);
cout<<"\nEnter The Batch No. of Student: ";
cin.getline(batch,15);
cout<<"\nEnter The Semester No. of Student: ";
cin.getline(semester,15);
//cin.ignore();
cout<<"\nEnter The Department of Student: ";
cin.getline(dept,15);
cout<<"\nEnter The Faculty of Student: ";
cin.getline(fac,15);

}
void student::show()
{

std::cout<<"\n\n#############################################################################################################\n";
    std::cout<<"\n\nID"<<std::setw(25)<<"Name"<<std::setw(35)<<"Batch No."<<std::setw(20)<<"Semester No."<<std::setw(18)<<"Department"<<std::setw(15)<<"Faculty\n";
std::cout<<"==============================================================================================================\n\n\n";
    std::cout<<id<<std::setw(20)<<name<<std::setw(29)<<batch<<std::setw(18)<<semester<<std::setw(21)<<dept<<std::setw(16)<<fac;
}

void Modify(int n);
void Delete_Record(int n);
void Wstudent() //input the student information on text file
{
    student st;
    ofstream op;
    op.open("student.dat",ios::binary|ios::app);
    st.input();
    op.write(reinterpret_cast<char *>(&st),sizeof(student));
    op.close();
    cout<<"\n\nStudent Information Record has been created."<<endl;
    cin.ignore();
    cin.get();
}
/*Display all Record*/

void displayAll()
{
    student st;
    ifstream rp;
    rp.open("student.dat",ios::binary|ios::app);
    if(!rp)
    {
        cout<<"File could not be open !! Press any key...";
        cin.ignore();
        cin.get();
    }
    cout<<"\n\n\t\t\t\tDisplay All Record!!!"<<endl<<endl;
    while(rp.read(reinterpret_cast<char *>(&st),sizeof(student)))
    {
         st.show();
         //std::cout<<"\n\n#######################################################################################################\n";
          std::cout<<"\n\n************************************************************************************************************************\n";
    }
    rp.close();
    cin.ignore();
    cin.get();
}

//Search student record
void Search(int n)
{
    student st;
    ifstream  rp;
    rp.open("student.dat",ios::binary);
    if(!rp)
    {
        cout<<"File could not be open!! Press any key....";
        cin.ignore();
        cin.get();
        return ;
    }
    bool flag=false;
    while(rp.read(reinterpret_cast<char *>(&st),sizeof(student)))
    {
        if(st.rollNO()==n)
        {
            st.show();
            flag=true;
        }
    }
    rp.close();
    if(flag==false)
        cout<<"\n\n Record not exist";
    cin.ignore();
    cin.get();

}


void admin();
void intro();

//Main Function Start
int main()
{
    char ch;
    intro();

    do{
        system("cls");
        cout<<"\n\n"<<'\t'<<"=================================================="<<"\n";
    cout<<'\t'<<"*"<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<" *"<<"\n";
        cout<<"\n\n\n\t\tMain Menu"<<endl;
        cout<<"\n\t\t\t 01.Administrator"<<endl;
        cout<<"\n\t\t\t 02.User"<<endl;
        cout<<"\n\t\t\t 03.Exit"<<endl;
        cout<<"\n\n\t\tPlease Select Your Option (1-3): ";

        cin>>ch;
        switch(ch)
        {
            case '1':admin();break;
            case '2':break;
            case '3':return 0;
        }

    }
    while(cin.get());
    cout << "Hello world!" << endl;
    return 0;
}

void intro()
{
    cout<<"\n\n"<<'\t'<<"=================================================="<<"\n";
    cout<<'\t'<<"*"<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<" *"<<"\n";

    cout<<"\n\n\t\tHamdarad University Bangladesh"<<endl;
    cout<<"\n\t\t Student Management System!!"<<endl;
    cout<<"\n\t\t\tMade by "<<endl;
    cout<<"\n\t\t    MD.NAIMUR RAHMAN"<<endl;
    cout<<"\t\t\    Department of CSE"<<endl;
    cout<<"\n\n"<<'\t'<<"*"<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<" *"<<endl;
    cout<<'\t'<<"=================================================="<<"\n";

    cin.get();
}
void admin(){
char ch,ph;
int num;
system("cls");
cout<<"\n\n"<<'\t'<<'\t'<<"=================================================="<<"\n";
    cout<<'\t'<<'\t'<<"*"<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<" *"<<"\n";
cout<<"\n\n\t\t|Admin Panel|"<<endl;
cout<<"\n\t\t\t01.Create Student Record."<<endl;
cout<<"\n\t\t\t02.Display All Students Record."<<endl;
cout<<"\n\t\t\t03.Search Student Record."<<endl;
cout<<"\n\t\t\t04.Modify Student Record."<<endl;
cout<<"\n\t\t\t05.Delete Student Record."<<endl;
cout<<"\n\t\t\t06.Back To Main Menu."<<endl;
cout<<"\n\n\t\t-->Please Enter Your Choice(1-6): ";
cin>>ch;
system("cls");
switch(ch)
{
case '1':
    cout<<"\n\t\t01.Create Student Information Record."<<endl;
    cout<<"\n\t\t02.Create Student Result Record."<<endl;
    cout<<"\n\t\t03.Back."<<endl;
    cout<<"\n\n\t\t-->Please Enter Your Choice(01-03): ";
    cin>>ph;
    system("cls");
    switch(ph)
    {
        case '1':
           do {
        Wstudent();

        cout<<"\n\nBack to Main Menu Press '0'. Continue Press '1': ";
         cin>>num;
    if(num==0) break;
        }
        while(num!=0);
                  break;
        case '2':break;
        case '3':break;
    }
    break;
case '2': displayAll();
    do {
        displayAll();

        cout<<"\n\nBack to Main Menu Press '0': ";
         cin>>num;
    if(num==0) break;
        }
        while(num!=0);break;


case '3':do {

    cout<<"\n\n\tPlease Enter Id Number : ";
    cin>>num;

    if(num==0) break;
        Search(num);
        cout<<"\n\nBack to Main Menu Press '0'"<<endl;
        }
        while(num!=0);
                  break;
case '4':
   /* cout<<"Enter ID Number :";
    cin>>num;
Modify(num);*/do {

    cout<<"\n\n\tPlease Enter Id Number : ";
    cin>>num;

    if(num==0) break;
        Modify(num);
        cout<<"\n\nBack to Main Menu Press '0'"<<endl;
        }
        while(num!=0);
        break;
case '5':cout<<"Enter The ID Number :";
        cin>>num;
        Delete_Record(num);break;
case '6':break;

     }
}

//Modify
void Modify(int n)
{
	bool found=false;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}

	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&st), sizeof(student));
		if(st.rollNO()==n)
		{
			st.show();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.input();
		    int pos=(-1)*static_cast<int>(sizeof(st));
		    File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&st), sizeof(student));
		    cout<<"\n\n\t Record Updated";
		    found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();

}



void Delete_Record(int n)

{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.rollNO()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
}

