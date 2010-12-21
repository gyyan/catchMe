#ifndef _JJCSCENE_H_
#define _JJCSCENE_H_
#include "SexyAppFramework/Point.h"
namespace CATCHME
{
	class JJCScene
	{
	public:
		int mWidth;
		int mHeight;

		// the one side player init position
		Sexy::Point mSideAInitPosition;
		// the other side player init position
		Sexy::Point mSideBInitPosition;
	public:
		JJCScene();
		virtual ~JJCScene();

		virtual Sexy::Point PlayerPositionChange( Sexy::Point originPosition, Sexy::Point targetPosition);
	};
}
#endif