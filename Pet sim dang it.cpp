#include <iostream>
#include <string>
using namespace std;

 // max stats value
//happiness -------------------------------------------------------------------------------------------------------------------
const int maxHappiness = 10;
const int minHappiness = 0;

//hunger ----------------------------------------------------------------------------------------------------------------------
const int maxHunger = 10; // basically starving
const int minHunger = 0; // full tummy sit

//rest ------------------------------------------------------------------------------------------------------------------------
const int maxRest = 10;
const int minRest = 0;

//energy ----------------------------------------------------------------------------------------------------------------------
const int maxEnergy = 10;
const int minEnergy = 0;

//health ----------------------------------------------------------------------------------------------------------------------
const int maxHealth = 10;
const int minHealth = 0;


void displayStats(int&happiness, int&hunger, int&energy, int&rest, int&health);
void play(int& energy, int& happiness, int& rest, int& health, int& hunger);
void feed(int& hunger, int& happiness, int&rest, int& health, int&energy);
void sleep(int& rest, int& happiness, int& hunger, int& health, int&energy);
char interact() {
    char input;
    cout << "1: Play" << endl;
    cout << "2: Feed" << endl;
    cout << "3: Rest" << endl;
    cout << "4: Exit" << endl;
    cout << "Input your choice (1-4): ";
    cin >> input;
    cout << endl;
    return input;
}
// MAIN FUNCTION --------------------------------------------------------------------------------------------------------------
int main() {
    char input;
//initial attributes ----------------------------------------------------------------------------------------------------------
    int happiness = 5;
    int hunger = 5;
    int energy = 10;
    int rest = 0;
    int health = 10;

    while (true) {
        displayStats(happiness, hunger, energy, rest, health);
        input = interact();

        switch (input) {
        case '1':
            play(energy, happiness, rest, health, hunger);
            break;

        case '2':
            feed(hunger, happiness, rest, health, energy);
            break;

        case '3':
            sleep(rest, happiness, hunger, health, energy);
            break;

        case'4':
            cout << "Exiting the game... Goodbye!" << endl;
            return 0;

        default:
            cout << "Invalid input! Please try again!";
        }

        // HEALTH CHECK ------------------------------------------------------------------------------------------------------------
        
        if (health <= 8) {
            displayStats(happiness, hunger, energy, rest, health);
            cout << "YOUR PET'S HEALTH IS SLOWLY DECREASING!!!" << endl;
            cout << endl;
        }
        if (health <= 3) {
            displayStats(happiness, hunger, energy, rest, health);
            cout << endl;
            cout << "Your pet is on the verge of death! MAKE HIM REST!" << endl;
            cout << endl;
        }
        if (health <= 0) {
            health = minHealth;
            displayStats(happiness, hunger, energy, rest, health);
            cout << "Your pet has died! Game over!" << endl;
            return 0;
        }
    }
    return 0;
}


//display stats ---------------------------------------------------------------------------------------------------------------
void displayStats(int& happiness, int& hunger, int& energy, int& rest, int& health) {
    string status;
    

    cout << "<==||=====================================================================>" << endl;
    cout << "Welcome to VIRTUAL PET CARE SIMULATOR!" << "\t" << endl;
    cout << "This is your pet's status:" << endl; // pet status ---------------------------------------------------------------
    cout << endl;
    cout << "Happiness: " << happiness << endl; // increased happiness, decreased energy --------------------------------------
    cout << "Hunger: " << hunger << endl; // belly full increased, decreased health if exceeds to 10 --------------------------
    cout << "Energy: " << energy << endl; // play (energy decreased, increased happiness) -------------------------------------
    cout << "Rest: " << rest << endl; // energy increased, decreased hunger ---------------------------------------------------
    cout << "Health: " << health << endl; // overall health -------------------------------------------------------------------
    cout << "<==||=====================================================================>" << endl;
    cout << endl;
}

// happinesss will increase if play, decreased energy -------------------------------------------------------------------------
void play(int& energy, int& happiness, int& rest, int&health, int&hunger) {
   
    if (hunger <= 0) {
        hunger = 0;
    }
    if (rest == 0) {
        cout << "Your pet needs to sleep!!" << endl;
        return;
    } else if (hunger >= 10) {
        cout << "Your pet is starving!! Your pet's HP is decreasing!!" << endl;
        health -= 2;
    }
    else {
        happiness >= maxHappiness;
        happiness += 1;
        rest -= 2;
        energy -= 2;
        hunger += 2;
    }

    if (energy <= 0) {
        energy = minEnergy;
        cout << "Your pet is tired!! do something!!" << endl;
    } 
       
    
}

//hunger will decreased if fed, increased if not fed --------------------------------------------------------------------------
void feed(int& hunger, int& happiness, int&rest, int&health, int&energy) {

    if (hunger <= 0) { // if the pet is full and getting bloated lmao
        hunger = 0;
        cout << "Your pet is already full! Happiness decreased to: " << happiness << endl;
        cout << endl;
    }
    // rest cap
    if (rest == 0) {
        rest = minRest;
      
        cout << "Your pet needs to SLEEP first before eating!" << endl;
        cout << endl;
    }
    else {       
        hunger -= 5;
        hunger <= 0;
        hunger <= minHunger;
        cout << "Your pet is well fed" << endl;
    }
}

// energy and rest will increase if slept, decreased if not slept -------------------------------------------------------------
void sleep(int& rest, int& happiness, int& hunger, int&health, int&energy) {

    rest < maxRest;
    rest += 10;
    energy += 10;
    hunger += 5;

    cout << "Your pet is sleeping peacefully...." << endl;
    cout << endl;
    //max hunger cap
    if (hunger >= 10) {
        hunger = maxHunger;
    }
    // max rest cap
    if (rest > 10) {
        rest = maxRest;
        health -= 2;
    }
    // max energy cap
    if (energy >= 10) {
        energy = maxEnergy;
    }
}