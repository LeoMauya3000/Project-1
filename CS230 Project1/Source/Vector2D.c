#include "stdafx.h"
#include "Vector2D.h"
#define _USE_MATH_DEFINES
#include <math.h>





void Vector2DZero(Vector2D* pResult)
{
	pResult->x = 0;
	pResult->y = 0;
}
void Vector2DSet(Vector2D* pResult, float x, float y)
{
	pResult->x = x;
	pResult->y = y;
}
void Vector2DNeg(Vector2D* pResult, const Vector2D* pVec0)
{
	
	pResult->x = -(pVec0->x);
	pResult->y = -(pVec0->y);

}
void Vector2DAdd(Vector2D* pResult, const Vector2D* pVec0, const Vector2D* pVec1)
{
	pResult->x = pVec0->x + pVec1->x;
	pResult->y = pVec0->y + pVec1->y;
}
void Vector2DSub(Vector2D* pResult, const Vector2D* pVec0, const Vector2D* pVec1)
{
	pResult->x = pVec0->x - pVec1->x;
	pResult->y = pVec0->y - pVec1->y;
}
void Vector2DNormalize(Vector2D* pResult, const Vector2D* pVec0)
{
	float magnitude = sqrtf(powf(pVec0->x,2) + powf(pVec0->y,2));
	
	pResult->x = pResult->x / magnitude;
	pResult->y = pResult->y / magnitude;
}
void Vector2DScale(Vector2D* pResult, const Vector2D* pVec0, float scale)
{

	pResult->x = pVec0->x * scale;
	pResult->y = pVec0->y * scale;

}
void Vector2DScaleAdd(Vector2D* pResult, const Vector2D* pVec0, float scale, const Vector2D* pVec1)
{
	pResult->x = (pVec0->x * scale) + pVec1->x;
	pResult->y = (pVec0->y * scale) + pVec1->y;
}
void Vector2DScaleSub(Vector2D* pResult, const Vector2D* pVec0, float scale, const Vector2D* pVec1)
{
	pResult->x = (pVec0->x * scale) - pVec1->x;
	pResult->y = (pVec0->y * scale) - pVec1->y;
}
float Vector2DLength(const Vector2D* pVec0)
{
	return sqrtf(powf(pVec0->x, 2) + powf(pVec0->y, 2));
}
float Vector2DSquareLength(const Vector2D* pVec0)
{
	return powf(Vector2DLength(pVec0), 2);
}
float Vector2DDistance(const Vector2D* pVec0, const Vector2D* pVec1)
{
	float distance = sqrtf(powf(pVec1->x - pVec0->x, 2) + powf(pVec1->y - pVec0->y, 2));
	return distance;
}
float Vector2DSquareDistance(const Vector2D* pVec0, const Vector2D* pVec1)
{
	return powf(Vector2DDistance(pVec0, pVec1),2);
}
float Vector2DDotProduct(const Vector2D* pVec0, const Vector2D* pVec1)
{
	float dotProd = (pVec0->x * pVec1->x) + (pVec0->y + pVec1->y);
	return dotProd;
}
void Vector2DFromAngleDeg(Vector2D* pResult, float angle)
{
	pResult->x = cosf(angle);
	pResult->y = sinf(angle);


}
void Vector2DFromAngleRad(Vector2D* pResult, float angle)
{
	float radians = (float)(angle * M_PI) / 180.0f;
	pResult->x = cosf(radians);
	pResult->y = sinf(radians);
}
float Vector2DToAngleRad(const Vector2D* pVec)
{
	if(pVec == NULL)
	{
		return 0.0f;
	}

	float angle = atan2f(pVec->y, pVec->x);
	return (float)(angle * M_PI) / 180.0f;
}


