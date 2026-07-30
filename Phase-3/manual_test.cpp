#include <iostream>
#include <vector>

#include "../Phase-1/models/Paragraph.h"
#include "models/Pitch.h"
#include "services/Database.h"
#include "services/BookCore.h"

using namespace std;

int main()
{
    cout << "========== PHASE 3 MANUAL TEST ==========\n\n";

    Database db;
    BookCore core(db);

    // -----------------------------
    // Paragraph Sorting Test
    // -----------------------------
    cout << "Paragraph Sorting Test\n";

    vector<Paragraph> paragraphs;

    paragraphs.push_back(Paragraph(1, "Third paragraph", "Ali", 3));
    paragraphs.push_back(Paragraph(2, "First paragraph", "Ahmed", 1));
    paragraphs.push_back(Paragraph(3, "Second paragraph", "Sara", 2));

    cout << "\nBefore Sorting:\n";

    for (Paragraph p : paragraphs){
        p.display();
        cout<<endl;
    }

    core.sortParagraphs(paragraphs);

    cout << "\nAfter Sorting:\n";

    for (Paragraph p : paragraphs){
        p.display();
        cout<<endl;
    }

    // -----------------------------
    // Pitch Acceptance Test
    // -----------------------------

    cout << "\n\nPitch Acceptance Test\n";

    db.addPitch(Pitch(1, 4, "Pitch One", "Ali"));
    db.addPitch(Pitch(2, 4, "Pitch Two", "Sara"));
    db.addPitch(Pitch(3, 4, "Pitch Three", "Ahmed"));

    bool result = core.acceptPitch(2);

    if(result){
        cout << "\nPitch Accepted Successfully!\n";
    }

    else{
        cout << "\nPitch Acceptance Failed!\n";
    }

    cout << "\nUpdated Pitches:\n";

    for(Pitch p : db.getPitches()){
        p.display();
        cout<<endl;
    }

    cout << "\nParagraphs Stored:\n";

    for(Paragraph p : db.getParagraphs()){
        p.display();
        cout<<endl;
    }

    cout << "\n========== TEST COMPLETE ==========\n";

    return 0;
}