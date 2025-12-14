#include"BookManager.h"
#include"UserManager.h"
#include"../ui/MainMenu.h"
#include <stdexcept>
#include <cstdlib>
#include<vector>
#include<sstream>
// Ensure the external variable declared in MainMenu.h is visible here
extern int choice;
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
void Books::UishowBook(){
    std::cout<<"Books are the ladder of human progress.\n";
    std::ifstream file("DataBase/BookInfo.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
} 

void Books::showBook(Books* certainBook){
    if(certainBook == nullptr){
        char ch;
        std::cout<<"Sorry! We don't have this book.\n";
        std::cout<<"Find another book? Y/N\n";
        std::cin>>ch;
        if(ch == 'Y'){
            choice = 6;
            return;
        }
        else if(ch == 'N'){
            choice = 4;
            return ;
        }
        else{
            choice = 5;
            std::cout<<"Error Input!\n";
            return;
        }
    }
    std::cout<<"Title: "<<certainBook->title<<std::endl;
    std::cout<<"Author: "<<certainBook->author<<std::endl;
    std::cout<<"Volume Left: "<<certainBook->volume<<std::endl;
    return ;
}

// Load data from file to Hash Table
void Books::loadFromfile(int method){
    std::ifstream file("DataBase/BookInfo.txt");
    std::string line;
    while(getline(file,line)){
        std::stringstream ss(line);
        std::string token;
        Books abook;
        if(getline(ss,token,','))
            abook.title = token;
        else continue;
        if(getline(ss,token,','))
            abook.author = token;
        else continue;
        if(getline(ss,token,','))
            abook.volume = std::stoi(token);
        else continue;
        if(getline(ss,token,','))
            abook.ForVip = stoi(token);
        else continue;
        if(method == 1)
            BooksMap[abook.title] = abook;
        if(method == 2)
            BooksMap[abook.author] = abook;
    }
}

//search for the book
Books* Books::searchBook1(std::string BookTitle){
    loadFromfile(1);
    auto it = BooksMap.find(BookTitle);
    if(it != BooksMap.end()){
        return &(it->second);
    }
    return nullptr;
}
Books* Books::searchBook2(std::string AuthorName){
    loadFromfile(2);
    auto it = BooksMap.find(AuthorName);
    if(it != BooksMap.end()){
        return &(it->second);
    }
    return nullptr;
}

void Books::BorrowNewBook(){
    std::cin.ignore();
    Books BorrowBook;
    std::cout<<"Search through Title/Author (with T/A front)\n";
    std::cout<<"Eg: TOne Hundred Years of Solitude \n"<<"AGarcia Marquez\n";
    std::string BookInput;
    std::getline(std::cin,BookInput);
    if(BookInput[0]=='T'){
        int len = BookInput.length();
        std::string title = BookInput.substr(1,len-1);
        BorrowBook.showBook(BorrowBook.searchBook1(title));
        if(choice == 4||choice == 5) return;
        else if(choice == 6) BorrowBook.BorrowNewBook();
        else{
            BorrowBook.loadFromfile(1);
            char ch;
            std::cout<<"You wanna borrow this book? Y/N\n";
            std::cin>>ch;
            if(ch == 'Y'){
                BorrowBook = *BorrowBook.searchBook1(title);
                if(BorrowBook.ForVip == 0 ||(BorrowBook.ForVip==1&&currentUser->memberyet==1))
                {
                    //执行藏本数量减一,并在BookInfo.txt中更新（未做）
                    BorrowBook.volume -= 1;
                    currentUser->HaveBook += 1;
                    std::cout<<"You've got it\n";
                    std::cout<<BorrowBook.title<<"Left: "<<BorrowBook.volume<<std::endl;
                }
                /*
                //将BookInfo更新重写，但是实在不会整
                std::fstream revise;
                revise.open("DataBase/BookInfo.txt",std::ios::out|std::ios::trunc);
                */
            }
            else if(ch == 'N')return ;
            else {std::cout<<"Error Input!\n";return ;}
        }
    }
    else if(BookInput[0]=='A'){
        int len = BookInput.length();
        std::string author = BookInput.substr(1,len-1);
        BorrowBook.showBook(BorrowBook.searchBook2(author));
        if(choice == 4||choice == 5) return;
        else if(choice == 6) BorrowBook.BorrowNewBook();
        else{
            BorrowBook.loadFromfile(2);
            char ch;
            std::cout<<"You wanna borrow this book? Y/N\n";
            std::cin>>ch;
            if(ch == 'Y'){
                BorrowBook = *BorrowBook.searchBook2(author);
                //执行藏本数量减一（未做）
                BorrowBook.volume -= 1;
                std::cout<<"You've got it\n";
                std::cout<<BorrowBook.title<<"Left: "<<BorrowBook.volume<<std::endl;
                system("pause");
                system("cls");
            }
            else if(ch == 'N')return ;
            else {std::cout<<"Error Input!\n";return ;}
        }
    }
    else {
        std::cout<<"Error Input!\n";
        system("pause");
        system("cls");
        return;
    }
}
void Books::ReturnBook(){}