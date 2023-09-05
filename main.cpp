/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




#include <iostream>
/*
 copied UDT 1:
 */
struct Castle
{
    int numberOfGates;
    std::string nameOfKing;
    std::string nameOfQueen;
    float amountOfTaxesCollected;
    bool isAtWar;

    Castle();
    ~Castle();

    struct FarmlandRevenue
    {
        int totalRevenue = 2500;
        int arces {65}, numberOfWorkers {120};
        float wheatSalePricePerKG {1.8f};
        std::string type {"Cereals and Grains"};
        bool isInDrought {false};

        FarmlandRevenue();
        ~FarmlandRevenue();

        void sellWheat(int wheatStockLevel, float currentMarketPrice, float amountToSell);
        float displayCurrentTurnover(int totalWorkers, int farmlandArea, float currentMarketPrice, float previousMarketPrice);
        void floodFarmlands(int areaToFlood, float amountOfFlooding, bool isIndrought);
        void hireNewWorkers(int startWorkers, int revenueThreshold);

        // New member functions
        void printCurrentTurnover();
        void printDroughtStatus();
        void listTotalNumWorkers();
    };

    float reportCollectTaxes(float collectTaxes, FarmlandRevenue farmlandIncome);
    void openCastleGates(int numberOfGatesClosed);
    std::string announceOrders(std::string orders);
    void fireSignalArrow(int startArrows, int targetHits);

    // New member functions
    void displayNameOfKingAndQueen();
    void printTotalNumGates();
    void printTaxCollection();
};

Castle::Castle() : numberOfGates(8), nameOfKing("Edward"), nameOfQueen("Magda"), amountOfTaxesCollected(300.f), isAtWar(true)
{
    std::cout << "Castle being constructed!\n";  
}

Castle::~Castle()
{
    std::cout << "Castle being deconstructed\n";
}

Castle::FarmlandRevenue::FarmlandRevenue()
{
    std::cout << "FarmlandRevenue being constructed!\n";
}

Castle::FarmlandRevenue::~FarmlandRevenue()
{
    std::cout << "FarmlandRevenue being deconstructed!\n";
}

// New member function
void Castle::displayNameOfKingAndQueen()
{
    std::cout << "names of royalty: " << this->nameOfKing << " & " << this->nameOfQueen << std::endl;
}

// New member function
void Castle::printTotalNumGates()
{
    std::cout << "total gates at castle: " << this->numberOfGates << std::endl;
}

// New member function
void Castle::printTaxCollection()
{
    std::cout << "tax collected: " << this->amountOfTaxesCollected << std::endl;
}

// New member function
void Castle::FarmlandRevenue::printCurrentTurnover()
{
    std::cout << "Current wholesale price of wheat per kg: " << this->wheatSalePricePerKG << std::endl;
}

// New member function
void Castle::FarmlandRevenue::printDroughtStatus()
{
    std::cout << "Is the farmland in drought? 0 = no, 1 = yes: " << this->isInDrought << std::endl;
}

// New member function
void Castle::FarmlandRevenue::listTotalNumWorkers()
{
    std::cout << "Current number of able workers: " << this->numberOfWorkers << std::endl;
}

void Castle::FarmlandRevenue::hireNewWorkers(int startWorkers, int revenueThreshold)
{
    int worker = (numberOfWorkers / numberOfWorkers);
    int workers = startWorkers;
    int revenuePerWorkerPerDay = (worker * 10);
    int revenue = workers * revenuePerWorkerPerDay;

    while (revenue < revenueThreshold) 
    {
        ++workers;
        revenue = workers * revenuePerWorkerPerDay;
        if (revenue >= revenueThreshold) 
        {
            std::cout << "Hired " << workers << " workers to reach the revenue threshold.\n";
            return;
        }
    }
    std::cout << "The initial number of workers already generates enough revenue.\n";
}

