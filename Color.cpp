#include "colorTools.h"

Color::Color()
{
	int4 argb = { 0 };
	unsigned char balance = 0;
}

void Color::SetARGB(int4 argb_)
{
	argb = argb_;
}

int4 Color::GetARGB()
{
	return argb;
}

void Color::SetAHSV(int4 ahsv)
{
	argb = ARGBfromAHSV(ahsv);
}

int4 Color::GetAHSV()
{
	return AHSVfromARGB(argb);
}

void Color::SetMerged(int merged)
{
	argb.w = (merged >> 24) & 0xFF;
	argb.x = (merged >> 16) & 0xFF;
	argb.y = (merged >> 8) & 0xFF;
	argb.z = merged & 0xFF;
}

int Color::GetMerged()
{
	return (argb.w << 24) |
		(argb.x << 16) |
		(argb.y << 8) |
		argb.z;
}

void Color::SetBalance(int balanceIn)
{
	balance = balanceIn;
}

int Color::GetBalance()
{
	return balance;
}
