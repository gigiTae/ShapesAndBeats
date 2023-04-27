#pragma once

typedef struct Object
{
	int arrIndex; // �迭 �ε���
	// ��ġ
	short x;
	short y;
	int foreground; // ���ڻ�
	int background; // ����
	unsigned long long time; 

	int value1;
	int value2;
	float fvalue1;
	float fvalue2;

	const char* name; // ��¹���

	// �Լ� �����͸� �̿��ؼ� ������Ʈ���� �Լ����� �����ؾ���
	void (*Object_Update)(Object*);
	void (*Object_Render)(Object*);
}Object;

 