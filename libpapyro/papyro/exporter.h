/*****************************************************************************
 *  
 *   This file is part of the Utopia Documents application.
 *       Copyright (c) 2008-2016 Lost Island Labs
 *           <info@utopiadocs.com>
 *   
 *   Utopia Documents is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU GENERAL PUBLIC LICENSE VERSION 3 as
 *   published by the Free Software Foundation.
 *   
 *   Utopia Documents is distributed in the hope that it will be useful, but
 *   WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 *   Public License for more details.
 *   
 *   In addition, as a special exception, the copyright holders give
 *   permission to link the code of portions of this program with the OpenSSL
 *   library under certain conditions as described in each individual source
 *   file, and distribute linked combinations including the two.
 *   
 *   You must obey the GNU General Public License in all respects for all of
 *   the code used other than OpenSSL. If you modify file(s) with this
 *   exception, you may extend this exception to your version of the file(s),
 *   but you are not obligated to do so. If you do not wish to do so, delete
 *   this exception statement from your version.
 *   
 *   You should have received a copy of the GNU General Public License
 *   along with Utopia Documents. If not, see <http://www.gnu.org/licenses/>
 *  
 *****************************************************************************/

#ifndef ATHENAEUM_EXPORTER_H
#define ATHENAEUM_EXPORTER_H

#include <papyro/config.h>
#include <utopia2/extension.h>

#include <QDir>
#include <QModelIndex>
#include <QStringList>

class QIODevice;

namespace Athenaeum
{

    class LibraryModel;

    class LIBPAPYRO_API Exporter
    {
    public:
        typedef Exporter API;
        virtual ~Exporter() {}

        virtual bool doExport(const QModelIndexList & indexList, const QString & filename);
        virtual QStringList extensions() const;
        virtual QString name() const = 0;
        virtual bool multipleFiles() const = 0;
    };

}

UTOPIA_DECLARE_EXTENSION_CLASS(LIBATHENAEUM, Athenaeum::Exporter)

#endif // ATHENAEUM_EXPORTER_H