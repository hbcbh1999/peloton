/*-------------------------------------------------------------------------
 *
 * constraint.h
 * file description
 *
 * Copyright(c) 2015, CMU
 *
 * /n-store/src/catalog/constraint.h
 *
 *-------------------------------------------------------------------------
 */

#pragma once

#include <string>
#include <vector>
#include <algorithm>

namespace nstore {
namespace catalog {

class Index;
class Table;
class Column;

//===--------------------------------------------------------------------===//
// Constraint
//===--------------------------------------------------------------------===//

class Constraint {

  enum ConstraintType{
    CONSTRAINT_TYPE_INVALID = 0, // invalid

    CONSTRAINT_TYPE_PRIMARY = 0, // primary key
    CONSTRAINT_TYPE_FOREIGN = 0  // foreign key
  };

 public:
  Constraint(std::string name,
             ConstraintType type,
             Index* index,
             Table* foreign_key_table,
             std::vector<Column*> columns)
 : name(name),
   type(type),
   index(index),
   foreign_key_table(foreign_key_table),
   columns(columns){
  }

  std::string GetName() const {
    return name;
  }

  ConstraintType GetType() const {
    return type;
  }

  Index *GetIndex() const {
    return index;
  }

  Table *GetForeignKeyTable() const {
    return foreign_key_table;
  }

  std::vector<Column*> GetColumns() const {
    return columns;
  }

 private:
  std::string name;

  // The type of constraint
  ConstraintType type = CONSTRAINT_TYPE_INVALID;

  // The index used by this constraint (if needed)
  Index* index = nullptr;

  // The table referenced by the foreign key (if needed)
  Table* foreign_key_table = nullptr;

  // The columns in the foreign table referenced by the constraint (if needed)
  std::vector<Column*> columns;

};

} // End catalog namespace
} // End nstore namespace