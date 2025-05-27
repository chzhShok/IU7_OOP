#include "BaseObjectCommand.hpp"

class CompositeObjectCommand : public BaseObjectCommand {
public:
    CompositeObjectCommand() = delete;
    virtual ~CompositeObjectCommand() = default;
    CompositeObjectCommand(std::vector<size_t> ids);

    virtual void execute();

private:
    std::vector<size_t> _ids;
};
