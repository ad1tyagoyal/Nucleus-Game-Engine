#include "NclPch.h"
#include "Shader.h"

#include "glad/glad.h"

namespace Nucleus {


	unsigned int Shader::CompileShader(int type, std::string& shader) {
		unsigned int shaderProgram = glCreateShader(type);
		const char* src = shader.c_str();
		glShaderSource(shaderProgram, 1, &src, 0);
		glCompileShader(shaderProgram);
		return shaderProgram;
	}

	Shader::Shader(std::string& fragmentShader, std::string& vertexShader) {

		m_RendererID = glCreateProgram();

		unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(m_RendererID, vs);
		glAttachShader(m_RendererID, fs);

		glLinkProgram(m_RendererID);
		glValidateProgram(m_RendererID);
	}

	Shader::~Shader() {
	}


	void Shader::Bind() {
		glUseProgram(m_RendererID);
	}

	void Shader::UnBind() {
		glUseProgram(0);
	}


	const void Shader::SetUniform4f(const char* uniformName, float v1, float v2, float v3, float v4) const {
		int location = glGetUniformLocation(m_RendererID, uniformName);
		glUniform4f(location, v1, v2, v3, v4);
	}

	const void Shader::SetUniform3f(const char* uniformName, float v1, float v2, float v3) const {
		int location = glGetUniformLocation(m_RendererID, uniformName);
		glUniform3f(location, v1, v2, v3);
	}

	const void Shader::SetUniform1f(const char* uniformName, float v) const {
		int location = glGetUniformLocation(m_RendererID, uniformName);
		glUniform1f(location, v);
	}

	const void Shader::SetUniform1i(const char* uniformName, int value) const {
		int location = glGetUniformLocation(m_RendererID, uniformName);
		glUniform1i(location, value);
	}

	const void Shader::SetUniformMatrix4fv(const char* uniformName, int count, unsigned char transpose, float* value) {
		int location = glGetUniformLocation(m_RendererID, uniformName);
		glUniformMatrix4fv(location, count, transpose, value);
	}


}
