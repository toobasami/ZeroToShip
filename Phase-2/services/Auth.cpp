#include "Auth.h"

// Constructor
Auth::Auth() {

    loggedIn = false;
}

// Login
bool Auth::login(const User& user) {

    currentUser = user;
    loggedIn = true;

    return true;
}

// Logout
void Auth::logout() {

    currentUser = User();
    loggedIn = false;
}

// Check session
bool Auth::isLoggedIn() {

    return loggedIn;
}

// Return current user
User Auth::getCurrentUser(){

    return currentUser;
}

// Editor authorization
bool Auth::canModerate(Paragraph& latestParagraph){

    if (!loggedIn){
        return false;
    }

    return currentUser.getUsername() == latestParagraph.getAuthor();
}