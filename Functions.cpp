//Function definitions for the main game file.
#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "Functions.hpp"
#include "Items.hpp"
#include "Trackers.hpp"
#include "Journal Entries.hpp"
#include "The Desert of the Dead.hpp"
#include "Heart_of_the_Colony.hpp"
#include "The_Glowing_Cave.hpp"
#include "The Whistling Gorge.hpp"
#include "The Oasis.hpp"
#include "The Swamplands.hpp"
#include "The Labyrinth.hpp"

using namespace std;

vector<string> inventory;
vector<string> journals;
vector<string> obslots;

inline void print_line()
{
    cout << "\n=====================================================================================================================================================================================================\n";
}

inline void try_again()
{
    cout << "\nSorry, that is not a valid option, please try again.\n";
}

void reset()
{
    // Once all trackers are determined, use this function to reset them upon a retry.
}

void sleeptimer(int seconds)
{
    #ifdef _WIN32
        Sleep(seconds * 1000);
    #else
        usleep(seconds * 1000000);
    #endif
}

void retry()
{
    char choice;
    cout << "\nWould you like to play again? Y/N: ";
    cin >> choice;
    if(choice == 'Y' || choice == 'y')
    {
        cout << "\n\nRESTARTING...\n\n";
        //reset();
        start();
    }
    else if(choice == 'N' || choice == 'n')
    {
        cout << "\nThanks for playing \"The Temple\"!\n";
        sleeptimer(3);
        return;
    }
    else
    {
        try_again();
        retry();
    }
}

void retry(void (*func)())
{
    char choice;
    cout << "\nRetry from the last area? Y/N: ";
    cin >> choice;
    if(choice == 'Y' || choice == 'y')
    {
        func();
    }
    else if(choice == 'N' || choice == 'n')
    {
        retry();
    }
    else
    {
        try_again();
        retry(func);
    }
}

