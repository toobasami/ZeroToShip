#include "BookCore.h"

#include <algorithm>

// Constructor

BookCore::BookCore(Database& db): database(db){}

// Sort Paragraph By Order Number

void BookCore::sortParagraphs(vector<Paragraph>& paragraphs){
    sort(paragraphs.begin(), paragraphs.end(), 
    [](Paragraph& a, Paragraph&b)
    {
        return a.getOrderNum() < b.getOrderNum();
    });
}

//Accept Pitch 

bool BookCore::acceptPitch(int pitchId){
    vector<Pitch>& pitches = database.getPitches();

    for(Pitch& pitch : pitches){
        if(pitch.getId()==pitchId){
            if(pitch.getStatus()!= "Pending"){
                return false;
            }
        
        // Accept Selected Pitch

        pitch.setStatus("Accepted");

        // Create Paragraph
        Paragraph newParagraph( 
            database.getParagraphs().size()+1,
            pitch.getText(),
            pitch.getAuthor(),
            pitch.getTargetOrderNum()
        );

        database.addParagraph(newParagraph);

        //Reject Remaining Pitches

        rejectCompetingPitches(pitch.getTargetOrderNum(),pitch.getId());

        database.saveData();

           return true;
        }
    }

    return false;
}

// Reject Competing Pitches

void BookCore::rejectCompetingPitches(int targetOrderNum,int acceptedPitchId){
    vector<Pitch>& pitches = database.getPitches();

    for(Pitch& pitch : pitches){
        if(pitch.getTargetOrderNum() == targetOrderNum && pitch.getId() != acceptedPitchId){
            pitch.setStatus("Rejected");
        }
    }

}