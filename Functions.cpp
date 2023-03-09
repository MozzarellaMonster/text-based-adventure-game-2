//Function definitions for the main game file.
#include <iostream>
#include <string>
#include <vector>

#include "Functions.hpp"
#include "Items.hpp"
#include "Trackers.hpp"
#include "Journal Entries.hpp"
#include "Heart_of_the_Colony.hpp"

using namespace std;

vector<string> inventory;

void print_line(){
    cout << "\n==============================================================================================\n";
}

void try_again(){
    cout << "\nSorry, that is not a valid option, please try again.\n";
}

void reset(){
    // Once all trackers are determined, use this function to reset them upon a retry.
}

void retry(){
    char choice;
    cout << "\nWould you like to play again? Y/N: ";
    cin >> choice;
    if(choice == 'Y' || choice == 'y'){
        cout << "\n\nRESTARTING...\n\n";
        //reset();
        start();
    }
    else if(choice == 'N' || choice == 'n'){
        exit(0);
    }
    else{
        try_again();
        retry();
    }
}

void retry(void (*func)()){
    char choice;
    cout << "\nRetry from the last room? Y/N: ";
    cin >> choice;
    if(choice == 'Y' || choice == 'y'){
        func();
    }
    else if(choice == 'N' || choice == 'n'){
        retry();
    }
    else{
        try_again();
        retry(func);
    }
}

// Function for handling the player options, to be added to later
void present_options(vector<string> option_names, vector<string> dialogue, void (*func)()){
    char choice;
    print_line();
    cout << "A." << option_names[0];
    cout << "B." << option_names[1];
    cout << "C." << option_names[2];
    print_line();
    cin >> choice;

    if(choice == 'a' || choice == 'A'){

    }
    else if(choice == 'b' || choice == 'B'){

    }
    else if(choice == 'c' || choice == 'C'){

    }
    else{
        try_again();
        func();
    }
}

void archway(string message, string name, bool *archway_read, void (*func)()){
    char answer;

        if(!(*archway_read)){
            print_line();
            cout << message;
            if(!saw_archway){
                cout << shimmer;
            }
            *archway_read = true;
            saw_archway = true;
        }
        else{
            print_line();
            cout << "\nYou approach " << name << "\n";
        }

        cout << "\nDo you want to enter the archway? Y/N: ";
        cin >> answer;
        cout << "\n";
        if(answer == 'Y' || answer == 'y'){
            cout << "\nYou take a step forward and enter " << name << "\n";
            func();
        }
        else if(answer == 'N' || answer == 'n'){
            cout << "\nYou decide not to go in and return to the center of the room.\n";
            temple_second_room();
        }
        else{
            try_again();
            temple_second_room();
        }
}

void deposit(){
    string key;
    print_line();
    for(int i = 0; i < inventory.size(); i++){
        for(int j = 0; j < sizeof(keys); j++){
            if(inventory[i] == keys[j]){
                key = inventory[i];
                inventory.erase(inventory.begin() + (i-1));
                break;
            }
        }
    }
    if(key != ""){
        cout << "\nYou place the " << key << " into the monolith and turn back to the room.\n";
    }
    return;
}

void determine_riddle(){
    set_riddle = rand() % 3 + 1;
    switch(set_riddle){
        case 1:
            current_riddle = water_riddle;
            break;
        case 2:
            current_riddle = wind_riddle;
            break;
        case 3:
            current_riddle = fire_riddle;
            break;
        default:
            current_riddle = water_riddle;
    }
}

bool inv_contains(string object){
    for(int i = 0; i < inventory.size(); i++){
        if(inventory[i] == object){
            return true;
        }
    }
    return false;
}

void start(){
    print_line();
    cout << "_________          _______   _________ _______  _______  _______  _        _______ \n";
    cout << "\\__   __/|\\     /|(  ____ \\  \\__   __/(  ____ \\(       )(  ____ )( \\      (  ____ \\\n";
    cout << "   ) (   | )   ( || (    \\/     ) (   | (    \\/| () () || (    )|| (      | (    \\/\n";
    cout << "   | |   | (___) || (__         | |   | (__    | || || || (____)|| |      | (__    \n";
    cout << "   | |   |  ___  ||  __)        | |   |  __)   | |(_)| ||  _____)| |      |  __)   \n";
    cout << "   | |   | (   ) || (           | |   | (      | |   | || (      | |      | (      \n";
    cout << "   | |   | )   ( || (____/\\     | |   | (____/\\| )   ( || )      | (____/\\| (____/\\\n";
    cout << "   )_(   |/     \\|(_______/     )_(   (_______/|/     \\||/       (_______/(_______/\n\n\n";
                                                                                   
    cout << "A game by MozzarellaMonster.\n"
            "Hello! Welcome to the sequel to The House!\n"
            "Hopefully you enjoy it and have as much fun as I did making it!\n\n";
    
    print_line();
    cout << "After wandering through the jungle for an immeasurable amount of time, you come across a strange temple.\n"
            "The temple is constructed of what appears to be large, polished black stone bricks with numerous strange engravings in them.\n"
            "The stone bricks are so well-polished in fact, that you can actually see your reflection in them.\n"
            "An ornate stone archway is set into the temple, but is currently blocked by what appears to be a large slab of stone.\n"
            "A stone pedestal stands before you holding a bowl of fire, seemingly burning some kind of charcoal.\n"
            "Exactly how the bowl of fire is burning when you have not come across anyone that could have started it is strange,\nbut you've already seen enough weird stuff to not question it further.\n"
            "There is an engraving below the pedestal, but you have cannot read the strange writing.\n"
            "An ornate dagger lies in a small recess beneath the inscription, seemingly made of an iron-like metal.\n";
    first_choice();
}

