#ifndef Patch_H_INCLUDED
#define Patch_H_INCLUDED

class Patch
{
    public:

        enum Kind
        {
            american,
            crab,
            kentuckyBlue,
            bamboo
        };
        Patch(Patch::Kind kind, int tally);
        const sf::RectangleShape& getDraw();

        const int getTally();
        void grow();
        void spread();

        struct jobClass
        {
            int limit;
            int might;
            int ward;
        };

    private:

        Patch::Kind kind;
        int tally;
        sf::RectangleShape drawing;
        sf::Clock growClock;
};

#endif // Patch_H_INCLUDED
