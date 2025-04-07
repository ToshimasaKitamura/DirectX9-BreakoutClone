#pragma once

class Error final
{
public:
	explicit Error() = default;
	~Error() = default;

	void Issue(const char* str) const;
};

