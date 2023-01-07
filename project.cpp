#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include<vector>
#include<iomanip>
#include <chrono>
#include <thread>
using namespace std;
void dash();
void tab();
void tab2();
void deletedata();
void adddata();
void viewdata();
void viewstudentdata();
void attendance();
void testreport();
void modifydata();
void login();
void menu();
void menu1();
void timetable();
void testperformance();
int studentroll;
int main(){
    login();
    return 0;
    //menu();
}
void dash(){
    cout<<"\t\t\t---------------------------------------------------------";
}
void tab(){              //tab space for alignment
    cout<<"\n\t\t\t\t\t";
}
void tab2(){                  //tab space for alignment
     cout<<"\n\t\t\t\t";
}
void modifydata(){
    string str,name1;
    int rollno,num,i,count=0;
    string q;
    vector<string>row;
    //row.clear();
    fstream obj,obj1;
    obj.open("data.txt",ios::in);
    obj1.open("data1.txt",ios::out);
    
    string moddata;
    int choice;
        obj.seekg(0, ios::beg);
        //cout<<obj.tellp()<<"\t";
        string word;
        cout<<" \n\t\t\tEnter roll no of record you wish to modify: ";
        cin>>num;
        while(getline(obj,str)){
          
            row.clear();
            stringstream obj(str);
            while(getline(obj,word,' ')){
                row.push_back(word);
                //cout<<r
            }
            /*for(i=0;i<row.size();i++){
                cout<<row[i]<<" ";
            }*/
            //cout<<row.size();
            int word1=stoi(row[0]);
            //cout<<str;
            if(num!=word1){
               
                obj1<<str;
                obj1<<"\n";
            }
            else if(num==word1){
                cout<<"\nenter field u wish to modify:\n1.roll no\n2.name\n3.collg\n4.branch\n5.attendance\n6.phy mark\n7.maths mark\n8.chem mark\n";
                cout<<"enter choice: ";
                cin>>choice;
                cout<<"enter modiefied data: ";
                cin>>moddata;
                 row[choice-1]=moddata;
                 for(i=0;i<row.size();i++){
                    obj1<<row[i]<<" ";
                    //cout<<row[i];
                 }
                 obj1<<"\n";
                 count=1;
            }
            
        }
        if(count==1){
            cout<<" \n\t\t\tRECORD modified\n";
        }
        else{
            cout<<" \n\t\t\tRecord doesn't exist";
        }
    
    obj.close();
    obj1.close();
    remove("data.txt");
    rename("data1.txt","data.txt");
    
    
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
    file<<rollno<<" ";
    cout <<"\n \t\t\tenter the name of the student : ";
    cin>>name;
    file<<name<<" ";
    cout<<"\n \t\t\tenter the college name: ";
    cin>>college;
    file<<college<<" ";

cout<<"\n \t\t\tenter the branch: ";
    cin>>branch;
    file<<branch<<" ";
    
    cout<<"\n \t\t\tenter the attendance percentage: "; 
    cin>>attendance;
    file<<attendance<<" ";
    cout<<"\n \t\t\tenter the physics mark: ";
    cin>>physics;
    file<<physics<<" ";
    cout<<"\n \t\t\tenter the maths mark: ";
    cin>>maths;
    file<<maths<<" ";
    cout<<"\n \t\t\tenter the chemistry mark: ";
    cin>>che;
    file<<che<<" ";
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
void viewdata(){
     fstream obj;
      obj.open("data.txt",ios::in|ios::out);
    if(!obj)
    {
        cout<<"no such file in existence";
    }
     cout << "\n\t\t\t\t\t\t|Students Record| \n";
     cout << "\n  ---------------------------------------------------------------------------------------------------------------\n" <<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\tMARKS\n";
    cout<<"\t\t\t\t\t\t\t\t\t***************************************\n";
    cout<<"   Roll No    Name\t   College\t   branch\t Attendance %\t Physics  \tChemistry\t  Maths\n";
    
   
    string word2,name,branch;
    int rollNumber;
  
    while(!obj.eof()){
       
        getline(obj,word2,' ');
        cout<<"   "<<word2<<"  \t  ";
    }
    cout<<"\n";
    obj.close();
}
void viewstudentdata(){
    string str,word;
    vector<string>row;
     int count=0,i;
     fstream obj;
      obj.open("data.txt",ios::in);
    if(!obj)
    {
        cout<<"no such file in existence";
    }
    
    while(getline(obj,str)){
        row.clear();
        stringstream obj(str);
        while(getline(obj,word,' ')){
            row.push_back(word);
        }
        int word1=stoi(row[0]);
        if(studentroll==word1){
            cout << "\n\t\t\t\t\t\t|Students Record| \n";
             cout << "\n  ---------------------------------------------------------------------------------------------------------------\n" <<endl<<endl;
            cout<<"   Roll No    Name\t   College\t   branch\t Attendance %\n";
            for(i=0;i<5;i++){
                cout<<"   "<<row[i]<<"  \t  ";
            }
            count=1;
        }
    }
    if(count!=1){
        cout<<"roll no doesn't exist";
    }
    obj.close();
     
    
   
    
    
}
void menu1(){
    int ch2;
    tab();
    cout<<"\tMAIN MENU\n";
    dash();
    tab();
    cout<<"\t1.View data";
    tab();
    cout<<"\t2.View testreport";
    tab();
    cout<<"\t3.Attendance";
    tab();
    cout<<"\t4.Timetable";
    tab();
    cout<<"\t5.Test performance";
    tab();
    cout<<"\t6.Exit";
    tab();
    cout<<"\tenter choice: ";
    cin>>ch2;
    switch(ch2){
        
        case 1:
        viewstudentdata();
        break;
        case 2:
        testreport();
        break;
        case 3:
        attendance();
        break;
        case 4:
        timetable();
        break;
        case 5:
        testperformance();
        break;
        case 6:
        exit(0);
        cout<<"exited";
        default:
        tab();
        cout<<"\tinvalid input\n";
        menu1();
        
    }
    menu1();
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
    cout<<"\t4.Modify data";
    tab();
    cout<<"\t5.Attendance";
    tab();
    cout<<"\t6.testreport";
    tab();
    cout<<"\t7.Exit";
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
        modifydata();
        break;
        case 5:
        attendance();
        break;
        case 6:
        tab();
        cout<<"enter roll no: ";
        cin>>studentroll;
        testreport();
        break;
        case 7:
        exit(0);
        cout<<"exited";
        default:
        tab();
        cout<<"\tinvalid input\n";
        menu();
        
    }
    menu();
}
void testreport(){
    int roll;
    
    string str,name1;
    int rollno,num,i,count=0;
    string q;
    vector<string>row;
    //row.clear();
    fstream obj,obj1;
    obj.open("data.txt",ios::in);
    //obj1.open("data1.txt",ios::out);
    
    string moddata;
    int choice;
        obj.seekg(0, ios::beg);
        //cout<<obj.tellp()<<"\t";
        string word;
        //cout<<" \n\t\t\tEnter roll no of record you wish to modify: ";
        //cin>>num;
        while(getline(obj,str)){
          
            row.clear();
            stringstream obj(str);
            while(getline(obj,word,' ')){
                row.push_back(word);
                //cout<<r
            }
            /*for(i=0;i<row.size();i++){
                cout<<row[i]<<" ";
            }*/
            //cout<<row.size();
            int word1=stoi(row[0]);
            //cout<<str;
            
            if(studentroll==word1){
                    tab();
                    cout<<"\t\t  MARKS\n";
                    cout<<"\t\t\t\t\t*******************************************\n";
                    tab();
                    cout<<"Physics\t\tChemistry\t Maths\n"; 
                    tab();
                    cout<<" "<<row[5]<<"\t\t  "<<row[6]<<"\t\t  "<<row[7]<<"\n";
                    count=1;
                    break;
            }
        }  
        if(count!=1){
            cout<<"ROLL NO DOESNT EXIST";
        }
    
    obj.close();
    //obj1.close();
    
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
    remove("data.txt");
    rename("data1.txt","data.txt");
    
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
                tab();
                cout<<"enter student roll: ";
                cin>>studentroll;
                menu1();      //main menu function invoked
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

void attendance(){
    
}
void testperformance(){
    tab();
    
   
     std::string filename = "C:\\Users\\user\\OneDrive\\Desktop\\graph.py";
    std::string command = "python ";
    command += filename;
    system(command.c_str());
    

}
void timetable(){
    string str1;
    fstream obj;
    obj.open("tt.txt",ios::in);
    while(getline(obj,str1)){
        cout<<str1<<"\n";
        
    }
    obj.close();
}
