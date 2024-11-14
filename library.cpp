#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

//Function for Input Validation
bool isValidName(string name)
{
  return all_of(name.begin(), name.end(), [](char ch) {
    return (isalpha(ch) || isspace(ch));
  });
}

 bool onlyDigits(string str, int n)
    {
        // Traverse the string from
        // start to end
        if(str[0]<='0'){
            return false;
        }
        for (int i = 0; i < n; i++) {

            // Check if character is
            // not a digit between 0-9
            // then return false
            if (str[i] < '0'
                || str[i] > '9') {
                return false;
            }
        }
          // If we reach here, that means
          // all characters were digits.
        return true;
    }





int flag123=0;
class Librarian {
    protected:
    unsigned int id=0;
    string lname,qual,exp;
    public:

    void gatherData(){
        cout << "\nLibrarian Name: ";
        cin >> lname;
        int flag = 0;
        while(flag == 0){
            if(isValidName(lname)){
                flag = 1;
                
            }else{
                cout<<"Invalid Input\n";
                cout<<"Librarian Name: ";
                cin>>lname;
            }
        } 
        cout << "\nLibrarian Qualification: ";
        cin >> qual;
        flag = 0;
        while(flag == 0){
            if(isValidName(qual)){
                flag = 1;
                
            }else{
                cout<<"Invalid Input\n";
                cout<<"Qualification: ";
                cin>>qual;
            }
        } 
        cout << "\nLibrarian Work Experience(in years): ";
        cin >> exp;
        flag = 0;
        while(flag == 0){
            if(onlyDigits(exp,exp.length())){
                flag = 1;
                
            }else{
                cout<<"Invalid Input\n";
                cout<<"Librarian Work Experience(in years): ";
                cin>>exp;
                
            }
        }

        id++;
    }

    void write(){
        ofstream write;
        write.open("librarian.txt",ios::app);
        if(!write){
            cout << "\nFile could not be opened.";
        } else {

            write << id << " " << lname << " " << qual << " " << exp << endl;

        }
    }


    void displaydata(){
    fstream file;
	cout << "\nAll Librarian Data:";
	file.open("librarian.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		file >> id >> lname;
		file >> qual >> exp;
		while (!file.eof()) {

			cout << "\nID: " << id
				<< "\nLibrarian Name: " << lname
				<< "\nLibrarian Qualification: " << qual
				<< "\nLibrarian Experience: " << exp << "yrs"
				<< "\n";

        file >> id >> lname;
		file >> qual >> exp;
		}
		file.close();
	}
    }


    void specificData(int idc)
    {
        int flag=0;
        fstream read;
        read.open("librarian.txt",ios::in);
        if(!read){
            cout << "\n\nFile Opening Error!";
        } else {
            while(!read.eof()){
                read >> id;
                read >> lname;
                read >> qual;
                read >> exp;
                if(id==idc){
                    flag=1;
                 cout << "\nLibrarian Data: ";
			    cout << "\nID: " << id
				<< "\nLibrarian Name: " << lname
				<< "\nLibrarian Qualification: " << qual
				<< "\nLibrarian Experience: " << exp << "yrs"
				<< "\n";
                break;
                }
               

            }
            if (flag==0){
                cout << "\nLibrarian ID Not Found.";
            }

        }
    }



