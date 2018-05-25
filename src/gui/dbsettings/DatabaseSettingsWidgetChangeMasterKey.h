/*
 *  Copyright (C) 2018 KeePassXC Team <team@keepassxc.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEEPASSXC_DATABASESETTINGSPAGECHANGEMASTERKEY_H
#define KEEPASSXC_DATABASESETTINGSPAGECHANGEMASTERKEY_H

#include "config-keepassx.h"
#include "DatabaseSettingsWidget.h"
#include <QPointer>

class Database;
class Key;
class CompositeKey;
class ChallengeResponseKey;
class KeyComponentWidget;
class PasswordEditWidget;
class KeyFileEditWidget;
class YubiKeyEditWidget;

class DatabaseSettingsWidgetChangeMasterKey: public DatabaseSettingsWidget
{
    Q_OBJECT

public:
    explicit DatabaseSettingsWidgetChangeMasterKey(QWidget* parent = nullptr);
    Q_DISABLE_COPY(DatabaseSettingsWidgetChangeMasterKey);
    ~DatabaseSettingsWidgetChangeMasterKey() override;

    void load(Database* db) override;

    inline bool hasAdvancedMode() const override { return false; }

public slots:
    void initialize() override;
    void uninitialize() override;
    bool save() override;
    void discard() override;

private:
    bool addToCompositeKey(KeyComponentWidget* widget,
                           QSharedPointer<CompositeKey>& newKey,
                           QSharedPointer<Key>& oldKey);
    bool addToCompositeKey(KeyComponentWidget* widget,
                           QSharedPointer<CompositeKey>& newKey,
                           QSharedPointer<ChallengeResponseKey>& oldKey);

    const QPointer<PasswordEditWidget> m_passwordEditWidget;
    const QPointer<KeyFileEditWidget> m_keyFileEditWidget;
#ifdef WITH_XC_YUBIKEY
    const QPointer<YubiKeyEditWidget> m_yubiKeyEditWidget;
#endif
};

#endif //KEEPASSXC_DATABASESETTINGSPAGECHANGEMASTERKEY_H
