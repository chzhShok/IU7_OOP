#pragma once

template<typename DrawerCreator, typename... Args>
    requires NotAbstract<DrawerCreator> && Derivative<DrawerCreator, BaseDrawerCreator> && Constructible<DrawerCreator, Args...>
void DrawManager::drawScene(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera, Args... args) {
    DrawerCreator drawerCreator(args...);
    std::shared_ptr<BaseDrawer> drawer = drawerCreator.create();
    DrawVisitor visitor(drawer, camera);
    setEdgesVisibilityForVisitor(visitor);

    for (auto it = scene->begin(); it != scene->end(); ++it)
        (*it)->accept(visitor);
}
