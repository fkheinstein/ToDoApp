#include "Task.h"

namespace todo
{

    Task::Task(TaskId taskId, const std::string &title, const std::string &description, const std::chrono::system_clock::time_point& start,
        const std::chrono::system_clock::time_point& due, TaskPriority p)
        : mTaskId(taskId)
        , mTaskTitle(title)
        , mTaskDescription(description)
        , mStartTime(start)
        , mDueTime(due)
        , mStatus(TaskStatus::Pending)
        , mPriority(p)
    {
    }

    Task::~Task()
    {
    }

    void Task::Completed()  {
        mStatus = TaskStatus::Completed;
    }

    bool Task::IsOverdue() const {
        return std::chrono::system_clock::now() > mDueTime;
    }

    TaskStatus Task::GetTaskStatus()
     {
         return mStatus;
     }

    TaskPriority Task::GetTaskPriority()
    {
         return mPriority;
    }

} // namespace todo
