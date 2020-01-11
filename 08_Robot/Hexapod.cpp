///////////////////////////////////////////////////////////////////////////
// Workfile :		Hexapod.cpp
// Author :			Marc Haunschmied
// Date :			11-January-2020
// Description :	Robot with 6 legs, looks like a spider
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "Hexapod.h"

std::string Hexapod::GetRobotType() const{
	return "Hexapod";
}

Hexapod::Hexapod(Position const& pos, std::string const& name, Direction const& dir) : Robot(pos,name,dir){

}
