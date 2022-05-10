/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2021 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#include "timeinput.h"

namespace olive {

#define super Node

TimeInput::TimeInput()
{
}

QString TimeInput::Name() const
{
  return tr("Time");
}

QString TimeInput::id() const
{
  return QStringLiteral("org.olivevideoeditor.Olive.time");
}

QVector<Node::CategoryID> TimeInput::Category() const
{
  return {kCategoryTime};
}

QString TimeInput::Description() const
{
  return tr("Generates the time (in seconds) at this frame.");
}

void TimeInput::Value(const NodeValueRow &value, const NodeGlobals &globals, NodeValueTable *table) const
{
  table->Push(NodeValue::kFloat,
              globals.time().in().toDouble(),
              this,
              false,
              QStringLiteral("time"));
}

}
