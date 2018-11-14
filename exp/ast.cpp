//  ast.cpp

#include "ast.hpp"
#include "Token.hpp"

BasicExpression::BasicExpression(int value)
    : value(value)
{
}

BasicExpression::~BasicExpression()
{
}

int BasicExpression::getValue() const
{
    return value;
}

void BasicExpression::accept(Visitor* v)
{
    v->visit(this);
}

BinaryExpression::BinaryExpression(std::shared_ptr<Expression> left, Token op, std::shared_ptr<Expression> right)
{
    this->left = left;
    this->op = op;
    this->right = right;
}

BinaryExpression::~BinaryExpression()
{
}

void BinaryExpression::accept(Visitor* v)
{
    v->visit(this);
}

std::shared_ptr<Expression> BinaryExpression::getLeft()
{
    return left;
}

std::shared_ptr<Expression> BinaryExpression::getRight()
{
    return right;
}

Token BinaryExpression::getOperator() const
{
    return op;
}

FunctionDecl::FunctionDecl(const std::string& id, std::shared_ptr<Expression> exp, std::vector<std::string> params, const std::vector<std::shared_ptr<Guard>>& guards)
    : mId(id)
    , mExpression(exp)
    , mParams(params)
    , mGuards(guards)
{
}

void FunctionDecl::accept(Visitor* v)
{
    v->visit(this);
}

std::string FunctionDecl::getId() const
{
    return mId;
}

std::shared_ptr<Expression> FunctionDecl::getDefaultExpression() const
{
    return mExpression;
}

std::vector<std::string> FunctionDecl::getParameters() const
{
    return mParams;
}

std::vector<std::shared_ptr<Guard>> FunctionDecl::getGuards() const
{
    return mGuards;
}

VariableExpression::VariableExpression(std::string variableName)
    : mVariableName(variableName)
{
}

std::string VariableExpression::getVariableName() const
{
    return mVariableName;
}

void VariableExpression::accept(Visitor* v)
{
    v->visit(this);
}

FunctionCallExpression::FunctionCallExpression(const std::string functionId, const std::vector<std::shared_ptr<Expression>> arguments)
    : mFunctionId(functionId)
    , mArguments(arguments)
{
}

std::string FunctionCallExpression::getFunctionId() const
{
    return mFunctionId;
}

std::vector<std::shared_ptr<Expression>> FunctionCallExpression::getArguments() const
{
    return mArguments;
}

void FunctionCallExpression::accept(Visitor* v)
{
    v->visit(this);
}

Guard::Guard(const std::shared_ptr<Expression> guardExpression, const std::shared_ptr<Expression> body)
    : mGuardExpression(guardExpression)
    , mBodyExpression(body)
{
}

void Guard::accept(Visitor* v)
{
}

std::shared_ptr<Expression> Guard::getGuardExpression() const
{
    return mGuardExpression;
}

std::shared_ptr<Expression> Guard::getBodyExpression() const
{
    return mBodyExpression;
}

ListExpression::ListExpression(const std::vector<std::shared_ptr<Expression>> &elements) : mElements(elements)
{
}

void ListExpression::accept(Visitor *v)
{
    v->visit(this);
}

std::vector<std::shared_ptr<Expression>> ListExpression::getElements() const
{
    return mElements;
}