     void updateData() {
        unsigned int vid,flag=0;
        string lname_c,qual_c,exp_c;
        ofstream write;
        ifstream read;
        cout << "\n\nUpdate librarian Record";
        write.open("temp.txt", ios::app);
        read.open("librarian.txt");

        if(!read){
            cout << "\nFile could not be found or File could not be created.";
        } else {
            cout << "\nLibrarian ID: ";
            cin >> vid;
            
            while (!read.eof()){
                read >> id;
                read >> lname;
                read >> qual;
                read >> exp;
                if(vid != id){
                    write << id << " " << lname << " " << qual << " " << exp << endl;
                } else {
                cout << "\t\t\t\tUpdate Librarian Record";
	            cout << "\nNew Librarian Name : ";
	            cin >> lname_c;
                        int flag1 = 0;
        while(flag1 == 0){
            if(isValidName(lname_c)){
                flag1 = 1;
                
            }else{
                cout<<"Invalid Input\n";
                cout<<"Librarian Name: ";
                cin>>lname_c;
            }
        } 
	            cout << "\nNew Librarian Qualification: ";
	            cin >> qual_c;
                flag1 = 0;
                while(flag == 0){
                    if(isValidName(qual_c)){
                        flag1 = 1;
                        
                    }else{
                        cout<<"Invalid Input\n";
                        cout<<"Qualification: ";
                        cin>>qual_c;
                    }
                } 
	            cout << "\nNew Librarian Work Experience (in years): ";
	            cin >> exp_c;
                flag1 = 0;
                while(flag1 == 0){
                    if(onlyDigits(exp,exp.length())){
                        flag1 = 1;
                        
                    }else{
                        cout<<"Invalid Input\n";
                        cout<<"Librarian Work Experience(in years): ";
                        cin>>exp_c;
                        
                    }
                }

                    write << id << " " << lname_c << " " << qual_c << " " << exp_c << endl;
                flag++;
                read >> id;
                read >> lname;
                read >> qual;
                read >> exp;
                } 
            }
            if(flag==0){
                    cout << "\nLibrarian ID not found.";
                }
        }

        cout << endl;
        write.close();
        read.close();
        remove("librarian.txt");
        rename("temp.txt", "librarian.txt");
    }



    void deleteData() {
    fstream file, file1;
    int found = 0;
    int CNum;
    cout << "\nDelete Librarian Details." << endl;

    file.open("librarian.txt", ios::in);
    if (!file)
    {
        cout << "\nFile Not Found.";
    }
    else
    {
        cout << "\nLibrarian ID:  ";
        cin >> CNum;
        file1.open("temp.txt", ios::app | ios::out);
        file >> id >> lname >> qual >> exp;
        while (!file.eof())
        {
            if (CNum != id)
            {
                     file1 << id << " " << lname << " " << qual << " " << exp << endl;
            }
            else
            {
                found++;
                cout << "\nDeleted successfully.";
            }
              file >> id >> lname >> qual >> exp;
        }
        if (found == 0)
        {
            cout << "\nStudent ID not found.";
        }
        file1.close();
        file.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");
    }
}

};


class Book {
    
    public:
    unsigned int id=0,flag404;
    string bname,auth,pub,cop;

    void gatherData(){
        cout << "\nBook Name: ";
        cin >> bname;
        int flag = 0;
        while(flag == 0){
            if(isValidName(bname)){
                flag = 1;
                
            }else{
                cout<<"Invalid Input\n";
                cout<<"Book Name: ";
                cin>>bname;
            }
        } 
        cout << "\nBook Author: ";
        cin >> auth;
        flag = 0;
        while(flag == 0){
            if(isValidName(auth)){
                flag = 1;
                
            }else{
                cout<<"Invalid Input\n";
                cout<<"Book AUthor: ";
                cin>>auth;
            }
        } 

        cout << "\nBook Publication: ";
        cin >> pub;
        flag = 0;
        while(flag == 0){
            if(isValidName(pub)){
                flag = 1;
                
            }else{
                cout<<"Invalid Input\n";
                cout<<"Book Publication: ";
                cin>>pub;
            }
        } 
        cout << "\nNumber of Copies: ";
        cin >> cop;
        flag = 0;
        while(flag == 0){
            if(onlyDigits(cop,cop.length())){
                flag = 1;

            }else{
                cout<<"Invalid Input\n";
                cout<<"No of Copies: ";
                cin>>cop;

            }
        }
        id++;
    }

