#include <Program.h>
#include <wrappers/CUrlWrapper.h>
#include <utils/Logger.h>
#include <exceptions/NotImplementedException.h>
#include <expressions/terminal/TextExpression.h>

Program::Program()
{
    baseUrl = "https://www.swiftcoder.nl/cpp1/";
}


Program::Program(const std::string& baseUrl)
    : baseUrl(baseUrl) {}


std::string Program::solve(const std::string& endpoint)
{
    std::unique_ptr<cUrlWrapper> cUrl{};
    std::string _endpoint = endpoint;

    // while .... end expression is not yet seen
    foundSolution = false;
    std::string lastStackValue;

    Logger::getInstance()->info("Started solving...");
    while(!foundSolution)
    {
        std::vector<std::string> lines = cUrl->getResponse(baseUrl + _endpoint);
        Context context{};

        // Read response line by line
        for (auto it = lines.begin(); it != lines.end(); ++it)
        {
            int rule = std::distance(lines.begin(), it);
            Logger::getInstance()->debug("executing expression >> " + lines[rule]);
            handleExpression(lines[rule], context, rule);

            if (foundSolution) break; // Quit early if solution is already found
        }

        lastStackValue = context.backStack();
        Logger::getInstance()->info("redirected to new file: " + lastStackValue);
        _endpoint = lastStackValue;
        foundSolution = true; //todo: Remove when all parsing works and end expression is detected!!! <------------------
    }
    // endwhile

    return lastStackValue;
}


void Program::handleExpression(const std::string& expression, Context& context, int rule)
{
    // Digits
    if (std::all_of(expression.begin(), expression.end(), ::isdigit))
    {
        if (int value = stoi(expression) < 0)
        {
            int val = stoi(expression);

            if (val > 0) val=-abs(val);
            if (val < 0) val=abs(val);

            context.pushToStack(std::to_string(val));
//            stack.push_back(std::to_string(neg(value)));
        }

        context.pushToStack(expression);
        return;
    }

    // Values & types
    switch(expression.front())
    {
        case '\\': TextExpression{expression.substr(1)}.Interpret(context); return;
        case  ':': context.setLabel(expression.substr(1), rule+1); return;
        case  '>': context.pushToStack(std::to_string(context.getLabel(expression.substr(1)))); return;
        case  '=': context.setVariable(expression.substr(1), *context.popStack()); return;
        case  '$': context.pushToStack(context.getVariable(expression.substr(1))); return;
    }

    // Integer operations
    if (expression == "add")
    {
        int val2 = stoi(*context.popStack());
        int val1 = stoi(*context.popStack());

        context.pushToStack(std::to_string(val1 + val2));
        return;
    }

    if (expression == "sub")
    {
        int val2 = stoi(*context.popStack());
        int val1 = stoi(*context.popStack());

        context.pushToStack(std::to_string(val1 - val2));
        return;
    }

    if (expression == "mul")
    {
        int val2 = stoi(*context.popStack());
        int val1 = stoi(*context.popStack());

        context.pushToStack(std::to_string(val1 * val2));
        return;
    }

    if (expression == "div")
    {
        int val2 = stoi(*context.popStack());
        int val1 = stoi(*context.popStack());

        context.pushToStack(std::to_string(val1 / val2));
        return;
    }

    if (expression == "mod")
    {
        int val2 = stoi(*context.popStack());
        int val1 = stoi(*context.popStack());

        context.pushToStack(std::to_string(val1 % val2));
        return;
    }

    if (expression == "neg")
    {
        int val = stoi(*context.popStack());

        if (val > 0) val=-abs(val);
        if (val < 0) val=abs(val);

        context.pushToStack(std::to_string(val));
        return;
    }

    if (expression == "abs")
    {
        int val = stoi(*context.popStack());
        context.pushToStack(std::to_string(abs(val)));
        return;
    }

    if (expression == "inc")
    {
        int val = stoi(*context.popStack());
        context.pushToStack(std::to_string(++val));
        return;
    }

    if (expression == "dec")
    {
        int val = stoi(*context.popStack());
        context.pushToStack(std::to_string(--val));
        return;
    }

    // String operations
    if (expression == "dup")
    {
        context.pushToStack(context.backStack());
        return;
    }

    if (expression == "rev")
    {
        auto str = context.popStack();
        reverse(str->begin(), str->end());
        context.pushToStack(*str);
        return;
    }

    if (expression == "slc")
    {
        int to = stoi(*context.popStack());
        int from = stoi(*context.popStack());
        auto value = context.popStack();

        context.pushToStack(value->substr(from, to-from+1));
        return;
    }

    if (expression == "idx")
    {
        int index = stoi(*context.popStack());
        auto str = context.popStack();

        context.pushToStack(std::to_string(str->at(index)));
        return;
    }

    if (expression == "cat")
    {
        auto str2 = context.popStack();
        auto str1 = context.popStack();

        context.pushToStack(*str1 + *str2);
        return;
    }

    if (expression == "len")
    {
        int val = context.backStack().size(); context.popStack();
        context.pushToStack(std::to_string(val));
        return;
    }

    if (expression == "rot")
    {
        std::string a = *context.popStack();

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

        context.pushToStack(a);
        return;
    }

    if (expression == "enl")
    {
        auto str = context.popStack();
        context.pushToStack(*str + '\n');
        return;
    }

    // Test & Jumps
    if (expression == "gto") throw NotImplementedException();
    if (expression == "geq") throw NotImplementedException();
    if (expression == "gne") throw NotImplementedException();
    if (expression == "glt") throw NotImplementedException();
    if (expression == "gle") throw NotImplementedException();
    if (expression == "ggt") throw NotImplementedException();
    if (expression == "gge") throw NotImplementedException();

    // Functions
    if (expression == "fun") throw NotImplementedException();
    if (expression == "ret") throw NotImplementedException();

    // End
    if (expression == "end") foundSolution = true;
}