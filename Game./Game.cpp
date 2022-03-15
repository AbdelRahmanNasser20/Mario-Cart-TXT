#include "Game.h"
Game::Game(){
    m_numLaps = 1;
    m_numRacers = 1;
}

Game::~Game(){
    for (int i = 0; i < int(m_Racers.size());i++){
        delete m_Racers[i];
    }
    for (int i = 0; i < int(m_myObsticales.size());i++){
        delete m_myObsticales[i];
    }
    
}

void Game::LoadTrack(){
int raceTrack = 0;
bool trackSelected = false;
while (!trackSelected){
    cout << "which race track do you want to race on?" << endl;
    cout << "1. Mario's Drag Race" << endl;
    cout << "2. Mario Circuit 1" << endl;
    cout << "3. Ultra Race" << endl;
    cin >> raceTrack;
    
    switch (raceTrack)
    {
    case 1:{
        
        cout << "opened 1" << endl;
        for (int i = 0; i < m_numLaps; i++){
            myTrack.LoadTrack(TRACK[0][1]);
        }
        trackSelected = true;
        break;
    }
    case 2:{
        cout << "opened 2" << endl;
        for (int i = 0; i < m_numLaps; i++){
            myTrack.LoadTrack(TRACK[1][1]);
        }
        trackSelected = true;
        break;
    }
    case 3:{
        cout << "opened 3" << endl;
        for (int i = 0; i < m_numLaps; i++){
            myTrack.LoadTrack(TRACK[2][1]);
        }
        trackSelected = true;
        break;
    }
    default:{
        break;}
    }
}

}


void Game::RaceSetup(){
int myRacer;
int competitors = 0;

cout << "What is your name?" << endl;
cin >> m_playerName;


bool racerSelected = false;

while (!racerSelected){
    cout << "Select a Racer" << endl;
    cout << "1. Toad" << endl;
    cout << "2. Wario" << endl;
    cout << "3. Mario" << endl;
    cin >> myRacer;
    

    switch (myRacer)
    {
    case 1:{
        Entity *newCharToad = new Toad(m_playerName, TOAD_STATS[0], TOAD_STATS[2], TOAD_STATS[1]);
        m_Racers.push_back(newCharToad);
        racerSelected = true;
        break;
    }
    case 2:{
        Entity *newCharWario = new Wario(m_playerName, WARIO_STATS[0], WARIO_STATS[2], WARIO_STATS[1]);
        m_Racers.push_back(newCharWario);
        racerSelected = true;
        break;
    }
    case 3:{
        Entity *newCharMario = new Mario(m_playerName, MARIO_STATS[0], MARIO_STATS[2], MARIO_STATS[1]);
        racerSelected = true;
        m_Racers.push_back(newCharMario);
        break;
    }
    default:
        break;
    }
    
}
// adds the user as one of the racers 

cout << "How many other competitors would you like?" << endl;
cin >> competitors;


while (competitors < 0){    
    cout << "How many other competitors would you like?" << endl;
    cin >> competitors;
}
// updates the number of racers
m_numRacers = competitors + 1;

for (int i = 0 ; i < competitors; i++){     
    
    string comp = "CPU" + to_string(i);
    int randomNumber = (rand() % 3) + 1; 
    
    switch (randomNumber){
        
        case 1:{
            Entity *newCharMarioCPU = new Mario(comp, MARIO_STATS[0], MARIO_STATS[2], MARIO_STATS[1]);
            m_Racers.push_back(newCharMarioCPU); 
            
            break;
        }
        case 2:{
            Entity *newCharWarioCPU = new Wario(comp, WARIO_STATS[0], WARIO_STATS[2], WARIO_STATS[1]);
            m_Racers.push_back(newCharWarioCPU);
            
            break;
        }
        case 3:{
            Entity *newCharToadCPU = new Toad(comp, TOAD_STATS[0], TOAD_STATS[2], TOAD_STATS[1]);
            m_Racers.push_back(newCharToadCPU);
            break;
        }
        default:
            break;
        }
                
}

cout << "How many laps would you like to complete for the race?" << endl;
cin >> m_numLaps;

while (m_numLaps <= 0){    
    cout << "How many laps would you like to complete for the race?" << endl;
    cin >> m_numLaps;
}
}


