#include "QMath.h"
namespace MATH
{
	float Angle(const Quaternion &q1_, const Quaternion &q2_)
	{
		Quaternion q1 = q1_;
		Quaternion q2 = q2_;

		return acos(QMath::Dot(q1, q2)) * 180 / M_PI;
	}

	Quaternion Lerp(const Quaternion q1_, const Quaternion q2_, const float t_)
	{
		Quaternion q1 = q1_;
		Quaternion q2 = q2_;
		Quaternion q;

		QMath::Normalize(q1);
		QMath::Normalize(q2);

		float f = 1 - t_;

		q1 *= f;
		q2 *= t_;

		float mag = QMath::Mag(q1 + q2);

		q = q1 + q2;

		return q / mag;
	}

	Quaternion Slerp(const Quaternion &q1_, const Quaternion &q2_, const float t_)
	{
		Quaternion q1 = q1_;
		Quaternion q2 = q2_;

		QMath::Normalize(q1);
		QMath::Normalize(q2);

		float t = t_;
		float angle = Angle(q1, q2) * DEGREES_TO_RADIANS;

		if (angle < VERY_SMALL)				//Not sure how small the angle has to be to cause a problem
			return Lerp(q1, q2, t);

		Quaternion q;

		float s1 = sin(angle * (1 - t)) / sin(angle);
		float s2 = sin(t * angle) / sin(angle);

		q = (q1 * s1) + (q2 * s2);

		return q;
	}
}