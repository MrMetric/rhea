#include "errors.hpp"

namespace rhea
{

error::~error() {}
internal_error::~internal_error() {}
bad_weight::~bad_weight() {}
constraint_not_found::~constraint_not_found() {}
duplicate_constraint::~duplicate_constraint() {}
required_failure::~required_failure() {}
duplicate_edit_variable::~duplicate_edit_variable() {}
unknown_edit_variable::~unknown_edit_variable() {}
bad_required_strength::~bad_required_strength() {}
row_not_found::~row_not_found() {}
nonlinear_expression::~nonlinear_expression() {}

}
