#pragma once
#include <list>
#include <vector>
#include "define.h"
template <class T> 

class Rect {

public:
	T x;
	T y;
	T width;
	T height;
public:
	Rect() {};
	Rect(T x, T y, T width, T height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}
	Rect(const Rect& rect) {
		this->x = rect.x;
		this->y = rect.y;
		this->height = rect.height;
		this->width = rect.width;
	}
	void Translate(T x, T y) {
		this->x += x;
		this->y += y;
	}
	// gán this bằng phần giao của this vs 1 rect khác
	void Clip(Rect rect) {
		T sRight = this->x + this->width;
		T sBottom = this->y + this->height;
		T rRight = rect.x + rect.width;
		T rBottom = rect.y + rect.height;
		
		this->x = max(this->x, rect.x);
		this->y = max(this->y, rect.y);

		sRight = min(sRight, rRight);
		sBottom = min(sBottom, rBottom);
		width = sRight - this->x;
		width = sBottom - this->y;
	}

	bool operator == (const Rect< T > rect)
	{
		return (x == rect.x &&
			y == rect.y &&
			width == rect.width &&
			height == rect.height);
	}

	//kiểm tra xem 2 rect có va chạm nhau không
	bool checkCollision(Rect r2)
	{
		if (this->x + this->width <= (T)r2.x)
			return false;
		if (this->x >= r2.x + (T)r2.width)
			return false;
		if (this->y + this->height <= (T)r2.y)
			return false;
		if (this->y >= r2.y + (T)r2.height)
			return false;
		return true;
	}

	//kiểm tra xem rect có nằm trong this hay không ( chỉ xét trục X )
	bool checkEdgeCollsion(Rect r2)
	{
		if (this->checkCollision(r2))
		{
			if (this->x > (T)r2.x) return false;
			if (this->x + this->width < (T)r2.x + (T)r2.width) return false;
			return true;

		}

		else
			return false;
	}

	//phép ép kiểu
	operator const Rect< T2 >()
	{
		return Rect< T2 >((T2)x, (T2)y, (T2)width, (T2)height);
	}
};

typedef Rect< float > RectF;
typedef std::list< Rect<float> > RectFList;
typedef Rect < int > RectI;


