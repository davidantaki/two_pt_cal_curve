// File: TwoPtCalCurve.h
// Author: David Antaki
// Date: 6/20/2020
// License: This software is not open source and is copyrighted by David
// Antaki and Sous Bois International, Inc.
// Contents: Library for a calibration curve for use with a sensor,
// for example.

#ifndef TWO_PT_CAL_CURVE_H
#define TWO_PT_CAL_CURVE_H

template <typename T>
class TwoPtCalCurve
{
public:
    // A point on the xy plane
    typedef struct
    {
        T refY; // Theoretical/reference voltage
        T expX; // Experimental/measured voltage
    } CalPoint;

    // The calibration curve represented by a slope and y-intercept
    typedef struct
    {
        T slope;
        T yint;
    } CalCurve;

    TwoPtCalCurve();
    TwoPtCalCurve(CalPoint _calPt1, CalPoint _calPt2);
    ~TwoPtCalCurve();
    // To calibrate an input value/point using the 2-pt calibration curve.
    // Uses y = mx + b where y=value returned and x=_measuredVal
    //
    // @param _measuredVal  The value measured from the sensor.
    // @return              The measured value calibrated using the 2-pt
    //                      calibration curve, inputted as x.
    T calibrateVal(T _measuredVal);

private:
    // The 2 Point calibration curve itself
    CalCurve calCurve;
};

template <typename T>
TwoPtCalCurve<T>::TwoPtCalCurve()
{
}

template <typename T>
TwoPtCalCurve<T>::TwoPtCalCurve(CalPoint _calPt1, CalPoint _calPt2)
{
    calCurve.slope = (_calPt2.refY - _calPt1.refY) / (_calPt2.expX - _calPt1.expX);
    calCurve.yint = _calPt1.refY - (calCurve.slope * _calPt1.expX);
}

template <typename T>
TwoPtCalCurve<T>::~TwoPtCalCurve()
{
}

template <typename T>
T TwoPtCalCurve<T>::calibrateVal(T _measuredVal)
{
    return (calCurve.slope * _measuredVal) + calCurve.yint;
}

#endif //TWO_PT_CAL_CURVE_H
