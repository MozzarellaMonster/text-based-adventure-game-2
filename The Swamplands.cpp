// File containing functions for The Swamplands passage
#include <iostream>
#include <string>
#include "The Swamplands.hpp"
#include "Functions.hpp"
#include "Journal Entries.hpp"
#include "Trackers.hpp"
#include "Items.hpp"

using namespace std;

void the_swamplands_text()
{
    cout << "You stumble out of the Gate and immediately get your foot stuck in a deep puddle of mud. The mud sucks at your shoes as you desperately try to free your foot without falling over.\n"
            "Thankfully, after much wiggling and pulling, you manage to free your foot, shoe and all, from the mud without so much as a slight stumble. You finally look up from the muddy puddle\n"
            "and take in your surroundings - you're in an unfamiliar swamp. Tall trees with large roots dot the landscape and tall grass covers the few areas that are above-water.\n"
            "Taking a cautious step forward, you stay on what little solid ground you can find, until you find a large boulder sticking out of the water that allows you some height to take in more of your surroundings.\n"
            "Standing atop it, you see that the swamp is divided into three distinct areas - one shady area covered in weeping willow trees consisting mainly of small islands, another area with a considerable\n"
            "lack of large trees mostly consisting of tall grass and waist-high water, and the final area making up the majority of the swamp with large trees and very deep water you would need a boat to go through.\n"
            "Thankfully, from your high position, you spot a dock with a small boat anchored to it. Climbing down, you make your way to the dock where you find a barrel of rope with a piece of folded paper nested within.\n"
            "Unfolding the piece of paper, you read:\n\n";
    cout << journal_entry_5;
    cout << "Look back down into the barrel, you notice another folded piece of paper. Retrieving it and opening it up, you read:\n\n";
    cout << hint_5;
    cout << "Suddenly, you hear a loud roar erupt from the central area of the swamp, where the tall trees hide the source of it. Scared but determined, you stand before the options before you - you could explore\n"
            "the left area that consists of tall grassland higher than your shoulders, a central area that consists of tall trees and deep waters, or the right area that is made up of lots of little islands and\n"
            "several weeping willow trees.\n\n";
}

void the_swamplands()
{
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Explore the tall grasslands\n";
    cout << "B. Explore the deep swamp with tall trees\n";
    cout << "C. Explore the clusters of tiny islands\n";
    cin >> choice;
    choice = tolower(choice);

    switch (choice)
    {
    case 'a':
        // Headhunters
        cout << "You decide to explore the tall grasslands.\n"
                "Getting into the boat, you paddle your way to the left area where tall grasslands greet you on thankfully solid ground. Reaching a smaller, more decrepit dock, you tie your boat to a piling\n"
                "and climb out. As expected, the grass is much higher than what you initially expected, well above your full height. With deep trepidation, yet equally deep determination, you step into the grasslands.\n"
                "Several minutes pass before you come across anything within the field. Even traveling in a straight line, you're pleasantly surprised that nothing has actually tried to kill you yet.\n"
                "Unexpectedly however, the monotony is dropped once you come across an unusual sight - a small camp of wooden and straw huts. And small is not an exaggeration, the huts are barely above knee-height.\n"
                "You stoop low to look inside one of them - empty. Eventually, you spot several small footprints on the ground leading away from every hut and into the tall grass. You now have two options - follow the\n"
                "footprints further into the grass or go in a separate direction away from them.\n";
        grasslands();
        break;

    case 'b':
        // Alligators, 'living hive' death, and The Black Heart
        cout << "You decide to explore the area with the tall trees.\n"
                "";
        break;

    case 'c':
        // Totems - wooden entities that stalk the player through the water of the swamps, only moves when the player is not looking directly at them.
        cout << "You decide to explore the cluster of small islands.\n"
                "";
        break;
    
    default:
        try_again();
        the_swamplands();
        break;
    }
}

void grasslands()
{
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Follow the footprints\n";
    cout << "B. Go in a separate direction\n";
    cin >> choice;
    choice = tolower(choice);

    switch (choice)
    {
    case 'a':
        cout << "You decide to follow the footprints.\n"
                "Approaching slowly, you follow the trail of footprints deeper into the tall grass, making sure to keep an ear out for anything that might\n"
                "try to get the jump on you. After a few moments, you start to hear noise nearby where you see the tall grass thin out. Quietly, you approach\n"
                "the edge of the tall grass. Cautiously peering out, you spy four small monkey-like figures with carved wooden masks gathered around the corpse\n"
                "of some kind of horned ungulate, cutting into the beast with pale daggers and speaking to each other in a strange harsh tongue. Slowly backing up,\n"
                "you turn to leave. Suddenly, another one of the small hominids suddenly jumps out in front of you and screeches pointing a sharp spear at you.\n"
                "Instantly, you hear the others stop what they're doing and race towards the both of you. You brandish the dagger and turn to the side to keep all\n"
                "five of them in sight. It's no good however, as they split up and circle around you, ushering you further out of the tall grass and into the the\n"
                "clearing you found them in. You grip the dagger tight, trying to keep as many as possible in your sight. It's futile however, as one of the distracts\n"
                "you by coming a little too close and drawing your attention, allowing another to jump on your back and stick the tip of a small sharp wooden stick\n"
                "into your neck. Instantly, you shake him off, but he only whoops in triumph as he digs his sharp little claws through your clothing and into your skin.\n"
                "After a few seconds, the world starts to blur around you and your movement becomes sluggish and slow. Eventually, your leg muscles give in and you fall\n"
                "to the ground, unconscious.\n"
                "The smell of a crackling fire awakens you and you find that you're now back in at the small camp you found earlier, tied securely to a log and the five small\n"
                "hominids are gathered around you. One is standing next to your head, brandishing a crude wood and bone axe. Your eyes widen as you realize what's about to happen.\n"
                "Slowly, one of the members starts to chant and the others soon join in. You pull against the bonds, flexing your muscles, trying everything you can to loosen them.\n"
                "Their chanting grows louder and the one holding the axe slowly raises it above your neck. You try to scream but it only comes out as a muffled moan against the rag\n"
                "tied over your mouth. You scream as the chanting grows ever louder until suddenly they stop, the axe held high. You look up, surprised. Then the one holding the axe\n"
                "breaks out in a gleeful smile and yells maniacly, bringing the axe down swiftly on your exposed neck.\n";

        cout << "\n\nEnding 17: Beheaded\n";
        print_line();
        retry(&grasslands);
        break;

    case 'b':
        cout << "You decide to head in a separate direction away from the footprints.\n";
        break;
    
    default:
        try_again();
        grasslands();
        break;
    }
}

void tall_trees()
{
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "";
    cin >> choice;
    choice = tolower(choice);

    switch (choice)
    {
    case '':
        cout << "";
        break;
    
    default:
        try_again();
        tall_trees();
        break;
    }
}

void islands()
{
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "";
    cin >> choice;
    choice = tolower(choice);

    switch (choice)
    {
    case '':
        cout << "";
        break;
    
    default:
        try_again();
        islands();
        break;
    }
}