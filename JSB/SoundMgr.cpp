#include "pch.h"
#include "SoundMgr.h"
#include "PathMgr.h" 

FMOD_SYSTEM* fsystem;
FMOD_SOUND* sound[SOUND_END];
FMOD_RESULT result; 
FMOD_CHANNEL* channelMusic;
FMOD_CHANNEL* channelEffect;

void SoundMgr_Init()
{
	// FMOD �ý��� ��ü �ʱ�ȭ
	result =FMOD_System_Create(&fsystem,FMOD_VERSION);
	assert(!result);

	result =FMOD_System_Init(fsystem, 32, FMOD_INIT_NORMAL, NULL);
	assert(!result);
	
	// ���� ����
	result = FMOD_System_CreateSound(fsystem, GetRelativePath("\\music\\MainScene.mp3"), FMOD_DEFAULT, 0, &sound[MAINSCENE]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, GetRelativePath("\\music\\Tutorial.mp3"), FMOD_DEFAULT, 0, &sound[TUTORIAL]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, GetRelativePath("\\music\\INTRO.wav"), FMOD_DEFAULT, 0, &sound[INTRO]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, GetRelativePath("\\music\\ENDING.mp3"), FMOD_DEFAULT, 0, &sound[ENDING]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, GetRelativePath("\\music\\Higher.mp3"), FMOD_DEFAULT, 0, &sound[HIGHER]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, GetRelativePath("\\music\\PV_Higher.mp3"), FMOD_DEFAULT, 0, &sound[PV_HIGHER]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, GetRelativePath("\\music\\Cascade.mp3"), FMOD_DEFAULT, 0, &sound[CASCCADE]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, GetRelativePath("\\music\\PV_Cascade.mp3"), FMOD_DEFAULT, 0, &sound[PV_CASCCADE]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, GetRelativePath("\\music\\Sevcon.mp3"), FMOD_DEFAULT, 0, &sound[SEVCON]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, GetRelativePath("\\music\\PV_Sevcon.wav"), FMOD_DEFAULT, 0, &sound[PV_SEVCON]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, GetRelativePath("\\music\\Die.wav"), FMOD_DEFAULT, 0, &sound[DIE]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, GetRelativePath("\\music\\Click1.wav"), FMOD_DEFAULT, 0, &sound[CLICK1]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, GetRelativePath("\\music\\Click2.wav"), FMOD_DEFAULT, 0, &sound[CLICK2]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, GetRelativePath("\\music\\HIT.wav"), FMOD_DEFAULT, 0, &sound[HIT]);
	assert(!result);
}

void SoundMgr_Exit()
{
	// �ý��� ��ü ����
	FMOD_System_Release(fsystem);
}

void SoundMgr_PlaySound(int sound_number)
{

	// ���� ���� �ε� �� ���
	FMOD_System_PlaySound(fsystem, sound[sound_number], NULL, 0, &channelMusic);
}

void SoundMgr_PlayEffect(int sound_number)
{
	SoundMgr_StopEffect();
	// ���� ���� �ε� �� ���
	FMOD_System_PlaySound(fsystem, sound[sound_number], NULL, 0, &channelEffect);
}

void SoundMgr_StopSound()
{
	// ��� ���� ���� ���߱�
	FMOD_Channel_Stop(channelMusic);
}

void SoundMgr_StopEffect()
{
	// ��� ���� ���� ���߱�
	FMOD_Channel_Stop(channelEffect);
}



void SoundMgr_AdjustVolume(float volume)
{
	// ä���� ���� ����
	FMOD_Channel_SetVolume(channelMusic, volume);
}