/*
  Copyright 2015 Kurt Hindenburg <kurt.hindenburg@gmail.com>

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of
  the License or (at your option) version 3 or any later version
  accepted by the membership of KDE e.V. (or its successor appro-
  ved by the membership of KDE e.V.), which shall act as a proxy
  defined in Section 14 of version 3 of the license.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see http://www.gnu.org/licenses/.
*/

// Own
#include "FileLocationSettings.h"

#include <QDir>
#include <QStandardPaths>
#include <QFileDialog>

using namespace Konsole;

FileLocationSettings::FileLocationSettings(QWidget* aParent) : QWidget(aParent)
{
    setupUi(this);

    // TODO: worth adding gauge on free disk space?
    useSystemLocationText->setText(QDir::tempPath());
    useUsersHomeLocationText->setText(QStandardPaths::writableLocation(QStandardPaths::CacheLocation));
}

FileLocationSettings::~FileLocationSettings() = default;

void FileLocationSettings::browse()
{
    QString path = kcfg_scrollbackUseSpecifiedLocationDirectory->text();
    path = QFileDialog::getExistingDirectory(this, i18n("Select directory"), path);
    if (path.isEmpty()) {
        return;
    }
    kcfg_scrollbackUseSpecifiedLocationDirectory->setText(path);
}
