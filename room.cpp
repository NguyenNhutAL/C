#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
*Class: Room
*Description: This class represents a basic implementation of a room object.
*/
class Room{
    private: 
        uint16_t roomNumber;
        bool isBooked;
        bool isCleaning;
    public:
        Room(uint16_t number);
        uint16_t getRoomNumber();
        void setRoomNumber(uint16_t roomNumber);
        bool isAvailable();
        bool bookRoom();
        void checkIn(); 
        void checkOut();
};
/*
*Contructor: Room
*Discription: This constructor initializes a new instance of the room class.
*Input:
*   number: room number
*   output: none
*/
Room::Room(uint16_t number){
    roomNumber= number;
    isBooked= false;
    isCleaning= true;
}
/*
*Function: getRoomNumber
*Description: This function returns number of room
*Output: number of room
*/
uint16_t Room::getRoomNumber(){
    return this->roomNumber;
}
/*
*Function: setRoomNumber
*Description: This function set number of room
*Input:roomNumber: number of room
*Output: none
*/
void Room::setRoomNumber(uint16_t roomNumber){
    this->roomNumber= roomNumber;
}
/*
*Function: isAvailable
*Description: This function set number of room
*Input:roomNumber: number of room
*Output: none
*/
bool Room::isAvailable(){
    return !isBooked && !isCleaning;
}
/*
*Function: bookRoom
*Description: This function returns status of room
*Input:none
*Output: status of room
*/
bool Room::bookRoom(){
    return isBooked= true;
}
/*
*Function: checkIn
*Description: This function check in room
*Input:none
*Output: none
*/
void Room::checkIn(){
    isCleaning= false;
    isBooked= true;
}
/*
*Function: bookRoom
*Description: This function check out room
*Input:none
*Output: status of room
*/
void Room::checkOut(){
    isCleaning= true;
    isBooked= false;
}
/*
*Class: HotelManager
*Description: This class includes methods to manage hotel.
*/
class HotelManager{
    private:
        vector<Room> databaseRoom;
        void displayAvailableRoom();
        void setRoom();
        void bookRoom(uint16_t roomNumber);
        void checkIn(uint16_t roomNumber);
        void checkOut(uint16_t roomNumber);
    public:
        HotelManager();
};
/*
*Contructor: HotelManager
*Discription: This constructor offer options of the hotelmanager class.
*Input:
*   number: room number
*   output: none
*/
HotelManager::HotelManager(){
    uint16_t option=10;
    while(option!= 0){
        cout<<"1.Dat so luong phong"<<endl;
        cout<<"2.Danh sach phong trong"<<endl;
        cout<<"3.Dat phong"<<endl;
        cout<<"4.check in"<<endl;
        cout<<"5.check out"<<endl;
        cout<<"0.Thoat"<<endl;
        cout<<"Lua chon cua ban: "; cin>>option;
        switch(option){
            case 1: this->setRoom(); break;
            case 2: displayAvailableRoom(); break;
            case 3: 
                uint16_t roomNumber_set;
                cout<<"Nhap so phong: "; cin>>roomNumber_set;
                this->bookRoom(roomNumber_set);
                break;
            case 4:
                uint16_t roomNumber_checkin;
                cout<<"Nhap so phong: "; cin>>roomNumber_checkin;
                this->checkIn(roomNumber_checkin);
                break;
            case 5:
                uint16_t roomNumber_checkout;
                cout<<"Nhap so phong: "; cin>>roomNumber_checkout;
                this->checkOut(roomNumber_checkout);
                break;
            default: break;
        }
    }
}
/*
*Function: setRoom
*Description: This function set quality of room
*Input:none
*Output: none
*/
void HotelManager::setRoom(){
    uint16_t roomQuality;
    cout<<"Nhap so luong phong"; cin>>roomQuality;
    for(uint16_t i=0; i<roomQuality; i++){
        Room newroom(i);
        databaseRoom.push_back(newroom);
    }
}
/*
*Function: displayAvailableRoom
*Description: This function display available rooms
*Input:none
*Output: none
*/
void HotelManager::displayAvailableRoom(){
    cout<<"---------Danh sach phong trong----------"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"| Phong | ";
    for(Room room: databaseRoom){
        cout<<room.getRoomNumber()<<" | ";
    }
    cout<<"\n----------------------------------------"<<endl;
    cout<<"|Da don | ";
    for(Room room : databaseRoom){   
        string cleanRoom;
        if(room.isAvailable() == true) cleanRoom = "x";
        else cleanRoom = "o";
         cout<<cleanRoom<<" | ";
    }
    cout<<"\n----------------------------------------"<<endl;
    cout<<"|Da dat | ";
    for(Room room : databaseRoom){   
        string cleanRoom;
        if(room.bookRoom() == true) cleanRoom = "x";
        else cleanRoom = "o";
         cout<<cleanRoom<<" | ";
    } cout<<"\n";
}
/*
*Function: bookroom
*Description: This function book a room in hotel
*Input:none
*Output: none
*/
void HotelManager::bookRoom(uint16_t roomNumber){
    for(uint16_t i=0; i<databaseRoom.size(); i++){
        if(databaseRoom[i].getRoomNumber()== roomNumber){
            databaseRoom[i].bookRoom();
            cout<<"Da dat"<<endl;
        }
    }
}
/*
*Function: checkIn
*Description: This function check in hotel
*Input:none
*Output: none
*/
void HotelManager::checkIn(uint16_t roomNumber){
    for(uint16_t i=0; i<databaseRoom.size(); i++){
        if(databaseRoom[i].getRoomNumber()== roomNumber){
            databaseRoom[i].checkIn();
            cout<<"Da check in"<<endl;
        }
    }
}
/*
*Function: checkout
*Description: This function check out in hotel
*Input:none
*Output: none
*/
void HotelManager::checkOut(uint16_t roomNumber){
    for(uint16_t i=0; i<databaseRoom.size(); i++){
        if(databaseRoom[i].getRoomNumber()== roomNumber){
            databaseRoom[i].checkOut();
            cout<<"Da check out"<<endl;
        }
    }
}
int main(){
    HotelManager a;  
}