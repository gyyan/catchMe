#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "SexyAppFramework/Point.h"
#include <string>
#include <map>
#include <vector>

namespace CATCHME
{
	class PlayerSatus;
	class Skill;

	class Player
	{
	public :
		Sexy::Point mPosition;
		float mSpeed;
		float mAcc;

		float mTargetX;// the play direction 
		float mTargetY;

		typedef std::vector<PlayerSatus*> VEC_PLAYER_STATUS;

		VEC_PLAYER_STATUS mVecBuff;
		VEC_PLAYER_STATUS mVecDebuff;
		VEC_PLAYER_STATUS mVecRemovedStatus;

		typedef std::vector<Skill*> VEC_SKILLS;
		VEC_SKILLS mVecSkills;

		std::string mName;
		int mLife;
	public:
		Player();
		~Player();

		void AddBuff(PlayerSatus* buff);
		void DelBuff(PlayerSatus* buff);

		void AddDebuff(PlayerSatus* debuff);
		void DelDebuff(PlayerSatus* debuff);

		void UpdatePlayer(int intervalTime);
	private:
		void CleanRemovedStatus();
	};
}// the end of namespace

#endif