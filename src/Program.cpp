#include <Program.h>
#include <wrappers/CUrlWrapper.h>
#include <utils/Logger.h>
#include <expressions/Expressions.h>
#include <exceptions/FileNotFoundException.h>

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
    *currentRule = 0;
    std::string lastStackValue;

    Logger::getInstance().info("Started solving...");
    while(!foundSolution)
    {
        std::vector<std::string> lines;

        try {
            lines = cUrl->getResponse(baseUrl + _endpoint);
        }
        catch (FileNotFoundException& e)
        {
            return e.what();
        }

        Context context{};

        // Pre-define labels
        for (auto it = lines.begin(); it != lines.end(); ++it)
        {
            int index = std::distance(lines.begin(), it);
            const std::string& expression = lines[index];
            if (expression.front() == ':')
                LabelDefinitionExpression{expression.substr(1), index}.Interpret(context);
        }

        // Handle expressions line by line
        for (auto it = lines.begin(); it != lines.end(); ++it)
        {
            *currentRule = std::distance(lines.begin(), it);

            Logger::getInstance().debug(lines[*currentRule]);
            handleExpression(lines[*currentRule], context);

            if (foundSolution) break; // Quit early if solution is already found

            it = lines.begin() + *currentRule;
        }

        lastStackValue = context.backStack();
        if (foundSolution) break; // Quit early if solution is already found

        Logger::getInstance().info("redirected to new file: " + lastStackValue);
        _endpoint = lastStackValue;
    }
    // endwhile

    return lastStackValue;
}


void Program::handleExpression(const std::string& expression, Context& context)
{
    // Digits
    if (std::all_of(expression.begin(), expression.end(), ::isdigit))
        { DigitsExpression{expression}.Interpret(context); return; }

    // Integer operations
    if (expression == "add") { AddExpression{}.Interpret(context); return; }
    if (expression == "sub") { SubtractExpression{}.Interpret(context); return; }
    if (expression == "mul") { MultiplyExpression{}.Interpret(context); return; }
    if (expression == "div") { DivideExpression{}.Interpret(context); return; }
    if (expression == "mod") { ModuloExpression{}.Interpret(context); return; }
    if (expression == "neg") { NegateExpression{}.Interpret(context); return; }
    if (expression == "abs") { AbsoluteExpression{}.Interpret(context); return; }
    if (expression == "inc") { IncrementExpression{}.Interpret(context); return; }
    if (expression == "dec") { DecrementExpression{}.Interpret(context); return; }

    // String operations
    if (expression == "dup") { DuplicateExpression{}.Interpret(context); return; }
    if (expression == "rev") { ReverseExpression{}.Interpret(context); return; }
    if (expression == "slc") { SubstringExpression{}.Interpret(context); return; }
    if (expression == "idx") { IndexingExpression{}.Interpret(context); return; }
    if (expression == "cat") { ConcatenationExpression{}.Interpret(context); return; }
    if (expression == "len") { LengthExpression{}.Interpret(context); return; }
    if (expression == "rot") { ROT13Expression{}.Interpret(context); return; }
    if (expression == "enl") { NewLineExpression{}.Interpret(context); return; }

    // Test & Jumps
    if (expression == "gto") { GotoExpression{currentRule}.Interpret(context); return; }
    if (expression == "geq") { GotoIfEqualExpression{currentRule}.Interpret(context); return; }
    if (expression == "gne") { GotoIfNotEqualExpression{currentRule}.Interpret(context); return; }
    if (expression == "glt") { GotoIfLessExpression{currentRule}.Interpret(context); return; }
    if (expression == "gle") { GotoIfLessOrEqualExpression{currentRule}.Interpret(context); return; }
    if (expression == "ggt") { GotoIfGreaterExpression{currentRule}.Interpret(context); return; }
    if (expression == "gge") { GotoIfGreaterOrEqualExpression{currentRule}.Interpret(context); return; }

    // Functions
    if (expression == "fun") { FunctionExpression{currentRule}.Interpret(context); return; }
    if (expression == "ret") { ReturnExpression{currentRule}.Interpret(context); return; }

    // End
    if (expression == "end") foundSolution = true;

    // Values & types
    std::string exp = expression.substr(1);
    switch(expression.front())
    {
        case '\\': TextExpression{exp}.Interpret(context); return;
        case  ':': LabelDefinitionExpression{exp, *currentRule}.Interpret(context); return;
        case  '>': LabelReferenceExpression{exp}.Interpret(context); return;
        case  '=': VariableAssignmentExpression{exp, *context.popStack()}.Interpret(context); return;
        case  '$': VariableReferenceExpression{exp}.Interpret(context); return;
    }
}