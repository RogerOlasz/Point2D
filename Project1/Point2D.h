#ifndef __Point2D_H__
#define __Point2D_H__

class Point2D
{
public:
	float x, y;

	void setZero()
	{
		x = y = 0.0f;
	}

	bool isZero() const
	{
		return x == 0.0f && y == 0.0f;
	}

	void Negate()
	{
		x = -x;
		y = -y;
	}

	Point2D operator+ (const Point2D& a) const
	{
		Point2D tmp;
		tmp.x = x + a.x;
		tmp.y = y + a.y;
		return tmp;
	}

	Point2D operator+= (const Point2D& a) 
	{
		 x += a.x;
		 y += a.y;
	}

	Point2D operator- (const Point2D& a) const
	{
		Point2D tmp;
		tmp.x = x - a.x;
		tmp.y = y - a.y;
		return tmp;
	}

	Point2D operator-= (const Point2D& a) 
	{
		x = x -= a.x;
		y = y -= a.y;
	}


};

#endif // __Point2D_H__
