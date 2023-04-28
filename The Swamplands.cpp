// File containing functions for The Swamplands passage
#include <iostream>
#include <string>
#include "The Swamplands.hpp"
#include "Functions.hpp"
#include "Journal Entries.hpp"
#include "Trackers.hpp"
#include "Items.hpp"

using namespace std;

bool explored_grasslands = false;
bool explored_tall_trees = false;

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
        if(explored_grasslands)
        {
            cout << "You look toward the tall grasslands, but remember that you didn't find anything there. You look back to the options before you.\n";
            the_swamplands();
        }
        else
        {
            cout << "You decide to explore the tall grasslands.\n"
                    "Getting into the boat, you paddle your way to the left area where tall grasslands greet you on thankfully solid ground. Reaching a smaller, more decrepit dock, you tie your boat to a piling\n"
                    "and climb out. As expected, the grass is much higher than what you initially expected, well above your full height. With deep trepidation, yet equally deep determination, you step into the grasslands.\n"
                    "Several minutes pass before you come across anything within the field. Even traveling in a straight line, you're pleasantly surprised that nothing has actually tried to kill you yet.\n"
                    "Unexpectedly however, the monotony is dropped once you come across an unusual sight - a small camp of wooden and straw huts. And small is not an exaggeration, the huts are barely above knee-height.\n"
                    "You stoop low to look inside one of them - empty. Eventually, you spot several small footprints on the ground leading away from every hut and into the tall grass. You now have two options - follow the\n"
                    "footprints further into the grass or go in a separate direction away from them.\n";
            explored_grasslands = true;
            grasslands();
        }
        break;

    case 'b':
        // 'Living hive' death, and The Black Heart
        cout << "You decide to explore the area with the tall trees.\n"
                "Getting into the boat, you paddle your way straight towards the deep swamp littered with numerous tall trees. As you approach, the sun hides behind the thick canopy, effectively darkening the entire area.\n"
                "Slowing the boat, you look around the deep swamp. The lack of light makes it hard to see, but you can just make out two paths ahead of you - the left path leads into a darker, older part of the swamp\n"
                "with much more densely packed and larger trees, whereas the other simply leads further into the swamp.\n";
        tall_trees();
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
                "                                                                   *****                                                                                \n"
                "The smell of a crackling fire awakens you and you find that you're now back in at the small camp you found earlier, tied securely to a log and the five small\n"
                "hominids are gathered around you. One is standing next to your head, brandishing a crude wood and bone axe. Your eyes widen as you realize what's about to happen.\n"
                "Slowly, one of the members starts to chant and the others soon join in. You pull against the bonds, flexing your muscles, trying everything you can to loosen them.\n"
                "Their chanting grows louder and the one holding the axe slowly raises it above your neck. You try to scream but it only comes out as a muffled moan against the rag\n"
                "tied over your mouth. You scream as the chanting grows ever louder until suddenly they stop, the axe held high. You look up, surprised. Then the one holding the axe\n"
                "breaks out in a gleeful smile and yells maniacally, bringing the axe down swiftly on your exposed neck.\n";

        cout << "\n\nEnding 17: Beheaded\n";
        print_line();
        retry(&grasslands);
        break;

    case 'b':
        cout << "You decide to head in a separate direction away from the footprints.\n"
                "Turning away from the trail of footprints, you walk back into the tall grass. After traveling some ways, you hear running water. Exiting the tall grass, you find yourself\n"
                "on the shoreline of a river. Looking up and down the shore, you don't see any easy way to cross it, nor is there a dock or boat. Turning away, you hear some water sloshing\n"
                "and look behind you to find a crocodile running at you. Terrified, you run into the tall grass as fast as you can. After a moment, you stop to catch your breath and notice\n"
                "that you've outrun the crocodile. As you heartrate returns to normal, you find that you're on a small mound and are able to look above the tall grass. Looking around, you notice\n"
                "a strange small humanoid figure atop a pole above the tall grass. Unfortunately, it also spots you and climbs down the pole with purpose. Almost immediately, you hear high-pitched\n"
                "yells and see the grass moving excitedly as multiple small hominids run towards you. Frantically, you turn around and run in the opposite direction, back towards the river. You run\n"
                "as fast as you can, back through the tall grass. Soon, you see the river through the thinning grass and remember the crocodiles. At the same time, you hear the small hominids gaining\n"
                "ground on you. Thinking quickly, you run to the very edge of the shoreline just before the water and make a sharp turn. Unfortunately, you slip on the wet mud and fall down just as the\n"
                "hominids catch up to you. It is then you hear the water sloshing as a crocodile surfaces. You quickly roll out of the way, and the small hominids are met with a nasty surprise as the\n"
                "crocodile grabs one of them in its huge jaws. Its screams cut through the air as the others try to help free their companion, and the crocodile pulls it under the water. In all the commotion,\n"
                "you are quickly forgotten and manage to run along the shoreline back around the field of tall grass to the small dock where the boat is anchored. You quickly untie the boat from the piling\n"
                "and return to the main dock where you found the boat.\n";
        the_swamplands();
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
    cout << "A. Go into the darker part of the swamp\n";
    cout << "B. Go further into the swamp\n";
    cin >> choice;
    choice = tolower(choice);

    switch (choice)
    {
    case 'a':
        cout << "Against your better judgement, you decide to head into the darker part of the forest.\n"
                "You slowly aim the boat towards the left path and paddle at a steady pace towards it. As you travel further down the path, the darker the swamp around you becomes.\n"
                "You continue onwards until you come to a massive tree with a thick trunk on a small island in the center of a clearing. Tall trees encircle the island at a considerable distance away,\n"
                "giving the entire area a sense of forboding. Slowing the boat down to a crawl, you stare at the massive tree ahead of you. It's a large dead tree, the wood is split and uneven\n"
                "yet, there appears to be large leaves swaying on the branches. As you draw nearer, the water reflects some light onto the island tree, giving it an eerie sense of motion.\n"
                "With a small jolt, the boat hits the shore of the island and breaks you out of your small reverie. Getting out and pulling the boat securely onto the sandy shore, you take in more\n"
                "of your surroundings. The island consists mainly of sand with more solid ground towards the center of the island, where the tree stands tall and wide. As you finish pulling the boat onshore,\n"
                "you get a better look at the tree closer. Immediately, you shudder as you notice that the reflections from the water isn't the primary reason the tree looks like it's moving, you spy\n"
                "and can now hear multiple soft clicking noises from several thousand insects crawling over each other on the tree. You then hear a small buzzing towards the top of the tree and look up.\n"
                "It is then you realize that the 'leaves' are not leaves, but are instead multiple winged insects holding onto the branches of the tree. Creeped out but curious, you take another step closer\n"
                "and proceed to trip as your foot catches on a large root of the tree protruding out of the sand. As you free your entangled foot, the root breaks open. Your eyes widen in horror. Inside the root\n"
                "is a dark shriveled hand, slowly moving and feeling around the edges of the hole in the root. As you stare in morbid shock, a large insect crawls out of a hole covered by a flap of skin on the\n"
                "wrist of the hand. Now terrified and disgusted, you look back to the massive 'tree.' How many bodies...\n"
                "You jump up, intent on getting off the island as fast as possible. However, your quick actions not only break even more of the root, but alert the insects resting on the surface of the tree-like\n"
                "structure. The buzzing sounds grow incredibly loud and you look up from pushing the boat back in the water. The winged insects have taken flight and several thousand of the crawling insects are\n"
                "now crawling towards you. Insects pour from the hole in the root, while others stay and visibly start to patch the hole up. Desperately, you push the boat back in the water and attempt to jump in\n"
                "but can feel several of the insects crawling over you. Unable to resist, you stop and brush off as many as you can. But as you brush off a few, hundreds more crawl onto you. You soon realize the\n"
                "futility of your actions and try to jump into the boat, but the weight of the insects makes your movements sluggish and you fall into the shallow water. You shake off as many as possible,\n"
                "but soon feel several thousand pinpricks as the insects bite you and pump you full of venom. Your movements slow even more and your vision blurs. You eventually cannot move anymore and are dimly\n"
                "aware of being dragged back toward the tree-like nest...\n"
                "                                                                                         *****                                                                                                     \n"
                "It's been several days now. You don't know which part of the tree-nest they stuffed you in, nor can you move as they continue to pump you full of their paralyzing venom. Somehow, you're still aware\n"
                "of what's happening to you. It's so dark that you can't see much, but you can see the dry stretched-out face in front of you, a good foot away from you. The face is locked in a perpetual scream.\n"
                "Every day, you watch the insects crawl in and out of the eye sockets and wide open mouth of the agonized visage. And you know that you will soon share the same fate, because after two days,\n"
                "you lost feeling in your legs before regaining it. You wish you didn't however, as you can feel the insects crawling in and out of holes in your flesh, burrowing out tunnels for them to crawl through.\n"
                "And you can feel them as they slowly but surely burrow upward, drying your meat of blood but somehow keeping you alive in this accursed existence.\n"
                "That's not the worst thing, however. The worst thing is the fact that the face is slowly coming closer... and it's starting to smile.\n";
        
        cout << "\n\nEnding 18: Hive\n";
        print_line();
        retry(&tall_trees);
        break;

    case 'b':
        cout << "You decide to stay the course and head further into the swamp, away from the darker part of it.\n"
                "Keeping the boat going at a steady pace, you maneuver away from the darker part of the forest and continue into the swamp. As you head deeper into the swamp, you notice the trees grow noticeably thicker\n"
                "and more densely crowded. Some time later, the boat inevitably gets stuck on a large cluster of roots. Balancing carefully, you move to dislodge the boat from the cluster of roots. During the process,\n"
                "you notice the swamp grow eeriely silent, void of the buzzing of insects and croaking of frogs. In fact, it is so silent that your breathing sounds amplified. Unintentionally, your heartrate speeds up\n"
                "and you start to feel anxious. Somehow, the silence only deepens and your stomach twists in dread and you just know something is watching you. Slowly, so as to not draw suspicion, you continue to work\n"
                "to dislodge the boat from the roots, all the while listening out for something... anything that will break the deafening silence and stealthily looking around and keeping an eye on your periphery. Finally,\n"
                "after a long moment, you hear the natural sounds of the swamp return just as you finish dislodging the boat. Feeling your dread evaporate, you stand up to your full height and look around, but see nothing\n"
                "out of the ordinary. With a shuddering breath, you return to paddling the boat further into the swamp. After some time, you come across an interesting sight: a decrepit house on stilts standing above the\n"
                "water of the swamp, with a small dock leading up to the raised porch of the house.\n"; // First encounter with Black Heart possessor
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
    case 'a':
        cout << "";
        break;
    
    case 'b':
        cout << "";
        break;

    default:
        try_again();
        islands();
        break;
    }
}