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
                    "\tHave you, this petrified might?\n";
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
    string object;
    print_line();
    cout << "After walking for several minutes, you now find yourself in another peculiar location. Before you lays a corridor with a sudden drop off ahead, descending into pitch black darkness.\n"
            "Inching closer, you look over the edge and suddenly the whirring of machinery starts as platforms materialize out of thin air before disappearing a second later.\n"
            "You watch for a bit but can discern no pattern to their appearances, with it being seemingly randomized. Not only that, but the platforms appear and disappear in random directions,\n"
            "with some appearing in a position that draws you closer to the other side and some that go away from or in another direction entirely.\n"
            "Try as you might, you cannot get a hold of any possible pattern to them, only noticing that they appear within jumping distance of each other,\n"
            "but the timing of the appearances is so precise to the point that they would only appear when you had already jumped. You watch for a bit longer and can confirm that you would have to already\n"
            "be in the air when another platform appears. With this in mind, you look over the items you have.\n";
    print_line();
    show_inventory();
    cout << "What object would you like to use?\n";
    print_line();
    object = remove_from_inventory();
    cout << "You select " << object << " from your inventory and use it.\n";
    print_line();
    
    if(object == the_heart_of_the_colony_key)
    {
        cout << "Holding out the Amber Eye, you are suddenly assaulted by a stream of images flooding your mind. Scenes from your journey up until this point,\n"
                "scenes of what would have happened if you had answered wrong on the previous puzzle, and finally, scenes of you attempting the puzzle you are now faced with.\n"
                "In a split second, you watch yourself die a thousand times over, some with other objects, some with the Amber Eye itself. You focus, mentally sorting through the images\n"
                "until you come across some that offer actual solutions to the puzzle. Closing your eyes, you envision yourself leaping from one ephemeral platform to another,\n"
                "paying special attention to when the platforms appear. And soon, you body freezes up, but then floods with adrenaline as you suddenly charge forward and take a flying leap from the edge of the pit.\n"
                "You land on a floating platform that wasn't there a mere fraction of a second earlier. Quickly, you get back up and jump in another seemingly random direction,\n"
                "the images from the Amber Eye flasing through your mind. Instantly, another platform appears, saving you from falling to your death. You keep this up,\n"
                "jumping from one location to another until you're close enough to the other side to make one final jump to safety. You jump to the other ledge, your momentum causing you to roll.\n"
                "For a moment, you just lay there, staring upward as you catch your breath. Your legs burn from all the jumping and for a moment, you feel as though you can't get back up.\n"
                "After a long pause however, you do. You make your way to the other side of the chamber where a door with a slot in it stands. Placing the Amber Eye in the slot, the door opens up and you proceed forward.\n";
        third_puzzle();
    }
    else if(object == the_glowing_cave_key)
    {
        cout << "Holding the Fossil in your hand, you feel your body flood with a renewed sense of power as your senses heighten and your body feels lighter, though not as much compared to the cave you found it in.\n"
                "With a renewed vigor, you jump into the pit safely onto a materialized platform. With your heightened hearing and echolocation, you can just make out when the platforms might appear. You continue jumping,\n"
                "slowly making your way to the other side. Then, when you're just one platform away from the other side, you misjudge a jump, missing the platform by mere inches. As you fall into the dark pit, you feel the\n"
                "effects of the Fossil intensify, but it's all no use now, as the ground rushes up to meet you.\n";

        cout << "\n\nEnding 26: Fossil doesn't fly\n";
        print_line();
        retry(&second_puzzle);
    }
    else
    {
        cout << "You jump from platform to platform, but to no avail. The platform disappears from underneath you, and you fall to your death.\n";
        cout << "\n\nEnding 25: Overzealous\n";
        print_line();
        retry(&second_puzzle);
    }
}

