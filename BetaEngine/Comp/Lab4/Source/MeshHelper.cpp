#include "stdafx.h"
#include "MeshHelper.h"
using namespace Beta;
// Create a colored mesh consisting of a single triangle using the Beta Framework.
// Params:
//   color0 = The color of vertex 0.
//   color1 = The color of vertex 1.
//   color2 = The color of vertex 2.
// Returns:
//	 A pointer to the newly created mesh.
Beta::Mesh *CreateTriangleMesh(const Beta::Color &color0, const Beta::Color &color1, const Beta::Color &color2)
{
	MeshFactory &meshFactory = *EngineGetModule(MeshFactory);
	meshFactory.AddTriangle(Vertex(Vector2D(1, 0.3f), color0),
							Vertex(Vector2D(-0.3f, 1), color1),
							Vertex(Vector2D(0.3f, -1), color2));
	Mesh *mesh = meshFactory.EndCreate();
	if (mesh == nullptr)
		std::cout << "Failed to create mesh!" << std::endl;
	return nullptr;
}

/*/ 
	Create a textured quad mesh using the Beta Framework.
    Params:
        textureSize = The UV size of the mesh, in texture coordinates.
    	    extents = The XY distance of the vertices from the origin.
    Returns:
	A pointer to the newly created mesh.
/*/

Beta::Mesh *CreateQuadMesh(const Beta::Vector2D &textureSize, const Beta::Vector2D &extents)
{
	// This shape has 2 triangles
	// Vertex(Vector2D(x, y), Vector2D(u, v))
	MeshFactory &meshFactory = *EngineGetModule(MeshFactory);

	meshFactory.AddTriangle(Vertex(Vector2D(-extents.x, -extents.y), Vector2D(0.0f, textureSize.y)), Vertex(Vector2D(extents.x, -extents.y), Vector2D(textureSize.x, textureSize.y)), Vertex(Vector2D(-extents.x, extents.y), Vector2D(0.0f, 0.0f)));
	meshFactory.AddTriangle(Vertex(Vector2D(extents.x, -extents.y), Vector2D(textureSize.x, textureSize.y)), Vertex(Vector2D(extents.x, extents.y), Vector2D(textureSize.x, 0.0f)), Vertex(Vector2D(-extents.x, extents.y), Vector2D(0.0f, 0.0f)));
	Mesh *mesh = meshFactory.EndCreate();

	// Saving the mesh (list of triangles) in mesh pointerMesh* mesh = meshFactory.EndCreate();
	if (mesh == nullptr)
		std::cout << "Failed to create mesh!" << std::endl;

	return nullptr;
}
