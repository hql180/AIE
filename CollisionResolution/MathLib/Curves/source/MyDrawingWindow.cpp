#include "MyDrawingWindow.h"


/******************************************************************************
Create the drawing window
*******************************************************************************/
MyDrawingWindow::MyDrawingWindow(const char *title)
	: DrawingWindow(title)
{
}

/******************************************************************************
*******************************************************************************/
MyDrawingWindow::~MyDrawingWindow()
{
}

/******************************************************************************
This method is called by the Framework immediately after the window is created.
Create however many control points that you'll need here. This method should
not be used for any drawing (see 'OnPaint').
*******************************************************************************/
void MyDrawingWindow::OnInit()
{
	// Create two control points that we can use to draw the circle:
	m_controlPoints.push_back(AddControlPoint(550, 400)); // The center of the circle
	m_controlPoints.push_back(AddControlPoint(700, 250)); // A point on the circumference
	m_controlPoints.push_back(AddControlPoint(600, 300));
	m_controlPoints.push_back(AddControlPoint(800, 450));
}

/******************************************************************************
This method is called by the Framework to actually draw the window.
*******************************************************************************/
void MyDrawingWindow::OnPaint()
{
	// We'll draw the circle in 1000 steps, which should be enough to create a 
	// smooth curve. If you use more steps, drawing performance will decrease.
	const float NUM_STEPS = 1000;

	const float PI = 3.14159265f;

	// Set the color in which all points will be drawn, in this case green (see 
	// 'Color.h' in the include folder for details)
	SetPointColor(aie::DarkGreen, 2);
	SetLineColor(aie::DarkBlue, 2);

	// Because the two control points can be dragged by the user, we need to 
	// ask the Drawing Framework for their current position by calling 
	// 'GetControlPointPosition'. We do that here and store the two positions 
	// as the center point and circumference point.
	const aie::Vector2 & center = GetControlPointPosition(m_controlPoints[0]);
	const aie::Vector2 & circumference = GetControlPointPosition(m_controlPoints[1]);
	const aie::Vector2 & dot3 = GetControlPointPosition(m_controlPoints[2]);
	const aie::Vector2 & dot4 = GetControlPointPosition(m_controlPoints[3]);

	// To get the radius of the circle, we can simply subtract the two (because the
	// two positions are Vectors, we can do airthmetic with them - see Vector2.h
	// for details).
	float radius = (circumference - center).Length();

	// Draw the circle by drawing 1000 separate points at interpolated angles around 
	// the circumference.


	

	for (int i = 0; i < NUM_STEPS; i++)
	{
		// The current angle
		float angle = i * 2 * PI / NUM_STEPS;

		// Compute the X,Y coordinates of the circumference point at this angle
		float x = center.x + radius * cos(angle);
		float y = center.y + radius * sin(angle);

		float steps = i / NUM_STEPS;

		aie::Vector2 drawMe = aie::Vector2::Lerp(center, circumference, steps);

		aie::Vector2 bezier = aie::Vector2::Lerp(aie::Vector2::Lerp(center, circumference, steps), aie::Vector2::Lerp(circumference, dot3, steps), steps);

		aie::Vector2 cubicBezier = aie::Vector2::Lerp(bezier, aie::Vector2::Lerp(dot3, dot4, steps), steps);

		// ...and draw the point
		SetPointColor(aie::DarkGreen, 2);
		DrawPoint(x, y);

		SetPointColor(aie::DarkBlue, 2);
		DrawPoint(drawMe);

		SetPointColor(aie::DarkCyan, 2);
		DrawPoint(bezier);

		SetPointColor(aie::LightBlue, 2);
		DrawPoint(cubicBezier);
	}
}
