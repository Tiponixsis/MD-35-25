#include <iostream>
#include <vector>

enum class Type {
    UNKNOWN = -1,
    OAK,
    BIRCH,
    SPRUCE,
    MANGROVE,
    CHERRY
};
//=============================================================================
class Tree;

class Forest {
public:

    Forest() {
        std::vector<Tree*> trees;
        _trees = trees;
    };

    Forest(std::vector<Tree*> trees) {
        _trees = trees;
    }

    size_t get_tree_number() {
        return _trees.size();
    }

    void cutAll() {
        _trees.clear();
        std::cout << "All trees were cut down. \n";
    }

    void growTree(Tree* other) {
        _trees.push_back(other);
        std::cout << "[Tree added]\n";
    }

    Forest operator + (const Forest& other) const {
        std::vector<Tree*> treestemp;
        std::cout << "\nsumm\n";
        for (int i = 0; i < _trees.size(); ++i) {
            treestemp.push_back(_trees[i]);
        }
        for (int i = 0; i < other._trees.size(); ++i) {
            treestemp.push_back(other._trees[i]);
        }
        return Forest{ treestemp };
    }

    void printForest();

    void changeId();

private:
    std::vector<Tree*> _trees;
};

//==================================================================

class Tree {
public:

    Tree(Type type, Forest& forest){
        _id = _treeCount + 100;
        _type = type;
        ++_treeCount;
        forest.growTree(this);
        wind();
    }

    Tree(const Tree& other, Forest& forest) {
        _id = _treeCount + 100;
        _type = other._type;
        ++_treeCount;
        forest.growTree(this);
        wind();
    }

    int getId() const {
        return _id;
    }
    Type getName() const {
        return _type;
    }
    std::string typetostring(Type type) {
        switch (type) {
        case Type::OAK: return "Oak";
        case Type::BIRCH: return "Birch";
        case Type::SPRUCE: return "Spruce";
        case Type::MANGROVE: return "Mangrove";
        case Type::CHERRY: return "Cherry";
        default: return "Unknown";
        }
    }

    void wind() {
        std::cout << "Tree type: " << typetostring(getName()) << ", its id: " << getId() << "\n";
    }

    friend void Forest::changeId();
    friend void Forest::printForest();

private:
    static int _treeCount;
    int _id;
    Type _type;
};

//===================================================================

void Forest::changeId() {
    if (!_trees.empty()) {
        _trees[0]->_id = _trees[0]->_id + 100;
        std::cout << "\nnew id: " << _trees[0]->_id << "\n";
    }
}
void Forest::printForest() {
    if (!_trees.empty()) {
        std::cout << "There are " << get_tree_number() << " trees in this forest.\n============================\n";
        for (int i = 0; i < _trees.size(); ++i) {
            _trees[i]->wind();
        }
        std::cout << "============================\n";
    }
    else {
        std::cout << "The forest is empty.\n\n";
    }
}
int Tree::_treeCount = 0;

//=======================================================================

int main()
{
    std::cout << "Hello World!\n";
    Forest OakForest{};
    Tree Oak1{ Type::OAK, OakForest };
    Tree Oak2{ Oak1, OakForest };
    OakForest.printForest();
    OakForest.cutAll(); 
    OakForest.printForest();

    Forest BirchForest{};
    Forest MixedForest{};
    Tree Birch1{ Type::BIRCH, BirchForest };
    Tree Birch2{ Birch1, BirchForest };
    Tree Cherry1{ Type::CHERRY, MixedForest };
    Tree Spruce1{ Type::SPRUCE, MixedForest };

    BirchForest.printForest();
    MixedForest.printForest();

    MixedForest.changeId();
    MixedForest.printForest();

    Forest MixedForest2 = MixedForest + BirchForest;
    MixedForest2.printForest();
}
