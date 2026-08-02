#include <iostream>
#include <vector>

#include "../Phase-1/models/Paragraph.h"
#include "../Phase-3/models/Pitch.h"
#include "services/Presentation.h"

using namespace std;

int main(){
    
    // Mock Story Paragraphs
    vector<Paragraph> story;

    story.push_back(Paragraph(
        1,
        "Once upon a time, there was a mysterious forest.",
        "Ali",
        1));

    story.push_back(Paragraph(
        2,
        "A young explorer entered the forest with courage.",
        "Sara",
        2));

    story.push_back(Paragraph(
        3,
        "Suddenly, a hidden door appeared between the trees.",
        "Ahmed",
        3));

    // Mock Candidate Pitches
    vector<Pitch> pitches;

    pitches.push_back(Pitch(
        1,
        4,
        "The explorer opens the mysterious door.",
        "Fatima"));

    pitches.push_back(Pitch(
        2,
        4,
        "The forest begins to disappear.",
        "Hamza"));

    pitches.push_back(Pitch(
        3,
        4,
        "A magical dragon comes out of the door.",
        "Ayesha"));

    Presentation ui;

    ui.clearScreen();

    ui.displayStory(story);

    cout << endl << endl;

    ui.displayPitchRegistry(pitches);

    return 0;
}