void first_choice(){
    char choice;
    print_line();
    cout << "Do you wish to take the dagger? Y/N: ";
    cin >> choice;
    cout << "\n";

    if(choice == 'Y' || choice == 'y'){
        print_line();
        cout << "You take the dagger out of the recess.\n"
                "Upon closer inspection, you notice there are strange glyphs in the center of the blade.\n"
                "The glyphs appear to be similar to the glyphs you saw on the stone ring in the basement of The House.\n"
                "You slowly run your thumb over the strange symbols.\n"
                "Suddenly, the glyphs glow a menacing red and you feel a sudden urge to cut your hand.\n"
                "The urge steadily grows until you deftly slice open the palm of your left hand.\n"
                "Complete surprise overtakes you for a moment as you process what you have just done until you suddenly and involuntarily thrust your hand over the bowl of fire\n and squeeze several large drops of your own blood into the waiting flames below.\n"
                "The blood sizzles as it hits the hot coals and the fire astoundingly changes colors into a deep red before quickly reverting back.\n"
                "Remarkably, the cut on your left palm has sealed completely with no visible scars, as if it was never there.\n"
                "You stand still for a while, flexing your hand and running your fingers over your smooth, unharmed palm.\n"
                "Well, things couldn't get any stranger.\n"
                "Suddenly, the stone slab blocking the entrance into the temple slides up, opening into the dark interior of the temple.\n"
                "You stand still for a moment, looking at the entrance. Then, you pick the dagger back up and store it on your person.\n";
        inventory.push_back(dagger);
        temple_entrance();
    }
    else if(choice == 'N' || choice == 'n'){
        print_line();
        if(jungle_repeat > 2){
            cout << "You decide against taking the dagger.\n"
                    "You look around and decide to get a better grasp of your surroundings.\n"
                    "You head back into the jungle.\n\n"
                    "XXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
                    "   SEVERAL MINUTES LATER\n"
                    "XXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
                    "\nYou look up after wandering through the jungle expecting to see the temple again, but there is nothing there.\n"
                    "You walk up to where the temple should be only to find an empty clearing.\n"
                    "You turn around, hoping the temple will just miraculously appear again, but nothing happens.\n"
                    "You stay there for several minutes, an hour, two hours, but there is still no temple.\n"
                    "Whatever chance you had for progress is now lost.\n"
                    "As are you. Forever.\n";

            cout << "\n\nEnding 1: Forever Lost";
            print_line();
            retry();
        }
        else{
            cout << "You decide against taking the dagger.\n"
                    "You look around and decide to get a better grasp of your surroundings.\n"
                    "You head back into the jungle.\n\n"
                    "XXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
                    "   SEVERAL MINUTES LATER\n"
                    "XXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
                    "\nYou look up after wandering through the jungle again only to find that you're back at the temple.\n"
                    "Well, looks like you're back at square one.\n";
            jungle_repeat++;
            first_choice();
        }
    }
    else{
        try_again();
        first_choice();
    }
}

void temple_entrance(){
    char choice;
    print_line();
    cout << "After making your choice, you turn back to the now-open temple entrance.\n"
            "Something catches your eye however, and you turn to look at the pedestal holding the bowl of fire.\n"
            "Somehow, the symbols now makes sense to you.\n"
            "The engraved text reads:\n\n\tAn offering needed to gain insight and entrance\n\n";
    print_line();
    cout << "Will you go into the temple? Y/N: ";
    cin >> choice;
    cout << "\n";

    if(choice == 'Y' || choice == 'y'){
        print_line();
        cout << "You head deeper into the temple.\n\n";
        temple_first_room_text();
    }
    else if(choice == 'N' || choice == 'n'){
        cout << "You decide against going into the temple, instead opting to explore your location more.\n\n"
                "You look around more and come across a rucksack half-buried in the dense foliage.\n"
                "You pull it out and search the pockets. You find an old map, a broken watch, and a piece of paper.\n"
                "The old map is nearly useless, as it is so worn and faded that all you can really see are faint gridlines and the border.\n"
                "The broken watch is even more useless since the casing seemingly broke open long ago and all the internal mechanisms have now fallen completely apart.\n"
                "The piece of paper is actually the most interesting of the junk you find. There's something written on it in in crooked, barely legible script.\n"
                "It reads:\n";
        cout << journal_entry_1;
        cout << "You fold up the piece of paper and stash it on your person.\n";
        inventory.push_back(first_note);
        cout << "You head back to the temple entrance and step inside.\n";
        temple_first_room_text();
    }
    else{
        try_again();
        temple_entrance();
    }
}

void temple_first_room_text(){
    determine_riddle();
    print_line();
    cout << "You enter the temple and find yourself in a dimly lit room.\n"
            "There is a small bowl of fire on a pedestal in the very center of the room and no other source of light, save for the open doorway you're standing in.\n"
            "Cautiously, you step into the room. When you're about halfway toward the pedestal in the middle of the room, the doorway suddenly shuts as a huge slab of stone slides over the entrance, completely sealing you in.\n"
            "Well, looks like you're stuck here now, might as well examine the room more.\n"
            "The room is pretty barren, composed entirely of smooth stone save for three symbols set into each of the walls beside the one containing the entryway.\n"
            "A loud voice suddenly booms from out of nowhere, as you quickly slam your hands over your ears. It doesn't help however, as it seems the voice is coming directly from inside your head.\n\n";
    cout << current_riddle << "\n";
    cout << "\nYou take a closer look at the symbols around the room. One appears to be a stylized gust of wind, another is clearly a flame, and the last appears to be running water.\n\n";
    temple_first_room();
}

