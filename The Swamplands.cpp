// File containing functions for The Swamplands passage
#include <iostream>
#include <string>
#include <conio.h>
#include "The Swamplands.hpp"
#include "Functions.hpp"
#include "Journal Entries.hpp"
#include "Trackers.hpp"
#include "Items.hpp"

using namespace std;

bool explored_grasslands = false;
bool explored_tall_trees = false;
bool explored_islands = false;
bool tt_intro_text = true;
bool hunt = false;
bool crab = false;

void reset_ts()
{
    explored_grasslands = false;
    explored_tall_trees = false;
    explored_islands = false;
    tt_intro_text = true;
    hunt = false;
    crab = false;
}

void the_swamplands_text()
{
    interlude();
    clear_screen();
    print_line();
    cout << "You stumble out of the Gate and immediately get your foot stuck in a deep puddle of mud. The mud sucks at your shoes as you desperately try to free your foot without falling over.\n"
            "Thankfully, after much wiggling and pulling, you manage to free your foot, shoe and all, from the mud without so much as a slight stumble. You finally look up from the muddy puddle\n"
            "and take in your surroundings - you're in an unfamiliar swamp. Tall trees with large roots dot the landscape and tall grass covers the few areas that are above-water.\n"
            "Taking a cautious step forward, you stand on what little solid ground you can find, until you find a large boulder sticking out of the water that gives you some height to take in more of your surroundings.\n"
            "Standing atop it, you see that the swamp is divided into three distinct areas - one shady area covered in weeping willow trees consisting mainly of small islands, another area with a considerable\n"
            "lack of large trees mostly consisting of tall grass and waist-high water, and the final area making up the majority of the swamp with large trees and very deep water you would need a boat to go through.\n"
            "Thankfully, from your high position, you spot a dock with a small boat anchored to it. Climbing down, you make your way to the dock where you find a barrel of rope with a piece of folded paper nested within.\n"
            "Unfolding the piece of paper, you read:\n\n";
    cout << journal_entry_7;
    journals.push_back(journal_entry_7);
    cout << "Look back down into the barrel, you notice another folded piece of paper. Retrieving it and opening it up, you read:\n\n";
    cout << hint_5;
    cout << "Suddenly, you hear a loud roar erupt from the central area of the swamp, birds flying away from the loud sound. Scared but determined, you stand before the options before you - you could explore\n"
            "the left area that consists of tall grassland higher than your shoulders, a central area that consists of tall trees and deep waters, or the right area that is made up of lots of little islands and\n"
            "several weeping willow trees.\n\n";
    the_swamplands(false);
}

void the_swamplands(bool show_interlude=false)
{
    if(show_interlude)
    {
        interlude();
        #ifndef _WIN32
        system("cls");
        #endif

        #ifndef linux
        system("clear");
        #endif
    }
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Explore the tall grasslands\n";
    cout << "B. Explore the deep swamp with tall trees\n";
    cout << "C. Explore the clusters of tiny islands\n";
    print_line();
    char choice = getch();
    choice = tolower(choice);
    cout << choice << "\n";

    print_line();
    switch (choice)
    {
    case 'a':
        if(explored_grasslands)
        {
            cout << "You look toward the tall grasslands, but remember that you didn't find anything there. You look back to the options before you.\n";
            the_swamplands(false);
        }
        else
        {
            cout << "You decide to explore the tall grasslands.\n";
            grasslands();
        }
        break;

    case 'b':
        cout << "You decide to explore the area with the tall trees.\n";
        tall_trees();
        break;

    case 'c':
        if(explored_islands)
        {
            cout << "You look towards the islands and think about what you saw there, then look back towards the options in front of you.\n";
            the_swamplands(false);
        }
        else
        {
            cout << "You decide to explore the cluster of small islands.\n";
            islands();
        }
        break;
    
    default:
        try_again();
        the_swamplands(false);
        break;
    }
}