void Castle::fireSignalArrow(int startArrows, int targetHits) 
{
    int arrows = startArrows;
    int hits = 0;

    while (arrows > 0 && hits < targetHits) 
    {
        --arrows;

        int hitTarget = rand() % 2;
        
        if (hitTarget == 1) 
        {
            ++hits;
            std::cout << "Target hit! Total hits: " << hits << "\n";
        } 
        else 
        {
            std::cout << "Missed. Remaining arrows: " << arrows << "\n";
        }
        if (hits >= targetHits) 
        {
            std::cout << "Target hits threshold reached with " << arrows << " arrows left.\n";
            return;
        }
    }
    
    if (arrows == 0) 
    {
        std::cout << "Out of arrows. Total hits: " << hits << "\n";
    }
}

void Castle::FarmlandRevenue::sellWheat(int wheatStockLevel, float currentMarketPrice, float amountToSell)
{
    int availableStock = wheatStockLevel - 100;
    
    if (availableStock < 100)
    {
        std::cout << "Stock levels too low\n";
    }
    else
    {
        std::cout << "Stock levels OK\n";
        std::cout << "Market price: " << currentMarketPrice << "\n";
        float estimatedSale = currentMarketPrice * amountToSell;
        std::cout << "Expected sale price: " << estimatedSale << "\n";
    }
}

float Castle::FarmlandRevenue::displayCurrentTurnover(int totalWorkers, int farmlandArea, float currentMarketPrice, float previousMarketPrice)
{
    int workForceOverArea = totalWorkers + farmlandArea / 2;
    std::cout << "Workforce turnover per acre: " << workForceOverArea << std::endl;
    float marketEstimation = currentMarketPrice - previousMarketPrice * 0.2f;
            
    return marketEstimation;
}

void Castle::FarmlandRevenue::floodFarmlands(int areaToFlood, float amountOfFlooding, bool isIndrought)
{
    if(isIndrought)
    {
        std::cout << "Select area to flood " << areaToFlood << "\n";
        std::cout << "Adjust flood level " << amountOfFlooding << "\n";       
    }
    else
    {
        std::cout << "Flooding not required\n";
    }
}

float Castle::reportCollectTaxes(float collectTaxes, FarmlandRevenue farmlandIncome)
{
    float taxTotalIncome = 0.f;
    float currentlyTaxed = collectTaxes * 20;
    float produceTax = farmlandIncome.displayCurrentTurnover(45, 12, 12.f, 10.f);

    std::cout << "Reporting tax collection my lord!\n";
    
    return taxTotalIncome = currentlyTaxed + produceTax;
}

void Castle::openCastleGates(int numberOfGatesClosed)
{
    if (numberOfGatesClosed <= 0)
    {
        std::cout << "All gates are already open.\n";
    }
    else
    {
        std::cout << "Opening " << numberOfGatesClosed << " gates...\n";
        std::cout << "Gates opened successfully!\n";
    }
}

std::string Castle::announceOrders(std::string orders)
{
    std::cout << "Here are the orders: " << orders << "\n";
    return orders;
}

/*
 copied UDT 2:
 */
struct RolandTB303
{
    int stepSequencer {16}, modeDial {10}, tempoDial {32};
    float cutoffFrequencyFilterKnob {750.f}, volumeKnob {-18.f};

    RolandTB303();
    ~RolandTB303();

    struct SavePattern
    {
        int numberOfSteps, tempoNumberSelected, loopCount;
        bool exportingToExternalDisk;
        float randomisationAmount;

        SavePattern();
        ~SavePattern();

        void savingSequence(int stepSize, int numberOfStepsEnabled, int numberOfLoops, int tempo);
        bool savingToExternal(int stepCount, std::string fileType = "TB303.p");
        void displaySavingProgress(int timeRemaining, float savingRate);
        void recallPattern(char X);
    };

    void programSequence(RolandTB303 sequence);
    void filterSignal(float cutoffFrequency);
    float tempoAdjust(RolandTB303 tempo);
    int syncMidi(int midiNotesIn);

    // New member function
    void displayVolume();
};

RolandTB303::RolandTB303()
{
    std::cout << "RolandTB303 being constructed!\n";  
}

RolandTB303::~RolandTB303()
{
    std::cout << "RolandTB303 being deconstructed.\n";
}

RolandTB303::SavePattern::SavePattern() : numberOfSteps(24), tempoNumberSelected(12), loopCount(8), exportingToExternalDisk(true), randomisationAmount(8.5f)
{
    std::cout << "SavePattern being constructed!\n";
}

