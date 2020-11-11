#include "QMath.h"

using namespace MATH;

float QMath::Dot(const Quaternion& q1, const Quaternion &q2)
{
	return (q1.w * q2.w) + (q1.i * q2.i) + (q1.j * q2.j) + (q1.k * q2.k);
}

Matrix4 QMath::QuaternionToMatrix4(const Quaternion& q)
{
	return Matrix4(1.0f - 2.0f * (q.j * q.j) - 2.0f * (q.k * q.k), 2.0f * (q.i * q.j) + 2.0f * (q.w * q.k), 2.0f * (q.i * q.k) - 2.0f * (q.w * q.j), 0.0f,
		2.0f * (q.i * q.j) - 2.0f * (q.w * q.k), 1.0f - 2.0f * (q.i * q.i) - 2.0f * (q.k * q.k), 2.0f * (q.j * q.k) - 2.0f * (q.w * q.i), 0.0f,
		2.0f * (q.i * q.k) + 2.0f * (q.w * q.j), 2.0f * (q.j * q.k) - 2.0f * (q.w * q.i), 1.0f - 2.0f * (q.i * q.i) - 2.0f * (q.j * q.j), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix3 QMath::QuaternionToMatrix3(const Quaternion& q)
{
	return Matrix3(1.0f - 2.0f * (q.j * q.j) - 2.0f * (q.k * q.k), 2.0f * (q.i * q.j) + 2.0f * (q.w * q.k), 2.0f * (q.i * q.k) - 2.0f * (q.w * q.j),
		2.0f * (q.i * q.j) - 2.0f * (q.w * q.k), 1.0f - 2.0f * (q.i * q.i) - 2.0f * (q.k * q.k), 2.0f * (q.j * q.k) - 2.0f * (q.w * q.i),
		2.0f * (q.i * q.k) + 2.0f * (q.w * q.j), 2.0f * (q.j * q.k) - 2.0f * (q.w * q.i), 1.0f - 2.0f * (q.i * q.i) - 2.0f * (q.j * q.j));
}

float QMath::Mag(const Quaternion& q)
{
	return sqrt((q.w * q.w) + (q.i * q.i) + (q.j * q.j) + (q.k * q.k));
}

Quaternion QMath::Normalize(const Quaternion& q)
{
	Quaternion n;
	float mag = Mag(q);

	n.w = q.w / mag;
	n.i = q.i / mag;
	n.j = q.j / mag;
	n.k = q.k / mag;

	return n;
}

Quaternion QMath::Inverse(const Quaternion& q)
{
	float m = Mag(q) * Mag(q);

	return Quaternion(q.w / m, -q.i / m, -q.j / m, -q.k / m);
}

Quaternion QMath::Rotation(float& angle, const Vec3& axis)
{
	angle *= DEGREES_TO_RADIANS;
	Vec3 a = VMath::normalize(axis);

	return Quaternion(cos(angle / 2.0f), a.x * sin(angle / 2.0f), a.y * sin(angle / 2.0f), a.z * sin(angle / 2.0f));
}

float QMath::Angle(const Quaternion& q_)
{
	return 2 * (acos(q_.w) * 180 / M_PI);
}

Vec3 QMath::Axis(const Quaternion& q)
{
	Vec3 v = Vec3(q.i, q.j, q.k);
	float n = sin(Angle(q) / 2.0f);

	return Vec3(v.x / n, v.y / n, v.z / n);
}