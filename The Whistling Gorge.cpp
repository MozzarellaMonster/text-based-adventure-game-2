// File containing functions for The Whistling Gorge passage
#include <iostream>
#include <string>
#include "The Whistling Gorge.hpp"
#include "Functions.hpp"
#include "Journal Entries.hpp"
#include "Trackers.hpp"
#include "Items.hpp"

using namespace std;

bool explored_left_path;
bool explored_right_path;
bool looked_around;
bool twg_found_journal = false;

bool denied_fruit;

void the_whistling_gorge_text()
{
    print_line();
    cout << "You stumble through the Gate, barely managing to regain your balance to avoid face planting in the chalky white dust.\n"
            "Standing upright, you find yourself in a large canyon with looming rock faces on either side of you.\n"
            "You look back to see a large similarly carved Gate set into the rock face behind you.\n"
            "However, this one is clearly inactive as nothing but black stone greets you between either pillar of the Gate.\n"
            "You turn back around and see what looks like a small forest a few hundred meters away from you.\n"
            "With no other option in the dead end of the canyon you find yourself in, you walk forward.\n"
            "As you approach the forest, you soon realize that seemingly every tree within it is dead.\n"
            "Their gnarled, twisted branches reach toward the calm blue sky like withering fingers from a grave.\n"
            "Wandering through the thicket, you notice several trees have lines of holes scattered along the length of their trunks.\n"
            "Like the holes along the length of a flute. You stop and stare at one series close to you before you feel the breeze pick up\n"
            "and you hear a somber whistling tone all around you...\n\n"
            "                                                       *****                                                                   \n"
            "You shake yourself from your stupor, regaining control of your limbs. It is then you notice your fingernails caked with the\n"
            "chalky white dust, and you look down to see you are crouched in front of a small hole in the ground where you had been digging.\n"
            "You stand back up, shaking the dust free from your hands. The breeze is noticeably gone, and the somber whistle nowhere to be heard.\n"
            "You don't know why you were digging, but you're sure it wasn't for a good reason, as a creeping dread crawls slowly up your spine.\n"
            "Something tells you it would be in your best interest to not hear the whistling woods again.\n"
            "Walking forward, you soon come upon a split in the path. There are two options: the path on the left goes up a hill,\n"
            "the path on the right goes further into the forest.\n";
    the_whistling_gorge();
}

void the_whistling_gorge()
{
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Take the path on the left\n";
    cout << "B. Take the path on the right\n";
    cout << "C. Look around where you are\n";
    cout << "D. Go back\n";
    print_line();
    cin >> choice;
    choice = tolower(choice);

    switch(choice)
    {
        case 'a':
            print_line();
            if(denied_fruit)
            {
                cout << "You look at the fruit and your stomach churns. Disgusted, you turn away from it, grateful you did not eat it and head back into the grove.\n";
                the_whistling_gorge();
            }
            else
            {
                cout << "You decide to take the path on the left. You walk forward and come to a small hill, where there is another dead tree\n"
                        "planted on the very crest of the hill. This tree however, bears fruit. Small, shriveled berries grow in clusters along\n"
                        "several of the branches. Some of which are within reach.\n\n";
                fruit_options();
            }
            break;
        
        case 'b':
            cout << "You head down the path on the right. As you walk down the path, you notice the trees here seem to be getting bigger.\n"
                "Unusual, given that you would think dead trees wouldn't grow.\n"
                "Soon, the path leads to a small clearing with a large black tree in the center, surrounded on all sides by a dense scattering of trees.\n"
                "The branches of said trees reach over the clearing, creating a domed roof that the sunlight is barely able to penetrate and casting the\n"
                "entire area into a gloomy shade.\n"
                "It is then you notice the hole in the center of the trunk of the large black tree,\n"
                "dimly glowing a shade of red, and the white twisted branch in the center of the hole.\n";
            branch_options();
            break;
        
        case 'c':
            if(twg_found_journal)
            {
                cout << "You briefly scan the area, but find nothing else of interest and turn back to the paths before you.\n";
                the_whistling_gorge();
            }
            else
            {
                cout << "You decide to look around where you are first before settling on a path. After a few seconds of looking over the area,\n"
                        "you find a stone between the paths that looks as though it was recently disturbed.\n"
                        "You look around it first and finding nothing, lift the stone up. Underneath, you find two folded pieces of paper.\n"
                        "Rolling the stone aside, you pick up the papers and begin to read:\n\n";
                cout << journal_entry_3;
                journals.push_back(journal_entry_3);
                cout << "Folding it up, you open the other paper.\n";
                cout << hint_6;
                cout << "You pocket the papers and walk back to your previous position. Once again, the paths lay before you.\n";
            }
            the_whistling_gorge();
            break;
        
        case 'd':
            cout << "You look back from where you came, but remember that solid rock that made up the way out -\n"
                    "you weren't getting out of here until you found what you needed.\n";
                    "You turn back to the paths ahead of you.\n";
            the_whistling_gorge();
            break;
        
        default:
        
            try_again();
            the_whistling_gorge();
    }
}

