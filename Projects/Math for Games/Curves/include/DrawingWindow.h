/******************************************************************************

                                DrawingWindow.h
                                ===============

'DrawingWindow' provides an X-Y Cartesian plane with floating point coordinates 
for drawing curves programmatically. The origin is at the bottom-left of the 
window with the units being in pixels. The coordinate system is a standard 
Cartesion system, with X running to the right and Y running upwards.

'DrawingWindow' also encapsulates an entire Windows application including the 
Windows message loop. To run a drawing application:

    - Derive your own class from class DrawingWindow

    - In WinMain, instantiate an object of your derived class.

    - Then call 'Run' on your derived object.

The drawing window will default to filling  80 percent of the screen, but you 
can maximize and/or resize it at any time.

*******************************************************************************/
#pragma once

#include "Color.h"
#include "Vector2.h"
#include <Windows.h>
#include <vector>



namespace aie
{
    class DrawingWindow
    {
    public:

        // Create the DrawingWindow with the specified title (can be zero
        // if no title is required).
        DrawingWindow(const char *title);
        virtual ~DrawingWindow();

        // Run the application and open the DrawingWindow. The application
        // will continue until the DrawingWindow is cloased by the user.
        void Run();

        // Sets the background color of the DrawingWindow. Generally, this 
        // is the only method that you can call before calling 'Run'. All
        // other methods must be called from the polymorphic override methods 
        // 'OnInit' and/or 'OnPaint' (see below).
        void SetBackgroundColor(const Color & color);

        // Specifies the color and thickness to be used by the 'DrawLine' method. 
        // All calls to 'DrawLine' will continue using this color/thickness 
        // until another color is set.
        void SetLineColor(const Color & color, int thickness = 1);

        // Specifies the color and thickness to be used by the 'DrawPoint' method. 
        // All calls to 'DrawPoint' will continue using this color/thickness until 
        // another color is set.
        void SetPointColor(const Color & color, int thickness = 1);

        // Specifies the color and thickness to be used for drawing control points. 
        // By default, control points are drawn in red with thickess of 10 pixels.
        void SetControlPointColor(const Color & color, int thickness = 10);

        // Draws a single point at a specified coordinate position within 
        // the window. The position can be specified either as X-Y coordinate
        // values or as a single Vector2.
        void DrawPoint(float x, float y);
        void DrawPoint(const Vector2 & vec);

        // Draws a single line between two supplied end-points. The end-points 
        // can be specified either as X-Y coordinate values or as a Vector2.
        void DrawLine(float x1, float y1, float x2, float y2);
        void DrawLine(const Vector2 & vec1, const Vector2 & vec2);

        // Adds a 'control point' to the window. This is a hot spot at a 
        // specified position on the window that can be dragged by the user
        // with the mouse. The mouse cursor will show the standard Windows 
        // move cursor whenever the cursor is within dragging distance of a 
        // control point.
        // Return Value: An id that uniquely identifies the control point 
        //               to your program. You can use this id to get the 
        //               position of the control point at any later time
        //               (see 'GetControlPointPosition').
        //       
        typedef int ControlPointId;
        ControlPointId AddControlPoint(float x, float y);

        // Returns the ciurrent position of a specified control point
        // (as specified by the id returned by the original call
        // to 'AddControlPoint').
        const Vector2 & GetControlPointPosition(ControlPointId id);



        //-------------------------------------------------
        // Polymorphic Overrides
        //-------------------------------------------------
        // Your derived class should override these methods to provide code
        // to draw the curves required by your program.

        // This method executes when the DrawingWindow is first created.
        // You should use this method to add all of the control points 
        // needed by your program.
        virtual void OnInit() {}

        // This method executes every time the DrawingWindow needs to be repainted.
        // You should use this method to call the various 'Draw...' and/or SetColor 
        // methods as required by your program.
        virtual void OnPaint() {}



    private:
        HWND m_hwnd;
        HDC m_hdcMem;
        HBITMAP m_bmpMem;
        HBITMAP m_bmpOld;
        int m_bmpWidth;
        int m_bmpHeight;
        int m_width;  // Client area width & height
        int m_height;
        HBRUSH m_backBrush;
        HBRUSH m_pointBrush;
        HPEN m_linePen;
        int m_pointThickness;
        bool m_dragging;
        bool m_painting;
        bool m_inInit;
        ControlPointId m_controlPointId;
        std::vector< Vector2 > m_controlPoints;
        Color m_controlPointColor;
        int m_controlPointThickness;
        HPEN m_controlPointPen;

        friend LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
        void OnCreate();
        void OnLButtonDown(int x, int y);
        void OnLButtonUp(int x, int y);
        void OnMouseMove(int x, int y);
        void OnPaint(HDC hdc);
        void OnSize(int width, int height);

        void SetStandardCursor(LPCTSTR cursorName);
        void Refresh();
    };


} // namespace aie
