// File containing functions for The Heart of the Colony passage
#include <iostream>
#include <string>
#include "Heart_of_the_Colony.hpp"
#include "Functions.hpp"
#include "Items.hpp"
#include "Trackers.hpp"
#include "Journal Entries.hpp"

using namespace std;

bool hotc_explored_left_tunnel = false;
bool hotc_explored_middle_tunnel = false;
bool hotc_explored_right_tunnel = false;
bool hotc_heard_history = false;
bool hotc_found_hint = false;
bool hotc_found_root = false;
bool hotc_read_book = false;
bool hotc_ask_orb = false;

// Massive changes to this file to come

void the_heart_of_the_colony_text()
{
    print_line();
    cout << "You brace yourself, but fall to your hands and knees anyway as you go through the entrance.\n"
            "Immediately, you notice something odd about the atmosphere here. The air is thick, yet strangely dry.\n"
            "The floor beneath your hands is composed of chalky, moist soil. You look up to see that you are in a large, dimly lit tunnel.\n"
            "Imperfectly circular, the tunnel runs for some distance ahead and behind you. Again, the portal from the temple has disappeared.\n"
            "Suddenly, you hear a distant familiar chittering that is gradually getting closer. A bright yellow light accompanies the source of the sound.\n"
            "You look around for a hiding spot, but find none. You can either run away from the chittering sound,\n"
            "or you can wait to see what is approaching you.\n\n";

    the_heart_of_the_colony();
}

void the_heart_of_the_colony()
{
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Run away from the sound\n";
    cout << "B. Wait\n";
    cout << "C. Look around some more\n";
    print_line();
    cin >> choice;

    if(choice == 'A' || choice == 'a'){
        print_line();
        cout << "You turn tail and run away from the approaching chittering sounds.\n"
                "Almost immediately, the chittering sounds increase in volume and urgency.\n"
                "You hear rapidly approaching scurrying sounds and quickly look behind you.\n"
                "You are greeted with the sight of multiple giant ants the size of horses chasing you,\n"
                "their enormous mandibles snapping and compound eyes bright with anger and bloodlust.\n"
                "They quickly gain ground, their huge jaws snapping shut just inches behind your ankles.\n"
                "You attempt to pick up speed yourself, but instead one of the ants catches your left foot in its jaws.\n"
                "Pain shoots up your leg as its mandibles pierce through the walls of your shoe and into your ankle.\n"
                "You trip and fall face-first into the dirt floor of the tunnel. Dazed, you barely have to time to register\n"
                "you're on the ground when you start to get pulled away. You panic and claw at the dirt, trying to pull yourself\n"
                "free of the giant ant's grip. It is no use however, as the huge insect easily drags you back towards it.\n"
                "Finally, after dragging you a few meters away, it releases its grip and you roll over to see\n"
                "that you're surrounded on all sides by the giant arthropods. For a moment, you simply look at them, and they at you,\n"
                "before the one that was dragging you swiftly closes the distance and locks its jaws around your throat. You gasp,\n"
                "trying to pull against the iron grip of the huge ant's jaws. It is no use however, as you stare into the dead compound eyes,\n"
                "it slowly clamps its jaws harder and harder around your throat. As your eyes roll up and you gasp for air, you feel\n"
                "blood pouring from your punctured neck and soon a sickening crunch is heard as your neck is broken.\n"
                "The last thing you hear before your limp body falls to the ground is triumphant chittering.\n"
                "Soon the chittering fades away, and you are left staring at the tunnel floor, awaiting death.\n"
                "It cannot arrive soon enough.\n";
                
        cout << "\n\nEnding 7: Crunch";
        print_line();
        retry(&the_heart_of_the_colony_text);
    }
    else if(choice == 'B' || choice == 'b'){
        print_line();
        cout << "You wait, facing the oncoming chittering noises. You nervously grip the loose fabric of your pants, anxiety slowly increasing\n"
                "as your fate waits to be written. Soon, you see the source of the noise and the light: several large ants, one of them carrying an\n"
                "unusual organic-looking lantern on its back. The ants stop and look at you, seemingly bemused at your sudden appearance, but then quickly move in,\n"
                "surrounding you on all sides while one behind you nips at your heels with its huge jaws, urging you forward. Hesitantly, you move forward, keeping pace with\n"
                "the huge insects.\n";

        the_queens_chambers();
    }
    else if(choice == 'C' || choice == 'c'){
        print_line();
        cout << "You quickly look around the tunnel again, looking for anything you might have missed before.\n"
                "It is then you notice an impression in one side of the tunnel, something you missed before due to the dim lighting.\n"
                "It looks as though someone tried digging out another tunnel, but stopped for some reason. It looks like you could hide in there, if you positioned yourself a certain way.\n"
                "The chittering grows louder, it's now or never. You quickly jump into the impression and flatten yourself against the wall as much as possible.\n"
                "You remain still as several huge ants pass by you, the chittering remaining uninterrupted. However, one stops where you dropped from the portal, causing the others to take notice.\n"
                "Its antennae dance around the tunnel floor where you were on your knees, it chitters at the others and soon all of them are looking for you.\n"
                "You could either run away, surrender, or try to fight. After all, you have a momentary advantage over them if you go with a surprise attack.\n";

        hotc_tunnel_options();
    }
    else{
        try_again();
        the_heart_of_the_colony();
    }
}

