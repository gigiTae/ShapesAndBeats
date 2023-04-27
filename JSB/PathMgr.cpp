#include "pch.h"
#include "PathMgr.h"

char ContentPath[256]{};
char RelativePath[256]{};

void PathMgr_Init()
{
	// ����θ� �ƽ�Ű �ڵ�� �޴� �Լ�
	GetCurrentDirectoryA(255, ContentPath); 

}

char* GetRelativePath(const char* _filepath)
{
	// ��λ� �ѱ������� ������ ������ ����Ƿ� �ѱ������� ����� �ٲ㼭 ����� �ּ���

	// ù��° ���ڸ� \0 �ʱ�ȭ�ؼ� ���ڿ��� �ֺ��ó�� �ർ��
	RelativePath[0] = '\0';

	strcat_s(RelativePath, sizeof(RelativePath), ContentPath);

	strcat_s(RelativePath, sizeof(RelativePath), _filepath);

	return RelativePath;
}
