// File containing functions for The Oasis passage
#include <iostream>
#include <string>
#include <conio.h>
#include "The Oasis.hpp"
#include "Functions.hpp"
#include "Journal Entries.hpp"
#include "Trackers.hpp"
#include "Items.hpp"

using namespace std;

bool middle_path_intro = false;
bool explored_clearing = false;
bool pond_hint = false;

void the_oasis_text()
{
    interlude();
    system("cls");
    print_line();
    cout << "You stumble out of the portal and quickly catch your balance as it closes behind you. Standing up straight, you take in your surroundings.\n"
            "You find yourself in a hot and humid jungle, large trees and exotic-looking plants surround you on all sides. The sun burns brightly through the canopy of trees.\n"
            "Notably, this jungle is very different from the one you found the Temple in, as this is much more humid and lively as birds chirp and insects buzz all around you.\n"
            "As a result, this jungle has a much less somber atmosphere and the foliage is noticeably lighter green in color compared to the one you found the Temple in.\n"
            "Although the jungle is dense and the undergrowth thick, you're able to make out three pathways in front of you - one to your left, one directly ahead, and another to your right.\n"
            "Looking behind you, you see a carved stone archway with no active portal. You look back towards the three pathways in front of you.\n";
    the_oasis(false);
}

void the_oasis(bool show_interlude=false)
{
    if(show_interlude)
    {
        interlude();
        system("cls");
    }
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Explore the left path\n";
    cout << "B. Explore the middle path\n";
    cout << "C. Explore the right path\n";
    print_line();
    char choice = getch();
    choice = tolower(choice);
    cout << choice << "\n";

    print_line();
    switch(choice)
    {
        case 'a':
            if(explored_clearing)
            {
                cout << "You look down the dark tunnel, and that familiar uneasy feeling bubbles like a noxious pit in your stomach. Whatever that clearing was, you want nothing to do with it.\n"
                        "You look back to the options in front of you.\n";
                the_oasis(false);
            }
            else
            {
                small_clearing();
            }
            break;
            
        case 'b':
            if(!middle_path_intro)
            {
                cout << "You decide to explore the middle path.\n"
                        "Peering through the trees, you can just make out a beautiful waterfall in the distance, a small rainbow reflected in the spray.\n"
                        "You follow the path through the jungle until you stand on the shore of the small pond the waterfall pours into. You stare at the beauty all around you.\n"
                        "The roar of the waterfall provides some natural white noise as you slowly close your eyes and simply soak in the moment. It's a nice reprieve from what you've been through lately.\n"
                        "Several moments later, after taking one final deep breath, you finally open your eyes and return to your previous mindset: looking for what you need.\n";
                middle_path_intro = true;
            }
            cout << "You stand on the shoreline of the small pond the roaring waterfall pours into. To your left, you see an unusually neatly stacked pile of rocks set against a cliff wall next to the waterfall,\n"
                    "to your left lies a log overgrown with mushrooms and moss, but appears hollow inside, and directly ahead of you lies the waterfall.\n";
            pond_options(true);
            break;

        case 'c':
            cout << "You decide to explore the right path.\n"
                    "You go through the trees until you reach the foot of a hill. After a brief climb, you find yourself at the top of an enormous cliff looking out over a misty valley with miles and miles of jungle all around.\n"
                    "Stricken by the beauty of it all, you approach the edge of the cliff and slowly, carefully get to your knees and look over the edge of the cliff. Looking down, you can see a small waterfall\n"
                    "some meters down coming out of the side of the cliff. You slowly start to bring yourself back up when you notice something in your peripheral vision. You snap your head in the direction of the large moving\n"
                    "shadow and see a giant condor diving toward you with its massive claws outstretched. You clumsily turn and try to dive back towards the jungle trees, but are caught up in the huge talons of the massive bird.\n"
                    "Terrified, you strike at feet of the beast, trying desperately to stab at it with the dagger from the temple. You stab and stab, but to no avail, the scutum of the massive bird is just too thick.\n"
                    "With one final desperate try, you bring down the dagger hard, but the bird suddenly dives and you drop the dagger. You watch as it falls into the jungle below, staring in shock as the trees past by blindingly fast.\n"
                    "The bird soon slows its descent and unceremoniously drops you into a huge collection of branches and dried leaves. You quickly get back up as the bird caws once and leaves. You grab your shoulder,\n"
                    "gently massaging it. Pain flares as you try to move it, the bird must have dislocated it when it dropped you. As you catch your breath, something moves in the shadows to your right. Your quickly look in that\n"
                    "direction and see a fuzzy shape move in the darkness. Startled, you turn to face it and slowly start to back away. You hear some muffled crooning sounds before the fuzzy shapes rights itself and steps into the light.\n"
                    "It's a giant baby condor, still flightless and looking right at you with hunger in its eyes. You move slowly away from it, trying to look for an exit, well aware of being the young bird's intended dinner.\n"
                    "The baby understands this too and charges at you. With speed you didn't know you had, you deftly dive out of the way, but land painfully on some branches. Gritting your teeth against the pain, you start to stand up,\n"
                    "but the baby is faster and knocks you into the wall of the nest. Pain flares in your ribs as you hear a sickening crack and you scream. The baby condor wastes no time and bites down hard on your midsection.\n"
                    "Your abdomen tears open as the baby condor pulls away, ripping you open even further. You only have a moment to process your death as your vision fades and you hear the baby condor crooning before coming back in for another bite.\n";
            
            cout << "\n\nEnding 16: Baby Food\n";
            print_line();
            retry(&the_oasis, true);
            break;

        default:
            try_again();
            the_oasis(false);
    }
}

