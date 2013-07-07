#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/gl.h>
#include <map>

#include "model.hpp"
#include "camera.hpp"

class Shader;
class VertexShader;
class FragmentShader;
class ShaderProgram;

class Shader {
	public:
		~Shader();
	protected:
		GLint id;

		void 								load(std::string filename);
		virtual std::string loadCode(std::string filename);
};

class VertexShader : Shader {
	public:
		VertexShader(std::string filename);
	protected:
		std::string loadCode(std::string filename);
	friend class ShaderProgram;
};

class FragmentShader : Shader {
	public:
		FragmentShader(std::string filename);
	friend class ShaderProgram;
};

class ShaderProgram {
	public:
		ShaderProgram(VertexShader&, FragmentShader&);

		template<class T>
		void setUniform(std::string, T);
		bool isSet(std::string);
		void draw(Model&, glm::mat4 M, glm::mat4 V, glm::mat4 P);
    void draw(Model&, glm::vec3 center, Camera &c);
    void draw(Model&, glm::mat4 M, Camera &c);
    void draw(Model&, glm::mat4 M, glm::mat4 V);
    void draw(Model&);
    
	protected:
		GLint getUniformLocation(std::string);
		void prepareContext();

		GLint id;
		VertexShader &vshader;
		FragmentShader &fshader;
		std::map<std::string, GLint> uids;

		std::map<GLint, int> ints;
		std::map<GLint, float> floats;
		std::map<GLint, glm::vec4> vec4s;
		std::map<GLint, glm::vec3> vec3s;
		std::map<GLint, glm::vec2> vec2s;
		std::map<GLint, glm::mat4> mat4s;
};

#endif