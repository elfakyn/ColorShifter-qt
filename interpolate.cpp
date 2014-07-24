#include "colorTools.h"

#define INTERPOLATE(A1, A2, XVALUE) (int)((XVALUE) * ((A2) - (A1)) + 1.0 * (A1))
#define ABS(x) ((x) >= 0 ? (x) : (0 - (x)))

// don't use this, use interpolate_ instead
Color interpolate(Color color1, Color color2, double xvalue)
{
    int4 ahsv1 = color1.GetAHSV();
    int4 ahsv2 = color2.GetAHSV();
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

int4 interpolate_(int4 ahsv1, int4 ahsv2, double xvalue, bool hsv)
{
    int x, offset = 0;
    if (hsv) {
        if (ahsv1.x - ahsv2.x > 127) {
            offset = 255 - ahsv1.x;
            ahsv2.x += offset;
            ahsv1.x = 0;
        } else if (ahsv2.x - ahsv1.x > 127) {
            offset = 255 - ahsv2.x;
            ahsv1.x += offset;
            ahsv2.x = 0;
        }
        x = INTERPOLATE(ahsv1.x, ahsv2.x, xvalue) - offset;
        if (x < 0) {
            x = 256 + x;
        }
    } else {
        x = INTERPOLATE(ahsv1.x, ahsv2.x, xvalue);
    }

    return int4 {
        INTERPOLATE(ahsv1.w, ahsv2.w, xvalue),
        x,
        INTERPOLATE(ahsv1.y, ahsv2.y, xvalue),
        INTERPOLATE(ahsv1.z, ahsv2.z, xvalue)
    };
}
