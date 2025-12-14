#include "MainMenu.h"
#include"../core/UserManager.h"
#include"../core/BookManager.h"
#include<iostream>
#include<stdlib.h>
#include<fstream>
int choice = 4;
//Begin Surface
void MainMenu::show(){
    
    
    do{
        std::cout<<"***LIBRARY***\n";
        std::cout<<"May the Light of Wisdom Cast on You\n";
        std::cout<<"Input corresponding number in front of the step you want to take next\n";
        std::cout<<"1.Home\n";
        std::cout<<"2.Explore\n";
        std::cout<<"3.Borrow & Return\n";
        std::cout<<"4.Leave\n";
        std::cin>>choice;

        switch(choice){
            case 1: UserSurface(); break;
            case 2: std::cout<<"to be developed\n"; system("pause");system("cls");break;
            case 3: BookSurface(); break;
            case 4: std::cout<<"Even Now the Competitors are passing through pages.\n"; break;
            default:
                std::cout<<"Error Input!\n";break;
        }
    } while(choice != 4);
}

//User Surface
void MainMenu::UserSurface(){
    system("cls");
    int UserChoice;
    std::cout<<"1.Creat an account.\n";
    std::cout<<"2.Already have an account?\n";
    std::cout<<"3.Return to main menu\n";
    std::cin>>UserChoice;
    UserManipulation operater;
    switch(UserChoice){
        case 1:
            operater.creatUser();
            break;
        case 2:
            //Log in through this Account
            //Prepare for the VIP judge afterwards
            std::cout<<"Please input your Student ID:\n";
            long tempId;
            std::cin>>tempId;
            operater.showUserInfo(operater.searchUser(tempId));
            break;
        case 3:
            system("cls");
            show();
            break;
        default:
            std::cout<<"Error Input!\n";break;
    }
}

void MainMenu::BookSurface(){
    system("cls");
    Books funcBook;
    funcBook.UishowBook();
    int Userchoice;
    std::cout<<"1.Borrow a new book.\n";
    std::cout<<"2.Return.\n";
    std::cin>>Userchoice;
    switch(Userchoice){
        case 1:
            funcBook.BorrowNewBook();
            break;
        case 2:
            funcBook.ReturnBook();
            break;
        default:
            std::cout<<"Error Input!\n";
            break;
    }
}
