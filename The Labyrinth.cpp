// File containing functions for The Labyrinth passage
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>
#include "Functions.hpp"
#include "Journal Entries.hpp"
#include "Trackers.hpp"
#include "Items.hpp"
#include "The Labyrinth.hpp"

using namespace std;

void door_object(char option);

int saved_index = 0;
string saved_object = "";

string first_puzzle_death = "The door remains closed. Surprised, you reach for the object but the floor suddenly opens up beneath you.\n"
                            "You fall into the dark abyss, but never stop falling. Down and down, impossibly deep.\n"
                            "You fall for what feels like forever. Until you suddenly meet the end.\n"
                            "\n\nEnding 22: Splat\n";

void timer(int time)
{
    while(time > 0)
    {
        cout << "\r";
        cout << "Countdown " << time << " seconds.";
        cout.flush();
        this_thread::sleep_for(chrono::seconds(1));
        time--;
    }
    //print_line();
    //cout << "\nGAME OVER!";
    //retry(&underwater_scene);
}

string remove_from_inventory()
{
    int index;
    string object;
    cout << "Use 1-" << inventory.size() - 1 << " for the object you wish to use.\n";
    cin >> index;
    if(index < inventory.size() && index >= 1)
    {
        object = inventory.at(index);
        saved_object = object;
        saved_index = index;
        inventory.erase(inventory.begin()+index);
        return object;
    }
    else
    {
        cout << "Number out of range, please try again.";
        remove_from_inventory();
        return ""; // Never actually executes
    }
}

void add_to_inventory()
{
    if(saved_index != 0 && saved_object != "")
    {
        inventory.insert(inventory.begin() + saved_index, saved_object);
    }
    saved_index = 0;
    saved_object = "";
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
    print_line();
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
                add_to_inventory();
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
            add_to_inventory();
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
            add_to_inventory();
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
    print_line();
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
        add_to_inventory();
        retry(&second_puzzle);
    }
    else
    {
        cout << "You jump from platform to platform, but to no avail. The platform disappears from underneath you, and you fall to your death.\n";
        cout << "\n\nEnding 25: Overzealous\n";
        print_line();
        add_to_inventory();
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
    print_line();
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
        add_to_inventory();
        retry(&third_puzzle);
    }
    else
    {
        cout << "You open the door and try to use the object, but to no avail. And in that moment, you realize your horrible mistake as a wave of jaws, teeth, and long sharp legs comes barreling towards you.\n";
        cout << "\n\nEnding 27: Splattered\n";
        print_line();
        add_to_inventory();
        retry(&third_puzzle);
    }
}

