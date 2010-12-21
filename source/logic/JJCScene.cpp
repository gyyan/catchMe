#include "JJCScene.h"

using namespace Sexy;
using namespace CATCHME;

JJCScene::JJCScene()
{
	mWidth = 0;
	mHeight = 0;

	mSideAInitPosition = Point(0, 0);
	mSideBInitPosition = Point(0, 0);
}

JJCScene::~JJCScene()
{

}

Sexy::Point JJCScene::PlayerPositionChange(Sexy::Point originPosition, Sexy::Point targetPosition)
{
	if( targetPosition.mX >= 0 && targetPosition.mX <= mWidth
		&& targetPosition.mY >= 0 && targetPosition.mY <= mHeight)
	{
		return targetPosition;
	}

	return originPosition;
}
