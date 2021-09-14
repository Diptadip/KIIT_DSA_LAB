#include <iostream>
using namespace std;

class Student
{
    private:
        char name[30];
        int  age;
        int roll;
    public:
        void get_data(void);
        void put_data(void);
};
 

void Student::get_data(void)
{
    cout << "Enter information:" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Roll: ";
    cin >> roll;
}
 
void Student::put_data(void)
{
    cout <<"Details of the student\n";
    cout << "Name: " << name <<"\n"<< "Roll: " << roll <<"\n" << "Age: " << age << endl;
}

class Test:public Student
{
    public:
        int sub1,sub2,sub3,sub4,sub5;
    public:
        void get_info(void);
        void put_info(void);
};

void Test::get_info(void)
{
   cout <<"Enter marks in 5 subjects: \n";
   cin >>sub1>>sub2>>sub3>>sub4>>sub5;
}
 
void Test::put_info(void)
{
   cout <<sub1<<endl;
   cout <<sub2<<endl;
   cout <<sub3<<endl;
   cout <<sub4 <<endl;
   cout <<sub5<<endl;
}
 
class Result:public Test
{
protected:
    int total;
    float percentage;
public:
    void get_result()
    {
        total=sub1+sub2+sub3+sub4+sub5;
		float t=static_cast<float>(total);
		cout<<t<<endl;
        percentage=(static_cast<float>(total)/5.0);
        cout <<"Total marks: " <<total<<endl;
        cout <<"Percentage: " <<percentage;
    }
};
 
 
int main()
{
    Result t;
    t.get_data();
    t.get_info();
    t.put_data();
    t.put_info();
    t.get_result();

    return 0;
}