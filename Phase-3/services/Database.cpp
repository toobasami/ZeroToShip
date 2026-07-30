#include "Database.h"
#include <fstream>
#include <iostream>

using namespace std;

// Helper function
string getValue(string line){

    size_t first = line.find("\"", line.find(":"));
    size_t second = line.find("\"", first + 1);

    return line.substr(first + 1, second - first - 1);
}

Database::Database(string file){

    filename = file;
    loadData();
}

// -------------------- User --------------------

void Database::addUser(const User& user){

    users.push_back(user);
}

vector<User> Database::getUsers(){

    return users;
}

User Database::findUser(string email, string password){

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getEmail() == email &&
            users[i].getPassword() == password)
        {
            return users[i];
        }
    }

    return User();
}

// -------------------- Paragraph --------------------

void Database::addParagraph(const Paragraph& paragraph){

    paragraphs.push_back(paragraph);
}

vector<Paragraph>& Database::getParagraphs(){

    return paragraphs;
}

// -------------------- Pitch --------------------

void Database::addPitch(const Pitch& pitch){

    pitches.push_back(pitch);
}

vector<Pitch>& Database::getPitches(){

    return pitches;
}

// -------------------- Save --------------------

void Database::saveData(){

    ofstream fout(filename);

    if (!fout){

        cout << "Unable to open file." << endl;
        return;
    }

    fout << "{\n";


    // USERS

    fout << "  \"users\": [\n";

    for (int i = 0; i < users.size(); i++){

        map<string,string> data = users[i].to_dict();

        fout << "    {\n";
        fout << "      \"id\": \"" << data["id"] << "\",\n";
        fout << "      \"username\": \"" << data["username"] << "\",\n";
        fout << "      \"email\": \"" << data["email"] << "\",\n";
        fout << "      \"password\": \"" << data["password"] << "\"\n";
        fout << "    }";

        if (i != users.size() - 1)
            fout << ",";

        fout << "\n";
    }

    fout << "  ],\n";


    // PARAGRAPHS

    fout << "  \"paragraphs\": [\n";

    for (int i = 0; i < paragraphs.size(); i++){

        map<string,string> data = paragraphs[i].to_dict();

        fout << "    {\n";
        fout << "      \"id\": \"" << data["id"] << "\",\n";
        fout << "      \"text\": \"" << data["text"] << "\",\n";
        fout << "      \"author\": \"" << data["author"] << "\",\n";
        fout << "      \"order_num\": \"" << data["order_num"] << "\"\n";
        fout << "    }";

        if (i != paragraphs.size() - 1)
            fout << ",";

        fout << "\n";
    }

    fout << "  ],\n";


    // PITCHES

    fout << "  \"pitches\": [\n";

    for (int i = 0; i < pitches.size(); i++){

        map<string,string> data = pitches[i].to_dict();

        fout << "    {\n";
        fout << "      \"id\": \"" << data["id"] << "\",\n";
        fout << "      \"target_order_num\": \"" << data["target_order_num"] << "\",\n";
        fout << "      \"text\": \"" << data["text"] << "\",\n";
        fout << "      \"author\": \"" << data["author"] << "\",\n";
        fout << "      \"status\": \"" << data["status"] << "\"\n";
        fout << "    }";

        if (i != pitches.size() - 1)
            fout << ",";

        fout << "\n";
    }

    fout << "  ]\n";


    fout << "}";

    fout.close();

    cout << "Data saved successfully." << endl;
}
// -------------------- Load --------------------

void Database::loadData(){

    ifstream fin(filename);

    if (!fin){

        return;
    }

    users.clear();
    paragraphs.clear();
    pitches.clear();


    string line;

    while(getline(fin, line)){

        // USERS

        if(line.find("\"users\"") != string::npos){

            while(getline(fin,line)){

                if(line.find("\"id\"") != string::npos){

                    string id = getValue(line);

                    getline(fin,line);
                    string username = getValue(line);

                    getline(fin,line);
                    string email = getValue(line);

                    getline(fin,line);
                    string password = getValue(line);


                    users.push_back(
                        User(
                            stoi(id),
                            username,
                            email,
                            password
                        )
                    );
                }

                if(line.find("]") != string::npos)
                    break;
            }
        }


        // PARAGRAPHS

        if(line.find("\"paragraphs\"") != string::npos){
            
            while(getline(fin,line)){ 

                if(line.find("\"id\"") != string::npos){

                    string id = getValue(line);

                    getline(fin,line);
                    string text = getValue(line);

                    getline(fin,line);
                    string author = getValue(line);

                    getline(fin,line);
                    string order = getValue(line);


                    paragraphs.push_back(
                        Paragraph(
                            stoi(id),
                            text,
                            author,
                            stoi(order)
                        )
                    );
                }

                if(line.find("]") != string::npos)
                    break;
            }
        }


        // PITCHES

        if(line.find("\"pitches\"") != string::npos){
            while(getline(fin,line)){

                if(line.find("\"id\"") != string::npos){

                    string id = getValue(line);

                    getline(fin,line);
                    string target = getValue(line);

                    getline(fin,line);
                    string text = getValue(line);

                    getline(fin,line);
                    string author = getValue(line);

                    getline(fin,line);
                    string status = getValue(line);


                    pitches.push_back(
                        Pitch(
                            stoi(id),
                            stoi(target),
                            text,
                            author,
                            status
                        )
                    );
                }

                if(line.find("]") != string::npos)
                    break;
            }
        }
    }

    fin.close();
}