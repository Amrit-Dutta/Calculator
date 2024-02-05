// this program uses user unputs and calculates the uncertanty

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x, y, ux, uy; // variables, and coresponding uncertainty
    char op;             // the mathimatical function the user would like to do
    double ans, uans;    // the calculated value and the coresponding uncertainty

    // bool repeat = 0; //keep calculating
    // using type instead

    int type; // the type of calculation the user would like to do

    do // reapeat if wanted
    {

        // promt user to enter the calculation type
        cout << "Enter 0 - power off" << endl
             << "Enter 1 - uncertanty of two terms" << endl
             << "Enter 2 - standard deviation:" << endl;

        // read the calculation type
        cin >> type;

        if (type == 1)
        {

            // promt user to enter the values
            cout << "Enter: [x uncertanty operator y uncertanty] in this order: ";

            // read the user input values
            cin >> x >> ux >> op >> y >> uy;

            // if multiplication
            if (op == '*')
            {
                ans = x * y;
            }

            // if divition
            else if (op == '/')
            {
                ans = x / y;
            }

            // if adition
            else if (op == '+')
            {
                ans = x + y;
            }

            // if subtraction
            else if (op == '-')
            {
                ans = x - y;
            }

            if ((op == '*') || (op == '/'))
            {
                uans = ((ux / x) + (uy / y)) * ans;
            }

            else if ((op == '+') || (op == '-'))
            {
                uans = ux + uy;
            }

            // display result
            cout << endl << "=" << ans << " +/_ " << uans << endl << endl;

        }

        if (type == 2)
        {
            int n;      // ammount of therms to deviate
            double avg; // avrage of the terms

            double a, b, c, d;
            // promt user to enter the terms to deviate
            cout << "number of terms to deviate: ";

            // read the ammount of terms
            cin >> n;

            // promt user to enter the 2 values to take deviation from
            cout << "enter " << n << " variables:";

            switch (n)
            {
            case 2:

                // read the n variables
                cin >> a >> b;

                // calculate avrage
                avg = (a + b) / 2;

                // calculation
                ans = pow((pow((a - avg), 2) * pow((b - avg), 2)) / (--n), .5);

                n += 1;
                break;

            case 3:

                // read the n variables
                cin >> a >> b >> c;

                // calculate avrage
                avg = (a + b + c) / n;

                // calculation
                ans = pow((pow((a - avg), 2) * pow((b - avg), 2) * pow((c - avg), 2)) / (--n), .5);

                n += 1;
                break;

            case 4:

                // read the n variables
                cin >> a >> b >> c >> d;

                // calculate avrage
                avg = (a + b + c + d) / n;

                // calculation
                ans = pow((pow((a - avg), 2) * pow((b - avg), 2) * pow((c - avg), 2) * pow((d - avg), 2)) / (--n), .5);

                n += 1;
                break;
            }

            cout << endl << "The standard deviation is: " << ans << endl << endl ;
        }

    } while (type > 0);
}