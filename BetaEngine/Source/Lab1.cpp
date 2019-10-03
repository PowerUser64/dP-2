#include "stdafx.h"
#include "Lab1.h"

Lab1::Lab1()
	: BetaObject("Lab1")
{

}

void Lab1::Initialize()
{
	std::cout << "Lab1:Initialize" << std::endl;
};

void Lab1::Update(float dt)
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
	if (cool_mode)
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
		rad_pos1 += dt * 0.5f;
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
		debug.AddCircle(Vector2D(center.x - 2.5, center.y + 0), radius + 1.0f,		camera, Colors::White);
		debug.AddCircle(Vector2D(center.x + 0.5, center.y + 0), radius,				camera, Colors::White);
		debug.AddCircle(Vector2D(center.x + 2,   center.y + 0), radius - 0.5f,		camera, Colors::White);

		// Draw a red line from 0,0 to 2,1.
		Vector2D start = Vector2D(0, 0);
		Vector2D end1 = Vector2D(0, 0);
		Vector2D end2 = Vector2D(0, 0);
		Vector2D end3 = Vector2D(0, 0);

		// Multiplier
		float M = 0.5;

		// one hour (at high speed) (Red)
		rad_pos1 += (dt * (3.0f * pi / 60.0f)) * M;
		// One minute (at high speed) (Aqua)
		rad_pos2 += (dt * 2.0f * pi) * M;
		// one second (at high speed) (Violet)
		rad_pos3 += (dt * 1.0f * pi * 60.0f) * M;

		// one hour (at high speed) (Red)
		end1.y = radius * cos(rad_pos1);
		end1.x = radius * sin(rad_pos1);

		// One minute (at high speed) (Aqua)
		end2.y = radius * cos(rad_pos2);
		end2.x = radius * sin(rad_pos2);

		// one second (at high speed) (Violet)
		end3.y = radius * cos(rad_pos3) - 0.5;
		end3.x = radius * sin(rad_pos3) - 0.5;

		debug.AddLineToList(Vector2D(start.x - 2.5, start.y), Vector2D(end1.x - 2.5, end1.y), Colors::Red);
		debug.AddLineToList(Vector2D(start.x + 0.5, start.y), Vector2D(end2.x + 0.5, end2.y), Colors::Aqua);
		debug.AddLineToList(Vector2D(start.x + 2,   start.y), Vector2D(end3.x + 2,   end3.y), Colors::Violet);
	}
	debug.EndLineList(camera);
	std::cout << "Lab1:Update, dt==" << dt << std::endl;
};

void Lab1::Shutdown()
{
	std::cout << "Lab1:Shutdown" << std::endl;
};