    void write(){
        ofstream write;
        write.open("book.txt",ios::app);
        if(!write){
            cout << "\nFile could not be opened.";
        } else {
            write << id << " " << bname << " " << auth << " " << pub << " " << cop << endl;
   
        }
    }


    void displaydata(){
    fstream file;
	cout << "\nAll Book Data:";
	file.open("book.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		file >> id >> bname;
		file >> auth >> pub;
        file >> cop;
		while (!file.eof()) {
          
			cout << "\nID: " << id
				<< "\nBook Name: " << bname
				<< "\nAuthor: " << auth
				<< "\nPublication: " << pub
                << "\nNo. of Copies: " << cop
				<< "\n";
               
        file >> id >> bname;
		file >> auth >> pub;
        file >> cop;
		}
		file.close();
	}
    }


    void specificData(int idc)
    {
        int flag=0;
        fstream read;
        read.open("book.txt",ios::in);
        if(!read){
            cout << "\n\nError!";
        } else {
            while(!read.eof()){
                read >> id;
                read >> bname;
                read >> auth;
                read >> pub;
                read >> cop;
                if(id==idc){
                    flag=1;
                 cout << "\nBook Data: ";
			   cout << "\nID: " << id
				<< "\nBook Name: " << bname
				<< "\nAuthor: " << auth
				<< "\nPublication: " << pub
                << "\nNo. of Copies: " << cop
				<< "\n";
                break;
                }
               

            }
            if (flag==0){
                cout << "\nBook ID Not Found.";
            }

        }
    }



     void updateData() {
        unsigned int vid,flag=0;
        string bname_c,auth_c,pub_c,cop_c;
        ofstream write;
        ifstream read;
        cout << "\n\nUpdate book Record";
        write.open("temp.txt", ios::app);
        read.open("book.txt");

        if(!read){
            cout << "\nFile could not be found or File could not be created.";
        } else {
            cout << "\nBook ID: ";
            cin >> vid;
            
            while (!read.eof()){
                read >> id;
                read >> bname;
                read >> auth;
                read >> pub;
                read >> cop;
                if(vid != id){
                    write << id << " " << bname << " " << auth << " " << pub << " " << cop << endl;
                } else {
                cout << "\t\t\t\tUpdate Book Record";
	            cout << "\nNew Book Name : ";
	            cin >> bname_c;
                int flag1 = 0;
                while(flag1 == 0){
                    if(isValidName(bname_c)){
                        flag1 = 1;
                        
                    }else{
                        cout<<"Invalid Input\n";
                        cout<<"Book Name: ";
                        cin>>bname_c;
                    }
                } 


	            cout << "\nNew Book Author: ";
	            cin >> auth_c;
                flag1 = 0;
                while(flag1 == 0){
                    if(isValidName(auth_c)){
                        flag1 = 1;
                        
                    }else{
                        cout<<"Invalid Input\n";
                        cout<<"Book AUthor: ";
                        cin>>auth_c;
                    }
                } 

	            cout << "\nNew Book Publication : ";
	            cin >> pub_c;
                flag1 = 0;
                while(flag1 == 0){
                    if(isValidName(pub_c)){
                        flag1 = 1;
                        
                    }else{
                        cout<<"Invalid Input\n";
                        cout<<"Book Publication: ";
                        cin>>pub_c;
                    }
                } 
                cout << "\nNew no. of  copies: ";
	            cin >> cop_c;
                flag1 = 0;
                while(flag1 == 0){
                    if(onlyDigits(cop_c,cop_c.length())){
                        flag1 = 1;
                        
                    }else{
                        cout<<"Invalid Input\n";
                        cout<<"No of Copies: ";
                        cin>>cop_c;
                        
                    }
                }
                id++;
            }


                    write << id << " " << bname_c << " " << auth_c << " " << pub_c << " " << cop_c << endl;
                flag++;
                read >> id;
                read >> bname;
                read >> auth;
                read >> pub;
                read >> cop;
                } 
            }
            if(flag==0){
                    cout << "\nBook ID not found.";
                }
                 cout << endl;
        write.close();
        read.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");
        }



