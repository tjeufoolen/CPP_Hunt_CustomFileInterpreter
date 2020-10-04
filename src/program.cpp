#include <program.h>
#include <wrappers/curlwrapper.h>
#include <utils/Logger.h>
#include <exceptions/NotImplementedException.h>

Program::Program()
{
    baseUrl = "https://www.swiftcoder.nl/cpp1/";
}

Program::Program(const std::string& baseUrl) : baseUrl(baseUrl) {}

std::string Program::solve(const std::string& endpoint)
{
    std::unique_ptr<cUrlWrapper> cUrl{};
    std::vector<std::string> lines = cUrl->getResponse(baseUrl + endpoint);

    // Read response line by line
    for (auto it = lines.begin(); it != lines.end(); ++it)
    {
        int index = std::distance(lines.begin(), it);

        Logger::getInstance()->debug("Expression: " + lines[index]);
        handleExpression(lines[index], index+1); // add 1 for actual ruleNumber
    }
    Logger::getInstance()->info(stack.back());


    return "super awesome result string (placeholder)";
}

// ----- Expressions

int neg(int value)
{
    throw NotImplementedException();
}

// ----- Handling

void Program::handleExpression(const std::string& expression, int ruleNumber) // <-- todo: rulenumber
{
    // Digits
    if (std::all_of(expression.begin(), expression.end(), ::isdigit))
    {
        if (int value = stoi(expression) < 0)
        {
            int val = stoi(expression);

            if (val > 0) val=-abs(val);
            if (val < 0) val=abs(val);


            stack.push_back(std::to_string(val));
            Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
//            stack.push_back(std::to_string(neg(value)));
        }

        stack.push_back(expression);
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    // Values & types
    switch(expression.front())
    {
        case '\\': // Text to end of line
            stack.push_back(expression.substr(1));
            Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
            return;
        case ':': // Label definition
            labels[expression.substr(1)] = ruleNumber+1;
            Logger::getInstance()->debug("defined label: " + expression.substr(1) + "->" + std::to_string(labels[expression.substr(1)]));
            return;
        case '>': // Label reference
            stack.push_back(std::to_string(labels[expression.substr(1)]));
            Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
            return;
        case '=': // Variable assignment
            variables[expression.substr(1)] = stack.back();
            Logger::getInstance()->debug("set variable: " + expression.substr(1) + "=" + variables[expression.substr(1)]);
            stack.pop_back();
            Logger::getInstance()->debug("removed last item from stack.");
            return;
        case '$': // Variable reference
            stack.push_back(variables[expression.substr(1)]);
            Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
            return;
    }

    // Integer operations
    if (expression == "add")
    {
        int val2 = stoi(stack.back()); stack.pop_back();
        int val1 = stoi(stack.back()); stack.pop_back();
        Logger::getInstance()->debug("removed last 2 items from stack.");

        stack.push_back(std::to_string(val1 + val2));
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "sub")
    {
        int val2 = stoi(stack.back()); stack.pop_back();
        int val1 = stoi(stack.back()); stack.pop_back();
        Logger::getInstance()->debug("removed last 2 items from stack.");

        stack.push_back(std::to_string(val1 - val2));
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "mul")
    {
        int val2 = stoi(stack.back()); stack.pop_back();
        int val1 = stoi(stack.back()); stack.pop_back();
        Logger::getInstance()->debug("removed last 2 items from stack.");

        stack.push_back(std::to_string(val1 * val2));
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "div")
    {
        int val2 = stoi(stack.back()); stack.pop_back();
        int val1 = stoi(stack.back()); stack.pop_back();
        Logger::getInstance()->debug("removed last 2 items from stack.");

        stack.push_back(std::to_string(val1 / val2));
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "mod")
    {
        int val2 = stoi(stack.back()); stack.pop_back();
        int val1 = stoi(stack.back()); stack.pop_back();
        Logger::getInstance()->debug("removed last 2 items from stack.");

        stack.push_back(std::to_string(val1 % val2));
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "neg")
    {
        int val = stoi(stack.back()); stack.pop_back();
        Logger::getInstance()->debug("removed last item from stack.");

        if (val > 0) val=-abs(val);
        if (val < 0) val=abs(val);

        stack.push_back(std::to_string(val));
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "abs")
    {
        int val = stoi(stack.back()); stack.pop_back();
        Logger::getInstance()->debug("removed last item from stack.");
        stack.push_back(std::to_string(abs(val)));
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "inc")
    {
        int val = stoi(stack.back()); stack.pop_back();
        Logger::getInstance()->debug("removed last item from stack.");
        stack.push_back(std::to_string(++val));
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "dec")
    {
        int val = stoi(stack.back()); stack.pop_back();
        Logger::getInstance()->debug("removed last item from stack.");
        stack.push_back(std::to_string(--val));
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    // String operations
    if (expression == "dup")
    {
        std::string str = stack.back();
        stack.push_back(str);
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "rev")
    {
        std::string str = stack.back(); stack.pop_back();
        Logger::getInstance()->debug("removed last item from stack.");
        reverse(str.begin(), str.end());
        stack.push_back(str);
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "slc")
    {
        int to = stoi(stack.back()); stack.pop_back();
        int from = stoi(stack.back()); stack.pop_back();
        std::string value = stack.back(); stack.pop_back();
        Logger::getInstance()->debug("removed last 3 items from stack.");

        stack.push_back(value.substr(from, to-from+1));
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "idx")
    {
        int index = stoi(stack.back()); stack.pop_back();
        std::string str = stack.back(); stack.pop_back();
        Logger::getInstance()->debug("removed last 2 items from stack.");

        stack.push_back(std::to_string(str.at(index)));
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "cat")
    {
        std::string str2 = stack.back(); stack.pop_back();
        std::string str1 = stack.back(); stack.pop_back();
        Logger::getInstance()->debug("removed last 2 items from stack.");

        stack.push_back(str1 + str2);
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "len")
    {
        int val = stack.back().size(); stack.pop_back();
        Logger::getInstance()->debug("removed last item from stack.");
        stack.push_back(std::to_string(val));
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "rot")
    {
        std::string a = stack.back(); stack.pop_back();
        Logger::getInstance()->debug("removed last item from stack.");

        int z = a.length(), i=0;
        for(i=0; i<=(z); i++) //Rot13 Algorithm
        {
            if(a[i] < 91 && a[i] > 64) //uppercase
            {
                if(a[i] < 78)
                    a[i] = a[i] + 13;
                else
                    a[i] = a[i] - 13;
            }
            if(a[i] < 123 && a[i] > 96) //lowercase
            {
                if(a[i] < 110)
                    a[i] = a[i] + 13;
                else
                    a[i] = a[i] - 13;
            }
        }

        stack.push_back(a);
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    if (expression == "enl")
    {
        std::string str = stack.back(); stack.pop_back();
        Logger::getInstance()->debug("removed last item from stack.");
        stack.push_back(str + '\n');
        Logger::getInstance()->debug("added " + stack.back() + " to the stack.");
        return;
    }

    // Test & Jumps

    // Functions

    // End
}