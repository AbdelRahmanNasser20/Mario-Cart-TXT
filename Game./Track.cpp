#include "Track.h"

Track::Track(){}
Track::~Track(){    
    for (int i = 0; i < int(m_track.size()); i++){
    
    // delete track
    delete m_track[i];}
}

void Track::LoadTrack(string fileName){  
// ensures no garbage value
m_totalLength = 0; 
ifstream myfile(fileName);    

if (myfile.is_open()){

    string name, desc, length, numBox, max, empty;
    
    // gets the name and desc of the file, first two lines
    getline(myfile, name,'\n');
    getline(myfile, desc,'\n');
    
    // reads in every line but the last and puts it in the track vector
    while(
    getline(myfile, length, '|') and getline(myfile, desc, '|') and getline(myfile, numBox, '|'), getline(myfile, max,'|'), getline(myfile, empty,'\n')){
    
    Piece *piece = new Piece(stoi(length), desc, stoi(numBox), stoi(max));
    m_track.push_back(piece);
    }
    
    // closes file
    myfile.close();
}
else{
    cout << " error loading file" << endl;
}
}

int Track::GetPiece(int distance){
int sumDistance = 0;

for (int i = 0; i < int(m_track.size()); ++i){

    // ensures theres no seg fault when on the last element in the vector
    if (i == int(m_track.size())-1) {
        return int(m_track.size())-1;
    }
    
    // add on the track
    sumDistance += m_track[i]->m_length;

    // reutrns the first index in the track vecotr if the first piece lengh is greater than 0
    if (sumDistance > distance and i ==0){
        return i;
    }
    
    if (sumDistance > distance){
        return i-1;
    }
    
}
return -1;

}

void Track::DisplayPiece(int index){
cout << m_track[index]->m_desc << endl;;
}

double Track::GetMaxSpeed(int index){
    return m_track[index]->m_maxSpeed;
}

int Track::GetTotalLength(){
// resets the total lengh to 0 to ensure it doesnt continue adding to m_total lengh if the function is called multiple time
m_totalLength = 0; 

// iterates through the vector and adds up the length of the track
for (int i = 0; i < int(m_track.size());i++){
m_totalLength += m_track[i]->m_length;
}

return m_totalLength;
}


string Track::GetDesc(){
    return m_desc;
}

int Track::GetNumObsticals(int index){return m_track[index]->m_numBox;}

void Track::SetNumObsticalsToZero(int index){m_track[index]->m_numBox = 0;}