RolandTB303::SavePattern::~SavePattern()
{
    std::cout << "SavePattern being deconstructed!\n";
}

// New member function
void RolandTB303::displayVolume()
{
    std::cout << "Volume level: " << this->volumeKnob << std::endl;
}
    
void RolandTB303::SavePattern::recallPattern(char X)
{    
    if (X == 'A')
    {
        std::cout << "Loading previous sequence... " << X << "\n";
        int sequenceMemory = 25;
        std::cout << "Sequence step total: " << sequenceMemory << "\n";
        
        for (int seq = 0; seq < 25; ++seq)
        {
            std::cout << "Step " << (seq + 1) << " loaded\n";
        }
    }
    else if (X == 'B')
    {
        std::cout << "Loading previous sequence... " << X << "\n";
        int sequenceMemory = 15;
        std::cout << "Sequence step total: " << sequenceMemory << "\n";
        
        for (int seq = 0; seq < 25; ++seq)
        {
            std::cout << "Step " << (seq + 1) << " loaded\n";
        }   
    }
    else if (X == 'C')
    {
        std::cout << "Loading previous sequence... " << X << "\n";
        int sequenceMemory = 41;
        std::cout << "Sequence step total: " << sequenceMemory << "\n";
        
        for (int seq = 0; seq < 25; ++seq)
        {
            std::cout << "Step " << (seq + 1) << " loaded\n";
        } 
    }
    else
    {
        std::cout << "Loading previous sequence ERROR...\n" << "Please try again...\n";
    }
}

int RolandTB303::syncMidi(int midiNotesIn)
{
    int totalMidiCount = midiNotesIn;
    
    for (int note = 0; note < midiNotesIn; ++note)
    {
        std::cout << "Syncing MIDI...\n";
        
        if (midiNotesIn != 0)
        {
            std::cout << "MIDI sync progress " << (note + 1) << " out of " << midiNotesIn << " \n" << "MIDI notes remaining before full sync " << (totalMidiCount -= 1) << " \n";
        }
    }
    return totalMidiCount;
}

void RolandTB303::SavePattern::savingSequence(int stepSize, int numberOfStepsEnabled, int numberOfLoops, int tempo)
{
    int savedSeq = stepSize + numberOfStepsEnabled + numberOfLoops + tempo;
    std::cout << "Saving sequence..." << savedSeq << "\n";
}

bool RolandTB303::SavePattern::savingToExternal(int stepCount, std::string fileType)
{
    if(stepCount > 0)
    {
        std::cout << "Exporting " << fileType << "\n";
        return true;
    }
    std::cout << "Export error, no steps" << "\n";
    return false;
}

void RolandTB303::SavePattern::displaySavingProgress(int timeRemaining, float savingRate)
{
    std::cout << "Time remaining: " << timeRemaining << " (secs)\n";
    std::cout << "saving data speed: " << savingRate << " kbps\n";
}

void RolandTB303::programSequence(RolandTB303 sequence)
{
    int displaySequenceCount = sequence.stepSequencer;
    std::cout << "Number of steps: " << displaySequenceCount << "\n";
}

void RolandTB303::filterSignal(float cutoffFrequency)
{
    std::cout << "Filter CutOff: " << cutoffFrequency << "Hz\n";
}

float RolandTB303::tempoAdjust(RolandTB303 tempo)
{    
    if (tempo.tempoDial > 0)
    {
        std::cout << "Tempo has been changed\n";
        return 15.f;
    }
    std::cout << "No tempo changes here...\n";
    return 1.f;
}
/*
 copied UDT 3:
 */
struct MidiKeyboard
{
    int numberOfKeys, numberOfKnobs, numberOfMPCPads;
    double pitchControlRange;
    char modeSelection;

    MidiKeyboard();
    ~MidiKeyboard();

    double adjustPitch(MidiKeyboard pitchChange);
    void isKeyPressed();
    float padHitAmount(MidiKeyboard padNumber);
    void ledLightDemoMode(std::string onOff);

    // New member functions
    void listTotalNumKeys();
    void displayPitchRange();
    void printPadsTotal();
};

MidiKeyboard::MidiKeyboard() : numberOfKeys(25), numberOfKnobs(16), numberOfMPCPads(4), pitchControlRange(300000.0), modeSelection('Y')
{
    std::cout << "MidiKeyboard being constructed!\n";  
}