void the_queens_chambers(){
    cout << "Eventually, the tunnel opens up into a large chamber where you spy a distinct silhouette facing away from you: the Ant Queen.\n"
            "It doesn't look like the typical ant, it is much bigger and has a distinctly semi-humanoid upper torso attached to the thorax,\n"
            "complete with chitin-covered humanoid hands and arms, giving it a very centaur-like appearance.\n"
            "\"It's been decades, Travelers. Have you found me a suitable mate, yet?\" a distinctly feminine voice enters your mind.\n"
            "You say, and think, nothing back at it. Soon, the large form turns around and looks directly at you.\n"
            "\"Well, you're not a Traveler. You're more akin to that scholar that came by years ago.\"\n"
            "This grabs your attention. \"You know about writer of the journals? Where is he?\" you ask out loud to her.\n"
            "The queen looks a bit put-off by your sudden question. \"He didn't stay very long here, as he seemed to be more interested in matters of his own mortality.\"\n"
            "This just makes you more confused. \"What? What do you mean by that?\" you ask.\n"
            "\"Enough!\" the Queen yells into your head, \"Tell me about the Travelers. Have they any any progress on their search?\" the Queen asks, a slight hopeful tone in her \"voice\".\n"
            // Maybe expand this a bit - add interactive dialogue options based on what the player has learned so far?
            "\"Uh, I don't know. There's no Worldwalkers around to ask. They disappeared a long time ago, I think.\"\n"
            "The Queen is somewhat taken aback by this. \"Have they retreated? And they didn't notify me?! We had an agreement!\" she thought-yells as she stomps the ground.\n"
            "There is a minor tremor from this as she turns back around away from you. \"I need to know what happened to them.\" she thought-says, more to herself than to you.\n"
            "She then holds out what seems to be an amber orb of some kind, roughly carved into an approximation of a sphere. Inside, you can just make out a yellow orb within through the roughly hewn surface.\n"
            "The Queen ant stares intently into the orb, her antennae waving frantically in the air before her before suddenly coming to a halt. For several moments, nothing happens and you fidget uncomfortably\n"
            "before the Queen suddenly moves again and turns to you. \"I've seen their end. And your's as well.\" You snap your attention to her, \"What?!\"\n"
            "The Queen is silent for a moment before continuing, \"You travel from place to place with little regard for the strain on your mortal husk.\" she approaches you and you tilt your head back as she towers over you.\n"
            "\"So did the Travelers, and they paid the ultimate price for it.\" After a pause, she walks back towards the center of the room.\n"
            "\"Now leave, you've taken enough of my time.\" Still confused by the interaction, you clumsily take a step towards her before being harshly stopped by the ants that escorted you through the tunnel.\n"
            "\"I c-can't.\", you say. \"And why is that?\" she thought-speaks to you, clutching the amber orb close to her thorax. \"I have to find something here before the Gate reopens.\""
            "\"And just what is it you seek?\" she asks, clutching the orb even closer to herself. \"I don't know, all I know is that it holds some significance to the Worldwalkers.\""
            "The Queen's antennae twitch in thought as she mulls over what you say. After a pregnant pause, she finally thought-speaks, \"The Worldwalkers rarely stayed here longer than necessary, but when they did,\n"
            "they spent the most time in our archives. \'Historians\' and \'archaeologists,\' they called themselves.\" She slowly draws a claw over the surface of the orb, \"But I know they had other intentions.\"\n"
            "She says as her compound eyes narrow. \"You share no such intentions, you merely wish to return home. Because of this, I will allow you to search through my hive, but be forewarned,\"\n"
            "her tone gains a threatening edge as she steps towards you and lowers her head to stare straight into your eyes, \"if you bring harm to any of my subjects, your bones will line my walls.\"\n"
            "You give an involuntary shudder at this. This seems to please her, as she stands back up to her full height and backs up to the center of the room, \"Go now, the sooner you find what it is you seek, the better.\"\n"
            "As she turns away from you, the ants around you disperse and head down another tunnel.\n\n";

    hotc_explore_nest_text();
}


