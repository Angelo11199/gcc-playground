#include <iostream>
using namespace std;
int main()
{
    int rows,columns;

    for (rows = 1; rows <= 6; rows++)
    {
        
        for (columns = 0; columns <= 6; columns++)
        {
            cout << "=" << "";
            if(columns == 6)
            {
                cout << "||";
            }
        }
                    if(rows == 1)
            {
                cout << "||";
            }

        
        cout << "\n";
    }
    
    
    return 0;
}