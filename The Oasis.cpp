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
bool pond_hint = false;

void the_oasis_text()
{
    print_line();
    cout << "You stumble out of the portal and quickly catch your balance as it closes behind you. Standing up straight, you take in your surroundings.\n"
            "You find yourself in a hot and humid jungle, large trees and exotic-looking plants surround you on all sides. The sun burns brightly through the canopy of trees.\n"
            "Notably, this jungle is very different from the one you found the temple in, as this is much more humid and lively as birds chirp and insects buzz all around you.\n"
            "As a result, this jungle has a much less somber atmosphere and the foliage is noticeably lighter green in color compared to the one you found the temple in.\n"
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
    choice = tolower(choice);

    switch(choice)
    {
        case 'a':
            print_line();
            cout << "You decide to explore the left path.\n"
                    "You look towards the left path. It lays in darkness, an overarching tunnel of branches that goes deeper into the jungle. You hesitate for just a moment, but step forward into the tunnel.\n"
                    "After several minutes, you find yourself in a small clearing. The floor of the clearing is littered with strange-looking twigs. Curious, you lean down and pick up a few of the twigs, rolling them between your fingers.\n"
                    "You inspect one of the twigs closely, small, white and perforated. Very brittle as well, you note as it snaps easily between your fingers. It is then you notice the marrow in the center of the twig.\n"
                    "These aren't twigs, they're bones. Your blood freezes as you drop the bones you're holding and turn to run. As you turn, a low growl rumbles all around you, and steadily grows louder.\n"
                    "You quickly turn to look at the entrance to the clearing, but you're met with a close-knit, intertwined collection of branches blocking the entrance. You're trapped here. The rumble is incredibly loud now.\n"
                    "It is then you hear wooden creaks as several branches are shifted away from the 'wall' of the clearing opposite the entrance, and a hideous gaping maw is shown in the space left behind.\n"
                    "Your heart gallops in your chest as the humid breath of the huge mouth hits you and several large tentacle-like tongues slowly wind their way up through the gullet of the thing in the branches.\n"
                    "You desperately turn back to the entrance of the clearing and tear at the branches blocking your way, slivers and cuts be damned. Remembering the dagger, you bring it out and start cutting at the branches\n"
                    "only for you to clumsily drop it in the nest of bones. Stooping to search, you see the tongues move closer and decide there's no time as you stand back up and resume your escape attempt.\n"
                    "You snap away as many of the branches as you can, but see through the spaces between them that they are quickly replaced with more as the entrance is further barricaded,\n"
                    "cutting off the dim light from the tunnel in the process and hopelessly sealing you in. The tongues slither ever closer, taking their time to savor the moment - playing with their prey.\n"
                    "You feel the breath of the thing grow in anticipation as one of the tongues finally wraps itself around your ankle, another around your waist. As a final futile attempt at escape,\n"
                    "you plunge your arm into the interwoven barricade of branches and grab one of them. Slowly, the tongue grows taut as the thing struggles to pull you in.\n"
                    "It pulls and pulls, but you hold fast, pulling yourself away whenever the thing grows tired. Finally impatient with this tug-of-war, the thing's final tongue wraps around the shoulder of the arm planted in the\n"
                    "web of branches and with great force, pulls. You hear a sickening pop as your shoulder dislocates and you scream in pain, but the thing is not done. It pulls even harder and harder, the fabric of your clothes\n"
                    "tearing at the seams. The pain is unbearable. And with a final tug, the things pulls you free of the branches as you lose your grip, several pieces of skin left behind on sharp thorns within.\n"
                    "Tears flow freely now as your limp arm drags behind you and you close your eyes in defeat as you enter the warm mouth of the thing.\n";
            
            cout << "\n\nEnding 14: Eaten\n";
            print_line();
            retry(&the_oasis);
            break;
            
        case 'b':
            print_line();
            if(!middle_path_intro)
            {
                cout << "You decide to explore the middle path.\n"
                        "Peering through the trees, you can just make out a beautiful waterfall in the distance, a small rainbow reflected in the spray.\n"
                        "You follow the path through the jungle until you stand on the shore of the small pond the waterfall pours into. You stare at the beauty all around you. \n"
                        "The roar of the waterfall provides some natural white noise as you slowly close your eyes and simply soak in the moment. It's a nice reprieve from what you've been through lately.\n"
                        "Several moments later, after taking one final deep breath, you finally open your eyes and return to your previous mindset: looking for what you need.\n";
                middle_path_intro = true;
            }
            cout << "You stand on the shoreline of the small pond the roaring waterfall pours into. To your left, you see an unusually neatly stacked pile of rocks set against a cliff wall next to the waterfall,\n"
                    "to your left lies a log overgrown with mushrooms and moss, but appears hollow inside, and directly ahead of you lies the waterfall.\n";
            pond_options();
            break;

        case 'c':
            print_line();
            cout << "You decide to explore the right path.\n"
                    "You go through the trees until you reach the foot of a hill. After a brief climb, you find yourself at the top of an enormous cliff looking out over a misty valley with miles and miles of jungle\n"
                    "all around. Stricken by the beauty of it all, you approach the edge of the cliff and slowly, carefully get to your knees and look over the edge of the cliff. Looking down, you can see a small waterfall\n"
                    "some meters down coming out of the side of the cliff. You slowly start to bring yourself back up when you notice something in your peripheral vision. You snap your head in the direction of the large moving\n"
                    "shadow and see a giant condor diving toward you with its massive claws outstretched. You clumsily turn and try to dive back towards the jungle trees, but are caught up in the huge talons of the massive bird\n"
                    "mid-dive. Terrified, you strike at feet of the beast, trying desperately to stab at it with the dagger from the temple. You stab and stab, but to no avail, the scutum of the massive bird is just too thick.\n"
                    "With one final desperate try, you bring down the dagger hard, but the bird suddenly dives and you drop the dagger. You watch as it falls into the jungle below. You stare as the trees past below you blindingly\n"
                    "fast, but soon the bird slows its descent and unceremoniously drops you into a huge collection of branches and dried leaves. You slowly get back up as the bird caws once and leaves. You grab your shoulder,\n"
                    "gently pressing on it. Pain flares as you try to move it, the bird must have dislocated it when it dropped you. As you catch your breath, something moves in the shadows to your right. Your quickly look in that\n"
                    "direction and see a fuzzy shape move in the darkness. Startled, you turn to face it and slowly start to back away. You hear some muffled crooning sounds before the fuzzy shapes rights itself and steps into the light.\n"
                    "It's a giant baby condor, still flightless and looking right at you with hungry intent. You move slowly away from it, try to look for an exit, well aware of being the young bird's intended dinner. The baby understands\n"
                    "this too, and suddenly charges at you. With speed you didn't know you had, you deftly dive out of the way, but land painfully on some branches. Gritting your teeth against the pain, you start to stand up, but the\n"
                    "baby is faster and knocks you into the wall of the nest. Pain flares in your ribs as you hear a sickening crack and you scream. The baby condor wastes no time and bites down on your midsection, hard. Your abdomen crunches\n"
                    "and is torn open as the baby condor pulls away and eats its meal. You only have a moment to process your death as your vision fades and you hear the baby condor crooning before coming back in for another bite.\n";
            
            cout << "\n\nEnding 16: Baby Food\n";
            print_line();
            retry(&the_oasis);
            break;

        default:
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
    if(pond_hint)
    {
        cout << "C. Go through the waterfall\n";
        cout << "D. Go back\n";
    }
    else
    {
        cout << "C. Go back\n";
    }
    print_line();
    cin >> choice;
    choice = tolower(choice);

    switch (choice)
    {
    case 'a':
        print_line();
        if(!pond_hint)
        {
            cout << "You decide to investigate the pile of rocks next to the waterfall.\n"
                    "You go up to the pile of rocks and after briefly looking them over, you carefully clear the stack until you find a two folded up pieces of paper.\n"
                    "After unfolding one of them, you read:\n\n";
            cout << journal_entry_5;
            journals.push_back(journal_entry_5);
            cout << "Folding that back up, you unfold the other and read:\n\n";
            cout << hint_4;
            cout << "For a long moment, you stare at the words of a dying man, processing what you just read. But you eventually fold the paper back up and put it in your pocket.\n"
                    "You then head back to the shoreline of the pond, the roar of the waterfall signalling your return.\n";
            pond_hint = true;
        }
        else
        {
            cout << "You look to the now dismantled pile of rocks. Besides the papers you found, there was nothing helpful there. You look back to the shoreline.\n";
        }
        pond_options();
        break;
    
    case 'b':
        print_line();
        cout << "You decide to investigate the overgrown log.\n"
                "You approach the log and look it over. It is covered in moss and mushrooms, a few strange-looking insects crawl slowly over the surface of the moss.\n"
                "Bending down, you brush away some moss hanging over the entrance to the hollow center of the log. Peering in, you don't see much besides darkness.\n"
                "Then, as your eyes finally adjust, you make out a furry shape stuck to inside wall of the log. Getting closer, you realize it's a lump of mold.\n"
                "Suddenly, the mold violently expels spores towards your face. Instantly, your eyes burn and your breath catches as you breathe it in.\n"
                "Your lungs itch and your vision grows black as your run your hands over them, feeling hair grow rapidly over the surface of them.\n"
                "Pain erupts from your lungs and you cough up blood, your skin becomes horribly itchy, and your eyes feel like they're on fire.\n"
                "The pain and itching is so terrible, you scratch deeply, trying to be rid of the horrid itching. You stumble around, blind, until you eventually trip over the log itself.\n"
                "Your body erupts in more pain as it hits the hard rock, but you're too busy clawing your eyes out. Blood pours from the empty sockets until you feel the mold invade them as well.\n"
                "You continue to scratch, your motions becoming slowed as your consciousness finally fades away and the mold consumes the remainder of your body.\n";

        cout << "\n\nEnding 15: Rot Mk. II\n";
        print_line();
        retry(&pond_options);
        break;
    
    case 'c':
        print_line();
        if(pond_hint)
        {
            cout << "You decide to go through the waterfall.\n"
                    "You remember what the piece of paper you found stated: that the tree with the special leaves can be found in a cave beyond the waterfall.\n"
                    "You pull your jacket over your head as you quickly go through the waterfall in a futile attempt to keep from getting soaked.\n"
                    "You shake and wring out what water you can from your clothes before taking in your surroundings, you are in a small cave with a tunnel heading even deeper into the rock wall.\n"
                    "Hesitating only slightly, you head into the tunnel. After a brief walk you find yourself in a vast open-ceiling cave with a huge beautiful tree growing in the middle, bathed in the sunlight\n"
                    "pouring through the opening of the cave. Massive roots penetrate the floor of the cave and small flowers can be seen around the base of the tree. A collage of colorful lights dance around on\n"
                    "the walls of the cave. You look to the source of the dancing lights - reflections off the leaves of the giant tree. Curious, you make your way to the base of the giant tree. Looking up,\n"
                    "you're surprised to see a staircase going around the circumference of the tree leading all the way to the top. After climbing it for several minutes, you come to a small platform at the\n"
                    "top of the tree where all the branches meet. From your central position, you can see several structures resembling handrails on each of the major branches of the tree. You also see a large\n"
                    "basket nearby filled with tight, strongly woven rope. Putting two and two together, you tie the rope around yourself and slowly make your way out on one of the larger branches of the tree.\n"
                    "After going several meters, you tie one end of the rope securely to the handrail structure and make your way out onto a smaller branch off the main branch you're on. Taking cautious steps,\n"
                    "you eventually reach a part of the branch close to a cluster of flowers and leaves. Reaching out after having tied yourself off yet again to a sturdy-looking branch on the opposite side,\n"
                    "you just manage to grab a leaf and pull it off. You quickly pull yourself back in and head back to the handrail structure before finally taking a moment to look closer at your prize.\n"
                    "The leaf shines brilliantly in the light, with a slight rainbow iridesence, and is somewhat transparent from a distance. Squinting, you bring the leaf closer to your face and peer through it.\n"
                    "The image is somewhat blurred, but you can see interesting waves in the air, as if seeing vibrations from noise. You look towards the tunnel leading out of the cave to the back of the waterfall.\n"
                    "The waves you see through the leaf appear to be emanating from that spot. You bring the leaf back down and the waves disappear. Interested, you complete your journey off the branch and back onto\n"
                    "the sturdy platform in the center of the tree. Taking the leaf back out of your pocket, you once again bring it to your face and peer through it. This time, instead of soundwaves, you see the\n"
                    "various temperatures of objects within the surrounding area. Bringing the leaf down to your hand, you wonder if you can see through your skin with the leaf.\n"
                    "Remarkably, you can. You can see the fuzzy outline of your bones through the translucent flesh of the leaf. Flexing your digits, you see your finger bones move as well.\n"
                    "Pocketing the leaf, you head back down the tree, through the waterfall and back through the portal.\n";
            inventory.push_back(the_oasis_key);
            oasis_completed = true;
            temple_second_room();
        }
        else
        {
            cout << "You decide to go back through the jungle.\n"
                    "Turning around, you head back through the trees.\n";
            the_oasis();
        }
        break;

    case 'd':
        print_line();
        if(pond_hint)
        {
            cout << "You decide to go back through the jungle.\n"
                    "Turning around, you head back through the trees.\n";
            the_oasis();
        }
        else
        {
            try_again();
            retry(&pond_options);    
        }
        break;
    
    default:
        try_again();
        retry(&pond_options);
        break;
    }
}