// SPDX-FileCopyrightText: 2019-2022 Connor McLaughlin <stenzek@gmail.com>
// SPDX-License-Identifier: (GPL-3.0 OR CC-BY-NC-ND-4.0)

#pragma once
#include "core/types.h"
#include <QtWidgets/QWidget>

#include "ui_biossettingswidget.h"

class SettingsDialog;

enum class ConsoleRegion;
namespace BIOS {
struct ImageInfo;
}

class BIOSSettingsWidget : public QWidget
{
  Q_OBJECT

public:
  explicit BIOSSettingsWidget(SettingsDialog* dialog, QWidget* parent);
  ~BIOSSettingsWidget();

  static void populateDropDownForRegion(ConsoleRegion region, QComboBox* cb,
                                        std::vector<std::pair<std::string, const BIOS::ImageInfo*>>& images,
                                        bool per_game);
  static void setDropDownValue(QComboBox* cb, const std::optional<std::string>& name, bool per_game);
  static std::vector<std::pair<std::string, const BIOS::ImageInfo*>> getList(const char* directory);

private Q_SLOTS:
  void refreshList();

private:
  Ui::BIOSSettingsWidget m_ui;

  SettingsDialog* m_dialog;
};
