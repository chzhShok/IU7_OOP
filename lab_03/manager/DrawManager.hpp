#pragma once

template<typename DrawerCreator, typename... Args>
    requires NotAbstract<DrawerCreator> && Derivative<DrawerCreator, BaseDrawerCreator> && Constructible<DrawerCreator, Args...>
void DrawManager::drawScene(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera, Args... args) {
    DrawerCreator drawerCreator(args...);
    std::shared_ptr<BaseDrawer> drawer = drawerCreator.create();
    DrawVisitor visitor(drawer, camera);

    for (auto &item: *scene)
        item->accept(visitor);
}
