#ifndef USER_H
#define USER_H

#include <string>
#include <map>

using namespace std;

class User
{
private:
    int id;
    string username;
    string email;
    string password;

public:
   
    User(int userId = 0, string userName = "", string userEmail = "", string userPassword = "");

    // Getters
    int getId() const;
    string getUsername() const;
    string getEmail() const;
    string getPassword() const;

    // Serialization
    map<string, string> to_dict() const;
    static User from_dict(const map<string, string>& data);

    // Display
    void display() const;
};

#endif