void grasslands()
{
    interlude();
    clear_screen();

    cout << "Getting into the boat, you paddle your way to the left area where the tall grasslands greet you on thankfully solid ground. Reaching a smaller, more decrepit dock, you tie your boat to a piling\n"
            "and climb out. As expected, the grass is much higher than what you initially expected, well above your full height. With deep trepidation, yet equally deep determination, you step into the grasslands.\n"
            "Several minutes pass before you come across anything within the field. Even traveling in a straight line, you're pleasantly surprised that nothing has actually tried to kill you yet.\n"
            "Unexpectedly however, the monotony is dropped once you come across an unusual sight - a small camp of wooden and straw huts. And small is not an exaggeration, the huts are barely above knee-height.\n"
            "You stoop low to look inside one of them - empty. Eventually, you spot several small footprints on the ground leading away from every hut and into the tall grass. You now have two options - follow the\n"
            "footprints further into the grass or go in a separate direction away from them.\n";
    explored_grasslands = true;
    
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Follow the footprints\n";
    cout << "B. Go in a separate direction\n";
    print_line();
    char choice = getch();
    choice = tolower(choice);
    cout << choice << "\n";

    print_line();
    switch (choice)
    {
    case 'a':
        cout << "You decide to follow the footprints.\n"
                "Approaching slowly, you follow the trail of footprints deeper into the tall grass, making sure to keep an ear out for anything that might\n"
                "try to get the jump on you. After a few moments, you start to hear noise nearby where you see the tall grass thin out. Quietly, you approach\n"
                "the edge of the tall grass. Cautiously peering out, you spy four small monkey-like figures with carved wooden masks gathered around the corpse\n"
                "of some kind of horned ungulate, cutting into the beast with pale daggers and speaking to each other in a strange harsh tongue. Slowly backing up,\n"
                "you turn to leave. Suddenly, another one of the small hominids suddenly jumps out in front of you and screeches, pointing a sharp spear at you.\n"
                "Instantly, you hear the others stop what they're doing and race towards the both of you. You brandish the dagger and turn to the side to keep all\n"
                "five of them in sight. It's no good however, as they split up and circle around you, ushering you further out of the tall grass and into the\n"
                "clearing you found them in. You grip the dagger tight, trying to keep as many as possible in your sight. It's futile however, as one of them distracts\n"
                "you by coming a little too close and drawing your attention, allowing another to jump on your back and stick the tip of a small sharp wooden stick\n"
                "into your neck. Instantly, you shake him off, but he only whoops in triumph as he digs his sharp little claws through your clothing and into your skin.\n"
                "After a few seconds, the world starts to blur around you and your movements become sluggish and slow. Eventually, your legs give in and you fall\n"
                "to the ground, unconscious.\n"
                "                                                                   *****                                                                                \n"
                "The smell of a crackling fire awakens you and you find that you're now back in the small camp you found earlier, tied securely to a log and lain on the ground as\n"
                "the five small hominids are gather around you. One is standing next to your head, brandishing a crude wood and bone axe. Your eyes widen as you realize what's about to happen.\n"
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
                "you are quickly forgotten and manage to run along the shoreline back around the field of tall grass to the small dock where the boat is anchored. You quickly untie the boat from the piling,\n"
                "jump in, and paddle your way back to the first dock you found the boat at.\n";
        the_swamplands(true);
        break;
    
    default:
        try_again();
        grasslands();
        break;
    }
}

