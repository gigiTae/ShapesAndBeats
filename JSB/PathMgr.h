#pragma once

extern char ContentPath[256];
extern char RelativePath[256];

void PathMgr_Init();
char* GetRelativePath(const char* _filepath);
