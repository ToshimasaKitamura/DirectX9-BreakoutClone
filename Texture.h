#pragma once

#include <string>

class Texture final
{
public:
	explicit Texture() = default;
	~Texture() = default;
	void CreateTexture(const std::string& fileName) const;
	void ReleaseTexture(const std::string& fileName) const;
};

