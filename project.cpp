#include <iostream>
#include<string.h>
#include <chrono>
#include <thread>

using namespace std;
void login();
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
    cout<<"MAIN MENU\n";
    dash();
    tab();
    cout<<"1.View data";
    tab();
    cout<<"2.Add data";
    tab();
    cout<<"3.Delete data";
    tab();
    cout<<"4.Attendance";
    tab();
    cout<<"5.Exit";
    tab();
    cout<<"enter choice: ";
    cin>>ch2;
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
        while(i>0){                    //admin verification
            i--;                      //no of attempts keep decreasing with every re-login.
            tab();
            cout<<"Enter password: ";
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
