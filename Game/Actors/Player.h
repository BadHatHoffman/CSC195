#pragma once
#include "Object/Actor.h"

class Player : public nc::Actor
	{
	public:
		Player() {}
		virtual ~Player() {}

		virtual eType GetType() { return eType::PLAYER; }

		virtual bool Load(const std::string& filename) override;

		virtual void Update(float dt) override;
		virtual void Draw(Core::Graphics& graphics)override;

		virtual void OnCollission(Actor* actor);

	protected:
		float m_thrust;
		float m_rotationRate;
		float m_fireRate{ 0.5f };
		float m_fireTimer{ 0.0f };
		nc::Vector2 m_velocity;
	};
