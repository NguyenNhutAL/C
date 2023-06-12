#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>
using namespace std;

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
}bookingHistorys;
/*
*Class: Customer
*Description: This class represents a basic implementation of a customer object.
*/
class Customer{
    private:
        uint16_t idRoom;
        string name;
        string phoneNumber;
        string address;
        vector <bookingHistorys> bookingHistory;
    public:
        Customer(string customerName, string customerPhone, string customerAddress);
        string getName();
        void setName(string name);
        string getPhoneNumber();
        void setPhoneNumber(string phoneNumber);
        string getAddress();
        void setAddress(string address);
        uint16_t getIdRoom();
        void setIdRoom(uint16_t idRoom);
        void addBookingHistory();
        void displayBookingHistory();
};
/*
*Contructor: Customer
*Discription: This constructor initializes a new instance of the customer class.
*Input:
*   customerName: name of Customer
*   customerPhone: phone numbers of Customer
*   customerAddress: work position of Customer
*   output: none
*/
Customer::Customer(string customerName, string customerPhone, string customerAddress){
    Customer::name= customerName;
    Customer::phoneNumber= customerPhone;
    Customer::address= customerAddress;
    static uint16_t id=100;
    Customer::idRoom =id;
    id++;
}
/*
*Function: getName
*Description: This function returns name of current customer
*Output: name of current customer
*/
string Customer::getName(){
    return this->name;
}
/*
*Function: setName
*Description: This function set name of current customer
*Input:
    name: name of customer
*Output: none
*/
void Customer::setName(string name){
    this->name= name;
}
/*
*Function: getPhoneNumber
*Description: This function returns phone number of current customer
*Output: phone number of current customer
*/
string Customer::getPhoneNumber(){
    return this->phoneNumber;
}
/*
*Function: setPhoneNumber
*Description: This function set phone number of current customer
*Input:
    phonenumber: phone number of customer
*Output: none
*/
void Customer::setPhoneNumber(string phoneNumber){
    this->phoneNumber= phoneNumber;
}
/*
*Function: getAddress
*Description: This function returns address of current customer
*Output: address of current customer
*/
string Customer::getAddress(){
    return this->address;
}
/*
*Function: setAddress
*Description: This function set address of current customer
*Input:
    address: address of customer
*Output: none
*/
void Customer::setAddress(string address){
    this->address= address;
}
/*
*Function: getIdRoom
*Description: This function returns id of current customer
*Output: id of current customer
*/
uint16_t Customer::getIdRoom(){
    return this->idRoom;
}
/*
*Function: addBookingHistory
*Description: This function add booking history of customers
*Input: none
*Output: none
*/
void Customer::addBookingHistory(){
    bookingHistorys bookingDetail;
    bookingDetail.status= (bookingDetail.status== IN) ? IN : OUT;
    do{
        cout<<"Ngay khach hang nhan/tra phong(date/month/year): "<<endl;
        cin>>bookingDetail.day.date>>bookingDetail.day.month>>bookingDetail.day.year;
    } while(bookingDetail.day.date>31 || bookingDetail.day.month>12);
    do{
        cout<<"Thoi gian khach hang nhan/tra phong(gio/phut/giay): "<<endl;
        cin>>bookingDetail.time.hour>>bookingDetail.time.minute>>bookingDetail.time.second;
    }while(bookingDetail.time.hour>12 || bookingDetail.time.minute>59 || bookingDetail.time.second>59);
    bookingHistory.push_back(bookingDetail);
}
/*
*Function: displayBookingHistory
*Description: This function display booking history of customers
*Input: none
*Output: none
*/
void Customer::displayBookingHistory(){
    cout<<"---------------Lich su dat phong---------------"<<endl;
    cout<<"---------------------------------"<<endl;
    for(auto x:bookingHistory){
        if(x.status== IN)
        cout<<"| Trang thai     |"<<" IN"<<endl;
        else
        cout<<"| Trang thai     |"<<" OUT"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"| Ngay/thang/nam | "<<x.day.date<<"/"<<x.day.month<<"/"<<x.day.year<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"| Gio/phut/giay  | "<<x.time.hour<<"/"<<x.time.minute<<"/"<<x.time.second<<endl;
        cout<<"---------------------------------"<<endl;
        
    }
}
/*
*Class: CustomerManager
*Description: This class include mothods to take care of customers
*/
class CustomerManager{
    private:
        vector <Customer> databaseCustomer;
    public:
        CustomerManager();
        void addCustomer();
        void editCustomer();
        void deleteCustomer();
        void displayCustomerInfor();
};
/*
*Function: addCustomer
*Description: This function add new customers into list
*Input:none
*Output: none
*/
void CustomerManager::addCustomer(){
    string name;
    string phone;
    string address;
    cout<<"Nhap ten khach hang moi: "; cin>>name;
    cout<<"Nhap sdt khach hang moi: "; cin>>phone;
    cout<<"Nhap dia chi khach hang: "; cin>>address;
    Customer newCustomer(name, phone, address);
    databaseCustomer.push_back(newCustomer);
    cout<<"Da them thanh cong"<<endl;
}
/*
*Function: editCustomer
*Description: This function edit customers from list
*Input:none
*Output: none
*/
void CustomerManager::editCustomer(){
    uint16_t id;
    string newName;
    string newPhone;
    string newAddress;
    cout<<"Nhap id khach hang can sua thong tin: "; cin>>id;
    for(uint8_t i=0; i<databaseCustomer.size();i++){
        if(id== databaseCustomer[i].getIdRoom()){
            cout<<"Nhap ten khach hang can sua: "; cin>>newName;
            databaseCustomer[i].setName(newName);
            cout<<"Nhap sdt khach hang can sua: "; cin>>newPhone;
            databaseCustomer[i].setPhoneNumber(newPhone);
            cout<<"Nhap dia chi khach hang can sua: "; cin>>newAddress;
            databaseCustomer[i].setAddress(newAddress);
            cout<<"Da sua thong tin khach hang"<<endl;
        }
    }
}
/*
*Function: deleteCustomer
*Description: This function delete customers from list
*Input:none
*Output: none
*/
void CustomerManager::deleteCustomer(){
uint16_t id_delete;
cout<<"Nhap id khach hang can xoa: "; cin>>id_delete;
    for(uint8_t i=0; i<databaseCustomer.size();i++){
        if(id_delete== databaseCustomer[i].getIdRoom()){
            databaseCustomer.erase(databaseCustomer.begin()+i);
            cout<<"Da xoa thanh cong"<<endl;
        }
    }
}
/*
*Function: displayCustomer
*Description: This function display customers in list
*Input:none
*Output: none
*/
void CustomerManager::displayCustomerInfor(){
    cout<<"----Thong Tin Khach Hang----"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"| ID |   Ten   |    sdt     |  Dia Chi  |"<<endl;
    cout<<"----------------------------------------"<<endl;
    for(auto x:databaseCustomer){
        cout<<"| "<<x.getIdRoom()<<"|  "<<x.getName().c_str()<<"   | "<<x.getPhoneNumber().c_str()<<" | "<<x.getAddress().c_str()<<" |"<<endl;
        cout<<"----------------------------------------"<<endl;
    }
}
/*
*construction: CustomerManager
*Description: This construction includes options to take care of customer
*Input:none
*Output: none
*/
CustomerManager::CustomerManager(){
    cout<<"--------abcd----------"<<endl;
    int n=10;
    while(n!=0){
        cout<<"1. Them khach hang"<<endl;
        cout<<"2. Sua khach hang"<<endl;
        cout<<"3. Xoa khach hang"<<endl;
        cout<<"4. In thong tin khach hang"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Lua chon cua ban: "; cin>>n;
        switch(n){
            case 1: addCustomer();
            break;
            case 2: editCustomer();
            break;
            case 3: deleteCustomer();
            break;
            case 4: displayCustomerInfor();
            break;
            default: break;
        }
    }
}
int main(){
    CustomerManager cm;
    return 0;
}