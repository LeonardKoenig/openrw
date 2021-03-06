#ifndef INGAMESTATE_HPP
#define INGAMESTATE_HPP

#include "State.hpp"

class PlayerController;

class IngameState : public State
{
	enum CameraMode
	{
		CAMERA_CLOSE = 0,
		CAMERA_NORMAL = 1,
		CAMERA_FAR = 2,
		CAMERA_TOPDOWN = 3,
		/** Used for counting - not a valid camera mode */
		CAMERA_MAX
	};

	bool started;
    std::string save;
	bool newgame;
	ViewCamera _look;
	/** Player input */
	glm::vec3 _movement;
	glm::vec3 cameraPosition;
	/** Timer to hold user camera position */
	float autolookTimer;
	CameraMode camMode;

	/// Current camera yaw and pitch
	glm::vec2 m_cameraAngles;
public:
    /**
     * @brief IngameState
     * @param game
     * @param newgame
     * @param game An empty string, a save game to load, or the string "test".
     */
    IngameState(RWGame* game, bool newgame = true, const std::string& save = "");

	void startTest();
	void startGame();

	virtual void enter();
	virtual void exit();

	virtual void tick(float dt);
    virtual void draw(GameRenderer* r);

	virtual void handleEvent(const sf::Event& event);
	virtual void handlePlayerInput(const sf::Event& event);
	
	virtual bool shouldWorldUpdate();

	const ViewCamera& getCamera();
};

#endif // INGAMESTATE_HPP
