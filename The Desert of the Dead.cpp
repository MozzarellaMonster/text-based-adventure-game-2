// File containing functions for The Desert of the Dead passage
#include <iostream>
#include <string>
#include <conio.h>
#include "The Desert of the Dead.hpp"
#include "Functions.hpp"
#include "Journal Entries.hpp"
#include "Items.hpp"
#include "Trackers.hpp"

using namespace std;

bool dod_explored_room = false;
bool dod_looked_outside = false;
bool dod_investigated_platform = false;
bool dod_sandstorm = false;
bool dod_used_dagger = false;

void reset_dod()
{
    dod_explored_room = false;
    dod_looked_outside = false;
    dod_investigated_platform = false;
    dod_sandstorm = false;
    dod_used_dagger = false;
}

void the_desert_of_the_dead_text()
{
    interlude();
    #ifndef _WIN32
    system("cls");
    #endif

    #ifndef linux
    system("clear");
    #endif
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

void the_desert_of_the_dead()
{
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Look around the room\n";
    cout << "B. Investigate the center platform\n";
    if(dod_looked_outside)
    {
        cout << "C. Go out into the desert\n";
    }
    else
    {
        cout << "C. Look outside\n";
    }

    print_line();
    char choice = getch();
    choice = tolower(choice);
    cout << choice << "\n";
    
    print_line();
    switch(choice)
    {
        case 'a':
            cout << "You decide to look around the room.\n\n";
            if(!dod_explored_room)
            {
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
            else if(dod_investigated_platform)
            {
                cout << "You wander around, looking at the names of tombs you pass, looking for the Crimson Head family name.\n"
                        "As you move, you hear something - a shuffling noise, but every time you look towards the noise, you don't see anything.\n"
                        "You continue to move along between the rows of tombs. The sandstorm persists outside the building.\n"
                        "You are about halfway through the rows of tombs, still looking for the Crimson Head family name when something grabs your foot.\n"
                        "You quickly look down to see the head of a mummified corpse poking out of the sand, its soulless eyes staring straight up at you and its hand grabbing your foot.\n"
                        "It then roars with an unearthly low growl that resonates throughout the chamber.\n"
                        "There is a moment of absolute silence before a chorus of unearthly screams erupt from every tomb in the room.\n"
                        "Panicking now, you rip your foot out of the mummy's grip and run towards the entrance of the building.\n"
                        "You try to force yourself into the sandstorm but are viciously flung backwards as the sandstorm picks up in even more intensity.\n"
                        "You pull yourself into a sitting position and look towards the entrance, but freeze and scream at what you see.\n" 
                        "Within the silicon tempest, a skull forms out of the flying sand, eyes shining with an ethereal bright blue light.\n"
                        "It roars at you and the voice in your head speaks again, \"You disturbed their peace, and now you will pay with your life.\"\n"
                        "It is then you notice the sound of the lumbering forms behind you. Before you can move, you are roughly pulled to your feet.\n"
                        "The mummy pulls you into the crowd of corpses. You kick and scream, but there is nothing more you can do as they pull you apart piece by piece.\n"
                        "As your screams soften into gurgles and the light leaves your eyes, the swarm of bodies disperses, the sandstorm calms, and all is silent in the desert again.\n";

                cout << "\n\nEnding 6: Torn\n";
                reset_dod();
                retry(&the_desert_of_the_dead_text);
            }
            else
            {
                cout << "You walk between the rows of tombs again.\n"
                        "After several minutes of this, nothing different jumps out at you.\n"
                        "You head to the wall of sarcophaguses and inspect them again.\n"
                        "The mummified remains continue to hang loosely out of some of them.\n"
                        "It would be best not to touch them.\n"
                        "You return to the entrance of the room.\n";
                the_desert_of_the_dead();
            }
            break;

        case 'b':
            cout << "You decide to investigate the center platform.\n\n";
            if(!dod_investigated_platform)
            {
                cout << "You head up to the raised platform in the center of the room.\n"
                        "On it lies a large stone tablet, several thousand names are inscribed on it.\n"
                        "Next to it, lays a note with a stone weighing it down.\n"
                        "You remove the stone and pick up the note. It reads:\n";
                cout << hint_2;
                cout << "As if on cue, you hear a shuffling noise somewhere ahead of you.\n"
                        "Your head snaps up to look in the direction of the noise, but you see nothing.\n"
                        "You fold up the piece of paper and stuff it in your pockets.\n"
                        "It is then you notice the world growing darker. You quickly glance toward the ceiling windows.\n"
                        "A sandstorm has started outside, the wind howling and blocking out the sun. Now, only the feeble light of the torches remains.\n"
                        "You head back to the entrance of the building.\n";
                dod_investigated_platform = true;
                dod_sandstorm = true;
                the_desert_of_the_dead();
            }
            else
            {
                cout << "You go to the raised platform in the middle of the room and look at the large stone tablet again, trying to locate the Crimson Head family name.\n"
                        "While you're looking through the names, something else catches your eye: a piece of paper folded and tucked in a crack on the side of the stone tablet.\n"
                        "Curious, you take the piece of paper out of the crack and unfold it. It reads:\n\n";
                cout << journal_entry_6;
                cout << "You fold up the piece of paper and stuff it in your pocket.\n"
                        "Your attention returns to the large stone tablet and you once again skim the text for the Crimson Head family name.\n"
                        "Finally, after several long moments, you find it near the bottom right of the stone tablet. Assuming the layout of the sarcophaguses are the same as presented on the stone tablet,\n"
                        "you jump off from the raised platform and run towards the bottom right end of the tombs.\n"
                        "It is only when you're nearly halfway there that you start to hear groaning and see motion out of the corner of your eye.\n"
                        "You look towards the tombs and notice several mummies have now opened their sarcophaguses and are climbing out.\n"
                        "It seems in your eagerness to get out of there, you accidentally woke up the dead. You quicken your pace.\n"
                        "There are a lot of mummies now, and they're all taking notice of you. You quickly run up to the tomb that was said to contain the Ruby Skull and deftly push the lid off.\n"
                        "There, inside the tomb lays a mummy holding the Ruby Skull in its cold dead hands. No time for respect or reverence, you quickly yank the Ruby Skull out of the mummy's hands and take off towards the exit.\n"
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
                journals.push_back(journal_entry_6);
                inventory.push_back(the_desert_of_the_dead_key);
                dod_completed = true;
                temple_second_room(true);
            }
            break;

        case 'c':
            if(!dod_looked_outside && !dod_sandstorm)
            {
                cout << "You decide to look outside.\n\n";
                cout << "You poke your head out of the doorway to the building you're in.\n"
                        "Heat waves ripple the air around you, forcing you to squint for a better view of your surroundings.\n"
                        "Mountainous volcanic rock ridges jut out of the sand several miles directly ahead of you.\n"
                        "To your left and right, there is nothing but sand and several smaller formations of the volcanic rock every hundred feet or so.\n"
                        "You pull your head back in and wipe the sweat from your brow.\n"
                        "After just peeking your head out for a moment, you have already felt the tremendous heat of the desert beyond the doorway.\n"
                        "In contrast, the building you're in is several degrees cooler than outside, with some protection from the heat of the sun.\n"
                        "It would be unwise to try wandering around the desert, you imagine. Still, the option is open to you if you so choose.\n"
                        "You look back to the room.\n";
                dod_looked_outside = true;
                the_desert_of_the_dead();
            }
            else if(dod_sandstorm)
            {
                cout << "You decide to look outside.\n\n";
                cout << "The sandstorm is so severe, there is no way you could find your way around out there.\n"
                        "You can't even safely stick your head out.\n"
                        "Despite this, sand somehow does not enter the building and you don't feel even the slightest of breezes.\n"
                        "You turn back to the room.\n";
                the_desert_of_the_dead();
            }
            else
            {
                cout << "You decide to head outside.\n\n";
                cout << "Despite the brutal heat and the extreme isolation, you head out into the desert.\n"
                        "Within minutes, you are severely sweating and overwhelmingly hot.\n"
                        "You turn to head back to the building, but don't see it anymore.\n"
                        "Turning wildly, you scan the horizon, but the building is nowhere in sight.\n"
                        "The only things that can be seen is sand and volcanic rock.\n"
                        "After futilely spinning around once more, hoping against hope the building would reappear, you hang your head in defeat and head deeper into the desert.\n"
                        "XXXXXXXXXXXXXXXXXXXXXXXX\n"
                        "           +====+\n"
                        "           |(..)|\n"
                        "           | )( |\n"
                        "           |(::)|\n"
                        "           +====+\n"
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
                reset_dod();
                retry(&the_desert_of_the_dead_text);
            }
            break;

        default:
            try_again();
            the_desert_of_the_dead();
    }
        
}