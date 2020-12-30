#include<iostream>
#include<string>
#include<stack>
#include<fstream>
using namespace std;
class node
{
private:
    node* next;
    string data;
public:
    node() :data(""), next(NULL)
    {}
    node(string d, node* n) :data(d), next(n)
    {}
    void set_data(string x)
    {
        data = x;
    }
    string get_data()
    {
        return data;
    }
    void set_next(node* ptr)
    {
        next = ptr;
    }
    node* get_next()
    {
        return next;
    }
    friend class stringstack;
};
class stringstack
{
private:
    node* topstack;
public:
    stringstack() :topstack(NULL)
    {}
    node* get_top()
    {
        return topstack;
    }
    void pushstack(string x)
    {
        node* ptr = new node();
        ptr->data = x;
        ptr->next = topstack;
        topstack = ptr;
    }
    string popstack()
    {
        if (StackEmptystack())
        {
            cout << "Stack is Empty" << endl;
            //return;
        }
        else
        {
            node* ptr = get_top();
            topstack = topstack->get_next();
            string y;
            y = ptr->get_data();
            delete ptr;
            return y;
        }
        return "";
    }
    bool StackEmptystack()
    {
        return (get_top() == NULL);
    }
    string topStack()
    {
        if (!StackEmptystack())
        {
            return (topstack->get_data());

        }
        else
        {
            return "empty";
        }

    }
    friend class split;
};



// Split class is use to split the the code line into one word and print in line by line. 
class split
{
public:
    string search;
    string word;
    stringstack s;
    int count = 0;
    int totalError = 0;
    string brr;
   // string ch = "OK";
    bool flage;
    int errlinecount = 0; // line number
    void splitcode(string str)
    {
        word = "";
        for (auto x : str)
        {
            if (x == ' ')
            {

                cout << "Line" << count << "\t" << word << endl;
                s.pushstack(word);
                count++;
                word = "";
            }

            else if (x == '(' || x == '[' || x == '{' || x == ')' || x == ']' || x == '}')
            {
                cout << "Line" << count << "\t" << x << endl;
                s.pushstack(word);
                count++;
                word = "";

            }
            else {
                word = word + x;


            }

        }
        cout << "Line" << count << "\t" << word << endl;

    }

    //==============================================================================================================


    bool errorcheck(string str, string brr)
    {

        size_t pos;
        //===================================================================================================
        if (brr == "begin")  //begin with end
        {
            search = "end";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
                totalError++;
            }
        }
        else if (brr == "if") //if with endif 
        {
            search = "endif";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                totalError++;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }

        }

        else if (brr == "for")  // for with endfor
        {
            search = "endfor";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                totalError++;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }

        }
        else if (brr == "while" && s.topStack() == "endwhile")  //while with endwhile
        {
            search = "endwhile";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                totalError++;
                flage = false;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }

        }
        //===================================================================================================


        else if (brr == "elseif") //elseif with if 
        {
            search = "if";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                totalError++;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }

        }
        else if (brr == "else")   // else with if
        {
            search = "if";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                totalError++;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }

        }
        else if (brr == "endif")  // endif with if
        {
            search = "if";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                totalError++;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }

        }
        else if (brr == "endfor")  // endfor with for
        {
            search = "for";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                totalError++;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }

        }
        else if (brr == "endwhile")  // endwhile with while
        {
            search = "while";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                totalError++;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }

        }

        else if (brr == "end")  //end with begin
        {
            search = "begin";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                totalError++;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }

        }

        else if (brr == "(")
        {
            search = ")";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                totalError++;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }
        }
        else if (brr == "{")
        {
            search = "}";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                totalError++;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }

        }
        else if (brr == "[")
        {
            search = "]";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                totalError++;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }

        }
        //=========================================================================================
        else if (brr == ")")
        {
            search = "(";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                totalError++;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }

        }
        else if (brr == "}")
        {
            search = "{";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                totalError++;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }

        }
        else if (brr == "]")
        {
            search = "[";
            pos = str.find(search);
            if (pos != std::string::npos)
                flage = true;
            else
            {
                flage = false;
                totalError++;
                cout << "Error-->\t" << "Line" << errlinecount << "\tExpected\t'" << search << "'" << endl;
            }

        }

        cout << "Total Errors:\t" << totalError++ << endl;
        return flage;
    }

    void get(string str)
    {
        while (!s.StackEmptystack())
        {
            brr = s.topStack();
            errorcheck(str, brr);
            if (errorcheck(str, brr) == true)
            {
                cout << "No Syntex Error Found\n";
            }
        }
    }

};
//=============================================================================================================



void add(string str)
{
    split s;
    ofstream fout;
    fout.open("test.txt", ios::binary | ios::app);
    s.splitcode(str);
    fout.write(reinterpret_cast<char*>(&s), sizeof(split));

    //<string*>;
   // (&s), sizeof(split));
    fout.close();
}


void errorchecking(string str)
{
    split s;
    ofstream fout;
    fout.open("Error.txt", ios::binary | ios::app);
    s.get(str);
    fout.write(reinterpret_cast<char*>(&s), sizeof(split));
    fout.close();
}




int main()
{
    cout << "==========================================================================================";
    cout << "==========================================================================================";
    cout << "\t\tSYNTEX ERRORS CHECKER\n";
    cout << "==========================================================================================";
    cout << "==========================================================================================";
    cout << endl << endl;
    cout << endl;
    cout << "KHADIJA NAZ\N";
    cout << "190834\n";
    cout << "BSCYS_III_A\N";
    cout << endl << endl;
    cout << endl;

    string str;

    cout << "Instruction\nPlz Enter code in this format\nYou can also copy this code\n\n";
    cout << "//input=  Begin{int i, j; i = 10;j = 20;if (i > j){for (i = 1; i < 10; i++)j = j + 2;endfor }elseif(i == j){for (i = 10; i < 20; i++)i = i * 2;endfor}else{ while (i < j){i = i + 1;j = j + i;}endwhile}endif }end";
    cout << "\n\nEnter a Code\n";
    getline(cin, str);
    add(str);
    errorchecking(str);
    cout << "THANKS For Using Syntex Error Checker\n";
 

    return 0;


    //input=  Begin{int i, j; i = 10;j = 20;if (i > j){for (i = 1; i < 10; i++)j = j + 2;endfor }elseif(i == j){for (i = 10; i < 20; i++)i = i * 2;endfor}else{ while (i < j){i = i + 1;j = j + i;}endwhile}endif }end


}


