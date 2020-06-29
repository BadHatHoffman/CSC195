#pragma once
#include "core.h"
#include <vector>
#include "shape.h"

class Painter
{
public:
	Painter() {}
	~Painter() {}

	void Update(float dt);
	void Draw(Core::Graphics& graphics);
	virtual void Load(const std::string& filename);
	virtual void Save(const std::string& filename);

private:
	Shape::eType m_shapeType{ Shape::eType::LINE };

	Shape* m_shape{ nullptr };
	std::vector<Shape*> m_shapes;
};