#include "Collision.h"
#include <cmath>

std::unordered_map<std::string, Vector2Tuple2> Collision::_list;

void Collision::Declare()
{
	_list.clear();
}

void Collision::Regist(const std::string& name, const Vector2Tuple2 x)
{
	_list.insert(std::make_pair(name, x));
}

bool Collision::isHit(const std::string& name1, const std::string& name2) const
{
	const Vector2Tuple2 Object1(_list.at(name1));
	const Vector2Tuple2 Object2(_list.at(name2));
	const float object1Width = Object1._b.GetX() - Object1._a.GetX();
	const float object1Height = Object1._b.GetY() - Object1._a.GetY();
	const float object2Width = Object2._b.GetX() - Object2._a.GetX();
	const float object2Height = Object2._b.GetY() - Object2._a.GetY();
	const Vector2 center1((object1Width) / 2.0f + Object1._a.GetX(), (object1Height) / 2.0f + Object1._a.GetY());
	const Vector2 center2((object2Width) / 2.0f + Object2._a.GetX(), (object2Height) / 2.0f + Object2._a.GetY());
	const Vector2 distance(std::abs(center1.GetX() - center2.GetX()), std::abs(center1.GetY() - center2.GetY()));
	const Vector2 size_sum((object1Width + object2Width) / 2.0f, (object1Height + object2Height) / 2.0f);
	if (distance.GetX() < size_sum.GetX() && distance.GetY() < size_sum.GetY()) return true;
	return false;
}