void archway(string message, string name, bool *archway_read, void (*func)())
{
    char answer;

        if(!(*archway_read))
        {
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
        if(answer == 'Y' || answer == 'y')
        {
            cout << "\nYou take a step forward and enter " << name << "\n";
            func();
        }
        else if(answer == 'N' || answer == 'n')
        {
            cout << "\nYou decide not to go in and return to the center of the room.\n";
            temple_second_room();
        }
        else
        {
            try_again();
            temple_second_room();
        }
}

void deposit()
{
    string key;
    for(int i = 0; i < inventory.size(); i++)
    {
        for(int j = 0; j < sizeof(keys); j++)
        {
            if(inventory[i] == keys[j])
            {
                key = inventory[i];
                inventory.pop_back();
                break;
            }
        }
    }
    if(key != "")
    {
        cout << "\nYou place the " << key << " into the monolith and turn back to the room.\n";
        obslots.push_back(key);
        cout << "\nThe Obelisk now contains: \n";
        for(int i = 0; i < obslots.size(); i++)
        {
            cout << obslots.at(i) << "\n";
        }
        if(obslots.size() == 6)
        {
            for(int i = 0; i < obslots.size(); i++)
            {
                inventory.push_back(obslots[i]);
            }
            obslots.clear();
            print_line();
            cout << "With a deafening roar, the giant stone blockingb the fourth archway opens, revealing the final portal.\n"
                    "You hear a voice in your head: \"Congratulations, you have unlocked the final world. Use all that you've learned to pass the final test.\n";
            second_room_obelisk_complete = true;
            show_inventory();
        }
    }
    return;
}

void determine_riddle()
{
    set_riddle = 1 + (rand() % 3);
    switch(set_riddle)
    {
        case 1:
            current_riddle = wind_riddle;
            break;
        case 2:
            current_riddle = water_riddle;
            break;
        case 3:
            current_riddle = fire_riddle;
            break;
        default:
            current_riddle = water_riddle;
    }
}

void show_inventory()
{
    cout << "Your inventory contains:\n";
    for(int i = 0; i < inventory.size(); i++)
    {
        if(i == inventory.size() - 1)
        {
            cout << inventory.at(i) << "\n";
        }
        else
        {
            cout << inventory.at(i) << ", ";
        }
    }
}

bool inv_contains(string object)
{
    for(int i = 0; i < inventory.size(); i++)
    {
        if(inventory[i] == object)
        {
            return true;
        }
    }
    return false;
}

void start()
{
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

void first_choice()
{
    char choice;
    print_line();
    cout << "Do you wish to take the dagger? Y/N: ";
    cin >> choice;
    cout << "\n";

    if(choice == 'Y' || choice == 'y')
    {
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
                "You stand still for a moment, looking at the entrance. Then you pick the dagger back up and store it on your person.\n";
        inventory.push_back(dagger);
        temple_entrance();
    }
    else if(choice == 'N' || choice == 'n')
    {
        print_line();
        if(jungle_repeat > 2)
        {
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
        else
        {
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
    else
    {
        try_again();
        first_choice();
    }
}

void temple_entrance()
{
    char choice;
    print_line();
    cout << "After making your choice, you turn back to the now-open temple entrance.\n"
            "Something catches your eye however, and you turn to look at the pedestal holding the bowl of fire.\n"
            "Somehow, the symbols now make sense to you.\n"
            "The engraved text reads:\n\n\tAn offering needed to gain insight and entrance.\n\n";
    print_line();
    cout << "Will you go into the temple? Y/N: ";
    cin >> choice;
    cout << "\n";

    if(choice == 'Y' || choice == 'y')
    {
        print_line();
        cout << "You head deeper into the temple.\n\n";
        temple_first_room_text();
    }
    else if(choice == 'N' || choice == 'n')
    {
        cout << "You decide against going into the temple, instead opting to explore your location more.\n\n"
                "You look around more and come across a rucksack half-buried in the dense foliage.\n"
                "You pull it out and search the pockets. You find an old map, a broken watch, and a piece of paper.\n"
                "The old map is nearly useless, as it is so worn and faded that all you can really see are faint gridlines and the border.\n"
                "The broken watch is even more useless since the casing seemingly broke open long ago and all the internal mechanisms have now fallen completely apart.\n"
                "The piece of paper is actually the most interesting of the junk you find. There's something written on it in in crooked, barely legible script.\n"
                "It reads:\n";
        cout << journal_entry_1;
        cout << "You fold up the piece of paper and stash it on your person.\n";
        inventory.push_back(journal_entry_1);
        cout << "You head back to the temple entrance and step inside.\n";
        temple_first_room_text();
    }
    else
    {
        try_again();
        temple_entrance();
    }
}

void temple_first_room_text()
{
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

void temple_first_room()
{
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. I'll try to solve the riddle now\n";
    cout << "B. I want to look around the room more\n";
    cout << "C. Look at the entrance\n";
    print_line();
    cin >> choice;
    choice = tolower(choice);

    switch(choice)
    {
        case 'a':
            char second_choice;
            print_line();
            cout << "You decide you want to try and solve the riddle now.\n";
            cout << "The riddle is:\n\n";
            cout << current_riddle << "\n";
            cout << "\nOf the three symbols on the walls, you decide to choose: \n\n";
            cout << "A. Wind\n";
            cout << "B. Water\n";
            cout << "C. Fire\n\n";
            print_line();
        
            cin >> second_choice;
            second_choice = tolower(second_choice);

            switch(second_choice)
            {
                case 'a':
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
                                "You pull your finger away and you realize the leaf was surprisingly stiff and sturdy, like a piece of metal.\n"
                                "Then with growing horror, you realize that the gusts of air are growing stronger and the leaves are slowly starting to twirl around the room.\n"
                                "You rush to the still-sealed entrance of the room and fruitlessly pound on the large stone slab keeping it closed.\n"
                                "The wind picks up even more, and the leaves dance freely around the room.\n"
                                "You feel the fabric of your clothes tear as the leaves cut cleanly through them.\n"
                                "You continue to helplessly pound on the stone slab, tears now pouring freely from your eyes.\n"
                                "The wind is now a forceful gale and tosses the leaves violently around the room.\n"
                                "Pain soon floods every part of your nearly exposed body as the leaves effortlessly tear open your skin.\n"
                                "You pound on the stone slab and scream for help, but you can't even hear yourself over the howling wind.\n"
                                "You scream and scream until you feel a leaf cut cleanly through both of your cheeks as another slices open your throat.\n"
                                "Blood fills your throat as you let out one more scream that comes out as more of a pathetic gurgle.\n"
                                "You fall forward on the ground and faintly feel your ear get cut away as a leaf embeds itself in your eye.\n"
                                "Your world is reduced to nothing but pain as your vision fades and you hear a voice in your head before everything fades to black.\n"
                                "\"Wrong answer.\"\n";

                        cout << "\n\nEnding 2: Shredded";
                        print_line();
                        retry(&temple_first_room_text);
                    }
                    else
                    {
                        cout << correct_riddle;
                        temple_second_room_text();
                    }
                    break;

                case 'b':
                    print_line();
                    cout << "You choose Water.\n";
                    if(set_riddle != 2)
                    {
                        cout << "You walk up to the Water symbol and gently touch it with your hand.\n"
                                "Nothing happens for several seconds, until you hear a roar right above you.\n"
                                "Your head snaps up to look at the ceiling where you see that several apertures have opened above you, allowing several gallons of water to start pouring in.\n"
                                "You quickly try to avoid the deluge, but there's nowhere to run. Instead, you climb the pedestal in the center of the room holding the now-extinguished bowl.\n"
                                "You watch with growing horror as the water level rises quickly, with no other option, you attempt to bang on the ceiling, to no avail.\n"
                                "The water is now at chest level, and there is nothing left to do but scream.\n"
                                "You scream and scream, but no help comes.\n"
                                "As the water rises, you take a final gasp of air before the water finally fills the room.\n"
                                "You struggle to hold your breath, but you can feel your lungs burning for air.\n"
                                "You hold back for as long as you can, but you can't hold on forever. You open your mouth and inhale the cold water.\n"
                                "As your vision fades and the cold invades your body, you hear a voice in your head.\n"
                                "\"Wrong answer.\"\n";

                        cout << "\n\nEnding 4: Drowned";
                        print_line();
                        retry(&temple_first_room_text);
                    }
                    else
                    {
                        cout << correct_riddle;
                        temple_second_room_text();
                    }
                    break;

                case 'c':
                    print_line();
                    cout << "You choose Fire.\n";
                    if(set_riddle != 3)
                    {
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
                    else
                    {
                        cout << correct_riddle;
                        temple_second_room_text();
                    }
                    break;
                
                default:
                    try_again();
                    temple_first_room();
            }
            break;
            
        case 'b':
            print_line();
            if(first_room_explored)
            {
                cout << "You quickly look around the room again, but you're sure you've already examined everything.\n"
                        "You turn back to the room.\n";
                temple_first_room();
            }
            else
            {
                cout << "You decide to look around the room more.\n"
                        "You look closer at the symbols on the walls: there's the wind symbol on the left wall, the water symbol on the wall directly opposite you and the fire symbol on the right wall.\n"
                        "Other than the fact that the symbols seemed to be etched out of the wall itself, there doesn't seem to be anything else interesting about them.\n"
                        "You also examine the pedestal in the center of the room and notice that there is a little piece of paper sticking out from a small crack between the pedestal and the floor.\n"
                        "You gently pull it out and read what it says:\n\n";
                cout << hint_1;
                cout << "\nYou flip the paper over and examine the back, but there is nothing else to read.\n"
                        "You gently fold the piece of paper up and look back to the room.\n";
                first_room_explored = true;
                temple_first_room();
            }
            break;

        case 'c':
            print_line();
            cout << "You look back to the entryway. The huge stone slab remains, sealing you in the temple.\n"
                    "You sigh and turn back to the room.\n";
            temple_first_room();
            break;

        default:
            try_again();
            temple_first_room();
    }
}

void temple_second_room_text()
{
    print_line();
    cout << "You step into the much larger room and look around.\n"
            "Spaced evenly around the perimeter of the room are seven stone archways.\n"
            "All of the archways have intricate carvings adorning them, each of them depicting different scenes.\n"
            "One archway appears to have faces carved into the smooth, black stone.\n"
            "Another appears to be adorned with carvings of insects.\n"
            "There are more rooms, but they are too far away to clearly see the carvings on them.\n"
            "Instead, you focus on the center of the room where an imposing stone obelisk stands.\n"
            "You approach the obelisk and are able to make out the few lines of text on it.\n\n"
            "\tBring forth six keys from the six paths. Present them to face the final test.\n\n"
            "You look to the seven archways, all but one are open. The largest one in the center of all the archways is closed off by a large stone.\n"
            "You look back to the obelisk where six recesses are arranged in a hexagonal pattern.\n"
            "You scan the different open archways again.\n";
    temple_second_room();
}

void temple_second_room()
{
    char choice;
    deposit();
    print_line();
    cout << "What would you like to do?\n";
    if(first_archway_read)
    {
        cout << "A. Approach The Desert of the Dead\n";
    }
    else
    {
        cout << "A. Approach the First Archway\n";
    }
    if(second_archway_read)
    {
        cout << "B. Approach the Heart of the Colony\n";
    }
    else
    {
        cout << "B. Approach the Second Archway\n";
    }
    if(third_archway_read)
    {
        cout << "C. Approach The Glowing Cave\n";
    }
    else
    {
        cout << "C. Approach the Third Archway\n";
    }
    if(fourth_archway_read)
    {
        cout << "D. Approach The Labyrinth\n";
    }
    else
    {
        cout << "D. Approach the Fourth Archway\n";
    }
    if(fifth_archway_read)
    {
        cout << "E. Approach The Oasis\n";
    }
    else
    {
        cout << "E. Approach the Fifth Archway\n";
    }
    if(sixth_archway_read)
    {
        cout << "F. Approach The Whistling Gorge\n";
    }
    else
    {
        cout << "F. Approach the Sixth Archway\n";
    }
    if(seventh_archway_read)
    {
        cout << "G. Approach The Swamplands\n";
    }
    else
    {
        cout << "G. Approach the Seventh Archway\n";
    }
    
    print_line();
    cin >> choice;
    choice = tolower(choice);
    string message;
    switch(choice)
    {
        case 'a':
            if(dod_completed)
            {
                print_line();
                cout << completed_world;
                temple_second_room();
                break;
            }
            else
            {
                // The First Archway - The Desert of the Dead
                message = "You approach the First Archway. As you approach, the name of the Archway becomes clear: \"The Desert of the Dead\"\n"
                                "The stone archway is covered in carvings of solemn, still faces. A message can be seen below the name of the room:\n"
                                "\n\tDo not disturb the slumber of the dead, wanderer. They are weary of life and will take yours if they awaken.\n\n"
                                "You gently touch the carved surface of the archway, running your hand over one of the carved faces.\n"
                                "A cold chill runs down your spine as your thumb drags over the closed eye of the stone face.\n"
                                "You look to the entrance.\n";
                
                archway(message, "The Desert of the Dead", &first_archway_read, &the_desert_of_the_dead_text);
                break;
            }

        case 'b':
            if(hotc_completed)
            {
                print_line();
                cout << completed_world;
                temple_second_room();
                break;
            }
            else
            {
                // The Second Archway - the Heart of the Colony
                message = "You approach the Second Archway. As you approach, the name of the Archway becomes clear: \"The Heart of the Colony\"\n"
                                "The stone archway is noticeably older than the other archways and appears to be decorated with strange, distorted carvings of insect-like creatures.\n"
                                "Your eyes glance towards the carved message beneath the name of the archway:\n"
                                "\n\tThey are the masters of their domain. Respect is required if you wish to keep your life and freedom.\n\n"
                                "You look closer at the carvings on the archway, an intricate framework of what appears to be tunnels and several thousand insects is depicted.\n"
                                "A sudden, low chittering sound occurs right behind you.\n"
                                "You swiftly turn around, but there is nothing there.\n"
                                "You look back to the entrance.\n";

                archway(message, "the Heart of the Colony", &second_archway_read, &the_heart_of_the_colony_text);
                break;
            }

        case 'c':
            if(tgc_completed)
            {
                print_line();
                cout << completed_world;
                temple_second_room();
                break;
            }
            else
            {
                // The Third Archway - The Glowing Cave
                message = "You approach the Third Archway. As you approach, the name of the Archway becomes clear: \"The Glowing Cave\"\n"
                                "This stone archway appears to be made of a different material than the others, it is much darker and surprisingly damp.\n"
                                "You look up at the carved message underneath the name of the archway:\n"
                                "\n\tThis cave is used only for gathering materials, but dangers still remain. Still your mind, lest you lose your way.\n\n"
                                "You run your hand over the archway. Unlike the others, this archway is not carved and appears roughly hewn from the stone.\n"
                                "You pull your hand away, taking notice of how damp it is. A faint glow appears to be emanating from the entrance.\n";

                archway(message, "The Glowing Cave", &third_archway_read, &the_glowing_cave_text);
                break;
            }

        case 'd':
            // The Fourth Archway - The Labyrinth - the final challenge, will not be unlocked until all the other worlds have been completed.
            print_line();
            if(!fourth_archway_read)
            {
                cout << "You approach the Fourth Archway. As you approach, the name of the Archway becomes clear: \"The Labyrinth\"\n"
                        "The stone archway appears to be made of bricks, with several different intricate carvings of maze-like lines on them.\n"
                        "You look up and read the message beneath the name of the archway:\n"
                        "\n\tThe final obstacle, open only to those who've found all the keys.\n\n"
                        "You feel the intricate carvings on the archway, the lines like ridges on the stone bricks.\n"
                        "You look to the entrance only to see a wall of stone between the pillars of the archway.\n"
                        "In your head you hear:\n"
                        "\n\t\"You cannot yet enter, for you do not have all the keys.\"\n\n"
                        "You head back to the center of the room.\n";
                fourth_archway_read = true;
                saw_archway = true;
                temple_second_room();
            }
            else
            {
                char answer;
                cout << "\nYou approach The Labyrinth.\n";
                cout << "\nDo you want to enter the archway? Y/N: ";
                cin >> answer;
                cout << "\n";
                if(answer == 'Y' || answer == 'y')
                {
                    if(second_room_obelisk_complete)
                    {
                        cout << "You have traveled the six paths and have collected the keys from each one.\n"
                                "With the stone guarding the entrance gone, you can now enter The Labyrinth.\n"
                                "You take a step forward and enter the archway.\n";
                        the_labyrinth_text();
                    }
                    else
                    {
                        cout << "You cannot go through the archway because you do not have all the keys for the stone obelisk.\n"
                                "You return to the center of the room.\n";
                        temple_second_room();
                    }
                }
                else if(answer == 'N' || answer == 'n')
                {
                    cout << "\nYou decide not to go in and return to the center of the room.\n";
                    temple_second_room();
                }
                else
                {
                    try_again();
                    temple_second_room();
                }
            }
            break;

        case 'e':
            if(oasis_completed)
            {
                print_line();
                cout << completed_world;
                temple_second_room();
                break;
            }
            else
            {
                // The Fifth Archway - The Oasis
                message = "You approach the Fifth Archway. As you approach, the name of the Archway becomes clear: \"The Oasis\"\n"
                                "This stone archway is covered in beautiful carvings of delicate-looking flowers, exotic plants, and a waterfall.\n"
                                "The message beneath the name of the archway reads:\n"
                                "\n\tDo not be deceived by the beauty of The Oasis, hidden dangers prey on the unwary.\n\n"
                                "You gently brush the intricate carvings on the archway. A sense of calm rushes through your body, but a lingering fear remains.\n"
                                "You try to relax and close your eyes, to fade into the imagined natural sounds of The Oasis. Your body slowly releases tension.\n"
                                "Then you hear a loud groan of wood snapping above you.\n"
                                "Immediately, your eyes shoot open and you look up, but you see nothing but the ceiling of the temple room.\n"
                                "After a short moment, you look back to the entrance.\n";
            
                archway(message, "The Oasis", &fifth_archway_read, &the_oasis_text);
                break;
            }

        case 'f':
            if(twg_completed)
            {
                print_line();
                cout << completed_world;
                temple_second_room();
                break;
            }
            else
            {
                // The Sixth Archway - The Whistling Gorge
                message = "You approach the Sixth Archway. As you approach, the name of the Archway becomes clear: \"The Whistling Gorge\"\n"
                                "The archway is noticeably lighter in color than the other archways and is covered in carvings of strange-looking trees.\n"
                                "A message beneath the name of the archway reads:\n"
                                "\n\tA terrible place, the wails of the damned howl forever in this accursed land. Death is a welcome alternative.\n\n"
                                "Suddenly, a strong gust of wind blows out of the entrance, nearly knocking you over.\n"
                                "A long, mournful whistling wail cuts through the still air of the temple. A cold dread fills your stomach as you take an involutary step backward.\n"
                                "After a long moment, you walk back up to the entrance.\n";

                archway(message, "The Whistling Gorge", &sixth_archway_read, &the_whistling_gorge_text);
                break;
            }
    
        case 'g':
            if(tsl_completed)
            {
                print_line();
                cout << completed_world;
                temple_second_room();
                break;
            }
            else
            {
                // The Seventh Archway - The Swamplands
                message = "You approach the Seventh Archway. As you approach, the name of the Archway becomes clear: \"The Swamplands\"\n"
                                "The archway appears to be covered in several overlapping layers of moss and lichen.\n"
                                "You then realize that the archway is actually made of stone, realistically carved to resemble such growths.\n"
                                "You take a closer look at the exquisitely carved archway, it appears to be made of one smooth, unbroken piece of marble.\n"
                                "You finally stop admiring the handiwork of the archway and read the message beneath the archway name:\n"
                                "\n\tThe Swamplands harbor many creatures, ensure your footing and maintain your steps, lest you are never seen again.\n\n"
                                "A musty, humid breeze blows through the archway. On it, a strange smell. A smell that sends a small shiver down your spine.\n"
                                "You look to the entrance of the archway.\n";
            
                archway(message, "The Swamplands", &seventh_archway_read, &the_swamplands_text);
                break;
            }
        
        default:
            try_again();
            temple_second_room();
    }
}