void small_clearing()
{
    interlude();
    system("cls");
    print_line();
    cout << "You decide to explore the left path.\n"
            "You look towards the left path. It lays in darkness, with an overarching tunnel of branches that goes deeper into the jungle. You hesitate for just a moment, but step forward into the tunnel.\n"
            "After a short walk, you find a small clearing carpeted by thick moss and illuminated brightly by a ray of sunshine peeking through the canopy. Small flowers line the circumference of the area.\n"
            "Their colorful petals gently dancing in a small breeze. Despite the welcoming atmosphere, a creeping feeling of unease slinks up your spine. You notice small particles floating through the air,\n"
            "dancing like the fae in fairytales. You hesitate, unsure of what to do.\n";

    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Proceed into the clearing\n";
    cout << "B. Go back through the tunnel\n";
    print_line();
    char choice = getch();
    choice = tolower(choice);
    cout << choice << "\n";

    print_line();
    switch(choice)
    {
        case 'a':
            cout << "You head deeper into the clearing, curious about the flowers. You head up to one to look closer. Several filaments reach out from the center of the flower, tipped red with a crimson hue.\n"
                    "After a short moment, the flower suddenly blasts your face full of pollen, causing you to cough and sneeze as your eyes begin to water. After regaining your breath and wiping at your eyes,\n"
                    "you notice something at the far end of the clearing - an ancient-looking stone shrine with a golden idol sitting in the center of it. Could that be what you needed to retrieve from here?\n"
                    "After only a brief hesitation, you briskly walk towards the shrine, eager to be done with this world. As you cross the center of the clearing, you hear something unusual, a shifting sound coming from directly beneath you.\n"
                    "As soon as you look down, the floor of the clearing opens up beneath you, revealing itself to be large, mossy leaves that are now retracting towards the edges of the small glade.\n"
                    "Your breath catches in your throat as you fall into a large nest of thorny vines. The vines immediately poke into your skin through your clothing, piercing deep enough to draw blood.\n"
                    "You thrash and thrash, trying to free yourself from the bramble prison, but only succeed in getting yourself even more tangled up. Finally, your strength wanes and you remain there,\n"
                    "suspended in the air as you bleed from several shallow cuts. As you catch your breath, you watch as a drop of your blood travels down the length of a vine, slowly making its way towards the bottom.\n"
                    "It is then you notice something in the distance, beyond the vine. As your vision refocuses on the object, your gut fills with horror as you stare at the desiccated corpse of a small furry mammal.\n"
                    "You look around some more and notice even more corpses hung up in the vines, all dry and brittle, resembling large, horrific raisins. All except one, a larger animal, resembling a panther,\n"
                    "taking in weak, shuddering breaths as it lays suspended in a cocoon of vines. Something stands out about this one, however. You notice a large vine attached to the chest of the animal,\n"
                    "with a splayed-open flower bulb firmly connected. You watch in growing horror as the vine sucks at the chest of the animal, a low slurping noise being heard even from your distance.\n"
                    "It is then that, unbeknownst to you, the drop of blood you watched earlier has finally made its way to the bottom of the shaft, slowing just before being collected in an organic cup-like orifice\n"
                    "lined with several small holes. An slick, wet sound emanates loudly from the bottom of the shaft as a similar vine with an large flower containing several long, sharp filaments in its center snakes\n"
                    "its way up the shaft towards you. You scream and writhe in your prison, trying desperately to reach for the dagger on your person, but unable to grasp it due to the strong vines holding you up like a ragdoll.\n"
                    "You kick and pull, but the vines hold fast, digging their thorns even deeper into your skin. You can do nothing but watch helplessly as the flower finally reaches you, its filaments tentacle-like,\n"
                    "squirming and brushing over your form, looking for a place to settle in. During all this, you continue to writhe, but the vines pull tighter, restricting your movements, allowing the flower to search\n"
                    "your body with relative ease. When it comes to your chest, it pauses, the movement of its filaments slowing as it places them lengthwise against your rapidly beating heart. Then, the filaments straighten out,\n"
                    "poised above your chest, and pierce through your skin. The pain is immense as the flower brings itself closer to your torso. It is then you feel them. The filaments fan out throughout your body,\n"
                    "squirming through your flesh like parasitic worms, searching. And they find what they're looking for. Your heartbeat slows as you feel the invasive tendrils wrap around and puncture your organ.\n"
                    "It is then you scream. You scream the scream of a soul damned to an eternity of suffering. And suffer you will, as the flower begins to drink.\n";
            
            cout << "\n\nEnding 14: Punctured\n";
                    print_line();
                    retry(&the_oasis, true);
            break;
        
        case 'b':
            cout << "You decide to listen to your gut and turn around, taking a small step towards the tunnel. It is then that you hear a low rumble, almost as if the world itself was sighing in disappointment.\n"
                    "Curious, you turn back towards the clearing, and your breath catches in your throat as you now see that all the flowers lining the perimeter of the clearing have shifted to face your direction.\n"
                    "Your eyes widen in horror and the uneasy feeling grows stronger as it is joined by the feeling of being watched. You quickly turn away from the accursed clearing and hurry back down the tunnel.\n";
            explored_clearing = true;
            the_oasis(true);
            break;

        default:
            try_again();
            small_clearing();
    }
}

