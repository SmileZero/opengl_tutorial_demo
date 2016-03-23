#version 150

in vec3 mColor;
out vec4 finalColor;

void main() {
    finalColor = vec4(mColor, 1.0);
}
