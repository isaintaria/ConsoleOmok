#include "OmokBattleSystem.h"

#include "JNG.h"
#include "KSM.h"
//---------------------------------------------

int main()
{
	COmokBattleSytem OmokGame;

	OmokGame.Init();

	OmokGame.SetYourFunc( 
		/*�浹Attack*/ JNG::Attack, /*�浹Defence*/JNG::Defence,
		/*�鵹Attack*/ KSM::Attack, /*�鵹Defence*/KSM::Defence);

	if( OmokGame.BeginGame() )
		OmokGame.Result();

	return 0;
}