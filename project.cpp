#include <iostream>
#include<string.h>
#include <chrono>
#include <thread>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
void login();
void viewdata();
void deletedata();
void adddata();
void attendance();
void dash();
void tab();
void tab2();
void menu();

void dash(){
    cout<<"\t\t\t---------------------------------------------------------";
}
void tab(){              //tab space for alignment
    cout<<"\n\t\t\t\t\t";
}
void tab2(){                  //tab space for alignment
     cout<<"\n\t\t\t\t";
}
int main()
{
    login();          //prog starts here. Goes to login page-->admin or student 

    return 0;
}
void menu(){
    int ch2;
    tab();
    cout<<"\tMAIN MENU\n";
    dash();
    tab();
    cout<<"\t1.View data";
    tab();
    cout<<"\t2.Add data";
    tab();
    cout<<"\t3.Delete data";
    tab();
    cout<<"\t4.Attendance";
    tab();
    cout<<"\t5.Exit";
    tab();
    cout<<"\tenter choice: ";
    cin>>ch2;
    switch(ch2){
        
        case 1:
        viewdata();
        break;
        case 2:
        adddata();
        break;
        case 3:
        deletedata();
        break;
        case 4:
        attendance();
        break;
        case 5:
        exit(0);
        cout<<"exited";
        default:
        tab();
        cout<<"\tinvalid input\n";
        menu();
        
    }
    menu();
}
void login(){
    int ch1,i=3,captcha,j=3;  //max no of login attempts:3  i:for admin  j:for student
    char logg='n';
    char pass[50];
    cout<<"\t\t\t\t\t      WELCOME USER\n";
    cout<<"\t\t\t\t\t\t LOGIN\n";
    dash();
    cout<<"\n\t\t\t\t\t\tLogin as: \n\n\t\t\t\t\t1.Admin\n\t\t\t\t\t2.Student\n\n";
    cout<<"\t\t\t\t\tenter choice: ";
    cin>>ch1;
    switch(ch1){
        case 1:              //admin login
        cout<<"\n\t\t\t\t\t      WELCOME ADMIN\n";
        dash();
        while(i>0){        //admin verification
            i--;    //no of attempts keep decreasing with every re-login.
            cout<<"\n\t\t\t\t\tEnter password: ";
            cin>>pass;
            if(strcmp(pass,"pw1024")==0){              //default password to login as admin:pw1024
                tab2();
                cout<<"SUCCESSFULL LOGIN! ";              //successfull login
                logg='y';
                cout<<"MAIN MENU LOADING PLEASE WAIT...\n";   //menu loading time:2secs 
                this_thread::sleep_for(chrono::seconds(2));
                menu();    //main menu function invoked
                break;
            }
            else if(i>0){               
                tab2();
                cout<<"Wrong pw try again.You have "<<i<<" attempt(s) left\n";
                
            }
            //i++;
        }
        break;
        case 2:        //student login
        
        cout<<"\n\t\t\t\t\t      WELCOME STUDENT\n";      
        dash();
        while(j>0){
            j--;              //no of attempts keep decreasing with every re-login.
            tab();
            cout<<"CAPTCHA: ";      //student verification
            srand(time(0));         //random number generator
            int a=rand();
            cout<<a<<"\n";
            tab();
            cout<<"Enter above captcha: ";  
            cin>>captcha;
            if(captcha==a){
                tab2();
                cout<<"CAPTCHA VERIFIED!";        //captcha verified
                logg='y';
                cout<<"MAIN MENU LOADING PLEASE WAIT...\n";         //menu loading time:2secs 
                this_thread::sleep_for(chrono::seconds(2));
                menu();      //main menu function invoked
                break;
            }
            else if(j>0){
                tab2();
                cout<<"Wrong captcha try again.You have "<<j<<" attempts left\n";
            }
            
            
        }
    }
        if(logg!='y'){             //successful login only if logg set to 'y' else failed
            cout<<"LOGIN FAILED.LOGIN AFTER 5s.....\n";     //login() function appears again after 5 secs
            this_thread::sleep_for(chrono::seconds(5));
            login();
       // menu();
        //menu();
        }
}
void adddata(){
    fstream file("data.txt",ios::out| ios::app);
   //check of the file is open or not
    if(!file)
    {
        cout<<"failed to open the file";
    }
    else{
        cout<<" \t\t\tEnter the data\n";
    }
    //declare variables
    string name,college,branch;
    int rollno,attendance,physics,che,maths;
    //enter the  values
    cout<<"\n \t\t\tenter the rollno : ";
    cin>>rollno;
    file<<rollno<<"\t";
    cout <<"\n \t\t\tenter the name of the student : ";
    cin>>name;
    file<<name<<"\t\t";
    cout<<"\n \t\t\tenter the college name: ";
    cin>>college;
    file<<college<<"\t\t";

cout<<"\n \t\t\tenter the branch: ";
    cin>>branch;
    file<<branch<<"\t\t";
    
    cout<<"\n \t\t\tenter the attendance percentage: "; 
    cin>>attendance;
    file<<attendance<<"\t\t";
    cout<<"\n \t\t\tenter the physics mark: ";
    cin>>physics;
    file<<physics<<"\t\t";
    cout<<"\n \t\t\tenter the maths mark: ";
    cin>>maths;
    file<<maths<<"\t\t";
    cout<<"\n \t\t\tenter the chemistry mark: ";
    cin>>che;
    file<<che<<"\t\t";
    file<<"\n";
    //close file
    file.close();
    //options to add the missed out data
    cout<<"\n \t\t\tadd missed out data? (YES/NOOO) : ";
    string option;
    cin>>option;
    if(option=="YES")
    {//back to adddata function
        adddata();
    }
    else if(option=="NOOO")
    {//back to the main menu
       // admindata();
       menu();
    }
    
    
}
void deletedata(){
    string str,name1;
    int rollno,num,i,count;
    string q;
    vector<string>row;
    
    fstream obj,obj1;
    obj.open("data.txt",ios::in);
    obj1.open("data1.txt",ios::out);
    if(!getline(obj,q)){
        //cout<<obj.tellp()<<"\t";
        cout<<" \n\t\t\tempty\n";
    }
    
    else{
        obj.seekg(0, ios::beg);
        //cout<<obj.tellp()<<"\t";
        string word;
        cout<<" \n\t\t\tEnter roll no of record you wish to delete: ";
        cin>>num;
        while(getline(obj,str)){
            row.clear();
            stringstream obj(str);
            while(getline(obj,word,' ')){
                row.push_back(word);
            }
            int word1=stoi(row[0]);
            //cout<<str;
            if(num!=word1){
                obj1<<str;
                obj1<<"\n";
            }
            else if(num==word1){
                 count=1;
            }
            rename("data1.txt","data.txt");
        }
        if(count==1){
            cout<<" \n\t\t\tRECORD DELETED\n";
        }
        else{
            cout<<" \n\t\t\tRecord doesn't exist";
        }
    }
    obj.close();
    obj1.close();
    
    
}
void viewdata(){
     fstream obj;
      obj.open("data.txt",ios::in|ios::out);
    if(!obj)
    {
        cout<<"no such file in existence";
    }
     cout << "\n\t\t\t\t\t\t|Students Record| \n";
     cout << "\n  ---------------------------------------------------------------------------------------------------------------\n" <<endl<<endl;
    cout<<"Roll\tName\t\tCollege\t\tbranch\t\tAttendance\tPhysics\t\tChemistry\tMaths\n";
    
   
    string word2,name,branch;
    int rollNumber;
  
    while(!obj.eof()){
       
        getline(obj,word2);
        cout<<word2<<"\n";
    }
    obj.close();
}
void attendance(){
    
}