    void deleteData() {
    fstream file, file1;
    int found = 0;
    int CNum;
    cout << "\nDelete Book Details." << endl;

    file.open("book.txt", ios::in);
    if (!file)
    {
        cout << "\nFile Not Found.";
    }
    else
    {
        cout << "\nBook ID:  ";
        cin >> CNum;
        file1.open("temp.txt", ios::app | ios::out);
        file >> id >> bname >> auth >> pub >> cop;
        while (!file.eof())
        {
            if (CNum != id)
            {
                     file1 << id << " " << bname << " " << auth << " " << pub << " " << cop << endl;
            }
            else
            {
                found++;
                cout << "\nDeleted successfully.";
            }
            file >> id >> bname >> auth >> pub >> cop;
        }
        if (found == 0)
        {
            cout << "\nStudent ID not found.";
        }
        file1.close();
        file.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");
    }
}


    int updateBook(int x){

        unsigned int vid,cop_c,flag=0,num;
        ofstream write;
        ifstream read;

        
        write.open("temp.txt", ios::app);
        read.open("book.txt");

        if(!read){
            cout << "\nFile could not be found or File could not be created.";
        } else {
            vid = x;
                 read >> id;
                read >> bname;
                read >> auth;
                read >> pub;
                read >> cop;
            while (!read.eof()){
                if(vid != id){
                write << id << " " << bname << " " << auth << " " << pub << " " << cop << endl;
                } else {
                    num = stoi(cop);
                    cop = to_string(num);
                flag=1;
                if(num==0){
                    write << vid << " " << bname << " " << auth << " " << pub << " " << cop << endl;
                    remove("temp.txt");
                    return 404;
                } else {

                num--;
                 cop = to_string(num);
                write <<  vid << " " << bname << " " << auth << " " << pub << " " << cop << endl;
                } 
                }
                read >> id;
                read >> bname;
                read >> auth;
                read >> pub;
                read >> cop;
                
            }
            if(flag==0){
                    cout << "\nBook ID not found.";
                }
        }

        cout << endl;
        write.close();
        read.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");
    

}


int updateBookbug(int x){

        unsigned int vid,cop_c,flag=0,num;
        ofstream write;
        ifstream read;
        write.open("temp.txt", ios::app);
        read.open("book.txt");

        if(!read){
            cout << "\nError!";
        } else {
            vid = x;
                 read >> id;
                read >> bname;
                read >> auth;
                read >> pub;
                read >> cop;
            while (!read.eof()){
                if(vid != id){
                write << id << " " << bname << " " << auth << " " << pub << " " << cop << endl;
                } else {
                flag=1;
                num = stoi(cop);
                num++;
                cop = to_string(num);
                write << vid << " " << bname << " " << auth << " " << pub << " " << cop << endl;
                remove("temp.txt");
                return 1234; 
                }
                read >> id;
                read >> bname;
                read >> auth;
                read >> pub;
                read >> cop;
                
            }
            if(flag==0){
                    cout << "\nBook ID not found.";
                }
        }

        cout << endl;
        write.close();
        read.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");
    
}
};

class Student : public Book{
    protected:
    int id=0;
    string sname,dept,grade,div,book1,book2,book3;
    public:

