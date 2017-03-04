#include "OmokBattleSystem.h"

#include "JNG.h"
#include "KSM.h"
//---------------------------------------------

int main()
{
	COmokBattleSytem OmokGame;

	OmokGame.Init();

	OmokGame.SetYourFunc( 
		/*�瘚農ttack*/ JNG::Attack, /*�瘚道efence*/JNG::Defence,
		/*寥給Attack*/ KSM::Attack, /*寥給Defence*/KSM::Defence);

	if( OmokGame.BeginGame() )
		OmokGame.Result();

	return 0;
}