// attribute.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <dbase.h>
#include <skill.h>

int query_str()
{
	int improve = query_skill("unarmed", 1) / 10;

	if ( query_skill("unarmed",1)
	  || query_skill("strike", 1)
	  || query_skill("finger", 1)
	  || query_skill("cuff", 1)
	  || query_skill("hand", 1)
	  || query_skill("claw", 1))
	{
		if ( query_skill("strike", 1) >= improve * 10 )
			improve = (int)query_skill("strike", 1) / 10;
		if ( query_skill("finger", 1) >= improve * 10)
			improve = (int)query_skill("finger", 1) / 10;
		if ( query_skill("cuff", 1) >= improve * 10)
			improve = (int)query_skill("cuff", 1) / 10;
		if ( query_skill("hand", 1) >= improve * 10)
			improve = (int)query_skill("hand", 1) / 10;
		if ( query_skill("claw", 1) >= improve * 10)
			improve = (int)query_skill("claw", 1) / 10;
	}

	return (int)query("str") + // (int)query("jiali") +
		query_temp("apply/strength") + improve;
}

int query_int()
{
	return (int)query("int") + query_temp("apply/intelligence") +
		(int)query_skill("literate", 1) / 10;
}

int query_con()
{
	return (int)query("con") + query_temp("apply/constitution") +
		(int)query_skill("force", 1) / 10;
}

int query_dex()
{
	return (int)query("dex") + query_temp("apply/dexerity") +
		(int)query_skill("dodge", 1) / 10;
}

int query_kar()
{
	return (int)query("kar");
}

int query_per()
{
	return (int)query("per")+query_temp("apply/personality");
}
