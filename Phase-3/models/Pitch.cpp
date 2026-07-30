#include "Pitch.h"
#include <iostream>

using namespace std;

int Pitch::getId() { return id; }

int Pitch::getTargetOrderNum() { return target_order_num; }

string Pitch::getText() { return text; }

string Pitch::getAuthor() {  return author; }

string Pitch::getStatus() { return status; }

map<string, string> Pitch::to_dict() {
    return {
        {"id", to_string(id)},
        {"target_order_num", to_string(target_order_num)},
        {"text", text},
        {"author", author},
        {"status", status}
    };
}

Pitch Pitch::from_dict(const map<string, string>& data){
    return Pitch(
        stoi(data.at("id")),
        stoi(data.at("target_order_num")),
        data.at("text"),
        data.at("author"),
        data.at("status")
    );
}

void Pitch::display(){
    cout << "ID: " << id << endl;
    cout << "Target Order Number: " << target_order_num << endl;
    cout << "Text: " << text << endl;
    cout << "Author: " << author << endl;
    cout << "Status: " << status << endl;
}