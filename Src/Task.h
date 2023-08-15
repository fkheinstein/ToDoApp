#pragma once

#include <string>
#include <chrono>
#include <ctime>

#include "ToDoEnum.h"
#include "TaskId.h"

#include "Publisher.h"


//https://github.com/parthenon-hpc-lab/parthenon/blob/ab9d16714d31e853d000a0757f3487bcb9804023/src/tasks/task_types.hpp

namespace todo
{
    class Task
    {
    public:
        Task(TaskId id, const std::string &title, const std::string &description,
            const std::chrono::system_clock::time_point& start,    const std::chrono::system_clock::time_point& due, TaskPriority p);

        ~Task();

        // Copy-constructor/copy-assignment
        Task(const Task &) = default;
        auto operator=(const Task &) -> Task & = default;

        // Move-constructor/move-assignment
        Task(Task &&) noexcept = default;
        auto operator=(Task &&) noexcept -> Task & = default;

        void Completed();
        bool IsOverdue() const;

        TaskStatus GetTaskStatus();
        TaskPriority GetTaskPriority();

        TaskId GetId() const { return mTaskId; }
        std::chrono::system_clock::time_point GetStartTime() const { return mStartTime; }
        std::chrono::system_clock::time_point GetDueTime() const { return mDueTime; }

        void setStartTime(const std::chrono::system_clock::time_point& time) { mStartTime = time; }
        void setDueTime(const std::chrono::system_clock::time_point& time) { mDueTime = time; }

        




    private:
        TaskId mTaskId;
        std::string mTaskTitle{};
        std::string mTaskDescription{};

        std::chrono::system_clock::time_point mStartTime;
        std::chrono::system_clock::time_point mDueTime;
        TaskStatus mStatus;
        TaskPriority mPriority;
    };

} // namespace todo
