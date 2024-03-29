// Header file for The_Glowing_Cave.hpp
#ifndef THE_GLOWING_CAVE_HPP
#define THE_GLOWING_CAVE_HPP

#include<string>

using namespace std;

extern bool gc_explored_left_tunnel;
extern bool gc_explored_right_tunnel;
extern bool gc_explored_path;
extern bool gc_usb_drive;
extern bool gc_found_journal;
extern bool gc_found_fossil;
extern bool recovered;

extern bool attention_seeker;

extern void reset_tgc();
extern void the_glowing_cave_text();
extern void the_glowing_cave();
extern void gc_left_tunnel_text();
extern void gc_left_tunnel();
extern void gc_right_tunnel();
extern void gc_pathway_text();
extern void gc_pathway(bool show_interlude);

#endif