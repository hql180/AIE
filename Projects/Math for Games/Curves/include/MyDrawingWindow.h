#include "AIE.h"

// The Windows Drawing Framework relies on polymorphism to allow you to 
// override its default behaviour. Therefore, we derive a new class here
// from the base class 'aie::DrawingWindow'.
class MyDrawingWindow : public aie::DrawingWindow
{
public:

	// Create the window with the specified title
	MyDrawingWindow(const char *title);
	~MyDrawingWindow();

private:

	// These two functions are overridden from aie::DrawingWindow to allow
	// you to write your own code to draw lines and curves. 'OnInit' is used
	// to create the control points that may be required (which must be done 
	// before any painting occurs). 'OnPaint' is used to write the code that 
	// will actually draw the curves. Drawing is done by calling the various
	// 'Draw' functions in the base class aie::DrawingWindow. 
	virtual void OnInit();
	virtual void OnPaint();

	std::vector< DrawingWindow::ControlPointId > m_controlPoints;
};