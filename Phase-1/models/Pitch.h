#ifndef PITCH_H
#define PITCH_H

#include <string>
#include <map>

using namespace std;

class Pitch
{
private:

    int id;
    int target_order_num;
    string text;
    string author;
    string status;

public:

 Pitch(int id = 0, int target_order_num = 0, string text = "", string author = "", string status = "Pending")
        : id(id),
          target_order_num(target_order_num),
          text(text),
          author(author),
          status(status)
    {}

    // Serialization
    map<string, string> to_dict();

    // Deserialization
    static Pitch from_dict(const map<string, string>& data);

    void display();

    // Getters
    int getId();
    int getTargetOrderNum();
    string getText();
    string getAuthor();
    string getStatus();
};

#endif