// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <algorithm>

class PlayerInfo
{
public:
	PlayerInfo(){};
	PlayerInfo(int, int);
	~PlayerInfo();

public:
	int value1, value2;

};

PlayerInfo::PlayerInfo(int p1, int p2)
{
	value1 = p1;
	value2 = p2;
}

PlayerInfo::~PlayerInfo()
{
}

bool myfunction (std::pair<int, int> i,std::pair<int, int> j) { return (i.second  > j.second); }

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<PlayerInfo> mPlayers;
	mPlayers.push_back(PlayerInfo(10, 20));
	mPlayers.push_back(PlayerInfo(12, 20));
	mPlayers.push_back(PlayerInfo(11, 20));
	mPlayers.push_back(PlayerInfo(11, 20));
	mPlayers.push_back(PlayerInfo(12, 20));
	mPlayers.push_back(PlayerInfo(10, 20));
	mPlayers.push_back(PlayerInfo(13, 20));
	mPlayers.push_back(PlayerInfo(13, 20));
	mPlayers.push_back(PlayerInfo(14, 20));
	mPlayers.push_back(PlayerInfo(13, 20));
	mPlayers.push_back(PlayerInfo(15, 20));
	mPlayers.push_back(PlayerInfo(16, 20));
	mPlayers.push_back(PlayerInfo(13, 20));
	mPlayers.push_back(PlayerInfo(14, 20));
	mPlayers.push_back(PlayerInfo(13, 20));

	std::vector<PlayerInfo>::iterator iter = mPlayers.begin();

	std::map<int, int> stateTmpData;

	for (; iter != mPlayers.end(); ++ iter)
	{
		if(stateTmpData.find(iter->value1) == stateTmpData.end())
		{
			stateTmpData[iter->value1] = 0;
		}
		stateTmpData[iter->value1] += iter->value2;
	}

	std::vector<std::pair<int, int> > mapcopy;
	std::map<int, int>::iterator it = stateTmpData.begin();

	while (it != stateTmpData.end())
	{
		mapcopy.push_back(*it);
		it++;
	}

	std::sort(mapcopy.begin(), mapcopy.end(), myfunction);

	return 0;
}

