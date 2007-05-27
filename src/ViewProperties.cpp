/*
    Copyright (C) 2007 by Robert Knight <robertknight@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301  USA.
*/

// Own
#include "ViewProperties.h"

using namespace Konsole;

ViewProperties::ViewProperties(QObject* parent)
: QObject(parent)
, _id(0)
//, _flags(0)
{
}

KUrl ViewProperties::url() const
{
    return KUrl();
}

void ViewProperties::fireActivity()
{
    emit activity(this);
}

void ViewProperties::setTitle(const QString& title)
{
    if ( title != _title )
    {
        _title = title;
        emit titleChanged(this);
    }
}
void ViewProperties::setIcon(const QIcon& icon)
{
    _icon = icon;
    emit iconChanged(this);
}
void ViewProperties::setIdentifier(int id)
{
    _id = id;
}
QString ViewProperties::title() const
{
    return _title;
}
QIcon ViewProperties::icon() const
{
    return _icon;
}
int ViewProperties::identifier() const
{
    return _id;
}
#include "ViewProperties.moc"
