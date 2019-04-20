#include "cube.hpp"

void Cube::Draw(float x, float y, float z, glm::vec3 color) {
	DrawBottomFace(x, y, z, color - glm::vec3(0.7f,0.7f,0.7f));
	DrawLeftFace(x, y, z, color - glm::vec3(0.4f,0.4f,0.4f));
	DrawRightFace(x, y, z, color - glm::vec3(0.4f,0.4f,0.4f));
	DrawFrontFace(x, y, z, color - glm::vec3(0.4f,0.4f,0.4f));
	DrawBackFace(x, y, z, color - glm::vec3(0.4f,0.4f,0.4f));
}

void Cube::DrawTopFace(float x, float y, float z, Texture texture) {
	glBegin(GL_POLYGON);
	glColor3f( 1.0f, 1.0f, 1.0f );
	glBindTexture(GL_TEXTURE_2D, *texture.data);
	glTexCoord2f( 1.0 , 1.0 ); glVertex3f( x + 0.5f, y + 0.5f, z + 0.5f );
	glTexCoord2f( 1.0 , 0.0 ); glVertex3f( x + 0.5f, y + 0.5f, z +-0.5f );
	glTexCoord2f( 0.0 , 0.0 ); glVertex3f( x +-0.5f, y + 0.5f, z +-0.5f );
	glTexCoord2f( 0.0 , 1.0 ); glVertex3f( x +-0.5f, y + 0.5f, z + 0.5f );
	glEnd();
}

void Cube::DrawBottomFace(float x, float y, float z, glm::vec3 color) {
	glBegin(GL_POLYGON);
	glColor3f( color.x, color.y, color.z );
    glVertex3f( x + 0.5f, y +-0.5f, z +-0.5f );
    glVertex3f( x + 0.5f, y +-0.5f, z + 0.5f );
    glVertex3f( x +-0.5f, y +-0.5f, z + 0.5f );
    glVertex3f( x +-0.5f, y +-0.5f, z +-0.5f );
	glEnd();
}

void Cube::DrawLeftFace(float x, float y, float z, glm::vec3 color) {
	glBegin(GL_POLYGON);
	glColor3f( color.x, color.y, color.z );
    glVertex3f( x +-0.5f, y +-0.5f, z + 0.5f );
    glVertex3f( x +-0.5f, y + 0.5f, z + 0.5f );
    glVertex3f( x +-0.5f, y + 0.5f, z +-0.5f );
    glVertex3f( x +-0.5f, y +-0.5f, z +-0.5f );
	glEnd();
}

void Cube::DrawRightFace(float x, float y, float z, glm::vec3 color) {
	glBegin(GL_POLYGON);
	glColor3f( color.x, color.y, color.z );
    glVertex3f( x + 0.5f, y +-0.5f, z +-0.5f );
    glVertex3f( x + 0.5f, y + 0.5f, z +-0.5f );
    glVertex3f( x + 0.5f, y + 0.5f, z + 0.5f );
    glVertex3f( x + 0.5f, y +-0.5f, z + 0.5f );
	glEnd();
}

void Cube::DrawFrontFace(float x, float y, float z, glm::vec3 color) {
	glBegin(GL_POLYGON);
	glColor3f( color.x, color.y, color.z );
    glVertex3f( x + 0.5f, y +-0.5f, z +-0.5f );
    glVertex3f( x + 0.5f, y + 0.5f, z +-0.5f );
    glVertex3f( x +-0.5f, y + 0.5f, z +-0.5f );
    glVertex3f( x +-0.5f, y +-0.5f, z +-0.5f );
	glEnd();
}

void Cube::DrawBackFace(float x, float y, float z, glm::vec3 color) {
	glBegin(GL_POLYGON);
	glColor3f( color.x, color.y, color.z );
    glVertex3f( x + 0.5f, y +-0.5f, z + 0.5f );
    glVertex3f( x + 0.5f, y + 0.5f, z + 0.5f );
    glVertex3f( x +-0.5f, y + 0.5f, z + 0.5f );
    glVertex3f( x +-0.5f, y +-0.5f, z + 0.5f );
	glEnd();
}