void tall_trees()
{
    interlude();
    clear_screen();

    if(tt_intro_text)
    {
        cout << "Getting into the boat, you paddle your way straight towards the deep swamp littered with numerous tall trees. As you approach, the sun hides behind the thick canopy, effectively darkening the entire area.\n"
                "Slowing the boat, you look around the deep swamp. The lack of light makes it hard to see, but you can just make out two paths ahead of you - the left path leads into a darker, older part of the swamp\n"
                "with much more densely packed and larger trees, whereas the other simply leads further into the swamp.\n";
        tt_intro_text = false;
    }

    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Go into the darker part of the swamp\n";
    cout << "B. Go further into the swamp\n";
    print_line();
    char choice = getch();
    choice = tolower(choice);
    cout << choice << "\n";

    print_line();
    switch (choice)
    {
    case 'a':
        cout << "Against your better judgement, you decide to head into the darker part of the forest.\n"
                "You slowly aim the boat towards the left path and paddle at a steady pace towards it. As you travel further down the path, the darker the swamp around you becomes.\n"
                "You continue onwards until you come to a massive tree with a thick trunk on a small island in the center of a clearing. Tall trees encircle the island a considerable distance away,\n"
                "covering the entire area in shade and creating a sense of forboding. Slowing the boat down to a crawl, you stare at the massive tree ahead of you. It's a large dead tree,\n"
                "its wood split and uneven, yet there appears to be large leaves swaying on the branches. As you draw nearer, the water reflects some light onto the island tree, giving it an eerie sense of motion.\n"
                "With a small jolt, the boat hits the shore of the island and breaks you out of your small reverie. Getting out and pulling the boat securely onto the sandy shore, you take in more\n"
                "of your surroundings. The island consists mainly of sand with more solid ground towards the center of the island, where the tree stands tall and wide. As you finish pulling the boat onshore,\n"
                "you get a better look at the tree. You shudder as you notice that the reflections from the water aren't the primary reason the tree looks like it's moving,\n"
                "as you spy several thousand insects crawling over each other, creating soft clicking noises as they move. You then hear a small buzzing towards the top of the tree and look up.\n"
                "It is then you realize that the 'leaves' are not leaves, but are instead multiple winged insects holding onto the branches of the tree. Creeped out but curious, you take another step closer\n"
                "and proceed to trip as your foot catches on a large root protruding out of the sand. As you free your entangled foot, the root breaks open. Your eyes widen in horror. Inside the root\n"
                "is a dark shriveled hand, slowly moving and feeling around the edges of the hole in the root. As you stare in morbid shock, a large insect crawls out of a hole on the wrist of the hand,\n"
                "moving aside a thin gray flap of skin to exit. Now horrified and disgusted, you look back to the massive 'tree.' How many bodies...\n\n"
                "You jump up, intent on getting off the island as fast as possible. However, your quick actions not only break even more of the root, but further alert the insects resting on the surface of the 'tree'.\n"
                "The buzzing sounds grow incredibly loud and you look up from pushing the boat back in the water. The winged insects have taken flight and several thousand of the crawling insects are\n"
                "now making their way towards you. Thousands of insects pour from the hole in the root, while some stay and visibly start to patch the hole up. Desperately, you push the boat back in the water\n"
                "and make to jump in, but notice several of the insects crawling over you. Immediately, you stop and brush off as many as you can. But as you brush off a few, hundreds more crawl onto you.\n"
                "You soon realize the futility of your actions and try to jump into the boat, but the weight of the insects makes your movements sluggish and you fall into the shallow water.\n"
                "You writhe in the water, shaking off as many as possible, but soon feel several thousand pinpricks as the insects bite into you, pumping you full of venom. Your movements slow even further as your vision blurs.\n"
                "Soon, you find that you cannot move at all anymore and become dimly aware of being dragged back toward the tree-like nest...\n"
                "                                                                                         *****                                                                                                     \n"
                "It's been several days now. You don't know which part of the tree-nest they stuffed you in, nor can you move as they continuously inject you with their paralyzing venom.\n"
                "Somehow, you're still aware of what's happening to you. It's so dark that you can't see much. However, you can see the dry stretched-out face several inches away from you, locked in a perpetual scream.\n"
                "Every day, you watch the insects crawl in and out of the eye sockets and wide open mouth of the agonized visage. And you know that you will soon share the same fate.\n"
                "You know this because after two days, you could feel them burrow into your legs. You feel the insects crawl in and out of holes in your flesh, cutting into you like termites into wood.\n"
                "And you can feel them as they slowly but surely make their way upward, draining your flesh of blood and bodily fluids along the way.\n"
                "Yet, somehow you remain alive in this torturous existence.\n"
                "Every day is agony as the pain never subsides and your mind slowly unravels trying to make sense of your continued existence.\n"
                "Every day, you stare at that same face frozen in perpetual agony.\n"
                "Every day, you wish for death.";
            
        cout << "\n\nEnding 18: Hive\n";
        print_line();
        retry(&tall_trees);
        break;

    case 'b':
        cout << "You decide to stay the course and head further into the swamp, away from the darker part of it.\n"
                "Keeping the boat going at a steady pace, you maneuver away from the darker part of the forest and continue into the swamp. As you head deeper into the swamp, you notice the trees grow noticeably thicker\n"
                "and more densely crowded. Some time later, the boat inevitably gets stuck on a large cluster of roots. Balancing carefully, you move to dislodge the boat from the cluster of roots. During the process,\n"
                "you notice the swamp grow eeriely silent, void of the buzzing of insects and croaking of frogs. In fact, it is so silent that your breathing sounds amplified. Unintentionally, your heartrate speeds up\n"
                "and you start to feel anxious. Somehow, the silence only deepens and your stomach twists in dread as you feel that something is watching you. Slowly, so as to not draw suspicion, you continue to work\n"
                "to dislodge the boat from the roots, all the while listening out for something... anything that will break the deafening silence and stealthily look around, keeping an eye on your periphery.\n"
                "Finally, after a long moment, you hear the natural sounds of the swamp return just as you finish dislodging the boat. Feeling your dread evaporate, you stand up to your full height and look around,\n"
                "but see nothing out of the ordinary. With a shaky breath, you return to paddling the boat further into the swamp.\n\n"
                "After some time, you come across an interesting sight: a decrepit house on stilts standing above the water of the swamp, with a small dock leading up to the raised porch of the house.\n"
                "Climbing up the short stairs, you stop to knock, but immediately hear a strange sound - a muffled rhythmic thudding noise, coming from the other side of the door.\n"
                "Curious, you put your ear up to the door and listen. The beat remains steady and intense. Slowly, you push open the door, careful not to make too much noise.\n"
                "It is then you see a large hole in the floor of the house several feet in front of you. Peeking into the hole, you see a swirling black mass of exposed muscle fibers shining like black licorice moving in a slow,\n"
                "serpentine fashion around an exposed center. And in that very center lies a black pulsating heart, beating loudly. You slowly approach the hole, watching the exposed\n"
                "muscle fibers shift and weave around hypnotically. As you draw near, you become dimly aware of the lack of noise that has once again pervaded the atmosphere. The silence grows as you kneel on the edge of the hole,\n"
                "the only thing you hear being the beating of the black heart. You are now mere inches away swirling black mass, you reach toward the pulsating organ with enraptured fascination before a loose floorboard beneath you suddenly\n"
                "gives way and you almost fall completely into the hole. You catch the sides quickly, stopping your fall forward. Immediately, the black mass now directly beneath you covers the beating heart, suddenly sprouting an eye that looks directly at you.\n"
                "Terrified, you scream as you push yourself up and away from the hole, falling flat on your rear before the mass of black explodes straight up past you and through the ceiling of the house.\n"
                "An unearthly, echoing roar fills the air as adrenaline floods your veins and you get up, turn, and run back through the door, down the short stairs, and practically dive into the boat.\n"
                "Kicking off the small dock and paddling as fast as you can, you hear multiple cracks and snaps as small pieces of wood and leaves rain down from the canopy above you.\n"
                "Pushing hard on the paddle, you hear a roar grow louder behind you until it is almost deafening. You've awakened a predator, and it has made you its prey.\n";
        hunt = true;
        the_hunt();
        break;
        
    default:
        try_again();
        tall_trees();
        break;
    }
}

