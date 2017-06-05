#ifndef _SAMPLE_CODE_BANANA_H_
#define _SAMPLE_CODE_BANANA_H_

class Banana{

    public:
        Banana(void); // Constructor
        ~Banana(void); // Destructor
        int getX(); // Return X location
        int getY(); // Return Y location
        void setX(int x); // Set X location
        void setY(int y); // Set Y location

    private:
        int xPos; // X location of Apple
        int yPos; // Y location of Apple
};
#endif
