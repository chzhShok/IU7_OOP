template<typename ConLoaderCreator>
    requires Derivative<ConLoaderCreator, BaseLoaderCreator>
std::shared_ptr<ConLoaderCreator> LoaderSolution::create(std::size_t index) {
    if (check(index)) {
        auto creator = std::dynamic_pointer_cast<ConLoaderCreator>(_creators[index]);
        if (!creator) {
            time_t now = time(nullptr);
            throw SolutionNotFoundException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }

        return creator;
    }

    time_t now = time(nullptr);
    throw SolutionNotFoundException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
}
