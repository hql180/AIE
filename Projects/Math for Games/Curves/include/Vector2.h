/******************************************************************************

                                Vector2.h
                                =========
                    
'Vector2' is a two-component vector that is used by the Library both as a 
standard mathematical vector and also to represent positions on the Cartesian
drawing plane (see DrawingWindow.h).

Vector2 supports all of the arithmetic operators so that it can be used in 
arbitrary mathematical expressions.

*******************************************************************************/
#pragma once


namespace aie
{
    class Vector2
    {
    public:

        //-------------------------------------------
        // Static Methods
        //-------------------------------------------

        // Returns a Vector2 that is a linear interpolation between the 'start'
        // and 'end' vectors by the specified ratio 't'.
        static Vector2 Lerp(const Vector2 & start, const Vector2 & end, float t);



        //-------------------------------------------
        // Constructors / Destructor
        //-------------------------------------------

        Vector2();
        Vector2(float x, float y);
        ~Vector2();



        //-------------------------------------------
        // Public Variables
        //-------------------------------------------

        float x, y;



        //-------------------------------------------
        // Public Methods
        //-------------------------------------------

        // Sets the individual components of the Vector2
        void Set(float x, float y);

        // Returns the length (i.e. magnitude) of the Vector2
        float Length() const;

        // Normalizes the Vector2
        void Normalize();



        //-------------------------------------------
        // Operators
        //-------------------------------------------

        Vector2 operator-() const;

        Vector2 & operator+= (float value);
        Vector2 & operator+= (const Vector2 & other);

        Vector2 & operator-= (float value);
        Vector2 & operator-= (const Vector2 & other);

        Vector2 & operator*= (float value);
        Vector2 & operator*= (const Vector2 & other);

        Vector2 & operator/= (float value);
        Vector2 & operator/= (const Vector2 & other);

    private:
    };



    //-------------------------------------------
    // Global Operators
    //-------------------------------------------
    Vector2 operator+(const Vector2 & vec, float value);
    Vector2 operator+(float value, const Vector2 & vec);
    Vector2 operator+(const Vector2 & vec1, const Vector2 & vec2);

    Vector2 operator-(const Vector2 & vec, float value);
    Vector2 operator-(float value, const Vector2 & vec);
    Vector2 operator-(const Vector2 & vec1, const Vector2 & vec2);

    Vector2 operator*(float value, const Vector2 & vec);
    Vector2 operator*(const Vector2 & vec, float value);
    Vector2 operator* (const Vector2 & vec1, const Vector2 & vec2);

    Vector2 operator/(float value, const Vector2 & vec);
    Vector2 operator/(const Vector2 & vec, float value);
    Vector2 operator/ (const Vector2 & vec1, const Vector2 & vec2);

} // namespace aie



