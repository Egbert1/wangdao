#ifndef __LINE_H__
#define __LINE_H__

class Line
{
public:
    Line(int,int,int,int);
    ~Line();
    class LineImpl;
    void printLine() const;
private:
    LineImpl * _pImpl;
};

#endif



