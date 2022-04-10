#ifndef BVH_NODE_H_
#define BVH_NODE_H_

#include "vector.h"
#include <vector>

class bvhNode_{
public:
    bvhNode_() {}
    ~bvhNode_() {}
    bvhNode_(const bvhNode_& bvhNode){
        aabbminxyz = bvhNode.aabbminxyz;
        aabbmaxxyz = bvhNode.aabbmaxxyz;
        isleaf = bvhNode.isleaf;
        leftChild = bvhNode.leftChild;
        rightChild = bvhNode.rightChild;
        divideAxis = bvhNode.divideAxis;
        facetids = bvhNode.facetids;
    }
    int setminxyz(const Vector& minxyz);
    int setmaxxyz(const Vector& maxxyz);
    int setleaf();

    int setLeftChild(bvhNode_* child);

private:
    Vector aabbminxyz;
    Vector aabbmaxxyz;
    bool isleaf{true};

    // for median nodes
    bvhNode_* leftChild{nullptr};
    bvhNode_* rightChild{nullptr};
    int divideAxis{-1};

    // for leaf nodes
    std::vector<int> facetids;
};

#endif // BVH_NODE_H_