#include "pch.h"
#include "Transform.h"

namespace nc
{
	std::istream& nc::operator>>(std::istream& stream, Transform& t)
	{
		stream >> t.position;

		std::string line;
		std::getline(stream, line);
		t.scale = stof(line);

		std::getline(stream, line);
		t.angle = stof(line);

		return stream;
	}

	void Transform::Update()
	{
		Matrix33 mxs;
		mxs.Scale(scale);

		Matrix33 mxr;
		mxr.Rotate(angle);

		Matrix33 mxt;
		mxt.Translate(position);

		matrix = mxs * mxr * mxt;
	}
}
