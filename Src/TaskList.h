#pragma once

#include "Task.h"
#include <vector>
#include <map>


namespace todo
{
    class TaskList
    {
        std::map<TaskId, Task> mTasks;

    public:
        TaskList() = default;

        void AddTask(const Task& task);
        bool RemoveTask(const TaskId& taskId);
        void MarkTaskAsCompleted(const TaskId& taskId);
        Task* GetTask(const TaskId& taskId);

    private:

    };

} // namespace todo