// Redo the options here to fit with the new direction of this passage's story
// Find a specific root to burn to put the Queen and hive to sleep
void hotc_explore_nest_text(){
    print_line();
    cout << "You are now free to explore the ant hive as you please, however keep in mind the warnings the Ant Queen gave you:\n"
            "\"[I]f you bring harm to any of my subjects, your bones will line my walls.\"\n"
            "You shiver slightly from the memory, but clear your head and focus on the matter at hand. You need to explore the hive and find\n"
            "the token you will need before you can return to the temple.\n"
            "From where you stand, you can see three different tunnels before you that lead away from the Queen's Chambers.\n"
            "First, there is the middle tunnel where you were first found but never found out what was at the other end, then there are the\n"
            "two tunnels to the left and right that remain unexplored.\n";
    hotc_explore_nest();
}

void hotc_explore_nest(){
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Explore the left tunnel\n";
    cout << "B. Explore the middle tunnel\n";
    cout << "C. Explore the right tunnel\n";
    cout << "D. Explore the Queen's Chambers\n";
    print_line();
    cin >> choice;

    if(choice == 'A' || choice == 'a')
    {
        print_line();
        if(hotc_explored_left_tunnel){
            cout << "You look back to the tunnel that leads to the egg room, and shake your head.\n"
                    "You did not find the token there, it would be unlikely to be there now.\n"
                    "You look back to the options before you.\n";
        }
        else{
            cout << "You decide to explore the left tunnel.\n"
                    "You go down the left tunnel for some distance before it opens into a large open cavernous space with several large pillars.\n"
                    "Along the walls and floor of the room are several oblong pill-shaped objects with distinct silhouettes wriggling around inside of them.\n"
                    "\"Eggs,\" you think to yourself before hesitantly crossing the threshold into the room. The room is lit with several organic-looking lanterns embedded in the ceiling,\n"
                    "providing a warm glow to the entirety of the large space. Several female worker ants are milling about, tending to the different egg clusters and occasionally throwing wary glances in your direction.\n"
                    "You begin to explore the room, scanning between piles of eggs without actually touching any. The first time you tried to look more thoroughly into a pile, several of the ants in the room let out loud warning\n"
                    "hisses, and you thought it better to not test their patience. After looking for some time, you finally manage to come across something interesting - a folded piece of paper stuck in a hole in a pillar\n"
                    "close to the entrance of the room. It is rather unnoticeable, and basically unretrievable for the ants of the hive, lest they were to actually destroy the pillar itself to find it.\n"
                    "You reach into the hole and bring out the piece of paper. Unfolding it, you begin to read:\n\n";
            cout << journal_entry_4;
            cout << "Folding it back up, you pocket the piece of paper, before noticing another one in the same hole.\n"
                    "Curious, you bring it out and read it:\n\n";
            cout << hint_3;
            cout << "You stare at the paper for a moment, parsing what you just read, before slowly folding it up and placing it in your pocket.\n"
                    "\"This is not going to be easy,\" you think to yourself as you make your way back out of the chamber and into the tunnel.\n";
            hotc_found_hint = true;
            hotc_explored_left_tunnel = true;
        }
        hotc_explore_nest();
    }
    else if(choice == 'B' || choice == 'b'){
        print_line();
        if(hotc_explored_middle_tunnel)
        {
            cout << "You make your way through the tunnel into the archives.\n\n";
        }
        else{
            cout << "You decide to explore the middle tunnel.\n"
                    "Carefully making your way down the mostly dark tunnel, you soon find yourself in a large cavern somewhat resembling a library,\n"
                    "with awkward, organic-looking shelves placed in a circle around a large stone pedestal in the center of the room.\n"
                    "You have found the archives.\n\n";
            hotc_explored_middle_tunnel = true;
        }
        hotc_archives();
    }
    else if(choice == 'C' || choice == 'c'){
        print_line();
        if(hotc_explored_right_tunnel && hotc_found_root){
            cout << "You look down the right tunnel, where the storage room was. You've already found what you needed from there.\n"
                    "You look back towards the other tunnels.\n";
        }
        else if(hotc_explored_right_tunnel && hotc_read_book)
        {
            cout << "Excitedly, you head down the right tunnel until you arrive in the storage room. This time, like the bustling ants around you, you move with purpose.\n"
                    "You head straight for the pile of roots and search through them until you find the one you need. From there, you simply take what you need and leave.\n"
                    "No ants try to stop you or even question what you're doing, they're all too busy with their own jobs to notice.\n"
                    "You walk briskly to the exit and make your way back down the tunnel.\n";
            hotc_found_root = true;
        }
        else if(hotc_explored_right_tunnel)
        {
            cout << "You go down the right tunnel until you arrive in the storage room again, but there's nothing of significance in here.\n"
                    "You head back down the tunnel.\n";
        }
        else{
            cout << "You decide to explore the right tunnel.\n"
                    "After walking for a few minutes, you come to a room full of various piles of objects.\n"
                    "Some resembled construction materials such as logs of wood, what appears to be lumps of clay, and a sticky glob of resin.\n"
                    "Other piles had seeds of all kinds, various strange vegetables, and unusual fruits of differing colors.\n"
                    "Here the ants moved in an organized, purposeful manner, restocking various piles and taking from others, all while avoiding you standing awkwardly among them.\n"
                    "You looked around, staring at the piles of items. Roots, fabrics, and surprisingly, even some tools. Perhaps items of conquest?\n"
                    "Besides the piles of items and bustling activity, you don't find anything that may help you figure out what you're looking for and decide to leave back down the tunnel.\n";
            hotc_explored_right_tunnel();
        }
        hotc_explore_nest();
    }
    else if(choice == 'D' || choice == 'd'){
        print_line();
        if(hotc_read_book)
        {
            cout << "You arrive back in the Queen's Chambers.";
        }
        else if(hotc_found_root)
        {
            cout << "";
        }
        else
        {
            // Redo this one to better suit new direction in story
            cout << "You decide to explore the Queen's Chambers.\n"
                    "The ants that escorted you down the tunnel have now left the chamber, leaving you alone with the Queen, her guards, and one other ant.\n"
                    "The guards stare you down as the Queen busily attends to what appears to be a map of the hive and converses with the other ant.\n"
                    "Looking about the room, you notice something strange. There appears to be a pile of what appears to be junk in one corner of the room.\n"
                    "You approach it and look through the rubble. Soon, you come across what appears to be a broken piece of amber with a strange claw embedded within.\n"
                    "\"Take it,\" you hear in your head. You lift the large piece of amber out of the rubble and tuck it under your arm. Almost immediately, a portal opens up.\n"
                    "\"WHAT ARE YOU DOING?!\" a voice booms in your head. \"DO NOT TOUCH THOSE.\" Your head spins around to see the guards closing in on you and the\n"
                    "glaring angrily at you. \"MY CONQUEST ITEMS ARE NOT FOR YOU TO TAKE!\" Quickly, you make a mad dash for the open portal and narrowly dodge multiple ants\n"
                    "that attempt to stop you, even stepping on one to avoid two others.\n"
                    "You leap into the portal but not before the Queen lets out one last enraged shriek in your head. You close your eyes against the pain and tumble out onto the floor of the temple.\n"
                    "A cold breeze embraces you as you open your eyes and pick yourself up. A mild throbbing in your cranium soon follows as you stagger slightly but quickly right yourself and proceed\n"
                    "to put the amber piece in the stone obelisk. That's another one down. You turn back to the archways.\n\n";
            hotc_explore_nest();
        }
    }
    else{
        try_again();
        hotc_explore_nest();
    }
}

