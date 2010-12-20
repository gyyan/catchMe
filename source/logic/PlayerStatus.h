// the PlayerStatus is the Player BUFF and DEBUFF 
#ifndef __PLAYER_STATUS_H_
#define __PLAYER_STATUS_H_
#include <string>
namespace CATCHME
{
	class Player;
	class PlayerSatus
	{
	public:
		std::string mName;
		bool mIsBuff;
		int mMaxCD;
		int mCurCD;// the status's life , when is 0 ,is disappear
		int mPriority;// the number bigger the priority is higher
	public:
		PlayerSatus();
		virtual ~PlayerSatus();

		// it should be called by inherit function in the end .
		virtual void StatusUpdate(Player * player, int intervalTime);
	};
}// the end of name space
#endif