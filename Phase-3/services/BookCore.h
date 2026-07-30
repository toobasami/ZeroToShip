#ifndef BOOKCORE_H
#define BOOKCORE_H

#include "../../Phase-1/models/Paragraph.h"
#include "../models/Pitch.h"
#include "Database.h"

#include <vector>

class BookCore{

private:
    Database& database;

public:
        BookCore(Database&db);

// Sort Paragrapghs By Order Number
void sortParagraphs(std::vector<Paragraph>& paragraphs);

// Accept A Pitch & Process The Workflow
bool acceptPitch(int pitchId);

private:

// Reject All Other Pitches for The Same Order Number
void rejectCompetingPitches(int targetOrderNum, int acceptedPitchId);

};

# endif