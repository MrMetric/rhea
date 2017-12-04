//---------------------------------------------------------------------------
/// \file   errors.hpp
/// \brief  Exception classes
//
// Copyright 2015, nocte@hippie.nu            Released under the MIT License.
//---------------------------------------------------------------------------
#pragma once

#include <string>
#include <stdexcept>

namespace rhea
{

class variable;

/** Base class for all Rhea exceptions. */
class error : public std::exception
{
public:
    virtual ~error();

    // LCOV_EXCL_START
    virtual const char* what() const noexcept { return "unspecified error"; }
    // LCOV_EXCL_STOP
};

/** Signals an internal inconsistency in the solver. */
class internal_error : public error
{
    std::string msg;

public:
    internal_error(const std::string& m)
        : msg(m)
    {
    }

    virtual ~internal_error();

    // LCOV_EXCL_START
    virtual const char* what() const noexcept { return msg.c_str(); }
    // LCOV_EXCL_STOP
};

/** The application tried to use an illegal weight value. */
class bad_weight : public error
{
public:
    virtual ~bad_weight();

    // LCOV_EXCL_START
    virtual const char* what() const noexcept
    {
        return "strength weight must be between 1 and 10000";
    }
    // LCOV_EXCL_STOP
};

/** The application tried to remove a constraint that doesn't exist in
 ** the solver. */
class constraint_not_found : public error
{
public:
    virtual ~constraint_not_found();

    // LCOV_EXCL_START
    virtual const char* what() const noexcept
    {
        return "tried to remove a constraint that was never added";
    }
    // LCOV_EXCL_STOP
};

class duplicate_constraint : public error
{
public:
    virtual ~duplicate_constraint();

    // LCOV_EXCL_START
    virtual const char* what() const noexcept
    {
        return "constraint was already added to the solver";
    }
    // LCOV_EXCL_STOP
};

class required_failure : public error
{
public:
    virtual ~required_failure();

    // LCOV_EXCL_START
    virtual const char* what() const noexcept
    {
        return "required constraint is unsatisfiable";
    }
    // LCOV_EXCL_STOP
};

class duplicate_edit_variable : public error
{
public:
    virtual ~duplicate_edit_variable();

    // LCOV_EXCL_START
    virtual const char* what() const noexcept
    {
        return "edit variable was already added to the solver";
    }
    // LCOV_EXCL_STOP
};

class unknown_edit_variable : public error
{
public:
    virtual ~unknown_edit_variable();

    // LCOV_EXCL_START
    virtual const char* what() const noexcept
    {
        return "edit variable was not added to the solver";
    }
    // LCOV_EXCL_STOP
};

class bad_required_strength : public error
{
public:
    virtual ~bad_required_strength();

    // LCOV_EXCL_START
    virtual const char* what() const noexcept
    {
        return "edit constraints cannot be required";
    }
    // LCOV_EXCL_STOP
};

/** The application tried to remove a row that doesn't exist. */
class row_not_found : public error
{
public:
    virtual ~row_not_found();

    // LCOV_EXCL_START
    virtual const char* what() const noexcept { return "row does not exist"; }
    // LCOV_EXCL_STOP
};

/** The application tried to remove a row that doesn't exist. */
class nonlinear_expression : public error
{
public:
    virtual ~nonlinear_expression();

    // LCOV_EXCL_START
    virtual const char* what() const noexcept
    {
        return "application tried to construct a non-linear expression";
    }
    // LCOV_EXCL_STOP
};

} // namespace rhea
