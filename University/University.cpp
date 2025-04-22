#include<iostream>
#include <string>
using namespace std;
class University{
    protected:
    string branch_name;
    string coordinator_name;
    int student_count;
    public:
    University(){
        branch_name="Unknown";
        coordinator_name="Unknown";
        student_count=0;
    }
    University(string n,string y):branch_name(n),coordinator_name(y){}
    virtual void display(){
        cout<<branch_name;
        cout<<coordinator_name;
        cout<<student_count;
    }
    void show_count(int count){
        student_count=count;
        
    }
    void show_count(int count,int increase){
        student_count+=increase;
    }
    
};

class Student:public University{
    protected:
    string name;
    int roll;
    public:
    Student():University(){}
    Student(int n,string name,string y,string c):University(y,c),name(name),roll(n){}
    void show(){
       cout<<this->name;
       cout<<roll;
       display();
    }
};

class GraduateStudent : public Student {
private:
    string thesis_title;

public:
    GraduateStudent() : Student() {}

    GraduateStudent(int n, string student_name, string branch, string coordinator, string thesis)
        : Student(n, student_name, branch, coordinator), thesis_title(thesis) {}

    void show() {
        Student::show();  
        cout << "Thesis Title: " << thesis_title << endl;
    }
};
class SportsTeam {
protected:
    string team_name;
    int team_members;

public:
    SportsTeam() : team_name("Unknown"), team_members(0) {}

    SportsTeam(string t, int m) : team_name(t), team_members(m) {}

    void display_team() {
        cout << "Team Name: " << team_name << endl;
        cout << "Team Members: " << team_members << endl;
    }
};
class SportsStudent : public Student, public SportsTeam {
private:
    string sport_name;

public:
    SportsStudent(int n, string student_name, string branch, string coordinator, string sport, string team, int members)
        : Student(n, student_name, branch, coordinator), SportsTeam(team, members), sport_name(sport) {}

    void show() {
        Student::show(); 
        cout << "Sport: " << sport_name << endl;
        display_team(); 
    }
};
class Faculty : public University {
private:
    string faculty_name;
    string subject;
    int experience;

public:
    Faculty() : University(), faculty_name("Unknown"), subject("Unknown"), experience(0) {}

    Faculty(string name, string sub, int exp, string branch, string coordinator)
        : University(branch, coordinator), faculty_name(name), subject(sub), experience(exp) {}

    void show() {
        cout << "Faculty Name: " << faculty_name << endl;
        cout << "Subject: " << subject << endl;
        cout << "Experience: " << experience << " years" << endl;
        display();
    }
};
int main() {
    Student s1(101, "Saksham", "Computer Science", "Dr. Smith");
    cout << "Student Info:" << endl;
    s1.show();
    cout << "\n\n";
    GraduateStudent g1(202, "Priyansh", "Physics", "Dr. Hardev", "Quantum Computing");
    cout << "Graduate Student Info:" << endl;
    g1.show();
    cout << "\n\n";

    SportsStudent ss1(303, "Mohit", "Mechanical", "Dr. Arun", "Football", "WildCats", 11);
    cout << "Sports Student Info:" << endl;
    ss1.show();
    cout << "\n\n";
      Faculty f1("Dr. Arun", "Artificial Intelligence", 10, "Computer Science", "Dr. Smith");
    cout << "Faculty Info:\n";
    f1.show();
    cout << "\n\n";
    cout << "Updating student count using overloaded functions:" << endl;
    s1.show_count(100);  
    s1.show_count(100, 25);  
    s1.display();
    cout << "\n";

    return 0;
}
