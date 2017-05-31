#include <iostream>
#include <math.h>
#include <ctype.h>

using namespace std;

int main()
{
        int idisp;              // Integer mode display val
        char mode = 'd';        // Mode = 'd' or 'i' 
        double ddisp = 0.0;     // Double mode display val 

        // Loop until exited by a quit command.
        while(1)
        {
                // Display.
                if(mode == 'd') cout << "  " << ddisp << endl;
                else cout << "  " << idisp << endl;

                // Input a command.  We issue a prompt, skip leanding
                // blanks, read one non-blank which is our command, then
                // skip to the next digit, space, or lineend.
                char comd;              // Command character. 
                char ch;                // Other input character.
                cout << '>';
                if(cin >> comd) {
                        // Skip to a digit, space, lineend, or EOF.
                        while(cin.get(ch)) {
                                if(isspace(ch)) break;
                                if(isdigit(ch)) break;
                        }

                        // If we reached a digit, pretend we never saw it.
                        if(isdigit(ch)) cin.unget();
                } else
                        // If we reached EOF, pretend command is quit. 
                        comd = 'q';

                // Obey the command. 
                if(comd == 'q') break;
                switch(comd)
                {
                        int in;         // Integer input value.
                        double din;     // Double input value.
                case '=': // Enter.
                        if(mode == 'd')
                                cin >> ddisp;
                        else
                                cin >> idisp;
                        break;

                case '+': // Add.
                        if(mode == 'd')
                        {
                                cin >> din;
                                ddisp += din;
                        }
                        else
                        {
                                cin >> in;
                                idisp += in;
                        }
                        break;

                case '-': // Subtract.
                        if(mode == 'd')
                        {
                                cin >> din;
                                ddisp -= din;
                        }
                        else
                        {
                                cin >> in;
                                idisp -= in;
                        }
                        break;

                case '*': // Multiply.
                        if(mode == 'd')
                        {
                                cin >> din;
                                ddisp *= din;
                        }
                        else
                        {
                                cin >> in;
                                idisp *= in;
                        }
                        break;

                case '/': // Divide.
                        if(mode == 'd')
                        {
                                cin >> din;
                                ddisp /= din;
                        }
                        else
                        {
                                cin >> in;
                                idisp /= in;
                        }
                        break;

                case '^': // Raise to power.
                        if(mode == 'd')
                        {
                                cin >> din;
                                ddisp = pow(ddisp,din);
                        }
                        else
                        {
                                cin >> in;
                                din = rint(pow((double)idisp,(double)in));
                        }
                        break;

                case 'i': // Integer mode.
                        if(mode == 'd')
                        {
                                idisp = rint(ddisp);
                                mode = 'i';
                        }
                        if(ch == '\n') continue;
                        break;

                case 'd': // Floating mode.
                case 'f':
                        if(mode == 'i')
                        {
                                ddisp = idisp;
                                mode = 'd';
                        }
                        if(ch == '\n') continue;
                        break;
                default:
                        cout << "Bad command, " << comd << endl;
                }

                /* discard up to a newline. */
                while(ch != '\n') 
                        if(!cin.get(ch)) break;
        }

        //exit(0);
}
