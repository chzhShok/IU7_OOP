template<typename DrawerCreator, typename... Args>
    requires NotAbstract<DrawerCreator> && Derivative<DrawerCreator, BaseDrawerCreator> && Constructible<DrawerCreator, Args...>
void DrawManager::drawScene(std::shared_ptr<SceneManager> sceneMngr, Args... args) {
    auto camera = sceneMngr->getMainCamera();
    auto scene = sceneMngr->getScene();
    DrawerCreator drawerCreator(args...);
    std::shared_ptr<BaseDrawer> drawer = drawerCreator.create();
    DrawVisitor vis(drawer, camera);

    for (auto it = scene->begin(); it != scene->end(); ++it)
        (*it)->accept(std::make_shared<DrawVisitor>(vis));
}
