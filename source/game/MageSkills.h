#ifndef __MAGE_SKILLS_H_
#define __MAGE_SKILLS_H_
#include "logic/Skill.h"

namespace CATCHME
{
	class SkillPhaseShift
		:public Skill
	{
	public:
		SkillPhaseShift();
		virtual ~SkillPhaseShift();

		virtual bool UseSkill(JJCScene* jjcScene, Player * sourcePlayer, Player *targetPlayer);
	};
}// the end of namespace
#endif