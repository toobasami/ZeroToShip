#include "User.h"
#include <iostream>

using namespace std;

User::User(int userId, string userName, string userEmail, string userPassword){

    id = userId;
    username = userName;
    email = userEmail;
    password = userPassword;
}


// Getters
int User::getId() const{ return id; }

string User::getUsername() const { return username; }

string User::getEmail() const { return email; }

string User::getPassword() const { return password; }

// Convert object to map
map<string, string> User::to_dict() const {

    map<string, string> data;

    data["id"] = to_string(id);
    data["username"] = username;
    data["email"] = email;
    data["password"] = password;

    return data;
}

// Create object from map
User User::from_dict(const map<string, string>& data) {

    return User(
        stoi(data.at("id")),
        data.at("username"),
        data.at("email"),
        data.at("password")
    );
}


void User::display() const {
    cout << "User ID: " << id << endl;
    cout << "Username: " << username << endl;
    cout << "Email: " << email << endl;
    cout << "Password: " << password << endl;
}