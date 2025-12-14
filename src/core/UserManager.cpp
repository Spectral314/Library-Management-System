#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include"UserManager.h"
#include<unordered_map>

int User::count = 0;
User* currentUser = nullptr;
//Show an Account
//Through struct
void UserManipulation::showUserInfo(User* Userptr){
    if (Userptr == nullptr){
        std::cout<<"Sorry! The account does not existed.\n";
        system("pause");
        system("cls");
        return ;
    }

    std::cout<<"Log in Successfully!\n";
    std::cout<<"Name: "<<Userptr->name<<std::endl;
    std::cout<<"Gender: "<<Userptr->gender<<std::endl;
    std::cout<<"Student ID: "<<Userptr->numberation<<std::endl;
    std::cout<<"Have not returned: "<<Userptr->HaveBook<<std::endl;
    currentUser = Userptr;
    system("pause");
    system("cls");
}

//Creat a new Account
void UserManipulation::creatUser(){
    std::cin.ignore();
    // Actually sort the ID before output
    User newUser;
    std::cout<<"Please enter your Username: \n";
    std::getline(std::cin,newUser.name);
    
    std::cout<<"Please choose your Gender(M/F): \n";
    std::getline(std::cin,newUser.gender);
    
    std::cout<<"Please enter your Student ID: ";
    std::cin>>newUser.numberation;
    //Check whether the Account is existed
    if(searchUser(newUser.numberation) != nullptr){
        std::cout<<"Congratulations!\n";
        std::cout<<"The ID has been created."<<std::endl;
        system("pause");
        system("cls");
        return;
    }

    newUser.HaveBook = 0;
    newUser.count ++;
    newUser.memberyet = 0;
    //Hash Table
    UserMap[newUser.numberation] = newUser;
    
    std::ofstream inUserfile("DataBase/UserInfo.txt",std::ios::app);
    inUserfile<<newUser.numberation<<","<<newUser.name<<","<<newUser.gender<<","<<newUser.HaveBook<<","<<newUser.memberyet<<"\n";
    inUserfile.close();
    std::cout<<"Append Successfully!\n";
    system("pause");
    system("cls");
}

//Search an already existed Account
User* UserManipulation::searchUser(const long stringn){
    loadFromFile();
    auto it = UserMap.find(stringn);
    if (it != UserMap.end()) {
            return &(it->second);  // 找到，返回指针
        }
        return nullptr;  // 没找到
}

//Load data from file to Hash Table
void UserManipulation::loadFromFile() {
        std::ifstream file("DataBase/UserInfo.txt");
        std::string line;
        while(getline(file,line)){
            std::stringstream ss(line);
            std::string token;
            User userInfo;
            if(getline(ss,token,','))
                userInfo.numberation = std::stol(token);
            else continue;
            if(getline(ss,token,','))
                userInfo.name = token;
            else continue;
            if(getline(ss,token,','))
                userInfo.gender = token;
            else continue;
            if(getline(ss,token,','))
                userInfo.HaveBook = std::stoi(token);
            else continue;
            if(getline(ss,token,','))
                userInfo.memberyet = std::stoi(token);
            else continue;
            UserMap[userInfo.numberation] = userInfo;
        }
}