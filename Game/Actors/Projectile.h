#pragma once
#include "Object/Actor.h"



class Projectile : public nc::Actor
{
public:
	Projectile() = default;
	virtual ~Projectile() {}

	virtual eType GetType() { return eType::PROJECTILE; }

	virtual bool Load(const std::string& filename) override;

	virtual void Update(float dt) override;

	virtual void OnCollission(Actor* actor);

	virtual void Draw(Core::Graphics& graphics)override;

	void setThrust(float thrust) { m_thrust = thrust; }

	
protected:
	float m_thrust{ 0.0f };
	float m_lifetime{};
};