    void gatherData(){
        cout << "\nStudent Name: ";
        cin >> sname;
        int flag = 0;
        while(flag == 0){
            if(isValidName(sname)){
                flag = 1;
                
            }else{
                cout<<"Invalid Input\n";
                cout<<"Student Name: ";
                cin>>sname;
            }
        }         
        cout << "\nStudent Department: ";
        cin >> dept;
        flag = 0;
        while(flag == 0){
            if(isValidName(dept)){
                flag = 1;
                
            }else{
                cout<<"Invalid Input\n";
                cout<<"Sudent Department: ";
                cin>>dept;
            }
        } 
        cout << "\nStudent grade: ";
        cin >> grade;
        flag = 0;
        while(flag == 0){
            if(isValidName(grade)){
                flag = 1;
                
            }else{
                cout<<"Invalid Input\n";
                cout<<"Grade: ";
                cin>>grade;
            }
        } 
        cout << "\nStudent Division: ";
        cin >> div;
                while(flag == 0){
            if(isValidName(div)){
                flag = 1;
                
            }else{
                cout<<"Invalid Input\n";
                cout<<"Div: ";
                cin>>div;
            }
        }
        book1 = "no-book";
        book2 = "no-book";
        book3 = "no-book";
        id++;
    }

    void write(){
        ofstream write;
        write.open("student.txt",ios::app);
        if(!write){
            cout << "\nFile could not be opened.";
        } else {
            
            write << id << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << "\n";
          
        }
    }


    void displaydata(){
    fstream file;
	cout << "\nAll Student Data:";
	file.open("student.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		file >> id >> sname;
		file >> dept >> grade;
        file >> div >> book1;
        file >> book2 >> book3;
		while (!file.eof()) {
            
			cout << "\nID: " << id
				<< "\nStudent Name: " << sname
				<< "\nStudent Dept: " << dept
				<< "\nStudent Grade: " << grade
                << "\nStudent Division: " << div
                << "\nBooks Issued: " << book1 << ", " << book2 << ", " << book3
				<< "\n";
              
        file >> id >> sname;
		file >> dept >> grade;
        file >> div >> book1;
        file >> book2 >> book3;
		}
		file.close();
	}
    }


    void specificData(int idc)
    {
        int flag=0;
        fstream read;
        read.open("student.txt",ios::in);
        if(!read){
            cout << "\n\nFile Opening Error!";
        } else {
            while(!read.eof()){
                read >> id;
                read >> sname;
                read >> dept;
                read >> grade;
                read >> div;
                if(id==idc){
                    flag=1;
                 cout << "\nStudent Data: ";
			    cout << "\nID: " << id
				<< "\nStudent Name: " << sname
				<< "\nStudent Dept: " << dept
				<< "\nStudent Grade: " << grade
                << "\nStudent Division: " << div
				<< "\n";
                break;
                }
               

            }
            if (flag==0){
                cout << "\nStudent ID Not Found.";
            }

        }
    }



     void updateData() {
        unsigned int vid,flag=0;
        string sname_c,dept_c,grade_c,div_c,book;
        ofstream write;
        ifstream read;
        cout << "\n\nUpdate Student Record";
        write.open("temp.txt", ios::app);
        read.open("student.txt");

        if(!read){
            cout << "\nFile could not be found or File could not be created.";
        } else {
            cout << "\nStudent ID: ";
            cin >> vid;
            
            while (!read.eof()){
                read >> id;
                read >> sname;
                read >> dept;
                read >> grade;
                read >> div;
                read >> book1;
                read >> book2;
                read >> book3;
                if(vid != id){
                    write << id << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
                } else {
                cout << "\t\t\t\tUpdate Student Record";
	            cout << "\nNew Student Name : ";
	            cin >> sname_c;
                int flag1 = 0;
                while(flag1 == 0){
                    if(isValidName(sname_c)){
                        flag1 = 1;
                        
                    }else{
                        cout<<"Invalid Input\n";
                        cout<<"Student Name: ";
                        cin>>sname_c;
                    }
                }
                
	            cout << "\nNew Student Department: ";
	            cin >> dept_c;
      flag1 = 0;
        while(flag == 0){
            if(isValidName(dept_c)){
                flag1 = 1;
                
            }else{
                cout<<"Invalid Input\n";
                cout<<"Sudent Department: ";
                cin>>dept_c;
            }
        } 
	            cout << "\nNew Student Grade : ";
	            cin >> grade_c;
        cout << "\nStudent grade: ";
        cin >> grade;
        flag1  = 0;
        while(flag1 == 0){
            if(isValidName(grade_c)){
                flag1 = 1;
                
            }else{
                cout<<"Invalid Input\n";
                cout<<"Grade: ";
                cin>>grade_c;
            }
        }
                cout << "\nNew Student Division : ";
	            cin >> div_c;
        flag1 = 0;
        while(flag1 == 0){
            if(isValidName(div_c)){
                flag1 = 1;
                
            }else{
                cout<<"Invalid Input\n";
                cout<<"Div: ";
                cin>>div_c;
            }
        }
               write << id << " " << sname_c << " " << dept_c << " " << grade_c << " " << div_c  << " " << book1 << " " << book2 << " " << book3 << endl;
                flag++;
                read >> id;
                read >> sname;
                read >> dept;
                read >> grade;
                read >> div;
                read >> book1;
                read >> book2;
                read >> book3;
                } 
            }
            if(flag==0){
                    cout << "\nStudent ID not found.";
                }
        }

        cout << endl;
        write.close();
        read.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");
    }



