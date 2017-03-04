#include "OmokBattleSystem.h"

COmokBattleSytem::COmokBattleSytem()
{
	Init();
}

//------ 함수 포인터를 셋팅	------
void COmokBattleSytem::SetYourFunc(
		void (*pfuncBlackAttack) ( int *x, int *y ),
		void (*pfuncBlackDefence)( int  x, int  y ),
		void (*pfuncWhiteAttack) ( int *x, int *y ),
		void (*pfuncWhiteDefence)( int  x, int  y ) )
//--------------------------------
{
	// 흑돌 함수
	m_funcBlackAttack	= pfuncBlackAttack;
	m_funcBlackDefence	= pfuncBlackDefence;

	// 백돌 함수
	m_funcWhiteAttack	= pfuncWhiteAttack;
	m_funcWhiteDefence	= pfuncWhiteDefence;

}

//--------- 게임 시작 ------------
bool COmokBattleSytem::BeginGame()
//--------------------------------
{
	int x = -1, y = -1;
	float fLimitTime = 0.0f;
	
	while( m_nCurrentGameCount < g_nGameCount )
	{

		// 무승부
		if( m_nBlack + m_nWhite >= g_nMax * g_nMax )
		{
			std::cout << "무승부 입니다.";
			++m_nCurrentGameCount;
			continue;
		}

		//------------------------------ 백돌 공격, 흑돌 방어------------------------------------
				
		getchar();
		
		StartTime();
		m_funcBlackAttack( &x, &y );		
		if( CheckTime( &m_fAttackExcuteTime ) )
		{
			std::cout << "●흑돌 Attack 수행시간 : " << m_fAttackExcuteTime << "초\n";
			std::cout << "제한시간 : " << g_fLimitTime <<"초를 초과하였으므로 흑돌은 졌습니다.";
			Init();
			++m_nCurrentGameCount;
			continue;
		}
		
		if( PutStone( x, y, BLACK ) )
		{
			++m_nCurrentGameCount;
			continue;
		}

		StartTime();
		m_funcWhiteDefence( x, y );
		if( CheckTime( &m_fDefenceExcuteTime ) )
		{
			std::cout << "○백돌 Defence 수행시간 : " << m_fDefenceExcuteTime << "초\n";
			std::cout << "제한시간 : " << g_fLimitTime <<"초를 초과하였으므로 흑돌은 졌습니다.";
			Init();
			++m_nCurrentGameCount;
			continue;
		}

		//------------------------------------------------------------------------------------------


		//------------------------------ 백돌 공격, 흑돌 방어------------------------------------
		getchar();

		StartTime();
		m_funcWhiteAttack( &x, &y );
		if( CheckTime( &m_fAttackExcuteTime ) )
		{
			std::cout << "○백돌 Attack 수행시간 : " << m_fAttackExcuteTime << "초\n";
			std::cout << "제한시간 : " << g_fLimitTime <<"초를 초과하였으므로 백돌은 졌습니다.";
			Init();
			++m_nCurrentGameCount;
			continue;
		}

		if( PutStone( x, y, WHITE ) )
		{
			++m_nCurrentGameCount;
			continue;
		}

		StartTime();
		m_funcBlackDefence( x, y );
		if( CheckTime( &m_fDefenceExcuteTime ) )
		{
			std::cout << "●흑돌 Denfence 수행시간 : " << m_fDefenceExcuteTime << "초\n";
			std::cout << "제한시간 : " << g_fLimitTime <<"초를 초과하였으므로 흑돌은 졌습니다.";
			Init();
			++m_nCurrentGameCount;
			continue;
		}

		//------------------------------------------------------------------------------------------
	}

	return true;
}


//--------- 게임 초기화 -----------
void COmokBattleSytem::Init()
//---------------------------------
{
	::ZeroMemory( m_nOmokPan, sizeof(m_nOmokPan) );
	::ZeroMemory( m_nUserWin, sizeof(m_nUserWin) );

	m_bActive			= true;
	m_nOmokType			= BLACK;
	m_nCurrentGameCount = 0;
	m_nBlack			= 0;
	m_nWhite			= 0;
	m_fAttackExcuteTime = 0.0f;
	m_fDefenceExcuteTime= 0.0f;


	if( QueryPerformanceFrequency( (LARGE_INTEGER*)&m_Freq ) )
	{
		QueryPerformanceCounter( (LARGE_INTEGER*)&m_nCurrentTime); 
		m_bPerHardware = true;
	}
	else
	{
		m_nCurrentTime	= timeGetTime();
		m_bPerHardware	= false;
	}	

	Draw();
}

//--------- 경기 결과 출력---------
void COmokBattleSytem::StartTime()
//---------------------------------
{
	if( m_bPerHardware )
	{
		QueryPerformanceCounter( (LARGE_INTEGER*)&m_nCurrentTime); 
	}
	else
	{
		m_nCurrentTime = timeGetTime();
	}
		
}
	