void pond_options(bool show_interlude=false)
{
    if(show_interlude)
    {
        interlude();
        system("cls");
    }
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
    char choice = getch();
    choice = tolower(choice);
    cout << choice << "\n";

    print_line();
    switch (choice)
    {
    case 'a':
        if(!pond_hint)
        {
            cout << "You decide to investigate the pile of rocks next to the waterfall.\n"
                    "You go up to the pile of rocks and after briefly looking them over, you carefully clear the stack until you find two folded up pieces of paper.\n"
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
        pond_options(false);
        break;
    
    case 'b':
        cout << "You decide to investigate the overgrown log.\n"
                "You approach the log and look it over. It is covered in moss and mushrooms, a few strange-looking insects crawl slowly over the surface of the moss.\n"
                "Bending down, you brush away some moss hanging over the entrance to the hollow center of the log. Peering in, you don't see much besides darkness.\n"
                "Then, as your eyes finally adjust, you make out a furry shape stuck to the inside wall of the log. Getting closer, you realize it's a lump of mold.\n"
                "Suddenly, the mold violently expels spores towards your face. Instantly, your eyes burn and your breath catches as you breathe it in.\n"
                "Your lungs itch and your vision grows black as your run your hands over them, feeling moldy fuzz grow rapidly over the surface of them.\n"
                "Pain erupts from your lungs and you cough up blood, your skin becomes horribly itchy, and your eyes feel like they're on fire.\n"
                "The pain and itching is so terrible, you scratch deeply, trying to be rid of the horrid itching. You stumble around, blind, until you eventually trip over the log itself.\n"
                "Your body erupts in more pain as it hits the hard rock, but you're too busy clawing your eyes out. Blood pours from the empty sockets until you feel the mold invade them as well.\n"
                "You continue to scratch, your motions becoming slowed as your consciousness finally fades away and the mold consumes the remainder of your body.\n";

        cout << "\n\nEnding 15: Rot Mk. II\n";
        print_line();
        retry(&pond_options, true);
        break;
    
    case 'c':
        if(pond_hint)
        {
            cout << "You decide to go through the waterfall.\n"
                    "You remember what the piece of paper you found stated: that the tree with the special leaves can be found in a cave beyond the waterfall.\n"
                    "You pull your jacket over your head as you quickly go through the waterfall in a futile attempt to keep from getting soaked.\n"
                    "You shake and wring out what water you can from your clothes before taking in your surroundings, you are in a small cave with a tunnel heading even deeper into the rock wall.\n"
                    "Hesitating only slightly, you head into the tunnel. After a brief walk you find yourself in a vast open-ceiling cave with a huge beautiful tree growing in the middle, bathed in the sunlight\n"
                    "pouring through an opening in the roof of the cave. Massive roots penetrate the floor of the cave and small flowers can be seen around the base of the tree. A collage of colorful lights dance around on\n"
                    "the cave walls, giving the whole environment a fantastical feel. You look to the source of the dancing lights - reflections off the leaves of the giant tree. Curious, you make your way to the base of the giant tree.\n"
                    "Looking up, you're surprised to see a staircase going around the circumference of the tree leading all the way to the top. After climbing it for several minutes, you come to a small platform at the\n"
                    "top of the tree where all the branches meet. From your central position, you can see several structures resembling handrails on each of the major branches of the tree. You also see a large\n"
                    "basket nearby filled with tight, strongly woven rope. Putting two and two together, you tie the rope around yourself and slowly make your way out on one of the larger branches of the tree.\n"
                    "After going several meters, you tie one end of the rope securely to the handrail structure and make your way out onto a smaller branch off the main branch you're on. Taking cautious steps,\n"
                    "you eventually reach a part of the branch close to a cluster of flowers and leaves. Reaching out after having tied yourself off yet again to a sturdy-looking branch on the opposite side,\n"
                    "you just manage to grab a leaf and pull it off. You quickly pull yourself back in and head back to the handrail structure before finally taking a moment to look closer at your prize.\n"
                    "The leaf shines brilliantly in the light, with a slight rainbow iridesence, and is somewhat transparent. Squinting, you bring the leaf closer to your face and peer through it.\n"
                    "The image is somewhat blurred, but you can see interesting waves in the air, as if seeing vibrations from noise. You look towards the tunnel leading out of the cave to the back of the waterfall.\n"
                    "The waves you see through the leaf appear to be emanating from that spot. You bring the leaf back down and the waves disappear. Interested, you complete your journey off the branch and back onto\n"
                    "the sturdy platform in the center of the tree. Taking the leaf back out of your pocket, you once again bring it to your face and peer through it. This time, instead of soundwaves, you see the\n"
                    "various temperatures of objects within the surrounding area. Bringing the leaf down to your hand, you wonder if you can see through your skin with the leaf.\n"
                    "Remarkably, you can. You can see the fuzzy outline of your bones through the translucent flesh of the leaf. Flexing your digits, you watch in fascination as you can see your finger bones move.\n"
                    "Pocketing the leaf, you head back down the tree, through the waterfall and back through the portal.\n";
            inventory.push_back(the_oasis_key);
            oasis_completed = true;
            temple_second_room(true);
        }
        else
        {
            cout << "You decide to go back through the jungle.\n"
                    "Turning around, you head back through the trees.\n";
            the_oasis(true);
        }
        break;

    case 'd':
        if(pond_hint)
        {
            cout << "You decide to go back through the jungle.\n"
                    "Turning around, you head back through the trees.\n";
            the_oasis(true);
        }
        else
        {
            try_again();
            retry(&pond_options, false);    
        }
        break;
    
    default:
        try_again();
        retry(&pond_options, false);
        break;
    }
}