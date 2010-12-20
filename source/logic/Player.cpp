#include "Player.h"
#include "PlayerStatus.h"
#include "Skill.h"
#include <algorithm>
using namespace std;
using namespace CATCHME;

Player::Player()
{
	mX = 0.f;
	mY = 0.f;
	mSpeed = 0.f;
	mAcc = 0.f;
	mAngle = 0.f;

	mName = "player";
	mLife = 100;
}

Player::~Player()
{
	VEC_PLAYER_STATUS::iterator iterStatusDel;
	for (iterStatusDel = mVecBuff.begin(); iterStatusDel != mVecBuff.end(); ++iterStatusDel)
	{
		delete *iterStatusDel;
	}
	mVecBuff.clear();

	for(iterStatusDel = mVecDebuff.begin(); iterStatusDel != mVecDebuff.end(); ++iterStatusDel)
	{
		delete *iterStatusDel;
	}
	mVecDebuff.clear();

	CleanRemovedStatus();

	VEC_SKILLS::iterator iterSkillDel;
	for (iterSkillDel = mVecSkills.begin(); iterSkillDel != mVecSkills.end(); ++iterSkillDel)
	{
		delete *iterSkillDel;
	}
	mVecSkills.clear();
}

void Player::AddBuff(CATCHME::PlayerSatus *buff)
{
	mVecBuff.push_back( buff );
}

void Player::DelBuff(CATCHME::PlayerSatus *buff)
{
	VEC_PLAYER_STATUS::iterator iterFind;
	iterFind = find(mVecBuff.begin(), mVecBuff.end(), buff );
	if (iterFind != mVecBuff.end())
	{
		mVecBuff.erase(iterFind);
		mVecRemovedStatus.push_back(buff);
	}else
	{
		printf("ERROR Player::DelBuff \n");
	}
}

void Player::AddDebuff(CATCHME::PlayerSatus *debuff)
{
	mVecDebuff.push_back( debuff );
}

void Player::DelDebuff(CATCHME::PlayerSatus *debuff)
{
	VEC_PLAYER_STATUS::iterator iterFind;
	iterFind = find(mVecDebuff.begin(), mVecDebuff.end(), debuff);
	if (iterFind != mVecDebuff.end())
	{
		mVecDebuff.erase( iterFind );
		mVecRemovedStatus.push_back( debuff );
	}
	else
	{
		printf("ERROR Player::DelDebuff\n");
	}
}

void Player::UpdatePlayer(int intervalTime)
{
	CleanRemovedStatus();

}

void Player::CleanRemovedStatus()
{
	if (mVecRemovedStatus.empty())
	{
		return;
	}
	VEC_PLAYER_STATUS::iterator iterRemoveStatus;
	for (iterRemoveStatus = mVecRemovedStatus.begin(); iterRemoveStatus != mVecRemovedStatus.end(); ++iterRemoveStatus)
	{
		delete *iterRemoveStatus;
	}
	mVecRemovedStatus.clear();

}

