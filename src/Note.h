

#include <string>

class Note{

    public:
    
    //constructors and deconstructor
    Note();
    Note(std::string m, int x, int y);
    ~Note();

    //getters
    int GetX();
	int GetY();
    std::string GetMessage();

    //setters
	void SetX(int x);
	void SetY(int y);
    void SetMessage(std::string s);


    private:

        //members
        std::string message;
        int posX;
        int posY;



};