void fourth_puzzle()
{
    string object;
    print_line();
    cout << "After a short period of time you come across another unique chamber: a long, brightly lit corridor with a slotted door at the other end. The corridor is suspiciously clear of any obstacles.\n"
            "After a moment's hesitation, you start to take a step into the corridor before hearing a roar behind you. Quickly, you turn around to see that one of the centipede creatures has followed you.\n"
            "You freeze in place as it charges towards you, but you deftly roll to the side right before it collides with you. Instantly, the giant bug is cut into small chunks, they scatter about from the speed of the charge.\n"
            "Surprised, you roll back over and stand upright. You realize that there are obstacles down this corridor, but for some reason you can't see them right now. You look to the artifacts you still have:\n";
    print_line();
    show_inventory();
    print_line();
    cout << "What object would you like to use?\n";
    print_line();
    object = remove_from_inventory();
    cout << "You remove " << object << " from your inventory and use it.\n";

    if(object == the_oasis_key)
    {
        cout << "You hold the Shimmering Leaf up to your eye and look down the corridor. At first, you don't see anything, but then it comes into focus: there is what appears to be a laser grid of some kind directly ahead of you.\n"
                "Knowing the deadly potential this grid has, you look around the entire surface of it, looking for some kind of opening. And moments later, you find it. A large square opening in the grid of lasers,\n"
                "but it is at the top of the grid, touching the ceiling. You look around some more, and think about finding some kind of switch or button of sorts before immediately seeing a panel on the left side of the corridor just before the grid.\n"
                "Still looking through the leaf, you walk over to it and drop the leaf, only for the panel to disappear before your eyes. You bring the leaf back up and look through it to see the panel again.\n"
                "With one hand, you operate a simple two-dimensional knob, much like a touchscreen representation of one, and slowly turn it. In the corner of your eye, you notice the grid slowly rotate as you turn the knob.\n"
                "You rotate it until the square opening is directly in front of you and touching the ground with no lasers blocking your progress. Carefully, you step through the hole in the grid and proceed to the next obstacle.\n"
                "Several different obstacles, each with a unique mechanism lay at intervals through the length of the corridor. At each one, you must stop and solve a simple puzzle or use some kind of mechanism in order to orient\n"
                "lasers to make a safe passage through. At one point, you even had to orient a series of lasers into a two-dimensional pyramid shape in order to make a big enough gap to pass through.\n"
                "After numerous obstacles, you finally make your way through the corridor and reach the slotted door at the other end. Placing the Shimmering Leaf in the slot, the door slides down and you proceed through.\n";
        fifth_puzzle();
    }
    else if(object == the_glowing_cave_key)
    {
        cout << "Taking the Fossil out, you hold it in your hand and can feel your senses sharpen, but only a tiny bit. Still, it's better than you could hear before and you slowly step into the corridor.\n"
                "You reach the area where you saw the centipede get minced and slow your approach. With your better hearing, you can hear a low droning sound, similar to that of a flourescent bulb.\n"
                "Listening intently, you walk from side to side, listening for changes in the pattern of the drone. Suddenly, after approaching one side of the corridor, you hear a sudden break in the droning noise.\n"
                "You close your eyes and listen intently, lifting your foot and slamming it back down. The sound visualizes in the darkness of your closed eyes, but just barely. Still it's provided enough guidance for\n"
                "you to take a confident step forward. At first you don't feel anything, but then you reach up and see your arm fall away like freshly sliced deli meat. You scream and back away holding the stump of your arm\n"
                "with your other hand, before you realize that you can't actually step backward. You look down and see your leg slowly fall apart too, before the weight of your body pulls you forward.\n"
                "You land on the other side of the invisible barrier, steam coming off your precisely sliced chunks.\n";
        
        cout << "\n\nEnding 30: Diced\n";
        print_line();
        add_to_inventory();
        retry(&fourth_puzzle);
    }
    else
    {
        cout << "You take out the Black Heart and turn into the smallest creature you can think of: a small insectoid resembling an ant. You then hurriedly scurry forward, getting past the remains of the centipede creature and running full speed ahead.\n"
                "Confidence floods your tiny body and you run full speed ahead. Unfortunately, you don't get very far, as a small sizzle can be heard in the corridor as you are cut cleanly in half.\n";

        cout << "\n\nEnding 29: Split\n";
        print_line();
        add_to_inventory();
        retry(&fourth_puzzle);
    }
}

