#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

#include "../models/User.h"
#include "../../Phase-1/models/Paragraph.h"
#include "../../Phase-1/models/Pitch.h"

using namespace std;

class Database
{
private:
    vector<User> users;
    vector<Paragraph> paragraphs;
    vector<Pitch> pitches;

    string filename;

public:

    Database(string file = "story_db.json");

    // User Functions
    void addUser(const User& user);
    vector<User> getUsers();
    User findUser(string email, string password);

    // Paragraph Functions
    void addParagraph(const Paragraph& paragraph);
    vector<Paragraph> getParagraphs();

    // Pitch Functions
    void addPitch(const Pitch& pitch);
    vector<Pitch> getPitches();

    // File Handling
    void saveData();
    void loadData();
};

#endif