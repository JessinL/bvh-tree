#ifndef BVH_NODE_H_
#define BVH_NODE_H_

#include "vector.h"
#include <vector>

class bvhNode_{
public:
    bvhNode_() {}
    ~bvhNode_() {}
    inline bvhNode_(const bvhNode_& bvhNode);

    inline int setminxyz(const Vector& minxyz);
    inline int setmaxxyz(const Vector& maxxyz);

    inline int setleaf();
    inline int setinternal();

    inline int setleftchild(bvhNode_* child);
    inline int setrightchild(bvhNode_* child);

    /**
     * @brief set some facets to a leaf node
     * @note only leaf node could be set
     * 
     * @param facetids 
     * @return int 
     */
    inline int setfacets(const std::vector<int>& facetids);

    inline Vector getminxyz() const;
    inline Vector getmaxxyz() const;
    
    inline bool isleaf() const;
    inline bool isinternal() const;

    inline bvhNode_* getleftchild() const;
    inline bvhNode_* getrightchild() const;

    inline std::vector<int> getfacetids() const;

    inline int divide(
        const int& divideaxis, 
        const Vector& leftminxyz, const Vector& leftmaxxyz,
        const Vector& rightminxyz, const Vector& rightmaxxyz,
        const std::vector<int>& leftfacetids, const std::vector<int>& rightfacetids
    );

    inline int raynodeintersectionfinder(
        const Vector& raystartingpoint, const Vector& raydirection
    );

private:
    Vector aabbminxyz_;
    Vector aabbmaxxyz_;
    bool isleaf_{true};

    // for internal nodes
    bvhNode_* leftchild_{nullptr};
    bvhNode_* rightchild_{nullptr};
    int divideaxis_{-1};

    // for leaf nodes
    std::vector<int> facetids_;
};

#endif // BVH_NODE_H_