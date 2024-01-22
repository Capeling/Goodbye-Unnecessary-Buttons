#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

class $modify(CreatorLayer) {
	bool init() {
		if(!CreatorLayer::init())
			return false;
		CCMenu* m_creatorButtonsMenu = as<CCMenu*>(this->getChildByID("creator-buttons-menu"));
		as<CCNode*>(m_creatorButtonsMenu->getChildByID("versus-button"))->removeFromParent();
		as<CCNode*>(m_creatorButtonsMenu->getChildByID("map-button"))->removeFromParent();
		as<CCNode*>(m_creatorButtonsMenu->getChildByID("event-button"))->removeFromParent();

		for(int i = 0; i < m_creatorButtonsMenu->getChildrenCount(); i++) {
			log::info("{}", i);

			auto node = as<CCNode*>(m_creatorButtonsMenu->getChildren()->objectAtIndex(i));
			auto sprite = as<CCSprite*>(node->getChildren()->objectAtIndex(0));
			auto nodeID = node->getID();
			
			sprite->setScale(0.85);

			if(nodeID == "featured-button")
				node->setZOrder(-4);
			
			if(nodeID == "map-packs-button")
				node->setZOrder(-3);
			
			if(nodeID == "lists-button")
				node->setZOrder(-2);
			
			if(nodeID == "search-button")
				node->setZOrder(-1);
		}

		AxisLayout* menuLayout = as<AxisLayout*>(m_creatorButtonsMenu->getLayout());
		menuLayout->setGap(13.5);
		m_creatorButtonsMenu->updateLayout();
		return true;
	}
};
