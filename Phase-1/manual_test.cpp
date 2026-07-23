#include <iostream>
#include <map>

#include "models/Paragraph.h"
#include "models/Pitch.h"

using namespace std;

int main(){

Paragraph p(1,"It all began when a mysterious stranger walked into the small town carrying a locked wooden box.","Ali",1);

cout<<"\n================== PARAGRAPH TEST ====================\n"<< endl;

cout<<"\nORIGINAL PARAGRAPH: "<< endl;
p.display();

map<string,string> paragraphData=p.to_dict();
cout<< "\nSERIALIZED DATA: "<< endl;

for(auto item :paragraphData){
    cout<< item.first<< " : "<< item.second<< endl;
}

Paragraph newParagraph= Paragraph:: from_dict(paragraphData);
cout<< "\nDESERIALIZED PARAGRAPH: "<< endl;
newParagraph.display();


cout << "\n========== Pitch Test ==========\n" << endl;

Pitch pitch(1, 1, "The dragon appears in the forest.", "Tooba", "Pending");

cout << "\nOriginal Pitch:" << endl;
pitch.display();

map<string, string> pitchData = pitch.to_dict();

cout << "\nSERIALIZED DATA:" << endl;

for (auto item : pitchData)
{
    cout << item.first << " : " << item.second << endl;
}

Pitch newPitch = Pitch::from_dict(pitchData);

cout << "\nDESERIALIZED PITCH:" << endl;
newPitch.display();





    return 0;
}