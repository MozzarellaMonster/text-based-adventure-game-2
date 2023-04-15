// File containing functions for The Oasis passage
#include <iostream>
#include <string>
#include "The Oasis.hpp"
#include "Functions.hpp"
#include "Journal Entries.hpp"
#include "Trackers.hpp"
#include "Items.hpp"

using namespace std;

bool middle_path_intro = false;

void the_oasis_text()
{
    print_line();
    cout << "You stumble out of the portal and quickly catch your balance as it closes behind you. Standing up straight, you take in your surroundings.\n"
            "You find yourself in a hot and humid jungle, large trees and exotic-looking plants surround you on all sides. The sun burns brightly through the canopy of trees.\n"
            "Although the jungle is dense and the undergrowth thick, you're just able to make out three pathways in front of you - one to your left, one directly ahead, and another to your right.\n"
            "Looking behind you, you see a carved stone archway with no active portal. You look back towards the three pathways in front of you.\n";
    the_oasis();
}

void the_oasis()
{
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Explore the left path\n";
    cout << "B. Explore the middle path\n";
    cout << "C. Explore the right path\n";
    print_line();
    cin >> choice;

    if(choice == 'A' || choice == 'a')
    {
        cout << "You decide to explore the left path.\n"
                "You look towards the left path. It lays in darkness, an overarching tunnel of branches that goes deeper into the jungle. You hesitate for just a moment, but step forward into the tunnel.\n"
                "After several minutes, you find yourself in a small clearing. The floor of the clearing is littered with strange-looking twigs. Curious, you lean down and pick up a few of the twigs, rolling them between your fingers.\n"
                "You inspect one of the twigs closely, small, white and perforated. Very brittle as well, you note as it snaps easily between your fingers. It is then you notice the marrow in the center of the twig.\n"
                "These aren't twigs, they're bones. Your blood freezes as you drop the bones you're holding and turn to run. As you turn, a low growl rumbles all around you, and steadily grows louder.\n"
                "You quickly turn to look at the entrance to the clearing, but you're met with a close-knit, intertwined collection of branches blocking the entrance. You're trapped here. The rumble is incredibly loud now.\n"
                "It is then you hear wooden creaks as several branches are shifted away from the 'wall' of the clearing opposite the entrance, and a hideous gaping maw is shown in the space left behind.\n"
                "Your heart gallops in your chest as the humid breath of the huge mouth hits you and several large tentacle-like tongues slowly wind their way down the gullet of the thing in the branches.\n"
                "You desperately turn back to the entrance of the clearing and tear at the branches blocking your way, slivers and cuts be damned. You snap away as many of the branches as you can, but see through\n"
                "the spaces between them that they are quickly replaced with more as the entrance is further barricaded, cutting off the dim light from the tunnel in the process and hopelessly sealing you in.\n"
                "The tongues slither ever closer, taking their time to savor the moment - playing with their prey. You feel the breath of the thing grow in anticipation as one of the tongues finally wrap around your ankle,\n"
                "another around your waist. As a final futile attempt at escape, you plunge your arm into the interwoven barricade of branches and grab one of them. Slowly, the tongue grows taut as the thing struggles to pull you in.\n"
                "It pulls and pulls, but you hold fast, pulling yourself away whenever the thing grows tired. Finally impatient with this tug-of-war, the thing's final tongue wraps around the shoulder of the arm planted in the\n"
                "web of branches and with great force, pulls. You hear a sickening pop as your shoulder dislocates and you scream in pain, but the thing is not done. It pulls even harder and harder, the fabric of your clothes\n"
                "tearing at the seams. The pain is unbearable. And with a final tug, the things pulls you free of the branches, several pieces of skin left behind on sharp thorns within. Tears flow freely now as your limp arm\n"
                "drags behind you and you close your eyes in defeat as you enter the warm mouth of the thing.\n";
        
        cout << "\n\nEnding 14: Eaten\n";
        print_line();
        retry(&the_oasis);
    }
    else if(choice == 'B' || choice == 'b')
    {   
        if(!middle_path_intro)
        {
            cout << "You decide to explore the middle path.\n"
                    "Peering through the trees, you can just make out a beautiful waterfall in the distance, a small rainbow reflected in the spray.\n"
                    "You follow the path through the jungle until you stand on the shore of the small pond the waterfall pours into. You stare at the beauty all around you. \n"
                    "The roar of the waterfall provides some natural white noise as you slowly close your eyes and simply soak in the moment. It's a nice reprieve from what you've been through lately.\n"
                    "Several moments later, after taking one final deep breath, you finally open your eyes and return to your previous mindset: looking for what you need.\n";
            middle_path_intro = true;
        }
        cout << "You stand on the shoreline of the small pond the roaring waterfall pours into. To your left, you see a pile of rocks set against a cliff wall next to the waterfall,\n"
                "to your left lies a log overgrown with mushrooms and moss, but appears hollow inside, and directly ahead of you lies the waterfall, which would definitely conceal some kind of hidden area\n"
                "if this was some kind of text adventure game.\n";
        pond_options();
    }
    else if(choice == 'C' || choice == 'c')
    {
        cout << "You decide to explore the right path.";
        // Cliffside?
    }
    else
    {
        try_again();
        the_oasis();
    }
}

void pond_options()
{
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Investigate the pile of rocks\n";
    cout << "B. Investigate the overgrown log\n";
    cout << "C. Go through the waterfall\n";
    cout << "D. Go back\n";
    cin >> choice;
    choice = tolower(choice);

    switch (choice)
    {
    case 'a':
        cout << "You decide to investigate the pile of rocks next to the waterfall.\n";
                // Find journal and hint here
        break;
    
    case 'b':
        cout << "You decide to investigate the overgrown log.\n";
                // Death - mold from first game
        break;
    
    case 'c':
        cout << "You decide to go through the waterfall.\n";
                // Entry into new area
        break;

    case 'd':
        cout << "You decide to go back through the jungle.\n";
                // Go back
        break;
    
    default:
        break;
    }
}