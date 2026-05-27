#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

// Simple LL(1) Predictive Parsing Table Example
map<pair<char, char>, string> table;

bool parse(string input)
{
    stack<char> st;
    st.push('$');
    st.push('E');   // start symbol

    input += '$';
    int i = 0;

    while (!st.empty())
    {
        char top = st.top();
        char current = input[i];

        cout << "Stack Top: " << top << " | Input: " << current << endl;

        if (top == current)
        {
            st.pop();
            i++;
        }
        else if (isupper(top))
        {
            string production = table[{top, current}];

            if (production == "")
                return false;

            st.pop();

            if (production != "ε")
            {
                for (int j = production.size() - 1; j >= 0; j--)
                    st.push(production[j]);
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    // Grammar:
    // E -> TR
    // R -> +TR | ε
    // T -> i

    table[{ 'E', 'i' }] = "TR";
    table[{ 'R', '+' }] = "+TR";
    table[{ 'R', '$' }] = "ε";
    table[{ 'T', 'i' }] = "i";

    string input;

    cout << "Enter input string (example: i+i): ";
    cin >> input;

    if (parse(input))
        cout << "String Accepted\n";
    else
        cout << "String Rejected\n";

    return 0;
}
