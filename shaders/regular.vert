// INPUTS

// The vertex position (its coordinates).
layout (location = 0) in vec3 aPosition;

// The texture coordinates associated with the vertex.
layout (location = 1) in vec2 aTextureCoordinates;

// The normal vector defined for the vertex.
layout (location = 2) in vec3 aNormal;

// OUTPUTS

// The fragment position (its coordinates). 
out vec3 bPosition;

// The texture coordinates associated with the fragment.
out vec2 bTextureCoordinates;

// The transformed normal vector to the fragment.
out vec3 bNormal;

// UNIFORMS

// The transformation matrices.
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// The normal matrix.
uniform mat3 normalMatrix;

void main() {
	
	// Forwarding the fragment coordinates in world space.
	bPosition = vec3(model * vec4(aPosition, 1.0));

	// Forwarding the fragment texture coordinates.
	bTextureCoordinates = aTextureCoordinates;

	// Forwarding the fragment transformed normal vector.
	bNormal = normalMatrix * aNormal;

	// Setting the vertex position.
	gl_Position = projection * view * model * vec4(aPosition, 1.0);
}