void fruit_options()
{
    char option;
    print_line();
    cout << "Eat the fruit? Y/N: ";
    cin >> option;
    cout << "\n";

    if(option == 'Y' || option == 'y')
    {
        cout << "Despite your better judgement, you reach up, pluck some berries off a low-hanging branch, and pop them into your mouth.\n"
                "Immediately, your mouth foams up as the berries hit your saliva. You choke and fall to your knees,\n"
                "leaning forward and trying desperately to spit them out, to no avail.\n"
                "The berries dissolve immediately and combine with your saliva to become a highly corrosive acid.\n"
                "Your tongue burns as the taste of blood appears for a second before your taste buds are burned away, followed by the rest of your tongue.\n"
                "The acid makes its way down your throat, dissolving your esophagus and exposing your throat to the parched air of the gorge.\n"
                "Blood spills down the front of your clothes and your lower jaw hangs loose as you finally fall forward,\n"
                "taking in wheezing breaths through the gaping hole in your neck.\n"
                "You lie on the parched white earth, succumbing to the pain, as everything around you fades to black.\n";
            
        cout << "\n\nEnding 12: Dissolved\n";
        print_line();
        retry(&the_whistling_gorge);
    }
    else if(option == 'N' || option == 'n')
    {
        cout << "Wisely, you decide not to take the fruit and turn around, heading back into the grove.\n";
        denied_fruit = true;
        the_whistling_gorge();
    }
    else
    {
        try_again();
        fruit_options();
    }
}

void branch_options()
{
    char option;
    print_line();
    cout << "Take the branch? Y/N: ";
    cin >> option;
    cout << "\n";

    print_line();
    if(option == 'Y' || option == 'y')
    {
        cout << "You slowly approach the tree and reach towards the branch in the trunk, expecting something horrible to happen to you before you can actually grab it.\n"
                "But nothing does, and you retrieve it successfully. Holding the twisted branch closer,\n"
                "you notice there are holes along the length of it and a larger one at one end.\n"
                "It's a flute, you realize. A slight breeze picks up and creates a low tune in the flute and in some of the surrounding trees.\n"
                "A cold chill creeps up your spine as a slight dizzying spell assaults you. You quickly regain your composure,\n"
                "put the flute away, and head back through the now open Gate.\n";
        inventory.push_back(the_whistling_gorge_key);
        twg_completed = true;
        temple_second_room();
    }
    else if(option == 'N' || option == 'n')
    {
            cout << "You decide not to take the branch and instead head around the tree and travel further into the forest.\n"
                    "Several minutes pass until you realize you're hopelessly lost.\n"
                    "You spin around in place, hoping to spot some familiar landmarks, but see nothing.\n"
                    "It is then a strong wind stirs up and you once again hear the strange whistling sound fill the air around you…\n"
                    "When you come to, you can't move. You spin your head and look up to see a hole with a view of the sky above, it is now nighttime.\n"
                    "Dirt fully encases your body from the neck down, completely immobilizing you. You scream, but soon stop, realizing how fruitless it is.\n"
                    "It is then you feel something wriggling in the dirt around you. Fear floods your body as you hear the earth shifting around you.\n"
                    "You try desperately to wriggle around, to try and escape, but it is hopeless. Roots burst from the surrounding soil,\n"
                    "wrapping themselves around your limbs and forcing themselves into your orifices.\n"
                    "You choke as the roots force their way down your throat, you grow deaf as your eardrums are ruptured,\n"
                    "and blinded as your eyes are crushed within their sockets.\n"
                    "Pain erupts in your skull as the roots invade your cranium. Somehow, pitifully, you are kept alive.\n"
                    "You feel the roots dig into your skin, invade your arteries,\n"
                    "and pierce your muscles.\n"
                    "It is then you hear the sickening crunch of bone as the roots permeate them. Your existence is nothing but pain, and you soon black out…\n\n"
                    "Dry.\n"
                    "Desiccate.\n"
                    "Dead.\n"
                    "Your limbs splay out, aching for moisture, reaching towards the sky that never grants rain.\n"
                    "Your ribs and spine gruesomely twisted into a trunk, patterned with holes down the length of your new body.\n"
                    "Your toes grown beyond anything humanly possible, planted firmly into the ground, writhing in eternal anticipation.\n"
                    "Everything that was human about you is now gone, as your mind fades away into eternity.\n"
                    "The wind blows and you hear it rise from the others around you, joining in yourself later. The whistle.\n"
                    "You join in the accursed chorus until the wind settles down and your song ends.\n"
                    "Soon.\n"
                    "Soon someone will come. And then you can feed again.\n";

            cout << "\n\nEnding 13: Dry\n";

            print_line();
            retry(&the_whistling_gorge);
    }
    else
    {
        try_again();
        branch_options();
    }
}