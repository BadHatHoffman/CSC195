#include "painter.h"
#include "mathlib.h"


void Painter::Update(float dt)
{
	// switch shapes
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT))
	{
		if (m_shape)
		{
			delete m_shape;
			m_shape = nullptr;
		}
		m_shapeType = Shape::eType::LINE;
	}
	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT))
	{
		if (m_shape)
		{
			delete m_shape;
			m_shape = nullptr;
		}
		m_shapeType = Shape::eType::BOX;
	}

	// create shape
	if (m_shape == nullptr && Core::Input::IsPressed(Core::Input::BUTTON_LEFT))
	{
		m_shape = Shape::CreateShape(m_shapeType);
	}

	// add current shape to shapes
	if (m_shape && m_shape->Update(dt))
	{
		m_shapes.push_back(m_shape);
		m_shape = nullptr;
	}
}

void Painter::Draw(Core::Graphics& graphics)
{
	// draw shape name
	graphics.DrawString(10, 10, Shape::GetShapeName(m_shapeType));

	// draw current shape
	if (m_shape)
	{
		m_shape->Draw(graphics);
	}

	// draw all shapes
	if (!m_shapes.empty())
	{
		for (Shape* shape : m_shapes)
		{
			shape->Draw(graphics);
		}
	}
}

void Painter::Load(const std::string& filename)
{
	// open file stream
	std::ifstream stream;
	stream.open(filename);
	if (stream.is_open())
	{
		// read shapes
		while (!stream.eof())
		{
			int itype;
			stream >> itype;

			if (stream.eof()) break;

			Shape::eType type = static_cast<Shape::eType>(itype);
			Shape* shape = Shape::CreateShape(type);
			shape->Load(stream);

			m_shapes.push_back(shape);
		}
	}
}

void Painter::Save(const std::string& filename)
{
	// open file stream
	std::ofstream stream;
	stream.open(filename);
	if (stream.is_open())
	{
		// save shapes
		for (Shape* shape : m_shapes)
		{
			shape->Save(stream);
		}
	}
}

