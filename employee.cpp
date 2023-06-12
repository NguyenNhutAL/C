/*
*File: employee.cpp
*Author: Nguyen Minh Nhut
*Date: 11/06/2023
*Description: manage hotel employee
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef enum{
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LUGGAGE_STAFF,
    GARDENER
}jobPosition;

typedef struct{
    uint16_t date;
    uint16_t month;
    uint16_t year;
}typeDate;

typedef struct{
    uint16_t second;
    uint16_t minute;
    uint16_t hour;
}typeTime;

typedef enum{
    IN,
    OUT
}typeStatus;

typedef struct{
    typeTime time;
    typeDate day;
    typeStatus status;
}Schedule;
/*
*Class: Employee
*Description: This class represents a basic implementation of a Empployee object.
*/
class Employee{
    private:
        string name;
        string phoneNumber;
        jobPosition position;
        Schedule schedule;
        uint16_t ID;
    public:
        Employee(string nameEmployee, string phoneNumberEmployee, jobPosition positionEmployee, Schedule scheduleEmployee);
        string getName();
        string getPhoneNumber();
        jobPosition getPosition();
        Schedule getSchedule();
        uint16_t getID();
        void setName(string name);
        void setPhoneNumber(string phoneNumber);
        void setPosition(jobPosition position);
        void setSchedule(Schedule schedule);
};
/*
*Contructor: Employee
*Discription: This constructor initializes a new instance of the Employee class.
*Input:
*   nameEmployee: name of employees
*   phoneNumberEmployee: phone numbers of employees
*   positionEmployee: work position of Employee
*   scheduleEmployee: schedule of Employee
*   output: none
*/
Employee::Employee(string nameEmployee, string phoneNumberEmployee, jobPosition positionEmployee, Schedule scheduleEmployee){
    Employee::name= nameEmployee;
    Employee::phoneNumber= phoneNumberEmployee;
    Employee::position= positionEmployee;
    Employee::schedule= scheduleEmployee;
    static uint16_t id=100;
    Employee::ID= id;
    id++;
    
}
/*
*Function: getName
*Description: This function returns name of current Employee
*Output: name of current Employee
*/
string Employee::getName(){
    return this->name;
}
/*
*Function: getPhoneNumber
*Description: This function returns phoneNumber of current Employee
*Output: phoneNumber of current Employee
*/
string Employee::getPhoneNumber(){
    return this->phoneNumber;
}
/*
*Function: getPosition
*Description: This function returns position of current Employee
*Output: position of current Employee
*/
jobPosition Employee::getPosition(){
    return this->position;
}
/*
*Function: getSchedule
*Description: This function returns schedule of current Employee
*Output: schedule of current Employee
*/
Schedule Employee::getSchedule(){
    return this->schedule;
}
/*
*Function: getID
*Description: This function returns id of current Employee
*Output: id of current Employee
*/
uint16_t Employee::getID(){
    return this->ID;
}
/*
*Function: setName
*Description: This function set name of current Employee
*Input:
    name: name of Employee
*Output: none
*/
void Employee::setName(string name){
    this->name=name;
}
/*
*Function: setPhoneNumber
*Description: This function set phone number of current Employee
*Input:
    phone number: phone number of Employee
*Output: none
*/
void Employee::setPhoneNumber(string phoneNumber){
    this->phoneNumber= phoneNumber;
}
/*
*Function: setPosition
*Description: This function set position of current Employee
*Input:
    position: work position of Employee
*Output: none
*/
void Employee::setPosition(jobPosition position){
    this->position= position;
}
/*
*Function: setSchedule
*Description: This function set work schedule of current Employee
*Input:
    schedule: work schedule of Employee
*Output: none
*/
void Employee::setSchedule(Schedule schedule){
    this->schedule= schedule;
}
/*
*Class: EmployeeManager
*Description: This class include mothods to manage employees.
*/
class EmployeeManager{
    private:
        vector<Employee> databaseEmployee;
    public:
        EmployeeManager();
        void addEmployee();
        void removeEmployee();
        void updateEmployee();
        void displayEmployee();
};
/*
*Function: addEmployee
*Description: This function add new Employee into list
*Input:none
*Output: none
*/
void EmployeeManager::addEmployee(){
    string name;
    string phoneNumber;
    jobPosition position;
    Schedule schedule;
    cout<<"Nhap ten nhan vien: "; cin>>name;
    cout<<"Nhap so dien thoai: "; cin>>phoneNumber;
    int positionOption=7;
    while(positionOption<0 or positionOption>6){
        cout<<"Nhap so tuong ung de chon vi tri cong viec: "<<endl;
        cout<<"1. Nhan vien bao ve"<<endl;
        cout<<"2. Nhan vien le tan"<<endl;
        cout<<"3. Nhan vien don dep"<<endl;
        cout<<"4. Nhan vien hanh ly"<<endl;
        cout<<"5. Nhan vien lam vuon"<<endl;
        cout<<"Lua chon cua ban: "; cin>>positionOption;
        switch(positionOption){
            case 1: position= JANITOR;
                break;
            case 2: position= RECEPTIONIST;
                break;
            case 3: position= LAUNDRY_STAFF;
                break;
            case 4: position= LUGGAGE_STAFF;
                break;
            case 5: position= GARDENER;
            default: break;
        }
    }
    cout<<"Nhap lich trinh lam viec: "<<endl;
    do{
        cout<<"Ngay lam viec (date/month/year): "<<endl;
        cin>>schedule.day.date>>schedule.day.month>>schedule.day.year;
    } while(schedule.day.date>31 || schedule.day.month>12);

    do{
        cout<<"Gio lam viec (hour/minute/second): "<<endl;
        cin>>schedule.time.hour>>schedule.time.minute>>schedule.time.second;
    } while(schedule.time.hour>12 || schedule.time.minute>59 || schedule.time.minute>59);

    Employee newEmployee(name, phoneNumber, position, schedule);
    databaseEmployee.push_back(newEmployee);
    cout<<"Da them nhan vien vao danh sach"<<endl;
}
/*
*Function: removeEmployee
*Description: This function remove Employee from list
*Input:none
*Output: none
*/
void EmployeeManager::removeEmployee(){
    uint16_t id_remove;
    cout<<"Nhap id can xoa: "; cin>>id_remove;
    for(uint8_t i=0; i<databaseEmployee.size(); i++){
        if(id_remove== databaseEmployee[i].getID()){
            databaseEmployee.erase(databaseEmployee.begin()+i);
            cout<<"Da xoa nhan vien co id: "<<id_remove<<endl;
        }
    }
}
/*
*Function: updateEmployee
*Description: This function update informative Employee into list
*Input:none
*Output: none
*/
void EmployeeManager::updateEmployee(){
    uint16_t id_update;
    cout<<"Nhap id nhan vien can update: "; cin>>id_update;
    for(uint8_t i=0; databaseEmployee.size(); i++){
        if(id_update== databaseEmployee[i].getID()){
            string name;
            string phoneNumber;
            jobPosition position;
            Schedule schedule;
            cout<<"Nhap ten nhan vien: "; cin>>name;
            databaseEmployee[i].setName(name);
            cout<<"Nhap so dien thoai: "; cin>>phoneNumber;
            databaseEmployee[i].setPhoneNumber(phoneNumber);
         int positionOption=8;
            while(positionOption<0 || positionOption>6){
                cout<<"Nhap so tuong ung de chon vi tri cong viec: "<<endl;
                cout<<"1. Nhan vien bao ve"<<endl;
                cout<<"2. Nhan vien le tan"<<endl;
                cout<<"3. Nhan vien don dep"<<endl;
                cout<<"4. Nhan vien hanh ly"<<endl;
                cout<<"5. Nhan vien lam vuon"<<endl;
                cout<<"Lua chon cua ban: "; cin>>positionOption;
                switch(positionOption){
                    case 1: position= JANITOR;
                        break;
                    case 2: position= RECEPTIONIST;
                        break;
                    case 3: position= LAUNDRY_STAFF;
                        break;
                    case 4: position= LUGGAGE_STAFF;
                        break;
                    case 5: position= GARDENER;
                    default: break;
                }
           }
           databaseEmployee[i].setPosition(position);
            cout<<"Nhap lich trinh lam viec: "<<endl;
            do{
                cout<<"Ngay lam viec (date/month/year): "<<endl;
                cin>>schedule.day.date>>schedule.day.month>>schedule.day.year;
            } while(schedule.day.date>31 || schedule.day.month>12);

            do{
                cout<<"Gio lam viec (hour/minute/second): "<<endl;
                cin>>schedule.time.hour>>schedule.time.minute>>schedule.time.second;
            } while(schedule.time.hour>12 || schedule.time.minute>59 || schedule.time.minute>59);
            databaseEmployee[i].setSchedule(schedule);
            cout<<"Da update"<<endl;
        }
    }
}
/*
*Function: displayEmployee
*Description: This function display list of Employees
*Input:none
*Output: none
*/
void EmployeeManager::displayEmployee(){
    cout<<"---------Danh sach nhan vien------------"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"| ID  |  Ten  |    SDT     |  Vi tri lam viec |"<<endl;
    string position;
    for(auto x: databaseEmployee){
        if(x.getPosition()== JANITOR)   position= "Nhan vien bao ve";
        else if(x.getPosition()== RECEPTIONIST) position= "Nhan vien le tan";
        else if(x.getPosition()== LAUNDRY_STAFF)    position="Nhan vien don dep";
        else if(x.getPosition()== LUGGAGE_STAFF)    position="Nhan vien hanh ly";
        else position="Nhan vien lam vuon";
        cout<<"| "<<x.getID()<<" | "<<x.getName().c_str()<<"  | "<<x.getPhoneNumber().c_str()<<" | "<<position<<"|"<<endl;
        cout<<"----------------------------------------"<<endl;
    }
}
/*
*Constructor: EmployeeManager
*Description: This function offer option to manage Employees
*Input:none
*Output: none
*/
EmployeeManager::EmployeeManager(){
    uint16_t option= 10;
    while(option != 0){
        cout<<"1. Them nhan vien"<<endl;
        cout<<"2. Xoa nhan vien"<<endl;
        cout<<"3. Sua thong tin nhan vien"<<endl;
        cout<<"4. In danh sach nhan vien"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Lua chon cua ban: "; cin>>option;
        switch(option){
            case 1: addEmployee();
                break;
            case 2: removeEmployee();
                break;
            case 3: updateEmployee();
                break;
            case 4: displayEmployee();
                break;
            default:
                break;
        }
    }
}
int main(){
    EmployeeManager process;
    return 0;
}
