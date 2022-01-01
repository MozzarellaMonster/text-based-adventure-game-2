//Function definitions for the main game file.
#include <iostream>
#include <vector>

#include "The Temple.cpp"
#include "Functions.hpp"

using namespace std;

vector<Items> inventory;

string bleh(){
    return "Bleh.";
}

void outside_temple(){
    char choice;
    
    cout << "After wandering through the jungle for an immeasurable amount of time, you come across a strange temple.";
    cout << "The temple is constructed of what appears to be large, polished black stone bricks with numerous strange engravings in them.";
    cout << "The stone bricks are so well-polished in fact, that you can actually see your reflection in them.";
    cout << "A yawning dark doorway opens into the interior of the temple. A simple stone pedestal stands before you holding a bowl of fire.";
    cout << "\n\n";
    cout << "An engraving in the pedestal below the bowl of fire reads: Fire burns as the brightest light, give yourself to it and be given sight.";
    cout << "An ornate iron dagger lies in a small recess beneath the inscription.";
    cout << "Take the dagger? Y/N: ";
    cin >> choice;

    if(choice == 'Y' || choice == 'y'){

        cout << "You take the dagger out of the recess.";
        cout << "Upon closer inspection, you notice there are strange glyphs in the center of the blade.";
        cout << "The glyphs appear to be similar to the glyphs you saw on the stone ring in the basement of The House.";
        cout << "You slowly run your thumb over the strange symbols.";
        cout << "Suddenly, the glyphs glow a menacing red and you feel a sudden urge to cut your hand.";
        cout << "The urge steadily grows until you deftly slice open the palm of your left hand.";
        cout << "Complete surprise overtakes you for a moment as you process what you have just done until you suddenly and involuntarily thrust your hand over the bowl of fire\n and squeeze several large drops of your own blood into the waiting flames below.";
        cout << "The bloods sizzles as it hits the hot coals and the fire astoundingly changes colors into a deep red before quickly reverting back.";
        cout << "Instantly, your eyes begin to burn as if they too were exposed to the flames. You drop the dagger as your hands shield your eyes and you scream in pain.";
        cout << "The pain is gone quickly however, and you slowly open your eyes again. Blinking slowly, the world falls back into focus as your eyes adjust to the light of day once again.";
        cout << "As far as you can tell, your eyes are completely fine and your visual acuity is the same as before.";
        cout << "Remarkably, the cut on your left palm has sealed completely with no visible scars, as if it was never there.";
        cout << "You stand still for a while, flexing your hand and running your fingers over your smooth, unharmed palm.";
        cout << "\"Things could not get any weirder,\" you think to yourself.";
        cout << "You pick the dagger back up and enter into the temple.";
        inventory.push_back(Items::dagger);
    }
    else{

        cout << "You decide against taking the dagger.";
        cout << "Strangely, you get a sense that the dagger might be important later.";
        cout << "Still, you've made your decision, right?";
        cout << "Do you want to take the dagger?";
        cin >> choice;
        if(choice == 'Y' || choice == 'y'){

            inventory.push_back(Items::dagger);
            temple_entrance();
        }
        else{
            temple_entrance();
        }
    }
}

void temple_entrance(){
    char choice;
    cout << "Will you go into the temple? ";
    cin >> choice;
    if(choice == 'Y' || choice == 'y'){

        cout << "You head deeper into the temple.";
    }
    else{

        cout << "You decide against going into the temple.";
    }
}

void temple_first_room(){
    char choice;
    cout << "You enter the temple and find yourself in a dimly lit room."; 
    cout << "There is a small bowl of fire on a pedestal in the very center of the room and no other source of light, save for the open doorway you're standing in.";
    cout << "Cautiously, you step into the room. When you're about halfway toward the pedestal in the middle of the room, the doorway suddenly shuts as a huge slab of stone slides over the entrance, completely sealing you in.";
    cout << "Well, looks like you're stuck here now, might as well examine the room more.";
    cout << "You notice a recess set into the pedestal below the bowl. Inside, there is a brown polished stone with a strange glyph carved into it."; 
    cout << "You pick it up and examine it closely. Suddenly, the glyph morphs into the word \"Answer\" right before your eyes.";
    cout << "You blink, but the word has disappeared and the symbol has returned. You gently set the stone back inside the recess and look around the room.";
    cout << "The room itself is pretty barren, composed entirely of smooth stone save for three symbols set into each of the walls beside the one containing the entryway.";
    cout << "Suddenly, the room grows dimmer as the fire quickly wanes and abruptly dies only to fiercely reignite only moments later with a blazing blue light.";
    cout << "An loud voice suddenly booms from out of nowhere, as you quickly slam your hands over your ears. It doesn't help however, as it seems the voice is coming directly from inside your head.";
    cout << "\"";
    cout << "\"Unhindered, I can destroy cities, yet tamed I supply them. I carve the very Earth, yet flesh does not yield. I reign over the many kingdoms of man, for I have seen them all.\"";
    cout << "\"For millennia you have tried to control me, to confine me, yet you are the greatest prisoner, for you cannot live without me.\"";
    cout << "You take a closer look at the symbols around the room. One appears to be a stylized gust of wind, another is clearly a flame, and the last appears to be running water.";

    cout << "Do you want to try and solve the riddle now or do you want to look around the room more?";
    cout << "A. I'll try to solve the riddle now.";
    cout << "B. I want to look around the room more.";
    cout << "C. What about the entrance?";
    cin >> choice;

    if(choice == 'a' || choice == 'A'){
        char second_choice;

        cout << "You decide you want to try and solve the riddle now.";
        cout << "Of the three symbols on the walls, you decide to choose: ";
        cout << "A. Wind";
        cout << "B. Fire";
        cout << "C. Water";
    }
}