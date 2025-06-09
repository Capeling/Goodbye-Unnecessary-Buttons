#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

// Terrible code, dgaf

class $modify(CreatorLayer) {
	static void onModify(auto& self) {
		if (self.setHookPriorityAfterPost("CreatorLayer::init", "minemaker0430.gddp_integration")) {
			log::warn("Failed to set hook priority for CreatorLayer::init");
		}
	}
	bool init() {
		if(!CreatorLayer::init())
			return false;
		CCMenu* m_creatorButtonsMenu = as<CCMenu*>(this->getChildByID("creator-buttons-menu"));
		as<CCNode*>(m_creatorButtonsMenu->getChildByID("versus-button"))->setVisible(false);
		as<CCNode*>(m_creatorButtonsMenu->getChildByID("map-button"))->setVisible(false);

		auto gddpBtn = as<CCMenuItemSpriteExtra*>(m_creatorButtonsMenu->getChildByID("demon-progression-button"));

		bool gddpThere = Loader::get()->isModLoaded("minemaker0430.gddp_integration") && gddpBtn;

		if (gddpThere) {
			gddpBtn->setZOrder(11);
		}

		for(int i = 0; i < m_creatorButtonsMenu->getChildrenCount(); i++) {
			auto node = as<CCMenuItemSpriteExtra*>(m_creatorButtonsMenu->getChildren()->objectAtIndex(i));
			auto sprite = node->getNormalImage();
			auto nodeID = node->getID();
			
			sprite->setScale(0.85);

			if (nodeID == "map-button")
				node->setZOrder(0);
			else if (nodeID == "create-button")
				node->setZOrder(1);
			else if (nodeID == "saved-button")
				node->setZOrder(2);
			else if (nodeID == "scores-button")
				node->setZOrder(3);
			else if (nodeID == "quests-button")
				node->setZOrder(4);
			else if (nodeID == "paths-button")
				node->setZOrder(5);
			else if (nodeID == "daily-button")
				node->setZOrder(6);
			else if (nodeID == "weekly-button")
				node->setZOrder(7);
			else if (nodeID == "event-button")
				node->setZOrder(8);
			else if (nodeID == "gauntlets-button")
				node->setZOrder(9);
			else if (nodeID == "map-packs-button")
				node->setZOrder(11 + gddpThere);
			else if (nodeID == "featured-button")
				node->setZOrder(12 - gddpThere);
			else if (nodeID == "lists-button")
				node->setZOrder(13 + gddpThere);
			else if (nodeID == "search-button")
				node->setZOrder(14 + gddpThere);
		}

		AxisLayout* menuLayout = as<AxisLayout*>(m_creatorButtonsMenu->getLayout());
		menuLayout->setGap(13.5);
		m_creatorButtonsMenu->getLayout()->ignoreInvisibleChildren(true);
		as<AxisLayout*>(m_creatorButtonsMenu->getLayout())->setCrossAxisReverse(false);
		m_creatorButtonsMenu->updateLayout();
		return true;
	}
};
