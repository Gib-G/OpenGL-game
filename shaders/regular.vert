// INPUTS

// The vertex position (its coordinates).
layout (location = 0) in vec3 vertexPosition;

// The texture coordinates associated with the vertex.
layout (location = 1) in vec2 vertexTextureCoordinates;

// The normal vector defined for the vertex.
layout (location = 2) in vec3 vertexNormal;

// OUTPUTS

// The fragment position (its coordinates). 
out vec3 fragmentPosition;

// The texture coordinates associated with the fragment.
out vec2 fragmentTextureCoordinates;

// The transformed normal vector to the fragment.
out vec3 fragmentNormal;

// UNIFORMS

// The transformation matrices.
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// The normal matrix.
// Projects the normals to VIEW SPACE (not world space).
// In the fragment shader, the illumination calculations 
// are done in view space.
uniform mat3 normalMatrix;

void main() {

	vec4 temp = view * model * vec4(vertexPosition, 1.0);
	
	// Forwarding the fragment coordinates in world space.
	fragmentPosition = vec3(temp);

	// Forwarding the fragment texture coordinates.
	fragmentTextureCoordinates = vertexTextureCoordinates;

	// Forwarding the fragment transformed normal vector.
	fragmentNormal = normalMatrix * vertexNormal;

	// Setting the vertex position.
	gl_Position = projection * temp;
}