void temple_first_room(){
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. I'll try to solve the riddle now\n";
    cout << "B. I want to look around the room more\n";
    cout << "C. Look at the entrance\n";
    print_line();
    cin >> choice;

    if(choice == 'A' || choice == 'a'){
        char second_choice;
        print_line();
        cout << "You decide you want to try and solve the riddle now.\n";
        cout << "The riddle is:\n\n";
        cout << current_riddle << "\n";
        cout << "\nOf the three symbols on the walls, you decide to choose: \n\n";
        cout << "A. Wind\n";
        cout << "B. Fire\n";
        cout << "C. Water\n\n";
        print_line();
        
        cin >> second_choice;
        if(second_choice == 'A' || second_choice == 'a'){
            print_line();
            cout << "You choose Wind.\n";
            if(set_riddle != 1){
                cout << "You walk up to the Wind symbol on the wall and gently touch it with your hand.\n"
                        "Almost immediately, you feel gusts of air blowing from somewhere within the small room.\n"
                        "Suddenly, the ceiling of the room opens up and several thousand leaves are dumped into the room.\n"
                        "You move to brush off the ones that fell on you, but immediately pull your hand away when you feel a sharp pain.\n"
                        "You quickly draw back your hand and look at the deep gash oozing blood over your palm.\n"
                        "It's then you notice that the leaf stuck on your shirt is... embedded in the fabric.\n"
                        "Small but wickedly sharp serrations can be seen lining the edge of the leaf and have been entangled in the cloth of your shirt.\n"
                        "You attempt to peel the leaf off with your fingernail, but only succeed in cutting the sensitive flesh underneath.\n"
                        "You pull your finger away, but before you do that, you realize the leaf was surprisingly stiff and sturdy, like a piece of metal.\n"
                        "Then with growing horror, you realize that the gusts of air are growing stronger and the leaves are slowly starting to twirl around the room.\n"
                        "You rush to the still-sealed entrance of the room and fruitlessly pound on the large stone slab keeping it closed.\n"
                        "The wind picks up even more, and the leaves dance freely around the room.\n"
                        "You feel the fabric of your clothes tear as the leaves cut cleanly through them.\n"
                        "You continue to helplessly pound on the stone slab, tears now pouring freely from your eyes.\n"
                        "The wind is now a forceful gale and tosses the leaves violently around the room.\n"
                        "Pain soon floods every part of your nearly exposed body as the leaves effortlessly tear open your skin.\n"
                        "You pound on the stone slab and scream for help, but you can't even hear yourself over the howling wind.\n"
                        "You scream and scream until you feel a leaf cut cleanly through both of your cheeks as another slices open your throat.\n"
                        "Blood fills your throat as you let out one more scream that comes out more as a pathetic gurgle.\n"
                        "You fall forward on the ground and faintly feel your ear get cut away as a leaf embeds itself in your eye.\n"
                        "Your world is reduced to nothing but pain as your vision fades and you hear a voice in your head before everything fades to black.\n"
                        "\"Wrong answer.\"\n";

                cout << "\n\nEnding 2: Shredded";
                print_line();
                retry(&temple_first_room_text);
            }
            else{
                cout << correct_riddle;
                temple_second_room_text();
            }
        }
        else if(second_choice == 'B' || second_choice == 'b'){
            print_line();
            cout << "You choose Fire.\n";
            if(set_riddle != 2){
                cout << "You walk up to the Fire symbol and gently touch it with your hand.\n"
                        "After some time passes with seemingly nothing happening, you slowly back up and look quickly around the room.\n"
                        "Nothing seems out of place or anything, but then you notice that something did change.\n"
                        "The room feels hotter.\n"
                        "It is then that you notice small heat waves emanating from the cracks in the stone floor.\n"
                        "You quickly stoop down and place your hand near one of the cracks. Intense heat brushes over the skin of your palm.\n"
                        "Suddenly, a stone brick in the floor directly in front of you gives way and falls down, revealing a fiery inferno underneath.\n"
                        "Soon, more bricks start to fall into the flames beneath, each faster than the last.\n"
                        "Quickly, you scan what little of the room remains to stand on and notice the pedestal is resting on a sturdy pillar of rock.\n"
                        "You deftly jump over to it and hold on to it as the rest of the room's floor falls away.\n"
                        "It's so hot now, you can barely breathe. Fire rages all around you. There's nowhere to run, nowhere to stand, nowhere to go.\n"
                        "The raging inferno grows bigger, billows of flame lick at the soles of your shoes.\n"
                        "You tilt your head back and finally scream.\n"
                        "As your skin melts away and the flames scorch your flesh, you hear a voice in your head.\n"
                        "\"Wrong answer.\"\n";

                cout << "\n\nEnding 3: Cremation Mk.2";
                print_line();
                retry(&temple_first_room_text);
            }
            else{
                cout << correct_riddle;
                temple_second_room_text();
            }
        }
        else if(second_choice == 'C' || second_choice == 'c'){
            print_line();
            cout << "You choose Water.\n";
            if(set_riddle != 0){
                cout << "You walk up to the Water symbol and gently touch it with your hand.\n"
                        "Nothing happens for several seconds, until you hear a roar right above you.\n"
                        "Your head snaps up to look at the ceiling where you see that several apertures have opened above you, allowing several gallons of water to start pouring in.\n"
                        "You quickly try to avoid the deluge, but there's nowhere to run. Instead, you climb the pedestal in the center of the room holding the now-extinguished bowl.\n"
                        "You watch with growing horror as the water level rises quickly, with no other option, you attempt to bang on the ceiling, to no avail.\n"
                        "The water level is now at chest level, and there is nothing left to do but scream.\n"
                        "You scream and scream, but no help comes.\n"
                        "As the water rises indifferently, you take a final gasp of air before the water finally fills the room.\n"
                        "You struggle to hold your breath, but you can feel your lungs burning for air.\n"
                        "You hold back for as long as you can, but you can't hold on forever. You open your mouth and inhale the cold water.\n"
                        "As your vision fades and the cold invades your body, you hear a voice in your head.\n"
                        "\"Wrong answer.\"\n";

                cout << "\n\nEnding 4: Drowned";
                print_line();
                retry(&temple_first_room_text);
            }
            else{
                cout << correct_riddle;
                temple_second_room_text();
            }
        }
        else{
            try_again();
            temple_first_room();
        }
    }
    else if(choice == 'B' || choice == 'b'){
        print_line();
        if(first_room_explored){
            cout << "You quickly look around the room again, but you're sure you've already examined everything.\n"
                    "You turn back to the room.\n";
            temple_first_room();
        }
        else{
            cout << "You decide to look around the room more.\n"
                    "You look closer at the symbols on the walls: there's the wind symbol on the left wall, the water symbol on the wall directly opposite you and the fire symbol on the right wall.\n"
                    "Other than the fact that the symbols seemed to be etched out of the wall itself, there doesn't seem to be anything else interesting about them.\n"
                    "You also examine the pedestal in the center of the room and notice that there is a little piece of paper sticking out from a small crack between the pedestal and the floor.\n"
                    "You gently pull it out and read what it says:\n\n";
            cout << hint;
            cout << "\nYou flip the paper over and examine the back, but there is nothing else to read.\n"
                    "You gently fold the piece of paper up and look back to the room.\n";
            first_room_explored = true;
            temple_first_room();
        }
    }
    else if(choice == 'C' || choice == 'c'){
        print_line();
        cout << "You look back to the entryway. The huge stone slab remains, sealing you in the temple.\n";
                "You sigh and turn back to the room.\n";
        temple_first_room();
    }
    else{
        try_again();
        temple_first_room();
    }
}