//--------- 경기 시간 초과---------
bool COmokBattleSytem::CheckTime( float *fResultTime )
//---------------------------------
{
	if( m_bPerHardware )
	{
		QueryPerformanceFrequency( (LARGE_INTEGER*)&m_Freq );
		QueryPerformanceCounter( (LARGE_INTEGER*)&m_nLastTime); 

		*fResultTime = static_cast<float>( (m_nLastTime - m_nCurrentTime ) / static_cast<float>(m_Freq) );

		if( *fResultTime > g_fLimitTime )
			return true;
	}
	else
	{
		m_nLastTime = timeGetTime();

		*fResultTime = static_cast<float>( ( m_nLastTime - m_nCurrentTime ) * 0.0001f );

		if( *fResultTime > g_fLimitTime )
			return true;
	}	

	return false;
}

//--------- 경기 결과 출력---------
void COmokBattleSytem::Result()
//---------------------------------
{


}

//--------- 게임판 그리기 --------
void COmokBattleSytem::Draw()
//--------------------------------
{
	system("cls");
	for( int y = 0; y < g_nMax; y++)
	{
		for( int x = 0; x < g_nMax; x++)
		{
			
			if( m_nOmokPan[ y ][ x ] == PAN )
			{
				if( x == 0 && y == 0 )
					std::cout<< "┌";
				else if( x == 18 && y == 18 )
					std::cout<< "┘";
				else if( x == 18 && y == 0  )
					std::cout<< "┐";
				else if( x == 0	 && y == 18 )
					std::cout<< "└";
				else if( y == 0 )
					std::cout<< "┬";
				else if( y == 18 )
					std::cout<< "┴";
				else if( x == 0 )
					std::cout<< "├";
				else if( x == 18 )
					std::cout<< "┤";
				else
					std::cout<< "┼";
			}
			else if( m_nOmokPan[ y ][ x ] == BLACK )
				std::cout<< "○"; 
			else if( m_nOmokPan[ y ][ x ] == WHITE )
				std::cout<< "●";
		}
		std::cout<< "\n";
	}
	
	printf("%s Attack  수행시간 : %.5f초\n", m_nOmokType == BLACK ? "○흑돌" : "●백돌", m_fAttackExcuteTime );
	printf("%s Defence 수행시간 : %.5f초\n", m_nOmokType == BLACK ? "●백돌" : "○흑돌", m_fDefenceExcuteTime );

	std::cout<< "○흑돌 턴수 : " << m_nBlack << "  ●백돌 턴수 : " << m_nWhite << std::endl;

}

