#include "stdafx.h"
#include "Level1.h"

void Level1::Initialize()
{
	std::cout << "Level1:Initialize" << std::endl;
};

void Level1::Update(float dt)
{
	// Use Beta namespace
	using namespace Beta;
	Input& input = *EngineGetModule(Input);
	if (input.CheckTriggered('C'))
		cool_mode = !cool_mode;
	// Get DebugDraw system
	DebugDraw& debug = *EngineGetModule(DebugDraw);

	// Get GraphicsEngine system
	GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);
	// Store reference to default camera
	Camera& camera = graphics.GetDefaultCamera();

	// cool mode
	if (!cool_mode)
	{
		// Draw a white circle at 0,0 with radius 2
		Vector2D center = Vector2D(0.0f, 0.0f);
		float radius = 1;
		debug.AddCircle(Vector2D(center.x + 0, center.y + 0), radius, camera, Colors::White);
		debug.AddCircle(Vector2D(center.x + 1, center.y + 0), radius, camera, Colors::White);
		debug.AddCircle(Vector2D(center.x - 2, center.y + 0), radius, camera, Colors::White);

		// Draw a red line from 0,0 to 2,1.
		Vector2D start = Vector2D(0, 0);
		Vector2D end1 = Vector2D(0, 0);
		Vector2D end2 = Vector2D(0, 0);
		Vector2D end3 = Vector2D(0, 0);

		// half speed
		rad_pos1 += dt * 0.5;
		// normal speed
		rad_pos2 += dt;
		// double speed
		rad_pos3 += dt * 2;

		// half speed, Red
		end1.y = radius * cos(rad_pos1) + end2.y;
		end1.x = radius * sin(rad_pos1) + end2.x;

		// normal speed, Aqua
		end2.y = radius * cos(rad_pos2);
		end2.x = radius * sin(rad_pos2);

		// double speed, Violet
		end3.y = radius * cos(rad_pos3) + end1.y;
		end3.x = radius * sin(rad_pos3) + end1.x;

		debug.AddLineToList(Vector2D(end3.x, end3.y), Vector2D(end1.x - 2, end1.y), Colors::Red);
		debug.AddLineToList(Vector2D(start.x, start.y), Vector2D(end2.x, end2.y), Colors::Aqua);
		debug.AddLineToList(Vector2D(end2.x, end2.y), Vector2D(end3.x, end3.y), Colors::Violet);
	}

	// no cool mode
	else
	{
		// Draw a white circle at 0,0 with radius 2
		Vector2D center = Vector2D(0.0f, 0.0f);
		float radius = 1;
		debug.AddCircle(Vector2D(center.x + 0, center.y + 0), radius,		camera, Colors::White);
		debug.AddCircle(Vector2D(center.x + 1, center.y + 0), radius,		camera, Colors::White);
		debug.AddCircle(Vector2D(center.x - 2, center.y + 0), radius,		camera, Colors::White);

		// Draw a red line from 0,0 to 2,1.
		Vector2D start = Vector2D(0, 0);
		Vector2D end1 = Vector2D(0, 0);
		Vector2D end2 = Vector2D(0, 0);
		Vector2D end3 = Vector2D(0, 0);

		// length of one second relative to the simulation

		// half speed
		rad_pos1 += dt * 0.5;
		// normal speed
		rad_pos2 += dt;
		// double speed
		rad_pos3 += dt * 2;

		// half speed
		end1.y = radius * cos(rad_pos1);
		end1.x = radius * sin(rad_pos1);

		// normal speed
		end2.y = radius * cos(rad_pos2);
		end2.x = radius * sin(rad_pos2);

		// double speed
		end3.y = radius * cos(rad_pos3);
		end3.x = radius * sin(rad_pos3);

		debug.AddLineToList(Vector2D(start.x - 2, start.y), Vector2D(end1.x - 2, end1.y), Colors::Red);
		debug.AddLineToList(Vector2D(start.x, start.y), Vector2D(end2.x, end2.y), Colors::Aqua);
		debug.AddLineToList(Vector2D(start.x + 1, start.y), Vector2D(end3.x + 1, end3.y), Colors::Violet);
	}
	debug.EndLineList(camera);
	std::cout << "Level1:Update, dt==" << dt << std::endl;
};

void Level1::Shutdown()
{
	std::cout << "Level1:Shutdown" << std::endl;
};

Level1::Level1()
	: BetaObject("Level1")
{

}
