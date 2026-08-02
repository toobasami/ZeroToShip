#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <vector>

#include "../../Phase-1/models/Paragraph.h"
#include "../../Phase-3/models/Pitch.h"

class Presentation
{
public:
    void clearScreen();

    void displayStory(const std::vector<Paragraph>& story);

    void displayPitchRegistry(const std::vector<Pitch>& pitches);
};

#endif