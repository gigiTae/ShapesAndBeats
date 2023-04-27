#pragma once

struct Object;

typedef struct {
	int centerX;
	int centerY;
	double r;
	double angle;
	double angle_dx;
	int color;
	int drawSpeed;
	int drawCount;
	int lifeTime;
	int isCollider;

}CircleData; //CircleThread의 파라미터로 쓸 데이터

typedef struct {
	double startAngle;
	int emissionCount;
	int coolTime;
	int angle_dx;

}c_SpinData; //SpiningCircleThread의 파라미터로 쓸 데이터

/// 메인 오브젝트
void Object_InitCascade(Object* obj);
void Object_UpdateCascade(Object* obj);
void Object_RenderCascade(Object* obj);


///원
void DrawCircleWithCenter(int CenterX, int CenterY, double r, double startAngle, double angle_dx, int color, int drawSpeed, int drawCount, int lifeTime, int isCollider);

unsigned CircleThread(void* arg);
unsigned CircleDispensorThread(void* arg);
unsigned SpiningCircleThread(void* arg);


///그냥 "*" 하나
void Object_InitJustSquare(Object* obj);
void Object_UpdateJustSquare(Object* obj);
void Object_RenderJustSquare(Object* obj);

void Object_InitJustSquare2(Object* obj);
void Object_UpdateJustSquare2(Object* obj);
void Object_RenderJustSquare2(Object* obj);


///패턴 경고용 네모
void Object_InitNCSquare(Object* obj);
void Object_UpdateNCSquare(Object* obj);
void Object_RenderNCSquare(Object* obj);


///비
void Object_InitRain(Object* obj);
void Object_UpdateRain(Object* obj);
void Object_RenderRain(Object* obj);

unsigned RainDispensorThread(void* arg);
unsigned RainDispensorThread2(void* arg);


///직선
void Object_InitStraight(Object* obj);
void Object_UpdateStraight(Object* obj);
void Object_RenderStraight(Object* obj);


///배경
void Object_InitBackgroundFlicker(Object* obj);
void Object_UpdateBackgroundFlicker(Object* obj);
void Object_RenderBackgroundFlicker(Object* obj);


///좌표변환
int xConversion(int x);
int yConversion(int y);