void hotc_archives_text()
{
    print_line();
    cout << "You approach the stone pedestal in the center of the room. Unlike the other chambers you've been in so far, this one appears to be close to the surface.\n"
            "You look up towards the circular hole in the roof of the chamber where sunlight pours through unhindered, it shines directly down on the stone pedestal.\n"
            "You move your gaze downwards onto the pedestal, on it lies a book. The book itself appears to be made of a coarse material, with pages thicker than that of printer paper.\n"
            "The binding and cover of the book appears to be made of a strong, compressed collection of leaves, making for an interesting pattern on both the inside and outside of the covers.\n"
            "\"You're an unusual one,\" you hear in your mind. Surprised, you look around in the bookshelves until you find strange being staring back at you from the shadows to your left.\n"
            "\"Who are you?\" you ask the shadow.\n"
            "\"I am the Librarian,\" it says, stepping out of the shadow and further into the circle of light, \"and I keep the records for the colony here, where they are protected and treasured.\"\n"
            "As it steps further into the light, you notice several differences between this creature and the work ants you ran into when you first came through the Gate. Notably, this one is taller\n"
            "and more humanoid, with a stretched thorax and a pair of arms, resembling the Queen more than the workers you saw earlier. It stands on four legs and walks slowly toward you, revealing\n"
            "more of itself as it towers over you, but not nearly to the height of the Queen.\n"
            "\"And I also want to know who you are,\" it says as it points towards you with an insectile hand, \"because you're definitely not a Traveler.\""
            "\"No,\" you reply, \"I am not one of your \'Travelers\', I am simply trying to make my way back home, and I must find and bring something back from this place to do so.\"\n"
            "\"I see,\" the Librarian says, \"and you think this archive may help with that?\"\n"
            "\"Yes,\" you reply.\n"
            "\"Alright, if you have any questions, you can just ask me.\"\n\n";
    hotc_archives();
}

