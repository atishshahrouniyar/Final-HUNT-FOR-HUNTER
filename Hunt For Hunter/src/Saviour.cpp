#include "Saviour.h"
#include"SDL.h"


Saviour::Saviour()
{
	spriteNum = 18;
}


Saviour::~Saviour()
{
}

void Saviour::init(float speed, glm::vec2 pos, GameEngine::keyHandler* keyHandler)
{
	_speed = speed;
	_position = pos;
	_keyHandler = keyHandler;
	_color.r = 242;
	_color.g = 147;
	_color.b = 106;
	_color.a = 255;


}

void Saviour::update(const std::vector<std::string>& levelData,
	std::vector<Animal*>& animals,
	std::vector <Poachers*>& poachers)
{
	if (_keyHandler->iskeyPressed(SDLK_w))
	{
		if (spriteNum < 0 || spriteNum >= 8)
			spriteNum = 0;
		spriteNum++;
		_position.y += _speed;
	}
	else if (_keyHandler->iskeyPressed(SDLK_s))
	{
		if (spriteNum < 20 || spriteNum >= 28)
			spriteNum = 20;
		spriteNum++;
		_position.y -= _speed;
	}
	if (_keyHandler->iskeyPressed(SDLK_a))
	{
		if (spriteNum < 10 || spriteNum >= 18)
			spriteNum = 10;
		spriteNum++;
		_position.x -= _speed;
	}
	else if (_keyHandler->iskeyPressed(SDLK_d))
	{
		if (spriteNum < 30 || spriteNum >= 38)
			spriteNum = 30;
		spriteNum++;
		_position.x += _speed;
	}

	spriteFile = std::to_string(spriteNum) + std::string(".png");


	CollideWithLevel(levelData);

}
