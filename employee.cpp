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

Employee::Employee(string nameEmployee, string phoneNumberEmployee, jobPosition positionEmployee, Schedule scheduleEmployee){
    Employee::name= nameEmployee;
    Employee::phoneNumber= phoneNumberEmployee;
    Employee::position= positionEmployee;
    Employee::schedule= scheduleEmployee;
    static uint16_t id=100;
    Employee::ID= id;
    id++;
    
}

string Employee::getName(){
    return this->name;
}

string Employee::getPhoneNumber(){
    return this->phoneNumber;
}

jobPosition Employee::getPosition(){
    return this->position;
}

Schedule Employee::getSchedule(){
    return this->schedule;
}

uint16_t Employee::getID(){
    return this->ID;
}

void Employee::setName(string name){
    this->name=name;
}
void Employee::setPhoneNumber(string phoneNumber){
    this->phoneNumber= phoneNumber;
}
void Employee::setPosition(jobPosition position){
    this->position= position;
}
void Employee::setSchedule(Schedule schedule){
    this->schedule= schedule;
}
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