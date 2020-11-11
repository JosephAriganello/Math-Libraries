#include "Quaternion.h"

namespace MATH
{
	class QMath
	{
	public:
		// Subroutines //
		static float Dot(const Quaternion &q1, const Quaternion &q2);
		static Matrix4 QuaternionToMatrix4(const Quaternion &q);
		static Matrix3 QuaternionToMatrix3(const Quaternion &q);
		static float Mag(const Quaternion &q);
		static Quaternion Normalize(const Quaternion &q);
		static Quaternion Inverse(const Quaternion &q);
		static Quaternion Rotation(float &angle, const Vec3 &axis);
		static float Angle(const Quaternion &q);
		static Vec3 Axis(const Quaternion &q);
	};
}
