#pragma once

namespace Nucleus {

	class Shader {
	private:
		unsigned int CompileShader(int type, std::string& shader);
	
	public:
		Shader(std::string& fragmentShader, std::string& vertexShader);
		~Shader();

		void Bind();
		void UnBind();

		const void SetUniform4f(const char* uniformName, float v1, float v2, float v3, float v4) const;
		const void SetUniform3f(const char* uniformName, float v1, float v2, float v3) const;
		const void SetUniform1f(const char* uniformName, float v) const;
		const void SetUniform1i(const char* uniformName, int value) const;
		const void SetUniformMatrix4fv(const char* uniformName, int count, unsigned char transpose, float* value);

	private:
		uint32_t m_RendererID;
	};
}

