#pragma once

#include <string>
#include <unordered_map>
#include "VectorTuple.h"

class Collision final
{
public:
	explicit Collision() = default;
	~Collision() = default;

	void Declare();
	void Regist(const std::string& name, const Vector2Tuple2 x);
	bool isHit(const std::string& name1, const std::string& name2) const;
private:
	static std::unordered_map<std::string, Vector2Tuple2>  _list;
};

