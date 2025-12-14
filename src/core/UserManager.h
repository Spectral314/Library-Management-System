#ifndef UserManager
#define UserManager
#include<iostream>
#include<string>
#include<unordered_map>
struct User
{
    /* data */
    std::string name;
    std::string gender;
    long numberation;
    int HaveBook;
    bool memberyet;
    static int count;
};
extern User* currentUser;
class UserManipulation{
    public:
        void showUserInfo(User* Userptr);
        void creatUser();
        User *searchUser(const long stringn);
        
    protected:
        std::unordered_map <long,User> UserMap;
        virtual void loadFromFile();
};

/*The VIP has authority to hold book for a longer time*/
class UserM_for_VIP: public UserManipulation{
    public:
        void openMembership();

};
#endif