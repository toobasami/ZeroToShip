#ifndef AUTH_H
#define AUTH_H

#include <string>
#include "../models/User.h"
#include "../../Phase-1/models/Paragraph.h"
using namespace std;

class Auth
{
private:
    User currentUser;
    bool loggedIn;

public:
    // Constructor
    Auth();

    // Authentication
    bool login(const User& user);
    void logout();

    // Session
    bool isLoggedIn() ;
    User getCurrentUser();

    // Authorization
    bool canModerate(Paragraph& latestParagraph);
};

#endif 