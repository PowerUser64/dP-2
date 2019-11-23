#include "stdafx.h"
#include "Lab2.h"
#include "Animator.h"
#define col Beta::Colors
#define p pointP
#define v vectorV
#define u vectorU

// for hexagon (drawn twice)
#define s ((p + (v * 2) / 3) + (u / 3))
#define t (p + (v * 2) / 3)
#define w ((p + (u * 2) / 3) + (v / 3))
#define x (p + v / 3)
#define y (p + (u * 2) / 3)
#define z (p + u / 3)

//without p
#define x_ (v / 3)
#define z_ (u / 3)

// for diamondcut
#define b (p + (x_ - z_))
#define c (p + (z_ - x_))

#define a (x_ + x_ + b)
#define d (z_ + z_ + c)
#define e (z_ + z_ + x_ + z_ + p)
#define f (x_ + x_ + z_ + x_ + p)

/*
 *
 *            P+v
 *            /\
 *           /   \
 *          /      \
 *         /         \
 *        /      ___---\
 *       /____---      P+u
 *      P
 */
/*                v /\
 *  (p+(v*2)/3) t _____ s ((p+(v*2)/3) + (p+u/3))
 *              /      \ 
 *  (p+v/3) x /         \ w ((p+(u*2)/3) + (p+v/3))
 *            \        / 
 *        /_   \_____/   _\ u
 *      p      z    y
 *     (p+u/3)^    ^(p+(u*2)/3)
 */
/*      
 *                           v
 *             (t+b)  a _________ f (s+x)
 *                    /    /\    \
 *                  /  t _____ s  \
 *                /    /      \    \ 
 *            b /  x /         \ w  \ e
 *             \     \        /     /
 *           p  \/_   \_____/   _\/  
 *               \    z    y    /  u
 *              c \___________/ d
 */

using namespace Beta;

const Vector2D &Lab2::pointP = Animator::GetPointP();
const Vector2D &Lab2::vectorU = Animator::GetVectorU();
const Vector2D &Lab2::vectorV = Animator::GetVectorV();

Lab2::Lab2()
	: BetaObject("Lab2")
{
}

void Lab2::Initialize()
{
	std::cout << "Lab2:Initialize" << std::endl;
}

void Lab2::Update(float dt)
{
	DebugDraw &debug = *EngineGetModule(DebugDraw);
	GraphicsEngine &graphics = *EngineGetModule(GraphicsEngine);
	Input &input = *EngineGetModule(Input);

	// call things to draw
	switch (expression)
	{
	case /* constant-expression */:
		/* code */
		break;
	
	default:
		break;
	}
	debug.EndLineList(graphics.GetDefaultCamera());
}

void Lab2::DrawLine(const Beta::Vector2D &start, const Beta::Vector2D &end, const Beta::Color color = Beta::Colors::Green)
{
	// Obtain necessary modules, etc.
	DebugDraw &debug = *EngineGetModule(DebugDraw);
	debug.AddLineToList(start, end, color);
}

void Lab2::CreateTriangle()
{
	DrawLine(p, u + p);
	DrawLine(p, v + p);
	DrawLine(u + p, v + p);
}

void Lab2::CreateParallelogram()
{
	DrawLine(p, u + p);
	DrawLine(p, v + p);
	DrawLine(p + u, p + v);
	DrawLine(p + v, p + v + u);
	DrawLine(p + u, p + v + u);
}

void Lab2::CreateTriforce()
{
	// outside
	DrawLine(p, u + p);
	DrawLine(p, v + p);
	DrawLine(u + p, v + p);
	/*
	 *    V _________ U
	 *      \  /\  /
	 *      \/__\/
	 *      \  /
	 *      \/
	 *      P
	 */
	// inside
	// pu to pv
	DrawLine(p + u / 2, p + v / 2);
	// uv to pv
	DrawLine(((p + u) + (p + v)) / 2, p + v / 2);
	// uv to pu
	DrawLine(((p + u) + (p + v)) / 2, p + u / 2);
}

void Lab2::CreateFace()
{
}

void Lab2::CreateHexagon()
{
	/*                v /\
	 *  (p+(v*2)/3) t _____ s ((p+(v*2)/3) + (p+u/3))
	 *              /      \ 
	 *  (p+v/3) x /         \ w ((p+(v*2)/3) + (p+v/3))
	 *            \        / 
	 *        /_   \_____/   _\ u
	 *      p      z    y
	 *     (p+u/3)^     ^(p+(v*2)/3)
	 */
	DrawLine(s, t);
	DrawLine(t, x);
	DrawLine(x, z);
	DrawLine(z, y);
	DrawLine(y, w);
	DrawLine(w, s);
}

void Lab2::CreateDiamondCut()
{
	CreateHexagon();
	/*      
	 *                           v
	 *                    a _________ f
	 *                    /    /\    \
	 *                  /  t _____ s  \
	 *                /    /      \    \ 
	 *            b /  x /         \ w  \ e
	 *             \     \        /     /
	 *           p  \/_   \_____/   _\/  
	 *               \    z    y    /  u
	 *              c \___________/ d
	 *       
	 *       
	 */
	// large hexagon
	DrawLine(a, b);
	DrawLine(b, c);
	DrawLine(c, d);
	DrawLine(d, e);
	DrawLine(e, f);
	DrawLine(f, a);

	// connect large hexagon to small hexagon
	DrawLine(a, t);
	DrawLine(b, x);
	DrawLine(c, z);
	DrawLine(d, y);
	DrawLine(e, w);
	DrawLine(f, s);
}

void Lab2::Shutdown()
{
}
