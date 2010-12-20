#include "PlayerStatus.h"
#include "Player.h"
using namespace std;
using namespace CATCHME;

PlayerSatus::PlayerSatus()
{
	mName = "";
	mMaxCD = 0;
	mCurCD = 0;
	mPriority = 0;
	mIsBuff = true;
}

PlayerSatus::~PlayerSatus()
{

}

void PlayerSatus::StatusUpdate(CATCHME::Player *player, int intervalTime)
{
	if(mCurCD > intervalTime)
		mCurCD -= intervalTime;
	else
	{
		mCurCD = 0;
		if (mIsBuff)
		{
			player->DelBuff( this );
		}else
		{
			player->DelDebuff( this );
		}
	}
}

