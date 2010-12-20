#include "Skill.h"

using namespace std;
using namespace CATCHME;

Skill::Skill()
{
	mName = "skill";
	mMaxCD = 0;
	mCurCD = 0;
}

Skill::~Skill()
{

}

bool Skill::UseSkill(CATCHME::Player *sourcePlayer, CATCHME::Player *targetPlayer)
{
	// WARNING: it just a sample call ,don't call this based class function
	if(IfInCD())
		return false;
	// the skill deal with you;

	UseSkillSucess();
	return true;
}
void Skill::UseSkillSucess()
{
	mCurCD = mMaxCD;
}

bool Skill::IfInCD()
{
	if ( mCurCD > 0)
	{
		return true;
	}
	return false;
}

void Skill::ResetCD()
{
	mCurCD = 0;
}


