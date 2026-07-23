#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include <string>
#include <map>

using namespace std;

class Paragraph
{
private:

    int id;
    string text;
    string author;
    int order_num;


public:

    Paragraph(int id = 0, string text = "", string author = "", int order_num = 0)
        : id(id),
          text(text),
          author(author),
          order_num(order_num)
    {}


    // Serialization
    map<string, string> to_dict();

    // Deserialization
    static Paragraph from_dict(const map<string, string>& data);

    void display();

    // Getters
    int getId();
    string getText();
    string getAuthor();
    int getOrderNum();


};

#endif