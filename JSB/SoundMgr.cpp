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
	// FMOD 시스템 객체 초기화
	result =FMOD_System_Create(&fsystem,FMOD_VERSION);
	assert(!result);

	result =FMOD_System_Init(fsystem, 32, FMOD_INIT_NORMAL, NULL);
	assert(!result);
	
	// 사운드 장착
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
	// 시스템 객체 해제
	FMOD_System_Release(fsystem);
}

void SoundMgr_PlaySound(int sound_number)
{

	// 사운드 파일 로드 및 재생
	FMOD_System_PlaySound(fsystem, sound[sound_number], NULL, 0, &channelMusic);
}

void SoundMgr_PlayEffect(int sound_number)
{
	SoundMgr_StopEffect();
	// 사운드 파일 로드 및 재생
	FMOD_System_PlaySound(fsystem, sound[sound_number], NULL, 0, &channelEffect);
}

void SoundMgr_StopSound()
{
	// 재생 중인 사운드 멈추기
	FMOD_Channel_Stop(channelMusic);
}

void SoundMgr_StopEffect()
{
	// 재생 중인 사운드 멈추기
	FMOD_Channel_Stop(channelEffect);
}



void SoundMgr_AdjustVolume(float volume)
{
	// 채널의 볼륨 조절
	FMOD_Channel_SetVolume(channelMusic, volume);
}