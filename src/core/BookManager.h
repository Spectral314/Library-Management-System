//BookManager.h
#ifndef BookManager
#define BookManager
#include<iostream>
#include<string>
#include<unordered_map>
class Books{
    protected:
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
        
        virtual void getLateFee(){
            std::cout<<"Fine 0.2 every day.";return;
        }
};

//继承书的几个类，每种书逾期罚款不同
class NormalBook : public Books{
    virtual void getLateFee(){
        std::cout<<"Fine 0.5 every day.";return;
    }
};
class ReferenceBook : public Books{
    virtual void getLateFee(){
        std::cout<<"Fine 2 every day.";
        return;
    }
};
class EBook : public Books {  // 电子书
    virtual void getLateFee(){
        std::cout<<"No Fine. But you need to return in time.";
        return;
    }
};
#endif