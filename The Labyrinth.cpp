// File containing functions for The Labyrinth passage
#include <iostream>
#include <string>
#include "Functions.hpp"
#include "Journal Entries.hpp"
#include "Trackers.hpp"
#include "Items.hpp"
#include "The Labyrinth.hpp"

using namespace std;

void door_object(char option);

string first_puzzle_death = "The door remains closed. Surprised, you reach for the object but the floor suddenly opens up beneath you.\n"
                            "You fall into the dark abyss, but never stop falling. Down and down, impossibly deep.\n"
                            "You fall for what feels like forever. Until you suddenly meet the end.\n"
                            "\n\nEnding 22: Splat\n";

string remove_from_inventory()
{
    int index;
    string object;
    cout << "Use 1-6 for the object you wish to use.\n";
    print_line();
    cin >> index;
    if(index < inventory.size() && index >= 1)
    {
        object = inventory.at(index);
        inventory.erase(inventory.begin()+index);
        return object;
    }
    else
    {
        cout << "Number out of range, please try again.\n";
        remove_from_inventory();
    }
}

void the_labyrinth_text()
{
    cout << "Unlike the other portals, you don't seem to be forced through. Rather, you find the ingress rather to be much easier.\n"
            "You look around you, at first it seems as though there is nothing but a long stone floor all around you polished to a mirror-like sheen.\n"
            "Then, the blocky outlines of edges form around you in a bright white light, like a solid wire mesh in a 3D animating program.\n"
            "Gradually, the meshes fill in with solid matter - more of the smooth, polished stone fills in the wire meshes, conforming to the shapes of them.\n"
            "And soon, massive walls materialize right before your eyes as you stand at the beginning of a giant maze. As the surfaces fill in around you,\n"
            "you finally take a step forward and truly take in your surroundings. Not only have walls sprang up on either side of you, but even the ceiling\n"
            "of the massive chamber has wall formed in the pattern of a maze. To your amazement, the chamber doesn't seem to have any hard edges,\n"
            "as you can see the floor slowly curve to meet the walls, and later, the ceiling. The sight dizzies you for a bit, and you lean against the wall nearby\n"
            "as you gather your senses. Eventually, you stand back upright and move forward. You've come this far already, nothing's going to stop you now.\n";
    first_puzzle();
}

void first_puzzle()
{
    char choice;
    cout << "You proceed further into the maze and eventually happen upon an unusual sight:\n"
            "A room with three doors in front of you, each one enscribed with a riddle and possessing a hole in the center of the door.\n"
            "You have the left door, the center door, and the right door.\n";
    
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Approach the left door\n";
    cout << "B. Approach the center door\n";
    cout << "C. Approach the right door\n";
    print_line();
    cin >> choice;
    choice = tolower(choice);

    print_line();
    switch(choice)
    {
        case 'a':
            cout << "You approach the left door and read the riddle:\n"
                    "\tLustrous and gleaming, fit for royalty\n"
                    "\tCarved into the face of Death, I grin for eternity\n"
                    "\tMy scarlet smile never wanes, yet amusement is not to blame\n"
                    "\tI stand for greatness, but possess no dexterity\n"
                    "\tI am the physical construction of a name\n";
            door_object(choice);
            break;
        
        case 'b':
            cout << "You approach the center door and read the riddle:\n"
                    "\tDealt with the swift hand of fate,\n"
                    "\tEminence slapped across the face,\n"
                    "\tAn object of prescience and relay,\n"
                    "\tThe path warned of bearing respect,\n"
                    "\tHave you, the object?\n";
            door_object(choice);
            break;
        
        case 'c':
            cout << "You approach the right door and read the riddle:\n"
                    "\tDwelling in darkness, a strange apparition,\n"
                    "\tEmitting a soft glow, resembling commotion,\n"
                    "\tAn object of unknown origin, granting extra locomotion,\n"
                    "\tThough, only applicable in the lack of light,\n"
                    "\tHave you, this petrified might?";
            door_object(choice);
            break;
        
        default:
            try_again();
            first_puzzle();
    }
}

