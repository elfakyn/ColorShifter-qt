#pragma once

typedef struct {
	int color;
	int afterglow;
	int colorBalance;
	int afterglowBalance;
	int blurBalance;
	int glassReflectionIntensity;
	int opaqueBlend;
} DwmColor;

typedef struct {
	int w;
	int x;
	int y;
	int z;
} int4;

class Color {
private:
	int4 argb;
	int balance; // colorBalance
public:
	Color();

	void SetARGB(int4); // Alpha Red Green Blue
	int4 GetARGB();

	void SetAHSV(int4); // Alpha Hue Saturation Value
	int4 GetAHSV();

	void SetMerged(int); // ARGB channels merged into an int 0xAARRGGBB
	int GetMerged();

	void SetBalance(int);
	int GetBalance();
};

Color interpolate(Color, Color, double);

int4 AHSVfromARGB(int4);
int4 ARGBfromAHSV(int4);

Color importColor(DwmColor);
DwmColor exportColor(Color);
