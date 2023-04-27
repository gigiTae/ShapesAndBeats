#pragma once

void SoundMgr_Init();

void SoundMgr_Exit();

// �÷����ϰ���� ����, ä�γѹ��� �Է��ؼ� ���� ���
void SoundMgr_PlaySound(int sound_number);

// ����Ʈ �÷��� �Լ�
void SoundMgr_PlayEffect(int sound_number);

// �÷����ϰ� �ִ� ä�ο��� ������ �����
void SoundMgr_StopSound();

// ����Ʈ ����
void SoundMgr_StopEffect();


// ä�� ���� ����
void SoundMgr_AdjustVolume(float volume);