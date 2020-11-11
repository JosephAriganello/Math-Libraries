
#include "Matrix.h"

namespace MATH
{
	class Transform
	{
	public:
		Transform();
		~Transform();

		static Matrix4 translate(const Vec3 &translate);
		static void translateByAddition(Vec3 &point_ , const Vec3 &translate_);
		static void translateByMultiplication(Vec3 &point_, const Matrix4 &translate_);

		static Matrix3 xRotate3D(float &angle);
		static Matrix4 xRotate4D(float &angle);

		static Matrix3 yRotate3D(float &angle);
		static Matrix4 yRotate4D(float &angle);

		static Matrix3 zRotate3D(float &angle);
		static Matrix4 zRotate4D(float &angle);

		static Matrix4 rotate(float pitch_, float yaw_, float roll_);

		static Matrix4 scale(const float x_, const float y_, const float z_);
		static void scale(Vec4 &point_, const Matrix4 &rotation_);
	};
}

