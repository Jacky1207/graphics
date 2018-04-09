#ifndef INODE_H
#define INODE_H

#include <QList>
#include <QPoint>

class INode
{
public:
    INode(const int index, INode *parent = 0);
    ~INode();

    void addChildNode(INode *node);
    QPoint getChildNodePoint(const int index);
    void setChildNodePoint(const QPoint point);
    void setChildNodePoint(const int x, const int y);
    int getChildNodeRotate(const int index) const { return index * _kdefault_rotate; }

    inline INode *getParentNode() const { return _node_parent; }
    inline INode *getChildNodeOfIndex(const int index) const { return _node_child_list.at(index); }
    inline int getChildNodeSize() const { return _node_child_list.size(); }
    inline int getNodeIndex() const { return _node_index; }
    inline float getNodeRotate() const { return _node_rotate; }
    inline int x() const { return _node_x; }
    inline int y() const { return _node_y; }
private:
    float initNodeRotate(const int index);
private:
    const int _kdefault_rotate = 30;
    const int _kdefault_radius = 200;

    int _node_x;
    int _node_y;
    int _node_index;
    float _node_rotate;
    INode * _node_parent;

    QList<INode *> _node_child_list;
};

#endif // INODE_H
