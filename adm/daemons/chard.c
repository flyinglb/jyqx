// chard.c
// From ES2
// Modified by Xiang@XKX
// kayin@CuteRabbit studio update "yihun-dafa" 99-4-15 16:16

#define HUMAN_RACE "/adm/daemons/race/human"
#define BEAST_RACE "/adm/daemons/race/beast"
#define MONSTER_RACE "/adm/daemons/race/monster"

void create() { seteuid(getuid()); }

void setup_char(object ob)
{
	string race;
	mapping my;
	int temp;//for jingli changed by "taoism"&"buddhism"
        if( !stringp(race = ob->query("race")) ) {
                race = "����";
                ob->set("race", "����");
        }

        switch(race) {
                case "����":
                        HUMAN_RACE->setup_human(ob);
                        break;
                case "��ħ":
                        MONSTER_RACE->setup_monster(ob);
                        break;
                case "Ұ��":
                        BEAST_RACE->setup_beast(ob);
                        break;
                default:
                        error("Chard: undefined race " + race + ".\n");
        }

	my = ob->query_entire_dbase();
	if( undefinedp(my["pighead"]) ) my["pighead"] = 0;

	if( undefinedp(my["jing"]) ) my["jing"] = my["max_jing"];
	if( undefinedp(my["qi"]) ) my["qi"] = my["max_qi"];

	if( undefinedp(my["eff_jing"]) ) my["eff_jing"] = my["max_jing"];
	if( undefinedp(my["eff_qi"]) || my["eff_qi"] > my["max_qi"]) my["eff_qi"] = my["max_qi"];
	
	// avoid excess neili
        if (userp(ob))
        {
         if((int)ob->query_skill("force") > (int)ob->query_skill("force", 1))
         {
         if (my["max_neili"] > (int)ob->query_skill("force") * 10)
                        my["max_neili"] = ob->query_skill("force") * 10;
         }
         else
         if (my["max_neili"] > (int)ob->query_skill("force",1) * 10)
                        my["max_neili"] = ob->query_skill("force",1) * 10;
                if (my["neili"] > my["max_neili"])
                        my["neili"] = my["max_neili"];
        }

	// avoid excess jingli
/*
	if((temp=(int)ob->query_skill("taoism"))<(int)ob->query_skill("buddhism"))
		temp=(int)ob->query_skill("buddhism");
*/
        if ( ob->query_skill("taoism"))
                temp = (int)ob->query_skill("taoism",1);
        if ( ob->query_skill("buddhism"))
           {
                 if((int)ob->query_skill("buddhism",1)>temp)
                 temp = (int)ob->query_skill("buddhism",1);
           }
        if ( ob->query_skill("mahayana"))
           {
                 if((int)ob->query_skill("mahayana",1)>temp)
                 temp = (int)ob->query_skill("mahayana",1);
           }
	if (userp(ob)) 
	{
		if((int)ob->query_skill("yihun-dafa"))
		{
			if(my["max_jingli"] > (int)ob->query_skill("yihun-dafa") * 10)
				my["max_jingli"] = ob->query_skill("yihun-dafa") * 10;
		}
		else if(temp)
		{
                        if(my["max_jingli"] > temp * 10 + 100)
                                my["max_jingli"] = temp * 10 + 100;
		}
		if (my["jingli"] > my["max_jingli"])
			my["jingli"] = my["max_jingli"];
	}

	if( undefinedp(my["shen_type"]) ) my["shen_type"] = 0;

	if( undefinedp(my["shen"]) ) {
		if (userp(ob))
			my["shen"] = 0;
		else
			my["shen"] = my["shen_type"] * my["combat_exp"] / 10;
	}

	if( !ob->query_max_encumbrance() )
//		ob->set_max_encumbrance( my["str"] * 5000 );
		ob->set_max_encumbrance( ob->query_str() * 5000 );

	ob->reset_action();
}

varargs object make_corpse(object victim, object killer)
{
	int i;
	object corpse, *inv;

	if( victim->is_ghost() ) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) inv[i]->move(environment(victim));
		return 0;
	}

	corpse = new(CORPSE_OB);
	corpse->set_name( victim->name(1) + "��ʬ��", ({ "corpse" }) );
	corpse->set("long", victim->long()
		+ "Ȼ����" + gender_pronoun(victim->query("gender")) 
		+ "�Ѿ����ˣ�ֻʣ��һ��ʬ�徲�����������\n");
	corpse->set("age", victim->query("age"));
	corpse->set("gender", victim->query("gender"));
	corpse->set("victim_name", victim->name(1));
	corpse->set_weight( victim->query_weight() );
	corpse->set_max_encumbrance( victim->query_max_encumbrance() );
	corpse->move(environment(victim));
	
	// Don't let wizard left illegal items in their corpses.
	if( !wizardp(victim) ) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) {
			if( (string)inv[i]->query("equipped")=="worn" ) {
				inv[i]->move(corpse);
				if( !inv[i]->wear() ) inv[i]->move(environment(victim));
			}
			else inv[i]->move(corpse);
		}
	}

	return corpse;
}

varargs object make_wutoucorpse(object corpse)
{
	string name,oldname;
	sscanf(corpse->query("name"),"%s��ʬ��%*s",oldname);
	corpse->set("oldname",oldname);
	switch(corpse->query("gender"))
	{
	case "����":
		name="��ͷ��ʬ";
		break;
	case "Ů��":
		name="��ͷŮʬ";
		break;
	default:
		name="�Ա�����ʬ��";
		break;
	}

	corpse->set("name",name);
	corpse->set("id",({"wutou corpse"}));
	return corpse;
}

varargs object make_toulu(object corpse)
{
	object toulu;
	toulu=new("/clone/misc/toulu");
	toulu->set("name",(string)corpse->query("oldname")+"��ͷ­");
	toulu->set("gender",corpse->query("gender"));
	toulu->set("age",corpse->query("age"));
	return toulu;
}
