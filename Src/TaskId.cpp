#include "TaskId.h"

#include <algorithm>
#include <bitset>
#include <stdexcept>
#include <string>
#include <utility>

namespace todo
{

    TaskId::TaskId(int id) {}

    int TaskId::GetValue() { return mValue; }

    bool TaskId::operator==(const TaskId& rhs) const { return mValue == rhs.mValue; }
    bool TaskId::operator!=(const TaskId& rhs) const { return mValue != rhs.mValue; }

    bool TaskId::operator<(const TaskId& rhs) const { return mValue < rhs.mValue; }
    bool TaskId::operator<=(const TaskId& rhs) const { return mValue <= rhs.mValue; }
    bool TaskId::operator>(const TaskId& rhs) const { return mValue > rhs.mValue; }
    bool TaskId::operator>=(const TaskId& rhs) const { return mValue >= rhs.mValue; }

}