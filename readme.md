ColorShifter
============

ColorShifter dynamically changes the Windows 7/8 theme colors by tapping into an undocumented API

##Usage

The main interface is split into three sections:

* Settings
* Palettes
* Colors

### Settings group

The settings group contains the following options:

| Item | Description |
| --- | --- |
| Smootness | Changes the smoothness of the transitions. Smoother settings consume more resources. "Disco" disables transitions. |
| Cycle time | Sets the duration of a cycle, i.e. the time until the palette wraps around back to the first color. Minimum value: 00:00:01. Maximum value: 23:59:59. |
| Shift colors in random order | Picks colors at random from the palette instead of cycling between them sequentially. |
| Transition by hue | Uses Hue-Saturation-Value representation when transitioning between colors, e.g. Red->Green goes through yellow instead of brown. May have a few visual glitches. |
| Override balance | Forces the colorBalance value in Window's DwmColorizationParameters to the value in the box. Play with this if colors are too washed out or jump around. |

### Palette group

Using the palette table you can rename palettes (double-click on the name) or drag and drop them around. There are also several buttons:

| Item | Description |
| --- | --- |
| + | Adds a new palette to the table. If "copy" is checked, it copies the currently selected palette. |
| - | Removes palette from the table. You cannot remove the last palette. |
| Preview | Displays a quick preview of how the current palette looks like in action. Click again to stop preview. |
| Copy | If this is checked, adding a new palette will copy the currently selected one. |
| Save | Saves all current palettes to a file, as well as all the settings in the settings group. |
| Load | Loads palettes and settings from a file, replacing the existing ones. |

### Color group

Using the color group you can manually set the hex value of the color (double-click on the value) or drag and drop them around.

| Item | Description |
| --- | --- |
| + | Adds a new color to the table. If "copy" is checked, it copies the currently selected color. Otherwise it adds a random color. |
| - | Removes the selected color from the table. You cannot remove the last color. |
| Preview | If this is checked, the windows theme colors will change to the currently selected color. Useful for choosing colors that don't prevent you from reading the window titles. |
| Hue, Sat, Value, Alpha | Controls the hue, saturation, value, and transparency of the color. (HSV is checked) |
| Red, Green, Blue, Alpha | Controls the red, green, blue, and alpha channels of the color. (RGB is checked) |
| RGB, HSV | Determines whether the sliders control the RGB or the HSV components of the spectrum. |
| Randomize | Chooses a random color. |
| Smart | If this is checked, randomize will prefer nice colors over ugly ones. |

### Other buttons

* **About** displays some brief information about the program and its author
* **Help** displays this text
* **Stop and quit** stops shifting and exits the application
* **Start with Windows** controls whether or not the application will automatically run when you log into Windows.
* **Shift the colors!** starts shifting the Windows theme colors according to the selected palette. You need to select a palette before this button becomes available. Click again to stop.

### System tray

When the application is loaded, it will display an icon in the system tray. Pressing "X" on the main application window will not close the application. Use "Stop and quit" instead.

Double-clicking on the icon will minimize the main application if it's maximized and maximize it if it's minimized. Middle-clicking on the icon will start/stop shifting the colors. Right clicking the application will bring up a menu where you can minimize, restore, start/stop shifting the colors as well as close the application.

## Known Issues

* Pressing "preview" on a palette with "shift colors in random order" checked will stop after a random amount of time instead of a single cycle.
* Manually typing in the hex code for a color while the HSV radio button is selected may result in small changes to the inputted value.
* Setting smoothness too high, cycle time too low and adding too many colors at the same time might slow down your system.

## How to use the undocumented API for your own purposes

I only know how to do this in C++. First, declare your function pointers and load the dwmapi DLL. This is Windows black magic and I won't even pretend to know what's going on here.

```C++
hlib = LoadLibrary("dwmapi.dll"); // load the Window Manager API

if (!hlib) {
        std::cerr << "Could not load dwmapi.dll" << std::endl;
        return -1;
}

*(FARPROC *)&DwmGetColorizationParameters = GetProcAddress(hlib, (LPCSTR)127);
*(FARPROC *)&DwmSetColorizationParameters = GetProcAddress(hlib, (LPCSTR)131);
```

You then need the DwmColorizationParameters struct that will get passed to the functions:

```C++
typedef struct { // DwmColorizationParameters
        int color;
        int afterglow;
        int colorBalance;
        int afterglowBalance;
        int blurBalance;
        int glassReflectionIntensity;
        int opaqueBlend;
} DwmColorizationParameters;
```

The `color` field is an 4-byte integer containing the alpha, red, green, and blue components (0xAARRGGBB). The `colorBalance` field is an integer setting some sort of saturation for the colors, between 0 and 127. I'm not really sure what the others do. They don't seem to have an effect on Windows 8, and on Windows 7 I think they control the intensity/opacity of different glass efects.

Now you can use the functions.

```C++
DwmColorizationParameters myColor; // declare the struct that we'll be using
DwmGetColorizationParameters(&myColor); // myColor now contains the current values of the Windows interface

myColor.color = 0xFF00FF00; // Alpha: 255, Red: 0, Green: 255, Blue: 0

DwmSetColorizationParameters(&myColor, 0); // I don't know what the 0 does but you need it
```

By knowing this basic implementation you can do all sorts of things with the Windows theme colors. I'm not sure why Microsoft chose to leave these functions undocumented; I think they're pretty neat.

One other thing: I can't take the credit for finding out how to fish into the Window Manager DLL. I realized it was possible when I was playing with the display settings and the theme color changed instantly -- surely there must be a mechanism with which to do that. After hours of intense searching, I managed to string together a few incomplete tutorials to make it work. If you were the first person to figure it out, let me know and I'll credit you and link to your tutorial/website.
