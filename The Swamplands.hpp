// Header file for The Swamplands.cpp
#ifndef THE_SWAMPLANDS_HPP
#define THE_SWAMPLANDS_HPP

#include <string>

using namespace std;

extern bool explored_grasslands;
extern bool explored_tall_trees;
extern bool explored_islands;
extern bool tt_intro_text;
extern bool hunt;
extern bool crab;

extern void reset_ts();
extern void the_swamplands_text();
extern void the_swamplands(bool show_interlude);
extern void grasslands();
extern void tall_trees();
extern void islands();
extern void rock_island();
extern void the_hunt();

#endif