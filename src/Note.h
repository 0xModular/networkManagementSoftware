

#include <string>

class Note{

    Note();
    Note(int x, int y, std::string m);
    ~Note();

    int GetX();
	int GetY();
    std::string GetMessage();

	void SetX(int x);
	void SetY(int y);
    void SetMessage(std::string s);

    private:
        std::string message;
        int posX;
        int posY;



};