MidiKeyboard::~MidiKeyboard()
{
    std::cout <<"MidiKeyboard being deconstructed!\n";
}

// New function
void MidiKeyboard::listTotalNumKeys()
{
    std::cout << "List number of keys: " << this->numberOfKeys << std::endl;
}

// New function
void MidiKeyboard::displayPitchRange()
{
    std::cout << "Available pitch control range: " << this->pitchControlRange << std::endl;
}

// New function
void MidiKeyboard::printPadsTotal()
{
    std::cout << "Programmable pads: " << this->numberOfMPCPads << std::endl;
}
    
void MidiKeyboard::ledLightDemoMode(std::string onOff)
{
    int totalLedsOnKeyboard = 1;
    
    if (onOff == "on")
    {
        for (int led = 0; led < totalLedsOnKeyboard; ++led)
        {
            std::cout << "**\n";
            std::cout << "     **\n";
            std::cout << "          **\n";
            std::cout << "               **\n";
            std::cout << "   PROGRAMMING      **\n";
            std::cout << "   FOR                   **\n";
            std::cout << "   MUSICIANS                  **\n";
            std::cout << "   IS                    **\n";
            std::cout << "   GREAT!           **\n";
            std::cout << "               **\n";
            std::cout << "          **\n";
            std::cout << "     **\n";
            std::cout << "**\n";
        }
    }
    else
    {
         std::cout << "*BLINK* please enter ""on"" for light demo\n";
    }
}

double MidiKeyboard::adjustPitch(MidiKeyboard pitchChange)
{    
    double adjustedPitch = pitchControlRange + pitchChange.pitchControlRange;
    std::cout << "Pitch adjusting!\n";
    return adjustedPitch;
}

void MidiKeyboard::isKeyPressed()
{
    std::cout << "Key input detected\n";
}

float MidiKeyboard::padHitAmount(MidiKeyboard padNumber)
{
    std::cout << "Pad number: " <<padNumber.numberOfMPCPads << "\n";
    std::cout << "BOY you hitting that pad haaaaard!!!\n";
    return 10.f;
}

/*
 new UDT 4:
 with 2 member functions
 */
struct Kingdom
{
    Kingdom();
    ~Kingdom();

    Castle myCastle;
    Castle::FarmlandRevenue farmlands;

    void defendCastle();
    void manageFarmlands();
};

void Kingdom::defendCastle()
{
    std::cout << "Orders to defend have been issued...\n";
    myCastle.announceOrders("Defend the castle!");
    myCastle.openCastleGates(0);  
    std::cout << "Castle gates now being closed...\n";
}

void Kingdom::manageFarmlands()
{
    std::cout << "Farmland management under way.\n";
    farmlands.displayCurrentTurnover(50, 25, 15.67f, 10.9f);
    int displayFarmlandSize = farmlands.arces;
    std::cout << "Current farmland area: "<< displayFarmlandSize << "\n";
}

Kingdom::Kingdom()
{
    // constructor
    std::cout << "The Kingdom is being constructed!\n";
}

Kingdom::~Kingdom()
{
    // decstructor
    std::cout << "The kingdom has fallen! Close the gates!\n";
    defendCastle();
}

/*
 new UDT 5:
 with 2 member functions
 */
struct MusicStore
{
    MusicStore();
    ~MusicStore();
    MidiKeyboard keyboards;
    RolandTB303::SavePattern bassSynths;

    void listKeyboardStock();
    void turnOnBassSynthDisplays();
};

MusicStore::MusicStore()
{
    // constructor
    std::cout << "Music store is open! Now listing keyboard inventory...\n";
    listKeyboardStock();
}

MusicStore::~MusicStore()
{
    // destructor
    std::cout << "The music store is now closing.\n";
}

void MusicStore::listKeyboardStock()
{
    std::cout << "Obtaining current keyboard stock level...\n";
    int totalKeyboardKeys = keyboards.numberOfKeys;
    if(totalKeyboardKeys > 200)
    {
        std::cout << "There are more than eight 25-key MIDI keyboards in stock!\n";
    }
    else
    {
        std::cout << "Less than eight 25-key MIDI keyboards in stock, list as stock running low\n";
    }
}

