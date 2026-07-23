#include "Paragraph.h"
#include <iostream>

using namespace std;

int Paragraph::getId() { return id; }

string Paragraph::getText() { return text; }

string Paragraph::getAuthor() { return author; }

int Paragraph::getOrderNum() { return order_num; }

map<string, string> Paragraph::to_dict(){
    return {
        {"id", to_string(id)},
        {"text", text},
        {"author", author},
        {"order_num", to_string(order_num)}
    };
}

Paragraph Paragraph::from_dict(const map<string, string>& data){
    return Paragraph(
        stoi(data.at("id")),
        data.at("text"),
        data.at("author"),
        stoi(data.at("order_num"))
    );
}

void Paragraph::display(){

    cout << "ID: " << id << endl
         << "Text: " << text << endl
         << "Author: " << author << endl
         << "Order Number: " << order_num << endl;
}