void Game::StartRace(){
    int round = 0;
    const double MAXSPEED = 1;
    const double PRETTYFAST = 0.75;
    const double FAST = 0.5;
    const double SLOW = 0.25;
    
    bool continuePlaying = true;
    
    cout << "You will be racing " << m_numLaps << " lap" << endl;
    cout << "The total length of the race track is " << myTrack.GetTotalLength() << " meters" << endl;
    cout << "Start of the Race Track\n" << endl;
    cout << "*********ON YOUR MARKS*********\n" << endl;
    cout << "*********GET SET*********\n" << endl;
    cout << "*********GO! GO! GO!*********\n" << endl;
    cout << "You currently see" << endl;
    myTrack.DisplayPiece(0);

    while (continuePlaying == true and CheckFinish() == false){
        
        int myPlayerIndex = FindPlayer();
        
        // finds my racers location
        double myRacerLocation = m_Racers[myPlayerIndex]->GetCurLocation();

        // finds the index of piece of track my character is on
        int myRacerPieceIndex = myTrack.GetPiece(myRacerLocation);

        // finds the max speed of that piece of track
        double maxSpeedOfPiece = myTrack.GetMaxSpeed(myRacerPieceIndex);

        // get the num of obsticals 
        int numObs = myTrack.GetNumObsticals(myRacerPieceIndex);
        //stores the obs in the vector
        StoreObstical(numObs);
        // set that track piece of obs to 0
        myTrack.SetNumObsticalsToZero(myRacerPieceIndex);

        // iterates the round
        round+=1;
        // calls action to display all the menu
        int input = Action();
        

        switch (input){
    
            case 1:
                m_Racers[myPlayerIndex]->CalcSpeed(MAXSPEED);
                break;
            
            case 2:
                m_Racers[myPlayerIndex]->CalcSpeed(PRETTYFAST);
                break;
            
            case 3:
                m_Racers[myPlayerIndex]->CalcSpeed(FAST);
                break;
            
            case 4:
                m_Racers[myPlayerIndex]->CalcSpeed(SLOW);
                break;
            
            case 5:
                Attack();
                break;

            case 6:
                continuePlaying = false;
                break;
            default:
                break;
            }
            
        if (round > 0){

            cout << "************************" << endl;
            cout << "ROUND " << round << endl;
            cout << "************************" << endl;

            cout << "you currently see " << endl;
            myTrack.DisplayPiece(myRacerPieceIndex);
            
            int trackSize = myTrack.GetTotalLength();
            
            // if were on the last track it doesnt try and display the next one 
            if ((myRacerLocation) < (trackSize - 100.0)){
        
                cout << "Ahead is:" << endl;
                myTrack.DisplayPiece(myRacerPieceIndex+1);
            }
            
            if (continuePlaying == true){
    
            cout << "\n************************" << endl;    
            cout << "User Special move" << endl;
            m_Racers[myPlayerIndex]->SpecialMove(maxSpeedOfPiece); // if the player has a spcial move it will use it here
            cout << "************************" << endl;
            
            
            // calculates the player speed based the max speed of the piece
            m_Racers[myPlayerIndex]->Tick(maxSpeedOfPiece);

            // randomly assigns each cpu a speed, and checks to see if they crashed
            CpuRandom();
            Tick(maxSpeedOfPiece);
            
            // reranges the vector
            Order();
        }

            cout << "\n************************" << endl;    
            // display all the characters
            Display();
            cout << "************************" << endl;
            if(CheckFinish() == true){
                continuePlaying = false;
            }

        }
    }

cout << "The race is over " << endl;
if (CheckFinish() == true){
    cout << "(" << m_Racers.at(0)->GetName() << ") " << m_Racers.at(0)->GetType()<< " won the race" << endl;
}
}

bool Game::CheckFinish(){
    for(int i = 0; i < int(m_Racers.size());i++){
    // checks to see if the racer travels the lenght of the track
    if (m_Racers[i]->GetCurLocation() >= double(myTrack.GetTotalLength())){
        return true;
    }
    }
return false;
}

