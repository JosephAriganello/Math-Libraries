#include "Transform.h"

using namespace MATH;

Transform::Transform()
{
}

Transform::~Transform()
{
}

Matrix4 Transform::translate(const Vec3& translate)
{
	return Matrix4(1.0f, 0.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f, 0.0f,
					0.0f, 0.0f, 1.0f, 0.0f,
		translate.x, translate.y, translate.z, 1.0f);
}

void Transform::translateByAddition(Vec3& point_, const Vec3& translate_)
{
	point_ += translate_;
}

void Transform::translateByMultiplication(Vec3& point_, const Matrix4& translate_)
{
	point_ = translate_ * point_;
}

Matrix3 Transform::xRotate3D(float &angle)
{
	angle *= DEGREES_TO_RADIANS;

	return Matrix3(1.0f,  0.0f,       0.0f,
				   0.0f,  cos(angle), sin(angle), 
				   0.0f, -sin(angle), cos(angle));
}

Matrix4 Transform::xRotate4D(float &angle)
{
	angle *= DEGREES_TO_RADIANS;

	return Matrix4(1.0f,  0.0f,       0.0f,       0.0f,
				   0.0f,  cos(angle), sin(angle), 0.0f,
		           0.0f, -sin(angle), cos(angle), 0.0f,
			       0.0f,  0.0f,       0.0f,       1.0f);
}

Matrix3 Transform::yRotate3D(float &angle)
{
	angle *= DEGREES_TO_RADIANS;

	return Matrix3(cos(angle), 0.0f, -sin(angle),
				   0.0f,       1.0f,  0.0f,
				   sin(angle), 0.0f,  cos(angle));
}

Matrix4 Transform::yRotate4D(float &angle)
{
	angle *= DEGREES_TO_RADIANS;

	return Matrix4(cos(angle), 0.0f, -sin(angle), 0.0f,
		           0.0f,       1.0f,  0.0f,       0.0f,
		           sin(angle), 0.0f,  cos(angle), 0.0f,
				   0.0f,       0.0f,  0.0f,       1.0f);
}

Matrix3 Transform::zRotate3D(float &angle)
{
	angle *= DEGREES_TO_RADIANS;

	return Matrix3(cos(angle), sin(angle), 0.0f,
		          -sin(angle), cos(angle), 0.0f,
		           0.0f,       0.0f,       1.0f);
}

Matrix4 Transform::zRotate4D(float &angle)
{
	angle *= DEGREES_TO_RADIANS;

	return Matrix4(cos(angle), sin(angle), 0.0f, 0.0f,
				  -sin(angle), cos(angle), 0.0f, 0.0f,
				   0.0f,       0.0f,       1.0f, 0.0f,
				   0.0f,       0.0f,       0.0f, 1.0f);
}

Matrix4 Transform::rotate(float pitch_, float yaw_, float roll_)
{
	Matrix4 x = xRotate4D(pitch_);
	Matrix4 y = yRotate4D(yaw_);
	Matrix4 z = zRotate4D(roll_);

	Matrix4 m = x * y * z;

	return m;
}

Matrix4 Transform::scale(const float x_, const float y_, const float z_)
{
	return Matrix4(x_,   0.0f, 0.0f, 0.0f,
				   0.0f, y_,   0.0f, 0.0f,
				   0.0f, 0.0f, z_,   0.0f,
				   0.0f, 0.0f, 0.0f, 1.0f);
}

void Transform::scale(Vec4 &point_, const Matrix4 &rotation_)
{
	point_ = rotation_ * point_;
}
