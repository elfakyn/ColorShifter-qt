#include "colorTools.h"

#define INTERPOLATE(A1, A2, XVALUE) (int)((XVALUE) * ((A2) - (A1)) + 1.0 * (A1))

Color interpolate(Color color1, Color color2, double xvalue)
{
	int4 ahsv1 = color1.GetAHSV();//
	int4 ahsv2 = color2.GetAHSV();/////FIXME
	int4 ahsvOut;
	int balanceOut;

	ahsvOut.w = INTERPOLATE(ahsv1.w, ahsv2.w, xvalue);
	ahsvOut.x = INTERPOLATE(ahsv1.x, ahsv2.x, xvalue);
	ahsvOut.y = INTERPOLATE(ahsv1.y, ahsv2.y, xvalue);
	ahsvOut.z = INTERPOLATE(ahsv1.z, ahsv2.z, xvalue);
	balanceOut = INTERPOLATE(color1.GetBalance(), color2.GetBalance(), xvalue);

	Color colorOut;

	colorOut.SetAHSV(ahsvOut);///FIXME
	colorOut.SetBalance(0x64);

	return colorOut;
}