void Game::CpuRandom(){

double arr[4] = {1.0, 0.75, 0.5, 0.25};

for(int i = 0; i < int(m_Racers.size());i++){

    // ensures it doesnt affect the user racer;
    if (m_Racers[i]->GetName() != m_playerName){

        // gets a rand number from 0 - 3
        int randomNumber = rand()%(3)+0;

        // calulcates the speed based the random speed
        m_Racers[i]->CalcSpeed(arr[randomNumber]);
    
    if (m_Racers[i]->GetCrash() == true and m_Racers[i]->GetType() != "Mario"){
        m_Racers[i]->SetCurSpeed(0);

        // resets their crash flag to false
        m_Racers[i]->SetCrash(false);
        }
    }    
}
}

void Game::Tick(double maxTrackSpeed){
    cout << "\n************************" << endl;    
    cout << "Cpu Special moves will be called here" << endl;
    for(int i = 0; i < int(m_Racers.size());i++){
        // for all computer racers
        if (m_Racers[i]->GetName() != m_playerName){
            
            m_Racers[i]->SpecialMove(maxTrackSpeed);
            // calls charcter tick on all the computer players
            m_Racers[i]->Tick(maxTrackSpeed);
        }   
    }   
    cout << "************************" << endl;    
}


void Game::Order(){

for (int i = 0; i < m_numRacers-1; i++){ 
    
    // itertes through the vector untill the the index is at the end
    for (int j = 0; j < m_numRacers-i-1; j++){
        
        // compares two racer total distance  
        if (m_Racers[j]->GetCurLocation() < m_Racers[j+1]->GetCurLocation()){
            
            // creates a temp entity so we can swap the two players
            Entity *temp = m_Racers[j];
            m_Racers[j] = m_Racers[j+1];
            m_Racers[j+1] = temp;}
    }   
}
}