void fifth_puzzle()
{
    string object;
    print_line();
    cout << "You proceed down a long, winding corridor until you reach another door. This time, the door slides open without any input from you. You hesitantly proceed further in and find yourself\n"
            "in a strange dark chamber. There are no lights to be seen anywhere, you can't even make out your hands in front of your face. Suddenly, the door shuts behind you and you hear machinery power up,\n"
            "what sounds like giant ancient gears start to turn, metal scrapes against metal, and there is a definite whoosh in front of you at regular intervals since you can feel the change in the air.\n"
            "Seeing no other option, you stand where you are and search your person for the objects you still have.\n";
    print_line();
    show_inventory();
    print_line();
    cout << "What object would you like to use?\n";
    print_line();
    object = remove_from_inventory();
    cout << "You remove " << object << " from your inventory and use it.\n";

    if(object == the_glowing_cave_key)
    {
        cout << "Holding the Fossil, you immediately feel a significant increase in the sharpness of your senses, especially your hearing. Your ears are so sensitive in fact, that you can make out the details of the large structures\n"
                "moving in the cavernous chamber ahead of you. The chamber is remarkably lacking in terms of a solid floor to walk on, with the exception of the small platform you're currently standing on.\n"
                "It appears as the though the machinery is somehow suspended in the air, as if floating around in zero gravity, with some partially hidden in what appear to be energy bubbles of some kind, based purely on the low, strange sound they emit.\n"
                "Despite the oppressive dark, the large clunky machinery generates enough sound for you to effectively visualize your surroundings as if you were looking at it in broad daylight, thanks to the effects of the Fossil.\n"
                "At the same time, you feel your muscles flood with newfound strength and agility. Crouching low, you tense your legs and take a flying leap into the strangely suspended maze of machinery, deftly moving between areas as gears turn, pistons pound, and steam whistles blow.\n"
                "Soon, you find the slotted door floating amidst the chaos, with a series of intricately woven metal bars resembling filigree blocking access to it, like security bars. You jump up to it and find yourself standing straight up on the narrow platform the door is floating on,\n"
                "as if it possessed its own gravity. Looking to the lock, you notice several different designs on the filigree, designs you remember feeling engraved on particular areas of the suspended machinery. You turn back to the machinery and start to feel around on them, the sound of everything\n"
                "acting like a light for your enhanced senses. Soon, you discover the key to the locked gate: four different tubes needing to be filled with liquid. Moving among the machinery, you listen intently to several pipes filled with liquid and move among the intricate network of pipes\n"
                "opening valves and closing others to move the liquid into the tubes. After several minutes, you finally fill the tubes and pull a nearby chain, causing a whistle to go off and the intricate gate to open, revealing the slotted door.\n"
                "You jump back up to the floating platform and place the Fossil into the slot, causing the door to slide open, revealing the corridor beyond. Taking a deep breath, you step out of the dark void and into the lit doorway.\n";
        sixth_puzzle();
    }
    else
    {
        cout << "Bringing out the Black Heart, you turn into a creature that can see in the dark and make out a chaotic swarm of machinery parts floating in an zero gravity abyss. Stunned for only a moment, you jump high, coiling the pitch-black muscles in your mutated legs like springs.\n"
                "You reach a floating piece of machinery, listening to it hiss with steam and fluid as it flows through a complex network of interwoven pipes. As you jump from each floating piece of machinery to another, you slowly start to feel your sanity draining away, the strange environment\n"
                "and lack of an outlet for your aggression accelerating it. You try to keep your head on straight, but can't afford to stop using the Black Heart now, fearing that you'll be defenseless among the grinding gears and loud whistles. You keep jumping, hoping to find a way out but everything\n"
                "either looks completely alien or completely familiar and you feel yourself losing grip on your reality. As your desperation increases, you frantically search for the door but find nothing, realizing that you're lost among the machinery. Soon, the grinding gears and low whistles seem deafening\n"
                "as you grip the sides of your head and let loose a long, loud roar as you finally lose your sanity amid the uncaring, unstoppable floating machinery.\n";
        
        cout << "\n\nEnding 31: Stimulating Environment\n";
        print_line();
        add_to_inventory();
        retry(&fifth_puzzle);
    }

}

