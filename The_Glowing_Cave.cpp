// File containing functions for The Glowing Cave passage
#include<iostream>
#include<string>
#include "The_Glowing_Cave.hpp"
#include "Journal Entries.hpp"
#include "Functions.hpp"
#include "Trackers.hpp"
#include "Items.hpp"

using namespace std;

bool gc_explored_left_tunnel = false;
bool gc_explored_right_tunnel = false;
bool gc_explored_path = false;

bool attention_seeker = false;

void the_glowing_cave_text(){
    print_line();
    cout << "Bracing yourself, you close your eyes and take a step into the portal.\n"
            "However, you are met with an eerie silence, followed by a sudden feeling of moisture in the air.\n"
            "You open your eyes and are immediately met with the beautiful site of a large glowing fungi right in front of you.\n"
            "Awestruck, you slowly circle the giant mushroom as you drag your hand across the surface of its massive stem.\n"
            "It's about as big as a tree, with a soft turquoise light emanating from the gills and cap of the mushroom.\n"
            "Trails of the soft light are made where your fingers brush the stem before softly fading like a heat-sensitive coating.\n"
            "After a moment, you finally move your eyes away from the mesmerizing mushroom and scan your surroundings.\n"
            "You appear to be in a large cavern, surrounded by clusters of the strange glowing fungi scattered about the walls an floors of the cave.\n"
            "With the mushrooms providing the only light in the otherwise dark and dank cave, you slowly take a step forward.\n"
            "You accidentally step into a deep puddle you were trying to avoid and end up making a large splash sound that echoes a bit within the confines of the cave.\n"
            "You suddenly hear an odd shuffling noise. Unsettled, you slowly look up and can barely make out large shapes spread out across the ceiling of the underground chamber.\n"
            "Bats. Very large bats. You stand stock still, your shoe now completely soaked, but you dare not wake the flying mammals."
            "After the bat settles down, you quietly sigh in relief. Looking back toward the ground level of the cave, you see two tunnels branching off from the chamber you're in directly ahead of you.\n"
            "There is also another path on the opposite side of the wall, between some large mushrooms you see a well-tread path leading further into the cave.\n\n";
    
    the_glowing_cave();
}

void the_glowing_cave(){

    if(attention_seeker){
        print_line();
        cout << "You burst back into the chamber, the echoing screech of the monster coming out of the tunnel. You fall to your knees and gasp for breath, tears welling up in your eyes.\n"
                "Your arms are like jelly, and you struggle to not collapse onto the floor entirely and assume the fetal position.\n"
                "After several minutes, the screeching finally stops and the cave falls silent. You take some shaky breaths and push yourself into a sitting position, just letting yourself process what you just saw.\n"
                "After a while, you notice that the bats have gone, probably fled the chamber after the screeching started. You sigh loudly and stand back up. Well, you still have to find what you're looking for.\n";
    }

    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Explore the left tunnel\n";
    cout << "B. Explore the right tunnel\n";
    cout << "C. Explore the well-tread path\n";
    print_line();
    cin >> choice;
    if(choice == 'A' || choice == 'a'){
        print_line();
        if(gc_explored_left_tunnel && attention_seeker){
            cout << "No. There's no way you're going back there.\n";
            the_glowing_cave();
        }
        else if(gc_explored_left_tunnel){
            cout << "You've already tried that path.\n";
            the_glowing_cave();
        }
        else{
            cout << "You decide to explore the left tunnel.\n"
                    "After approaching the left tunnel, you lift your hand to brush away the faintly glowing pink moss swaying over the entrance and feel a damp breeze coming from the opening.\n"
                    "A muffled roaring noise accompanies the slight mist spraying from the entrance, giving you the image of rushing water. The mist gently dampens your face as if to verify your thoughts.\n"
                    "You take a cautious step into the tunnel.\n";
            
            gc_left_tunnel();
        }
    }
    else if(choice == 'B' || choice == 'b'){
        print_line();
        if(gc_explored_right_tunnel){
            cout << "You approach the right tunnel, lean your head in and listen. You can't hear any bats so you proceed further in.\n";

            gc_right_tunnel();
        }
        else{
            cout << "You decide to explore the right tunnel.\n"
                    "You walk up to the right tunnel, noticing that this tunnel is darker in comparison to the other options, but not enough to keep you from seeing.\n"
                    "The air here feels drier as well. In fact, it seems that the air from the chamber you're in is flowing out into the tunnel. Despite the fantastical and warm atmosphere of the cave so far,\n"
                    "you feel a sudden surge of trepidation staring into the dim tunnel, as if you were staring down the throat of a large leviathan about to swallow you whole.\n"
                    "Closing your eyes and taking a deep breath, you brace yourself and grip the handle of the dagger, the cold metal bringing you some degree of comfort.\n"
                    "After a while, you open your eyes and make your way down the tunnel.\n";
            
            gc_right_tunnel();
        }
    }
    else if(choice == 'C' || choice == 'c'){
        print_line();
        if(gc_explored_path){
            // To be filled in...
        }
        else{
            cout << "You decide to explore the well-tread path on the opposite side of the cavern.\n"
                    "You turn your back to the two tunnels and quietly make your way across the cave, careful not to make too much noise.\n"
                    "You approach the well-tread path stretching between the fluorescent fungi, smaller mushrooms growing on either side of the pathway, giving the whole thing a comforting feeling of familiarity,\n"
                    "despite the fact that this whole thing is entirely new to you. A small smile plays across your lips as you confidently walk down the path that so many others have tread upon before you.\n"
                    "Following in the footprints of the Worldwalkers.\n";
            
            gc_pathway_text();
        }
    }
    else{
        try_again();
        the_glowing_cave();
    }
}

