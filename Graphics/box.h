#pragma once
#include "shape.h"
#include "vector2.h"

class Box : public Shape
{
	// Inherited via Shape
	virtual bool Update(float dt) override;
	virtual void Draw(Core::Graphics& graphics) override;
	virtual void Load(std::ifstream& stream);
	virtual void Save(std::ofstream& stream);
	virtual eType Type() override { return eType::BOX; }

private:
	float m_size{ 40 };
	nc::vector2 m_center;
	static const nc::vector2 s_points[];
};

