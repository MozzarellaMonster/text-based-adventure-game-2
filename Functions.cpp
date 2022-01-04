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

void print_line(){
    cout << "\n\n============================================\n";
}

void try_again(){
    cout << "\nSorry, that is not a valid option, please try again.\n";
}

void start(){
    cout << "_________          _______   _________ _______  _______  _______  _        _______ \n";
    cout << "\\__   __/|\\     /|(  ____ \\  \\__   __/(  ____ \\(       )(  ____ )( \\      (  ____ \\\n";
    cout << "   ) (   | )   ( || (    \\/     ) (   | (    \\/| () () || (    )|| (      | (    \\/\n";
    cout << "   | |   | (___) || (__         | |   | (__    | || || || (____)|| |      | (__    \n";
    cout << "   | |   |  ___  ||  __)        | |   |  __)   | |(_)| ||  _____)| |      |  __)   \n";
    cout << "   | |   | (   ) || (           | |   | (      | |   | || (      | |      | (      \n";
    cout << "   | |   | )   ( || (____/\\     | |   | (____/\\| )   ( || )      | (____/\\| (____/\\\n";
    cout << "   )_(   |/     \\|(_______/     )_(   (_______/|/     \\||/       (_______/(_______/\n\n\n";
                                                                                   
    
    
    
    
    print_line();
    cout << "After wandering through the jungle for an immeasurable amount of time, you come across a strange temple.\n";
    cout << "The temple is constructed of what appears to be large, polished black stone bricks with numerous strange engravings in them.\n";
    cout << "The stone bricks are so well-polished in fact, that you can actually see your reflection in them.\n";
    cout << "An ornate stone archway is set into the temple, but is currently blocked by what appears to be a large slab of stone.\n";
    cout << "A stone pedestal stands before you holding a bowl of fire, seemingly burning some kind of charcoal.\n";
    cout << "Exactly how the bowl of fire is burning when you have not come across anyone that could have started it is strange,\nbut you've already seen enough weird stuff to not question it further.\n";
    cout << "There is an engraving below the pedestal, but you have cannot read the strange writing.\n";
    cout << "An ornate dagger lies in a small recess beneath the inscription, seemingly made of an iron-like metal.\n";
    first_choice();
}

void first_choice(){
    char choice;
    print_line();
    cout << "Do you wish to take the dagger? Y/N: ";
    cin >> choice;

    if(choice == 'Y' || choice == 'y'){
        cout << "You take the dagger out of the recess.\n";
        cout << "Upon closer inspection, you notice there are strange glyphs in the center of the blade.\n";
        cout << "The glyphs appear to be similar to the glyphs you saw on the stone ring in the basement of The House.\n";
        cout << "You slowly run your thumb over the strange symbols.\n";
        cout << "Suddenly, the glyphs glow a menacing red and you feel a sudden urge to cut your hand.\n";
        cout << "The urge steadily grows until you deftly slice open the palm of your left hand.\n";
        cout << "Complete surprise overtakes you for a moment as you process what you have just done until you suddenly and involuntarily thrust your hand over the bowl of fire\n and squeeze several large drops of your own blood into the waiting flames below.\n";
        cout << "The blood sizzles as it hits the hot coals and the fire astoundingly changes colors into a deep red before quickly reverting back.\n";
        cout << "Remarkably, the cut on your left palm has sealed completely with no visible scars, as if it was never there.\n";
        cout << "You stand still for a while, flexing your hand and running your fingers over your smooth, unharmed palm.\n";
        cout << "\"Things could not get any weirder,\" you think to yourself.\n";
        cout << "Suddenly, the stone slab blocking the entrance into the temple slides up, opening into the dark interior of the temple.\n";
        cout << "You stand there for a moment, then state, \"Aaand it just did.\"\n";
        cout << "You pick the dagger back up and store it on your person.\n";
        inventory.push_back(Items::dagger);
        temple_entrance();
    }
    else if(choice == 'N' || choice == 'n'){
        cout << "You decide against taking the dagger.\n";
        cout << "You look around and decide to get a better grasp of your surroundings.\n";
        cout << "You head back into the jungle.\n\n";
        print_line();
        cout << "SEVERAL MINUTES LATER\n";
        print_line();
        cout << "You look up after wandering through the jungle again only to find that you're back at the temple.\n";
        cout << "Well, looks like you're back at square one.\n";
        first_choice();
    }
    else{
        try_again();
        first_choice();
    }
}

void temple_entrance(){
    char choice;
    print_line();
    cout << "After making your choice, you turn back to the now-open temple entrance.\n";
    cout << "Something catches your eye however, and you turn to look at the pedestal holding the bowl of fire.\n";
    cout << "Somehow, the symbols now makes sense to you.\n";
    cout << "The engraved text reads \"An offering needed to gain insight and entrance\".";
    cout << "\"So,\" you think to yourself, \"now I can understand that language and enter the temple.\"";
    cout << "Will you go into the temple? ";
    cin >> choice;
    if(choice == 'Y' || choice == 'y'){
        cout << "You head deeper into the temple.";
    }
    else{
        cout << "You decide against going into the temple.";
    }
}

void temple_first_room_text(){
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
    temple_first_room();
}

void temple_first_room(){
    char choice;
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
        
        cin >> second_choice;
        if(second_choice == 'A' || second_choice == 'a'){

        }
    }
    else if(choice == 'B' || choice == 'b'){
        //cout << ""
    }
    else if(choice == 'C' || choice == 'c'){

    }
    else{
        try_again();
        temple_first_room();
    }
}