void gc_left_tunnel_text(){
    // Natural land bridge and waterfall - dangerous balancing game and hidden horror
    print_line();
    cout << "You find yourself in a large cavern, a narrow, natural land bridge stretching across a massive canyon splitting the chamber in two. A large waterfall cascades down from above and to the left of the land bridge,\n"
            "completely soaking the bridge to the point that puddles have formed on it, giving the illusion of holes. Were it not for the constant spray sending ripples through the puddles, you'd believe the illusion.\n"
            "Looking up, you find that the source of the waterfall cannot be determined as the entire top half of the chamber is engulfed in darkness. You glance down towards the equally shrouded bottom of the chamber\n"
            "and try to imagine how deep it must be. You look around and find a nearby glowing mushroom growing on the wall near the entrance and pluck it right off. You hold the mushroom over the crevasse and let go.\n"
            "The light from the mushroom gradually fades as it falls into the abyss, confirming your suspicions that the canyon is, in fact, very deep. Deep enough that you'd be falling for some time before you inevitably die.\n"
            "You look back up across the bridge and spy a flickering orange light in the distance. Squinting, you think you see shadows move back and forth in front of the light. A bonfire, perhaps? If that's a bonfire, then the\n"
            "shadows must be people, right? Maybe they can help you find what you're looking for. You look back down to the bridge and weigh your options.\n"
            "Either you can risk crossing the bridge, which is not only barely wide enough for two people to walk across but completely soaked, or you can simply try to get the attention of the figures on the other side of the chamber.\n";
    
    gc_left_tunnel();
}

