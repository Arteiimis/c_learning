#include <iostream>
#include <vector>
#include <cmath>

struct Vector3 { double x, y, z; };

struct Triangle { Vector3 v1, v2, v3; };

struct Material
{
	Vector3 ambient, diffuse, specular;
	double shininess;
};

struct Mesh
{
	std::vector<Triangle> triangles;
	Material material;
};

class Renderer
{
public:
	Renderer(int width, int height) : width(width), height(height)
	{
		framebuffer.resize(width * height);
	}

	void clear()
	{
		std::fill(framebuffer.begin(), framebuffer.end(), Vector3{ 0, 0, 0 });
	}

	void drawMesh(const Mesh& mesh)
	{
		for (const auto& triangle : mesh.triangles) {
			drawTriangle(triangle, mesh.material);
		}
	}

	void save(const std::string& filename)
	{
		// save framebuffer as image file

	}

private:
	int width, height;
	std::vector<Vector3> framebuffer;

	void drawTriangle(const Triangle& triangle, const Material& material)
	{
		// implement a simple rasterization algorithm to fill the triangle
		// calculate the color of each pixel using Phong shading model
	}
};

int main()
{
	// create a simple 3D scene
	Mesh mesh;
	mesh.triangles.push_back(Triangle{ {-1, 0, -1}, {1, 0, -1}, {0, 1, -1} });
	mesh.material.diffuse = { 1, 0, 0 };

	// create a renderer and render the scene
	Renderer renderer(640, 480);
	renderer.clear();
	renderer.drawMesh(mesh);
	renderer.save("output.png");

	return 0;
}