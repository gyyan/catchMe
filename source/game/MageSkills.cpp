#include "MageSkills.h"
#include <string>
using namespace std;
using namespace CATCHME;

SkillPhaseShift::SkillPhaseShift()
{
	mName = "Phase Shift";
	mMaxCD = 15000;// 15s
	mCurCD = 0;
}

SkillPhaseShift::~SkillPhaseShift()
{

}

bool SkillPhaseShift::UseSkill(CATCHME::JJCScene* jjcScene, CATCHME::Player *sourcePlayer, CATCHME::Player *targetPlayer)
{
	if(IfInCD())
		return false;

	//player run 20 yard
	
	UseSkillSucess();
	return true;
}
