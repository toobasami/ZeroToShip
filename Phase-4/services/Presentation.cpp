#include "Presentation.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

void Presentation::clearScreen(){

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Presentation::displayStory(const vector<Paragraph>& story){

    cout << "============================================================" << endl;
    cout << "                      STORY CANVAS" << endl;
    cout << "============================================================" << endl;
    cout << endl;

    if (story.empty()){

        cout << "No story available." << endl;
    }
    else{

        for (Paragraph paragraph : story){

            cout << paragraph.getOrderNum() << ". "
                 << paragraph.getText() << endl;
            cout << "Author: " << paragraph.getAuthor() << endl;
            cout << endl;
        }
    }

    cout << "============================================================" << endl;
    cout << endl;
}

void Presentation::displayPitchRegistry(const vector<Pitch>& pitches){
    
    cout << "+--------------------------------------------------------------------------+" << endl;
    cout << "|                           PITCH REGISTRY                                 |" << endl;
    cout << "+--------------------------------------------------------------------------+" << endl;
    cout << "| ID | Order | Status     | Pitch                                          |" << endl;
    cout << "+--------------------------------------------------------------------------+" << endl;

    if (pitches.empty()){

        cout << "| No pitches available.                                                    |" << endl;
        cout << "+--------------------------------------------------------------------------+" << endl;
        return;
    }

    for (Pitch pitch : pitches){
        string text = pitch.getText();

        if (text.length() > 44){

            text = text.substr(0, 41) + "...";
        }

        cout << "| "
             << setw(2) << right << pitch.getId() << " | "
             << setw(5) << right << pitch.getTargetOrderNum() << " | "
             << setw(10) << left << pitch.getStatus() << " | "
             << setw(46) << left << text << "|" << endl;

        cout << "+--------------------------------------------------------------------------+" << endl;
    }

    cout << endl;
}