//--------- 승리 여부 판단 ----------
int COmokBattleSytem::CheckWin( int x, int y, int type )
//-----------------------------------
{
	int dx, dy, _dx, _dy;
	int count = 0;	
	int nEmptyFlag[ 4 ] = { 0, };			
	int nEmpty[ 4 ] = { 0,  };			// 공백
	int nCount[ 4 ] = { 1,1,1,1 };		// 같은 돌 승리 카운트
	int nEnemytype[ 4 ] = { 0, };		// 다른 돌인 경우 올라가는 카운트
	int _nCount[ 4 ] = { 1,1,1,1 };		// 같은 돌인 카운트
	bool bNoEmpty[ 4 ];
			
	int result = NOWIN;


	for( int j = 0; j < 4; j++ )
	{
		dx = _dx = x ;
		dy = _dy = y ;

		dx = dx + g_Directiontable[ j ][ 0 ];
		dy = dy + g_Directiontable[ j ][ 1 ];

		_dx = _dx + g_Directiontable[ j + 4 ][ 0 ];
		_dy = _dy + g_Directiontable[ j + 4 ][ 1 ];
		
		count = 0;		
		bNoEmpty[ j ] = true;
		
		while( count < 4 )
		{
			if( ( dx >= 0 && dx <= 18 ) && ( dy >= 0 && dy <= 18 ) )
			{
				if( m_nOmokPan[ dy ][ dx ] == type ) //○○● , ○○
				// 같은 돌인 경우
				{
					++_nCount[ j ];

					if( bNoEmpty[ j ] )
						++nCount[j];				

					if( nEmptyFlag[ j ] >= 1  )
						bNoEmpty[ j ] = false;					
					
					dx = dx + g_Directiontable[ j ][ 0 ];
					dy = dy + g_Directiontable[ j ][ 1 ];
					
				}
				else if( m_nOmokPan[ dy ][ dx ] == PAN)  
				// 공백일떄...
				{
					++nEmptyFlag[ j ];	

					if( nEmptyFlag[ j ] == 2 )
					{					
						if( nCount[ j ]		 >= 2 && bNoEmpty[ j ] == false )	// ○ ○
						{
							nEmpty[j] = 1;
							nEmptyFlag[j] = 1;
						}
						else if( nCount[ j ] == 1 && bNoEmpty[ j ] == true  )	// ○
						{
							nEmpty[j] = 0;
							nEmptyFlag[j] = 0;
						}
						else if( nCount[ j ] >= 2 && bNoEmpty[ j ] == true  )	// ○○
						{
							nEmpty[j] = 0;
							nEmptyFlag[j] = 0;
						}
					
						break;								
					}
					
					dx = dx + g_Directiontable[ j ][ 0 ];
					dy = dy + g_Directiontable[ j ][ 1 ];
				
				}
				else if( ( m_nOmokPan[ dy ][ dx ] != PAN ) && ( m_nOmokPan[ dy ][ dx ] != type ) )
				// 다른 돌인 경우
				{	
					if( nEmptyFlag[ j ] == 0)
						++nEnemytype[ j ];
					break;
				}
				
				++count;			
			}
			else
				break;
		}

		count = 0;

		while( count < 4 )
		{
			if( ( _dx >= 0 && _dx <= 18 ) && ( _dy >= 0 && _dy <= 18 ) ) 
			{
				if( m_nOmokPan[ _dy ][ _dx ] == type) //○○● , ○○
				// 같은 돌인 경우
				{	
					++_nCount[ j ];

					if( bNoEmpty[ j ] )
						++nCount[j];				

					if( nEmptyFlag[ j ] >= 1  )
						bNoEmpty[ j ] = false;	

					_dx = _dx + g_Directiontable[ j + 4 ][ 0 ];
					_dy = _dy + g_Directiontable[ j + 4 ][ 1 ];				
					
				}
				else if( m_nOmokPan[ _dy ][ _dx ] == PAN) 
				// 공백일떄...
				{
					++nEmptyFlag[ j ];	
				
					if( nEmptyFlag[ j ] == 2 )
					{					
						if( nCount[ j ]		 >= 2 && bNoEmpty[ j ] == false )	// ○ ○
						{					
							nEmpty[j] = 1;						
						}
						else if( nCount[ j ] == 1 && bNoEmpty[ j ] == true  )	// ○
						{
							nEmpty[j] = 0;					
						}
						else if( nCount[ j ] >= 2 && bNoEmpty[ j ] == true  )	// ○○
						{
							nEmpty[j] = 0;						
						}
					
						break;								
					}
					
					_dx = _dx + g_Directiontable[j + 4][0];
					_dy = _dy + g_Directiontable[j + 4][1];				

				}
				else if( ( m_nOmokPan[ _dy ][ _dx ] != PAN ) && ( m_nOmokPan[ _dy ][ _dx ] != type ) )
				// 다른 돌인 경우
				{	
					if( nEmptyFlag[ j ] == 0)
						++nEnemytype[ j ];
					break;
				}
				
				++count;			
			}
			else
				break;
		}
	}

	int nSamSamCount = 0;
	/*for(int j = 0; j < 4; j++ )
	{
		if( _nCount[ j ] == 3 && nEmpty[ j ] == 0  && nEnemytype[ j ] == 0  ) // ○○○
		{
			++nSamSamCount;			
		}		
		else if( _nCount[ j ] == 3 && nEmpty[ j ] == 1  && nEnemytype[ j ] == 0  ) // ○ ○○
		{
			++nSamSamCount;
		}

		if( nSamSamCount >= 2 )
			return SAM;
	}*/
		
	
	for(int j = 0; j < 4; j++ )
	{
		if( nCount[ j ] == 5 )
		{
			return WIN;
		}
	}	

	return NOWIN;

}

/*
//--------- 순서 변경( 흑, 백 ) -----
void COmokBattleSytem::ChangeType()
//-----------------------------------
{



}
*/

//--------- 순서 변경( 흑, 백 ) -----
bool COmokBattleSytem::PutStone(int x, int y, int type )
//-----------------------------------
{
	if( m_nOmokPan[ y ][ x ] == PAN )
	{
		
		if( type == BLACK )
		{
			m_nOmokPan[ y ][ x ] = BLACK;
			Draw();				
			++m_nBlack;
			
			switch( CheckWin( x, y, BLACK ) )
			{
			case WIN:
				std::cout << " 흑돌이 승리하였습니다.\n ";
				return true;
				break;
			
			case SAM:
				std::cout << " 흑돌이 삼삼 규칙 위반으로 흑돌은 반칙패입니다.\n ";
				return true;
				break;
			}

			m_nOmokType = WHITE;
		}
		else
		{
			m_nOmokPan[ y ][ x ] = WHITE;
			Draw();				
			++m_nWhite;

			switch( CheckWin( x, y, WHITE ) )
			{
			case WIN:
				std::cout << " 백돌이 승리하였습니다.\n ";
				return true;
				break;
			
			case SAM:
				std::cout << " 백돌이 삼삼 규칙 위반으로 백돌은 반칙패입니다.\n ";
				return true;
				break;
			}
						
			m_nOmokType = BLACK;

		}

	}
	return false;
}


