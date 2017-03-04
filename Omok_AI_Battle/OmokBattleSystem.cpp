#include "OmokBattleSystem.h"

COmokBattleSytem::COmokBattleSytem()
{
	Init();
}

//------ �Լ� �����͸� ����	------
void COmokBattleSytem::SetYourFunc(
		void (*pfuncBlackAttack) ( int *x, int *y ),
		void (*pfuncBlackDefence)( int  x, int  y ),
		void (*pfuncWhiteAttack) ( int *x, int *y ),
		void (*pfuncWhiteDefence)( int  x, int  y ) )
//--------------------------------
{
	// �浹 �Լ�
	m_funcBlackAttack	= pfuncBlackAttack;
	m_funcBlackDefence	= pfuncBlackDefence;

	// �鵹 �Լ�
	m_funcWhiteAttack	= pfuncWhiteAttack;
	m_funcWhiteDefence	= pfuncWhiteDefence;

}

//--------- ���� ���� ------------
bool COmokBattleSytem::BeginGame()
//--------------------------------
{
	int x = -1, y = -1;
	float fLimitTime = 0.0f;
	
	while( m_nCurrentGameCount < g_nGameCount )
	{

		// ���º�
		if( m_nBlack + m_nWhite >= g_nMax * g_nMax )
		{
			std::cout << "���º� �Դϴ�.";
			++m_nCurrentGameCount;
			continue;
		}

		//------------------------------ �鵹 ����, �浹 ���------------------------------------
				
		getchar();
		
		StartTime();
		m_funcBlackAttack( &x, &y );		
		if( CheckTime( &m_fAttackExcuteTime ) )
		{
			std::cout << "���浹 Attack ����ð� : " << m_fAttackExcuteTime << "��\n";
			std::cout << "���ѽð� : " << g_fLimitTime <<"�ʸ� �ʰ��Ͽ����Ƿ� �浹�� �����ϴ�.";
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
			std::cout << "�۹鵹 Defence ����ð� : " << m_fDefenceExcuteTime << "��\n";
			std::cout << "���ѽð� : " << g_fLimitTime <<"�ʸ� �ʰ��Ͽ����Ƿ� �浹�� �����ϴ�.";
			Init();
			++m_nCurrentGameCount;
			continue;
		}

		//------------------------------------------------------------------------------------------


		//------------------------------ �鵹 ����, �浹 ���------------------------------------
		getchar();

		StartTime();
		m_funcWhiteAttack( &x, &y );
		if( CheckTime( &m_fAttackExcuteTime ) )
		{
			std::cout << "�۹鵹 Attack ����ð� : " << m_fAttackExcuteTime << "��\n";
			std::cout << "���ѽð� : " << g_fLimitTime <<"�ʸ� �ʰ��Ͽ����Ƿ� �鵹�� �����ϴ�.";
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
			std::cout << "���浹 Denfence ����ð� : " << m_fDefenceExcuteTime << "��\n";
			std::cout << "���ѽð� : " << g_fLimitTime <<"�ʸ� �ʰ��Ͽ����Ƿ� �浹�� �����ϴ�.";
			Init();
			++m_nCurrentGameCount;
			continue;
		}

		//------------------------------------------------------------------------------------------
	}

	return true;
}


//--------- ���� �ʱ�ȭ -----------
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

//--------- ��� ��� ���---------
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
	

//--------- ��� �ð� �ʰ�---------
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

//--------- ��� ��� ���---------
void COmokBattleSytem::Result()
//---------------------------------
{


}

//--------- ������ �׸��� --------
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
					std::cout<< "��";
				else if( x == 18 && y == 18 )
					std::cout<< "��";
				else if( x == 18 && y == 0  )
					std::cout<< "��";
				else if( x == 0	 && y == 18 )
					std::cout<< "��";
				else if( y == 0 )
					std::cout<< "��";
				else if( y == 18 )
					std::cout<< "��";
				else if( x == 0 )
					std::cout<< "��";
				else if( x == 18 )
					std::cout<< "��";
				else
					std::cout<< "��";
			}
			else if( m_nOmokPan[ y ][ x ] == BLACK )
				std::cout<< "��"; 
			else if( m_nOmokPan[ y ][ x ] == WHITE )
				std::cout<< "��";
		}
		std::cout<< "\n";
	}
	
	printf("%s Attack  ����ð� : %.5f��\n", m_nOmokType == BLACK ? "���浹" : "�ܹ鵹", m_fAttackExcuteTime );
	printf("%s Defence ����ð� : %.5f��\n", m_nOmokType == BLACK ? "�ܹ鵹" : "���浹", m_fDefenceExcuteTime );

	std::cout<< "���浹 �ϼ� : " << m_nBlack << "  �ܹ鵹 �ϼ� : " << m_nWhite << std::endl;

}

