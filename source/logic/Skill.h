#ifndef __SKILL_H_
#define __SKILL_H_
#include <string>
namespace CATCHME
{
	class Player;
	class Skill
	{
	public:
		std::string mName;
		int mMaxCD;// the CD Time
		int mCurCD;// the time ,you must wait to use this skill.0: you can use this skill
	public:
		Skill();
		virtual ~Skill();

		virtual bool UseSkill(Player * sourcePlayer, Player *targetPlayer);
		void UseSkillSucess();

		bool IfInCD();
		void ResetCD();
		
	};
}// the end of namespace
#endif