void hotc_archives()
{
    print_line();
    cout << "\"If you have any questions, feel free to ask me,\" the Librarian says in your mind.\n";
    char choice;
    cout << "What would you like to do?\n";
    cout << "A. Ask about the book on the pedestal\n";
    cout << "B. Ask about the history of the colony\n";
    cout << "C. Ask about the Queen's orb\n";
    cout << "D. Leave the archives\n";
    cin >> choice;
    if(choice == 'A' || choice == 'a')
    {
        print_line();
        if(hotc_read_book)
        {
            cout << "You look back at the book. There is nothing more to learn from it, you know to look for a particular root that can put the ants to sleep.\n"
                    "You look back to the librarian.\n";
        }
        else
        {
            cout << "\"What is this book here?\" you ask, gesturing towards the book on the pedestal.\n"
                    "\"Ah, that is a record of all our accumulated knowledge. The Queen and the colony have learned much from Her conquests.\"\n"
                    "\"May I?\" you ask, gesturing to the book. \"Oh yes, of course!\" responds the Librarian, \"I appreciate the thirst for knowledge you have.\"\n"
                    "You turn back to the book and begin to look through it.\n"
                    "After flipping through the majority of the book, scanning the giant ant's knowledge in different areas - architecture, mathematics, and even pottery,\n"
                    "you come across something interesting - alchemy.\n"
                    "Upon going through much of the section, you finally come across some information that could help in your quest: a sleeping concoction made from the root of a\n"
                    "particular plant. You take note of the way the root looks, then put the book back on the pedestal.\n"
                    "Unsurprisingly, there is no mention of the amber orb the Queen holds in the book. She clearly doesn't want anyone to know about it.\n"
                    "You turn back to the librarian.\n";
            hotc_read_book = true;
        }
        hotc_archives();
    }
    else if(choice == 'B' || choice == 'b')
    {
        print_line();
        cout << "\"I'd like to know more about the history of the colony itself.\n\" you say."
                "\"Well, it all started several millennia ago...\" begins the Librarian."
                "XXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
                "      ONE HOUR LATER\n"
                "XXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
                "\"...and that brings us up to the present, where you now sit.\"\n"
                "You jump to your feet, having been a little too enthralled with the story of the giant insects.\n"
                "Sadly, that didn't help you much with what you were looking for.\n";
        hotc_heard_history = true;
        hotc_archives();
    }
    else if(choice == 'C' || choice == 'c')
    {
        print_line();
        if(hotc_ask_orb)
        {
            cout << "\"The Librarian tilts his head bemusedly, \"You already asked about that, it's just a normal hunk of amber.\"\n";
        }
        else
        {
            if(hotc_found_hint)
            {
                cout << "Given what you just learned from the piece of paper, you decide it wouldn't be wise to ask about the orb directly.\n"
                        "\"I saw the Queen handling a strange amber orb earlier,\" you say, \"is that to help her concentrate?\"\n"
                        "The Libarian stiffens a bit at the mention of the orb, but relaxes once you finish with your question.\n"
                        "\"Oh no, the Queen simply likes the feel of it, I believe. It's just a normal chunk of amber she has taken a liking to.\n";
                        "I personally think it calms her down a bit. She hasn't been quite the same since learning of her... inability.\" he responds.\n"
                        "The Librarian looks visibly uncomfortable.\n"
                        "\"Playing it safe,\" you think to yourself.\n"
                        "If the Librarian heard what you thought, he gives no reaction.\n";
                hotc_ask_orb = true;
            }
            else
            {
                cout << "\"What is that orb the Queen carries around with her? It seems like it's pretty important.\" you ask.\n"
                        "The Librarian stiffens, and his antennae move quickly for a moment before settling down.\n"
                        "\"Oh, that's nothing,\" he says, \"She just likes to hold it every now and then.\"\n"
                        "His tone is guarded now however, yet you persist.\n"
                        "\"Really? Why does she hold it so close to her though? She acts like it's a child or something. It's important that I know exactly what it is.\"\n"
                        "It is then that several worker ants arrive and quickly surround you. You turn around in surprise, seeing the angry glint in their compound eyes.\n"
                        "The Librarian simply says, \"You think that Her orb may hold the key to your escape, but I cannot allow you to take it.\"\n"
                        "You are then herded out of the archives and placed before the Queen herself.\n"
                        "\"So, you want to know what it is I have here,\" you hear in your head, as she holds the orb up for you to see.\n"
                        "\"And not only that, but you believe that it may help you get out of here,\" she says, amused.\n"
                        "\"Well, you cannot have it,\" she thought-speaks, \"and now you will never leave.\n"
                        "You are then escorted out and imprisoned in a cell set high into a wall.\n"
                        "You are kept there for weeks, months, and eventually, years.\n"
                        "The ants take good care of you, all things considered, and you even get to help out every now and then if you behave.\n"
                        "Oh, but the food is awful.\n";

                cout << "\n\nEnding 10: Prisoner";
                print_line();
                retry(&hotc_archives);
            }
        }
        hotc_archives();
    }
    else if(choice == 'D' || choice == 'd')
    {
        print_line();
        cout << "You leave the archives and head back down the tunnel.\n";
        the_queens_chambers();
    }
    else
    {
        try_again();
        hotc_archives();
    }
}