    void deleteData() {
    fstream file, file1;
    int found = 0;
    int CNum;
    cout << "\nDelete Student Details." << endl;

    file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "\nFile Not Found.";
    }
    else
    {
        cout << "\nStudent ID:  ";
        cin >> CNum;
        file1.open("temp.txt", ios::app | ios::out);
        file >> id >> sname >> dept >> grade >> div >> book1 >> book2 >> book3;
        while (!file.eof())
        {
            if (CNum != id)
            {
                     file1 << id << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
            }
            else
            {
                found++;
                cout << "\nStudent Record has been deleted successfully.";
            }
            file >> id >> sname >> dept >> grade >> div >> book1 >> book2 >> book3;
        }
        if (found == 0)
        {
            cout << "\nStudent ID not found.";
        }
        file1.close();
        file.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");
    }
}

    string assignBookValue(int x){

        int flag=0;
        fstream read;
        read.open("book.txt",ios::in);
        if(!read){
            cout << "\n\nFile Opening Error!";
        } else {
            while(!read.eof()){
                read >> id;
                read >> bname;
                read >> auth;
                read >> pub;
                read >> cop;
                if(id==x){
                flag=1;
                return(bname);
                break;
                }
               

            }
            if (flag==0){
                cout << "\nBook ID Not Found.";
            }

        }
        
    }


    int checkStudent(int idc){
         int flag=0;
        fstream read;
        read.open("student.txt",ios::in);
        if(!read){
            cout << "\n\nFile Opening Error!";
        } else {
            while(!read.eof()){
                read >> id;
                read >> sname;
                read >> dept;
                read >> grade;
                read >> div;
                read >> book1;
                read >> book2;
                read >> book3;
                if(id==idc){
                    flag=1;
                    if(book1.compare("no-book")!=0 && book2.compare("no-book")!=0 && book3.compare("no-book")!=0){
                        return 123;
                        break;
                    }

                    
                }
               

            }
            if (flag==0){
                cout << "\nStudent ID Not Found.";
            }

        }


    }

    int updateStudent(int x,int y){


        unsigned int vid,flag=0;
        string book;
        ofstream write;
        ifstream read;
        write.open("temp.txt", ios::app);
        read.open("student.txt");
        

        if(!read){
            cout << "\nFile could not be found or File could not be created.";
        } else {
            vid = x;
                read >> id;
                read >> sname;
                read >> dept;
                read >> grade;
                read >> div;
                read >> book1;
                read >> book2;
                read >> book3;
            while (!read.eof()){
                if(vid != id){
                    write << id << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
                } else {
                    if(book1.compare("no-book")==0){
                book1 = assignBookValue(y);
                if (flag404!=1){
                write << vid << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
                flag=1;
                cout << "\nBook has been Issued.";
                }
                } else if(book2.compare("no-book")==0){
                book2 = assignBookValue(y);
                if (flag404!=1){
                write << vid << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
                flag=1;
                cout << "\nBook has been Issued.";
                }
                }else if(book3.compare("no-book")==0){
                book3 = assignBookValue(y);
                if (flag404!=1){
                write << vid << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
                flag=1;
                cout << "\nBook has been Issued.";
                }
                } else {
                if (flag404!=1){
                write << vid << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
                flag=1;
                cout << "\nStudent already has max number of books.";
                return 123;
                }
                    flag=1;
                }
                }
                read >> id;
                read >> sname;
                read >> dept;
                read >> grade;
                read >> div;
                read >> book1;
                read >> book2;
                read >> book3;
            }
            if(flag==0){
                    cout << "\nStudent ID not found.";
                }
        }

        cout << endl;
        write.close();
        read.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");


    }


    void testBook(string x){
        int bidd,flag,num;
        flag=0;
        fstream read;
        ofstream write;
        write.open("temp1.txt",ios::app);
        read.open("book.txt",ios::in);
        if(!read){
            cout << "\nFile Opening Error";

        } else{
                read >> bidd;
                read >> bname;
                read >> auth;
                read >> pub;
                read >> cop;
                while(!read.eof()){
                    if(bname.compare(x)==0){
                        flag=1;
                        num = stoi(cop);
                        num++;
                        cop = to_string(num);
                        write <<  bidd << " " << bname << " " << auth << " " << pub << " " << cop << endl;
                        cout << "\nBook has been returned.";
                    } else {
                         write <<  bidd << " " << bname << " " << auth << " " << pub << " " << cop << endl;
                    }
                read >> bidd;
                read >> bname;
                read >> auth;
                read >> pub;
                read >> cop;
                }

                if(flag==0){
                    cout << "\nStudent does not have a book";
                }





                write.close();
                read.close();
                remove("book.txt");
                rename("temp1.txt","book.txt");


        }

        



    }


    void testStudent(int x)
    {
        int flag=0,choice;
        fstream read;
        ofstream write;
        write.open("temp.txt",ios::app);
        read.open("student.txt",ios::in);
        if(!read){
            cout << "\n\nFile Opening Error!";
        } 
        else{
                read >> id;
                read >> sname;
                read >> dept;
                read >> grade;
                read >> div;
                read >> book1;
                read >> book2;
                read >> book3;
                while(!read.eof()){
                    if(id==x){
                        if(book1.compare("no-book")==0 && book2.compare("no-book")==0 &&book3.compare("no-book")==0){
                            cout<<"No books to return!";
                        }
                        else
                        {
                                
                                if (book1.compare("no-book") != 0)
                                {
                                    cout << "\nWhich book would you like to return?\n";
                                    cout << " (1) " << book1 << endl;
                                }
                                if (book2.compare("no-book") != 0)
                                {
                                    cout << " (2) " << book2 << endl;
                                }
                                if (book3.compare("no-book") != 0)
                                {
                                    cout << " (3) " << book3 << endl;
                                }
                    
                                cin >> choice;

                                if(choice==1){

                                if(book1.compare("no-book")!=0){
                                    flag=1;
                                    testBook(book1);
                                    book1 = "no-book";
                                    write << id << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
                                } 
                                else {
                                    flag=1;
                                    write << id << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
                                    cout << "\nStudent does not have a book.";
                                }
                                }
                                else if(choice==2){
                                
                                if(book2.compare("no-book")!=0){
                                    flag=1;
                                    testBook(book2);
                                    book2 = "no-book";
                                    write << id << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
                                }
                                else{
                                    flag=1;
                                    write << id << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
                                    cout << "\nStudent does not have a book.";
                                }
                                }
                                else if(choice==3){
                                    if(book3.compare("no-book")!=0){
                                        flag=1;
                                        testBook(book3);
                                        book3 = "no-book";
                                        write << id << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
                                    }
                                    else{
                                        flag=1;
                                        write << id << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
                                        cout << "\nStudent does not have a book.";
                                    }
                                } 
                                else{
                                    cout << "\nInvalid Choice";
                                    write << id << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
                                }
                        }
                    // } 
                }
                else {
                         write << id << " " << sname << " " << dept << " " << grade << " " << div << " " << book1 << " " << book2 << " " << book3 << endl;
                    }
                read >> id;
                read >> sname;
                read >> dept;
                read >> grade;
                read >> div;
                read >> book1;
                read >> book2;
                read >> book3;
                }
                write.close();
                read.close();
                remove("student.txt");
                rename("temp.txt","student.txt");
            if (flag==0){
                cout << "\nNothing Pending Congrats!\n\n\n\n\n\n";
            }

        }
                        }
                
                    };



