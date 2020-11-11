
#include "Vector.h"
#include "VMath.h"
#include "Matrix.h"

namespace MATH
{
	class Quaternion
	{
	public:

		float w, i, j, k;

		Quaternion();
		Quaternion(const float &w_, const float &i_, const float & j_, const float &k_);
		Quaternion(const Quaternion &q);
		Quaternion(const float &w_, const Vec3 &v);
		~Quaternion();

		// Operator Overloads //

		Quaternion operator * (const Quaternion &q)
		{
			float w1w2 = w * q.w;
			float v1v2Dot = VMath::dot(Vec3(i, j, k), Vec3(q.i, q.j, q.k));
			Vec3 w1v2 = w * Vec3(q.i, q.j, q.k);
			Vec3 w2v1 = q.w * Vec3(i, j, k);
			Vec3 v1v2Cross = VMath::cross(Vec3(i, j, k), Vec3(q.i, q.j, q.k));

			Quaternion Q = Quaternion(w1w2 - v1v2Dot,                 //w
									  w1v2.x + w2v1.x + v1v2Cross.x,  //i
				                      w1v2.y + w2v1.y + v1v2Cross.y,  //j
				                      w1v2.z + w2v1.z + v1v2Cross.z); //k
			return Q;
		}

		Quaternion operator *= (const float &f)
		{
			w *= f;
			i *= f;
			j *= f;
			k *= f;
		}

		Quaternion operator * (const float &f)
		{
			w *= f;
			i *= f;
			j *= f;
			k *= f;
		}

		Quaternion operator + (const Quaternion &q)
		{
			w += q.w;
			i += q.i;
			j += q.j;
			k += q.k;
		}

		Quaternion operator /= (const float &f)
		{
			w /= f;
			i /= f;
			j /= f;
			k /= f;
		}

		Quaternion operator / (const float &f)
		{
			w /= f;
			i /= f;
			j /= f;
			k /= f;
		}
	};
}

