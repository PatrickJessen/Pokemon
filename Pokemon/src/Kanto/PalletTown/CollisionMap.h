#pragma once

class CollisionMap
{
public:
	CollisionMap(const char* fileMap);
	~CollisionMap();

public:
	int trueCollition = 1;
	int doorCollision = 2;
	int depthCollision = 3;
	int waterCollision = 4;
	int exitMapCollision = 5;
};