#pragma once


#include <ostream>
#include <string>

namespace todo
{
    class TaskId
    {
    public:
        explicit TaskId(int id);
        int GetValue();

        bool operator==(const TaskId& rhs) const;
        bool operator!=(const TaskId& rhs) const;
        bool operator<(const TaskId& rhs) const;
        bool operator<=(const TaskId& rhs) const;
        bool operator>(const TaskId& rhs) const;
        bool operator>=(const TaskId& rhs) const;


        friend std::ostream& operator<<(std::ostream& os, const TaskId& id)
        {
            os << id.mValue;
        }

    private:
        int mValue;

    };

} // namespace todo
