#include <iostream>
#include <vector>

enum class TreeType {
	UNKOWN = -1,
	OAK,
	BIRCH,
	SPRUCE
};

class Tree;

//============================================

class Tree {
public:

	virtual void wind() = 0;
	virtual ~Tree() = default;
	auto getType() { return _treeType; }

protected:
	TreeType _treeType;
};

//============================================

class Forest {
public:
	virtual void add(Tree* other) = 0;
	virtual ~Forest() = default;
	void wind(){
		for (int i = 0; i < _trees.size(); ++i) {
			_trees[i]->wind();
		}
	}

protected:
	std::vector<Tree*> _trees;
};

//============================================

class OakTree : public Tree {
public:
	OakTree() {
		++_treeCountOak;
		_treeType = TreeType::OAK;
	}
	void wind() override{
		std::cout << "oak\n";
	}
	static int _treeCountOak;
};
class BirchTree : public Tree {
public:
	BirchTree() {
		++_treeCountBirch;
		_treeType = TreeType::BIRCH;
	}
	void wind() override{
		std::cout << "birch\n";
	}
	static int _treeCountBirch;
};
class SpruceTree : public Tree {
public:
	SpruceTree() {
		++_treeCountSpruce;
		_treeType = TreeType::SPRUCE;
	}
	void wind() override{
		std::cout << "spruce\n";
	}
	static int _treeCountSpruce;
};

//=================================================

class coniferForest : public Forest {
public:
	void add(Tree* other) override{
		auto type = other->getType();
		if(type == TreeType::OAK || type == TreeType::BIRCH)
		_trees.push_back(other);
	}
private:

};
class leafForest : public Forest {
public:
	void add(Tree* other) override{
		auto type = other->getType();
		if (type == TreeType::SPRUCE)
			_trees.push_back(other);
	}
private:

};

//=================================================

int OakTree::_treeCountOak = 0;
int BirchTree::_treeCountBirch = 0;
int SpruceTree::_treeCountSpruce = 0;

//=================================================

int main() {
	OakTree Oak1;
	BirchTree Birch1;
	BirchTree Birch2;
	SpruceTree Spruce1;

	leafForest leafForest1;
	coniferForest coniferForest1;

	leafForest1.add(&Oak1);
	leafForest1.add(&Birch1);
	leafForest1.add(&Birch2);
	leafForest1.add(&Spruce1);
	leafForest1.wind();

	coniferForest1.add(&Oak1);
	coniferForest1.add(&Birch1);
	coniferForest1.add(&Birch2);
	coniferForest1.add(&Spruce1);
	coniferForest1.wind();

	std::cout << "There are " << OakTree::_treeCountOak << " oak trees\n";
	std::cout << "There are " << BirchTree::_treeCountBirch << " birch trees\n";
	std::cout << "There are " << SpruceTree::_treeCountSpruce << " spruce trees\n";
}