void islands()
{
    interlude();
    clear_screen();

    cout << "Getting into the boat, you point it in the direction of the cluster of islands and begin to paddle your way there. Unlike the other areas, this area is further away.\n"
            "After paddling for a long while, you finally arrive at the first of the islands. A dense fog has collected around the islands, making it hard to see in particular areas.\n"
            "From what you can make out, it seems as though there are two areas that seem to be worth exploring - a large island with a collection of large boulders in the middle of it and another area\n"
            "filled with several broken and rotting wooden structures that may have been a village at some point in the past.\n";

    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Explore the large island with several large boulders\n";
    cout << "B. Explore the abandoned village\n";
    cout << "C. Turn around and head back to the dock\n";
    print_line();
    char choice = getch();
    choice = tolower(choice);
    cout << choice << "\n";

    print_line();
    switch (choice)
    {
    case 'a':
        if(crab)
        {
            cout << "You look toward the island and shudder a bit as you spy the boulder-like shell of the giant crab. You shake your head and turn back to the options before you.\n";
            islands();
        }
        else
        {
            cout << "You decide to explore the island with the pile of large boulders on it.\n"
                    "Pointing your boat in the direction of the island, you paddle your way over until you breach the shore and stop. Getting out, you secure the boat and approach the rocks.\n"
                    "Looking through them, you don't seem to find anything of interest and get up to leave until you hear something. A noise. Some kind of faint clicking, coming from in-between two rocks.\n"
                    "Could it be a device of some kind? Maybe something that could help you? The crack is just large enough for you to fit your hand in, so maybe you can reach it...\n";
            rock_island();
        }
        break;
    
    case 'b':
        cout << "You decide to explore the abandoned village.\n"
                "You paddle your way towards the broken and rotting wooden structures and tie off the boat on a small, decrepit, barely functional dock nearby.\n"
                "Getting off the boat, you are immediately hit with a strange feeling of being watched. You glance around quickly, but see nothing. Creeped out, you hesitantly make your way towards the village.\n"
                "Once there, you start to methodically search through the buildings, looking for anything that might help you. While searching the third house, you hear a strange creaking noise outside, like a wooden\n"
                "branch swaying in a strong wind. That doesn't make any sense however, since there is no wind here at all. You make your way to the doorway and look around outside, listening for the source of the creaking noise.\n"
                "The creaking noise is now absent however, and you don't see anything out of the ordinary either. Now on edge, you close the rotting door and turn around to begin searching again but hear the\n"
                "creaking noise resume. Turning back around and throwing the door open, you step outside and immediately scream, falling back into the house. Outside, you see a wooden statue looming several feet away from the doorway, unmoving.\n"
                "It has a carved, mask-like face and several twisted tree limbs making up its body. Slowly, you get back up and approach it. The statue remains still, unmoving.\n"
                "You take a closer look at its face and can make out the fine detail in the mask-like carving of it, with a large frowning face and hollowed-out eyes, it reminds you of a tribal-style Greek tragedy mask.\n"
                "Quickly looking side to side, you don't see anyone that could have moved the statue here. Apprehensively, you back into the doorway of the building, making sure to keep the statue within view.\n"
                "After one last long look at it, you once again close the door. As soon as the door hits the frame, you hear the wooden creaking noise again, now joined by others around the house.\n"
                "Terrified, you throw the door open, intent on running away, only to come face to face again with the wooden statue, which has moved several feet closer and now looms right outside the door.\n"
                "You scream in surprise, its face directly in front of you, its frown having somehow grown deeper. You stumble back from it and slam the door shut, moving a mostly-intact piece of furniture in front of it.\n"
                "A loud bang rattles the door in its frame, the sound of wood splintering fills the air. The wooden creaking noise is now all around you, surrounding the house you're in. You quickly run around the perimeter of the room,\n"
                "looking through the windows to see two more wooden statues, each with its own uniquely carved face standing outside. All the while the front door starts to break and you soon hear pounding on other walls of the room.\n"
                "You cower in the center of the room, unsure of what to do. You cover your ears as the pounding grows louder and close your eyes, tucking your head into your knees and taking a deep breath in a feeble attempt to calm yourself.\n"
                "The pounding suddenly stops and you slowly, apprehensively, remove your hands from your ears. Lifting your head up from your knees, but still not opening your eyes.\n"
                "Slowly, you open your eyes and scream as a carved face stares back at you, connected to a long, thick wooden branch poking in through the open window. You crawl backwards, never taking your eyes off the carved face.\n"
                "It doesn't move as you maneuver away from it and towards the door. You quickly get up and turn towards the door, only to be greeted with the split remains of the door and the statue now completely blocking the exit,\n"
                "its carved face now having slinked over the makeshift barricade, staring back at you. Angry, you take out the dagger and stab at the carved wooden face, striking it in one of the cheeks.\n"
                "Immediately, a sharp pain explodes in your own cheek and you drop the dagger as blood oozes down your face. You press down on the fresh wound and back up, horrified.\n"
                "You start hyperventilating as you hear wooden creaking behind you and you quickly turn to see the one in the window has turned on its long neck to face you, its expression one of comedic joy.\n"
                "Your eyes flick between the two as you back up until your back hits a wall, keeping both of them in view. Behind you, you hear wood creaking just beyond the surface of the wall and a new pounding starts behind your back,\n"
                "shaking the wall with every hit. You slowly start to accept the reality of the situation and hopelessly fall to the floor. Tears well up in your eyes, but you refuse to blink, staring at the two masks in front of you as a burst of wood chips rains down on you.\n"
                "You keep your eyes trained on them for a several moments before realizing that a shadow has moved above you. Hesitantly, you look up and see another wooden mask poking through a hole in the wall mere inches above you, carved with a solemn, stoic expression.\n"
                "Your eyes are burning now and you struggle hard to keep them open, but you can't. You take a deep breath, surrendering as you close your eyes one final time. The creak of wood all around you is the last thing you hear.\n";
        
        cout << "\n\nEnding 20: Totems\n";
        print_line();
        retry(&islands);
        break;

    case 'c':
        cout << "You turn the boat around and head back to the dock.\n";
        explored_islands = true;
        the_swamplands(true);
        break;

    default:
        try_again();
        islands();
        break;
    }

}
void rock_island()
{
    interlude();
    clear_screen();
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Reach between the rocks\n";
    cout << "B. Return to the boat\n";
    print_line();
    char choice = getch();
    choice = tolower(choice);
    cout << choice << "\n";

    print_line();
    switch (choice)
    {
    case 'a':
        cout << "Thinking it could be a device, you reach between the rocks and feel around, trying to find something that could be making the noise. It is then the clicking suddenly stops, and you in turn, pause.\n"
                "You hold still for a moment, and just when you're about to pull your arm out, something grabs onto you. You scream and pull away, tearing a finger off in the process. Falling down, you clutch your\n"
                "bleeding hand, pinching the severed stump in an attempt to stop the bleeding. It is then the biggest boulder in the pile moves. Momentarily forgotten, you look away from your missing finger and look\n"
                "towards the moving rock. With growing horror, you watch as the 'rock' turns towards you and is revealed to be a giant crab, your missing finger still clutched in its giant claw. Bringing your finger\n"
                "towards its mouth, it slowly chews it. Then, with terrifying speed, it approaches you and in desperation, you crawl backwards away from it. You're not fast enough however, and the crab soon grabs your\n"
                "leg in its giant claw and drags you closer. Kicking and hitting it with all your might, you soon stop as your fists start to bleed from impacts with the spikey carapace of the crab. Resorting to only kicking,\n"
                "you desperately flail at the crab, which seems to not be affected by your hits at all, only reacting in an annoyed manner to them. The crab then grabs your other leg mid-kick with its other claw and gives it\n"
                "a hard squeeze. You cry out in pain as the pressure intensifies until you hear a sickening crack as your leg bone breaks, tears welling up in your eyes. The crab then drops both of your legs to the ground and\n"
                "steps over you. Adrenaline takes over and you once again try to back up, crawling backwards on your elbows until you feel them sloshing in the shallow swamp water. The crab is not done, however.\n"
                "It grabs you by the shoulder with one of its claws and drags you back towards the center of the island. Now crying, you turn your body and helplessly claw at the ground, some of your fingernails breaking as a result.\n"
                "The crab drags you into a large divet in the ground and claws at your body, cutting and tearing open your skin everywhere. You defend as much as you can, but are helpless against the sharp and brutal onslaught.\n"
                "After several moments, you feel your strength leave you as your blood soaks the ground. Your limbs fall to your sides and you relent, letting the crab finish the job. Your head slumps back and you take\n"
                "one final breath before your vision fades entirely to black.\n";
        
        cout << "\n\nEnding 19: Clawed\n";
        print_line();
        retry(&islands);
        break;
        
    case 'b':
        cout << "You decide it would not be worth it to find out. You get up and return to the boat. The clicking noise increases in volume, but you ignore it. Suddenly, the biggest rock in the pile gets up and turns towards you.\n"
                "It's not a rock at all, but a giant crab. You watch as it clicks its mandibles together, reproducing the clicking noise you heard. You stare in shock for a moment before the crab starts crawling rapidly towards you.\n"
                "You turn and run, jumping into the boat and pushing off the shore, paddling as fast as you can. The crab soon reaches the shore and watches you for a moment before turning back around and settling back into its divet,\n"
                "its shell blending in and looking just like a boulder. You watch in stunned fascination as you slow your paddling and your heartbeat. \"It's a good thing I didn't reach between those rocks\", you think as you paddle\n"
                "back to the start of the paths.\n";
        crab = true;
        islands();
        break;

    default:
        try_again();
        islands();
        break;
    }

}
        
