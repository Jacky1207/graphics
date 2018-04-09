#ifndef INODEINFORMATION_H
#define INODEINFORMATION_H

#include <QList>

class INodeInformation
{
public:
    INodeInformation(INodeInformation *parent = 0);
    INodeInformation(const QString str, INodeInformation *parent = 0);
    ~INodeInformation();

    void addChild(INodeInformation *child);
    void setChildIndex(const int index) { _index = index; }
    void setNodePoint(const int x, const int y);
    void setNodePoint(const QPoint point);
    QString getNodeText() const {return _node_text;}

    int x() const { return _node_x; }
    int y() const { return _node_y; }

    QPoint getChildPoint(const int index);

    int getChildNodeSize() const {return _child.size();}
    INodeInformation* getChildNode(const int index) const;
    INodeInformation* getParentNode()const {return _parent;}
    int getChildNodeRotate(const int index) const{ return index * _kdefault_rotate; }
    inline int getNodeRotate() const {return _index *_kdefault_rotate; }
//    inline int getNodeRotate() const { return _node_rotate;}
private:
    INodeInformation *_parent;
    QList<INodeInformation *> _child;
    int _index;     //
    const int _kdefault_rotate = 30;
    const int _kdefault_radius = 200;

    int _node_rotate;

    QString _node_text;

    int _node_x;
    int _node_y;
};

#endif // INODEINFORMATION_H
