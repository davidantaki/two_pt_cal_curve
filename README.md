# Two-Pt-Cal-Curve

Library for a generic two point calibration curve.

A calibration curve is a function/graph with the theoretical values that
the sensor SHOULD/IS EXPECTED to output on the y-axis, and the ACTUALLY
values measured by the sensor on the x-axis.

For example, if you had a temperature sensor. To calibrate it, you
read a value from the temperature sensor and say it outputs 30F but
the actual temperature in the room is 32F. (30, 32) becomes your first
point on the calibration curve.

On a different day (or you change the environment temperature), you take
another reading from the temp sensor and it reads 54F, but the actual
temp in the room is 51F. (54, 51) becomes your second point on the
calibration curve.

(30, 32) and (54, 51) would be the CalPoint's you pass when instantiating
an object of this class.