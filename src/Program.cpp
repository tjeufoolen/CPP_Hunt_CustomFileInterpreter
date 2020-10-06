#include <Program.h>
#include <wrappers/CUrlWrapper.h>
#include <utils/Logger.h>
#include <exceptions/NotImplementedException.h>
#include <expressions/Expressions.h>

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

    Logger::getInstance().info("Started solving...");
    while(!foundSolution)
    {
        std::vector<std::string> lines = cUrl->getResponse(baseUrl + _endpoint);
        Context context{};

        // Read response line by line
        for (auto it = lines.begin(); it != lines.end(); ++it)
        {
            int rule = std::distance(lines.begin(), it);
            Logger::getInstance().debug(lines[rule]);
            handleExpression(lines[rule], context, rule);

            if (foundSolution) break; // Quit early if solution is already found
        }

        lastStackValue = context.backStack();
        if (foundSolution) break; // Quit early if solution is already found

        Logger::getInstance().info("redirected to new file: " + lastStackValue);
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
        { DigitsExpression{expression}.Interpret(context); return; }

    // Values & types
    std::string exp = expression.substr(1);
    switch(expression.front())
    {
        case '\\': TextExpression{exp}.Interpret(context); return;
        case  ':': LabelDefinitionExpression{exp, rule+1}.Interpret(context); return;
        case  '>': LabelReferenceExpression{exp}.Interpret(context); return;
        case  '=': VariableAssignmentExpression{exp, *context.popStack()}.Interpret(context); return;
        case  '$': VariableReferenceExpression{exp}.Interpret(context); return;
    }

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
    if (expression == "gto") { GotoExpression{}.Interpret(context); return; }
    if (expression == "geq") { GotoIfEqualExpression{}.Interpret(context); return; }
    if (expression == "gne") { GotoIfNotEqualExpression{}.Interpret(context); return; }
    if (expression == "glt") { GotoIfLessExpression{}.Interpret(context); return; }
    if (expression == "gle") { GotoIfLessOrEqualExpression{}.Interpret(context); return; }
    if (expression == "ggt") { GotoIfGreaterExpression{}.Interpret(context); return; }
    if (expression == "gge") { GotoIfGreaterOrEqualExpression{}.Interpret(context); return; }

    // Functions
    if (expression == "fun") throw NotImplementedException();
    if (expression == "ret") throw NotImplementedException();

    // End
    if (expression == "end") foundSolution = true;
}