///////////////////////////////////////////////////////////////////////////
// Workfile :		Robot.h
// Author :			Marc Haunschmied
// Date :			11-January-2020
// Description :	Abstract robot class
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef ROBOT_H
#define ROBOT_H

#include <utility>
#include <string>

#include "Object.h"
#include "IRobot.h"
#include "Direction.h"
#include "Direction.h"

typedef std::pair<int, int> Position;

class Robot : public Object, public IRobot{
private:
	Position mPos;
	std::string mName;
	Direction mDir;

protected:
	virtual std::string GetRobotType() const = 0;

public:
	void Info(std::ostream& os) const;
	~Robot() override;
	
	Robot(Position const& pos = std::make_pair(0,0), std::string const & name = "", Direction const & dir = Direction::NORTH);
	

	void SetPos(Position const& pos);
	void SetName(std::string const& name);
	void SetDirection(Direction const& dir);



};


#endif
