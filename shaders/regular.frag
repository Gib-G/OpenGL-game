// NOTE :
// All illumination calculations are done in view space!!

struct Material {
	vec3 ambientLight;
	vec3 diffuseLight;
	vec3 specularLight;

	float shininess;

	// Set to default white textures if the model
	// does not have them.
	sampler2D ambientMap;
	sampler2D diffuseMap;
	sampler2D specularMap;
};

struct DirectionalLight {
	// Defined in world space.
	vec3 direction;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct PointLight {
	// Defined in world space.
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

// INPUTS

in vec3 bPosition;
in vec2 bTextureCoordinates;
in vec3 bNormal;

// OUTPUTS
out vec4 color;

// UNIFORMS

uniform Material material;
uniform DirectionalLight[10] directionalLights;
uniform PointLight[10] pointLights;



void main() {
	
}