#ifndef LAWN_H
#define LAWN_H

class Lawn
{
    public:
        Lawn(int scale, int w, int h);
        virtual ~Lawn();

        const int getScale();
        const std::map<int, std::map<int, Patch*>> getField();
        void update();

    protected:
    private:
        int scale;
        std::map<int, std::map<int, Patch*>> field;
};

#endif // LAWN_H