void temple_second_room_text(){
    print_line();
    cout << "You step into the much larger room and look around.\n"
            "Spaced evenly around the perimeter of the room are seven stone archways.\n"
            "All of the archways have intricate carvings adorning them, each of them depicting different scenes.\n"
            "One archway appears to have faces carved into the smooth, black stone. The room appears to be named \"The Desert of the Dea\".\n"
            "Another appears to be adorned with carvings of insects and reads \"The Room of the Swarm\".\n"
            "There are more rooms, but they are too far away to clearly read the names of them.\n"
            "Instead, you focus on the center of the room where an imposing stone obelisk stands.\n"
            "You approach the obelisk and are able to make out the few lines of text on it.\n\n"
            "\tBring forth six tokens from the six paths, wanderer. Present them to continue your journey.\n\n"
            "You look to the seven archways, all but one are open. The largest one in the center of all the archways is closed off by a large stone.\n"
            "You look back to the obelisk where six recesses are arranged in a hexagonal pattern.\n";
            "You scan the different open archways again.\n";
    temple_second_room();
}

void temple_second_room(){
    char choice;
    deposit();
    print_line();
    cout << "What would you like to do?\n";
    if(first_archway_read){
        cout << "A. Approach The Desert of the Dead\n";
    }
    else{
        cout << "A. Approach the First Archway\n";
    }
    if(second_archway_read){
        cout << "B. Approach the Heart of the Colony\n";
    }
    else{
        cout << "B. Approach the Second Archway\n";
    }
    if(third_archway_read){
        cout << "C. Approach The Glowing Cave\n";
    }
    else{
        cout << "C. Approach the Third Archway\n";
    }
    if(fourth_archway_read){
        cout << "D. Approach The Labyrinth\n";
    }
    else{
        cout << "D. Approach the Fourth Archway\n";
    }
    if(fifth_archway_read){
        cout << "E. Approach The Garden\n";
    }
    else{
        cout << "E. Approach the Fifth Archway\n";
    }
    if(sixth_archway_read){
        cout << "F. Approach The Whistling Gorge\n";
    }
    else{
        cout << "F. Approach the Sixth Archway\n";
    }
    if(seventh_archway_read){
        cout << "G. Approach The Silken Throne\n";
    }
    else{
        cout << "G. Approach the Seventh Archway\n";
    }
    print_line();
    
    cin >> choice;
    if(choice == 'A' || choice == 'a'){
        // The First Archway - The Desert of the Dead
        string message = "You approach the First Archway. As you approach, the name of the Archway becomes clear: \"The Desert of the Dead\"\n"
                         "The stone archway is covered in carvings of solemn, still faces. A message can be seen below the name of the room:\n"
                         "\n\tDo not disturb the slumber of the dead, wanderer. They are weary of life and will take yours if they awaken.\n\n"
                         "You gently touch the carved surface of the archway, running your hand over one of the carved faces.\n"
                         "A cold chill runs down your spine as your thumb drags over the closed eye of the stone face.\n"
                         "You look to the entrance.\n";

        archway(message, "The Desert of the Dead", &first_archway_read, &the_desert_of_the_dead);
    }
    else if(choice == 'B' || choice == 'b'){
        // The Second Archway - the Heart of the Colony
        string message = "You approach the Second Archway. As you approach, the name of the Archway becomes clear: \"The Heart of the Colony\"\n"
                        "The stone archway is noticeably older than the other archways and appears to be decorated with strange, distorted carvings of insect-like creatures.\""
                        "Your eyes glance towards the carved message beneath the name of the archway:\n"
                        "\n\tThey are the masters of their domain. Respect is required if you wish to keep your life and freedom.\n\n"
                        "You look closer at the carvings on the archway, an intricate framework of what appears to be tunnels and several thousand insects is depicted.\n"
                        "A sudden, low chittering sound occurs right behind you.\n"
                        "You swiftly turn around, but there is nothing there.\n"
                        "You look back to the entrance.\n";

        archway(message, "the Heart of the Colony", &second_archway_read, &the_heart_of_the_colony);
    }
    else if(choice == 'C' || choice == 'c'){
        // The Third Archway - The Glowing Cave
        string message = "You approach the Third Archway. As you approach, the name of the Archway becomes clear: \"The Glowing Cave\"\n"
                        "This stone archway appears to be made of a different material than the others, it is much darker and surprisingly damp.\n"
                        "You look up at the carved message underneath the name of the archway:\n"
                        "\n\tThis cave is used only for gathering materials, but dangers still remain. Still your mind, lest you lose your way.\n\n"
                        "You run your hand over the archway. Unlike the others, this archway is not carved and appears roughly hewn from the stone.\n"
                        "You pull your hand away, taking notice of how damp it is. A faint glow appears to be emanating from the entrance.\n"
                        "You take a closer look.\n";

        archway(message, "The Glowing Cave", &third_archway_read, &the_glowing_cave);
    }
    else if(choice == 'D' || choice == 'd'){
        // The Fourth Archway - The Labyrinth - entrance to next area, will not be available until the other rooms are completed
        if(!fourth_archway_read){
            print_line();
            cout << "You approach the Fourth Archway. As you approach, the name of the Archway becomes clear: \"The Labyrinth\"\n"
                    "The stone archway appears to be made of bricks, with several different intricate carvings of maze-like lines on them.\n"
                    "You look up and read the message beneath the name of the archway:\n"
                    "\n\tThe final obstacle, open only to those who've found all the keys.\n\n"
                    "You feel the intricate carvings on the archway, the lines like ridges on the stone bricks.\n";
            if(!saw_archway){
                cout << shimmer;
            }
            fourth_archway_read = true;
            saw_archway = true;
        }
        else{
            char answer;
            print_line();
            cout << "\nYou approach The Labyrinth.\n";
            cout << "\nDo you want to enter the archway? Y/N: ";
            cin >> answer;
            cout << "\n";
            if(answer == 'Y' || answer == 'y'){
                if(second_room_obelisk_complete){
                    cout << "You have traveled the six paths and have collected the keys from each one.\n"
                            "With the stone guarding the entrance gone, you can now enter The Labyrinth.\n"
                            "You take a step forward.\n";
                    the_labyrinth();
                }
                else{
                    cout << "You cannot go through the archway because you do not have all the keys for the stone obelisk.\n"
                            "You return to the center of the room.\n";
                    temple_second_room();
                }
            }
            else if(answer == 'N' || answer == 'n'){
                cout << "\nYou decide not to go in and return to the center of the room.\n";
                temple_second_room();
            }
            else{
                try_again();
                temple_second_room();
            }
        }
    }
    else if(choice == 'E' || choice == 'e'){
        // The Fifth Archway - The Garden
        string message = "You approach the Fifth Archway. As you approach, the name of the Archway becomes clear: \"The Garden\"\n"
                        "This stone archway is covered in beautiful carvings of delicate-looking flowers, exotic plants, and a waterfall.\n"
                        "The message beneath the name of the archway reads:\n"
                        "\n\tDo not be deceived by the beauty of the Garden, hidden dangers prey on the unwary.\n\n"
                        "You gently brush the intricate carvings on the archway. A sense of calm rushes through your body, but a lingering fear remains.\n"
                        "You try to relax and close your eyes, to fade into the imagined natural sounds of the Garden. Your body slowly releases tension.\n"
                        "Then you hear a loud groan of wood snapping above you.\n"
                        "Immediately, your eyes shoot open and you look up, but you see nothing but the ceiling of the temple room.\n"
                        "After a short moment, you look back to the entrance.\n";
        
        archway(message, "The Garden", &fifth_archway_read, &the_garden);
    }
    else if(choice == 'F' || choice == 'f'){
        // The Sixth Archway - The Whistling Gorge
        string message = "You approach the Sixth Archway. As you approach, the name of the Archway becomes clear: \"The Whistling Gorge\"\n"
                        "The archway is noticeably lighter in color than the other archways and is covered in carvings of strange-looking trees.\n"
                        "A message beneath the name of the archway reads:\n"
                        "\n\tA terrible place, the wails of the damned howl forever in this accursed land. Death is a welcome alternative.\n\n"
                        "Suddenly, a strong gust of wind blows out of the entrance, nearly knocking you over.\n"
                        "A long, mournful whistling wail cuts through the still air of the temple. A cold dread fills your stomach as you take an involutary step backward.\n"
                        "After a long moment, you walk back up to the entrance.\n";

        archway(message, "The Whistling Gorge", &sixth_archway_read, &the_whistling_gorge);
    }
    else if(choice == 'G' || choice == 'g'){
        // The Seventh Archway - The Silken Throne
        string message = "You approach the Seventh Archway. As you approach, the name of the Archway becomes clear: \"The Silken Throne\"\n"
                        "The archway appears to be covered in several sheets of fabric. Then you take a closer look.\n"
                        "You then realize that the archway is actually made of stone, realistically carved to resemble draped fabric.\n"
                        "You take a closer look at the exquisitely carved archway, it appears to be made of one smooth, unbroken piece of marble.\n"
                        "You finally stop admiring the handiwork of the archway and read the message beneath the archway name:\n"
                        "\n\tOnly those of noble blood may trade, but visitors are tolerated. Act honorably or you will never leave.\n\n"
                        "A strange mixture of feelings overcomes you - pleasure and pain. But it passes quickly, like silk over skin.\n"
                        "You look to the entrance of the archway.\n";
        
        archway(message, "The Silken Throne", &seventh_archway_read, &the_silken_throne);
    }
    else{
        try_again();
        temple_second_room();
    }
}

