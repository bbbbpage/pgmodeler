/*
# PostgreSQL Database Modeler (pgModeler)
#
# Copyright 2006-2019 - Raphael Araújo e Silva <raphael@pgmodeler.io>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation version 3.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# The complete text of GPLv3 is at LICENSE file on source code root directory.
# Also, you can get the complete GNU General Public License at <http://www.gnu.org/licenses/>
*/

/**
\ingroup libpgmodeler
\brief Implements the operations to manipulate foreign tables on the database.
*/

#ifndef FOREIGN_TABLE_H
#define FOREIGN_TABLE_H

#include "physicaltable.h"
#include "foreignobject.h"

class ForeignTable: public PhysicalTable, public ForeignObject {
	private:


	public:
		ForeignTable(void);
		~ForeignTable(void);

		//! \brief Returns the SQL / XML definition for table
		virtual QString getCodeDefinition(unsigned def_type) final;

		//! \brief Copy the attributes between two tables
		void operator = (ForeignTable &table);

		//! \brief Returns the alter definition comparing the this table against the one provided via parameter
		virtual QString getAlterDefinition(BaseObject *object) final;

		/*! \brief Generates the table's SQL code considering adding the relationship added object or not.
		 * Note if the method is called with incl_rel_added_objs = true it can produce an SQL/XML code
		 * that does not reflect the real semantics of the table. So take care to use this method and always
		 * invalidate the tables code (see setCodeInvalidated()) after retrieving the resulting code */
		QString __getCodeDefinition(unsigned def_type, bool incl_rel_added_objs);

		friend class Relationship;
		friend class OperationList;
};

#endif