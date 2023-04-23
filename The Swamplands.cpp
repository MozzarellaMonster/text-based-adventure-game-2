// File containing functions for The Swamplands passage
#include <iostream>
#include <string>
#include "The Swamplands.hpp"
#include "Functions.hpp"
#include "Journal Entries.hpp"
#include "Trackers.hpp"
#include "Items.hpp"

using namespace std;

// Possible scenarios - alligators, small 'swamp spirits' that hunt you down and turn you into a shrunken head, a strange being stalking you possessing the Black Heart, 'living hive', cannot stay here past dusk

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
    cout << journal_entry_5; // Not finished
    cout << "";
}

void the_swamplands()
{
    char choice;
    print_line();
    cout << "A. Explore the tall grass\n";
    cout << "B. Explore the shady area\n";
    cout << "C. Explore the deep area\n";
    cin >> choice;
    choice = tolower(choice);

    switch (choice)
    {
    case 'a':
        cout << "";
        break;

    case 'b':
        cout << "";
        break;

    case 'c':
        cout << "";
        break;
    
    default:
        try_again();
        the_swamplands();
        break;
    }
}