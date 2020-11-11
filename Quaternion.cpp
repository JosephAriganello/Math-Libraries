#include "Quaternion.h"

MATH::Quaternion::Quaternion()
{
	w = 0.0f;
	i = 0.0f;
	j = 0.0f;
	k = 0.0f;
}

MATH::Quaternion::Quaternion(const float& w_, const float& i_, const float& j_, const float& k_)
{
	w = w_;
	i = i_;
	j = j_;
	k = k_;
}

MATH::Quaternion::Quaternion(const Quaternion& q)
{
	w = q.w;
	i = q.i;
	j = q.j;
	k = q.k;
}

MATH::Quaternion::Quaternion(const float& w_, const Vec3& v)
{
	w = w_;
	i = v.x;
	j = v.y;
	k = v.z;
}


MATH::Quaternion::~Quaternion()
{
	delete this;
}


