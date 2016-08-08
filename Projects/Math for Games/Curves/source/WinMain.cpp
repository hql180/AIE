#include "AIE.h"
#include "MyDrawingWindow.h"

/******************************************************************************
Program entry point
*******************************************************************************/
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    try
    {
        // Create a drawing window. 
        MyDrawingWindow window("Windows Drawing Framework");

        // Set the background color of the window to dark gray (for other colors, see Color.h).
        window.SetBackgroundColor(aie::DarkGray);

        // Run the window. This will display the window to the user. The application
        // will close automatically when the user closes the window.
        window.Run();
    }
    catch (const std::exception & e)
    {
        // Any fatal errors that occur within the Drawing Framework will throw a std::exception
        // with an appropriate error message and will be caught here.
        MessageBox(0, e.what(), "Fatal Error", MB_ICONSTOP);
    }
    catch (...)
    {
        MessageBox(0, "Unhandled exception", "Fatal Error", MB_ICONSTOP);
    }

    return 0;
}
