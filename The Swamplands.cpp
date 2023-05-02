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
bool explored_islands = false;
bool hunt_start = false;
bool crab = false;

// Revisit areas here to find ways to kill BH possessor and obtain Black Heart
// Include timed-events
void the_swamplands_text()
{
    print_line();
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
            print_line();
            cout << "You look toward the tall grasslands, but remember that you didn't find anything there. You look back to the options before you.\n";
            the_swamplands();
        }
        else
        {
            print_line();
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
        print_line();
        cout << "You decide to explore the cluster of small islands.\n"
                "Getting into the boat, you point it in the direction of the cluster of islands and begin to paddle your way there. Unlike the other areas, this area is further away.\n"
                "After paddling for a long while, you finally arrive at the first of the islands. A dense fog has collected around the islands, making it hard to see in particular areas.\n"
                "From what you can make out, it seems as though there are two areas that seem to be worth exploring - a large island with a collection of large boulders in the middle of it and another area\n"
                "filled with several broken and rotting wooden structures that may have been a village at some point in the past.\n";
        islands();
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
        print_line();
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
        print_line();
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
        print_line();
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
        print_line();
        cout << "You decide to stay the course and head further into the swamp, away from the darker part of it.\n"
                "Keeping the boat going at a steady pace, you maneuver away from the darker part of the forest and continue into the swamp. As you head deeper into the swamp, you notice the trees grow noticeably thicker\n"
                "and more densely crowded. Some time later, the boat inevitably gets stuck on a large cluster of roots. Balancing carefully, you move to dislodge the boat from the cluster of roots. During the process,\n"
                "you notice the swamp grow eeriely silent, void of the buzzing of insects and croaking of frogs. In fact, it is so silent that your breathing sounds amplified. Unintentionally, your heartrate speeds up\n"
                "and you start to feel anxious. Somehow, the silence only deepens and your stomach twists in dread and you just know something is watching you. Slowly, so as to not draw suspicion, you continue to work\n"
                "to dislodge the boat from the roots, all the while listening out for something... anything that will break the deafening silence and stealthily looking around and keeping an eye on your periphery. Finally,\n"
                "after a long moment, you hear the natural sounds of the swamp return just as you finish dislodging the boat. Feeling your dread evaporate, you stand up to your full height and look around, but see nothing\n"
                "out of the ordinary. With a shuddering breath, you return to paddling the boat further into the swamp. After some time, you come across an interesting sight: a decrepit house on stilts standing above the\n"
                "water of the swamp, with a small dock leading up to the raised porch of the house. Climbing up the short stairs, you stop to knock, but immediately hear a strange sound - a muffled rhythmic thudding noise,\n"
                "coming from the other side of the door. Curious, you put your ear up to the door and after a few seconds you can hear it come from the other side. Slowly, you push open the door, careful to minimize noise.\n"
                "You then spy a large hole in the floor of the house several feet in front of you. In the hole, you spy a swirling black shape. You see expose muscles fibers shining like black licorice moving in a slow,\n"
                "serpentine fashion around an exposed center. And in that very center lies a black pulsating heart. A heart with a slow, muted heartbeat every few seconds. You slowly approach the hole, watching the exposed\n"
                "muscle fibers shift and weave around hypnotically. As you draw near, you become dimly aware of the lack of noise that has once again pervaded the atmosphere. The silence grows as you draw nearer, the only thing\n"
                "that you can still hear is the beating of the heart. You are now mere inches away from the hole, reaching toward the pulsating organ with enraptured fascination before the loose floorboard beneath you suddenly\n"
                "way and you almost fall completely into the hole before catching the sides, bringing you to a complete halt. Immediately, the black mass directly below you rapidly transforms into a large teeth-lined gaping maw.\n"
                "Shocked, you scream as you push yourself up from the hole just in time before a mass of black explodes straight up past you through the ceiling, emitting an unearthly raspy screech all the while. Adrenaline floods\n"
                "your veins as you turn and run back through the door, down the short stairs and practically dive into the boat, kicking off the small dock and paddling as fast as you can. As you paddle away, you can hear multiple\n"
                "cracks and snaps from all different directions above you as small pieces of wood and leaves ran down from the canopy. Pushing hard on the paddle, a small roar grows louder behind you until it is almost deafening.\n"
                "It is a loud, reverberating roar signalling not only the awakening of a monster, but the start of its hunt. And you are its prey.\n"; // First encounter with Black Heart possessor
        hunt_start = true;
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
    cout << "A. Explore the large island with several large boulders\n";
    cout << "B. Explore the abandoned village\n";
    cout << "C. Turn around and head back to the dock\n";
    cin >> choice;
    choice = tolower(choice);

    switch (choice)
    {
    case 'a':
        print_line();
        cout << "You decide to explore the large island with the pile of large boulders on it.\n"
                "Pointing your boat in the direction of the island, you paddle your way over until you breach the shore and stop. Getting out, you secure the boat and approach the rocks.\n"
                "Looking through them, you don't seem to find anything of interest and get up to leave until you hear something. A noise. Some kind of faint clicking, coming from in-between two rocks.\n"
                "Could it be a device of some kind? Something that could help you? Would it be worth it to find out?\n";
        rock_island();
        break;
    
    case 'b':
        print_line();
        cout << "You decide to explore the abandoned village.\n"
                "You paddle your way towards the broken and rotting wooden structures and tie off the boat on a small, equally decrepit but still functional dock nearby.\n"
                "Getting off the boat, you are immediately hit with a strange feeling of being watched. You glance around quickly, but see nothing. Creeped out a bit, you hesitantly make your way towards the village.\n"
                "Once there, you start to methodically search through the buildings, looking for anything that might help you. While searching the third house, you hear a strange creaking noise outside, like a wooden\n"
                "branch swaying in a strong wind. That doesn't make any sense however, since there is no wind here at all. You make your way to the doorway and look around outside, listening for the source of the creaking\n"
                "noise. The creaking noise is surprisingly absent however, and you don't see anything out of the ordinary either. On edge, you close the rotting door and turn around to begin searching again but hear the\n"
                "creaking noise start up again. Turning back around and throwing the door open, you step outside and immediately scream, falling back into the house. Outside, you see a wooden statue with a carved mask-like\n"
                "face and one long twisted tree limb making up its body. It looms several feet away from the doorway, unmoving. Slowly, you get back up and approach it. Completely still, the statue does not move at all.\n"
                "You take a closer look at its face and can make out the fine detail in the mask-like carving of it, with a large frowning face and hollowed-out eyes, it reminds you of a Greek tragedy mask. Quickly looking\n"
                "side to side, you don't see anyone that could have moved the statue here. Apprehensively, you back into the doorway of the building while still looking at the statue before you. After one last long look at the\n"
                "statue and a quick look around the immediate area, you once again close the door. As soon as the door hits the frame, you hear the wooden creaking noise again, alongside multiple others around the house.\n"
                "Now terrified, you throw the door open, intent on running away, only to come face to face again with the wooden statue. You scream in surprise, as it face looms directly in front of you, its frown having\n"
                "somehow grown deeper. You stumble back from it and close the door again, moving a mostly-intact piece of furniture in front of it. It is then that loud pounding starts on the door, shaking the door in its frame.\n"
                "You can now hear the wooden creaking noise all around you, surrounding the house you're in. You quickly run around the perimeter of the room you're in, looking through the windows to see even more wooden statues,\n"
                "each with its own uniquely carved face standing outside. All the while the front door starts to break and you soon hear pounding on other walls of the house. You cower in the center of the room, unsure what to do.\n"
                "You cover your ears for a moment as the pounding all around you grows louder and close your eyes, taking a deep breath to try and calm yourself. You open your eyes again and scream as a carved face stares back at you,\n"
                "itself connected to a long, thick wooden branch poking in through the open window. You crawl backwards, never taking your eyes off the carved face. It doesn't move as you manuever around it and make your way to the door.\n"
                "The pounding has stopped now and you quickly turn to open the door, only to be greeted with the door having fallen off and the statue now completely blocking the exit, its carved face now having slinked around the fallen door,\n"
                "staring back at you. Angry, you take out the dagger and stab at the carved wooden face, striking it in one of the cheeks, only to feel a sharp pain reflected in your own cheek and blood pouring down your face. You press down on\n"
                "your new cut and back up, horrified. You start hyperventilating as you hear wooden creaking behind you and you quickly turn to see the one in the window has turned on its long neck to face you, its expression one of comedic joy.\n"
                "Your eyes flick between the two as you back up until your back hits a wall, keeping both of them in view. Behind you, you hear wood creaking just beyond the surface of the wall and a new pounding starts behind your back,\n"
                "vibrating your entire body with every hit. You slowly start to accept the reality of the situation and hopelessly fall to the floor. Tears well up in your eyes, but you refuse to blink or wipe them away as the pounding stops once\n"
                "you spy a bit of wooden mask-like face poking through a new hole in the wall above you, carved with a solemn, stoic expression. You eyes are burning now, the faces mere inches away, and you struggle hard to keep them open, but you can't.\n"
                "And taking a deep breath, clutching the now-useless dagger, you relent and close your eyes one final time. The wooden creaking and three very quiet voices whispering is the last thing you hear.\n";
        
        cout << "\n\nEnding 20: Totems\n";
        print_line();
        retry(&islands);
        break;

    case 'c':
        print_line();
        cout << "You turn the boat around and head back to the dock.\n";
        explored_islands = true;
        the_swamplands();
        break;

    default:
        try_again();
        islands();
        break;
    }

}
void rock_island()
{
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Reach between the rocks\n";
    cout << "B. Return to the boat\n";
    cin >> choice;
    choice = tolower(choice);

    switch (choice)
    {
    case 'a':
        print_line();
        cout << "Thinking it could be a device, you reach between the rocks and feel around, trying to find something that could be making the noise. It is then the clicking suddenly stops, and you, in turn, pause.\n"
                "You hold still for a moment, and just when you're about to pull your arm out, something grabs onto you. You scream and pull away, tearing a finger off in the process. Falling down, you clutch your\n"
                "bleeding hand, pinching the severed stump in an attempt to stop the bleeding. It is then the biggest boulder in the pile moves. Momentarily forgotten, you look away from your missing finger and look\n"
                "towards the moving rock. With growing horror, you watch as the 'rock' turns towards you and is revealed to be a giant crab, your missing finger still clutched in its giant claw. Bringing your finger\n"
                "towards its mouth, it slowly chews it. Then, with terrifying speed, it approaches you and in desperation, you crawl backwards away from it. You're not fast enough however, and the crab soon grabs your\n"
                "leg in its giant claw and pulls you closer. Kicking and hitting it with all your might, your soon stop as your fists start to bleed from impacts with the spikey shell of the crab. Resorting to only kicking,\n"
                "you desperately flail at the crab, which seems to not be affected by your hits at all, only reacting in an annoyed manner to them. The crab then grabs your other leg mid-kick with its other claw and gives it\n"
                "a hard squeeze. You cry out in pain as the pressure intensifies until you hear a sickening crack as your leg bone breaks, tears welling up in your eyes. The crab then drops both of your legs to the ground and\n"
                "steps towards you. Adrenaline takes over and you once again try to back up, your elbows now sloshing in the shallow swamp water. The crab is not done, however. It grabs you by the shoulder with one of its claws\n"
                "and drags you back towards the center of the island. Now crying, you turn your body and helplessly claw at the ground, your fingernails filling with clumps of dirt and some even breaking in the process.\n"
                "The crab drags you into a large divet in the ground and claws at your body, cutting and tearing open your skin everywhere. You defend as much as you can, but are helpless against the sharp and brutal onslaught.\n"
                "After several moments, you feel your strength leave you as your blood soaks the ground. Your limbs fall to your sides and you relent, letting the crab finish the job. Your head slumps into your chest and you take\n"
                "one final breath before your vision fades entirely to black.\n";
        
        cout << "\n\nEnding 19: Clawed\n";
        print_line();
        retry(&islands);
        break;
        
    case 'b':
        if(crab)
        {
            print_line();
            cout << "You look toward the island and shudder a bit as you see the boulder-like shell of the giant crab you saw there. You shake your head and turn back to the options before you.\n";
            islands();
        }
        else
        {
            print_line();
            cout << "You decide it would not be worth it to find out. You get up and return to the boat. The clicking noise increases in frequency, but you ignore it. Suddenly, the biggest rock in the pile gets up and turns towards you.\n"
                    "It's not a rock at all, but a giant crab. You watch as it clicks its mandibles together, reproducing the clicking noise you heard. You stare in shock for a moment before the crabs starts crawling rapidly towards you.\n"
                    "You turn and run, jumping into the boat and pushing off the shore, paddling as fast as you can. The crab soon reaches the shore and watches you for a moment before turning back around and settling back into its divet,\n"
                    "its shell blending in and looking just like a boulder. You watch in stunned fascination as you slow your paddling and your heartbeat. \"It's a good thing I didn't reach in-between those rocks\", you think as you paddle\n"
                    "back to the start of the paths.\n";
            crab = true;
            islands();
        }

    default:
        try_again();
        islands();
        break;
    }
        
}