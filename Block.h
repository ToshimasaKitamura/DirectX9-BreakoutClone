#pragma once

#include <vector>
#include <array>
#include "A_MainObject.h"
#include "E_Stage.h"

class Block final : public A_MainObject
{
public:
	explicit Block() = default;
	~Block() = default;

	void CollisionRegist(E_Stage stage) const;
	void Update(E_Stage stage);
	void Draw(E_Stage stage) const;
	void Destroy(E_Stage stage);
	void GetActiveBlcok(E_Stage stage, std::array<bool, _blockHMax* _blockVMax>& blockArray);
	bool isBlockZero(E_Stage stage) const;
private:
	static std::array<std::array<bool, _blockHMax * _blockVMax>, (int)E_Stage::Max> _blockArray;
	static std::vector<int> _destroyBlockNumber;
}; 

