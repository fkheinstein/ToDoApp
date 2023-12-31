#pragma once 

#include <string>
#include <memory>

namespace todo {

    class EventData;
    class Observer
    {
    public:
        explicit Observer(const std::string& name);
        virtual ~Observer();

        void notify(std::shared_ptr<EventData>);

        const std::string name() const { return observerName_; }

    private:
        virtual void notifyImpl(std::shared_ptr<EventData>) = 0;

        std::string observerName_;
    };

}