void sixth_puzzle()
{
    string text;
    // Final puzzle for The Black Heart: Fighting through a dimensional prison full of terrifying creatures in differing environments. 
    print_line();
    cout << "You walk for some time down the long corridor, longer than you had to for the other corridors. After some time, you come to a door resembling that to a large vault. It is then you notice a small slot in the door.\n"
            "At first, you think that there's no way it can hold the Black Heart, since it is so small, but then you realize something. It's not a slot for the Black Heart, but rather, the dagger you received at the start of this whole ordeal.\n"
            "Taking out the dagger from your belt, you look at it one final time, before sliding it into the slot. It fits snugly, the jewel embedded in the handle shining brightly. You then hear several loud thunks as the vault door unlocks.\n"
            "A hiss then escapes, like pressurized air before the vault door swings open before you. Inside, you see strange structures that are difficult to completely make out from your perspective. After a moment's hesitation, you step past the threshold.\n"
            "Taking a closer look without the frame of the vault door in the way, you can clearly see several strange orbs floating in the white void you find yourself in. Realizing the tendency for the Labyrinth to trick you, you quickly turn around,\n"
            "only to see that the vault door has now vanished, replaced by nothing but more white void. Frustrated but not surprised, you turn back to the orbs before you. In each, you can see a fisheye view of different environments, ranging from a forest\n"
            "to an underwaters ocean scene. You wander among the orbs, looking through each of them and trying to find a way out. After looking for a long time, you find no door. With little other choice, you look back to the orbs and decide to try the one\n"
            "with a forest scene inside. Stepping into the orb, you are immediately hit with a rush of air and the pull of gravity as you see the ground rush up to you. Quickly, you pull out the Black Heart and transform into a winged creature,\n"
            "catching the air and slowing your descent. Eventually, you settle back on the ground and look around. This forest is unlike any you've seen before in that it actually looks rather normal, but deserted. Tall, thin trees populate the landscape around you\n"
            "and the forest floor is littered with dry, dead leaves. You look around, expecting to see some kind of structure, but nothing is revealed. Thinking it would be better to get a bird's-eye view, you flap your wings and try to lift off,\n"
            "but are suddenly assailed by a hit to your side that sends you crashing into nearby tree, shattering it apart and leaving you laying amid the rubble. You feel your anger boil as you look up to see a strange stick-like figure, almost humanoid in its appearance\n"
            "were it not for its strange, misshapen head. The head of the thing had a saucer-like quality to it, with a large mouth splitting the head halfway along the circumference of the thing. It roars at you, spitting saliva as it did. Your anger boils as you change your\n"
            "form and charge at the thing. After a brief fight, you pull the thing's head off with your massive, mutated muscle and throw it far away from its body. Suddenly, you find yourself back in the white void with the orbs all around you again, the blood of the thing\n"
            "still on your hulking form. Quickly, you change back. You look around at the orbs again and notice that the one with the forest scene is now gone, and the faint outline of a door can just barely be made out at the other end of the void.\n"
            "You look back to the orbs around you, picking the underwater scene, and enter into it.\n";
    underwater_scene();
}

void underwater_scene()
{
    bool correct_solution = false;
    cout << "As you enter the orb, water rushes all around you and throws you off your guard. Utilizing the Black Heart, you change your form into an aquatic one, able to breathe underwater and move around effortlessly in the deep.\n"
            "";


    /*
        Idea for final puzzle: Implement a timer and a separate function that will output a random character and ask the user for input, if the input matches, the character gets in a hit.
        If the input does not match, the player suffers a hit. If the user gets in more hits than misses, the player successfully defeats the creature and proceeds to the next challenge.
        If not, the player gets a 'game over'.
    */
    thread time(timer, 10);
    time.detach();
}

void fight(string monster, int str_len, int difficulty)
{
    // str_len determines length of randomized string
    // difficulty determines types of characters found in string
    // monster is just the monster you fight
    cout << "You start a fight with the " << monster << ".\n";
    this_thread::sleep_for(chrono::seconds(10)); // Need to run in separate thread
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string randomString, attack;
    int chars;
    switch(difficulty)
    {
        case 1:
            chars = 26;
            break;
        case 2:
            chars = 52;
            break;
        case 3:
            chars = 62;
            break;
    }
    
    for(int i = 0; i < str_len; ++i)
    {
        int randomIndex = rand() % chars;
        randomString += characters[randomIndex];
    }

}

void input()
{
    string sentence;
    cout << "\n";
    cin >> sentence;
    cout << "You wrote: " << sentence;

    if(sentence == "This is a sentence.")
    {
        cout << "You won!";
    }
    else
    {
        cout << "You lost!";
    }
}