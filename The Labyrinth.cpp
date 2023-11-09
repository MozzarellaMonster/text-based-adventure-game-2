// File containing functions for The Labyrinth passage
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>
#include "Functions.hpp"
#include "Journal Entries.hpp"
#include "Trackers.hpp"
#include "Items.hpp"
#include "The_Glowing_Cave.hpp"
#include "The Labyrinth.hpp"

using namespace std;

void door_object(char option, string puzzle);

bool timer_done;
int saved_index = 0;

string saved_object = "";
string object;
string time_remaining;

string first_puzzle_death = "The door remains closed. Surprised, you reach for the object but the floor suddenly opens up beneath you.\n"
                            "You fall into the dark abyss and never stop falling. Down and down, impossibly deep.\n"
                            "You fall for what feels like forever. Until you suddenly meet the end.\n"
                            "\n\nEnding 22: Splat\n";

string door_1_riddle =        "\tLustrous and gleaming, fit for royalty\n"
                              "\tCarved into the face of Death, I grin for eternity\n"
                              "\tMy scarlet smile never wanes, yet amusement is not to blame\n"
                              "\tI stand for greatness, but possess no dexterity\n"
                              "\tI am the physical representation of a name\n";

string door_2_riddle =        "\tDealt with the swift hand of fate,\n"
                              "\tEminence slapped across the face,\n"
                              "\tAn object of prescience and relay,\n"
                              "\tThe path warned of bearing respect,\n"
                              "\tHave you, the object?\n";

string door_3_riddle =        "\tDwelling in darkness, a strange apparition,\n"
                              "\tEmitting a soft glow, resembling commotion,\n"
                              "\tAn object of unknown origin, granting extra locomotion,\n"
                              "\tThough, only applicable in the lack of light,\n"
                              "\tHave you, this petrified might?\n";

void timer(int time)
{
    while(time > 0)
    {
        this_thread::sleep_for(chrono::seconds(1));
        time_remaining = to_string(time) + " seconds remaining.\n";
        time--;
    }
    timer_done = true;
}

int fight(string monster, int str_len, int difficulty, int seconds)
{
    /*
        Function made for the final puzzle of the game
        str_len determines length of randomized string
        difficulty ranges from 1-3 and determines difficulty of characters found in string
        monster is just the name of the monster you fight
        seconds is the amount of time the timer counts down from
    */
    cout << "You start a fight with the " << monster << ".\n";
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string input;
    timer_done = false;
    int chars, points = 0;

    thread time(timer, seconds);
    time.detach();

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
        default:
            chars = 52;
    }
    
    while(timer_done == false)
    {
        string randomString = "";
        for(int i = 0; i < str_len; ++i)
        {
            randomString += characters[rand() % chars];
        }

        cout << "Points: " << points << "\n\n";
        cout << "Match the sentence to score a hit on the " << monster << "!\n";
        cout << "Sentence: " << randomString << "\n";

        cin >> input;

        if(input == randomString)
        {
            points++;
            cout << "\nCorrect! You scored a hit!\n";
        }
        else
        {
            points--;
            cout << "\nIncorrect! You suffer a hit from the " << monster << "!\n";
        }
        cout << time_remaining;
    }
    return points;
}