void gc_left_tunnel(){
    gc_explored_left_tunnel = true;
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Cross the bridge\n";
    cout << "B. Try to get the attention of the \"figures\"\n";
    cout << "C. Go back through the tunnel\n";
    print_line();
    cin >> choice;

    if(choice == 'a' || choice == 'A'){
        cout << "You decide to try and cross the bridge.\n"
                "You take a tentative step forward, cautious of the slickness of the water-beaten stone. Small clumps of glowing pink moss help to identify the borders of the bridge and offer minor footholds\n"
                "as you make your dangerous trek forwards. Spreading your arms out and keeping your legs steady, you slowly make your way forward, keeping your eyes firmly rooted to the path in front of you and\n"
                "avoiding looking at the pitch black abyss below you at all costs. Step by cautious step, you make your way across the bridge. Puddles glint in the faint light of the moss and shine like stars reflecting\n"
                "the spray of the waterfall to the left of you. Finally, you're about halfway across the bridge and getting comfortable in your stride when your shoe finally gives way, surrendering to the slippery stone.\n"
                "You wave your arms frantically in the air, trying to maintain balance, but only succeed in further dislodging yourself from relatively safe footholds. You fall and slide down the side of the bridge, clawing\n"
                "desperately at the pink moss that reliquishes its own grip far too easily. The tumble down is quick, but the fall is long. So, so long. The darkness swallows you up like a ravenous beast slurping up the remains\n"
                "of its recent kill. All that is left are the echoes of your screams, until that too is drowned out by the incessant roar of the waterfall.\n";

        cout << "\n\nEnding 10: Water Fall";
        print_line();
        retry(&gc_left_tunnel);
    }
    else if(choice == 'b' || choice == 'B'){
        if(!attention_seeker){
            cout << "You decide to try and get the attention of the figures on the other side of the chasm. You look around for something to signal them with. All there really seems to be are some smooth pebbles and\n"
                    "the bioluminescent foliage growing out of the walls and bridge near the entrance. Even if they're glowing, they're way too dim to be very noticeable, especially considering that the light is reflecting\n"
                    "off the mist from the waterfall. You look around some more and notice something that you didn't before - there's something stuck in a puddle of mud near the tunnel entrance. You dig through the mud and\n"
                    "pull out the object - a slingshot. You test the strength of the sling and notice that, despite its exposure to the water, the slingshot is still in good condition. You pick up some of the larger smooth\n"
                    "stones and load them into the sling. You take aim towards the flickering light and let it fly. Nothing. You load another stone and take aim again, then fire the second stone. This time, it hits.\n"
                    "Specifically, it hits the light dead-on. You watch in stunned bewilderment as the stone bounces off the surface of something slightly translucent, behind which the glow emanates. Then, the \"bonfire\" moves.\n"
                    "The glow moves up, and as it moves you hear the echoes of crashing rocks. The glow rotates and comes closer to you, so close you can see that there's a strange organic-looking membrane covering the source of the glow,\n"
                    " which appears to be a fleshy bulb of some kind. You stare at the strange, flickering glow and feel a unusual urge to get even closer. You take a small step forward before realizing how close you are to the edge of the\n"
                    "and pull back, adrenaline flooding your veins. It is then you hear it - a low rumble gradually getting louder. You look back towards the bulb, but notice movement behind it - two large opal globes.\n"
                    "You squint in confusion, but then your blood runs cold.\n"
                    "Eyes. Those globes are eyes. A giant reptilian visage suddenly engulfs the chamber, so close the bioluminescent fungi has no trouble lighting it up. You fall back in shock and quickly start dragging yourself backwards.\n"
                    "All the while, you're still staring at the monstrous face and when it hears you scuffle against the floor of the tunnel, it leaps forward with its mouth agape. You scream, turn around and run back through the tunnel.\n";
            attention_seeker = true;
            the_glowing_cave();
        }
        else{
            cout << "You shouldn't be able to read this.\n"
                    "Only death awaits those who dare try this path again.\n\n";
            the_glowing_cave();
        }
    }
    else if(choice == 'c' || choice == 'C'){
        cout << "You turn around and head back through the tunnel.\n";
        the_glowing_cave();
    }
    else{
        try_again();
        gc_left_tunnel();
    }
};