int main(){
    Student stud;
    Book book;
    Librarian lib;

    int cid,flag=0,sid,bid;
    int loop = 0,a,b,c,d,e,f;
    system("clear");
    while (loop == 0){
        cout << "\nLibrary Managment System";
        cout << "\n1) Book";
        cout << "\n2) Librarian";
        cout << "\n3) Student ";
        cout << "\n4) Issue a Book";
        cout << "\n5) Return a Book";
        cout << "\nExit(0)";
        cout << "\nWhat would you like to do?: ";
        cin >> a;
     if (a==1){
        cout << "\nBook Info";
        cout << "\nAdd Data (1)";
        cout << "\nView Data(2)";
        cout << "\nModify Data(3)";
        cout << "\nDelete Data(4)";
        cout << "\nExit(0)";
        cout << "\nWhat would you like to do?: ";
        cin >> b;
        if(b==1){
            book.gatherData();
            book.write();
        } else if(b==2){
            book.displaydata();
        } else if (b==3){
            book.updateData();
        } else if (b==4){
            book.deleteData();
        }
    } else if(a==2){
        cout << "\nLibrarian Info";
        cout << "\nAdd Data(1)";
        cout << "\nView Data(2)";
        cout << "\nModify Data(3)";
        cout << "\nDelete Data(4)";
        cout << "\nExit(0)";
        cout << "\nWhat would you like to do?: ";
        cin >> b;
        if(b==1){
            lib.gatherData();
            lib.write();
        } else if(b==2){
            lib.displaydata();
        } else if (b==3){
            lib.updateData();
        } else if (b==4){
            lib.deleteData();
        }

    } else if(a==3){
        cout << "\nStudent Information";
        cout << "\nAdd Data(1)";
        cout << "\nView Data(2)";
        cout << "\nModify Data(3)";
        cout << "\nDelete Data(4)";
        cout << "\nExit(0)";
        cout << "\nWhat would you like to do?: ";
        cin >> b;
        if(b==1){
            stud.gatherData();
            stud.write();
        } else if(b==2){
            stud.displaydata();
        } else if (b==3){
            stud.updateData();
        } else if (b==4){
            stud.deleteData();
        }
    } else if(a==4){

        cout << "\nEnter Student ID: ";
        cin >> sid;
        f = stud.checkStudent(sid);
        if(f==123){
             cout << "\nStudent already has max number of books.\n";
        } else { 
        if (f==123)
        cout << "\nBooks Available: ";
        book.displaydata();
        cout << "\nEnter the ID of the book you have to issue: ";
        cin >> bid;
        d = book.updateBook(bid);
        if(d==404){
            cout << "\nOut of copies.";
        } else {
        stud.updateStudent(sid,bid);
        }
        }
    } else if(a==5){
        cout << "\nEnter Student ID: ";
        cin >> sid;
        stud.testStudent(sid);
        }
    else if(a==0){
    break;
    } else {
        cout << "\nInvalid Input. Please Try again";
    }
    }


}   