void door_object(char option)
{
    string object;
    print_line();
    cout << "The hole in the center of the door has enough room for one of the objects in your inventory.\n";
    cout << "What object do you want to put in?\n";
    show_inventory();
    print_line();
    object = remove_from_inventory();
    cout << "You place " << object << " into the hole in the door\n";
    print_line();
    switch(option)
    {    
        case 'a':
            if(object == the_desert_of_the_dead_key)
            {
                cout << "With a loud thud, the door sinks into the floor, revealing the path beyond.\n";
                second_puzzle();
            }
            else
            {
                cout << first_puzzle_death;
                print_line();
                retry(&first_puzzle);
            }
            break;
        
        case 'b':
            if(object == the_heart_of_the_colony_key)
            {
                cout << "With a loud thud, the door sinks into the floor revealing another gateway beyond.\n"
                        "With confidence, you step into the gateway. After the initial force and regaining your balance, you open your eyes, expecting to see another room in the Labyrinth.\n"
                        "Instead, what you see causes all your confidence to disintegrate. You find yourself back in the Hive, and standing in front of you is the Ant Queen, the Amber Eye clutched in her right hand.\n"
                        "Her eyes, although multifaceted and lacking any real form of facial expression, seethe with an unbridled malice.\n"
                        "You quickly reach for the dagger and bring it out, but the Ant Queen is quicker, grabbing your arm roughly, the force of which causes you to inadvertently toss the dagger away.\n"
                        "With her other arm, she grabs you by the throat and lifts you into the air. You grasp for breath and futilely claw at the hardened chitin of her clawed fingers.\n"
                        "\"YOU!\" you hear her scream in your head, the force of which combined with the lack of oxygen causing a massive pain in your skull.\n"
                        "\"YOU DARE TO DISRESPECT ME? YOU COME INTO MY DOMAIN, STEAL MY TREASURE, AND DARE TO STRIKE ME?!\" she telepathically roars, throwing you down.\n"
                        "You hit the ground hard, bouncing once before laying still and taking in a shuddering breath. You try to lift yourself up, but are forced back down when the Queen\n"
                        "places one of her feet onto your back, forcing your face into the dirt. She grabs your head by the hair and twists it to the side to look her straight on as she leans down to your level.\n"
                        "\"Remember what I told you would happen if you bring harm to any of my subjects?\" she thought-speaks, her \'voice\' dripping with barely-restrained malevolence.\n"
                        "Your eyes widen as you remember her warning: \"Your bones will line my walls\" and an involuntary whimper escapes your mouth.\n"
                        "Her eyes shine with malicious glee when she realizes you do, in fact, remember.\n"
                        "\"Good,\" she says, \"As Queen of the Hive, I make sure to keep my promises. It just wouldn't do if I wasn't a good role model for my subjects, now would it?\"\n"
                        "She clamps down hard on your skull, her claws drawing blood that seeps into your eyes as she lifts you up by your head.\n"
                        "You desperately try to pull against her vice-like grip with your hands as you scream in pain, but she only tightens her grip.\n"
                        "She raises you up to her face and stares directly into your eyes one final time.\n"
                        "\"Goodbye, traveler. I'll make sure to decorate my chamber with whatever's still intact,\" she says before she swiftly and violently slams you into the hard, compacted dirt of her chamber.\n"
                        "Bones all across your body violently snap upon impact as the last thing you feel is unimaginable pain before the life leaves your eyes.\n";
                cout << "\n\nEnding 23: A Scorned Queen\n";
            }
            else
            {
                cout << first_puzzle_death;
            }
            print_line();
            retry(&first_puzzle);
            break;
        
        case 'c':
            if(object == the_glowing_cave_key)
            {
                cout << "With a loud thud, the door sinks into the floor revealing another gateway beyond.\n"
                        "Confidently, you stride into the gateway, assured in your answer.\n"
                        "You arrive on the other side into darkness and a strikingly familiar sound: a waterfall.\n"
                        "You look around you and notice the familiar land bridge with the roaring waterfall falling into canyon below, somehow darker than you remember.\n"
                        "You tense slightly, turning around to notice that the tunnel leading back to the main chamber is now closed off by several large boulders that appear to have fallen from above.\n"
                        "You slowly turn back around to see that same light on the other side of the bridge, slowly swinging back and forth, almost hypnotically.\n"
                        "You notice a thin ledge to the left of the bridge trailing off into the darkness, hugging the wall of the large cave, something you didn't notice before and decide that,\n"
                        "with the only known exit closed off, that is the only option left. You slowly make your way towards it, taking carefully measured steps, keeping your eyes on the path ahead.\n"
                        "As you tentatively make your way through the darkness, you regret putting The Fossil into the door, wishing it was here now to help you, or that there was at least more light to see by.\n"
                        "You continue on your way, the path coming into more focus, seemingly lit by some unknown source. It is then that you realize the waterfall is no longer splashing onto the bridge to your right.\n"
                        "The hairs on the back of your neck stand straight up as you finally hear it - deep breathing that you had mistaken as wind traveling through the chamber eariler.\n"
                        "The terrifyingly familiar orange glow dancing above you now, making your shadow lean from side to side, almost as if in an terror-stricken dance.\n"
                        "A hot, humid breath suddenly caresses the stiff hairs along your neck and you shut your eyes as you brace yourself for what you're about to see, remembering how you wished to never witness it again.\n"
                        "You slowly turn around, foolishly hoping it wasn't what you feared. You open your eyes and immediately regret it. You stare hopelessly into those same huge opal globes of the reptillian monstrosity.\n"
                        "Its huge jaws cracked open, breathing hot, sticky fire your way. Its tongue licks the air, taking in your scent. You hold back as long as you can, but your fear eventually wins.\n"
                        "You scream, long and loud. And throughout that long chamber, the sound of a massive jaw snapping closed echoes throughout.\n";
                cout << "\n\nEnding 24: Canyon Crawler\n";
            }
            else
            {
                cout << first_puzzle_death;
            }
            print_line();
            retry(&first_puzzle);
            break;
        
        default:
            cout << "You shouldn't be able to read this. Something is definitely wrong.\n";
            retry(&first_puzzle);
    }

}

void second_puzzle()
{

}