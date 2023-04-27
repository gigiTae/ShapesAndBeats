#pragma once

void SoundMgr_Init();

void SoundMgr_Exit();

// 플레이하고싶은 사운드, 채널넘버를 입력해서 사운드 재생
void SoundMgr_PlaySound(int sound_number);

// 이펙트 플레이 함수
void SoundMgr_PlayEffect(int sound_number);

// 플레이하고 있는 채널에서 음악을 멈춘다
void SoundMgr_StopSound();

// 이펙트 멈춤
void SoundMgr_StopEffect();


// 채널 사운드 조절
void SoundMgr_AdjustVolume(float volume);