void MusicStore::turnOnBassSynthDisplays()
{
    std::cout << "Loading previous demo patterns...\n";
    bassSynths.recallPattern('B');
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    
    //------------------------------------------------------------------------------------------------------------------
    
    Castle castle;
    //1
    castle.announceOrders("Release the hounds!");
    std::cout << "names of royalty: " << castle.nameOfKing << " & " << castle.nameOfQueen << "\n";
    castle.displayNameOfKingAndQueen();

    //2
    castle.openCastleGates(4);
    std::cout << "total gates at castle: " << castle.numberOfGates << "\n";
    castle.printTotalNumGates();
    
    //3
    castle.reportCollectTaxes(10.f, Castle::FarmlandRevenue());
    std::cout << "tax collected: " << castle.amountOfTaxesCollected << "\n";
    castle.printTaxCollection();
    
    //4
    castle.fireSignalArrow(20, 8); // enter how many arrows first, then hit threshold requirement value
        
    //------------------------------------------------------------------------------------------------------------------
    Castle::FarmlandRevenue farmlandrev;

    //1
    farmlandrev.displayCurrentTurnover(30, 66, 12.f, 8.f);
    std::cout << "Current wholesale price of wheat per kg: " << farmlandrev.wheatSalePricePerKG << "\n";
    farmlandrev.printCurrentTurnover();
    
    //2
    farmlandrev.floodFarmlands(150, 23.f, true);
    std::cout << "Is the farmland in drought? 0 = no, 1 = yes: " << farmlandrev.isInDrought << "\n";
    farmlandrev.printDroughtStatus();
    
    //3
    farmlandrev.sellWheat(500, 21.f, 180.f);
    std::cout << "Current number of able workers: " << farmlandrev.numberOfWorkers << "\n";
    farmlandrev.listTotalNumWorkers();

    //4
    farmlandrev.hireNewWorkers(10, 3000); // enter number of workers and income threshold

    //------------------------------------------------------------------------------------------------------------------
    
    MidiKeyboard midikeyboard;

    //1
    midikeyboard.adjustPitch(MidiKeyboard());
    std::cout << "List number of keys: " << midikeyboard.numberOfKeys << "\n";
    midikeyboard.listTotalNumKeys();
    
    //2
    midikeyboard.isKeyPressed();
    std::cout << "Available pitch control range: " << midikeyboard.pitchControlRange << "\n";
    midikeyboard.displayPitchRange();
    
    //3
    midikeyboard.padHitAmount(MidiKeyboard());
    std::cout << "Programmable pads: " << midikeyboard.numberOfMPCPads << "\n";
    midikeyboard.printPadsTotal();
    
    //4
    midikeyboard.ledLightDemoMode("on"); // enter "on" for demo
    
    //------------------------------------------------------------------------------------------------------------------
    
    RolandTB303 rolandtb303;

    //1
    rolandtb303.filterSignal(3500.f);
    std::cout << "Volume level: " << rolandtb303.volumeKnob << "\n";
    rolandtb303.displayVolume();
    
    //2
    rolandtb303.programSequence(RolandTB303());
    
    //3
    rolandtb303.tempoAdjust(RolandTB303());

    //4
    rolandtb303.syncMidi(15); // enter number of midi notes
    
    //------------------------------------------------------------------------------------------------------------------
    
    RolandTB303::SavePattern savepattern;

    //1
    savepattern.displaySavingProgress(35, 50.f);

    //2
    savepattern.savingSequence(4, 8, 2, 120);
    
    //3
    savepattern.savingToExternal(8, "TB303.p");

    //4
    savepattern.recallPattern('C'); // enter 'A', 'B', 'C' to recall partern

    //------------------------------------------------------------------------------------------------------------------

    Kingdom kingdom;

    //1
    kingdom.manageFarmlands();

    //2
    kingdom.defendCastle();

    //------------------------------------------------------------------------------------------------------------------

    MusicStore musicStore;

    //1 
    musicStore.turnOnBassSynthDisplays();

    //2
    musicStore.listKeyboardStock();

    //------------------------------------------------------------------------------------------------------------------

    std::cout << "good to go!" << std::endl;
}