#include "VergerCl.h"
#include "CherryTree.h"
#include "AppleTree.h"
#include "PeerTree.h"
#include "Controller.h"

Verger::Verger()
{
	int cherryTree = EnterValue("Cherry tree", 0, 8);
	int appleTree = EnterValue("Apple tree", 0, 10);
	int peerTree = EnterValue("Peer tree", 0, 18);

	for (int i = 0; i < cherryTree; ++i)
	{
		trees.emplace_back(CherryTree());
	}
	for (int i = 0; i < appleTree; ++i)
	{
		trees.emplace_back(AppleTree());
	}
	for (int i = 0; i < peerTree; ++i)
	{
		trees.emplace_back(PeerTree());
	}
}

int Verger::HarvestVerger()
{
	int harvest = 0;
	for (Tree tree : trees)
	{
		harvest += tree.Harvest();
	}
	return harvest;
}