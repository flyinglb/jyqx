// weishi.h 升级到卫士, 拜师
int ask_me()
{
	string sta;
	object ob = this_player();

	if( !stringp(sta =ob->query("dali_family_status")) ) {
	        command("say 你先投身(toushen)我大理做家丁或婢女吧。");
	        return 1;
	}
	if( sta != "家臣") {
		command("say 只有家臣才能升卫士。\n");
		return 1;
	}
	if ((int)ob->query_skill("kurong-changong",1) < 60)
	{
		command("say 你想当卫士，再练几年功吧。\n");
		return 1;
	}
        ob->set_temp("fight_ok",1);
	command("say 好，既然如此想切磋，那就看你的本事如何了。\n");
	return 1;
}

int accept_fight(object ob)
{
        object me  = this_object();
        if ( !ob->query_temp("fight_ok") ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        ob->delete_temp("fight_ok");
        return 1;
}

int checking(object me, object ob)
{
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) 
	{
		call_out("checking",2, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
	{
		command("say 青出於蓝胜於蓝，不愧是大理段家的好弟子 ! 恭喜你了 !\n");
		command("say 你的已经可以胜任大理卫士 !\n");
		ob->set("dali_family_status","卫士");
		return 1;
	}
	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say 看来" + RANK_D->query_respect(ob) + 
			"还得多加练习，方能在大理段家诸多弟子中出人头地 !\n");
		return 1;
	}
	return 1;  
}

void attempt_apprentice(object ob)
{
        if( !stringp(ob->query("dali_family_status")) ) {
		command("shake "+this_player()->query("id"));
		command("say 我早已投身大理为臣，不再涉足江湖俗务，不能收徒了。\n");
		return;
	}
	if ((int)ob->query("shen") < 0  )
	{
		command("say 我大理段氏向来不与您这种黑道人物打交道，您请回吧！");
		return;
	}
	if ((int)ob->query("combat_exp") > 10000 || (int)ob->query("age") >17 )
	{
		command("say 镇南王府收了大侠您，也让你太屈尊了吧！");
		return;
	}
	command("say 很好，很好。既已入府，便当尽忠报主，这条性命也就不是自己的了。\n");

	if( (string)ob->query("gender") == "男性")
		ob->set("dali_family_status","家丁");
	else
		ob->set("dali_family_status","婢女");

	command("recruit " + ob->query("id"));
}