void Game::Attack(){
    
    // if the user has no objects in the vector, return
    if (int(m_myObsticales.size()) == 0){
        cout << "you have no objects to throw" << endl;
        return;
    }
    // else if he has objects in
    else{
        
        // prints out the inventory of the users obsticals in his vectors
        cout << "you currently have" << endl;
        int countShells = 0;
        int countBanana = 0;
        for (int i = 0; i < int(m_myObsticales.size()); i++){
            (*m_myObsticales.at(i)) << cout << endl;
            if (m_myObsticales[i]->GetType() == "Shell"){
                countShells += 1;
            }
            else{
                countBanana +=1;
            }
        }
        cout << "you have " << countBanana << " Bananas and " << countShells << " Shells" << endl;
        int myPlayerIndex = FindPlayer();

        // if the user has only Shell obsticals in his vector the user will then throw the shell
        if (countShells > 0 and countBanana == 0){        

	  delete m_myObsticales[int(m_myObsticales.size())-1];

            // remooves the last object in the vector
            m_myObsticales.pop_back();
            
            // if the user is in first place then he will miss as the shell hits no one 
            if (myPlayerIndex == 0){
                cout << "you missed, No one was infront of you" << endl;
            
            }
            // else the user will hit whoever is ahead if him unless its Mario as he dodges all objects
            else{
                int oppIndex = myPlayerIndex -1;
                
                // sets the opp bool flag crash to true
                m_Racers[oppIndex]->SetCrash(true);
                
                if (m_Racers[oppIndex]->GetType() != "Mario"){
                    cout << m_Racers[oppIndex]->GetName() << " has been hit by a shell" << endl;
                }
            }
            return;
        
        }
        // if the user only has bananas in his vector he will automatically throw one
        else if (countShells == 0 and countBanana > 0){
                delete m_myObsticales[int(m_myObsticales.size())-1];

	        m_myObsticales.pop_back();
                
                // if the user has no one behind him he will therefor miss
                if (myPlayerIndex == (int(m_Racers.size())-1)){
                    cout << "you missed, No one was behind you" << endl;
                }
                else{
                    // whover is infornt of the user will get hit unless its Mario
                    int oppIndex = myPlayerIndex + 1;
                    m_Racers[oppIndex]->SetCrash(true);
                    if (m_Racers[oppIndex]->GetType() != "Mario"){
                        cout << m_Racers[oppIndex]->GetName() << " has been hit by a banana" << endl;
                    }
                       
                }
            return;
        }

        // else ask the user what he wants to throw
        else{ 
            
            // checks user inputs ensures he inputs a shell or banana
            int throwObj = 0;
            cout << "What would you like to throw, (Enter a number) 0 for Shell or 1 for Banana?" << endl;
            cin >> throwObj;
            while (throwObj != 0 and throwObj != 1){
                cout << "enter a int 0 or 1?" << endl;
                cin >> throwObj;
            }
            
            // iterates through the obstical vector
            for (int i = 0; i < int(m_myObsticales.size()); i++){
                
                // if a player throws a shell, we iterate through the vector untill we find the index of that shell
                if (throwObj == 0 and m_myObsticales[i]->GetType() == "Shell"){
                    
                    // misses the shell if the user is 1st place
                    if (myPlayerIndex == 0){
                        cout << "you missed, No one was infront of you" << endl;

                    }
                    else{
                        // else hits whoever is ahead of him unless its mario
                        int oppIndex = myPlayerIndex -1;
                        m_Racers[oppIndex]->SetCrash(true);
                        
                        if (m_Racers[oppIndex]->GetType() != "Mario"){
                        cout << m_Racers[oppIndex]->GetName() << "has been hit by a shell" << endl;
                        }

                    }
		    delete m_myObsticales[i];			
                    // erase that index shell from the vector 
                    m_myObsticales.erase(m_myObsticales.begin() + i);                    
                    return;
                    
                }
                // if a player throws a shell, we iterate through the vector untill we find the index of that banana
                else if (throwObj == 1 and m_myObsticales[i]->GetType() == "Banana"){
                    // if there is a  racer behind the user its a miss
                    if (myPlayerIndex == (int(m_Racers.size())-1)){
                        cout << "you missed, No one was behind you" << endl;
                    }
                    else{
                        // if there is a racer infornt of the user its a hit
                        int oppIndex = myPlayerIndex + 1;
                        m_Racers[oppIndex]->SetCrash(true);

                        if (m_Racers[oppIndex]->GetType() != "Mario"){
                        cout << m_Racers[oppIndex]->GetName() << "has been hit by a banana" << endl;
                        }

                    }
                    // remove the object obstical index 
		    delete m_myObsticales[i];
		    m_myObsticales.erase(m_myObsticales.begin() + i);
                    return;
                }
           }         
        }
    }
}


void Game::Display(){
    // itereates through all the player and calls the overload cout operater

    for (int i = 0; i < m_numRacers; i++){
        *m_Racers.at(i) << cout << endl;
    }
}

int Game::FindPlayer(){
    for (int i = 0; i < m_numRacers; i++){
        if (m_Racers[i]->GetName() == m_playerName){
            return i;
        }
    }
    return -1;
}


int Game::Action(){
int choice = 0;
    cout << "What would you like to do?" << endl;
    cout << "1. Max Speed" << endl;
    cout << "2. Pretty Fast" << endl;
    cout << "3. Fast" << endl;
    cout << "4. Slow" << endl;
    cout << "5. Use Obstacle" << endl;
    cout << "6. Quit" << endl;
    cin >> choice;

// ensures user inputs a choice from 1-6
// displays menu as well
while (choice > 6 or choice < 0){

    cout << "What would you like to do?" << endl;
    cout << "1. Max Speed" << endl;
    cout << "2. Pretty Fast" << endl;
    cout << "3. Fast" << endl;
    cout << "4. Slow" << endl;
    cout << "5. Use Obstacle" << endl;
    cout << "6. Quit" << endl;
    cin >> choice;
}
return choice;
}

void Game::StoreObstical(int numObstical){
    
    for (int i  = 0; i < numObstical; i++){
        int randomNumber = rand()%(2)+0;
        if (randomNumber == 0){
            Obstacle* newShell = new Shell();                                                                                                                     
            m_myObsticales.push_back(newShell);  
            cout << " you have picked up a shell" << endl;
        }
        
        else{
            Obstacle* newBanana = new Banana();                                                                                                                   
            m_myObsticales.push_back(newBanana);
            cout << " you have picked up a banana" << endl;
        }

    }
}
