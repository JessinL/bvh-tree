#ifndef BVH_TREE_H_
#define BVH_TREE_H_

#include "bvhnode.h"
#include <algorithm>

class bvhTree_{
public:
    bvhTree_() {}
    ~bvhTree_() {}

    inline int setobject(const std::vector<double>& vertices, const std::vector<int>& facets);

    inline int setmaxfacetsnum(const int& maxfacetsnum);

    inline int setmaxdepth(const int& maxdepth);

    inline bvhNode_* getroot() const;

    inline int getdepth() const;

    inline int getmaxdepth() const;

    inline int buildtree();

    inline int dividenode(bvhNode_* node, const int& divideaxis);

    int rayobjectintersectionfinder(
        const Vector& raystartingpoint, const Vector& raydirection
    );

protected:
    bvhNode_* root_{nullptr};
    int depth_{0};

    int maxdepth_{10};

    // max facets num of every node
    int maxfacetsnum_{0};

    // triangle facet object
    std::vector<double> vertices_;
    std::vector<int> facets_;
};

#endif // BVH_TREE_H_