//--------- �¸� ���� �Ǵ� ----------
int COmokBattleSytem::CheckWin( int x, int y, int type )
//-----------------------------------
{
	int dx, dy, _dx, _dy;
	int count = 0;	
	int nEmptyFlag[ 4 ] = { 0, };			
	int nEmpty[ 4 ] = { 0,  };			// ����
	int nCount[ 4 ] = { 1,1,1,1 };		// ���� �� �¸� ī��Ʈ
	int nEnemytype[ 4 ] = { 0, };		// �ٸ� ���� ��� �ö󰡴� ī��Ʈ
	int _nCount[ 4 ] = { 1,1,1,1 };		// ���� ���� ī��Ʈ
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
				if( m_nOmokPan[ dy ][ dx ] == type ) //�ۡۡ� , �ۡ�
				// ���� ���� ���
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
				// �����ϋ�...
				{
					++nEmptyFlag[ j ];	

					if( nEmptyFlag[ j ] == 2 )
					{					
						if( nCount[ j ]		 >= 2 && bNoEmpty[ j ] == false )	// �� ��
						{
							nEmpty[j] = 1;
							nEmptyFlag[j] = 1;
						}
						else if( nCount[ j ] == 1 && bNoEmpty[ j ] == true  )	// ��
						{
							nEmpty[j] = 0;
							nEmptyFlag[j] = 0;
						}
						else if( nCount[ j ] >= 2 && bNoEmpty[ j ] == true  )	// �ۡ�
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
				// �ٸ� ���� ���
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
				if( m_nOmokPan[ _dy ][ _dx ] == type) //�ۡۡ� , �ۡ�
				// ���� ���� ���
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
				// �����ϋ�...
				{
					++nEmptyFlag[ j ];	
				
					if( nEmptyFlag[ j ] == 2 )
					{					
						if( nCount[ j ]		 >= 2 && bNoEmpty[ j ] == false )	// �� ��
						{					
							nEmpty[j] = 1;						
						}
						else if( nCount[ j ] == 1 && bNoEmpty[ j ] == true  )	// ��
						{
							nEmpty[j] = 0;					
						}
						else if( nCount[ j ] >= 2 && bNoEmpty[ j ] == true  )	// �ۡ�
						{
							nEmpty[j] = 0;						
						}
					
						break;								
					}
					
					_dx = _dx + g_Directiontable[j + 4][0];
					_dy = _dy + g_Directiontable[j + 4][1];				

				}
				else if( ( m_nOmokPan[ _dy ][ _dx ] != PAN ) && ( m_nOmokPan[ _dy ][ _dx ] != type ) )
				// �ٸ� ���� ���
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
		if( _nCount[ j ] == 3 && nEmpty[ j ] == 0  && nEnemytype[ j ] == 0  ) // �ۡۡ�
		{
			++nSamSamCount;			
		}		
		else if( _nCount[ j ] == 3 && nEmpty[ j ] == 1  && nEnemytype[ j ] == 0  ) // �� �ۡ�
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
//--------- ���� ����( ��, �� ) -----
void COmokBattleSytem::ChangeType()
//-----------------------------------
{



}
*/

//--------- ���� ����( ��, �� ) -----
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
				std::cout << " �浹�� �¸��Ͽ����ϴ�.\n ";
				return true;
				break;
			
			case SAM:
				std::cout << " �浹�� ��� ��Ģ �������� �浹�� ��Ģ���Դϴ�.\n ";
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
				std::cout << " �鵹�� �¸��Ͽ����ϴ�.\n ";
				return true;
				break;
			
			case SAM:
				std::cout << " �鵹�� ��� ��Ģ �������� �鵹�� ��Ģ���Դϴ�.\n ";
				return true;
				break;
			}
						
			m_nOmokType = BLACK;

		}

	}
	return false;
}