void the_desert_of_the_dead_text(){
    print_line();
    cout << "You fall to your knees. Going through the entrance knocked the wind out of you.\n"
            "After taking a few seconds to catch your breath, you stand back up and look around the room you are now in.\n"
            "The room is large, at least the size of two football fields. Several torches hang from the ceiling but are not the only source of light.\n"
            "You look up to see small openings near the ceiling of the room letting in bright, hot sunlight.\n"
            "Unlike the temple, the air in this place feels drastically drier and noticeably hotter.\n"
            "You look behind you to see an open doorway, but not the portal you expected.\n"
            "Instead, you appear to have been transported to a vast desert with nothing around for miles except large extrusions of volcanic rock and sand.\n"
            "You look back to the interior of the room and see that the walls are lined with numerous upright sarcophaguses.\n"
            "There are also several rows of tombs lying throughout the expanse of the room with a large raised platform in the very center of the room.\n\n";
    the_desert_of_the_dead();
}

void the_desert_of_the_dead(){
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Look around the room\n";
    cout << "B. Investigate the center platform\n";
    if(dod_looked_outside){
        cout << "C. Go out into the desert\n";
    }
    else{
        cout << "C. Look outside\n";
    }

    print_line();
    cin >> choice;
    
    if(choice == 'A' || choice == 'a'){
        print_line();
        if(!dod_explored_room){
            cout << "You walk between the rows of tombs, noticing the names inscribed on several of them.\n"
                    "After several moments, you make your way to the walls of the room where the upright sarcophaguses are.\n"
                    "Unlike the tombs which are sealed shut, some of the sarcophaguses appear to have been opened or are damaged enough to expose the body within.\n"
                    "Mummified remains can be seen hanging loosely out of some of them, while others are empty entirely.\n"
                    "This last detail is incredibly worrisome, since the archway had warned you about disturbing the dead.\n"
                    "You quickly scan the room, but thankfully don't see any corpses walking around. At least not yet.\n"
                    "You head back to the entrance of the room.\n";
            dod_explored_room = true;
            the_desert_of_the_dead();
        }
        else if(dod_investigated_platform){
            cout << "You wander around, looking at the names of tombs you pass, looking for the Crimson Leaf family name.\n"
                    "As you move, you hear something - a shuffling noise, but every time you look you don't see anything.\n"
                    "You continue to move along between the rows of tombs. The sandstorm persists outside the building.\n"
                    "You are about halfway through the rows of tombs, still looking for the Crimson Leaf family name when something grabs your foot.\n"
                    "You quickly look down to see the head of a mummified corpse poking out of the sand, its soulless eyes staring straight up at you and its hand grabbing your foot.\n"
                    "It then roars an unearthly low growl that resonates throughout the chamber."
                    "There is a moment of absolute silence before a chorus of unearthly screams erupt from every tomb in the room.\n"
                    "Panicking now, you rip your foot out of the mummy's grip and run towards the entrance of the building."
                    "You try to force yourself into the sandstorm but are viciously flung backwards as the sandstorm picks up in even more intensity.\n"
                    "You pull yourself into a sitting position and look towards the entrance, but freeze and scream at what you see." 
                    "Within the silicon tempest, a skull forms out of the flying sand, eyes shining with an ethereal bright blue light.\n"
                    "It roars at you and the voice in your head speaks again, \"You disturbed their peace, and now you will pay with your life.\"\n"
                    "It is then you notice the sound of the lumbering forms behind you. Before you can move, you are roughly pulled to your feet.\n"
                    "The mummy pulls you into the crowd of corpses. You kick and scream, but there is nothing more you can do as they pull you apart piece by piece."
                    "As your screams soften into gurgles and the light leaves your eyes, the swarm of bodies disperses, the sandstorm calms, and all is silent in the desert again.\n";

            cout << "\n\nEnding 6: Torn\n";
            retry(&the_desert_of_the_dead_text);
        }
        else{
            cout << "You walk between the rows of tombs again.\n"
                    "After several minutes of this, nothing different jumps out at you.\n"
                    "You head to the wall of sarcophaguses and inspect them again.\n"
                    "The mummified remains continue to hang loosely out of some of them.\n"
                    "It would be best not to touch them.\n"
                    "You return to the entrance of the room.\n";
            the_desert_of_the_dead();
        }
    }
    else if(choice == 'B' || choice == 'b'){
        print_line();
        if(!dod_investigated_platform){
            cout << "You head up to the raised platform in the center of the room.\n"
                    "On it lies a large stone tablet, several thousand names are inscribed on it.\n"
                    "It is then you hear the voice in your head again.\n"
                    "\"Here the dead rest, returned to their families and undisturbed by the common rabble of life.\""
                    "\"Retrieve the Ruby Skull held by the head of the Crimson Leaf family, and you will be permitted to return.\""
                    "\"If you do not, prepare to join the dead, though you will be... unwelcome.\""
                    "As if on cue, you hear a shuffling noise somewhere ahead of you.\n"
                    "Your head snaps up to look in the direction of the noise, but you see nothing.\n"
                    "It is then you notice the world growing darker. You quickly glance toward the ceiling windows.\n"
                    "A sandstorm has started outside, the wind howling and blocking out the sun. Now, only the feeble light of the torches remains.\n"
                    "You head back to the entrance of the building.\n";
            dod_investigated_platform = true;
            dod_sandstorm = true;
            the_desert_of_the_dead();
        }
        else{
            cout << "You go to the raised platform in the middle of the room and look at the large stone tablet again, trying to locate the Crimson Leaf family name.\n"
                    "While you're looking through the names, something else catches your eye: a piece of paper folded and tucked in a crack on the side of the stone tablet.\n"
                    "Curious, you take the piece of paper out of the crack and unfold it. It reads:\n\n";
            cout << journal_entry_4;
            cout << "You fold up the piece of paper and stuff it in your pocket.\n"
                    "Your attention returns to the large stone tablet and you once again skim the text for the Crimson Leaf family name.\n"
                    "Finally, after several long moments, you find it near the bottom right of the stone tablet. Assuming the layout of the sarcophaguses are the same as presented on the stone tablet,\n"
                    "you jump off from the raised platform and run towards the bottom right end of the tombs.\n"
                    "It is only when you're nearly halfway there that you start to hear groaning and see motion out of the corner of your eye.\n"
                    "You look towards the tombs and notice several mummies have now opened their sarcophaguses and are climbing out.\n"
                    "It seems in your eagerness to get out of there, you accidentally woke up the dead. You quicken your pace.\n"
                    "There are a lot of mummies now, and they're all taking notice of you. You quickly run up to the tomb that was said to contain the Ruby Skull and deftly push the lid off.\n"
                    "There inside the tomb lays a mummy holding the Ruby Skull in its cold dead hands. No time for respect or reverence, you quickly yank the Ruby Skull out of the mummy's hands and take off towards the exit.\n"
                    "You hear a piercing wail behind you as several mummies have now closed in on your position.\n"
                    "Pulling out the dagger, you cut at the limbs of any that manage to grab you, forcing them to let go, and dodge the rest.\n"
                    "The entrance has reopened into that familiar shimmer of an active Gate, and you make a mad dash for it.\n"
                    "You're about to jump through the gate when suddenly, you're held back by a pair of strong hands.\n"
                    "You turn around and recognize the mummy you took the Ruby Skull from and quickly raise the dagger to swipe at one of its arms.\n"
                    "The mummy deftly grabs your wrist and stops the downward plunge of the blade. It then pulls you closer, lifting you off the ground entirely and roars loudly in your face.\n"
                    "Thinking quickly, you pull in both your legs and push hard against the body of the mummy, launching yourself through the entrance.\n"
                    "There's a sickening tearing sound as the mummy's arms rip at the elbows and you go flying through the Gate.\n"
                    "You land hard on your back in the temple room with the Ruby Skull still clutched hard against your chest.\n"
                    "You remain laying on the floor, taking a moment to catch your breath before you hesitantly pick yourself back up.\n";
            inventory.push_back(third_note);
            inventory.push_back(the_desert_of_the_dead_key);
            temple_second_room();
            // return to room to insert obelisk key
        }
    }
    else if(choice == 'C' || choice == 'c'){
        print_line();
        if(!dod_looked_outside && !dod_sandstorm){
            cout << "You poke your head out of the doorway to the building you're in.\n"
                    "Heat waves ripple the air around you, forcing you to squint for a better view of your surroundings.\n"
                    "Mountainous volcanic rock ridges jut out of the sand several miles directly ahead of you.\n"
                    "To your left and right, there is nothing but sand and several smaller formations of the volcanic rock every hundred feet or so.\n"
                    "You pull your head back in and wipe the sweat from your brow.\n"
                    "After just peeking your head out for a moment, you have already felt the tremendous heat of the desert beyond the doorway.\n"
                    "In contrast, the building you're in is several degrees cooler than outside, with some protection from the heat of the sun.\n"
                    "It would be unwise to try wandering around the desert, you imagine. Still, the option is open to you if you so choose.\n";
                    "You look back to the room.\n";
            dod_looked_outside = true;
            the_desert_of_the_dead();
        }
        else if(dod_sandstorm){
            cout << "The sandstorm is so severe, there is no way you could find your way around out there.\n"
                    "You can't even safely stick your head out.\n"
                    "Despite this, sand somehow does not enter the building and you don't feel even the slightest of breezes.\n"
                    "You turn back to the room.\n";
            the_desert_of_the_dead();
        }
        else{
            cout << "Despite the brutal heat and the extreme isolation, you head out into the desert.\n";
                    "Within minutes, you are severely sweating and overwhelmingly hot.\n"
                    "You turn to head back to the building, but don't see it anymore.\n"
                    "Turning wildly, you scan the horizon, but the building is nowhere in sight.\n"
                    "The only things that can be seen is sand and volcanic rock.\n"
                    "After futilely spinning around once more, hoping against hope the building would reappear, you hang your head in defeat and head deeper into the desert.\n"
                    "XXXXXXXXXXXXXXXXXXXXXXXX\n"
                    "   SEVERAL DAYS LATER\n"
                    "XXXXXXXXXXXXXXXXXXXXXXXX\n"
                    "After wandering the desert for days now, you struggle to stand upright.\n"
                    "You are so thirsty, so terribly thirsty.\n"
                    "You chew your dry tongue, wishing for the sky to erupt in a shower of blessed water.\n"
                    "But of course, it does not. There is not a cloud in the sky to be seen.\n"
                    "Panting, you take one final step before you collapse against the unforgivingly hot sand.\n"
                    "As you feel your sunburned skin sizzle against the desert floor, you look to the sky one last time.\n"
                    "The scorching sun glares back at you as your eyes roll up in your head and at last, you see no more.\n";

            cout << "\n\nEnding 5: Thirst";
            print_line();
            retry(&the_desert_of_the_dead_text);
        }
    }
    else{
        try_again();
        the_desert_of_the_dead();
    }
}