void hotc_tunnel_options(){
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Run away\n";
    cout << "B. Surrender\n";
    cout << "C. Fight\n";
    print_line();
    cin >> choice;

    if(choice == 'a' || choice == 'A'){
        print_line();
        cout << "Quickly, while the ant's attention is away from you, you sprint down the tunnel in the other direction.\n"
                "Immediately, the ants turn around and give chase, chittering loudly all the while. You take a quick look back\n"
                "to see them closing the distance. You try to pick up speed but only succeed in tripping, allowing the ants to catch up to you quickly.\n"
                "You scramble to get back up, but one of the ants steps on your back, putting its full weight on you and pinning you to the ground. Another ant makes\n"
                "its way to the front of you and looks down on you. Without warning, it clamps its large jaws over your cranium. Blood quickly begins to pour where the\n"
                "ant has made contact with your temples and you can feel the pressure increasing as the ant clamps down harder and harder. You pull hard against the jaws\n"
                "of the insect, trying to unclamp them, but they remain in place like a steel vice. It then dawns on you this is how you die - foolishly. Your eyes go wide\n"
                "when you hear a sickening crunch as your skull gives way, then all is black.\n";

        cout << "\n\nEnding 8: Migraine";
        print_line();
        retry(&hotc_tunnel_options);
    }
    else if(choice == 'b' || choice == 'B'){
        print_line();
        cout << "You decide just to surrender to the giant ants. You slowly walk out of the impression in the wall\n"
                "with your hands up, showing your defenseless state. The ants quickly turn toward you, surround you,\n"
                "and then herd you down the tunnel, all the while snapping at your legs with their huge mandibles if\n"
                "you so much as slow down.\n";
        
        the_queens_chambers();
    }
    else if(choice == 'c' || choice == 'C'){
        print_line();
        cout << "You decide to fight. You jump out brandishing the dagger and lunge at the first ant you see.\n"
                "Quickly bringing the dagger down on the back of the ant, you put all your strength into making it a killing blow.\n"
                "The dagger pierces the chitin and stabs the ant, bringing it down. It slumps to the ground, but does not appear dead.\n"
                "The other two ants immediately lunge toward you, angered and ready to kill. The giant insects manuever around you, one on each side, surrounding you.\n"
                "You focus quickly shifts from one to the other and you make striking motions with the dagger to keep them at bay. One ant lunges at your legs, jaws snapping.\n"
                "You turn towards it to fend it off. However, in doing so you have made yourself vulnerable to the other ant. Realizing your mistake you quickly try to\n"
                "turn back around to fend off the other ant but end up losing your balance and tripping over the first ant to attack, which has now locked its jaws around into your leg.\n"
                "You fall flat on your back with your left leg held aloft by the first biting ant. You look over at it, trying to pull out of its jaws, but it only locks in tighter.\n"
                "It then quickly rips its mandibles along the length of your leg, tearing through your sensitive flesh. Pain shoots through your leg as you look down at your now mangled limb.\n"
                "You scream, before a shadow covers your face and you realize the second ant is now standing over you. You quickly try to stab it with the dagger, but it catches your arm\n"
                "and pulls hard. Searing pain tears through your arm as you feel your soft flesh rip apart from the strong jaws. You drop the dagger and scream again. The ants have no mercy\n"
                "for a hostile intruder, however. The second ant grabs your arm again near the shoulder, bites down hard until you feel its mandibles scrape your bone and pulls. A sickening tearing sound\n"
                "can be heard as your arm is torn from its socket. Screams are no longer sufficient in portraying the hellish pain you are in. Tears flow freely from your eyes and you sob loudly as you realize\n"
                "what a terrible mistake you've made. Their task is not over, however. As the first ant moves over your body and grabs your lower jaw with its own and easily yanks it free from your skull.\n"
                "Blood fills your throat as the pain becomes unbearable. You stare at the tunnel ceiling, past the gaze of the ant still looking down at you with your jaw in its own as blood drips from it\n"
                "into your face. The other ant then enters your view and moves closer, its antennae moving over your destroyed visage. You can do nothing except let it happen.\n"
                "Eventually, the ant stops and works together with the other to drag what's left of you down the tunnel. Slowly, your vision fades as you watch the tunnel ceiling pass by and you realize you've lost a lot of blood.\n"
                "One thought strikes you as oddly funny before you eventually die: that you decided to fight an enemy that you knew nothing about and that clearly outnumbered you.\n";

        cout << "\n\nEnding 9: Belligerence";
        print_line();
        retry(&hotc_tunnel_options);
    }
    else{
        try_again();
        hotc_tunnel_options();
    }
}
