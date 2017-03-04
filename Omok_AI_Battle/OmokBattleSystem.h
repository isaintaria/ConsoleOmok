#ifndef _OMOKBATTLESYSTEM_H_
#define _OMOKBATTLESYSTEM_H_

#include <cstdio>
#include <iostream>
#include <windows.h>

#pragma comment( lib, "winmm.lib" )

const int	g_nMax			= 19;	// ������ ���� ���� ����
const int	g_nGameCount	= 1;	// ���� Ƚ��
const float	g_fLimitTime	= 2.0f; // AI Attack�Լ� Limit Time 2�� �̻��̸� ���ӿ��� ����.

const int g_Directiontable[8][2] = 
{ 
	{ -1, -1 }, {  0, -1 },			//����,			��
	{  1, -1 }, {  1,  0 },			//������,		����
	{  1,  1 }, {  0,  1 },			//���� �Ʒ�,	�Ʒ�
	{ -1,  1 }, { -1,  0 }			//�޾Ʒ�,		��
};


class COmokBattleSytem
{

	enum{ PAN, BLACK, WHITE };						
	enum{ NOWIN, WIN, SAM };

	void (*m_funcBlackAttack)( int *x, int *y );	//�浹 �Լ� ������
	void (*m_funcBlackDefence)( int x, int y );
	
	void (*m_funcWhiteAttack)( int *x, int *y );	//�鵹 �Լ� ������
	void (*m_funcWhiteDefence)( int x, int y );

	int		m_nOmokType;							// ����� Ÿ��
	int		m_nUserWin[2];							// ���� �¸�
	int		m_nCurrentGameCount;					// ���� Ƚ��			
	int		m_nOmokPan[g_nMax][g_nMax];				// ������	
	bool	m_bActive;								// ���� ����

	int		m_nBlack;								// �浹 �� Ƚ��
	int		m_nWhite;								// �� �� Ƚ��

	__int64 m_nCurrentTime;							// �ð�
	__int64 m_nLastTime;
	__int64 m_Freq;			
	bool	m_bPerHardware;							// QueryPerformanceFrequency ���� ����	

	float	m_fAttackExcuteTime;					// Attack�Լ� ����ð�
	float	m_fDefenceExcuteTime;					// Defence�Լ� ����ð�


public:

	COmokBattleSytem();

	void SetYourFunc(
		void (*pfuncBlackAttack)( int *x, int *y ),
		void (*pfuncBlackDefence)( int x, int y ),
		void (*pfuncWhiteAttack)( int *x, int *y ),
		void (*pfuncWhiteDefence)( int x, int y ) );

	// ���� ����
	bool BeginGame();
	// ���� ���� 
	bool GetGameState() const { return m_bActive; }
	// ��� ��� ���
	void Result();
	// ���� �ʱ�ȭ
	void Init();	

private:
	// �� �׸���
	void Draw();
	// �Ѽ� �д�.
	bool PutStone(int x, int y, int type );
	// �¸� ���� �Ǵ�
	int CheckWin( int x, int y, int type );
	// ���� ����( ��, �� )
//	void ChangeType();	

	// ���� �ð� üũ
	void StartTime();
	bool CheckTime( float *fResultTime );


};

#endif