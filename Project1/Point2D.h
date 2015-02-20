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



};

#endif // __Point2D_H__
