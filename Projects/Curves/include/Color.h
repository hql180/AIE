/******************************************************************************

                                    Color.h
                                    =======

Provides a Color structure that is used throughout the Library for Windows
color management (all Windows color functionality is based on RGB components
ranging from 0 to 255).

*******************************************************************************/
#pragma once

#include <Windows.h>



namespace aie
{
    // 'Color' represents a color in the Windows color management system.
    struct Color
    {
        BYTE red, green, blue;

        Color() : red(0), green(0), blue(0) {}
        Color(BYTE r, BYTE g, BYTE b) : red(r), green(g), blue(b) {}
    };

    // Some pre-supplied standard colors
    static Color Black = Color(0, 0, 0);
    static Color Blue = Color(0, 0, 255);
    static Color Cyan = Color(0, 255, 255);
    static Color DarkBlue = Color(0, 0, 128);
    static Color DarkCyan = Color(0, 128, 128);
    static Color DarkGray = Color(64, 64, 64);
    static Color DarkGreen = Color(0, 128, 0);
    static Color DarkMagenta = Color(128, 0, 128);
    static Color DarkRed = Color(128, 0, 0);
    static Color DarkYellow = Color(128, 128, 0);
    static Color Gray = Color(128, 128, 128);
    static Color Green = Color(0, 255, 0);
    static Color LightBlue = Color(0, 0, 192);
    static Color LightCyan = Color(0, 192, 192);
    static Color LightGray = Color(192, 192, 192);
    static Color LightGreen = Color(0, 192, 0);
    static Color LightMagenta = Color(192, 0, 192);
    static Color LightRed = Color(192, 0, 0);
    static Color LightYellow = Color(192, 192, 0);
    static Color Magenta = Color(255, 0, 255);
    static Color Red = Color(255, 0, 0);
    static Color White = Color(255, 255, 255);
    static Color Yellow = Color(255, 255, 0);

} // namespace