void gc_right_tunnel(){
    print_line();
    if(!gc_explored_right_tunnel){
        cout << "You go through the dry tunnel. The air flowing past your body as you head further in.\n"
                "Soon, you come across a much larger cave, dim light pouring in through a crevice in the ceiling of the chamber.\n"
                "You look up and instantly freeze, even more bats are present in this cave than the one you were just in.\n"
                "Thankfully, these bats seem to be deep asleep, with very little movements coming from the furry horde.\n"
                "You adjust your movements accordingly, ensuring that you don't make any loud noises. You carefully make your way across the chamber to the wall opposite the entrance.\n"
                "On this wall are numerous cave paintings, distinct from the usual style of the Worldwalkers. From what you can make out, it depicts an intelligent humanoid species\n"
                "encountering what appears to be the Worldwalkers coming from the cave. The paintings continue on to show that an agreement was struck to barter and trade between the two groups.\n"
                "Some time passes before something affects the agreement, the Worldwalkers appear less in the paintings until they no longer show at all.\n"
                "The rest of the paintings are cut off by large boulders blocking what appears to be the exit to the outside world.\n"
                "Something caused the native humanoids to want to cut off contact with the Worldwalkers. And something caused the Worldwalkers to stop trade with the native humanoids.\n"
                "It is then you find an interesting assortment of rocks. The rocks are stacked in a peculiar way that suggests they served as an altar of sorts. Unfortunately, most of the\n"
                "altar was smashed in whatever caused the avalanche that blocked off the entrance. Most of what appear to be valuable artifacts are either shattered or broken in some other way.\n"
                "Looking around, you find a strange-looking fossil that appears to have fallen off the altar, pieces of a smashed vase laying around it. You pick it up.\n"
                "Immediately, your ears pop and you find that your hearing has become extremely acute. In fact, you can even hear the quiet snoring of the bats hanging above you.\n"
                "The effect is so sudden, you end up dropping the fossil. It clatters loudly on the cave floor and the effect disappears. You quickly snatch it up and your acute hearing returns.\n"
                "It is then you notice something has changed - you can't hear the snoring of the bats anymore.\n"
                "Hesitantly, you stiffly lean your head up towards the ceiling of the cave. What you see makes your stomach drop - you see at least a hundred beady black eyes staring down at you.\n"
                "You pause, and for a moment, nothing happens. Then, a drop of water falls off a nearby stalactite and like a starting pistol, you take off in a mad sprint toward the tunnel.\n"
                "Immediately, the bats take to the air in a mammalian cyclone, screeching and diving towards you. Strangely, you can hear them coming towards you so well it allows you to dodge them before\n"
                "they can attack you. In fact, with the addition of the screeching, it feels as though you can sense the entirety of the cave around you. You move around in it, dodging the bats as if\n"
                "it was the most well-lit gym in the world and you were a star dodgeball player.\n"
                "You make it to the tunnel and run through, an angry bat trying to claw its way in, but can't due to its size.\n"
                "You smile, your newfound power helping you through the darkness, and you soon burst back out into the previous area. You look up towards the ceiling, but there are no bats to be found.\n";
        gc_explored_right_tunnel = true;
    }
    else
    {
        cout << "When you enter into the cave, you find no bats.\n"
                "Instead, you see a hole in the ceiling that you didn't see before. You assume the bats must have escaped through there. You are free to explore this cave more thoroughly now.\n"
                "You walk around the cave, taking a closer look at the artifacts around the altar. You also find a folded paper partially hidden underneath a larger piece of vase.\n"
                "You pick it up and read it:\n\n";
        cout << journal_entry_2;
        cout << "You fold the paper up and pocket it. Searching the cave further, you find nothing of interest and head back through the tunnel.\n\n";
    }
    the_glowing_cave();
}

void gc_pathway_text(){
    print_line();
    cout << "You follow the trail for some distance before arriving in a small clearing in the forest of fungi. A portion of the dirt here is tilled, but small, dead sprouts of an unknown plant line\n"
            "the ground. Nearby is a wooden cart with a missing wheel, tilted at an angle where you can easily see into the back of it. In the back of the cart are intricately-woven baskets with decayed\n"
            "remnants of the plant inside them. You approach the cart and look inside the baskets. It looks as though this cave served as a small farm of sorts for whatever plant the Worldwalkers had grown\n"
            "here. Lining the walls of the cart are several luxuriously designed blankets made of a thick, shiny material. Gold trim accents the blankets, with an embossed geometric pattern making up the\n"
            "center of the blanket. You feel the material, and are surprised to feel it react to your touch. A feeling of warmth immediately embraces your hand, providing a small comfort despite the damp nature\n"
            "of the cave. The feel of the blanket is so comforting, you wish you could take it with you. Unfortunately, you don't exactly have anywhere to store it, so you leave it be. You take a step back and examine\n"
            "the cart as a whole. From what you can make of the damage, it appears the wheel had broken away from the axle and been left alongside the cart. You look back over the whole scene before you.\n"
            "Whoever had left this cart here had been meaning to return for it, you decide. Given the nature of the objects and the state of the cart, it appears that whoever owned it was intent on returning, but never did.\n"
            "Why? It is then you notice what appears to be a parchment or scroll of some king partially hidden between two of the baskets. You pull it out and open it. At first, the unusual text is illegible, but then the effect\n"
            "of the knife causes the meaning of it to appear. It's an inventory order of some kind. Evidently, this cart belonged to a merchant and this farm was used to produce a good used for trade.\n";
    gc_pathway();
}

void gc_pathway(){
    // Evidence of Worldwalkers - abandoned basket and/or cart in clearing
    print_line();
    cout << "";
    // To be continued...
}