// Header file for The Labyrinth passage
#ifndef THE_LABYRINTH_HPP
#define THE_LABYRINTH_HPP

#include <string>

using namespace std;

extern int saved_index;

extern string object;
extern string saved_object;
extern string first_puzzle_death;
extern string door_1_riddle;
extern string door_2_riddle;
extern string door_3_riddle;

extern void remove_from_inventory(string puzzle, bool recursing);
extern void add_to_inventory();
extern void timer(int time);
extern void the_labyrinth_text();
extern void first_puzzle();
extern void second_puzzle();
extern void third_puzzle();
extern void fourth_puzzle();
extern void fifth_puzzle();
extern void sixth_puzzle();
extern void underwater_scene();
extern void input();

#endif