void remove_from_inventory(string puzzle, bool recursing=false)
{
    int index;

    print_line();
    if(recursing)
    {
        cout << "The puzzle is:\n\n";
        cout << puzzle << "\n\n";
    }
    show_inventory();
    print_line();

    cout << "Use 1-" << inventory.size() - 1 << " for the object you wish to use.\n";
    index = int(getch()) - '0'; // Accept user input as single character.

    if(index < 1 || index > inventory.size() - 1)
    {
        cout << "\nInput not a number or out of range, please try again.\n";
        remove_from_inventory(puzzle, true);
    }
    else
    {
        object = inventory.at(index);
        saved_object = object;
        saved_index = index;
        inventory.erase(inventory.begin()+index);
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
    interlude();
    clear_screen();
    cout << "Unlike the other portals, you don't seem to be forced through. Rather, you find the ingress to be much more pleasant.\n"
            "You look around you, at first it seems as though there is nothing but a long stone floor all around you polished to a mirror-like sheen.\n"
            "Then, the blocky outlines of edges form around you in a bright white light, like a solid wire mesh in a 3D animating program.\n"
            "Gradually, the meshes fill in with solid matter - more of the smooth, polished stone fills in the wire meshes, conforming to the shapes of them.\n"
            "And soon, massive walls materialize right before your eyes as you stand at the beginning of a giant maze. As the surfaces fill in around you,\n"
            "you finally take a step forward and truly take in your surroundings. Not only have walls sprung up on either side of you, but even the ceiling\n"
            "of the massive chamber has walls formed in the pattern of a maze. To your amazement, the chamber doesn't seem to have any hard edges,\n"
            "as you can see the floor slowly curve to meet the walls, and later, the ceiling. The sight dizzies you for a bit, and you lean against the wall nearby\n"
            "as you gather your senses. Eventually, you stand back upright and move forward. You've come this far already, nothing's going to stop you now.\n";
    first_puzzle();
}

void first_puzzle()
{
    interlude();
    clear_screen();
    cout << "You proceed further into the maze and eventually happen upon an unusual sight:\n"
            "A room with three doors in front of you, each one inscribed with a riddle and possessing a hole in the center of the door.\n"
            "You have the left door, the center door, and the right door.\n";
    
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Approach the left door\n";
    cout << "B. Approach the center door\n";
    cout << "C. Approach the right door\n";
    print_line();
    char choice = getch();
    cout << choice << "\n";
    choice = tolower(choice);

    print_line();
    switch(choice)
    {
        case 'a':
            cout << "You approach the left door and read the riddle:\n\n";
            cout << door_1_riddle;
            door_object(choice, door_1_riddle);
            break;
        
        case 'b':
            cout << "You approach the center door and read the riddle:\n\n";
            cout << door_2_riddle;
            door_object(choice, door_2_riddle);
            break;
        
        case 'c':
            cout << "You approach the right door and read the riddle:\n\n";
            cout << door_3_riddle;
            door_object(choice, door_3_riddle);
            break;
        
        default:
            try_again();
            first_puzzle();
    }
}

void door_object(char option, string puzzle)
{
    print_line();
    cout << "The hole in the center of the door has enough room for one of the objects in your inventory.\n";
    cout << "What object do you want to put in?\n";
    remove_from_inventory(puzzle);
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
                        "Instead, what you see causes all your confidence to dissipate. You find yourself back in the Hive, and standing in front of you is the Ant Queen, the Amber Eye clutched in her right hand.\n"
                        "Her eyes, although multifaceted and lacking any real form of facial expression, seethe with an unbridled malice.\n"
                        "You quickly reach for the dagger and bring it out, but the Ant Queen is quicker, grabbing the dagger out of your hand and tossing it away.\n"
                        "With her other arm, she grabs you by the throat and lifts you into the air. You grasp for breath and futilely claw at the hardened chitin of her clawed fingers.\n"
                        "\"YOU!\" you hear her scream in your head, the force of which combined with the lack of oxygen causing a massive pain in your skull.\n"
                        "\"YOU DARE TO DISRESPECT ME? YOU COME INTO MY DOMAIN, STEAL MY TREASURE, AND DARE TO STRIKE ME?!\" she telepathically roars, throwing you down.\n"
                        "You hit the ground hard, bouncing once before laying still and taking in a shuddering breath. You try to lift yourself up, but are forced back down when the Queen\n"
                        "places one of her feet onto your back, forcing your face into the dirt. She grabs your head by the hair and twists it to the side to look at her straight on as she leans down to your level.\n"
                        "\"Remember what I told you would happen if you bring harm to any of my subjects?\" she thought-speaks, her \'voice\' dripping with barely-restrained hatred.\n"
                        "Your eyes widen as you remember her warning: \"Your bones will line my walls\" and an involuntary whimper escapes your mouth.\n"
                        "Her eyes shine with malicious glee when she realizes you do in fact, remember.\n"
                        "\"Good,\" she says, \"As Queen of the Hive, I make sure to keep my promises. It just wouldn't do if I wasn't a good role model for my subjects, now would it?\"\n"
                        "She clamps down hard on your skull, her claws drawing blood that seeps into your eyes as she lifts you up by your head.\n"
                        "You desperately try to pull against her vice-like grip with your hands as you scream in pain, but she only tightens her grip.\n"
                        "She raises you up to her face and stares directly into your eyes one final time.\n"
                        "\"Goodbye, traveler. I'll make sure to decorate my chamber with whatever's still intact,\" she says before she swiftly and violently slams you into the hard, compacted dirt of her chamber.\n"
                        "Your neck and several bones all across your body violently snap upon impact as the last thing you feel is unimaginable pain before the life leaves your eyes.\n";

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
                        "You look around you and notice the familiar land bridge with the roaring waterfall falling into the canyon below, somehow darker than you remember.\n"
                        "You tense slightly, turning around to notice that the tunnel leading back to the main chamber is now closed off by several large boulders that appear to have fallen from above.\n"
                        "You slowly turn back around to see that same light on the other side of the bridge, slowly swinging back and forth, almost hypnotically.\n"
                        "You notice a thin ledge to the left of the bridge trailing off into the darkness, hugging the wall of the large cave, something you didn't notice before and decide that,\n"
                        "with the only known exit closed off, that is the only option left. You slowly make your way towards it, taking carefully measured steps, keeping your eyes on the path ahead.\n"
                        "As you tentatively make your way through the darkness, you regret putting The Fossil into the door, wishing it was here now to help you, or that there was at least more light to see by.\n"
                        "You continue on your way, the path coming more into focus, seemingly lit by some unknown source. It is then that you realize the waterfall is no longer splashing onto the bridge.\n"
                        "The hairs on the back of your neck stand straight up as you finally hear it - deep breathing that you had mistaken as wind traveling through the chamber earlier.\n"
                        "The terrifyingly familiar orange glow dances above you now, making your shadow lean from side to side, almost as if in an terror-stricken dance.\n"
                        "A hot, humid breath suddenly caresses the stiff hairs along your neck and you shut your eyes as you brace yourself for what you're about to see.\n"
                        "You slowly turn around and open your eyes, immediately regretting it. You stare hopelessly into two huge opal globes of a reptillian monstrosity.\n"
                        "Its huge mouth hangs open, breathing hot, sticky fire your way. Its tongue licks the air, taking in your scent. You hold back as long as you can, but your fear eventually wins.\n"
                        "You scream, long and loud. And throughout that long chamber, the sound of massive jaws snapping closed echoes throughout.\n";

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
    interlude();
    clear_screen();
    print_line();
    cout << "After walking for several minutes, you now find yourself in another peculiar location. Before you lays a corridor with a sudden drop off ahead, descending into pitch black darkness.\n"
            "Inching closer, you look over the edge and suddenly the sound of whirring machinery starts as platforms materialize out of thin air before disappearing a second later.\n"
            "You watch for a bit but can discern no pattern to their appearances, with it being seemingly randomized. Not only that, but the platforms appear and disappear in random directions,\n"
            "with some appearing in a position that draws you closer to the other side and some that go away from or in another direction entirely.\n"
            "Try as you might, you cannot grasp any possible pattern to them, only noticing that they appear within jumping distance of each other,\n"
            "but the timing of the appearances is so precise that they would only appear when you had already jumped. You watch for a bit longer and can confirm that you would have to already\n"
            "be in the air when another platform appears. With this in mind, you look over the items you have.\n";
    cout << "What object would you like to use?\n";
    remove_from_inventory("A large gap that can only be crossed with manifesting platforms that require precise timing, practically needing some form of precognition.\n");
    print_line();
    cout << "You select " << object << " from your inventory and use it.\n";
    print_line();
    
    if(object == the_heart_of_the_colony_key)
    {
        cout << "Holding out the Amber Eye, you are suddenly assailed by a stream of images flooding your mind. Scenes from your journey up until this point,\n"
                "scenes of what would have happened if you had answered wrong on the previous puzzle, and finally, scenes of you attempting the puzzle you are now faced with.\n"
                "In a split second, you watch yourself die a thousand times over, some with other objects, some with the Amber Eye itself. You focus, mentally sorting through the images\n"
                "until you come across some that offer actual solutions to the puzzle. Closing your eyes, you envision yourself leaping from one ephemeral platform to another,\n"
                "paying special attention to when the platforms appear. And soon, you body freezes up, but then floods with adrenaline as you suddenly charge forward and take a flying leap from the edge of the pit.\n"
                "You land on a floating platform that wasn't there a mere fraction of a second earlier. Quickly, you get back up and jump in another seemingly random direction,\n"
                "the images from the Amber Eye flasing through your mind. Instantly, another platform appears, barely saving you from falling to your death. You keep this up,\n"
                "jumping from one location to another until you're close enough to the other side to make one final jump to safety. You jump to the other ledge, your momentum causing you to roll.\n"
                "For a moment, you just lay there, staring upward as you catch your breath. Your legs burn from all the jumping and for a moment, you feel as though you can't get back up.\n"
                "After a long pause however, you do. You make your way to the other side of the chamber where a door with a slot in it stands. Placing the Amber Eye in the slot, the door opens up and you proceed forward.\n";
        third_puzzle();
    }
    else if(object == the_glowing_cave_key)
    {
        cout << "Holding the Fossil in your hand, you feel your body flood with a sense of power as your senses heighten and your body feels lighter, though not as much compared to the cave you found it in.\n"
                "With a renewed vigor, you jump into the pit safely onto a materialized platform. With your heightened hearing and echolocation, you can just make out when and where the platforms might appear. You continue jumping,\n"
                "slowly making your way to the other side. Then, when you're just one platform away from the other side, you misjudge a jump, missing the platform by mere inches. As you fall into the dark pit, you feel the\n"
                "effects of the Fossil intensify, but it's all no use now, as the ground rushes up to meet you.\n";

        cout << "\n\nEnding 26: Dead Weight\n";
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
    interlude();
    clear_screen();
    print_line();
    cout << "After a brief period of time you come across a closed door. However, this door is different from the ones you've seen thus far. It resembles more of a blast door\n"
            "with thick windows than the usual stone doors with slots in them. Next to the door is a small screen. Ignoring the screen for now, you peer through the windows of the blast door.\n"
            "Inside, you see a chamber: one full of huge centipede-like creatures, all crawling over each other and occasionally fighting. You stare for a moment in disbelief\n"
            "at the size of the creatures, before lurching back when one of them takes notice of you and attempts to break the thick glass of the blast door before giving up and returning to\n"
            "crawling over the others. From a small break in the creatures' writhing masses, you spy another blast door and just beyond that, the usual slotted door.\n"
            "It is then you notice a raised platform to the right of the other blast door. You can't see much from here, so you turn to the screen next to you. The small screen resembles what looks like a camera feed,\n"
            "showing the interior of the chamber from a different angle that shows the surface of the raised platform. On the top of the raised platform, you see a glowing raised tile.\n"
            "As a few of the creatures walk over the tile, you see it ever-so-slightly give, before popping back up when all of them leave. You look around you and spy a button on the left side of the chamber door,\n"
            "inferring its purpose to be to open the door. You look back to the swarming mass of insectoids inside before looking through your options.\n";

    cout << "What object would you like to use?\n";
    remove_from_inventory("A room full of dangerous insectoid monsters that you'll need to pass through safely. A pressure plate is hidden on a raised platform in a corner of the room.\n");
    print_line();
    cout << "You select " << object << " from your inventory and use it.\n";

    if(object == the_whistling_gorge_key)
    {
        cout << "Holding Twisted Bone to your mouth, you quickly hit the button next to the door and blow into the flute. Immediately, the centipede-like creatures freeze, stunned by the inaudible sound of the flute.\n"
                "Slowly, you force them to clear a path for you to the other blast door. They stand by, close enough for you to see the unbridled anger and hatred in their eyes, despite their otherwise calm-looking exterior.\n"
                "Still playing the flute, you finally reach the blast door, only to find that there is no button nearby. You frantically search for it, your eyes looking around wildly as your mouth starts to grow tired.\n"
                "Then you remember the raised platform next to you with the raised tile on it. You look to it and immediately, nearby creatures start to climb up to the platform and sit on the tile, gently depressing it.\n"
                "After several of them fully depress the tile, the blast door finally opens. Your mouth is hurting now, and as you quickly step past the door you pull Twisted Bone away from your mouth and take a gasp of air.\n"
                "Instantly, the creatures break out of their trance and rush towards you, but the blast door quickly shuts again as the tile raises once again.\n"
                "Holding your chest, you feel your heart beat rapidly before slowly calm back down as you look to the other door ahead of you - a familiar one with a slot for Twisted Bone in it.\n"
                "Placing the flute in the slot of the door, it opens and you head through it.\n";
        fourth_puzzle();
    }
    else if(object == the_swamplands_key)
    {
        cout << "Gripping the Black Heart in your hand, you will your body to change form, taking on a more aggressive shape. The shape of a predator.\n"
                "As your muscles ripple under your pitch-black skin, your teeth grow long and pointed and your nails grow into long sharp claws.\n"
                "Feeling invincible, you smash the button and open the blast door. Immediately, you are assaulted by several of the huge creatures, all gnashing jaws and teeth, their multi-segmented bodies\n"
                "lined with several long, sharp legs wrap around you, piercing into your body. They swarm over you, but you fight back, tearing their bodies apart with your newly grown teeth and\n"
                "slamming their comparatively fragile bodies into the hard ground, splattering them all over. Bloodlust fills you as you charge into them, ripping them to pieces with your claws and teeth,\n"
                "smashing the rest with your massive hands and feet. You fight and fight and fight, but they continue to swarm over you, relentless and unforgiving. Merciless, they slowly beat you back as your\n"
                "strength and energy wanes, unable to maintain your balance as you try to keep up the slaughter. Only when the room is nearly empty and you're so tired you can barely stand do you realize the other\n"
                "blast door is still shut tight. You lean over, exhausted, as several new tentacles sprout from your back and slice and stab any creatures that dare to approach you. Soon, the room stands empty all\n"
                "around you... but the door remains shut. You fall to your knees and feel your mind on the verge of breaking, as the muscles in your body burn with the promise of pain and the Heart whispers to you\n"
                "sweet dreams of carnage and carrion. As you look up to ceiling of the room, you notice several hatches open as more of the creatures are poured back in, several thousand at a time.\n"
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
        cout << "\n\nEnding 27: Mangled\n";
        print_line();
        add_to_inventory();
        retry(&third_puzzle);
    }
}

void fourth_puzzle()
{
    interlude();
    clear_screen();
    print_line();
    cout << "After a short period of time you come across another unique chamber: a long, brightly lit corridor with a slotted door at the other end. The corridor is suspiciously clear of any obstacles.\n"
            "After a moment's hesitation, you start to take a step into the corridor before hearing a roar behind you. Quickly, you turn around to see that one of the centipede creatures has followed you.\n"
            "You freeze in place as it charges towards you, but you deftly roll to the side right before it collides with you. The giant insectoid soars past you and is immediately cut into small chunks,\n"
            "of which fly further forward, propelled by the speed of the charge. Surprised, you roll back over and stand upright. You realize that there ARE obstacles down this corridor,\n"
            "but for some reason you can't see them. You look to the artifacts you still have.\n";
    cout << "What object would you like to use?\n";
    remove_from_inventory("A brightly-lit hallway with some form of invisible laser grid. A door awaits you at the other end.\n");
    print_line();
    cout << "You remove " << object << " from your inventory and use it.\n";

    if(object == the_oasis_key)
    {
        cout << "You hold the Shimmering Leaf up to your eye and look down the corridor. At first, you don't see anything, but then it comes into focus: there appears to be a laser grid of some kind directly ahead of you.\n"
                "Knowing the deadly potential this grid has, you look over the entirety of it, looking for some kind of opening. And moments later, you find it. A large square opening in the grid of lasers,\n"
                "but it is at the top of the grid, touching the ceiling. You look around some more, and think about finding some kind of switch or button of sorts before immediately seeing a panel on the left side of the corridor just before the grid.\n"
                "Still looking through the leaf, you walk over to it and drop the leaf, only for the panel to vanish before your eyes. You bring the leaf back up and look through it to see the panel again.\n"
                "With one hand, you operate a simple two-dimensional knob, much like a touchscreen representation of one, and slowly turn it. In the corner of your eye, you notice the grid slowly rotate as you turn the knob.\n"
                "You rotate it until the square opening is directly in front of you and touching the ground with no lasers blocking your progress. Carefully, you step through the hole in the grid and proceed to the next obstacle.\n"
                "Several different obstacles, each with a unique mechanism lay at intervals throughout the length of the corridor. At each one, you must stop and solve a simple puzzle or use some kind of mechanism in order to orient\n"
                "lasers to make a safe passage through. At one point, you even had to orient a series of lasers into a two-dimensional pyramid shape in order to make a big enough gap to pass through.\n"
                "After numerous obstacles, you finally make your way through the corridor and reach the slotted door at the other end. Placing the Shimmering Leaf in the slot, the door slides down and you proceed through.\n";
        fifth_puzzle();
    }
    else if(object == the_glowing_cave_key)
    {
        cout << "Taking the Fossil out, you hold it in your hand and can feel your senses sharpen, but only a tiny bit. Still, it's better than you could hear before and you slowly step into the corridor.\n"
                "You reach the area where you saw the centipede get minced and slow your approach. With your better hearing, you can hear a low droning sound, similar to that of a flourescent bulb.\n"
                "Listening intently, you walk from side to side, listening for changes in the pattern of the drone. Suddenly, after approaching one side of the corridor, you hear a sudden break in the droning noise.\n"
                "You close your eyes and listen intently, lifting your foot and slamming it back down. The sound visualizes in the darkness of your closed eyes, but just barely. Still it provides enough guidance for\n"
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
        cout << "You take out the Black Heart and turn into the smallest creature you can think of: a small insectoid resembling an ant. You then hurriedly scurry forward,\n"
                "getting past the steaming remains of the centipede creature and running full speed ahead. Confidence fills your tiny body and you run.\n"
                "Unfortunately, you don't get very far, as a small sizzle can be heard in the corridor as you are cut cleanly in half.\n";

        cout << "\n\nEnding 29: Split\n";
        print_line();
        add_to_inventory();
        retry(&fourth_puzzle);
    }
}

void fifth_puzzle()
{
    interlude();
    clear_screen();
    print_line();
    cout << "You proceed down a long, winding corridor until you reach another door. This time, the door slides open without any input from you. You hesitantly proceed and find yourself in a strange dark chamber.\n"
            "There are no lights to be seen anywhere, you can't even make out your hands in front of your face. Suddenly, the door shuts behind you and you hear machinery power up.\n"
            "What sounds like giant ancient gears start to turn, metal scrapes against metal, and there is a definite whoosh in front of you at regular intervals, like a giant swinging pendulum.\n"
            "Seeing no other option, you stand where you are and search your person for the objects you still have.\n";
    cout << "What object would you like to use?\n";
    remove_from_inventory("A dark chamber with the sound of machinery in front of you.\n");
    print_line();
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
    interlude();
    clear_screen();
    print_line();
    cout << "You walk for some time down the long corridor, longer than you had to for the other corridors. After some time, you come to a door resembling that to a large vault. It is then you notice a small slot in the door.\n"
            "At first, you think that there's no way it can hold the Black Heart, since it is so small, but then you realize something. It's not a slot for the Black Heart, but rather, the dagger you received at the start of this whole ordeal.\n"
            "Taking out the dagger from your belt, you look at it one final time, before sliding it into the slot. It fits snugly, the jewel embedded in the handle shining brightly. You then hear several loud thunks as the vault door unlocks.\n"
            "A hiss then escapes, like pressurized air before the vault door swings open before you. Inside, you see strange structures that are difficult to completely make out from your perspective. After a moment's hesitation, you step past the threshold.\n"
            "Taking a closer look without the frame of the vault door in the way, you can clearly see several strange orbs floating in the white void you find yourself in. Realizing the tendency for the Labyrinth to trick you, you quickly turn around,\n"
            "only to see that the vault door has now vanished, replaced by nothing but more white void. Frustrated but not surprised, you turn back to the orbs before you. In each, you can see a fisheye view of different environments, ranging from a forest\n"
            "to an underwater ocean scene. You wander among the orbs, looking through each of them and trying to find a way out. After looking for a long time, you find no door. With little other choice, you look back to the orbs and decide to try the one\n"
            "with a forest scene inside. Stepping into the orb, you are immediately hit with a rush of air and the pull of gravity as you see the ground rush up to you. Quickly, you pull out the Black Heart and transform into a winged creature,\n"
            "catching the air and slowing your descent. Eventually, you settle back on the ground and look around. This forest actually looks rather normal, but deserted. Tall, thin trees populate the landscape around you and the forest floor is littered with dry, dead leaves.\n"
            "You look around, expecting to see some kind of structure, but nothing is revealed. Thinking it would be better to get a bird's-eye view, you flap your wings and try to lift off,\n"
            "but are suddenly knocked away by a hit to your side that sends you crashing into a nearby tree, splintering it apart and leaving you laying amid the rubble. You feel your anger boil as you look up to see a strange stick-like figure, almost humanoid in its appearance\n"
            "were it not for its strange, misshapen head. The head of the thing had a saucer-like quality to it, with a large mouth splitting the head halfway along the circumference of the thing. It roars at you, spitting saliva as it did. Your anger boils as you change your\n"
            "form and charge at the thing. After a brief fight, you pull the thing's head off with your massive, mutated muscle and throw it far away from its body. Suddenly, you find yourself back in the white void with the orbs all around you again, the blood of the thing\n"
            "still on your hulking form. Quickly, you change back. You look around at the orbs again and notice that the one with the forest scene is now gone, and the faint outline of a door can just barely be made out at the other end of the void.\n"
            "You look back to the orbs around you, picking the underwater scene, and enter into it.\n";
    underwater_scene();
}

void underwater_scene()
{
    interlude();
    clear_screen();
    print_line();
    cout << "As you enter the orb, water rushes all around you and throws you off your guard. Utilizing the Black Heart, you change your form into an aquatic one, able to breathe underwater and move around effortlessly in the deep.\n"
            "Regaining your vertical orientation, you look all around you. A deep blue abyss expands in all directions around you, but directly below you lies a dark chasm - a huge dark canyon filled with the blackest black imaginable.\n"
            "Staring into the void, you suddenly hear an immense roar as deep, visceral dread floods your body. Immense tentacles erupt from the chasm as several glowing yellow-green eyes appear deep within the chasm, staring at you with a deep hunger.\n"
            "Immediately, you bolt for the surface, but are grabbed by a tentacle around your leg. Pain erupts in the area as a hook comes out of the tentacle and plunges deep into your leg. Anger overwhelms your fear as it surges through your veins.\n"
            "Turning back to the tentacles, you slash at them with your newly-formed claws and black blood spills from the gaping wounds in them. Immediately, the tentacle releases you, but you dive deeper and begin to slash at more of them.\n"
            "After seeing your charge, the creature in the chasm releases more tentacles from the darkness, hooks fully deployed as they shoot straight for you.\n\n";

    interlude();
    cout << "The fight is on! Score at least five hits to win! 30 seconds to get in as much damage as possible!\n";
    int fight_results = fight("tentacle monster", 5, 1, 30);

    print_line();
    if(fight_results >= 5)
    {
        cout << "Your fight against the monster results in your victory!\n"
                "As the water around you grows murky with a mixture of both yours and the creature's blood, you suddenly feel a violent force sucking at your worn and wounded body as your mind suddenly goes blank.\n"
                "When you come to, you find yourself back at the white void filled with orbs, the ocean orb nowhere to be seen. You take a moment to sit and heal as your wounds close with the help of the Black Heart.\n"
                "Becoming aware of exactly how much time you've spent using it already, you stop using it and rest for a while. Finally rested, you stand back up and approach another orb - this one looking oddly clustered with what appears\n"
                "to be fine white strands of... silk?\n"
                "Refusing to be swayed, not after you've come this far, you approach and touch the orb, getting sucked right into it.\n\n";
        web_scene();
    }
    else if(fight_results < 0)
    {
        cout << "You get pulled down into the depths of the chasm, as the tentacles pull you down. You stare upward towards the dazzling display of light on the surface of the water.\n"
                "You think how beautiful it looks before the creature's jaws close around you.\n";
        
        cout << "\n\nEnding 31: Claimed By The Chasm\n";
        print_line();
        retry(&underwater_scene);
    }
    else
    {
        cout << "Succumbing to your wounds, you slowly fall into the chasm, the water murky from the blood spilled during the fight. A solemn, low growl emanates from below you as the monster also slowly perishes.\n"
                "As the darkness encroaches on the edges of your vision, you stare up towards the dazzling light penetrating the surface of the water and finally let the cold embrace of death take you.\n\n";

        cout << "\n\nEnding 32: The Depths\n";
        print_line();
        retry(&underwater_scene);
    }
}

void web_scene()
{
    interlude();
    clear_screen();
    print_line();
    cout << "You come to in a dark place, surrounded by long, sticky strands of silk. Trying to get up, you find that the webs all around you keep you stuck in place. Tossing and turning, you only manage to get yourself even more tangled.\n"
            "After struggling for a while, you notice that one particular strong strand of silk is vibrating rapidly with your movements. A signal. It is then you notice several strands of silk starting to vibrate, rapidly increasing in motion\n"
            "as something approaches. Something big. As you feel that familiar feeling of fear start to take hold, you quickly bring out the Black Heart and morph into an arachnid-like being capable of resisting the sticky entrapment of the webs.\n"
            "As your body changes, you shrug off the strands previously entangling you as your body sprouts thick, prickly hairs and your face erupts with several large eyes. Just as you finish changing, a large exotic arachnid with several\n"
            "brightly-colored jagged streaks covering its body bursts onto your section of the web and hisses angrily.\n"
            "\t\"You are intruding on my domain, trespasser. Leave now or perish.\" you hear in your head.\n"
            "Your anger flares and your aggression increases tenfold as the Black Heart finishes its work and you charge at the arachnid, lusting for blood. The arachnid hisses angrily and charges in turn.\n\n";
    
    interlude();
    cout << "The fight is on! Score at least five hits to win! 45 seconds to get in as much damage as possible!\n";
    int fight_results = fight("arachnid", 10, 2, 45);

    print_line();
    if(fight_results >= 5)
    {
        cout << "Missing some limbs and covered in blood and stray strands of silk, you emerge from the tangled mass of silk and broken exoskeleton triumphant. Quickly, you feel your mind slipping and you hastily stop using the Black Heart.\n"
                "Drawing in a sharp breath, your body twists and contorts, making horrible cracking and splintering sounds as you shed your exoskeleton in favor of your familiar epidermis. As your bones return to their original shape and your\n"
                "wounds rapidly close, you are suddenly flung into nothingness before re-emerging back into the white void, now populated with much less floating orbs.\n"
                "You sit back a while and slowly regain your composure, stilling your mind and weaving your sanity back into place. You're not sure how much more of this your mind or body can take. Continuously using the Black Heart like this is\n"
                "straining your fragile grasp on reality. Taking several deep breaths, you calm back down until you finally stand back up, ready to take on the next challenge.\n";
        shaft_scene();
    }
    else if(fight_results < 0)
    {
        cout << "You lay on the web, what little limbs you have left entangled in more of the arachnid's webs. Blood drips from the gaping holes in your exoskeleton where your limbs used to connect.\n"
                "Blinking away the goo dripping from several of your ruptured eyes, you stare daggers at the arachnid as it moves in closer for the kill.\n"
                "\t\"You put up a decent fight trespasser, but you're in MY domain.\" it says snidely.\n"
                "Moving over you, it bares its huge fangs and quickly plunges them into your head. You feel the venom pump into your body as your vision blurs and the final threads of your life finally snap.\n";
        
        cout << "\n\nEnding 33: Slain in Silk\n";
        print_line();
        retry(&web_scene);
    }
    else
    {
        cout << "You lay there, completely broken. Blood and goo drips from several wounds all over your arachnid-like body. You feel your life slipping away. With your final reserves of strength, you look towards the alien arachnid and see that it too, is dying.\n"
                "It lays amidst its webs, missing several limbs and quietly nursing a gaping hole in its abdomen. You slowly turn back to look in a direction you believe may be upward, though you can't tell as your senses slip away\n"
                "and the world spins out of control around you. You laugh quietly to yourself, before erupting into a painful choking fit. As you coughs get weaker and weaker, your multitude of eyes glaze over and you perish within the confines of the silken prison.\n";
        
        cout << "\n\nEnding 34: The Silken Tomb\n";
        print_line();
        retry(&web_scene);
    }
}

void shaft_scene()
{
    interlude();
    clear_screen();
    print_line();
    cout << "You find yourself falling, falling deep into a dark hole before you see the ground approaching fast. Quickly, you use the Black Heart to sprout wings that catch the air and slow your descent before growing claws and grabbing onto the hard rock wall nearby.\n"
            "Slowing to a stop, you jump the last few feet to the ground and look up. Above you, you see a hole in the ceiling of a tall circular shaft where you can see the stars above. All along the length of the shaft, you see clusters of diamonds sprouting from the walls.\n"
            "Of which, several catch the starlight just right to sparkle brilliantly in the dim light. Momentarily distracted by the sudden natural beauty, you feel your body start to change back into its human form. Your short reverie is interrupted by a sudden loud growl emanating from a cave\n"
            "connected at the base of the shaft. Turning towards it, you see two large yellow eyes glowing in the darkness of the cave. Feeling your aggression and anger start to bubble, you increase your muscle mass and overall size as much as possible before roaring at it.\n"
            "The eyes narrow in contempt before closing completely, leaving the entire opening in darkness. A little confused, you take a step towards the cave before you see the eyes snap back open, smoke come out of the opening of the cave, and a loud roar emanates from it.\n"
            "Taking a step back, you see a huge clawed hand grip the side of the cave and a massive dragon climb out of it. Your eyes widen as you take in the hulking form of the huge dragon, and despite the effects of the Black Heart, you feel fear seep into your body.\n"
            "The dragon roars and opens its huge jaws, smoke seeping out of it as a fiery glow forms in its throat. Thinking quickly, you climb up the side of the shaft and use your massive arms to launch yourself towards the open top, taking to the air with your wings.\n"
            "For a moment, you smile smugly before looking behind you and seeing that the dragon has now given chase with its own pair of wings. Turning back to the hole, you flap your wings harder and fly out of the volcanic shaft, the dragon now chasing you through the night sky.\n"
            "Making a wide arc, you fly away as you feel the heat of the fire the dragon shoots in your direction. You realize that the dragon will not stop, and your anger flares again as you turn back around and face it.\n\n";

    interlude();
    cout << "The fight is on! Score at least five hits to win! 60 seconds to get in as much damage as possible!\n";
    int fight_results = fight("dragon", 15, 3, 60);

    print_line();
    if(fight_results >= 5)
    {
        // Alternative text - dragon is wounded
        cout << "Wounded, the dragon circles back around and dives toward the volcanic shaft. Quickly you follow, eager to finish the fight. You follow it down the volcanic shaft and suddenly get slammed against the wall, feeling a cluster of diamonds pierce your side.\n"
                "You let out a pained roar and claw at the dragon's face. It lets you go, a look of smug triumph on its face. It may be injured, but it is not done fighting you either. Now bloodlusted, you dive back in again as it prepares another blast of fire for you.\n";
    }
    else if(fight_results < 5 && fight_results > 0)
    {
        // Tie - Ending
        cout << "You fall, and to your side, you see the dragon falling some distance away from you. Both of you have succumbed to your wounds. In your final moments, you look back to night sky, stars twinkling in the distance.\n"
                "You smile to yourself, appreciating the beautiful sight before your body slams into the ground.\n";

        cout << "\n\nEnding 35: Fallen\n";
        print_line();
        retry(&shaft_scene);

    }
    else
    {
        // Alternative text - you are wounded
        cout << "Wounded, you return to the volcanic shaft, all the while being chased by the dragon. Thinking quickly, you turn around and spread your wings to catch the air, passing by the dragon as it turns back to look at you in surprise.\n"
                "Immediately, you take this opportunity to slash at the dragon's face and push it against the wall of the shaft will all your might. It slams against the wall, a large piece of clustered diamonds piercing its thick hide.\n"
                "It lets out a pained roar as you dive back in and continue the fight.\n";
    }

    print_line();
    interlude();
    cout << "The fight is still on! Score at least five hits to win! 60 seconds to get in as much damage as possible!\n";
    fight_results = fight("dragon", 20, 3, 60);

    print_line();
    if(fight_results >= 5)
    {
        // Victory - call to final ending
        cout << "With a final cry of victory, you slam the dragon into the ground of the volcanic shaft. It groans in defeat, succumbing to the strength of your blow. But your rage boils on and you slam your enlarged fists into its body over and over,\n"
                "pounding it harder and harder into the ground. Soon, a crack forms in the hard rock of the shaft's floor. Seeing this, you redouble your efforts, the dragon now whimpering with pain. Raising both of your fists high, you slam them down\n"
                "together with enough force to break open the shaft floor. Immediately, the ground gives and the dragon falls several feet down into a pool of lava. It writhes in the molten rock for a moment before its movements slow and it sinks below the surface.\n"
                "You watch for a few moments, but the pool of lava remains still. Suddenly, you feel the familiar pulling sensation as you are yanked from this reality and flung back into the white void.\n";
        the_end();
    }
    else if(fight_results < 5 && fight_results > 0)
    {
        // Tie - Ending
        cout << "You lay in the center of the base of the volcanic shaft, exhausted and bleeding profusely. Across the shaft, the dragon snorts defeatedly and falls to the ground. You watch as its chest rises and falls repeatedly, slowly at first,\n"
                "until it stops entirely. Slowly, you roll over onto your back and stare at the open circle of sky at the top of the shaft, distantly aware that you've lost way too much blood as your body slowly returns to its human form.\n"
                "Dreamily, you stare at the small piece of sky high above you as you close your eyes. A small smile creeps onto your face as you breathe your last breath and feel the cold embrace of death.\n";

        cout << "\n\nEnding 36: Starry Skies\n";
        print_line();
        retry(&shaft_scene);
    }
    else
    {
        // Defeat
        cout << "The dragon slams your beaten and broken body hard into the floor of the volcanic shaft. You hear several horrible snaps as multiple bones break all across your body. The Black Heart tries desperately to hold you together, but to no avail.\n"
                "You are far too broken for it to be of any help. Sensing its victory, the dragon picks you up with its sharp claws and holds you up to its eye, looking you over with pure contempt in its gaze.\n"
                "\t\"You are pathetic and weak, far too pitiful to even consider eating.\"\n"
                "Taken aback, you open your mouth to roar in reply, but are met with a nasty surprise as the dragon breathes fire down your throat and upon your defeated form, burning you up until you are nothing but ash.\n";

        cout << "\n\nEnding 37: Roasted\n";
        print_line();
        retry(&shaft_scene);
    }
}

void the_end()
{
    interlude();
    clear_screen();
    print_line();
    cout << "Stumbling from reentry into the white void, you grab ahold of something solid. Leaning against it, you catch your breath as your muscles scream for rest and your legs barely hold you up.\n"
            "It is not over however, as you realize that you're leaning against a door. Standing back up, you back up a bit to see the door in full view. It is intricately carved,\n"
            "looking to be made of some kind of white petrified wood. The carvings resemble vines, but each 'leaf' is a Gate. A slot opens in the center of the door, revealing a small platform.\n"
            "Reaching into your pocket, you take out the Black Heart and place it on the platform. The slot slowly closes and some grinding sounds can be heard, like ancient gears coming to life after centuries of neglect.\n"
            "Slowly, the door slides open. You can't see anything beyond the threshold as a bright white light shines from beyond. Shielding your eyes, you walk through the doorway.\n\n";
    print_line();
    cout << "\nYou find yourself outside the Temple, your wounds healed and your body back in pristine condition. You look back behind you to see that the entrance to the temple is now gone, replaced with a smooth stone wall.\n"
            "Suddenly, the temple begins to descend into the ground, the layers of the temple collapsing into a smooth, flat black stone surface. Suddenly, an object in your pocket vibrates.\n"
            "Taking it out, you see that it is the USB drive that you found in The Glowing Cave. You see a small red light fading in and out. Walking around, you notice the red light fade in and out in shorter and shorter intervals.\n"
            "Following the vibration and light, you find yourself at the base of a nearby tree. Kneeling down to dig, you find a small metal box. Opening it, you find a camcorder within.\n"
            "Plugging in the USB drive, you find only one recording on it. Selecting it, the video begins to play.\n\n";
    cout << video_log;
    cout << "\nTurning the camera off, you look back into the box and see the vial full of the faintly luminescent crimson liquid similar to the one in the video. You take it out of the box and pocket it.\n"
            "Standing back up, you hear a strange grinding sound as an archway rises out of the flat black surface of the flattened temple. That familiar liquid shimmer manifests within the archway as you walk towards it.\n"
            "Standing in front of the archway, you can hear birds chirping and the sound of a car driving past beyond the surface of the Gate. Hesitating for just a moment, you step through the Gate.\n\n";
    print_line();
    cout << "You almost don't feel the pull this time as you calmly walk past the barrier and find yourself back in the basement of the House. The familiar concrete walls around you.\n"
            "You turn around and see that familiar old stone ring laying in the center of the basement floor, the liquid shimmer within the confines of it.\n"
            "Taking out your phone, you snap several pictures of the old stone ring before taking out the small gray cylinder and placing it in the center of the stone ring.\n"
            "Immediately, the top of the cylinder pops open, releasing a small puff of air before rotating counterclockwise, coming to a stop, and sliding back down.\n"
            "Electricity arcs from the cylinder to the inner circumference of the stone ring. A high, strange droning sound fills the air as you see some small pebbles rise\n"
            "from the floor of the basement and float in the air beside you. You look around you in concern at the floating rocks before noticing the symbols of the stone ring light up.\n"
            "Then, the first symbol loses its light as the droning sound gets higher. Then, the next symbol goes out, and another. Realizing it's a countdown timer, you turn around and run up the stairs.\n"
            "All the while, the droning sound gets louder and louder as arcs of electricity dance on the surfaces of the house around you.\n"
            "You fling open the door and run outside, feeling the warm glow of the afternoon sun on your skin, your car parked out on the street in front of you.\n"
            "You reach it and turn around, waiting for the spectacle. The House is now covered in arcing electricity all over and a bright white light flashes from within.\n"
            "Suddenly, the house begins to fold in on itself, as if being sucked into a small vacuum.\n"
            "Shielding your eyes, you look away for a moment, hearing the wood crack as the house is violently sucked away and soon... silence.\n"
            "You look back up to see an empty lot, the house completely gone and the basement now an empty hole in the ground.\n"
            "Taking out the vial, you drink the crimson liquid, grimacing at the bitter taste before closing it back up and pocketing the vial again.\n"
            "You stand there for a moment, thinking about everything that you've been through, all that you've experienced.\n"
            "You close your eyes and take in a huge breath before turning back around, digging out your keys, and hopping into your car.\n"
            "The paper is gonna love this story.\n\n";

    cout << "\nEnding 38: The End (True Ending)\n\n";

    retry();
}