void the_heart_of_the_colony_text(){
    print_line();
    cout << "You brace yourself, but fall to your hands and knees anyway as you go through the entrance.\n"
            "Immediately, you notice something odd about the atmosphere here. The air is thick, yet strangely dry.\n"
            "The floor beneath your hands is composed of chalky, moist soil. You look up to see that you are in a large, dimly lit tunnel.\n"
            "Imperfectly circular, the tunnel runs for some distance ahead and behind you. Again, the portal from the temple has disappeared.\n"
            "Suddenly, you hear a distant familiar chittering that is gradually getting closer. A bright yellow light accompanies the source of the sound.\n"
            "You look around for a hiding spot, but find none. You can either run away from the chittering sound,\n"
            "or you can wait to see what is approaching you.\n\n";

    the_heart_of_the_colony();
}

void the_heart_of_the_colony(){
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Run away from the sound\n";
    cout << "B. Wait\n";
    cout << "C. Look around some more\n";
    print_line();
    cin >> choice;

    if(choice == 'A' || choice == 'a'){
        print_line();
        cout << "You turn tail and run away from the approaching chittering sounds.\n"
                "Almost immediately, the chittering sounds increase in volume and urgency.\n"
                "You hear rapidly approaching scurrying sounds and quickly look behind you.\n"
                "You are greeted with the sight of multiple giant ants the size of horses chasing you,\n"
                "their enormous mandibles snapping and compound eyes seemingly bright with anger and bloodlust.\n"
                "They quickly gain ground, their huge jaws snapping shut just inches behind your ankles.\n"
                "You attempt to pick up speed yourself, but instead one of the ants catches your left foot in its jaws.\n"
                "Pain shoots up your leg as its mandibles pierce through the walls of your shoe and into your ankle.\n"
                "You trip and fall face-first into the dirt floor of the tunnel. Dazed, you barely have to time to register\n"
                "you're on the ground when you start to get pulled away. You panic and claw at the dirt, trying to pull yourself\n"
                "free of the giant ant's grip. It is no use however, as the huge insect easily drags you back towards it.\n"
                "Finally, after dragging you a few meters away from where you were, it releases its grip and you roll over to see\n"
                "that you're surrounded on all sides by the giant arthropods. For a moment, you simply look at them, and they at you,\n"
                "before the one that was dragging you swiftly closes the distance and locks its jaws around your throat. You gasp,\n"
                "trying to pull against the iron grip of the huge ant's jaws. It is no use however, as you stare into the dead compound eyes,\n"
                "it slowly clamps its jaws harder and harder around your throat. As your eyes roll up and you gasp for air, you feel\n"
                "blood pouring from your punctured neck and soon a sickening crunch is heard as your neck is broken.\n"
                "The last thing you hear before your limp body falls to the ground is triumphant chittering.\n"
                "Soon the chittering fades away, and you are left staring at the tunnel floor, awaiting death.\n"
                "It cannot arrive soon enough.\n";
                
        cout << "\n\nEnding 7: Crunch";
        print_line();
        retry(&the_heart_of_the_colony_text);
    }
    else if(choice == 'B' || choice == 'b'){
        print_line();
        cout << "You wait, facing the oncoming chittering noises. You nervously grip the loose fabric of your pants, anxiety slowly increasing\n"
                "as your fate waits to be written. Soon, you see the source of the noise and the light: several large ants, one of them carrying an\n"
                "unusual organic-looking lantern on its back. The ants stop and look at you, seemingly bemused at your sudden appearance, but then quickly move in,\n"
                "surrounding you on all sides while one behind you nips at your heels with its huge jaws, urging you forward. Hesitantly, you move forward, keeping pace with\n"
                "the huge insects.\n"

        the_queens_chambers();
    }
    else if(choice == 'C' || choice == 'c'){
        print_line();
        cout << "You quickly look around the tunnel again, looking for anything you might have missed before.\n"
                "It is then you notice an impression in one side of the tunnel, something you missed before due to the dim lighting.\n"
                "It looks as though someone tried digging out another tunnel, but stopped for some reason. It looks like you could hide in there, if you positioned yourself a certain way.\n"
                "The chittering grows louder, it's now or never. You quickly jump into the impression and flatten yourself against the wall as much as possible.\n"
                "You remain still as several huge ants pass by you, the chittering remaining uninterrupted. However, one stops where you dropped from the portal, causing the others to take notice.\n"
                "Its antennae dance around the tunnel floor where you were on your knees, it chitters at the others and soon all of them are looking for you.\n"
                "You could either run away, surrender, or try to fight. After all, you have a momentary advantage over them with a surprise attack.\n";

        hotc_tunnel_options();
    }
    else{
        try_again();
        the_heart_of_the_colony();
    }
}

void the_glowing_cave(){
    retry();
}

void the_garden(){
    retry();
}

void the_whistling_gorge(){
    retry();
}

void the_silken_throne(){
    retry();
}

void the_labyrinth(){
    retry();
}