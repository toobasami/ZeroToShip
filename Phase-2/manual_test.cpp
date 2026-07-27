#include <iostream>

#include "models/User.h"
#include "../Phase-1/models/Paragraph.h"
#include "../Phase-1/models/Pitch.h"
#include "services/Auth.h"
#include "services/Database.h"

using namespace std;

int main()
{
    cout << "========== USER TEST ==========" << endl;

    User user1(1, "Tooba", "tooba@gmail.com", "12345");

    user1.display();

    cout << endl;

    cout << "========== DATABASE TEST ==========" << endl;

    Database db;

    db.addUser(user1);

    db.saveData();

    cout << "User Saved Successfully!" << endl;

    db.loadData();

    vector<User> users = db.getUsers();

    for (int i = 0; i < users.size(); i++)
    {
        users[i].display();
    }

    cout << endl;

    cout << "========== LOGIN TEST ==========" << endl;

    Auth auth;

    User loginUser = db.findUser("tooba@gmail.com", "12345");

    if (loginUser.getId() != 0)
    {
        auth.login(loginUser);
        cout << "Login Successful!" << endl;
    }
    else
    {
        cout << "Login Failed!" << endl;
    }

    cout << endl;

    cout << "========== PARAGRAPH TEST ==========" << endl;

    Paragraph p1(
        1,
        "Once upon a time there was a dragon.",
        "Tooba",
        1
    );

    db.addParagraph(p1);

    p1.display();

    cout << endl;

    cout << "========== PITCH TEST ==========" << endl;

    Pitch pitch1(
        1,
        1,
        "The dragon met a knight.",
        "Ali",
        "Pending"
    );

    db.addPitch(pitch1);

    pitch1.display();

    cout << endl;

    cout << "========== AUTHORIZATION TEST ==========" << endl;

    if (auth.canModerate(p1))
    {
        cout << "Editor Access Granted." << endl;
    }
    else
    {
        cout << "Editor Access Denied." << endl;
    }

    cout << endl;

    cout << "========== SAVE AGAIN ==========" << endl;

    db.saveData();

    cout << "All Data Saved Successfully!" << endl;

    auth.logout();

    if (!auth.isLoggedIn())
    {
        cout << "Logout Successful!" << endl;
    }

    return 0;
}