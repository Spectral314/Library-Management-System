//BookManager.h
#ifndef BookManager
#define BookManager
#include<iostream>
#include<string>
#include<unordered_map>
class Books{
    private:
        std::string title;
        std::string author;
        int volume;
        bool ForVip;
        std::unordered_map<std::string,Books>BooksMap;
    public:
        void UishowBook();
        void showBook(Books* certainBook);
        void BorrowNewBook();
        void ReturnBook();
        void loadFromfile(int method);
        
        //search the book (two methods)
        //search through booktitle
        Books* searchBook1(std::string BookTitle);
        //search through authorname
        Books* searchBook2(std::string AuthorName);

};
#endif