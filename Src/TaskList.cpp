#include "TaskList.h"
#include <utility>

namespace todo {

    void TaskList::AddTask(const Task& task_) {
        //mTasks[task_.GetId()] = task_;
        mTasks.insert(std::pair<TaskId, Task>(task_.GetId(), task_));
    }

    bool TaskList::RemoveTask(const TaskId& taskId) {
        auto it = mTasks.find(taskId);
        if (it != mTasks.end()) {
            mTasks.erase(it);
            return true;
        }
        return false;
    }

    void TaskList::MarkTaskAsCompleted(const TaskId& taskId) {
        auto it = mTasks.find(taskId);
        if (it != mTasks.end()) {
            it->second.Completed();
        }
        // Handle cases where task is not found, if needed.
    }

    Task* TaskList::GetTask(const TaskId& taskId) {
        auto it = mTasks.find(taskId);
        if (it != mTasks.end()) {
            return &(it->second);
        }
        return nullptr; // Task not found
    }
}