void third_puzzle()
{
    string object;
    print_line();
    cout << "After a brief period of time you come across a closed door. However, this door is different from the ones you've seen thus far. It resembles more of a blast door\n"
            "with thick windows than the usual stone doors with slots in them. Next to the door is a small screen. Ignoring the screen for now, you peer through the windows of the blast door.\n"
            "Inside, you see a chamber: one full of huge centipede-like creatures, all crawling over each other and occasionally fighting. You stare for a moment in disbelief\n"
            "at the size of the creatures, before lurching back when one of them takes notice of you and attempts to break the thick glass of the blast door before giving up and returning to\n"
            "crawling over the others, like a writhing mass of worms. From a small break in between the creatures' writhing mass, you spy another blast door and just beyond that, the usual slotted door.\n"
            "It is then you notice a raised platform to the right of the other blast door, you can't see much from here, so you turn to the screen next to you. The small screen resembles what looks like a camera feed,\n"
            "showing the interior of the chamber from a different angle that shows the surface of the raised platform. On the top of the raised platform, you see a glowing raised tile.\n"
            "As a few of the creatures walk over the tile, you see it ever-so-slightly give, before popping back up when all of them leave. You look around you and spy a button on the left side of the chamber door,\n"
            "inferring its purpose to be to open the door. You look back to the swarming mass of insectoids inside before looking through your options.\n";
    print_line();
    show_inventory();
    cout << "What object would you like to use?\n";
    print_line();
    object = remove_from_inventory();
    cout << "You select " << object << " from your inventory and use it.\n";

    if(object == the_whistling_gorge_key)
    {
        cout << "Holding Twisted Bone to your mouth, you quickly hit the button next to the door and blow into the flute. Immediately, the centipede-like creatures freeze, stunned by the inaudible sound of the flute.\n"
                "Slowly, you force them to clear a path for you to the other blast door. They stand by, close enough for you to see the unbridled anger and hatred in their eyes, despite their otherwise calm-looking exterior.\n"
                "Still playing the flute, you finally reach the blast door, only to find that there is no button nearby. You frantically search for it, your eyes looking around wildly as your mouth starts to grow tired.\n"
                "Then you remember the raised platform next to you with the raised tile on it. You look to it and immediately, nearby creatures start to climb up to the platform and sit on the tile, gently depressing it.\n"
                "After several of them fully depress the tile, the blast door finally opens. Your mouth is hurting now, and as you quickly step past the door you tear Twisted Bone away from your mouth and take a gasp of air.\n"
                "Instantly, the creatures break out of their trance and rush towards you, but the blast door quickly shuts again as the tile raises once again.\n"
                "Holding your chest, you feel your heartbeat slowly start to calm back down as you look to the other door ahead of you - a familiar one with a slot for Twisted Bone in it. Placing the flute in the slot of the door,\n"
                "it opens and you head through it.\n";
        fourth_puzzle();
    }
    else if(object == the_swamplands_key)
    {
        cout << "Gripping the Black Heart in your hand, you will your body to change form, taking on a more aggressive appearance. The appearance of a predator.\n"
                "As your muscles ripple under your pitch-black skin, your teeth grow long and pointed and your nails grow into long sharp claws. Feeling invincible,\n"
                "you smash the button and open the blast door. Immediately, you are assaulted by several of the huge creatures, all gnashing jaws and teeth, their multi-segmented bodies\n"
                "lined with several long, sharp legs wrap around you, piercing into your body. They swarm over you, but you fight back, tearing their bodies apart with your newly grown teeth and\n"
                "slamming their comparatively fragile bodies into the hard ground, splattering them all over. Bloodlust fills you as you charge into them, ripping them to pieces with your claws and teeth,\n"
                "smashing the rest with your massive hands and feet. You fight and fight and fight, but they continue to swarm over you, relentless and unforgiving. Merciless, they slowly beat you back as your\n"
                "strength and energy wanes, unable to keep steady as you attempt to keep up your slaughter. Only when the room is nearl empty and you're so tired you can barely stand do you realize the other\n"
                "blast door is still shut tight. You lean over, exhausted, as several new tentacles sprout from your back and slice and stab any creatures that dare to approach you. Soon, the room is empty all\n"
                "around you... but the door remains shut. You fall to your knees and feel your mind on the verge of breaking, as the muscles in your body burn with the promise of pain and the Heart whispers to you\n"
                "sweet dreams of carnage and carrion. As you look up to ceiling of the room, you notice several doors open as more of the creatures are poured back in, several thousand at a time.\n"
                "Your mind snaps and your body moves on its own, showering itself in the blood and gore of the creatures as they mindlessly attack you over and over.\n"
                "You feel your consciousness leave you as the last thing you hear before completely giving in to insanity is the blast door closing behind you.\n";

        cout << "\n\nEnding 28: Endless Bloodlust\n";
        print_line();
        retry(&third_puzzle);
    }
    else
    {
        cout << "You open the door and try to use the object, but to no avail. And in that moment, you realize your horrible mistake as a wave of jaws, teeth, and long sharp legs comes barreling towards you.\n";
        cout << "\n\nEnding 27: Splattered\n";
    }
}

void fourth_puzzle()
{
    cout << "After a short period of time you come across another unique chamber: a long corridor with a door at the other end";
}