void the_hunt()
{
    interlude();
    clear_screen();
    print_line();
    cout << "Going back to the starting position, you look around quickly, taking in your surroundings and looking for anything that might make a good makeshift weapon. The Nightflesh monster will be here any minute now,\n"
            "and you only have the dagger on you for protection. There are a few sizable rocks laying in a pool nearby, a large broken-off branch that could make a good makeshift club lying against the trunk of a tree,\n"
            "and of course, the paddle for the boat. Using the dagger, you could sharpen one end of the paddle into a makeshift spear, but that would cost precious time, and that is not something you have a whole lot of.\n"
            "Alternatively, you could just wait for the creature to arrive and fend it off with only the dagger. Whatever choice you make right now will be your final decision before the confrontation,\n"
            "so you better make a good decision and make it fast.\n\n";

    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Pick up the rocks\n";
    cout << "B. Pick up the large branch\n";
    cout << "C. Sharpen the paddle into a spear\n";
    cout << "D. Make do with the dagger\n";
    print_line();
    char choice = getch();
    choice = tolower(choice);
    cout << choice << "\n";

    print_line();
    switch (choice)
    {
        case 'a':
            cout << "You decide to pick up the rocks.\n"
                    "You start digging through the puddle, grabbing the larger of the rocks and bringing them onto the boat. Soon after grabbing a few of the rocks, you suddenly feel the hairs on the back of your neck stand up.\n"
                    "Your slowly lift your head up and notice that the swamp has grown silent all around you. It is so quiet in fact, that you can hear your own heartbeat and shallow breathing. Then it returns, that feeling of being watched.\n"
                    "Except now you know exactly what it is that is watching you. You hurriedly grab some rocks and get in position to throw them as soon as you see the Nightflesh creature. Keeping your eyes peeled, you look all\n"
                    "around the silent swamp. The boat rocking back and forth from your motions. Then you hear it, a growing roar directly above you. Immediately, you look up. The Nightflesh monster looks down from the canopy\n"
                    "of trees, spread out like a spider's web with a multitude of eyes all along the strands. You scream and immediately throw a rock up towards it, hitting one of its eyes. The thing roars in anger and crawls down towards you\n"
                    "at breakneck speed. You get off one more shot with a rock before it is upon you, now in humanoid form, gripping your throat in its strong hands. You beat at it with a large rock in one hand while the other claws at the\n"
                    "vice-like grip it has on your throat. Soon, your lungs scream for air and you try to suck in what you can while your strength wanes and your hits with the rock falter. The thing, sensing your situation, lifts you up\n"
                    "by the neck and holds you. You drop the rock and with both hands, pry desperately at the ferociously strong grip it has on your neck, your face now turning blue. It brings you closer, looking at you with numerous eyes\n"
                    "on its slick black flesh where a face should be. Soon, darkness creeps in at the edges of your vision as the thing's face morphs into several rows of jagged shark-like teeth and moves to bite off your head.\n";
            
            cout << "\n\nEnding 21A: The End of the Hunt - Stones\n";
            print_line();
            retry(&the_hunt);
            break;
        
        case 'b':
            cout << "You decide to pick up the large branch.\n"
                    "You paddle towards the large branch leaning against one of the tall swamp trees and position yourself to pull it out of the stagnant swamp water. Balancing carefully, you hoist the large branch up out of the water.\n"
                    "It's nearly a yard long and hefty. You give a few practice swings and find yourself nearly falling out of the boat. You squat back down, grabbing the sides of the boat as it gradually settles back down,\n"
                    "dropping the branch in the process. After stilling the boat, you stand back up but immediately notice a change in the atmosphere of the swamp. Everything has gone silent, so quiet that the only thing making noise is you.\n"
                    "Immediately, you fumble for the branch as you feel eyes on you and stand back up, goosebumps breaking out on your skin. Then you see it, the Nightflesh creature, crawling on the side of a tree and looking down at you\n"
                    "with numerous eyes pockmarking its slick pitch-black skin all across its humanoid head. You reach down and grab the branch, trying to steady yourself in the rocking boat. All at once, the thing's face morphs into a large\n"
                    "mouth as it roars and dives at you. You raise the branch just in time for it to absorb most of the impact of the beast before tumbling into the water with it as the boat rolls over. Under the water, you struggle against\n"
                    "the monster's much larger mass as it pulls you deeper and deeper. Changing the orientation of the branch, you shove the larger end of it into the thing's face, breaking its hold on you as you start to swim back to the surface.\n"
                    "Breaking free of the surface of the water for just a moment, you take a big lungful of air before you are pulled back under again. This time, the Nightflesh creature has the branch and it whacks you with it across your face,\n"
                    "causing you to lose your breath and see stars. It then pulls you deeper as you struggle to regain your composure, pulling you towards a collection of large boulders. Once there, it throws you against the largest boulder.\n"
                    "You hear a sickening crack in your back and involuntarily suck in a mouthful of dirty swamp water as the wind is knocked out of you. Then, the Nightflesh creature lifts the branch with one hand and with a mighty thrust,\n"
                    "impales the smaller end of the branch through your abdomen and into a large crack in the boulder. Blood pours out of you and darkens the water as the Nightflesh creature swims closer to look in your eyes one more time before swimming away,\n"
                    "leaving you to die under the water.\n";
            
            cout << "\n\nEnding 21B: The End of the Hunt - Branch\n";
            print_line();
            retry(&the_hunt);
            break;

        case 'c':
            cout << "You decide to sharpen the paddle into a spear.\n"
                    "Paddling towards a small raised piece of land nearby, you stop the boat on it and steady yourself as you take out the dagger and carefully start to whittle away the rounded end of the handle into a sharp point.\n"
                    "After some time, you develop a nice sharp point that could do some real damage. Putting the dagger away, you stand up and practice a few jabs with the sharpened paddle, making sure not to dislodge the boat while you're at it.\n"
                    "Soon, you realize that the swamp has fallen silent, with you being the only source of noise. You grip your makeshift spear and look around for the Nightflesh creature, keeping a keen eye on your periphery.\n"
                    "After several seconds you finally spot it standing between two large bushes, almost unnoticeable in its rigid posture, poised like an animal ready to strike. As soon as you see it, several eyes pop open all over its body,\n"
                    "and look at you with unrestrained malice. You stand firm, the spear giving you some degree of confidence despite your pounding heart and fear flooding through your veins.\n"
                    "Suddenly, it rears back and lets loose a deafening roar before plowing through the bushes towards you. You brace yourself the best you can in the still boat, your spear pointed towards the charging beast.\n"
                    "Loud thuds can be heard with the creature's every step as it hurtles towards you, its mostly humanoid silhouette changing shape at random. Soon, it is upon you and you thrust the spear into it with all your might,\n"
                    "grinding it in and twisting the handle as you go. To your dismay however, it doesn't seem phased, proceeding to simply absorb the spear into its form with a sickening sucking sound before pulling it out the other side.\n"
                    "You watch in stunned silence as it lifts and holds the spear inches from its 'face', inspecting it. Then, it simply tosses your makeshift weapon into the waters with contempt. It then looks at you, making your stomach drop.\n"
                    "Oh, you've gone and done it now. With blinding speed, the Nightflesh creature morphs one of its arms into a wicked point and impales you with it. Pain floods your abdomen as you feel it lift you off the ground.\n"
                    "The taste of blood fills your mouth as it raises you above it with one arm and lets out a loud raspy choking sound that you soon realize is its laughter, its form writhing with glee.\n"
                    "Unbearable pain soon gives way to a growing numbness as you realize your inevitable fate, and as your vision fades, you feel the thing retract its sharp, twisted limb and lets you fall into the boat.\n"
                    "The last thing you see is its multitude of eyes staring down at you as your vision fades to black.\n";
            
            cout << "\n\nEnding 21C: The End of the Hunt - Spear\n";
            print_line();
            retry(&the_hunt);
            break;

        case 'd':
            cout << "You decide to make do with the dagger.\n"
                    "Taking it out, you examine it closer. Surprisingly, the red jewel embedded into the guard of the dagger is glowing slightly.\n"
                    "Taking time to examine it fully, you find that the dagger also has some intricate carvings on the guard and pommel, somewhat resembling the artwork found around the gates in the temple.\n"
                    "As you continue to inspect it, you notice the glow of the jewel slowly growing brighter. You also notice that the swamp around has grown quiet.\n"
                    "Gripping the dagger in your right hand, you stand up in the boat and take in the silent swamp. Somehow, you feel as though your senses have grown slightly more keen, and your head\n"
                    "snaps up and catches the form of the Nightflesh creature flash by overhead as it leaps from tree to tree before finally coming to rest above you. Looking down, it seems somewhat surprised\n"
                    "to see that you've already spotted it. Recovering quickly, it roars loudly, giving you time to prepare and set your feet into position, assumging a stance ready to receive a charge from the creature.\n"
                    "And it does, jumping from its position on the tree to the boat. As it lands, the boat shudders violently and a loud crack can be heard as it splits into two, causing the creature to fall into the water.\n"
                    "You jump off the boat and onto a small nearby island formed by the roots of a large tree and again, get ready for another charge from the creature. The creature quickly surfaces and jumps onto the island,\n"
                    "snarling and circling around you. Now in its humanoid form, the face of the creature is taken up by a huge mouth spread from ear-to-ear with long sharp dagger-like teeth as its body sprouts numerous blinking eyes.\n"
                    "Taking your steps carefully, you mirror the movements of the creature, keeping the dagger pointed at it while making your own circle on the island. Finally, after several moments, the creature lashes\n"
                    "out at you with a huge clawed hand but you manage to just avoid it and slice the dagger across its arm. It howls with pain and rage as the slash visibly bubbles the flesh around it, resembling a severe\n"
                    "chemical burn. Noticing this, you quickly look at the dagger and notice the glyphs on the blade and the jewel inset into the guard are now glowing bright red. So bright in fact, that you expect the dagger\n"
                    "to be red-hot, and you realize, it just might be to the creature. Placing its hand on its cut, the creature appears to be confused as to why the flesh remains scarred and unchanging as the flesh around it\n"
                    "morphs and shifts in-place. It then looks back up to you and roars angrily. It pushes off the ground and charges at you once again with remarkable speed. Dodging the otherwise supernatural strike easily with\n"
                    "your own newfound speed, you stab the dagger into the back of the creature and cut a deep slash across its back. It roars in pain and falters mid-charge, stumbling away from you quickly. You jump back\n"
                    "swiftly and brandish the dagger before you. The creature stumbles, the flesh of its back bubbling violently as it lets out a pained roar and falls to the ground, clawing at the earth. Taking advantage\n"
                    "of the situation, you quickly close the distance and turn the lightly thrashing beast over, exposing the heart surrounded by writhing muscle. You lift the dagger up and plunge it into the connecting tissue.\n"
                    "The creature lets out a pained howl and claws at you, drawing blood. You yelp and jump back, but kick the creature down again as it slowly tries to get up. Keeping the creature's good arm pinned beneath your\n"
                    "own, you again plunge the knife into the muscle surrounding the Black Heart, severing the strands holding it aloft. It writhes and snarls at you, yowling in pain whenever you cut more of the strands away.\n"
                    "Eventually, its movements slow and grow weak as you near the end of your extraction and begin to lift the slowly beating organ out of its chest. As the final strand of connecting tissue snaps like taut rubber band,\n"
                    "the creature lets out one final howl as its body turns a ghostly white and soldifies into a chalky white dust, blowing away from a slight breeze. The swamp comes alive again, somehow with more fervor than before.\n"
                    "You stand there victorious, the dagger still gripped tightly in your hand, now no longer glowing. The Black Heart slowly beats in your other hand. It's not long before you start to hear it - a low whisper in your mind.\n"
                    "You lift the Black Heart up to your face and listen. Promises of power, strength, and abilities beyond your wildest dreams manifest in your mind. Quickly, you stow the heart away in your pocket, silencing the whispers.\n"
                    "Suddenly, a Gate manifests before you, revealing the interior of the Temple beyond. Grateful to be out of this place, you step into the portal.\n\n";
            
            inventory.push_back(the_swamplands_key);
            tsl_completed = true;
            temple_second_room(true);
            break;

        default:
            try_again();
            the_hunt();
            break;
    }
}