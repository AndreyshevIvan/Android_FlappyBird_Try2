#ifndef __BIRD_H__
#define __BIRD_H__

#include "cocos2d.h"
#include "constants.h"
#include "sound.h"
#include <cmath>

enum struct BirdStatus
{
	IDLE,
	FLAPPING,
	DEAD,
};

class Bird : public cocos2d::Node
{
public:
	Bird();

	void update(float dt) override;

	void StartFlapping();
	void Jump();

	cocos2d::Point GetPosition();
	cocos2d::PhysicsBody* GetBody();
	void Reset();
	void Death();

private:
	GameSound m_audio;
	cocos2d::Sprite* m_body;
	cocos2d::Texture2D* m_aliveTexture;
	cocos2d::Texture2D* m_deadTexture;
	BirdStatus m_status;
	float m_topOfScreen;
	float m_idleAnimTime;
	float m_flappingAnimTime;

	void onEnter() override;
	void onExit() override;

	void Idle(float elapsedTime);
	void RotateBird(float elapsedTime);
	void FlappingAnimate(float elapsedTime);

	void ResetTexture();

};

#endif // __BIRD_H__